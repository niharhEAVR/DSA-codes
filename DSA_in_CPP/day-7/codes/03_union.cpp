
#include <bits/stdc++.h>

#include <iostream>

void traverse(std::vector<int> &arr, int n)
{
    std::cout << "[ ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << "]";
}

// Brute force Approach
// std::vector<int> unionf(std::vector<int> &nums, std::vector<int> &nums2)
// {
//     std::set<int> st;
//     for (size_t i = 0; i < nums.size(); i++)
//     {
//         st.insert(nums[i]);
//     }
//     for (size_t i = 0; i < nums2.size(); i++)
//     {
//         st.insert(nums2[i]);
//     }

//     std::vector<int> temp;
//     for (auto it : st)
//     {
//         temp.push_back(it);
//     }
//     traverse(temp, temp.size());
//     return temp;

// }

// optimal approach (we have to sort it first)
std::vector<int> unionf(std::vector<int> &nums, std::vector<int> &nums2)
{
    std::sort(nums.begin(), nums.end());
    std::sort(nums2.begin(), nums2.end());
    int i{}, j{};
    std::vector<int> temp;

    while (i < nums.size() && j < nums2.size())
    {
        if (nums[i] <= nums2[j])
        {
            if (temp.size() == 0 || temp.back() != nums[i])
            {
                temp.push_back(nums[i]);
            }
            i++;
        }
        else
        {
            if (temp.size() == 0 || temp.back() != nums2[j])
            {
                temp.push_back(nums2[j]);
            }
            j++;
        }
    }
    while (j < nums2.size())
    {
        if (temp.size() == 0 || temp.back() != nums2[j])
        {
            temp.push_back(nums2[j]);
        }
        j++;
    }

    while (i < nums.size())
    {
        if (temp.size() == 0 || temp.back() != nums[i])
        {
            temp.push_back(nums[i]);
        }
        i++;
    }

    traverse(temp, temp.size());
    return temp;
}

int main()
{

    std::vector<int> nums = {0, 1, 0, 3, 12};
    std::vector<int> nums2 = {0, 5, 6, 2, 3, 1, 18};

    unionf(nums, nums2);
    return 0;
}

//  need a more good solution for the leetcode
