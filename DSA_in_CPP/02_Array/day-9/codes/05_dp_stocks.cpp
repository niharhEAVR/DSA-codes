#include <iostream>
#include <vector>

int optimal(std::vector<int> &nums)
{
    int mini = nums[0], profit{};

    for (int i = 1; i < nums.size(); i++)
    {
        int cost = nums[i] - mini;
        profit = std::max(profit, cost);
        mini = std::min(mini, nums[i]);
    }
    return profit;
}

int main()
{

    std::vector<int> nums = {7, 1, 5, 3, 6, 4};
    std::vector<int> nums2 = {7, 6, 4, 3, 1};

    std::cout << optimal(nums) << std::endl;
    std::cout << optimal(nums2) << std::endl;

    return 0;
}