// three numbers lcm

/*
 *Example
Input
Input number1: 12
Input number2: 30
Output
LCM = 60
 */

#include <stdio.h>
int main()
{
    int num1, num2, max, lcm;
    printf("Enter first number:");
    scanf("%d", &num1);
    printf("Enter second number:");
    scanf("%d", &num2);
    if (num1 > num2)
    {
        max = num1;
    }
    else
    {
        max = num2;
    }
    while (1)
    {
        if (max % num1 == 0 && max % num2 == 0)
        {
            lcm = max;
            break;
        }
        else
        {
            max++;
        }
    }
    printf("The lcm of %d and %d is: %d", num1, num2, lcm);
    return 0;
}