#include <iostream>

bool isPalindrome(int x)
{
    if (x < 0) // negative numbers are not palindrome
    {
        return 0;
    }
    int copy = x;
    int palindrome{};
    while (x != 0)
    {
        int digit = x % 10;

        if (palindrome > INT_MAX / 10 || (palindrome == INT_MAX / 10 && digit > 7))
            return 0;

        if (palindrome < INT_MIN / 10 || (palindrome == INT_MIN / 10 && digit < -8))
            return 0;

        palindrome = (palindrome * 10) + digit;

        x /= 10;
    }
    return copy == palindrome;
}

bool palindrome(int x)
{
    if (x < 0)
        return false;

    int y = x;
    int reversed{};
    while (y != 0)
    {
        reversed = reversed * 10 + y % 10;
        y /= 10;
    }
    return reversed == x;
} // leetcode does optimized overflow check for this problem, so we don't need to worry about it here.