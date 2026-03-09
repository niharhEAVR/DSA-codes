// #include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <algorithm>

void traverse(std::vector<int> &nums)
{
    std::cout << "[ ";
    for (auto it = nums.begin(); it != nums.end(); it++)
    {
        it + 1 == nums.end() ? std::cout << *it << " " : std::cout << *it << ", ";
    }
    std::cout << "]";
}

// There is brute & better approach but those will take extra spaces, so no need.

void optimal(std::vector<int> &nums1, std::vector<int> &nums2, int m, int n)
{
    int i = m - 1;     // last real element of nums1
    int j = n - 1;     // last element of nums2
    int k = m + n - 1; // last position of nums1

    // Merge from the back
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
        }
        else
        {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // If nums2 still has elements left
    while (j >= 0)
    {
        nums1[k] = nums2[j];
        j--;
        k--;
    }

    // traverse(nums1);
}
//   TC=O(m+n), SC=O(1)

void optimalGap(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
{
    // Step 1: Put nums2’s elements into nums1’s empty spaces
    for (int i = 0; i < n; i++)
    {
        nums1[m + i] = nums2[i];
    }
    traverse(nums1);
    
    // Now nums1 contains m+n elements but not sorted yet
    int total = m + n;

    // Gap function
    auto nextGap = [&](int gap)
    {
        if (gap <= 1)
            return 0;
        return (gap / 2) + (gap % 2);
    };
    
    // Step 2: Apply GAP sorting logic
    for (int gap = nextGap(total); gap > 0; gap = nextGap(gap))
    {
        int left = 0;
        int right = left + gap;

        while (right < total)
        {
            if (nums1[left] > nums1[right])
            {
                std::swap(nums1[left], nums1[right]);
            }
            left++;
            right++;
        }
    }
    traverse(nums1);
}
//   TC=O(n log n), SC=O(1)

int main()
{

    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> nums2 = {2, 5, 6};

    int m = 3, n = 3;

    // optimal(nums1, nums2, m, n);
    optimalGap(nums1, m, nums2, n);

    return 0;
}