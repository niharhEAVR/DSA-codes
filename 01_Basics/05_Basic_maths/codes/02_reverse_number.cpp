#include <iostream>

int main()
{
    int x = 72697863;
    int rev{}, mod{}, i{x};
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
    std::cout << rev;
    return 0;
}

// another more optimized solution:

int reverse(int x)
{

    int rev = 0;

    while (x != 0)
    {
        int digit = x % 10;

        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7))
            return 0;

        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8))
            return 0;

        rev = (rev * 10) + digit;

        x /= 10;
    }

    return rev;
}