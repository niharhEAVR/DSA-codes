#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// fibo 0,1,1,2,3,5,8,.......
// in fibonacci we always talks about the place, not the actual number.
// ex. if n=6, there is no 6 in fibonacci, but at 6th place number is 8
// And fibonacci is mainly starts with index 0.

int fibo(int i)
{
    if(i<=1) return i;
    return fibo(i-1) + fibo(i-2);
}
// tc=o(n), sc=o(n) - stack space

int main()
{
    cout << fibo(6);

    return 0;
}



        //                           fib(5)
        //                       /              \
        //                 fib(4)                 fib(3)
        //                /      \               /      \
        //          fib(3)       fib(2)       fib(2)    fib(1) return 1
        //         /     \       /   \         /   \       
        //    fib(2)   fib(1) fib(1) fib(0)  fib(1) fib(0) return 1
        //    /   \   return 1     return 1
        // fib(1) fib(0)
        // return 1