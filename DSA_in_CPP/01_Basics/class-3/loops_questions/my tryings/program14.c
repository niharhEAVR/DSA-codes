#include <stdio.h>

int main() {
    int number, num_digits = 0, temp, first_digit, last_digit, power_of_ten = 1;
    
    printf("Enter a number: ");
    scanf("%d", &number);

    // Counting the number of digits
    temp = number;
    while (temp != 0) {
        temp /= 10;
        num_digits++;
    }

    // If the number has only one digit, no need to swap
    if (num_digits == 1) {
        printf("Number after swapping first and last digits: %d\n", number);
        return 0;
    }

    // Finding the last digit
    last_digit = number % 10;
    
    // Finding the first digit
    temp = number;
    while (temp >= 10) {
        temp /= 10;
    }
    first_digit = temp;

    // Finding the power of 10 to adjust the positions
    for (int i = 1; i < num_digits; i++) {
        power_of_ten *= 10;
    }

    // Swapping the first and last digits
    number -= first_digit * power_of_ten;
    number += last_digit * power_of_ten;
    number -= last_digit;
    number += first_digit;

    printf("Number after swapping first and last digits: %d\n", number);

    return 0;
}