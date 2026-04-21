#include <iostream>
#include <vector>

int floor(std::vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int ans = -1; // if floor does not exist

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] <= target)
        {
            ans = mid; // possible floor
            low = mid + 1;   // try to find bigger ≤ x
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

int ceil(std::vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int ans = -1; // if ceil does not exist

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] >= target)
        {
            ans = mid; // possible ceil
            high = mid - 1;  // try to find smaller ≥ x
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    std::vector<int> nums={5,7,7,8,8,10};
    int target = 6;
    // std::vector<int> nums = {1, 2, 2, 2, 4, 4, 7, 9, 9, 15};
    // int target = 5;

    std::vector<int> nums2 = {1, 1, 1, 1, 1};
    int target2 = 1;

    int floori = floor(nums, target);
    int ceili = ceil(nums, target);

    int floori2 = floor(nums2, target2);
    int ceili2 = ceil(nums2, target2);

    std::cout << "The floor index is: " << floori << std::endl;
    std::cout << "The ceil index is: " << ceili << std::endl;

    std::cout << "The floor index is: " << floori2 << std::endl;
    std::cout << "The ceil index is: " << ceili2 << std::endl;

    return 0;
}
