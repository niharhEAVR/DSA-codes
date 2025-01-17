#include <stdio.h>

// Function to calculate nth Fibonacci number using recursion
int fibonacci(int n) {
    if (n == 0)  // Base case: 0th Fibonacci number is 0
        return 0;
    else if (n == 1)  // Base case: 1st Fibonacci number is 1
        return 1;
    else  // Recursive case
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n, i;

    // Input from the user
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        printf("Fibonacci series: ");
        for (i = 0; i < n; i++) {
            printf("%d ", fibonacci(i));
        }
        printf("\n");
    }

    return 0;
}