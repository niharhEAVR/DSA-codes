// #include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <algorithm>

void traverse(std::vector<int> &arr, int n)
{
    std::cout << "[ ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << "]";
}

// Better Approach
void better(std::vector<int> &arr, int n)
{
    std::next_permutation(arr.begin(), arr.end());
}

// Optimal Approach (its actually better indepth)
void optimal(std::vector<int> &nums, int n)
{
    int index{-1};
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    for (int i = n - 1; i > index; i--)
    {
        if (nums[i] > nums[index])
        {
            std::swap(nums[i], nums[index]);
            break;
        }
    }
    reverse(nums.begin() + index + 1, nums.end());
}

int main()
{
    std::vector<int> arr = {1, 2, 3};
    int n = arr.size();
    
    // Better Approach
    better(arr, n);
    traverse(arr, n);
    
    std::vector<int> arr2 = {1, 2, 3};
    n = arr2.size();
    // Optimal Approach
    optimal(arr2, n);
    traverse(arr2, n);

    return 0;
}