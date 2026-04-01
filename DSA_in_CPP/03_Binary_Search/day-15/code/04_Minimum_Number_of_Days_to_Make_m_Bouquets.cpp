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
int possibleOutcome(std::vector<int> &nums, int mid, int k)
{

    int adjecentFlowerCounter{};
    int totalBouket{};
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] <= mid)
        {
            adjecentFlowerCounter++;
            if (adjecentFlowerCounter == k)
            {
                totalBouket++;
                adjecentFlowerCounter = 0;
            }
        }
        else
        {
            adjecentFlowerCounter = 0;
        }
    }
    return totalBouket;
}

// Optimal Approach
int optimal(std::vector<int> &nums, int m, int k)
{
    std::vector<int> minMax = maxMinEle(nums);
    int low{minMax[0]}, high(minMax[1]);
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        std::cout << "low: " << low << ", high: " << high << ", mid: " << mid << std::endl;
        std::cout << "possibleOutcome: " << possibleOutcome(nums, mid, k) << std::endl;
        std::cout << "-----------------------------" << std::endl;
        if (possibleOutcome(nums, mid, k) >= m)
        {
            ans = mid;
            high = mid - 1;
        }
        else if(possibleOutcome(nums, mid, k) < m)
        {
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    return ans;
}
//   TC=O(), SC=O()

int main()
{

    std::vector<int> nums = {1000000000,1000000000};
    int m = 1, k = 1;

    int value = optimal(nums, m, k);
    std::cout << value << std::endl;

    return 0;
}