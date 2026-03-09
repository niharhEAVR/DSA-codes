// Write a program to Calculate the Sum of 1 to 10 numbers using a 
// for loop, while loop, and do while loop. 
#include<stdio.h>
int main()
{   
    int i,sum=0;
    for (i=1;i<=10;i++)
    {
        sum += i;
    }
    printf("The sum is : %d",sum);
    

}