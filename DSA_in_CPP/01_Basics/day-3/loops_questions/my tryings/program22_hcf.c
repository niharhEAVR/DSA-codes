/*Write a Program to Find GCD or HCF of two numbers
entered by user*/
#include<stdio.h>
int main()
{
    int swap,num1,num2;
    printf("Enter two positive integers: ");
    scanf("%d%d",&num1,&num2);
    int c1=num1,c2=num2;
    while(num2!=0){
        swap = num2;
        num2 = num1%num2;
        num1 = swap;
    }
    printf("The hcf of %d and %d is: %d",c1,c2,num1);
    return 0;
}