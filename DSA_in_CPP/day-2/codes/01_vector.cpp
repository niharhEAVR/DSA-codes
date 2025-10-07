#include <iostream>
#include <vector>
#include <utility> // for pair

int main()
{
    std::vector<int> v; // create an empty vector of integers

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.emplace_back(2);

    std::vector<std::pair<int, int>> v2;

    v2.push_back({1, 2});
    v2.emplace_back(3, 4);

    std::vector<int> v3(5, 100); // it will store five 100s

    // normal way to show the vector array
    std::cout << "Size of a vector: " << v.size() << std::endl;
    std::cout << "Size of a vector: " << v2.size() << std::endl;
    std::cout << "Size of a vector: " << v3.size() << std::endl;
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i < v2.size(); i++)
        std::cout << v2[i].first << " " << v2[i].second << " | ";
    std::cout << std::endl;
    for (int i = 0; i < v3.size(); i++)
        std::cout << v3[i] << " ";
    std::cout << std::endl;

    // advanced iterator
    for (auto i = v.begin(); i != v.end(); i++)
        std::cout << *i << " ";

    std::cout << std::endl;
    for (auto i : v3)
        std::cout << i << " ";

    return 0;
}