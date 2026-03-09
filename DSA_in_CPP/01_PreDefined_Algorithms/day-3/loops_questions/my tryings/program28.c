#include <stdio.h>
int main()
{
    int num,remainder,sum=0;
    printf("Enter the number: ");
    scanf("%d",&num);

    int temp = num;

    while(num!=0){
        remainder = num%10;
        int facto=1;
        for(int i=remainder; i>=1; i--){
            facto *= i;
        }
        sum += facto;
        num /=10;
    }
    if(sum==temp)
        printf("%d is a Strong Number.",temp);
    else
        printf("%d is not a Strong Number.",temp);
    return 0;
}