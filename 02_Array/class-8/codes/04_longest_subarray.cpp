// #include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

int longestSubarrayBrute(vector<int> &arr, int k)
{
    int length{};
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size(); j++)
        {
            int sum{};
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            if (sum == k)
                length = max(length, j - i + 1);
        }
    }
    return length;
}
// This brute force approach time complexity is nearly O(n^3)
// but this will work for all the positive and negative numbers also, and SC is O(1)

// The better solution is on the the 05_longest_subarray.cpp

// This is 2 pointer approach for only positive numbers
int positiveLongestSubarrayOptimal(vector<int> &arr, int k)
{

    int left{}, right{}, maxLen{};
    long long sum = arr[0];
    int n = arr.size();

    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= arr[left];
            left++;
        }
        if (sum == k)
        {
            maxLen = std::max(maxLen, right - left + 1);
        }
        right++;
        if (right < n)
            sum += arr[right];
    }

    return maxLen;
}
// TC = O(2n)
// SC = O(1)

int main()
{
    vector<int> nums = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    vector<int> nums2 = {1, 2, -1, 2, -1, 3};
    vector<int> nums3 = {1, 2, 0, 0, 0, 0, 0, 3};
    int k = 3;

    // cout<<longestSubarrayBrute(nums,k) << " = Result" << endl;
    // cout<<longestSubarrayBrute(nums2,k) << " = Result" << endl;

    cout << positiveLongestSubarrayOptimal(nums, k) << " = Result" << endl;
    cout << positiveLongestSubarrayOptimal(nums2, k) << " = wrong Result" << endl;
    cout << positiveLongestSubarrayOptimal(nums3, k) << " = Result" << endl;
    // this apprach is Optimal one which means that only for positive values
    // The Negative ones will fail here. eg => [1, 2, -1, 2, -1] → sum = 3 → length = 5 ✅
    return 0;
}