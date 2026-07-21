#include <stdio.h>

int main() {
    int num1, num2, i, gcd, lcm;

    printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);

    for(i=1; i <= num1 && i <= num2; ++i) {
        // Checks if i is factor of both integers
        if(num1%i==0 && num2%i==0)
            gcd = i;
    }

    lcm = (num1*num2)/gcd;

    printf("HCF of %d and %d is %d\n", num1, num2, gcd);
    printf("LCM of %d and %d is %d\n", num1, num2, lcm);

    return 0;
}
