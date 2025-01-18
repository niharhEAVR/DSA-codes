**Bubble Sort** is a simple sorting algorithm in C (and other languages) that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The process is repeated until the list is sorted. It is called "Bubble Sort" because smaller elements "bubble" to the top of the list (start), while larger elements sink to the bottom (end).

### **How Bubble Sort Works**
1. Start from the beginning of the array.
2. Compare adjacent elements.
3. Swap them if they are in the wrong order (e.g., for ascending order, swap if the first element is greater than the second).
4. Repeat this process for all elements in the array.
5. After each iteration, the largest element is placed at its correct position at the end of the array.
6. Reduce the range of comparison for subsequent iterations since the last elements are already sorted.

### **Algorithm**
1. For each pass through the array:
   - Compare adjacent elements.
   - Swap them if needed.
2. Repeat this process until no swaps are needed in a complete pass.

### **Example in C**
Here’s a simple implementation of Bubble Sort in C:

```c
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        // Last i elements are already sorted
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
```

### **Explanation**
1. **Input:** `{64, 34, 25, 12, 22, 11, 90}`
2. **First Pass:**
   - Compare `64` and `34`: Swap → `{34, 64, 25, 12, 22, 11, 90}`
   - Compare `64` and `25`: Swap → `{34, 25, 64, 12, 22, 11, 90}`
   - Continue until the largest number `90` is at the end.
3. **Subsequent Passes:**
   - The next largest numbers are placed in their correct positions.
4. **Final Output:** `{11, 12, 22, 25, 34, 64, 90}`

### **Time Complexity**
- **Best Case:** \(O(n)\) (when the array is already sorted and optimized with no swaps).
- **Worst Case:** \(O(n^2)\) (when the array is sorted in reverse order).

### **Space Complexity**
- \(O(1)\) (in-place sorting). 

Bubble Sort is suitable for small datasets but inefficient for larger datasets due to its quadratic time complexity.


---
---
---



Here's a step-by-step **text visualization** of how Bubble Sort works on the array `{64, 34, 25, 12, 22, 11, 90}`:

---

### **Unsorted Array:**  
`64 34 25 12 22 11 90`

---

### **Pass 1:**  
- Compare `64` and `34` → Swap → `34 64 25 12 22 11 90`  
- Compare `64` and `25` → Swap → `34 25 64 12 22 11 90`  
- Compare `64` and `12` → Swap → `34 25 12 64 22 11 90`  
- Compare `64` and `22` → Swap → `34 25 12 22 64 11 90`  
- Compare `64` and `11` → Swap → `34 25 12 22 11 64 90`  
- Compare `64` and `90` → No Swap → `34 25 12 22 11 64 90`  

**After Pass 1:**  
`34 25 12 22 11 64 90` (Largest element `90` is in its correct position)

---

### **Pass 2:**  
- Compare `34` and `25` → Swap → `25 34 12 22 11 64 90`  
- Compare `34` and `12` → Swap → `25 12 34 22 11 64 90`  
- Compare `34` and `22` → Swap → `25 12 22 34 11 64 90`  
- Compare `34` and `11` → Swap → `25 12 22 11 34 64 90`  
- Compare `34` and `64` → No Swap → `25 12 22 11 34 64 90`  

**After Pass 2:**  
`25 12 22 11 34 64 90` (Second largest element `64` is in its correct position)

---

### **Pass 3:**  
- Compare `25` and `12` → Swap → `12 25 22 11 34 64 90`  
- Compare `25` and `22` → Swap → `12 22 25 11 34 64 90`  
- Compare `25` and `11` → Swap → `12 22 11 25 34 64 90`  
- Compare `25` and `34` → No Swap → `12 22 11 25 34 64 90`  

**After Pass 3:**  
`12 22 11 25 34 64 90` (Third largest element `34` is in its correct position)

---

### **Pass 4:**  
- Compare `12` and `22` → No Swap → `12 22 11 25 34 64 90`  
- Compare `22` and `11` → Swap → `12 11 22 25 34 64 90`  
- Compare `22` and `25` → No Swap → `12 11 22 25 34 64 90`  

**After Pass 4:**  
`12 11 22 25 34 64 90` (Fourth largest element `25` is in its correct position)

---

### **Pass 5:**  
- Compare `12` and `11` → Swap → `11 12 22 25 34 64 90`  
- Compare `12` and `22` → No Swap → `11 12 22 25 34 64 90`  

**After Pass 5:**  
`11 12 22 25 34 64 90` (Fifth largest element `22` is in its correct position)

---

### **Pass 6:**  
- Compare `11` and `12` → No Swap → `11 12 22 25 34 64 90`  

**After Pass 6:**  
`11 12 22 25 34 64 90` (Fully sorted array)

---

### **Sorted Array:**  
`11 12 22 25 34 64 90`

This visualization shows how the largest unsorted elements gradually "bubble" to the end of the array with each pass.


---
---
---


### Real-World Example of **Bubble Sort**

Let’s use a **real-world analogy** to explain **Bubble Sort**: **Sorting soda cans by weight in a conveyor belt system**.

---

### Scenario:
Imagine a conveyor belt with soda cans of different weights. Your task is to sort them in ascending order of weight using the **Bubble Sort** approach.

---

### Steps:

1. **Start from the Beginning**:
   - Compare the first two cans.
   - If the first can is heavier, swap them.

2. **Move to the Next Pair**:
   - Compare the next two cans.
   - Swap them if they are out of order.

3. **Repeat for the Entire Line**:
   - Continue comparing and swapping cans until you reach the end of the line.
   - The heaviest can "bubbles up" to its correct position at the end of the line.

4. **Repeat for Remaining Cans**:
   - Ignore the last sorted can and repeat the process for the unsorted cans.
   - Continue until the entire line is sorted.

---

### Example:

#### Initial Weights of Soda Cans: `[64, 25, 12, 22, 11]`

1. **Pass 1**:
   - Compare `64` and `25` → Swap (`[25, 64, 12, 22, 11]`).
   - Compare `64` and `12` → Swap (`[25, 12, 64, 22, 11]`).
   - Compare `64` and `22` → Swap (`[25, 12, 22, 64, 11]`).
   - Compare `64` and `11` → Swap (`[25, 12, 22, 11, 64]`).
   - Largest can (`64`) is now in its correct position.

2. **Pass 2**:
   - Compare `25` and `12` → Swap (`[12, 25, 22, 11, 64]`).
   - Compare `25` and `22` → Swap (`[12, 22, 25, 11, 64]`).
   - Compare `25` and `11` → Swap (`[12, 22, 11, 25, 64]`).
   - Second largest can (`25`) is now in its correct position.

3. **Pass 3**:
   - Compare `12` and `22` → No swap (`[12, 22, 11, 25, 64]`).
   - Compare `22` and `11` → Swap (`[12, 11, 22, 25, 64]`).
   - Third largest can (`22`) is now in its correct position.

4. **Pass 4**:
   - Compare `12` and `11` → Swap (`[11, 12, 22, 25, 64]`).
   - Fourth largest can (`12`) is now in its correct position.

5. **Pass 5**:
   - No swaps needed; all cans are sorted.

**Final Sorted Weights**: `[11, 12, 22, 25, 64]`.

---

### Key Points:
1. **Bubble Process**:
   - Heavier (or larger) elements "bubble up" to their correct positions at the end of the array with each pass.

2. **Real-Life Applications**:
   - Sorting small datasets, like arranging a list of numbers on paper, organizing coins by size, or aligning files by name.
