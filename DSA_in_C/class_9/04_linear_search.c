#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int value = 3;
    int found = 0;

    // Linear search
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            found = 1;
            printf("Element %d found at index %d\n", value, i);
            break;
        }
    }

    if (!found) {
        printf("Element %d not found\n", value);
    }

    return 0;
}
