#include <iostream>
#include <vector>
// #include <unordered_map>
// #include <algorithm>

void traverse(std::vector<int> &arr, int n)
{
    std::cout << "[ ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << "]";
}

// void traverse(std::vector<int> &nums){
//	std::cout << "[ ";
//	for (auto it = nums.begin(); it != nums.end(); it++){
//		it+1 == nums.end() ? std::cout << *it << " " : std::cout << *it << ", ";
//	}
//	std::cout << "]";
// }

// Optimal Approach
std::vector<int> Optimal(std::vector<int> &nums, int target)
{

    int low = 0, high = nums.size() - 1;
    std::vector<int> ans = {-1, -1};

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] >= target)
        {
            if (nums[mid] == target)
            ans[0] = mid;
            high = mid - 1; // try to find smaller ≥ x
        }
        else
        {
            low = mid + 1;
        }
    }
    
    low = 0, high = nums.size() - 1;
    
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        
        if (nums[mid] <= target)
        {
            if (nums[mid] == target)
                ans[1] = mid;
            low = mid + 1; // try to find bigger ≤ x
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}
//   TC=O(log n + log n = log n), SC=O(1)

int main()
{

    std::vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 0;

    std::vector<int> result = Optimal(nums, target);
    traverse(result, result.size());

    return 0;
}