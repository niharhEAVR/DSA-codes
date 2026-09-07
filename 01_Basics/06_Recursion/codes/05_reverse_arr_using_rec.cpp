#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void swapFunc(int l, int r, int arr[])
{
    if (l >= r)
        return;
    swap(arr[l], arr[r - 1]);
    swapFunc(l + 1, r - 1, arr);
}
// tc=o(n), sc=o(n) - stack space


void swapFunc2(int l, int r, int arr[])
{
    if (l >= r/2)
        return;
    swap(arr[l], arr[r-l-1]);
    swapFunc2(l + 1, r, arr);
}
// tc=o(n), sc=o(n) - stack space


int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    // swapFunc(0, n, arr);
    swapFunc2(0, n, arr);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }


    return 0;
}