#include <bits/stdc++.h>

// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <algorithm>

using namespace std;

int main()
{

    vector<int> v = {1, 2, 3};

    do
    {
        for (int x : v)
            cout << x;
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));

    return 0;
}