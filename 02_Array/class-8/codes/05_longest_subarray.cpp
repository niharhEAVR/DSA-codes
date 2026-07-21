// First of all we want to clear that this hashing method concept is better approach for Positive Numbers
// And Optimal approach for Positive + Negative numbers


#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

void traverse(const unordered_map<int, int> &arr)
{
    cout << "[ ";
    for (auto it : arr)
    {
        cout << it.first << ":" << it.second << " ";
    }
    cout << "]\n";
}

int longSubArrBetterDebugging(vector<int> &nums, int k)
{
    if(nums.empty()) return 0;
    unordered_map<int, int> mp; // prefixSum -> first index
    int sum = 0;
    int maxLen = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        cout << "  map now: ";
        traverse(mp);
        sum += nums[i];
        cout << "i=" << i << " nums[i]=" << nums[i] << " sum=" << sum << '\n';

        // Case 1: if sum itself becomes k
        if (sum == k)
        {
            std::cout << "    case-1 if block" << std::endl;
            maxLen = max(maxLen, i + 1);
            cout << "  sum == k -> maxLen = " << maxLen << '\n';
        }

        // Case 2: if (sum - k) exists in map
        auto it = mp.find(sum - k);
        if (it != mp.end())
        {
            std::cout << "    case-2 if block" << std::endl;
            std::cout << "  [ sum =" << it->first << ": index = " << it->second << " ] != [ end (Invalid) ]" << std::endl;
            cout << "  found (sum-k)=" << (sum - k) << " in map at index " << it->second << '\n';
            int len = i - it->second;
            cout << "  candidate len = " << len << " (i - " << it->second << ")\n";
            maxLen = max(maxLen, len);
            cout << "  maxLen updated = " << maxLen << '\n';
        }
        else
        {
            std::cout << "    case-2 else block" << std::endl;
            std::cout << "  [ not found (Invalid) ] == [ end (Invalid) ]" << std::endl;
        }

        // Store prefix sum only the first time
        if (mp.find(sum) == mp.end())
        {
            std::cout << "    case-3 if block" << std::endl;
            cout << "  storing mp[" << sum << "] = " << i << '\n';
            mp[sum] = i;
        }
        else
        {
            std::cout << "    case-3 else block" << std::endl;
            cout << "  mp already has sum=" << sum << " at index " << mp[sum] << " (not overwriting)\n";
        }
        cout << "  map now: ";
        traverse(mp);
        cout << "---------------------------------\n";
    }

    return maxLen;
}

int longestSubarrayBetter(vector<int> &arr, int K)
{
    unordered_map<int, int> mp;
    int sum = 0;
    int maxLen = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        // case-1
        if (sum == K)
            maxLen = max(maxLen, i + 1);

        // case-2
        if (mp.find(sum - K) != mp.end())
        {
            int len = i - mp[sum - K];
            maxLen = max(maxLen, len);
        }

        // case-3
        if (mp.find(sum) == mp.end())
        {
            mp[sum] = i;
        }
    }

    return maxLen;
}

// TC = O(n log n) for map and O(n^2) for unordered map
// SC = O(n)

int main()
{
    vector<int> nums = {1, 2, -1, 2, -1, 3};
    vector<int> nums2 = {1, 2, 0, 0, 0, 0, 3};
    vector<int> nums3 = {1,2,1,2,1};
    int k = 3;
    // cout << longSubArrBetterDebugging(nums, k) << " = Result" << endl;
    // cout << longSubArrBetterDebugging(nums2, k) << " = Result" << endl;
    cout << longSubArrBetterDebugging(nums3, k) << " = Result" << endl;

    return 0;
}
