#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void printNum(int i, int n){
    if(i>n) return;
    cout<<i<<endl;
    printNum(i+1,n);
}
// tc=o(n), sc=o(n) - stack space

void printNumReverse(int i, int n){
    if(i<n) return;
    cout<<i<<endl;
    printNumReverse(i-1,n);
}
// tc=o(n), sc=o(n) - stack space

int main()
{
    // printNum(1,5);
    printNumReverse(5,1);
    return 0;
}