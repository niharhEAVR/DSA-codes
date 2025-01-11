// Question1: Fine the time complexity of the func1 function in the program shown in the snippet below:


#include<stdio.h>

void func1(int array[], int length)
{
    int sum=0;
    int product =1;
    for (int i = 0; i <length; i++)
    {
        sum+=array[i];
    }
 
    for (int i = 0; i < length; i++)
    {
        product*=array[i];
    }
}
 
int main()
{
    int arr[] = {3,4,66};
    func1(arr,3);
    return 0;
}
