#include<stdio.h>
int main()
{
    int n,f,l,r;
    printf("Enter the number: ");
    scanf("%d",&n);
    l = n;
    f = n;
    while(f>=10){
        f /= 10;
    }
    l %= 10;
    r = f+l;
    printf("The sum of first and last digit of the number is: %d",r);
    return 0;
}