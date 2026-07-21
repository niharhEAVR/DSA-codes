// #include <bits/stdc++.h>

#include <iostream>
#include <vector>

// Optimal Approach Math
std::pair<int, int> optimalMath(std::vector<int> &nums)
{
    int n = nums.size();
    // Sum of n natural numbers is (n*(n+1))/2
    // Sum of n^2 natural numbers is (n*(n+1)*(2*n+1))/n
    long long E1 = (1LL * n * (n + 1)) / 2;               // expected sum
    long long E2 = (1LL * n * (n + 1) * (2 * n + 1)) / 6; // expected square sum

    long long S1 = 0, S2 = 0;
    for (long long x : nums)
    {
        S1 += x;
        S2 += 1LL * x * x;
    }

    // Before diving in this solution read this doc first 07_small_concept.md

    // int x; // repeating num
    // int y; // missing num
    // x-y == arrSum-originalSum;
    // x-y = -4; --- eq(i)

    // On the same way we can find the square sum difference
    // int x; // repeating square num
    // int y; // missing square num
    // we can that from eq(i)
    // x^2 - y^2 == arrSqaureSum - originalSquareSum;
    // x^2 - y^2 = -24; --- eq(ii)
    // xe can the simplify the eq(ii) more.
    // a^2 - b^2 = (a+b) * (a-b)
    // (x+y) * (x-y) = -24
    // x+y = -24/x-y
    // x+y = -24/-4 -- from eq(i)
    // x+y = 6
    // y = 6 - x --- eq(iii)

    // now lets put the eq(iii) in eq(i)
    // x-y=-4
    // x-(6-x) = -4
    // x-6+x = -4
    // 2x = -4+6
    // x= 2/2
    // x=1 --- eq(iv)

    // now get the missing num
    // x-y = -4
    // 1-y = -4
    // -y = -4-1
    // y=5 --- eq(v)

    // So from the above calculations we have
    // Repeating number (x) = 1
    // Missing number (y) = 5

    long long D = S1 - E1; // x - y
    long long Q = S2 - E2; // x^2 - y^2 = (x-y)(x+y)

    long long sum_xy = Q / D; // x + y

    long long x = (D + sum_xy) / 2;
    long long y = x - D; // 1 - (-4) == 1+4 == 5

    return {(int)x, (int)y}; // (repeating, missing)
}
//   TC=O(n), SC=O(1)

// Optimal Approach XOR
std::pair<int, int> optimalXor(std::vector<int> &nums)
{
    // 1. Find the XOR of all elements in the array and numbers from 1 to n
    int Xor{0};
    for (int i{}; i < nums.size(); i++)
    {
        Xor ^= nums[i];
        Xor ^= (i + 1);
    }
    std::cout << Xor << std::endl;

    // 2. Now find the bit number where the difference happened.
    // As we know from bit manupulation  that If two numbers are different, then they MUST differ in at least one bit.
    // like for this example the Xor comes out 4, which is 100 in binary and the Right most bit is difference
    // if we have taken a diff ex like nums = [1, 3, 4, 5, 3], then Xor would came out 1 and binary would be 001, so the Left most bit is different
    // Now find the bit number for this example where the bit is differ

    // option 1:
    // int bitNo{};
    // while (true)
    // {
    //     if ((Xor & (1 << bitNo)) != 0)
    //     {
    //         break;
    //     }
    //     bitNo++;
    // } // This will find any kind of value's bit number at any positions.
    // option 2:
    int bitNo = Xor & -Xor;

    std::cout << bitNo << std::endl;

    // 3. Now we have to gourp all the numbers based on thier bit positions 0's or 1's
    int bucketOfOnes = 0, bucketOfZeros = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (bitNo <= 0)
        {
            // part of 1's club for array elements
            if ((nums[i] & /*(1 << bitNo) or */ bitNo) == 0)
                bucketOfOnes ^= nums[i];
            // part of 0'th club for array elements
            else
                bucketOfZeros ^= nums[i];

            // part of 1's club for 1-n numbers
            if (((i + 1) & /*(1 << bitNo) or */ bitNo) == 0)
                bucketOfOnes ^= (i + 1);
            // part of 0'th club for 1-n numbers
            else
                bucketOfZeros ^= (i + 1);
        }
        else
        {
            // part of 1's club for array elements
            if ((nums[i] & /*(1 << bitNo) or */ bitNo) != 0)
                bucketOfOnes ^= nums[i];
            // part of 0'th club for array elements
            else
                bucketOfZeros ^= nums[i];

            // part of 1's club for 1-n numbers
            if (((i + 1) & /*(1 << bitNo) or */ bitNo) != 0)
                bucketOfOnes ^= (i + 1);
            // part of 0'th club for 1-n numbers
            else
                bucketOfZeros ^= (i + 1);
        }
    }

    std::cout << bucketOfOnes << std::endl;
    std::cout << bucketOfZeros << std::endl;

    int cnt{};
    for (int x : nums)
        if (x == bucketOfZeros)
            cnt++;

    if (cnt == 2)
        return {bucketOfZeros, bucketOfOnes}; // repeating, missing
    else
        return {bucketOfOnes, bucketOfZeros};
}
//   TC=O(4n = n), SC=O(1)

int main()
{
    // std::vector<int> nums = {4, 3, 6, 2, 1, 1};
    std::vector<int> nums = {1, 3, 4, 5, 3};
    // auto [repeatNum, missNum] = optimalMath(nums); // array destructuring in C++17
    // std::cout << "Missing Number using Math method: " << missNum << "\n";
    // std::cout << "Repeating Number using Math method: " << repeatNum << "\n";

    auto [repeatNum, missNum] = optimalXor(nums);
    std::cout << "Missing Number using XOR method: " << missNum << "\n";
    std::cout << "Repeating Number using XOR method: " << repeatNum << "\n";

    return 0;
}
