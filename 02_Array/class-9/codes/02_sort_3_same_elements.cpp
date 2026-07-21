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

// // brute force approach O(n log n)
// void sortSame3(std::vector<int> &nums)
// {
//     std::vector<int> arr;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         arr.push_back(nums[i]);
//     }

//     std::sort(arr.begin(), arr.end());

//     traverse(arr, arr.size());
    
// }

// // better approach Hashing O(2n) , sc O(1)
// void sortSame3(std::vector<int> &nums)
// {
//     int ct0{},ct1{},ct2{};

//     for (int i = 0; i < nums.size(); i++)
//     {
//         if(nums[i] == 0) ct0++;
//         else if(nums[i] == 1) ct1++;
//         else ct2++;
//     }

//     for (int i = 0; i < ct0; i++)
//     {
//         nums[i] = 0;
//     }
//     for (int i = ct0; i < ct0+ct1; i++)
//     {
//         nums[i] = 1;
//     }
//     for (int i = ct0+ct1; i < ct0+ct1+ct2; i++)
//     {
//         nums[i] = 2;
//     }
    
//     traverse(nums, nums.size());
// }

// optimal solution dutch national flag algo
void sortSame3(std::vector<int> &nums)
{
    int n = nums.size()-1;
    int low{0},mid{0},high{n};

    while(mid<=high){
        if(nums[mid] == 0){
            std::swap(nums[low], nums[mid]);
            low++, mid++;
        }
        else if(nums[mid] == 1){
            mid++;
        }
        else{
            std::swap(nums[mid] , nums[high]);
            high--;
        }
    }

    traverse(nums, nums.size());

}

int main()
{
    std::vector<int> nums = {2,0,2,1,1,0};
    
    sortSame3(nums);
    
    return 0;
}