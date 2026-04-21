#include <bits/stdc++.h>

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

// brute force approach O(n^2)
// std::vector<int> sum2(std::vector<int> &nums, int k)
// {
//     int l{},m{};
//     for (int i = 0; i < nums.size(); i++)
//     {
//         for (int j = i + 1; j < nums.size(); j++)
//         {
//             if(nums[i]+nums[j] == k){
//                 l = i;
//                 m = j;
//                 break;
//             }
//         }

//     }

//     return {l,m};
// }

// better approach Hashing O(n)
// std::vector<int> sum2(std::vector<int> &nums, int k)
// {
//     int l{-1}, m{-1};
//     std::map<int, int> mpp;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         int moreNeed = k - nums[i];
//         if (mpp.find(moreNeed) != mpp.end())
//         {
//             l = mpp[moreNeed];
//             m = i;
//             break;
//         }
//         mpp[nums[i]] = i;
//     }

//     return {l, m};
// }
// wrost case find() will take O(n^2)

// optimal solution Two pointer
std::vector<int> sum2(std::vector<int> &nums, int k)
{
    int l{-1}, m{-1};
    int left{0}, right(nums.size() - 1);
    std::sort(nums.begin(), nums.end());

    std::cout<<"After sort the array is: ";
    traverse(nums, nums.size());
    
    while (left < right)
    {
        int sum = nums[left] + nums[right];
        if (sum == k)
        {
            l = left, m = right;
            break;
        }
        else if (sum < k)
        left++;
        else
        right--;
    }
    
    return {l, m};
}

int main()
{
    std::vector<int> nums = {2, 7, 9, 15, 12};
    int target = 14;
    
    std::vector<int> arr = sum2(nums, target);
    
    std::cout<<"\nAnswer Indexes: ";
    traverse(arr, arr.size());

    return 0;
}