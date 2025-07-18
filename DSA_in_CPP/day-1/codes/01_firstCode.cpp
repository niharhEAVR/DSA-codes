// #include <bits/stdc++.h>
#include <iostream>
#include <math.h>

void changedDirectValueForArr(int arr[][3], int r)
{
    arr[r-1][2] = 43;
}

void changedDirectValue(int &a, int &b)
{
    a += b;
    b += a;
}

int main()
{
    std::string name;
    std::cout << "Enter yout name: ";
    std::getline(std::cin, name);
    std::cout << "Your name is: " << name << std::endl;

    std::cout << std::endl;

    int row{3};
    int column{3};
    int arr2d[row][3];
    for (size_t i{}; i < row; i++)
    {
        for (size_t j{}; j < column; j++)
        {
            std::cout << "Enter the value of arr2d[" << i << "][" << j << "]: ";
            std::cin >> arr2d[i][j];
        }
    }

    std::cout << std::endl;

    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < column; j++)
        {
            std::cout << arr2d[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    changedDirectValueForArr(arr2d, row);

    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < column; j++)
        {
            std::cout << arr2d[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    std::cout << row << " , " << column << std::endl;
    changedDirectValue(row, column);
    std::cout << row << " , " << column << std::endl;

    return 0;
}