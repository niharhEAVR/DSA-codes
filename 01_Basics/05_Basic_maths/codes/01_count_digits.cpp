#include <iostream>

int main()
{
    long long x = 726976988375087;
    int count{};
    while (x > 0)
    {
        count++;
        x/=10;
    };
    std::cout<<count;
    return 0;
}