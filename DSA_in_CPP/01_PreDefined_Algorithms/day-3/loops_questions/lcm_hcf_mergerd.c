#include <stdio.h>

// Function to find HCF of two numbers
int hcf(int n1, int n2) {
    if (n2 != 0)
        return hcf(n2, n1 % n2);
    else 
        return n1;
}

// Function to find LCM of two numbers
int lcm(int n1, int n2) {
    return (n1 * n2) / hcf(n1, n2);
}

int main() {
    int num1, num2;

    printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);

    printf("HCF of %d and %d is %d\n", num1, num2, hcf(num1, num2));
    printf("LCM of %d and %d is %d\n", num1, num2, lcm(num1, num2));

    return 0;
}
