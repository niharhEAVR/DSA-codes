// #include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <algorithm>

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

std::vector<std::vector<int>> optimal(std::vector<std::vector<int>> &nums)
{
    std::sort(nums.begin(), nums.end());

    int index = 0; // this tracks merged nums

    for (int i = 1; i < nums.size(); i++)
    {
        // overlap condition
        if (nums[i][0] <= nums[index][1])
        {
            // merge into same place
            nums[index][1] = std::max(nums[index][1], nums[i][1]);
        }
        else
        {
            // no overlap -> move to next position
            index++;
            nums[index] = nums[i];
        }
    }

    // return only merged part (index+1 nums)
    return std::vector<std::vector<int>>(nums.begin(), nums.begin() + index + 1);
}
//   TC=O(n log n (for sorting) + n) = O(n log n), SC=O(1)

int main()
{

    std::vector<std::vector<int>> nums = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    // std::vector<std::vector<int>> nums = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    // std::vector<std::vector<int>> nums = {{4, 7}, {1, 4}};

    std::vector<std::vector<int>> ans = optimal(nums);
    nestedTraverse(ans);

    return 0;
}