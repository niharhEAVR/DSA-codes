#include <stdio.h>
int main()
{
    int num,rem = 0;//num & rem are variables to store number and remainder
    int reverse=0;//rev is variable to store reverse of number
    printf("Enter a number: ");
    scanf("%d", &num);
    int temp=num;//c is variable to store original number
    //loop to find reverse of number
    while(num != 0)
    {
        rem = num%10;//find remainder
        reverse = ((reverse*10) + rem);//find reverse
        num /= 10;//reduce number by 1 digit
    }
    
    //check if number is palindrome or not
    if(temp==reverse){
        printf("%d is palindrome\n", temp);
    }
    else{
        printf("%d is not palindrome\n", temp);
    }
    
    return 0;
}