// solve it


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2,2, 3, 4, 5, 6, 7, 8, 9, 10};

    unordered_map<int, int> freq;

    for (auto i : arr)
    {
        freq[i]++;
    }

    int max_freq = INT_MIN;
    int min_freq = INT_MAX;

    for (auto i : freq)
    {
        max_freq = max(max_freq, i.second);
        min_freq = min(min_freq, i.second);
    }

    cout << "Maximum frequency: " << max_freq << endl;
    cout << "Elements with maximum frequency: ";
    for (auto i : freq)
    {
        if (i.second == max_freq)
            cout << i.first << ' ';
    }
    cout << endl;

    cout << "Minimum frequency: " << min_freq << endl;
    cout << "Elements with minimum frequency: ";
    for (auto i : freq)
    {
        if (i.second == min_freq)
            cout << i.first << ' ';
    }
    cout << endl;

    return 0;
}