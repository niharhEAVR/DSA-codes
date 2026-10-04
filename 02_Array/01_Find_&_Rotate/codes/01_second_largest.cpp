// #include <bits/stdc++.h>

#include <iostream>

int findNum(int arr[], int size)
{
    int largest{INT_MIN}, second{INT_MIN};
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] > largest)
        {
            second = largest;
            largest = arr[i];
        }
        else if (arr[i] > second && arr[i] != largest)
        {
            second = arr[i];
        }
    }

    return (second == INT_MIN) ? -1 : second;
}

int main()
{
    // int arr[] = {2, 8, 4, 7, 1, 6, 5, 3};
    int arr[] = {2, 2, 2, 3, 1, 2, 2, 2, 2, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "The second Largest is: " << findNum(arr, size);

    return 0;
}