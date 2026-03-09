#include <stdio.h>
int fun()
{
    int num, first = 0, second = 1, next;

    printf("Enter the number of terms: ");
    scanf("%d", &num);

    printf("Fibonacci Series:\n");

    for (int i = 0; i < num; i++)
    {
        if (i <= 1)
            next = i;
        else
            next = first + second;
            first = second;
            second = next;

        printf("%d ", next);
    }
    printf("\n");
}
int main()
{
    while (1)
    {
        fun();
    }
    return 0;
}
