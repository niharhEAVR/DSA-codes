#include <stdio.h>

int main()
{
    int num, sum = 0;
    printf("Enter the number: ");
    scanf("%d", &num);

    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            sum += i;
        }
    }
    if (sum == num)
        printf("%d is a Perfect number.", num);
    else
        printf("%d is not a Perfect number.", num);
    return 0;
}