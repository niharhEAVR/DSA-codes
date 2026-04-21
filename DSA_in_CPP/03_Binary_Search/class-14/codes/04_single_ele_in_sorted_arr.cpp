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

// Optimal Approach
int optimal(std::vector<int> &nums)
{

    if (nums.size() == 1)
        return nums[0];
    if(nums[0] != nums[1]) return nums[0];
    if (nums[nums.size() - 1] != nums[nums.size() - 2])
        return nums[nums.size() - 1];

    int low = 1, high = nums.size() - 2;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            return nums[mid];
        if(nums[mid] == nums[mid-1] && (mid-1)%2==0) low = mid+1;
        if(nums[mid] == nums[mid+1] && (mid+1)%2==0) high = mid-1;
        
        if(nums[mid] == nums[mid-1] && (mid-1)%2!=0) high = mid-1;
        if(nums[mid] == nums[mid+1] && (mid+1)%2!=0) low = mid-1;

        // optimize this 4 if statements
    }

    return -1;
}
//   TC=O(), SC=O()

int main()
{

    std::vector<int> nums{1,2,2,3,3};
    int val = optimal(nums);
    std::cout<<val;

    return 0;
}