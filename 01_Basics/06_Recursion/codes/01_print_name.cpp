#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void printNam(int i, int n){
    if(i>n) return;
    cout<<"nihar"<<endl;
    printNam(i+1,n);
}
// tc=o(n), sc=o(n) - stack space


void printNameUsRec(int n)
{
    if (n == 0)
        return;
    std::cout << "name" << std::endl;
    --n;
    printNameUsRec(n);
}


int main()
{
    // printNameUsRec(5);
    printNam(1,5);
    return 0;
}