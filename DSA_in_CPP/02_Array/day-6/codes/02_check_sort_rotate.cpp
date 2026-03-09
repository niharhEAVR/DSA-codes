#include <bits/stdc++.h>

#include <iostream>

int main()
{
    
    
    int arr[] = {3,4,5,1,2};
    // int arr[] = {2,1,3,4};
    // int arr[] = {1,2,3};
    
    int drop_count{}, n = (sizeof(arr) / sizeof(arr[0]));
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] > arr[(i+1)%n])
        {
            drop_count++;
        }
    }
    if (drop_count <= 1)
    {
        std::cout << true;
    }
    else
    {
        std::cout << false;
    }

    return 0;
}

// dry run