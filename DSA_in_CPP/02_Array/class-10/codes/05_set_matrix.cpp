// #include <bits/stdc++.h>

#include <iostream>
#include <vector>

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
}

// Brute Approach
void brute(std::vector<std::vector<int>> &matrix)
{

    int rows = matrix.size();
    int cols = matrix[0].size();

    std::vector<std::vector<int>> result = matrix; // make a copy

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                for (int k = 0; k < cols; k++)
                    result[i][k] = 0;
                for (int k = 0; k < rows; k++)
                    result[k][j] = 0;
            }
        }
    }

    matrix = result;
}
//   TC=O((m×n) × (m+n)), SC=O(m×n)
// Always remember that Time Complexity and Space Complexity of Any matrix is m*n, because there is nested array inside the original array (normal array tc & sc is O(n)) thats why.

void traverse2(std::vector<int> &row)
{
    for (auto it : row)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

// Better Approach
void better(std::vector<std::vector<int>> &matrix)
{

    if (matrix.empty() || matrix[0].empty())
        return;

    std::vector<int> row(matrix.size(), 1);
    std::vector<int> col(matrix[0].size(), 1);

    traverse2(row);
    traverse2(col);

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 0;
                col[j] = 0;
            }
        }
    }
    traverse2(row);
    traverse2(col);

    for (int i = 0; i < row.size(); i++)
    {
        for (int j = 0; j < col.size(); j++)
        {
            if (row[i] == 0 || col[j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
}
//   TC=O(2 × m × n), SC=O(m+n)

// Optimal Approach
void optimal(std::vector<std::vector<int>> & matrix)
{
    int m = matrix.size(), n = matrix[0].size(), col0 = 1;

    for (int i = 0; i < m; i++)
    {
        if (matrix[i][0] == 0)
            col0 = 0;

        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 1; j--)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] == 0;
            }
        }

        if (col0 == 0)
        {
            matrix[i][0] = 0;
        }
    }
}
//   TC=O(m × n), SC=O(1)

int main()
{

    std::vector<std::vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    // std::vector<std::vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    // std::vector<std::vector<int>> matrix = {{-1}, {2}, {1}};

    // brute(matrix);
    // traverse(matrix);

    // better(matrix);
    // traverse(matrix);

    optimal(matrix);
    traverse(matrix);
    return 0;
}