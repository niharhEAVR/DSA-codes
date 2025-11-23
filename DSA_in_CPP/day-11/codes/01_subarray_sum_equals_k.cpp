// #include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <unordered_map>

// void traverse(std::vector<int> &arr, int n){
//	std::cout << "[ ";
//	for (int i = 0; i < n; i++)
//	{
//		std::cout << arr[i] << ", ";
//	}
//	std::cout << "]";
// }

void traverse(std::vector<int> &nums)
{
    std::cout << "[ ";
    for (auto it = nums.begin(); it != nums.end(); it++)
    {
        it + 1 == nums.end() ? std::cout << *it << " " : std::cout << *it << ", ";
    }
    std::cout << "]";
}

// Optimal Approach
int optimal(std::vector<int> &arr, int k)
{
    std::unordered_map<int, int> mp;
    int preSum = 0;
    int cnt = 0;
    mp[0] = 1;

    for (int i = 0; i < arr.size(); i++)
    {
        preSum += arr[i];

        int remove = preSum - k;
        cnt += mp[remove];
        mp[preSum] += 1;
    }

    return cnt;
}

// TC = O(n log n) for map and O(n^2) for unordered map
// SC = O(n)

int main()
{
    std::vector<int> nums = {1, 2, -1, 2, -1, 3};
    std::vector<int> nums2 = {1, 2, 0, 0, 0, 0, 3};
    std::vector<int> nums3 = {1, 2, 1, 2, 1};
    int k = 3;
    std::cout << optimal(nums, k) << " = Result" << std::endl;
    // std::cout << optimal(nums2, k) << " = Result" << std::endl;
    // std::cout << optimal(nums3, k) << " = Result" << std::endl;

    return 0;
}