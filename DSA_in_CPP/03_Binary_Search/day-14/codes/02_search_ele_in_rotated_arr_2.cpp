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
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if(nums[mid] == target) return true;

        if(nums[low] == nums[mid] && nums[mid] == nums[high]){
            high--;
            low++;
            continue;
        }

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
    return false;
}
//   TC=O(log n), SC=O(1)

int main()
{

    std::vector<int> arr = {1,0,1,1,1};
    int target = 0;

    // std::vector<int> arr = {2,5,6,0,0,1,2};
    // int target = 3;


    bool result = optimal(arr, target);

    std::cout << "result: " << (result ? "true" : "false") << std::endl;
    return 0;
}