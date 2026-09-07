#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void parameterizedPrintSum(int i, int sum)
{
    if (i < 1)
    {
        cout << sum;
        return;
    };
    parameterizedPrintSum(i - 1, sum + i);
}
// tc=o(n), sc=o(n) - stack space

int functionalPrintSum(int sum)
{
    if (sum < 0)
        return 0;
    return sum + functionalPrintSum(sum - 1);
}
// tc=o(n), sc=o(n) - stack space

int functionalPrintfacto(int facto)
{
    if (facto == 0)
        return 1; // because 0! is 1
    return facto * functionalPrintfacto(facto - 1);
}
// tc=o(n), sc=o(n) - stack space

int main()
{
    // parameterizedPrintSum(20, 0);
    cout << functionalPrintSum(5) << endl;

    cout << functionalPrintfacto(5);
    return 0;
}