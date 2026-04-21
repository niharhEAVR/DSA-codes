#include <bits/stdc++.h>

int main()
{
    // std::vector<int> arr = {1, 2, 3, 4, 5, 6, 2, 325, 235, 21, 33, 5, 3, 5, 3, 6, 646, 346, 36, 66, 6, 6, 35, 46, 76};
    // int k = 3000;

    std::vector<int> arr = {2, 4, 1};
    int k = 5;
    
    std::sort(arr.begin(), arr.end());
    std::unordered_map<int, int> freq;

    int left{}, right{}, maxFreq{};
    long long sum{};

    for (int right = 0; right < arr.size(); right++)
    {
        sum += arr[right];

        long long cost = (long long)(arr[right]) * (right - left + 1) - sum;

        while (cost > k)
        {
            sum -= arr[left];
            left++;
            cost = (long long)(arr[right]) * (right - left + 1) - sum;
        }

        freq[arr[right]] = right-left+1;

        maxFreq = std::max(maxFreq, freq[arr[right]]);
    }

    std::cout << "Max freq is: " << maxFreq << std::endl;

    std::cout<< "[ ";
    for(auto i: freq){
        std::cout << "("<<i.first <<  "," << i.second << ")" << " ";
    }
    std::cout<< "]";

    return 0;
}
