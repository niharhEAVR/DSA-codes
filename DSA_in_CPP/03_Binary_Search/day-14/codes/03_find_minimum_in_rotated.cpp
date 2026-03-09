// #include <bits/stdc++.h>

#include <iostream>
#include <vector>
// #include <unordered_map>
// #include <algorithm>

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

// Optimal Approach by me
int optimal(std::vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;
    int lowest = nums[0];
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] <= lowest)
            lowest = nums[mid];

        if (nums[low] < nums[mid])
        {
            if (nums[low] < lowest && lowest <= nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (nums[mid] < lowest && lowest <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return lowest;
}
//   TC=O(log n), SC=O(1)

// Optimal Approach by striver
int optimalTwo(std::vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;
    int lowest = INT_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[low] <= nums[mid])
        {
            lowest = std::min(lowest, nums[low]);
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
            lowest = std::min(lowest, nums[mid]);
        }
    }
    return lowest;
}
//   TC=O(log n), SC=O(1)

int main()
{

    // std::vector<int> arr = {3,4,5,1,2};

    // std::vector<int> arr = {2, 1};

    std::vector<int> arr = {11, 13, 15, 17};

    // bool result = optimal(arr);
    bool result = optimalTwo(arr);

    std::cout << "result: " << result << std::endl;
    return 0;
}