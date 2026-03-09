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

// bad solution
// void mis(std::vector<int> &nums)
// {
//     std::sort(nums.begin(), nums.end());
//     nums.push_back(0);
//     int flag{};
//     for (int i = 0; i < nums.size() + 1; i++)
//     {
//         if (!(nums[i] == i))
//         {
//             flag = i;
//             break;
//         }
//     }
//     std::cout<<flag<<std::endl;
//     traverse(nums, nums.size());
//     nums.pop_back();
//     traverse(nums, nums.size());
// }

// two optimal solution
// 1st (using math formula `sum of first 10 naturals numbers`)
// here the 10 means the total size of an array use logic and you will understand
void mis2(std::vector<int> &nums)
{
    // we will find the sums or first 10 naturals numbers
    long long sum = (nums.size() * (nums.size() + 1)) / 2;
    long long afterSumVal{};
    for (int i = 0; i < nums.size(); i++)
    {
        afterSumVal += nums[i];
    }
    std::cout << sum - afterSumVal << std::endl;
}

// 2nd (using XOR) Legend solution

void mis3(std::vector<int> &nums)
{
    int xor1{}, xor2{};
    for (int i = 0; i < nums.size(); i++)
    {
        xor1 ^= (i + 1);
        xor2 ^= nums[i];
    }

    std::cout << (xor1 ^ xor2) << std::endl;
}

int main()
{
    std::vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1, 8};
    // mis(nums);
    // mis2(nums);
    mis3(nums);

    return 0;
}