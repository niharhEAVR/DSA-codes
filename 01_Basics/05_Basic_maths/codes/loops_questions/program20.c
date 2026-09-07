/*
 * Example
Input
Input number: 12
Output
Factors of 12: 1, 2, 3, 4, 6, 12
*/
#include <stdio.h>
int main()
{
    int num;//n is variable to store number
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("The factors of %d are:\n",num);
    //loop to find factors of number
    for(int i=1;i<=num;i++){
        //check if i is factor of n
        if(num%i==0){
            printf("%d\n",i);
        }
    }
    return 0;
}