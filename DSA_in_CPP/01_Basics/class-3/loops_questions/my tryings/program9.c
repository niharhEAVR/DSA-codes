// Write a program to print all alphabets from a to z. 
#include<stdio.h>
#include<ctype.h>
int main()
{
    // for(int i=1;i<=26;i++){
    //     printf("%c\n",96+i);
    // }
    for(char i='a';i<='z';i++){
        printf("The alphabets are:%c\n",i);
    }
    return 0;
}
