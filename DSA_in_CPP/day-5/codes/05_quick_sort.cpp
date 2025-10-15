#include <bits/stdc++.h>

// void mergee(int arr[], int mid, int low, int high)
// {
//     vector<int> temp;
//     int left = low;
//     int right = mid + 1;
//     while (left <= mid && right <= high)
//     {
//         if (arr[left] <= arr[right])
//         {
//             temp.push_back(arr[left]);
//             left++;
//         }
//         else
//         {
//             temp.push_back(arr[right]);
//             right++;
//         }
//     }
//     while (left <= mid)
//     {
//         temp.push_back(arr[left]);
//         left++;
//     }
//     while (right <= high)
//     {
//         temp.push_back(arr[right]);
//         right++;
//     }
//     for (int i = low; i <= high; i++)
//     {
//         arr[i] = temp[i - low];
//     }
// }

// void quickSort(int arr[], int low, int high)
// {
//     if (low >= high)
//         return;
//     int mid = (low + high) / 2;
//     quickSort(arr, low, mid);
//     quickSort(arr, mid + 1, high);
//     mergee(arr, mid, low, high);
// }


// void quickSort(int arr[], int low, int high)
// {
//     int pivot = arr[high]; // 3

//     std::vector<int> pivotlow;
//     std::vector<int> pivothigh;

//     for (int i = 0; i <= high; i++) // <=7
//     {
//         if(arr[i]<=pivot){
//             pivotlow.push_back(arr[i]);
//         }else{
//             pivothigh.push_back(arr[i]);
//         }
//     }
    
//     pivotlow.push_back(pivot);
//     // int n = pivotlow.size()-1;
    
//     // for (int i = 2; i <= high; i++)
//     // {
//     //     pivotlow.push_back(pivothigh[i-2]);
//     // }
    
//     for (int i = 0; i <= high; i++)
//     {
//         arr[i] = pivotlow[i];
//     }
// }




// void traverse(int arr[], int n)
// {
//     std::cout << "[ ";
//     for (int i = 0; i < n; i++)
//     {
//         std::cout << arr[i] << ", ";
//     }
//     std::cout << "]";
// }

// int main()
// {
//     int arr[] = {2, 8, 4, 7, 1, 6, 5, 3};
//     int size = sizeof(arr) / sizeof(arr[0]);

//     quickSort(arr, 0, size - 1);
//     traverse(arr, size);
//     return 0;
// }
