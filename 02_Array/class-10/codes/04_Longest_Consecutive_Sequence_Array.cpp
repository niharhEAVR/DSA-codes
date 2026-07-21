// #include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

void traverse(std::vector<int> &nums)
{
    std::cout << "[ ";
    for (auto it = nums.begin(); it != nums.end(); it++)
    {
        it + 1 == nums.end() ? std::cout << *it << " " : std::cout << *it << ", ";
    }
    std::cout << "]";
}

// Brute Approach
int brute(std::vector<int> &nums)
{
    if (nums.empty())
        return 0;

    int longest{1};
    for (int i = 0; i < nums.size(); i++)
    {
        int count{1};
        int current = nums[i];

        int nextNum = current + 1;
        while (std::find(nums.begin(), nums.end(), nextNum) != nums.end())
        {
            count++;
            nextNum++;
        }
        longest = std::max(count, longest);
    }

    return longest;
}
//   TC=O(n^2), SC=O(1)

// Better Approach
int better(std::vector<int> &nums)
{
    if (nums.empty())
        return 0;
    std::sort(nums.begin(), nums.end());
    int lastSmaller = INT_MIN;
    int cnt{0};
    int longest{1};
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] - 1 == lastSmaller)
        {
            cnt++;
            lastSmaller = nums[i];
        }
        else if (lastSmaller != nums[i])
        {
            cnt = 1;
            lastSmaller = nums[i];
        }

        longest = std::max(cnt, longest);
    }

    return longest;
}
//   TC=O(n), SC=O(1), problem is the we distorting the array, which means we are replacing the values from its original placeses by direct sorting, And also at wrost case it will take O(nlogn) time.

// Optimal Approach
int optimal(std::vector<int> &nums)
{
    if (nums.empty())
        return 0;
    std::unordered_set<int> st;
    for (int i = 0; i < nums.size(); i++)
        st.insert(nums[i]);

    int longest = 0;
    for (auto num : st)
    {
        if (st.find(num - 1) == st.end())
        {
            std::cout << num - 1 << std::endl;
            int cnt = 1;
            int currentNum = num;
            while (st.find(currentNum + 1) != st.end())
            {
                currentNum++;
                cnt++;
            }
            longest = std::max(longest, cnt);
        }
    }
    return longest;
}
//   TC=O(3n), SC=O(n)

int lezend(std::vector<int> &nums)
{
    std::unordered_set<int> s(nums.begin(), nums.end());

    int ans = 0;

    for (int elem : s)
    {
        if (s.find(elem - 1) != s.end())
            continue;
        int count = 1;
        while (s.find(elem + count) != s.end())
            count++;
        ans = std::max(ans, count);
    }
    return ans;
}

int main()
{

    std::vector<int> nums = {102, 4, 100, 1, 101, 3, 2, 1, 1};

    // std::cout << "Longest consecutive suquence array will be formed by: " << brute(nums) << " elements." << std::endl;
    // std::cout << "Longest consecutive suquence array will be formed by: " << better(nums) << " elements." << std::endl;
    std::cout << "Longest consecutive suquence array will be formed by: " << optimal(nums) << " elements." << std::endl;

    traverse(nums);

    return 0;
}