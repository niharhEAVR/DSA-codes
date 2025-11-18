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
    std::vector<std::vector<int>> result = matrix;

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            result[j][matrix[0].size() - i - 1] = matrix[i][j];
            // Huge achievement for me that is i solved this brute approach by me and also the logic ( so stay consistent ).
        }
    }
    matrix = result;
}
//   TC=O(n^2), SC=O(n^2)

// Better Approach
void better(std::vector<std::vector<int>> &matrix)
{

    for (int i = 1; i < matrix.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        std::reverse(matrix[i].begin(), matrix[i].end());
    }
}
//   TC=O(2*n^2), SC=O(1)

// Optimal Approach
void optimal(std::vector<std::vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][n - 1 - j];
            matrix[i][n - 1 - j] = temp;
        }
    }
}
//   TC=O(2*n^2), SC=O(1)

int main()
{

    std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // std::vector<std::vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};

    // brute(matrix);
    // traverse(matrix);

    // traverse(matrix);
    // better(matrix);
    // traverse(matrix);


    traverse(matrix);
    optimal(matrix);
    traverse(matrix);
    return 0;
}