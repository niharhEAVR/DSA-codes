#include <iostream>
#include <vector>

// Optimal Approach
int searchInsert(std::vector<int> &nums, int target)
{
    int low{}, high = nums.size() - 1;
    int ans = nums.size();
    while (low <= high)
    {
        // int mid = (low + high) >> 1;
        int mid = low + (low + high) >> 1;
        if (nums[mid] >= target)
        {
            high = mid - 1;
            ans = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
//   TC=O(log n), SC=O(1)

int main()
{
    std::vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    int result = searchInsert(nums, target);
    std::cout << "The index is: " << result << std::endl;

    return 0;
}