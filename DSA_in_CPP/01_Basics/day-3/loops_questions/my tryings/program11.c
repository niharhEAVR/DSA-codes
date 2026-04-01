// Write a program to find the last digit of a given number
#include <stdio.h>

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    // Iterate until number becomes single digit
    // while (number >= 10) {
    //     number %= 10;
    // }

    number %= 10;

    printf("The last digit of the original number is: %d\n", number);

    return 0;
}
