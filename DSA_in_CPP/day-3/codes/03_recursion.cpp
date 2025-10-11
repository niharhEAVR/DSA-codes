#include <iostream>
#include <string>
#include <cctype>
void printNameUsRec(int n)
{
    if (n == 0)
        return;
    std::cout << "name" << std::endl;
    --n;
    printNameUsRec(n);
}

void printNumUsRec(int n)
{
    if (n == 0)
        return;
    std::cout << n << std::endl;
    --n;
    printNumUsRec(n);
}

void printNumUsRecBT(int n)
{
    if (n == 1)
        return;
    printNumUsRecBT(n--);
    std::cout << n << std::endl;
}

int facto(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * facto(n - 1);
}

// my logic to reverse an array
void revArrRec(int i, int n, int bc, int arr[])
{
    if (i == bc / 2)
        return;
    int temp = arr[n - 1];
    arr[n - 1] = arr[i];
    arr[i] = temp;
    revArrRec(i + 1, n - 1, bc, arr);
}

// advanced logic
void advRevArrRec(int i, int n, int arr[])
{
    if (i >= n / 2)
        return;
    std::swap(arr[i], arr[n - i - 1]);
    advRevArrRec(i + 1, n, arr);
}

// advanced logic
bool isPalindromeRec(const std::string &s, int left, int right)
{
    while (left < right && !std::isalnum(s[left]))
        left++;
    while (left < right && !std::isalnum(s[right]))
        right--;

    if (left >= right)
        return true;

    if (std::tolower(s[left]) != std::tolower(s[right]))
        return false;

    return isPalindromeRec(s, left + 1, right - 1);
}

bool isPalindrome(std::string s)
{
    return isPalindromeRec(s, 0, s.size() - 1);
}

int fibo(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibo(n - 1) + fibo(n - 2);
}

int main()
{
    // printNameUsRec(5);
    // printNumUsRec(5);
    // printNumUsRecBT(5);

    // std::cout << facto(5);

    {
        // int arr[5] = {1, 2, 3, 4, 5};
        // // revArrRec(0, 5, 5, arr);
        // advRevArrRec(0, 5, arr);
        // for (size_t i = 0; i < 5; i++)
        // {
        //     std::cout << arr[i] << " ";
        // }
        //     advRevArrRec(0)
        //     swap(0,4)
        //      |
        //      └── advRevArrRec(1)
        //            swap(1,3)
        //                |
        //                └── advRevArrRec(2)
        //                      base case → stop
    }

    {
        // std::string s = "A man, a plan, a 97831rhbcanal: Panama";
        // std::string refined = "";
        // for (auto i : s)
        // {
        //     if(std::isalnum(i)){
        //         refined += std::tolower(i);
        //     }
        // }
        // std::string swp = "";
        // int n = refined.size();
        // for (int i = n-1; i >= 0; i--)
        // {
        //     swp+=refined[i];
        // }

        // if(swp == refined) {
        //     std::cout<<true<<std::endl;
        // }else{
        //     std::cout<<false<<std::endl;
        // }

        std::string s = "A man, a plan, a canal: Panama";
        // std::cout << isPalindrome(s) << std::endl;
    }

    {
        // std::cout<<"fibonacci of 5 is: "<<fibo(5)<<std::endl;
        //                           fib(5)
        //                       /              \
        //                 fib(4)                 fib(3)
        //                /      \               /      \
        //          fib(3)       fib(2)       fib(2)    fib(1) return 1
        //         /     \       /   \         /   \       
        //    fib(2)   fib(1) fib(1) fib(0)  fib(1) fib(0) return 1
        //    /   \   return 1     return 1
        // fib(1) fib(0)
            // return 1

        // here 5 return 1's thaths why the answer of 5 is 5

    }   

    return 0;
}