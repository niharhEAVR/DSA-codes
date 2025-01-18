### Selection Sort in DSA (C Programming)
**Selection Sort** is a simple comparison-based sorting algorithm. It works by repeatedly finding the smallest (or largest, depending on sorting order) element from the unsorted part of the array and swapping it with the first element of the unsorted part. This process is repeated until the entire array is sorted.

---

### How Selection Sort Works
1. **Divide the Array into Sorted and Unsorted Parts**:
   - The sorted part starts empty and grows as the algorithm progresses.
   - The unsorted part shrinks as elements are moved into the sorted part.

2. **Find the Minimum Element**:
   - Iterate through the unsorted part to find the smallest element.

3. **Swap the Minimum with the First Element**:
   - Swap the found minimum element with the first element of the unsorted part.

4. **Repeat**:
   - Move the boundary of the sorted part one step to the right and repeat the process.

---

### Selection Sort Code in C

```c
#include <stdio.h>

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Assume the first element is the minimum
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Update minIndex if a smaller element is found
            }
        }
        // Swap the minimum element with the first element of the unsorted part
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
```

---

### Memory Visualization
Selection Sort operates **in-place**, meaning it does not require extra space for another array. Here's how the memory visualization looks:

1. **Initial State**:
   - Array: `[64, 25, 12, 22, 11]`
   - `minIndex` points to the first element.

2. **First Pass**:
   - Compare all elements to find the smallest (`11`).
   - Swap `11` with `64`.
   - Array after first pass: `[11, 25, 12, 22, 64]`.

3. **Second Pass**:
   - Consider the subarray `[25, 12, 22, 64]`.
   - Find the smallest (`12`).
   - Swap `12` with `25`.
   - Array after second pass: `[11, 12, 25, 22, 64]`.

4. **Subsequent Passes**:
   - Continue finding the minimum in the remaining unsorted part and swapping.

---

### Key Memory Aspects
- **In-Place Sorting**: Only a constant amount of extra memory is used (temporary variable for swapping).
- **Time Complexity**:
  - Best, Average, and Worst Case: \( O(n^2) \), as two nested loops are used.
- **Space Complexity**: \( O(1) \), as no additional data structures are used.


---
---
---



### Differences Between Bubble Sort, Insertion Sort, and Selection Sort

| **Aspect**               | **Bubble Sort**                           | **Insertion Sort**                         | **Selection Sort**                         |
|---------------------------|-------------------------------------------|--------------------------------------------|--------------------------------------------|
| **Basic Idea**            | Repeatedly compares adjacent elements and swaps them if they are in the wrong order. | Builds the sorted portion of the array by inserting each element into its correct position. | Selects the smallest (or largest) element from the unsorted portion and swaps it with the first element of the unsorted portion. |
| **Sorting Mechanism**     | Swaps adjacent elements to "bubble" the largest (or smallest) element to its correct position. | Inserts elements one by one into the correct position in the sorted portion. | Finds the minimum (or maximum) element in the unsorted portion and swaps it into the correct position. |
| **Time Complexity (Best)**| \( O(n) \) (if already sorted)            | \( O(n) \) (if already sorted)             | \( O(n^2) \) (no early exit possible)      |
| **Time Complexity (Worst)**| \( O(n^2) \)                             | \( O(n^2) \)                               | \( O(n^2) \)                               |
| **Time Complexity (Avg)** | \( O(n^2) \)                             | \( O(n^2) \)                               | \( O(n^2) \)                               |
| **Space Complexity**      | \( O(1) \)                               | \( O(1) \)                                 | \( O(1) \)                                 |
| **Stability**             | Stable                                   | Stable                                     | Not Stable                                 |
| **Best Use Case**         | When the array is nearly sorted or small. | When the array is nearly sorted or small.  | When memory is limited and stability is not required. |
| **Number of Swaps**       | High (many swaps in each iteration).      | Moderate (only necessary swaps).           | Low (one swap per iteration).              |
| **Number of Comparisons** | \( O(n^2) \) in all cases.               | \( O(n^2) \) in worst case; fewer in best. | \( O(n^2) \) in all cases.                 |

---

### Key Characteristics of Each Algorithm

#### 1. **Bubble Sort**
- **How It Works**: Compares adjacent elements and swaps them if they are out of order. Each pass moves the largest unsorted element to its correct position.
- **Advantages**: Simple to implement and understand.
- **Disadvantages**: Inefficient due to excessive swaps and comparisons.

#### 2. **Insertion Sort**
- **How It Works**: Iterates through the array, and for each element, inserts it into its correct position in the sorted portion.
- **Advantages**: Efficient for small or nearly sorted datasets; fewer swaps compared to Bubble Sort.
- **Disadvantages**: Inefficient for large unsorted datasets.

#### 3. **Selection Sort**
- **How It Works**: Finds the smallest (or largest) element in the unsorted portion and swaps it with the first element of the unsorted portion.
- **Advantages**: Minimal number of swaps; easy to implement.
- **Disadvantages**: Always performs \( O(n^2) \) comparisons, even if the array is already sorted; not stable.

---

### Visual Example
Consider sorting the array `[64, 25, 12, 22, 11]` in ascending order.

1. **Bubble Sort**:
   - Pass 1: `[25, 12, 22, 11, 64]` (largest element bubbles to the end).
   - Pass 2: `[12, 22, 11, 25, 64]`.
   - Pass 3: `[12, 11, 22, 25, 64]`.
   - Pass 4: `[11, 12, 22, 25, 64]`.

2. **Insertion Sort**:
   - Pass 1: `[25, 64, 12, 22, 11]` (insert 25 in the correct position).
   - Pass 2: `[12, 25, 64, 22, 11]`.
   - Pass 3: `[12, 22, 25, 64, 11]`.
   - Pass 4: `[11, 12, 22, 25, 64]`.

3. **Selection Sort**:
   - Pass 1: `[11, 25, 12, 22, 64]` (smallest element swapped with the first element).
   - Pass 2: `[11, 12, 25, 22, 64]`.
   - Pass 3: `[11, 12, 22, 25, 64]`.
   - Pass 4: `[11, 12, 22, 25, 64]`.

---

### Summary
- **Bubble Sort**: Best for teaching purposes or small datasets.
- **Insertion Sort**: Best for nearly sorted data or small datasets.
- **Selection Sort**: Best when memory is constrained and stability is not a concern.



---
---
---


Let's do a step-by-step breakdown for all three sorting algorithms using the array `[64, 25, 12, 22, 11]` in ascending order.

---

### 1. **Bubble Sort**

**Initial Array**: `[64, 25, 12, 22, 11]`

#### Pass 1:
- Compare `64` and `25` → Swap → `[25, 64, 12, 22, 11]`
- Compare `64` and `12` → Swap → `[25, 12, 64, 22, 11]`
- Compare `64` and `22` → Swap → `[25, 12, 22, 64, 11]`
- Compare `64` and `11` → Swap → `[25, 12, 22, 11, 64]`

**Array after Pass 1**: `[25, 12, 22, 11, 64]`

#### Pass 2:
- Compare `25` and `12` → Swap → `[12, 25, 22, 11, 64]`
- Compare `25` and `22` → Swap → `[12, 22, 25, 11, 64]`
- Compare `25` and `11` → Swap → `[12, 22, 11, 25, 64]`

**Array after Pass 2**: `[12, 22, 11, 25, 64]`

#### Pass 3:
- Compare `12` and `22` → No Swap → `[12, 22, 11, 25, 64]`
- Compare `22` and `11` → Swap → `[12, 11, 22, 25, 64]`

**Array after Pass 3**: `[12, 11, 22, 25, 64]`

#### Pass 4:
- Compare `12` and `11` → Swap → `[11, 12, 22, 25, 64]`

**Array after Pass 4**: `[11, 12, 22, 25, 64]`

**Final Sorted Array**: `[11, 12, 22, 25, 64]`

---

### 2. **Insertion Sort**

**Initial Array**: `[64, 25, 12, 22, 11]`

#### Pass 1:
- Take `25`, compare with `64` → Insert before `64`.
- **Array**: `[25, 64, 12, 22, 11]`

#### Pass 2:
- Take `12`, compare with `64` → Insert before `64`.
- Compare `12` with `25` → Insert before `25`.
- **Array**: `[12, 25, 64, 22, 11]`

#### Pass 3:
- Take `22`, compare with `64` → Insert before `64`.
- Compare `22` with `25` → Insert before `25`.
- **Array**: `[12, 22, 25, 64, 11]`

#### Pass 4:
- Take `11`, compare with `64` → Insert before `64`.
- Compare `11` with `25` → Insert before `25`.
- Compare `11` with `22` → Insert before `22`.
- Compare `11` with `12` → Insert before `12`.
- **Array**: `[11, 12, 22, 25, 64]`

**Final Sorted Array**: `[11, 12, 22, 25, 64]`

---

### 3. **Selection Sort**

**Initial Array**: `[64, 25, 12, 22, 11]`

#### Pass 1:
- Find the smallest element (`11`) and swap it with the first element (`64`).
- **Array**: `[11, 25, 12, 22, 64]`

#### Pass 2:
- Find the smallest element in the unsorted part (`12`) and swap it with `25`.
- **Array**: `[11, 12, 25, 22, 64]`

#### Pass 3:
- Find the smallest element in the unsorted part (`22`) and swap it with `25`.
- **Array**: `[11, 12, 22, 25, 64]`

#### Pass 4:
- The last two elements (`25` and `64`) are already in order.
- **Array**: `[11, 12, 22, 25, 64]`

**Final Sorted Array**: `[11, 12, 22, 25, 64]`


---
---
---





### Real-World Example of **Selection Sort**

Let’s use a real-world analogy to explain **Selection Sort**: **Selecting the shortest person in a line to form a height-based queue**.

---

### Scenario:
Imagine a teacher is asking students to line up in ascending order of height. The teacher uses the **Selection Sort** approach to arrange them.

---

### Steps:

1. **Start with the First Position**:
   - Look at all students in the line and find the shortest one.
   - Swap the shortest student with the one standing in the first position.

2. **Move to the Next Position**:
   - Ignore the first position (it’s already sorted).
   - Look at the remaining students and find the shortest one.
   - Swap the shortest student with the one in the second position.

3. **Repeat**:
   - Continue this process for each position until the entire line is sorted.

---

### Example:

#### Initial Heights of Students: `[64, 25, 12, 22, 11]`

1. **Step 1 (First Position)**:
   - Find the shortest student: `11`.
   - Swap `11` with the first student (`64`).
   - Line after Step 1: `[11, 25, 12, 22, 64]`.

2. **Step 2 (Second Position)**:
   - Find the shortest student in the remaining line (`25, 12, 22, 64`): `12`.
   - Swap `12` with the second student (`25`).
   - Line after Step 2: `[11, 12, 25, 22, 64]`.

3. **Step 3 (Third Position)**:
   - Find the shortest student in the remaining line (`25, 22, 64`): `22`.
   - Swap `22` with the third student (`25`).
   - Line after Step 3: `[11, 12, 22, 25, 64]`.

4. **Step 4 (Fourth Position)**:
   - Find the shortest student in the remaining line (`25, 64`): `25`.
   - No swap needed (already in the correct position).
   - Line after Step 4: `[11, 12, 22, 25, 64]`.

5. **Step 5 (Last Position)**:
   - Only one student left (`64`), no action needed.

**Final Sorted Line**: `[11, 12, 22, 25, 64]`.

---

### Key Points:
1. **Selection Process**:
   - At each step, you select the smallest (or largest) element from the unsorted part of the array.

2. **Real-Life Application**:
   - Sorting physical items by size, such as arranging books by height, organizing coins by diameter, or sorting cards by value.
