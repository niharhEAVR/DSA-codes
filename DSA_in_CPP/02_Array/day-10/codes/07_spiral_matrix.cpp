// #include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <algorithm>

void traverse(std::vector<std::vector<int>> &nums)
{
    for (auto it = nums.begin(); it != nums.end(); it++)
    {
        std::cout << "[ ";
        for (auto jt = it->begin(); jt != it->end(); jt++)
        {
            std::next(jt) == it->end() ? std::cout << *jt << " " : std::cout << *jt << ", ";
        }
        std::cout << "]\n";
    }
    std::cout << "\n";
}

// Brute Approach
void brute(std::vector<std::vector<int>> &matrix)
{
}

// Better Approach
void better(std::vector<std::vector<int>> &matrix)
{
}

// Optimal Approach
std::vector<int> optimal(std::vector<std::vector<int>> &matrix)
{

    int n = matrix.size();
    if (n == 0)
        return {};
    int m = matrix[0].size();
    int top{}, left{};
    int bottom = n - 1;
    int right = m - 1;
    std::vector<int> ans;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            ans.push_back(matrix[left][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}
//   TC=O(2*n^2), SC=O(1)

int main()
{

    // std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // std::vector<std::vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    std::vector<std::vector<int>> matrix = {{1, 2, 3, 4}};

    traverse(matrix);
    std::vector<int> ans = optimal(matrix);

    std::cout << "[ ";
    for (auto it = ans.begin(); it != ans.end(); it++)
    {
        it + 1 == ans.end() ? std::cout << *it << " " : std::cout << *it << ", ";
    }
    std::cout << "]";

    return 0;
}
