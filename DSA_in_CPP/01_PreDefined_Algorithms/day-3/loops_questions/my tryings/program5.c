// Write a program to print odd numbers up to N 
#include<stdio.h>
int main()
{
    int n,i;
    printf("Enter the n value: ");
    scanf("%d",&n);
    for(i=1;i<=n;i+=2){
        printf("ODD numbers:%d\n",i);
    }
    return 0;
}