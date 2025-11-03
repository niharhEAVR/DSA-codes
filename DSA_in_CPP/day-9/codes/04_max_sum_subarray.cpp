#include <iostream>
#include <vector>
#include <unordered_map>

int maxSubArray(std::vector<int> &nums)
{
    int maxSum = nums[0];
    int currSum = 0;

    for (int x : nums)
    {
        currSum += x;
        if (currSum > maxSum)
            maxSum = currSum;
        if (currSum < 0)
            currSum = 0;
    }
    return maxSum;
}

int main()
{

    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    std::cout << maxSubArray(nums) << std::endl;

    return 0;
}