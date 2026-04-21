#include<stdio.h>
#include<math.h>

int main()
{
    int  num, originalNum, remainder, count=0;
    float arm=0;

    printf("Enter the number: ");
    scanf("%d",&num);

    originalNum = num;
    while(originalNum!=0){
        originalNum /= 10;
        count++;
    }
    // another method to store the number of digits of num in n
    // for (originalNum = num; originalNum != 0; ++count) {
    //     originalNum /= 10;
    // }
    
    originalNum = num;
    while(originalNum>0){
        remainder = originalNum%10;
        arm = arm + pow(remainder,count);
        originalNum /=10;
    }

    if((int)arm == num)
        printf("%d is armstrong number.",num);
    else
        printf("%d is not armstrong number.",num);
    
    return 0;
}