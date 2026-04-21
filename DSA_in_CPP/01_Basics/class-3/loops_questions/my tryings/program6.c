// Write a program to find the sum of all natural numbers between 
// 1 to n.
// Write a program to print even numbers up to N 
#include<stdio.h>
int main()
{
    int n,i,sum;
    printf("Enter the n value: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("naturels numbers:%d\n",i);
        sum +=i;
    }
    printf("The sum of 1-n numbers is:%d",sum);
    return 0;
}