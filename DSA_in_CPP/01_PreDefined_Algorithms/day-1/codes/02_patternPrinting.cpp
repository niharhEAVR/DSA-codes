#include <iostream>

// Outer loop is for rows and inner loop is for the column.
// In Pattern printing revise only do the dry run of these programs , dont write code
// on the notebook so write the formulas and dry run

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

    //           *
    //         * * *
    //       * * * * *
    //     * * * * * * *
    //   * * * * * * * * *
    // hard
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
    // hard
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

    // *
    // * *
    // * * *
    // * * * *
    // * * * * *
    // * * * *
    // * * *
    // * *
    // *
    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j <= i; j++)
        {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 4 - i; j > 0; j--)
        {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }

    // 1
    // 0 1
    // 1 0 1
    // 0 1 0 1
    // 1 0 1 0 1
    for (size_t i = 0; i < 6; i++)
    {

        int start{1};
        if (i % 2 == 0)
            start = 0;
        else
            start = 1;

        for (size_t j = 0; j < i; j++)
        {
            std::cout << start << " ";
            start = 1 - start;
        }

        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    // 1 3 5 7 9
    // 3 5 7 9 1
    // 5 7 9 1 3
    // 7 9 1 3 5
    // 9 1 3 5 7
    // hard
    for (size_t i = 0; i < 5; i++) // 1-5
    {

        for (size_t j = 0; j < 5; j++)
        {
            int value = 2*((i+j)%5)+1;
            std::cout<<value<<" ";
        }
        std::cout << std::endl;
    }

    return 0;
}