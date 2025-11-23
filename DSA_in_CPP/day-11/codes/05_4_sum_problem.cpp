// #include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

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

void nestedTraverse(std::vector<std::vector<int>> &nums)
{

    std::cout << "[";

    for (auto it = nums.begin(); it != nums.end(); it++)
    {
        traverse(*it);

        if (it + 1 != nums.end())
            std::cout << ",";
    }
    std::cout << "]" << std::endl;
}

// Brute Approach
//   TC=O(n^4), as a huge tc we dont have to do the code

// Better Approach
std::vector<std::vector<int>> better(std::vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> ans;

    for (int j = 0; j < nums.size(); j++)
    {
        // Level-1 duplicate skip (for 1st value)
        if (j > 0 && nums[j] == nums[j - 1])
            continue;
        for (int i = j + 1; i < nums.size(); i++)
        {
            // Level-2 duplicate skip (for 2nd value)
            if (i > j + 1 && nums[i] == nums[i - 1])
                continue;

            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r)
            {
                long long sum = (long long)nums[j] + nums[i] + nums[l] + nums[r];

                if (sum < target)
                    l++;

                else if (sum > target)
                    r--;

                else // sum == target
                {
                    ans.push_back({nums[j], nums[i], nums[l], nums[r]});

                    // move both
                    l++;
                    r--;

                    // Level-3 duplicate skip (for l)
                    while (l < r && nums[l] == nums[l - 1])
                        l++;

                    // Level-4 duplicate skip (for r)
                    while (l < r && nums[r] == nums[r + 1])
                        r--;
                }
            }
        }
    }

    return ans;
}
//   TC=O(n^3), SC=O(n)

// Optimal Approach with Pruning
std::vector<std::vector<int>> optimal(std::vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> ans;
    if (nums.size() < 4)
        return ans;

    for (int i = 0; i < nums.size() - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < nums.size() - 2; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int l = j + 1;
            int r = nums.size() - 1;

            long long minSum = (long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2];
            if (minSum > target)
                break;

            long long maxSum = (long long)nums[i] + nums[j] + nums[nums.size() - 1] + nums[nums.size() - 2];
            if (maxSum < target)
                continue;

            while (l < r)
            {
                long long sum = (long long)nums[j] + nums[i] + nums[l] + nums[r];

                if (sum < target)
                    l++;

                else if (sum > target)
                    r--;

                else
                {
                    ans.push_back({nums[j], nums[i], nums[l], nums[r]});

                    l++;
                    r--;

                    while (l < r && nums[l] == nums[l - 1])
                        l++;

                    while (l < r && nums[r] == nums[r + 1])
                        r--;
                }
            }
        }
    }

    return ans;
}
//   TC=O(n), SC=O(1)

int main()
{


    std::vector<int> fourSum = {1, 0, -1, 0, -2, 2}; int target=0;
    // std::vector<int> fourSum = {2, 2, 2, 2, 2}; int target=8;

    traverse(fourSum);

    // std::vector<std::vector<int>> ans = better(fourSum, target);
    // nestedTraverse(ans);

    std::vector<std::vector<int>> ans = optimal(fourSum, target);
    nestedTraverse(ans);
    return 0;
}