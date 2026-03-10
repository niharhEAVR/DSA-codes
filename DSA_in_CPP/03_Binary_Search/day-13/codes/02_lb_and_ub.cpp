#include <iostream>
#include <vector>

int lowerBound(std::vector<int> &arr, int x)
{
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high)
    {
        int mid = (low + high) >> 1;

        if (arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int upperBound(std::vector<int> &arr, int x)
{
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high)
    {
        int mid = (low + high) >> 1;

        if (arr[mid] > x)
        {
            ans = mid;
            high = mid - 1; // go LEFT
        }
        else
        {
            low = mid + 1; // go RIGHT
        }
    }
    return ans;
}

int main()
{
    std::vector<int> arr = {2,2,2,2,2};
    int x=2;

    int lb = lowerBound(arr, x);
    int ub = upperBound(arr, x);

    std::cout << ub-lb << std::endl;


    return 0;
}