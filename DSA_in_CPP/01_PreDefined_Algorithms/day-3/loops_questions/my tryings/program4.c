// Write a program to print even numbers up to N 
#include<stdio.h>
int main()
{
    int n,i;
    printf("Enter the n value: ");
    scanf("%d",&n);
    for(i=2;i<=n;i+=2){
        printf("Even numbers:%d\n",i);
    }
    return 0;
}