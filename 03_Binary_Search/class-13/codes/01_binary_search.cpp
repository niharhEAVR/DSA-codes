// #include <bits/stdc++.h>

#include <iostream>
#include <vector>
// #include <unordered_map>
// #include <algorithm>

// Brute Approach
int BinaryLoop(std::vector<int> &nums, int target)
{
    int low{0}, high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
//   TC=O(log n), SC=O(1)

// Better Approach
int BinaryRec(std::vector<int> &nums, int target, int low, int high)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;
    if (nums[mid] == target)
        return mid;
    else if (nums[mid] > target)
    return BinaryRec(nums, target, low, mid-1);
    else
    return BinaryRec(nums, target, mid+1, high);

}
//   TC=O(log n), SC=O(log n)

int main()
{
    std::vector<int> nums = {1, 4, 6, 7, 12, 23, 45};
    int target = 23;

    // int Index = BinaryLoop(nums, target);
    // std::cout << "The value found at : " << Index << std::endl;

    int Index = BinaryRec(nums, target, 0, nums.size() - 1);
    std::cout << "The value found at : " << Index << std::endl;
    return 0;
}