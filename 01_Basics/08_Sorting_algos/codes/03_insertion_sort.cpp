// #include <bits/stdc++.h>
#include<iostream>

void insertionSort(int arr[], int n)
{
    for (size_t i = 0; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {10, 9, 1, 4, 6}; // size=5
    int size = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, size);

    std::cout << "[ ";
    for (auto i : arr)
    {
        std::cout << i << ",";
    }
    std::cout << " ]";

    return 0;
}