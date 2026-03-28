// #include <bits/stdc++.h>

#include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <algorithm>
#include <cmath>

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

// Optimal Approach
int optimal(int num, int n){
    int low = 1, high = num;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(std::pow(mid, n) == num){
            return mid;
        }
        else if(std::pow(mid, n) <= num){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1; 
}
//   TC=O(log n), SC=O(1)

int main(){
    
    int num  = 69;
    int n  = 4;

    int value = optimal(num, n);
    std::cout<<value<<std::endl;

    
    return 0;
}