#include <stdio.h>

void BubblSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int temp;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("The sorted array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    
}

int main()
{
    int arr[] = {10, 8, 9, 6, 7, 4, 5, 2, 3, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    BubblSort(arr, size);

    return 0;
}