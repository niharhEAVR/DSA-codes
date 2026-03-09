// Write a program to print 1-10 using a for loop, while loop, and do 
// while loop. 

#include<stdio.h>
int main()
{   
    /*for(int i=1;i<=10;i++)
    {
        printf("%d\n",i);
    }*/

    /*int i=1;
    while(i<=10){
        printf("%d\n",i);
        i++;
    }*/

    int i=1;
    do{
        printf("%d\n",i);
        i++;
    } while(i<=9);
    {
        printf("%d\n",i);
    }



    return 0;
}