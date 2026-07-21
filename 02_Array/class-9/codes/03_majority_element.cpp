#include <bits/stdc++.h>

void traverse(std::vector<int> &arr, int n)
{
    std::cout << "[ ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << "]";
}

// // brute force approach O(n^2)
// int majorEle(std::vector<int> &nums)
// {
//     int value{-1};
//     for (int i = 0; i < nums.size(); i++)
//     {
//         int count{};
//         for (int j = 0; j < nums.size(); j++)
//         {
//             if(nums[i] == nums[j]) count++;
//         }
//         if(count>(nums.size()/2)) value = nums[i];
//     }
//     return value;
// }

// // better approach Hashing O(n) , sc O(n) and for wrost case (unordered map) it will take O(n log n)
// int majorEle(std::vector<int> &nums)
// {
//     int value{-1};
//     std::map<int,int> mpp;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         mpp[nums[i]]++;
//     }

//     for (auto i : mpp)
//     {
//         if(i.second > (nums.size()/2)) value = i.first;
//     }
    
//     return value;

// }

// optimal solution Moore's Voting Algorithm vol-1
int majorEle(std::vector<int> &nums)
{
    int count{},candidate;
    for (int i = 0; i < nums.size(); i++)
    {
        if(count == 0) count++,candidate = nums[i];
        
        if(nums[i] == candidate) count++;
        else count--;
    }
    
    
    int count2{};
    // dry run this code for understanding why do we need 2 loops (basically for non major elements, because the moore's algo will fail for non major)
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == candidate) count2++;
    }
    
    if(count2 > (nums.size()/2)) return candidate;
    return -1;
}

int majorEle(std::vector<int> &nums) // vol-2
{
    int count{},candidate;
    for (int i = 0; i < nums.size(); i++)
    {
        if(count == 0)candidate = nums[i];
        
        if(nums[i] == candidate) count++;
        else count--;
    }
    return candidate;
    
    // but this will fail for non-majority elments
}

int main()
{
    // std::vector<int> nums = {1, 2, 3, 4}; // no majority element
    // std::vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    std::vector<int> nums = {6,5,5};


    std::cout << "The element is: " << majorEle(nums);

    return 0;
}