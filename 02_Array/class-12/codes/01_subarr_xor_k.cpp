// #include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <unordered_map>

void traverse(std::vector<int> &nums)
{
    std::cout << "[ ";
    for (auto it = nums.begin(); it != nums.end(); it++)
    {
        it + 1 == nums.end() ? std::cout << *it << " " : std::cout << *it << ", ";
    }
    std::cout << "]";
}

void nestedTraverse(std::vector<std::vector<int>> &nums)
{

    std::cout << "[";

    for (auto it = nums.begin(); it != nums.end(); it++)
    {
        traverse(*it);

        if (it + 1 != nums.end())
            std::cout << ",";
    }
    std::cout << "]" << std::endl;
}

void brute(const std::vector<int> &arr, int K)
{
    std::vector<std::vector<int>> ans;
    int n = arr.size();
    int count = 0;
    // if(n==0) return 0;

    for (int l = 0; l < n; ++l)
    {
        for (int r = l; r < n; ++r)
        {
            int x = 0;
            for (int i = l; i <= r; ++i)
            {
                x ^= arr[i];
            }
            if (x == K)
            {
                ++count;
                std::vector<int> temp;
                for (int i = l; i <= r; ++i)
                {
                    temp.push_back(arr[i]);
                }
                ans.push_back(temp);
            }
        }
    }
    nestedTraverse(ans);
    // return count;
}
//   TC=O(n^3), SC=O(1) sc is 1 becasue on the original program we are only returning the value of count.

// Better Aproach in on the docs

// Optimal Approach
int optimal(std::vector<int> &arr, int K)
{
    std::unordered_map<int, int> mp;

    // IMPORTANT: store 0 once
    mp[0] = 1;

    int prefixXor = 0;
    int count = 0;

    for (int num : arr)
    {
        // step 1: build prefix xor
        prefixXor ^= num;

        // step 2: find the needed value
        int need = prefixXor ^ K;

        // step 3: if need is in map -> add all its occurrences
        if (mp.find(need) != mp.end())
        {
            count += mp[need];
        }

        // step 4: store this prefixXor into map
        mp[prefixXor]++;
    }

    return count;
}
//   TC=O(n), SC=O(n)


int main()
{

    std::vector<int> arr = {4, 2, 2, 6, 4};
    int K = 6;

    brute(arr, K);

    std::cout << optimal(arr, K) << std::endl;

    return 0;
}