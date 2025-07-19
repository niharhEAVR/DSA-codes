#include <iostream>

// Outer loop is for rows and inner loop is for the column.

int main()
{

    // * * * *
    // * * * *
    // * * * *
    // * * * *
    for (size_t i{}; i < 4; i++)
    {
        for (size_t j{}; j < 4; j++)
        {
            std::cout << " *";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // *
    // * *
    // * * *
    // * * * *
    for (size_t i{}; i < 5; i++)
    {
        for (size_t j{}; j < i; j++)
        {
            std::cout << " *";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // 1
    // 1 2
    // 1 2 3
    // 1 2 3 4
    for (size_t i{1}; i < 6; i++)
    {
        for (size_t j{1}; j < i; j++)
        {
            std::cout << " " << j;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // 1
    // 2 2
    // 3 3 3
    // 4 4 4 4
    // 5 5 5 5 5
    for (size_t i{}; i < 6; i++)
    {
        for (size_t j{}; j < i; j++)
        {
            std::cout << " " << i;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // * * * * *
    // * * * *
    // * * *
    // * *
    // *
    // rule -> (rows-i+1)
    for (size_t i{1}; i < 6; i++)
    {
        for (size_t j{1}; j < 6 - i + 1; j++)
        {
            std::cout << " *";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // 1 2 3 4 5
    // 1 2 3 4
    // 1 2 3
    // 1 2
    // 1
    for (size_t i{1}; i < 6; i++)
    {
        for (size_t j{1}; j < 6 - i + 1; j++)
        {
            std::cout << " " << j;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //           *
    //         * * *
    //       * * * * *
    //     * * * * * * *
    //   * * * * * * * * *
    for (size_t i{}; i < 5; i++)
    {
        for (size_t j{}; j < 5 - i - 1; j++)
        {
            std::cout << "  ";
        }
        for (size_t j{}; j < 2 * i + 1; j++)
        {
            std::cout << " *";
        }
        for (size_t j{}; j < 5 - i - 1; j++)
        {
            std::cout << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //  * * * * * * * * *
    //    * * * * * * *
    //      * * * * *
    //        * * *
    //          *
    for (size_t i{}; i < 5; i++)
    {
        for (size_t j{}; j < i; j++)
        {
            std::cout << "  ";
        }
        for (size_t j{}; j < 2 * 5 - (2 * i + 1); j++)
        {
            std::cout << " *";
        }
        for (size_t j{}; j < i; j++)
        {
            std::cout << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //          *
    //        * * *
    //      * * * * *
    //    * * * * * * *
    //  * * * * * * * * *
    //  * * * * * * * * *
    //    * * * * * * *
    //      * * * * *
    //        * * *
    //          *
    for (size_t i{}; i < 5; i++)
    {
        for (size_t j{}; j < 5 - i - 1; j++)
        {
            std::cout << "  ";
        }
        for (size_t j{}; j < 2 * i + 1; j++)
        {
            std::cout << " *";
        }
        for (size_t j{}; j < 5 - i - 1; j++)
        {
            std::cout << "  ";
        }
        std::cout << std::endl;
    }
    for (size_t i{}; i < 5; i++)
    {
        for (size_t j{}; j < i; j++)
        {
            std::cout << "  ";
        }
        for (size_t j{}; j < 2 * 5 - (2 * i + 1); j++)
        {
            std::cout << " *";
        }
        for (size_t j{}; j < i; j++)
        {
            std::cout << "  ";
        }
        std::cout << std::endl;
    }

   
    return 0;
}