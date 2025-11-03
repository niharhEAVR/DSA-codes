// #include <bits/stdc++.h>

#include <iostream>
#include <chrono>
using namespace std::chrono;

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

    auto start = high_resolution_clock::now();
    
    
    bubbleSort(arr, size);

    std::cout << "[ ";
    for (auto i : arr)
    {
        std::cout << i << ",";
    }
    std::cout << " ]";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken: " << duration.count() << " microseconds." << std::endl;
    std::cout << "Or: " << duration.count() / 1000000.0 << " seconds.";

    return 0;
}