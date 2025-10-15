#include <bits/stdc++.h>

#include <iostream>

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    int arr[] = {13, 46, 24, 52, 10, 9, 1, 4, 6, 5425, 23, 563, 2, 5235, 36, 363, 523, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, size);

    std::cout << "[ ";
    for (auto i : arr)
    {
        std::cout << i << ",";
    }
    std::cout << " ]";

    return 0;
}