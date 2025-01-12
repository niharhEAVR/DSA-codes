### **Linear Search**:
- **Description**: Linear search is a simple algorithm that checks each element in the array sequentially from the beginning until the target element is found or the end of the array is reached.
- **Use case**: It is used for **unsorted** arrays or when the array is too small for more complex algorithms to be beneficial.
- **Time Complexity**: O(n) where n is the number of elements in the array. In the worst case, every element needs to be checked.
- **Example**: If the array is `[1, 2, 3, 4, 5]` and we are searching for `4`, the algorithm will check `1`, `2`, `3`, and then find `4`.

#### Code Example (Linear Search):

```c
#include <stdio.h>

int linearSearch(int arr[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            return i;  // element found at index i
        }
    }
    return -1;  // element not found
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int value = 4;
    
    int result = linearSearch(arr, n, value);
    if (result != -1) {
        printf("Element %d found at index %d\n", value, result);
    } else {
        printf("Element %d not found\n", value);
    }
    
    return 0;
}
```

### **Binary Search**:
- **Description**: Binary search is a more efficient algorithm that works by dividing the sorted array into two halves. It compares the target element to the middle element of the array and determines which half the element must lie in. This process is repeated recursively (or iteratively) on the chosen half.
- **Use case**: It is used only for **sorted arrays**.
- **Time Complexity**: O(log n) where n is the number of elements in the array. This makes binary search much faster than linear search for large arrays.
- **Example**: If the array is `[1, 2, 3, 4, 5]` and we are searching for `4`, the algorithm first compares with `3` (middle element), finds that `4` is larger, and then compares with `4` in the right half.

#### Code Example (Binary Search):

```c
#include <stdio.h>

int binarySearch(int arr[], int n, int value) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == value) {
            return mid;  // element found at mid
        } else if (arr[mid] < value) {
            left = mid + 1;  // search in the right half
        } else {
            right = mid - 1;  // search in the left half
        }
    }
    
    return -1;  // element not found
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int value = 4;
    
    int result = binarySearch(arr, n, value);
    if (result != -1) {
        printf("Element %d found at index %d\n", value, result);
    } else {
        printf("Element %d not found\n", value);
    }
    
    return 0;
}
```

---

### **Key Differences Between Linear Search and Binary Search**:

| Feature                | **Linear Search**                                    | **Binary Search**                                   |
|------------------------|------------------------------------------------------|-----------------------------------------------------|
| **Array Requirement**   | Can be used on **unsorted arrays**                  | Can only be used on **sorted arrays**               |
| **Time Complexity**     | O(n) where n is the number of elements               | O(log n) where n is the number of elements          |
| **Algorithm Type**      | Sequential search, checking one element at a time   | Divide and conquer, dividing the array in half      |
| **Best Use Case**       | Small or unsorted arrays                            | Large sorted arrays                                |
| **Space Complexity**    | O(1) (constant space)                               | O(1) (constant space)                              |
| **Efficiency**          | Less efficient for large arrays                     | More efficient for large arrays                    |

### **When to Use**:
- **Linear Search**: When the array is small or unsorted, and you don't need the overhead of sorting it first.
- **Binary Search**: When the array is sorted and you need a faster search method for large datasets.