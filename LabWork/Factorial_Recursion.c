 #include <stdio.h>

// Function to calculate factorial using recursion
int factorial(int n) {
    if (n == 0)  // Base case: factorial of 0 is 1
        return 1;
    else         // Recursive case: n * factorial of (n-1)
        return n * factorial(n - 1);
}

int main() {
    int num;
    
    // Input from the user
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial of a negative number is undefined.\n");
    } else {
        // Output the result
        printf("Factorial of %d is: %d\n", num, factorial(num));
    }

    return 0;
}