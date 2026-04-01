// #include <bits/stdc++.h>

#include <iostream>
#include <vector>
// #include <unordered_map>
// #include <algorithm>
#include <cmath>

// void traverse(std::vector<int> &arr, int n){
//	std::cout << '[ ';
//	for (int i = 0; i < n; i++)
//	{
//		std::cout << arr[i] << ', ';
//	}
//	std::cout << ']';
// }

// void traverse(std::vector<int> &nums){
//	std::cout << '[ ';
//	for (auto it = nums.begin(); it != nums.end(); it++){
//		it+1 == nums.end() ? std::cout << *it << ' ' : std::cout << *it << ', ';
//	}
//	std::cout << ']';
// }

// Brute Approach
void brute()
{
}
//   TC=O(), SC=O()

// Better Approach
void better()
{
}
//   TC=O(), SC=O()

std::vector<int> maxMinEle(std::vector<int> &nums)
{
    int maxele = nums[0];
    int minele = nums[0];
    for (size_t i = 0; i < nums.size(); i++)
    {
        minele = std::min(minele, nums[i]);
        maxele = std::max(maxele, nums[i]);
    }
    return {minele, maxele};
}
int possibleOutcome(std::vector<int> &nums, int mid)
{

    int counter{};
    for (size_t i = 0; i < nums.size(); i++)
    {
        counter+=(nums[i] + mid - 1) / mid;
    }
    return counter;
}

// Optimal Approach
int optimal(std::vector<int> &nums, int threshold)
{
    std::vector<int> minMax = maxMinEle(nums);
    int low{1}, high(minMax[1]);
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (possibleOutcome(nums, mid) <= threshold)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}
//   TC=O(), SC=O()

int main()
{

    std::vector<int> nums = {21212,10101,12121};
    int threshold = 100000;

    int value = optimal(nums, threshold);
    std::cout << value << std::endl;

    return 0;
}