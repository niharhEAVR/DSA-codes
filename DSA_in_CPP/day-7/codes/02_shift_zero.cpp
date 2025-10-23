#include <bits/stdc++.h>

#include <iostream>

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
void rotate(std::vector<int> &nums)
{
    if (nums.size() <= 1)
        return;

    int j{-1};
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            j = i;
            break;
        }
    }
    if (j == -1)
        return;
    for (size_t i = j + 1; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            std::swap(nums[i], nums[j]);
            j++;
        }
    }
}

int main()
{

    std::vector<int> nums = {0, 1, 0, 3, 12};
    std::vector<int> nums2 = {0};

    rotate(nums);
    rotate(nums2);
    traverse(nums, nums.size());
    traverse(nums2, nums2.size());

    return 0;
}

//  need a more good solution for the leetcode
