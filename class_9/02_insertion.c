#include <stdio.h>

int main() {
    int arr[6] = {1, 2, 3, 4, 5};
    int n = 5;  // current size of the array
    int pos = 2; // position to insert (0-based index)
    int value = 10;

    // Insertion operation
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];  // shift elements to the right
    }
    arr[pos] = value;  // insert the new element
    n++;  // increase size

    // Displaying the array after insertion
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
