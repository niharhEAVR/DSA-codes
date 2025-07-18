### Merge Sort in DSA (Data Structures and Algorithms)

**Merge Sort** is a **divide-and-conquer** algorithm that splits an array into smaller subarrays, sorts them, and then merges them back together in a sorted manner. It is one of the most efficient sorting algorithms with a guaranteed time complexity of \(O(n \log n)\) in all cases.

---

### How Merge Sort Works

#### Steps:
1. **Divide**: 
   - Split the array into two halves until each subarray has only one element (a single element is considered sorted).
   
2. **Conquer** (Sort): 
   - Merge the subarrays back together in a sorted order.
   
3. **Combine**: 
   - Once all subarrays are merged, you get a fully sorted array.

---

### Example Walkthrough

Let’s take an example to explain how Merge Sort works.

#### Initial Array: `[38, 27, 43, 3, 9, 82, 10]`

1. **Step 1: Divide the Array**
   - Split the array into two halves:
     - Left: `[38, 27, 43, 3]`
     - Right: `[9, 82, 10]`
   
2. **Step 2: Divide Again**
   - Left: `[38, 27, 43, 3]` → `[38, 27]` and `[43, 3]`
   - Right: `[9, 82, 10]` → `[9]` and `[82, 10]`
   
3. **Step 3: Divide Further**
   - `[38, 27]` → `[38]` and `[27]`
   - `[43, 3]` → `[43]` and `[3]`
   - `[82, 10]` → `[82]` and `[10]`
   
   Now, each subarray has only one element, and they are considered sorted.

---

### Step 4: **Merge the Subarrays**

Now, we start merging the subarrays back in sorted order.

1. **Merge `[38]` and `[27]`**:
   - Compare `38` and `27`, and merge them into `[27, 38]`.

2. **Merge `[43]` and `[3]`**:
   - Compare `43` and `3`, and merge them into `[3, 43]`.

3. **Merge `[82]` and `[10]`**:
   - Compare `82` and `10`, and merge them into `[10, 82]`.

Now, we have:
- Left: `[27, 38]`, `[3, 43]`
- Right: `[9]`, `[10, 82]`

---

### Step 5: **Merge Larger Subarrays**

1. **Merge `[27, 38]` and `[3, 43]`**:
   - Compare elements: `3 < 27`, so `3` goes first.
   - Compare `27` and `43`, `27` goes first.
   - Compare `38` and `43`, `38` goes first.
   - Final merged array: `[3, 27, 38, 43]`

2. **Merge `[9]` and `[10, 82]`**:
   - Compare `9` and `10`, `9` goes first.
   - Compare `10` and `82`, `10` goes first.
   - Final merged array: `[9, 10, 82]`

Now we have:
- Left: `[3, 27, 38, 43]`
- Right: `[9, 10, 82]`

---

### Step 6: **Final Merge**

1. **Merge `[3, 27, 38, 43]` and `[9, 10, 82]`**:
   - Compare `3` and `9`, `3` goes first.
   - Compare `27` and `9`, `9` goes first.
   - Compare `27` and `10`, `10` goes first.
   - Compare `27` and `82`, `27` goes first.
   - Compare `38` and `82`, `38` goes first.
   - Compare `43` and `82`, `43` goes first.
   - Finally, `82` is the last remaining element.
   - Final sorted array: `[3, 9, 10, 27, 38, 43, 82]`

---

### Merge Sort Algorithm in C

```c
#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[], if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Find the middle point
        mergeSort(arr, left, mid); // Sort the first half
        mergeSort(arr, mid + 1, right); // Sort the second half
        merge(arr, left, mid, right); // Merge the sorted halves
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    mergeSort(arr, 0, n - 1);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
```

---

### Memory Visualization

**Memory usage in Merge Sort** can be visualized as follows:

1. **Divide Step**:
   - The array is recursively divided into smaller arrays. This requires memory for the recursion stack (function calls).

2. **Merge Step**:
   - Temporary arrays (`leftArr[]` and `rightArr[]`) are used to store the divided parts of the array before merging them back. This requires extra space proportional to the size of the array being merged.

---

### Time Complexity of Merge Sort

1. **Best, Worst, and Average Case**: \(O(n \log n)\)
   - Regardless of the input, the array is always divided into two halves, and merging takes linear time. So, the time complexity is always \(O(n \log n)\).

---

### Space Complexity of Merge Sort

1. **Space Complexity**: \(O(n)\)
   - Merge Sort requires extra space for the temporary arrays used in the merging step. This space is proportional to the size of the array.

---

### Advantages of Merge Sort

1. **Stable**: Equal elements retain their relative order.
2. **Efficient**: \(O(n \log n)\) time complexity in all cases.
3. **Works well for large datasets**.

### Disadvantages of Merge Sort

1. **Space Complexity**: Requires extra space for temporary arrays.
2. **Slower than QuickSort**: In practice, Merge Sort is often slower than QuickSort due to its larger constant factors.

---

### Summary

- **Merge Sort** is a **divide-and-conquer** algorithm with a time complexity of \(O(n \log n)\) in all cases.
- It is **stable** and efficient but requires **extra memory**.
- The algorithm divides the array into smaller parts, sorts them, and merges them back together in sorted order.
