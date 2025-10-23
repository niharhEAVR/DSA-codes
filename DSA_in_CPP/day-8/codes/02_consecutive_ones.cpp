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

// this is my logic and its bad solution;
void conscutiveOnes(std::vector<int> &nums)
{
    std::vector<int> flags;
    int flag{};
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == 1){
            flag++;
        }else{
            flags.push_back(flag);
            flag=0;
        }
        if (i == nums.size()-1)
        {
            flags.push_back(flag);
        }
        
    }
    std::sort(flags.begin(), flags.end());
    std::cout<<flags[flags.size()-1]<<std::endl;
}

// slight optimal logic
void conscutiveOnes2(std::vector<int> &nums)
{
    int flag{}, maxi{};
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == 1){
            flag++;
            maxi = std::max(maxi, flag);
        }else{
            flag=0;
        }
    }
    std::cout<<maxi<<std::endl;
}



int main()
{
    std::vector<int> nums = {1,0,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,0};
    // conscutiveOnes(nums);
    conscutiveOnes2(nums);

    return 0;
}