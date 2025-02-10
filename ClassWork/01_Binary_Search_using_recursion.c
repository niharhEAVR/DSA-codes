#include <stdio.h>

// Recursive function for binary search
int binarySearch(int arr[], int low, int high, int target)
{
    if (low > high)
    {
        return -1; // Base case: Element not found
    }

    int mid = low + (high - low) / 2; // Prevent integer overflow

    if (arr[mid] == target)
    {
        return mid; // Element found
    }
    else if (arr[mid] > target)
    {
        return binarySearch(arr, low, mid - 1, target); // Search left half
    }
    else
    {
        return binarySearch(arr, mid + 1, high, target); // Search right half
    }
}

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate array size
    int target = 56;                      // Element to search

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1)
    {
        printf("Element %d found at index %d\n", target, result);
    }
    else
    {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}
