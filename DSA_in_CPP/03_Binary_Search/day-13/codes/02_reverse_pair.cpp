// #include <bits/stdc++.h>

#include <iostream>
#include <vector>
// #include <unordered_map>
// #include <algorithm>

// Its a same problem from the count inversion, but in here the we are comparing it by multiply by 2.

// Brute Approach
int reversePairs(std::vector<int> &nums)
{
    int n = nums.size();
    int count{};
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] > (2 * nums[j]))
                count++;
        }
    }

    return count;
}
//   TC=O(n^2), SC=O(1)

// Optimal Approach
// copy & paste the total merge then do customizations.
void mergee(std::vector<int> &nums, int mid, int low, int high)
{
    std::vector<int> temp;
    int left = low;
    int right = mid + 1;
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
}
int countRev(std::vector<int> &nums, int low, int mid, int high)
{
    int count = 0;
    int j = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (j <= high && nums[i] > 2LL * nums[j])
        {
            j++;
        }
        count += (j - (mid + 1));
    }
    return count;
}

int mergeSort(std::vector<int> &nums, int low, int high)
{
    if (low >= high)
        return 0;
    int mid = (low + high) / 2;
    int cnt = mergeSort(nums, low, mid);
    cnt += mergeSort(nums, mid + 1, high);
    cnt += countRev(nums, low, mid, high);
    mergee(nums, mid, low, high);
    return cnt;
}

int mergeOptimal(std::vector<int> &nums)
{
    int n = nums.size();
    return mergeSort(nums, 0, n - 1);
}
//   TC=O(n log n), SC=O(n)

int main()
{

    std::vector<int> nums = {2, 4, 3, 5, 1};
    int value = mergeOptimal(nums);
    std::cout << "reverse pairs: " << value;

    return 0;
}