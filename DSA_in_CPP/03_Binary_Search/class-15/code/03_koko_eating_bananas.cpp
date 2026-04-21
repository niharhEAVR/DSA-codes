// #include <bits/stdc++.h>

#include <iostream>
#include <vector>
// #include <unordered_map>
// #include <algorithm>
#include<cmath>

//void traverse(std::vector<int> &arr, int n){
//	std::cout << '[ ';
//	for (int i = 0; i < n; i++)
//	{
//		std::cout << arr[i] << ', ';
//	}
//	std::cout << ']';
//}

//void traverse(std::vector<int> &nums){
//	std::cout << '[ ';
//	for (auto it = nums.begin(); it != nums.end(); it++){
//		it+1 == nums.end() ? std::cout << *it << ' ' : std::cout << *it << ', ';
//	}
//	std::cout << ']';
//}

// Brute Approach
void brute(){
    
}
//   TC=O(), SC=O()

// Better Approach
void better(){
    
}
//   TC=O(), SC=O()


int maxEle(std::vector<int> &nums){
    int maxele = nums[0];
    for (size_t i = 0; i < nums.size(); i++)
    {
        maxele = std::max(maxele,nums[i]);
    }
    return maxele;
}
long long totalTimeTaken(std::vector<int> &nums, int mid){

    long long totalTime{};

    for (size_t i = 0; i < nums.size(); i++)
    {
        totalTime += (nums[i]+mid-1)/mid;
    }
    
    return totalTime;
}

// Optimal Approach
int optimal(std::vector<int> &nums, int h){
    int low{1}, high(maxEle(nums));

    while(low<=high){
        int mid = low+(high-low)/2;
        if(totalTimeTaken(nums, mid) <= h){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }

    return low;

}
//   TC=O(), SC=O()

int main(){
    
    std::vector<int> nums = {805306368,805306368,805306368};
    int h = 1000000000;

    int value = optimal(nums, h);
    std::cout << value << std::endl;
    
    return 0;
}