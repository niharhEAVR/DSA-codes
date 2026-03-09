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

void traverse2(int arr[], int n)
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
// int temp{};
// for (int i = 0; i < k; i++)
// {
//     temp = nums[nums.size() - 1];
//     for (int j = nums.size() - 1; j > 0; j--)
//     {
//         nums[j] = nums[j - 1];
//     }
//     nums[0] = temp;
// }
// }

// Bad solution
// void rotate(std::vector<int> &nums, int k)
// {
// if(k<=0) return;
//     std::reverse(nums.begin(), nums.end());
//     std::reverse(nums.begin() , nums.begin()+k);
//     std::reverse(nums.begin()+k , nums.end());
// }

// Better Approach
void rotate(std::vector<int> &nums, int k)
{
    int n = nums.size(), d = k % n; // If number of rotation is greater than the size of the array then we do modulas the rotation by array size and it will give me the original rotation it needs
    if (d <= 0)
        return;
    int temp[d];
    for (int i = 0; i < d; i++)
    {
        temp[i] = nums[i + (n - d)];
    }
    traverse2(temp, 3);
    for (int i = n - 1; i >= d; i--)
    {
        nums[i] = nums[i - d];
    }
    traverse(nums, n);

    for (int i = 0; i < d; i++)
    {
        nums[i] = temp[i];
    }
}

int main()
{

    // std::vector<int> nums = {1, 2};
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    rotate(nums, k);
    traverse(nums, nums.size());

    return 0;
}

//  need a more good solution for the leetcode
