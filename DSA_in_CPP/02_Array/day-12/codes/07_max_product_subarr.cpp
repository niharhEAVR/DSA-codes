// #include <bits/stdc++.h>

#include <iostream>
#include <vector>

// Brute Approach
int brute(std::vector<int> &nums)
{
    int maxi = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {
            int prod{1};
            for (int k = i; k < j; k++)
            {
                prod *= nums[k];
            }
            maxi = std::max(maxi, prod);
        }
    }
    return maxi;
}
//   TC=O(n^3), SC=O(1)

// Better Approach
int better(std::vector<int> &nums)
{

    int maxi = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        int prod{1};
        for (int j = i; j < nums.size(); j++)
        {
            prod *= nums[j];
            maxi = std::max(maxi, prod);
        }
    }
    return maxi;
}
//   TC=O(n^2), SC=O(1)

// The Brute & Better Approach for this problem will fail the time limit or exceed the time limit
// But there is 2 optimal approaches (Observation and Modified Kadane algorithm)

// Optimal Approach Modified Kadane
/*
The maximum product can come from:

* continuous positives
* or two negatives (because - × - = +)
* or restarting after zero
*/
int optimalOne(std::vector<int> &nums)
{
    int n = nums.size();
    int maxProd = nums[0];
    int minProd = nums[0];
    int answer = nums[0];

    for (int i = 1; i < n; i++)
    {
        int tempMax = std::max(nums[i], std::max(maxProd * nums[i], minProd * nums[i]));
        int tempMin = std::min(nums[i], std::min(maxProd * nums[i], minProd * nums[i]));

        maxProd = tempMax;
        minProd = tempMin;
        answer = std::max(answer, maxProd);
    }

    return answer;
    /*Another Method - less code, but same logic
    int n = nums.size();
    int maxProd = nums[0];
    int minProd = nums[0];
    int answer = nums[0];
    for (int i = 1; i < n; i++)
    {
        int x = nums[i];
        if (x < 0)
            std::swap(maxProd, minProd);

        maxProd = std::max(x, minProd * x);
        minProd = std::min(x, minProd * x);
        answer = std::max(answer, maxProd);
    }
    return answer;
    */
}
//   TC=O(n), SC=O(1)

// Optimal Approach Observations Technique
/*
The maximum product can come from:

* continuous positives
* or two negatives (because - × - = +)
* or restarting after zero
*/
int optimalTwo(std::vector<int> &nums)
{
    int n = nums.size();

    int pefs = 1, suffs = 1;
    int answer = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        pefs *= nums[i];
        answer = std::max(answer, pefs);
        if (pefs == 0)
            pefs = 1;

        suffs *= nums[n - 1 - i];
        answer = std::max(answer, suffs);
        if (suffs == 0)
            suffs = 1;
    }

    return answer;
}
//   TC=O(n), SC=O(1)

int main()
{
    // std::vector<int> arr = {2, 3, -2, 4};
    std::vector<int> arr = {1, 0, -5, 2, 3, -8, -9};

    // int result = brute(arr);
    // std::cout << "The max is: " << result << std::endl;

    // int result = better(arr);
    // std::cout << "The max is: " << result << std::endl;

    // int result = optimalOne(arr);
    // std::cout << "The max is: " << result << std::endl;

    int result = optimalTwo(arr);
    std::cout << "The max is: " << result << std::endl;

    return 0;
}