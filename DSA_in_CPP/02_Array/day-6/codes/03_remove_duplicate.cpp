#include <bits/stdc++.h>

#include <iostream>

void traverse(int arr[], int n)
{
    std::cout << "[ ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << "]";
}

int main()
{

    int arr[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int n = (sizeof(arr) / sizeof(arr[0]));

    // brute force approach
    int i = 0;
    for (size_t j = 1; j < n; j++)
    {
        if (!(arr[i] == arr[j]))
        {
            i++;
            arr[i] = arr[j];
        }
    }

    std::cout<<"Total "<<i+1<<" values are unique in the array."<<std::endl;

    traverse(arr, n);

    return 0;
}
