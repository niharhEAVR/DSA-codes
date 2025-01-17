#include <stdio.h>

// Function for binary search
int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // Calculate mid-point

        if (arr[mid] == key) {   // Key found
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;       // Search in the right half
        } else {
            high = mid - 1;      // Search in the left half
        }
    }

    return -1;  // Key not found
}

int main() {
    int n, i, key;

    // Input the size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input the sorted array
    printf("Enter %d sorted elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the element to search
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Perform binary search
    int result = binarySearch(arr, n, key);

    // Output the result
    if (result != -1) {
        printf("Element %d found at index %d.\n", key, result);
    } else {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}
