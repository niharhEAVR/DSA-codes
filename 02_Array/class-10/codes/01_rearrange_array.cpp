// #include <bits/stdc++.h>

#include <iostream>
#include <vector>

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
void brute(std::vector<int> &nums)
{
    std::vector<int> pos;
    std::vector<int> neg;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < 0)
        {
            neg.push_back(nums[i]);
        }
        else
        {
            pos.push_back(nums[i]);
        }
    }

    for (int i = 0; i < nums.size() / 2; i++)
    {
        nums[i * 2] = pos[i];
        nums[i * 2 + 1] = neg[i];
    }
    // But TC = O(n) and SC = O(n)
}

// Optimal Approach
std::vector<int> optimal(std::vector<int> &nums)
{
    std::vector<int> ans(nums.size(), 0);
    int posIndex{}, negIndex{1};
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < 0)
        {
            ans[negIndex] = nums[i];
            negIndex += 2;
        }
        else
        {
            ans[posIndex] = nums[i];
            posIndex += 2;
        }
    }

    return ans;
    // But its still taking TC = O(n) and SC = O(n)
}

// SecondVarietyOptimal Approach for different size of sign elements (it might be more positive numbers, less negative number or vice-versa)
std::vector<int> SecondVarietyOptimal(std::vector<int> &nums)
{
    
    std::vector<int> pos;
    std::vector<int> neg;
    std::vector<int> ans(nums.size(),0);

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < 0)
        {
            neg.push_back(nums[i]);
        }
        else
        {
            pos.push_back(nums[i]);
        }
    }

    if (pos.size() > neg.size())
    {
        for (int i = 0; i < neg.size(); i++)
        {
            ans[i * 2] = pos[i];
            ans[i * 2 + 1] = neg[i];
        }

        int index = neg.size()*2;
        for (int i = neg.size(); i < pos.size(); i++)
        {
            ans[index++] = pos[i];
        }
    }
    else 
    {
        for (int i = 0; i < pos.size(); i++)
        {
            ans[i * 2] = pos[i];
            ans[i * 2 + 1] = neg[i];
        }
        
        int index = pos.size()*2;
        for (int i = pos.size(); i < neg.size(); i++)
        {
            ans[index++] = neg[i];
        }
    }

    return ans;
    // But its still taking TC = O(n)+O(n) = O(2n) or, O(n) and SC = O(n) + O(n) + O(n) = O(3n) or, O(n)
}

int main()
{

    // std::vector<int> nums = {3, 1, -2, -5, 2, -4};
    // std::vector<int> nums = {-1,1};
    std::vector<int> secondVariety = {-1, 1, 2, 3, 5, -4, 6, -3};

    // brute(nums);
    // traverse(nums, nums.size());

    // nums = optimal(nums);
    // traverse(nums, nums.size());

    secondVariety = SecondVarietyOptimal(secondVariety);
    traverse(secondVariety, secondVariety.size());

    return 0;
}