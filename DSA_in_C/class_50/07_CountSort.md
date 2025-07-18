### **Counting Sort in DSA**

**Counting Sort** is a non-comparison-based sorting algorithm that works by counting the frequency of each unique element in the array. It is efficient when the range of input values is small compared to the number of elements to be sorted.

---

### **How Counting Sort Works**

#### Steps:
1. **Find the Range**: Determine the minimum and maximum values in the array to calculate the range of elements.
2. **Count Frequencies**: Create a count array of size equal to the range. Populate this array with the frequency of each element in the input array.
3. **Cumulative Count**: Modify the count array to store cumulative counts. This helps in placing the elements in their correct positions in the sorted array.
4. **Build the Output Array**: Iterate through the input array in reverse order (to maintain stability) and place elements in their correct positions in the output array.
5. **Copy to Original Array**: Copy the sorted elements from the output array back to the original array.

---

### **Memory Visualization**
Let’s visualize the memory layout with an example:

#### Input Array:  
\[ 4, 2, 2, 8, 3, 3, 1 \]

#### Step 1: Find the Range  
Minimum = 1, Maximum = 8, Range = \(8 - 1 + 1 = 8\)

#### Step 2: Create the Count Array  
Create a count array of size \(8\) (range of numbers):  
\[ 0, 0, 0, 0, 0, 0, 0, 0 \]

#### Step 3: Count Frequencies  
Count occurrences of each number:  
- 1 appears once.
- 2 appears twice.
- 3 appears twice.
- 4 appears once.
- 8 appears once.  

Count Array:  
\[ 1, 2, 2, 1, 0, 0, 0, 1 \]  
(Index corresponds to numbers \(1, 2, 3, \dots, 8\)).

#### Step 4: Cumulative Count  
Modify the count array to store cumulative counts:  
\[ 1, 3, 5, 6, 6, 6, 6, 7 \]  
(This tells us the position of each element in the sorted array.)

#### Step 5: Build the Output Array  
Create an output array of the same size as the input array:  
\[ \_, \_, \_, \_, \_, \_, \_ \]  

Place each element from the input array into the output array based on the cumulative count:  
1. Start with the last element (1): Place it at index \(1 - 1 = 0\). Update count array:  
   Count Array: \[ 0, 3, 5, 6, 6, 6, 6, 7 \]  
   Output Array: \[ 1, \_, \_, \_, \_, \_, \_ \]  
2. Next element (3): Place it at index \(5 - 1 = 4\). Update count array:  
   Count Array: \[ 0, 3, 4, 6, 6, 6, 6, 7 \]  
   Output Array: \[ 1, \_, \_, \_, 3, \_, \_ \]  
3. Repeat for all elements. Final output array:  
   \[ 1, 2, 2, 3, 3, 4, 8 \]

#### Step 6: Copy Back  
Copy the sorted elements from the output array to the original array.

---

### **Code Implementation in C**
```c
#include <stdio.h>
#include <string.h>

void countingSort(int arr[], int size) {
    int output[size]; // Output array
    int max = arr[0], min = arr[0];

    // Find the range of the input array
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    int range = max - min + 1;
    int count[range];
    memset(count, 0, sizeof(count)); // Initialize count array to 0

    // Count the occurrences of each element
    for (int i = 0; i < size; i++) {
        count[arr[i] - min]++;
    }

    // Compute cumulative count
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = size - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    countingSort(arr, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
```

---

### **Advantages of Counting Sort**
1. **Fast**: It has a time complexity of \(O(n + k)\), where \(n\) is the number of elements and \(k\) is the range.
2. **Stable**: It preserves the relative order of equal elements.
3. **Efficient for small ranges**: Works well when the range (\(k\)) is not significantly larger than \(n\).

---

### **Disadvantages of Counting Sort**
1. **Not suitable for large ranges**: If the range is much larger than the number of elements, it becomes inefficient.
2. **Extra memory required**: Needs additional space for the count array and output array.

---

### **Real-World Analogy**
Imagine sorting exam scores (ranging from 0 to 100) for a class of 30 students:
1. Create a tally sheet with 101 slots (one for each possible score).
2. Mark how many students got each score.
3. Use the tally to place scores in the correct order.

Counting Sort is perfect here because the range (0–100) is small and well-defined.