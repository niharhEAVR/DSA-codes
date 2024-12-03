#include<stdio.h>
int dummy(int n){
    n++;
    printf("The value of n: %d\n",n);
}
int main()
{
    int n=15;
    dummy(n);
    printf("The value of n: %d",n);
    return 0;
}

// pass by value