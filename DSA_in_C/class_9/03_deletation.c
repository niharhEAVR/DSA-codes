#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;  // current size of the array
    int pos = 2; // position to delete (0-based index)

    // Deletion operation
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];  // shift elements to the left
    }
    n--;  // decrease size

    // Displaying the array after deletion
    for (int i = 0; i < 100; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
