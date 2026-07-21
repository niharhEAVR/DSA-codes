// #include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <algorithm>

void traverse(std::vector<int> &arr, int n)
{
    std::cout << "[ ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << "]";
}

// Brute Approach 
std::vector<int> brute(std::vector<int> &nums)
{

    std::vector<int> ans;
    int leader;
    for (int i = 0; i < nums.size(); i++)
    {
        leader = nums[i];
        for (int j = i+1; j < nums.size(); j++)
        {
            if (nums[j] > leader)
            {
                leader = nums[j];
            }
        }
        if(ans.empty()){
            ans.push_back(leader);
        }
        else if(ans.back() != leader){
            ans.push_back(leader);
        }
    }

    return ans;
}
// TC=O(n^2), SC=O(n)


// Optimal Approach
std::vector<int> optimal(std::vector<int> &nums)
{
    std::vector<int> ans;
    int maxi = INT_MIN;
    for (int i = nums.size()-1; i >=0; i--)
    {
        if(nums[i] > maxi){
            ans.push_back(nums[i]);
        }
        maxi = std::max(maxi, nums[i]);
    }
    
    std::reverse(ans.begin(), ans.end());
    return ans;

}
// TC=O(n), SC=O(n)

int main()
{

    std::vector<int> nums = {10, 22, 12, 3, 0, 6};
    
    std::vector<int> nums2 = {5,4,3,2,1};
    // std::vector<int> ans = brute(nums);
    // std::vector<int> ans = brute(nums2);
    // traverse(ans, ans.size());
    
    
    // std::vector<int> ans2 = optimal(nums);
    std::vector<int> ans2 = optimal(nums2);
    traverse(ans2, ans2.size());

    return 0;
}