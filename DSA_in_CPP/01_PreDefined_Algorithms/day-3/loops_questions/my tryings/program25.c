#include<stdio.h>
int main()
{
    int n,p;
    printf("Enter the number: ");
    scanf("%d",&n);
    for(int i=2;i<n;i++){
        if(n%i==0){
            p = i;
            printf("The prime factors are: %d\n",p);
        }
    }
    return 0;
}