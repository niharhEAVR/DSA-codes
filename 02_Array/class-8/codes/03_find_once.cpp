#include <bits/stdc++.h>

void traverse(std::vector<int> &arr, int n)
{
    std::cout << "[ ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << "]";
}

// better approach
void fndo(std::vector<int> &nums)
{
    std::unordered_map<int, int> freq;
    for (int n : nums)
        freq[n]++;
    for (auto &p : freq)
    {
        if (p.second == 1)
            std::cout << p.first << std::endl;
    }
}

// optimal solution & this is very easy when you know this
// that using xor, Order does not matter if there is anything like anythings coming twice it will automatically vanishes at the end only the single pairs lefts 
void fndo2(std::vector<int> &nums)
{
    int xorr{};
    for (auto i : nums)
    {
        xorr ^= i;
    }
    std::cout << xorr;
}

int main()
{
    std::vector<int> nums = {4,1,2,2,1};
    // std::vector<int> nums = {1, 1, 2, 3, 3};
    // std::vector<int> nums = {1};
    fndo2(nums);

    return 0;
};