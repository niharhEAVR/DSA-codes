#include <bits/stdc++.h>


void insertionSort(int arr[], int n){
    int current{};
    for (size_t i = 0; i < n; i++)
    {
        current = arr[i];
        int j = i-1;
        while (j>=0 && arr[j]>current)
        {
            arr[j+1] = arr[j];
            j -= 1;
        }
        arr[j+1] = current;
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