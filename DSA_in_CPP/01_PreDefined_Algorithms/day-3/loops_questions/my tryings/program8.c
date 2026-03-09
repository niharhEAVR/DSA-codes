// Write a program to print all natural numbers in reverse (from n to 1). 
#include<stdio.h>
int main()
{
    int n,i,sum;
    printf("Enter the n value: ");
    scanf("%d",&n);
    for(i=n;i>=1;i--){
        printf("naturels numbers:%d\n",i);
    }
    return 0;
}