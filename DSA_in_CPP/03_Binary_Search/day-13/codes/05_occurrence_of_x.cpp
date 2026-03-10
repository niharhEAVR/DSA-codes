
#include <bits/stdc++.h>

int lowerBound(std::vector<int> &arr, int x)
{
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int upperBound(std::vector<int> &arr, int x)
{
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] > x)
        {
            ans = mid;
            high = mid - 1; // go LEFT
        }
        else
        {
            low = mid + 1; // go RIGHT
        }
    }
    return ans;
}


std::vector<int> searchRange(std::vector<int> &nums, int target)
{
    int lb = lowerBound(nums, target);
    int ub = upperBound(nums, target);
    if (lb < nums.size() && nums[lb] != target)
    {
        return {-1, -1};
    }
    else if (ub == 0 || nums[ub - 1] != target)
    {
        return {-1, -1};
    }
    return {lb, ub - 1};
}


int main()
{
    std::vector<int> arr = {2, 2};
    int x = 3;
    std::vector<int> ans = searchRange(arr, x);
    std::cout << "First and Last Occurrence of " << x << " is: [" << ans[0] << ", " << ans[1] << "]\n";
    return 0;
}