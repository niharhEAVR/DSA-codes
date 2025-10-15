#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;

void selectionSort(std::vector<int> &arr, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        int minIndex = i;
        for (size_t j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    std::vector<int> arr = {13, 46, 24, 52, 10, 9, 1, 4, 6, 5425, 23, 563, 2, 5235, 36, 363, 523, 5};

    auto start = high_resolution_clock::now();

    selectionSort(arr, arr.size());

    std::cout << "[ ";
    for (auto i : arr)
    {
        std::cout << i << ",";
    }
    std::cout << " ]";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;

    return 0;
}