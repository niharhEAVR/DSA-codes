#include<stdio.h>
int main()
{
    int product=1,digit,number,temp;
    printf("Enter the number: ");
    scanf("%d",&number);
    temp = number;
    while(number != 0){
        digit = number % 10;
        product *= digit;
        number /= 10;
    }
    printf("The product of digit of %d is: %d",temp,product);
}