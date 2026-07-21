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

void traverseAdv(std::vector<std::vector<int>> &nums)
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
std::vector<std::vector<int>> brute(std::vector<int> &nums)
{
    std::vector<std::vector<int>> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    std::vector<int> triplet = {nums[i], nums[j], nums[k]};
                    std::sort(triplet.begin(), triplet.end());
                    ans.push_back(triplet);
                }
            }
        }
    }

    std::sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    return ans;
}
//   TC=O(n^3), SC=O(1) or O(n^3) in wrost case

// Better Approach
std::vector<std::vector<int>> better(std::vector<int> &nums)
{
    int n = nums.size();
    std::vector<std::vector<int>> result;

    sort(nums.begin(), nums.end()); // step 1

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            int third = -(nums[i] + nums[j]);

            if (binary_search(nums.begin() + j + 1, nums.end(), third))
            {
                std::vector<int> triplet = {nums[i], nums[j], third};
                result.push_back(triplet);
            }
        }
    }

    std::sort(result.begin(), result.end());
    result.erase(std::unique(result.begin(), result.end()), result.end());
    return result;
}
//   TC=O(n^2 log n), SC=O(1), or SC=O(n^2) in worst case

// Optimal Approach
std::vector<std::vector<int>> optimal(std::vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();

    std::vector<std::vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        // Level-1 duplicate skip
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int l = i + 1;
        int r = n - 1;

        while (l < r)
        {
            long long sum = (long long)nums[i] + nums[l] + nums[r];

            if (sum < 0)
                l++;

            else if (sum > 0)
                r--;

            else // sum == 0
            {
                ans.push_back({nums[i], nums[l], nums[r]});

                // move both
                l++;
                r--;

                // Level-2 duplicate skip (for l)
                while (l < r && nums[l] == nums[l - 1])
                    l++;

                // Level-3 duplicate skip (for r)
                while (l < r && nums[r] == nums[r + 1])
                    r--;
            }
        }
    }
    return ans;
}
//   TC=O(n), SC=O(1)

int main()
{

    // std::vector<int> threeSum = {-1, 0, 1, 2, -1, -4};
    // std::vector<int> threeSum = {0,1,1};
    std::vector<int> threeSum = {0,0,0};

    traverse(threeSum);
    // std::vector<std::vector<int>> ans = brute(threeSum);
    // traverseAdv(ans);

    // std::vector<std::vector<int>> ans = better(threeSum);
    // traverseAdv(ans);

    std::vector<std::vector<int>> ans = optimal(threeSum);
    traverseAdv(ans);
    return 0;
}