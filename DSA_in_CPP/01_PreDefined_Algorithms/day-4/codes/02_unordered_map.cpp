#include <bits/stdc++.h>

int main()
{
    int arr[] = {1,2,3,4,5,6,2,325,235,21,33,5,3,5,3,6,646,346,36,66,6,6,35,46,76};

    std::unordered_map<int, int> frecq;

    for(auto i:arr){
        frecq[i]++;
    }
    for (auto i : frecq)
    {
        std::cout<< i.first << " repeated " << i.second << " times."<< std::endl;
    }

    return 0;
}