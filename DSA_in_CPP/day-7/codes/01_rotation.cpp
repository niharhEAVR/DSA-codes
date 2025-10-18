#include <bits/stdc++.h>

#include <iostream>

void traverse(std::vector<int> & arr, int n)
{
    std::cout << "[ ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << "]";
}

// Bad solution
// void rotate(std::vector<int> &nums, int k)
// {
//     std::cout<<k<<std::endl;
//     int temp{};
//     for (int i = 0; i < k; i++)
//     {
//         temp = nums[nums.size() - 1];
//         for (int j = nums.size() - 1; j > 0; j--)
//         {
//             nums[j] = nums[j - 1];
//         }
//         nums[0] = temp;
//     }
// }

// Legend solution
// void rotate(std::vector<int> &nums, int k)
// {
//     std::reverse(nums.begin(), nums.end());
//     std::reverse(nums.begin() , nums.begin()+k);
//     std::reverse(nums.begin()+k , nums.end());
// }

// Better Approach solution (left to right) 
// But the problem we are doing right to left,
// So dry run the code and find the right to left approach
void rotate(std::vector<int> &nums, int k)
{
    int n = nums.size();
    k %= n;
    int temp[k];
    for (size_t i = 0; i < k; i++)
    {
        temp[i] = nums[i];
    }

    for (size_t i = k; i < n; i++)
    {
        nums[i-k] = nums[i];
    }
    
    for (size_t i = n-k; i < n; i++)
    {
        nums[i] = temp[i-(n-k)];
    }
    
}

int main()
{
    
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    
    rotate(nums, k);
    traverse(nums, nums.size());

    return 0;
}

//  need a more good solution for the leetcode