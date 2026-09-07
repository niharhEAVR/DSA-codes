#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void printNumBT(int i, int n){
    if(i>n) return;
    printNumBT(i+1,n);
    cout<<i<<endl;
}
// tc=o(n), sc=o(n) - stack space

void printNumReverseBT(int i, int n){
    if(i<n) return;
    printNumReverseBT(i-1,n);
    cout<<i<<endl;
}
// tc=o(n), sc=o(n) - stack space

int main()
{
    printNumBT(1,5);
    printNumReverseBT(5,1);
    return 0;
}