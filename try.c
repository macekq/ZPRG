#include <stdio.h>
#include <stdlib.h> // For malloc() and realloc()

void push(int** array, int* size, int value) {
    // Increase the size of the array
    *size += 1;
    *array = realloc(*array, *size * sizeof(int));
    if (*array == NULL) {
        perror("Realloc failed");
        exit(EXIT_FAILURE);
    }

    // Add the new value at the end
    (*array)[*size - 1] = value;
}

int main() {
    int* array = NULL; // Start with a NULL pointer
    int size = 0;

    // Push values to the array
    push(&array, &size, 10);
    push(&array, &size, 20);
    push(&array, &size, 30);

    // Print the array
    printf("Array contents: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(array);

    return 0;
}
