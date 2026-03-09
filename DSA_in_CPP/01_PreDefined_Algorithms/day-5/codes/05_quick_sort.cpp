#include <bits/stdc++.h>

int sortAlgo(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partionIndex = sortAlgo(arr, low, high);
        quickSort(arr, low, partionIndex - 1);
        quickSort(arr, partionIndex + 1, high); 
    }
}

void traverse(int arr[], int n);
int main()
{
    int arr[] = {2, 8, 4, 7, 1, 6, 5, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, size - 1);
    traverse(arr, size);
    return 0;
}
void traverse(int arr[], int n)
{
    std::cout << "[ ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << "]";
}