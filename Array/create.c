#include <stdio.h>

#define MAX 100

void insert(int arr[], int *size, int element, int position) {
    if (*size >= MAX) {
        printf("Array is full. Cannot insert more elements.\n");
        return;
    }

    if (position < 0 || position > *size) {
        printf("Invalid position. It should be between 0 and %d.\n", *size);
        return;
    }

    // Shift elements to the right
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element; // Insert the element
    (*size)++; // Increase the size
    printf("Element %d inserted at position %d.\n", element, position);
}

void delete(int arr[], int *size, int position) {
    if (*size == 0) {
        printf("Array is empty. Cannot delete any elements.\n");
        return;
    }

    if (position < 0 || position >= *size) {
        printf("Invalid position. It should be between 0 and %d.\n", *size - 1);
        return;
    }

    // Shift elements to the left
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--; // Decrease the size
    printf("Element at position %d deleted.\n", position);
}

void display(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX];
    int size = 0; // Current number of elements in the array
    int numElements, element, position;

    // Input multiple elements from user
    printf("How many elements do you want to insert? ");
    scanf("%d", &numElements);
    
    if (numElements > MAX) {
        printf("Cannot insert more than %d elements.\n", MAX);
        return 1;
    }

    printf("Enter %d elements:\n", numElements);
    for (int i = 0; i < numElements; i++) {
        scanf("%d", &arr[i]);
    }
    size += numElements; // Update size after insertion

    // Display the current array
    display(arr, size);

    // Prompt user for insertion of a new element
    printf("Enter the element to insert: ");
    scanf("%d", &element);
    printf("Enter the position to insert the element (0 to %d): ", size);
    scanf("%d", &position);
    insert(arr, &size, element, position);
    display(arr, size);

    // Prompt user for deletion
    printf("Enter the position of the element to delete (0 to %d): ", size - 1);
    scanf("%d", &position);
    delete(arr, &size, position);
    display(arr, size);

    return 0;
}
