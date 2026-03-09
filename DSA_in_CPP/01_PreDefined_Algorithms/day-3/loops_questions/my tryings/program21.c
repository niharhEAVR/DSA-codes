/*
 *Example
Input
Input number: 5
Output
Factorial: 120

 */
#include <stdio.h>
int main()
{
    int num,facto=1;//n is variable to store number 6
    printf("Enter a number: ");
    scanf("%d", &num);
    //loop to find factorial of number
    for(int i=1;i<=num;i++)
    {
        facto *= i;//1*1=1 1*2=2 2*3=6
    }
    printf("The Factorial of %d is: %d",num,facto);
    return 0;
}