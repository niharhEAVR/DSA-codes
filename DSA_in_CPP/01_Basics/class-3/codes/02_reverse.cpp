#include <iostream>

int main()
{
    long long x = 72697863;
    long long rev{}, mod{}, i{x};
    while (i != 0)
    {
        mod = i % 10;
        if (rev > INT_MAX / 10 || rev < INT_MIN / 10)
        {
            std::cout << "Overflow occurred\n";
            return 0;
        }
        rev = (rev * 10) + mod;
        i /= 10;
    };
    std::cout<<rev;
    return 0;
}