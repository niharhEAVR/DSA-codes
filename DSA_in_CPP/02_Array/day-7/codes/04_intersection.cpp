#include <bits/stdc++.h>
using namespace std;

void traverse(vector<int> &arr)
{
    cout << "[ ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << (i + 1 == arr.size() ? "" : ", ");
    cout << " ]";
}

vector<int> intersecF(vector<int> &nums, vector<int> &nums2)
{
    sort(nums.begin(), nums.end()); // after sort the array becomes [0, 0, 1, 3, 12]
    sort(nums2.begin(), nums2.end()); // after sort the array becomes [0, 1, 2, 3, 5, 6, 18]

    int i = 0, j = 0;
    vector<int> ans;

    while (i < nums.size() && j < nums2.size())
    {
        if (nums[i] == nums2[j])
        {
            if (ans.empty() || ans.back() != nums[i])
                ans.push_back(nums[i]);
            i++;
            j++;
        }
        else if (nums[i] < nums2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    traverse(ans);
    return ans;
}

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    vector<int> nums2 = {0, 5, 6, 2, 3, 1, 18};

    intersecF(nums, nums2);
    return 0;
}
