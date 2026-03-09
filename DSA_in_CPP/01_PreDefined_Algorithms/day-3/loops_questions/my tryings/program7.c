//  Write a program to find the sum of all even numbers between 1 
// to n.
#include<stdio.h>
int main()
{
    int n,i,sum;
    printf("Enter the n value: ");
    scanf("%d",&n);
    for(i=2;i<=n;i+=2){
        printf("Even numbers:%d\n",i);
        sum +=i;
    }
    printf("The sum of 1-n even numbers is:%d",sum);
    return 0;
}