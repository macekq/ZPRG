#include <Windows.h>
#include <stdio.h>

int main() {
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;

    // Get current console mode and modify it
    GetConsoleMode(hInput, &mode);
    mode &= ~ENABLE_QUICK_EDIT_MODE; // Disable Quick Edit Mode
    mode |= ENABLE_MOUSE_INPUT;      // Enable Mouse Input
    SetConsoleMode(hInput, mode);

    INPUT_RECORD inputRecord;
    DWORD events;
    COORD lastMousePos = { -1, -1 }; // To track mouse movement

    printf("Move the mouse inside the console window.\n");

    while (1) {
        // Wait for and read console input events
        ReadConsoleInput(hInput, &inputRecord, 1, &events);

        if (inputRecord.EventType == MOUSE_EVENT) {
            MOUSE_EVENT_RECORD mouseEvent = inputRecord.Event.MouseEvent;

            if (mouseEvent.dwEventFlags == MOUSE_MOVED) { // Mouse moved
                COORD mousePos = mouseEvent.dwMousePosition;

                // Print only if position changes to avoid spamming
                if (mousePos.X != lastMousePos.X || mousePos.Y != lastMousePos.Y) {
                    printf("Mouse moved to (%d, %d)\n", mousePos.X, mousePos.Y);
                    lastMousePos = mousePos;
                }
            } else if (mouseEvent.dwEventFlags == 0) { // Mouse button press/release event
                if (mouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) {
                    printf("Left click at (%d, %d)\n", mouseEvent.dwMousePosition.X, mouseEvent.dwMousePosition.Y);
                }
                if (mouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED) {
                    printf("Right click at (%d, %d)\n", mouseEvent.dwMousePosition.X, mouseEvent.dwMousePosition.Y);
                }
            }
        }
    }

    return 0;
}
