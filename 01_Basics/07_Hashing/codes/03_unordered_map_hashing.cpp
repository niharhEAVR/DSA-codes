#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    // hashing using unordered_map, for sizing problem
    
    int arr2[] = {2, 1000000, 2, 50000000, 1000000};

    unordered_map<int, int> frecq;

    for (auto i : arr2)
    {
        frecq[i]++;
    }
    for (auto i : frecq)
    {
        std::cout << i.first << " repeated " << i.second << " times." << std::endl;
    }

    // search for a number in the array
    int x = 1000000;
    if (frecq.find(x) != frecq.end())
    {
        std::cout << x << " is present in the array." << std::endl;
    }
    else
    {
        std::cout << x << " is not present in the array." << std::endl;
    }

    return 0;
}