// nCr formula = n!/r! * (n-r)!
#include<stdio.h>

int factorial(int num){
    int fact = 1;
    for (int i = 1; i <= num; i++)
    {
        fact *=i;
    }
    return fact;
}

int nCr(int n, int r){
    int numerator = factorial(n);

    int denominator = factorial(r) * factorial(n-r);

    int ans = numerator/denominator;

    return ans;
}

int main()
{
    int n,r;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    printf("Enter the value of r: ");
    scanf("%d",&r);

    int answer = nCr(n,r);

    printf("The answer is: %d",answer);
    return 0;
}