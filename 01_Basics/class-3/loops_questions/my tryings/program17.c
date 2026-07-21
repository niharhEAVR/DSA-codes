#include<stdio.h>
int main()
{
    int num,reverse=0;
    printf("Enter the number: ");
    scanf("%d",&num);
    int temp = num;
    while(num!=0){
       reverse *= 10;
       reverse = (num%10)+reverse;
       num /= 10;
    }
    printf("The reverse of %d is: %d",temp,reverse);
    return 0;
}