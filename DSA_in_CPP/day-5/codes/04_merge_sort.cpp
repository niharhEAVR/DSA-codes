// #include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

void mergee(int arr[], int mid, int low, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    mergee(arr, mid, low, high);
}

void traverse(int arr[], int n)
{
    cout << "[ ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "]";
}

int main()
{
    int arr[] = {2, 8, 4, 7, 1, 6, 5, 3}; // size = 8
    int size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, size - 1); // arr , 0 , 7
    traverse(arr, size);
    return 0;
}
