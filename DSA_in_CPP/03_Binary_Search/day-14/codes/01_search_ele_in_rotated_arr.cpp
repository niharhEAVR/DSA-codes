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


// Optimal Approach
int optimal(std::vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int ans{-1};
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if(nums[mid] == target) return mid;

        if (nums[low] <= nums[mid])
        {
            if (nums[low] <= target && target <= nums[mid])
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
            if (nums[mid] <= target && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return ans;
}
//   TC=O(log n), SC=O(1)

int main()
{

    // std::vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    // int target = 0;

    std::vector<int> arr = {6, 7, 8, 1, 2, 3, 4, 5};
    int target = 3;

    // std::vector<int> arr = {1};
    // int target = 0;

    int result = optimal(arr, target);

    std::cout << "result: " << result;
    return 0;
}