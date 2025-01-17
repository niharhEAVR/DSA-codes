#include <stdio.h>

int main() {
    int n, i, max, sum = 0;

    // Get the number of elements in the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n]; // Declare an array of size n

    // Input elements into the array
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Display the elements of the array
    printf("\nArray elements are: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Calculate the sum of all elements in the array
    for(i = 0; i < n; i++) {
        sum += arr[i];
    }
    printf("Sum of elements: %d\n", sum);

    // Find the maximum element in the array
    max = arr[0]; // Assume first element is max
    for(i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Maximum element: %d\n", max);

    return 0;
}