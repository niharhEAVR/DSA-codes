#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool swapFunc2(int l, int r, string s)
{
    if (l >= r / 2)
        return true;
    if (s[l] != s[r - l - 1])
        return false;
    return swapFunc2(l + 1, r, s);
}
// tc=o(n), sc=o(n) - stack space

int main()
{
    string s = "madam";
    int n = s.size();
    bool pal = swapFunc2(0, n, s);

    cout << pal;

    return 0;
}