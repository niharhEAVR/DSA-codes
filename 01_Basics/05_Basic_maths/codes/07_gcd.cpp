// #include <bits/stdc++.h>

#include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <algorithm>

int gcd(int a, int b)
{
    while (b != 0)
    {
        int rem = a % b;
        a = b;
        b = rem;
    }

    return a;
}


int main(){
    
    int a, b;
    std::cout << "Enter two positive integers: ";
    std::cin >> a >> b;

    int result = gcd(a, b);

    std::cout << "The GCD of " << a << " and " << b << " is: " << result << std::endl;

    return 0;
}