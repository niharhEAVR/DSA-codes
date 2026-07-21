// #include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

// void traverse(std::vector<int> &arr, int n){
//	std::cout << "[ ";
//	for (int i = 0; i < n; i++)
//	{
//		std::cout << arr[i] << ", ";
//	}
//	std::cout << "]";
// }

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
std::vector<int> brute(std::vector<int> &nums)
{
    std::vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        int count{1};
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] == nums[i])
                count++;
        }

        if (count > (nums.size() / 3))
        {
            bool alreadyTaken = false;
            for (int x : ans)
            {
                if (x == nums[i])
                {
                    alreadyTaken = true;
                    break;
                }
            }

            if (!alreadyTaken)
            {
                ans.push_back(nums[i]);
            }
        }

        if (ans.size() == 2)
            break;
    }
    return ans;
}
//   TC=O(n^2), SC=O(n)

// Better Approach
std::vector<int> better(std::vector<int> &nums)
{
    std::vector<int> ans;
    std::unordered_map<int, int> mpp;

    for (int x : nums)
    {
        mpp[x]++;
        if (mpp[x] == (nums.size() / 3 + 1))
        {
            ans.push_back(x);
        }
    }

    return ans;
}
//   TC=O(n), SC=O(n), or SC=O(n log n)

// Optimal Approach
std::vector<int> optimal(std::vector<int> &nums)
{
    int n = nums.size();

    // Step 1: Find potential candidates
    int c1 = 0, c2 = 0;
    int cnt1 = 0, cnt2 = 0;

    for (int x : nums) {
        if (x == c1) {
            cnt1++;
        }
        else if (x == c2) {
            cnt2++;
        }
        else if (cnt1 == 0) {
            c1 = x;
            cnt1 = 1;
        }
        else if (cnt2 == 0) {
            c2 = x;
            cnt2 = 1;
        }
        else {
            cnt1--;
            cnt2--;
        }
    } // Upto This portion it is selectiong which 2 candidates are slected for the winner

    cnt1 = 0;
    cnt2 = 0;

    for (int x : nums) {
        if (x == c1) cnt1++;
        else if (x == c2) cnt2++;
    }

    std::vector<int> ans;
    if (cnt1 > n / 3) ans.push_back(c1);
    if (cnt2 > n / 3) ans.push_back(c2);

    return ans;
}
//   TC=O(n), SC=O(1)

int main()
{

    // std::vector<int> mj = {3, 2, 3};
    // std::vector<int> mj = {1};
    // std::vector<int> mj = {1, 2};
    std::vector<int> mj = {1, 2, 1, 3, 1};
    // std::vector<int> mj = {2, 2};

    traverse(mj);
    // std::vector<int> ans = brute(mj);
    // traverse(ans);

    // std::vector<int> ans = better(mj);
    // traverse(ans);

    std::vector<int> ans = optimal(mj);
    traverse(ans);
    return 0;
}