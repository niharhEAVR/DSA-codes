#include <iostream>
#include <vector>
// #include <unordered_map>
// #include <algorithm>

// Brute Approach
int brute(std::vector<int> &nums)
{
    int n = nums.size();
    int count{};
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] > nums[j])
                count++;
        }
    }

    return count;
}
//   TC=O(n^2), SC=O(1)

// No Better Approach

// Optimal Approach
// copy & paste the total merge then do customizations.
int mergee(std::vector<int> &nums, int mid, int low, int high)
{
    std::vector<int> temp;
    int left = low;
    int right = mid + 1;
    int count{};
    while (left <= mid && right <= high)
    {
        if (nums[left] <= nums[right])
        {
            temp.push_back(nums[left]);
            left++;
        }
        else
        {
            temp.push_back(nums[right]);
            count += mid - left + 1;
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(nums[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(nums[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        nums[i] = temp[i - low];
    }
    return count;
}

int mergeSort(std::vector<int> &nums, int low, int high)
{
    int cnt{};
    if (low >= high)
        return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSort(nums, low, mid);
    cnt += mergeSort(nums, mid + 1, high);
    cnt += mergee(nums, mid, low, high);
    return cnt;
}

int mergeOptimal(std::vector<int> &nums)
{
    int n = nums.size();
    return mergeSort(nums, 0, n - 1);
}
//   TC=O(n log n), SC=O(n) - as we are altering the original array, if interviewer dont want that we can use a separate copy

int main()
{
    std::vector<int> nums = {5, 3, 2, 4, 1};

    // int value = brute(nums);

    int value = mergeOptimal(nums);
    std::cout << "Count Inversions are: " << value << std::endl;

    return 0;
}