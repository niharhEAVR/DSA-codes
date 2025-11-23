#include <iostream>
#include <vector>
#include <algorithm>

void traverse(std::vector<long long> &nums)
{
    std::cout << "[";
    for (auto it = nums.begin(); it != nums.end(); it++)
    {
        it + 1 == nums.end() ? std::cout << *it << "" : std::cout << *it << ",";
    }
    std::cout << "]";
}

long long pascalValueOptimal(int r, int c)
{
    // This solves the problem of Find element at (row=r, col=c)
    long long ans = 1;
    int n = r - 1;
    int k = c - 1;

    for (int i = 1; i <= k; i++)
        ans = ans * (n - i + 1) / i;

    return ans;
}

std::vector<long long> generateRowOptimal(int n)
{
    // This solves the problem of Print the entire nth row of Pascal’s Triangle
    std::vector<long long> row;
    long long val = 1;

    row.push_back(val);

    for (int i = 1; i < n; i++)
    {
        val = val * (n - i) / i;
        row.push_back(val);
    }

    return row;
}

void printCenteredPascal(int n)
{
    // This not related to this question, but i implemented the pattern printing for pascal triangle
    for (int row = 1; row <= n; row++)
    {

        // printing leading spaces
        for (int s = 0; s < n - row; s++)
        {
            std::cout << "  ";
        }

        // print row elements
        std::vector<long long> r = generateRowOptimal(row);
        for (long long x : r)
        {
            std::cout << x << "   ";
        }

        std::cout << std::endl;
    }
}

// Brute Approach or Better Approach or Optimal Approach
std::vector<std::vector<long long>> brute(int numRows)
{
    std::vector<std::vector<long long>> pascal;
    for (int i = 0; i < numRows; i++)
    {
        pascal.push_back(generateRowOptimal(i + 1));
    }
    return pascal;
}
//   TC=O(n^2), SC=O(n^2)

void printPascalArray(std::vector<std::vector<long long>> &pascal)
{

    std::cout << "[";

    for (auto it = pascal.begin(); it != pascal.end(); it++)
    {
        traverse(*it);

        if (it + 1 != pascal.end())
            std::cout << ",";
    }

    std::cout << "]" << std::endl;
}

std::vector<std::vector<int>> dsaSolve(int numRows)
{
    std::vector<std::vector<int>> ans;

    for (int i{}; i < numRows; i++)
    {
        std::vector<int> row;
        int val{1};
        row.push_back(val);
        for (int j{1}; j < i + 1; j++)
        {
            val = val * ((i + 1) - j) / j;
            row.push_back(val);
        }
        ans.push_back(row);
    }
    return ans;
}

int main()
{

    int numRows = 5;

    printCenteredPascal(numRows);

    std::cout << std::endl;
    std::cout << pascalValueOptimal(5, 3) << std::endl;

    std::vector<long long> row = generateRowOptimal(5);
    traverse(row);
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << std::endl;
    std::vector<std::vector<long long>> pascal = brute(numRows);
    printPascalArray(pascal);

    return 0;
}