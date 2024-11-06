#include <windows.h>
#include <gdiplus.h>
#include <stdio.h>
#pragma comment (lib, "Gdiplus.lib")

using namespace Gdiplus;

// Global variables for GDI+ initialization
ULONG_PTR gdiplusToken;

// Function to initialize GDI+
void InitGDIPlus() {
    GdiplusStartupInput gdiplusStartupInput;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
}

// Function to shut down GDI+
void ShutdownGDIPlus() {
    GdiplusShutdown(gdiplusToken);
}

// Window procedure function to handle window messages
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // Create a GDI+ graphics object
            Graphics graphics(hdc);

            // Create a pen for drawing
            Pen pen(Color(255, 0, 0, 255), 5); // Red pen with 5px thickness
            graphics.DrawLine(&pen, 50, 50, 200, 50); // Draw a line

            // Draw a rectangle
            graphics.DrawRectangle(&pen, 50, 70, 150, 100);

            // Create a solid brush for filling
            SolidBrush brush(Color(255, 0, 255, 0)); // Green color
            graphics.FillEllipse(&brush, 100, 200, 100, 100); // Draw filled circle

            // Draw text
            FontFamily fontFamily(L"Arial");
            Font font(&fontFamily, 24, FontStyleRegular, UnitPixel);
            SolidBrush textBrush(Color(255, 255, 0, 0)); // Red text
            graphics.DrawString(L"Hello, GDI+!", -1, &font, PointF(50, 350), &textBrush);

            EndPaint(hwnd, &ps);
            return 0;
        }
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

// Main function to create and run the application
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    InitGDIPlus();

    // Define and register the window class
    const wchar_t CLASS_NAME[] = L"SampleWindowClass";
    WNDCLASS wc = { };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    RegisterClass(&wc);

    // Create the window
    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        L"GDI+ Example",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 400, 500,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (hwnd == NULL) {
        ShutdownGDIPlus();
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    // Run the message loop
    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    ShutdownGDIPlus();
    return 0;
}
