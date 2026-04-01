**Selection Sort** is one of the simplest sorting algorithms in **Data Structures and Algorithms (DSA)**.
It works by **repeatedly selecting the smallest (or largest) element** from the **unsorted part** of the array and **placing it at the beginning** (or end) of the sorted part.

Let’s go step-by-step 👇

---

### 🧠 Basic Idea:

1. Divide the array into **two parts**:

   * **Sorted part** (at the beginning)
   * **Unsorted part** (remaining elements)

2. Find the **smallest element** in the unsorted part.

3. **Swap** it with the **first element** of the unsorted part.

4. Move the boundary of the sorted part one step forward.

5. Repeat until the whole array is sorted.

---

### 📊 Example

Array:

```
[64, 25, 12, 22, 11]
```

**Step-by-step process:**

| Pass | Unsorted Array       | Smallest Element | Swap With | Resulting Array      |
| ---- | -------------------- | ---------------- | --------- | -------------------- |
| 1    | [64, 25, 12, 22, 11] | 11               | 64        | [11, 25, 12, 22, 64] |
| 2    | [25, 12, 22, 64]     | 12               | 25        | [11, 12, 25, 22, 64] |
| 3    | [25, 22, 64]         | 22               | 25        | [11, 12, 22, 25, 64] |
| 4    | [25, 64]             | 25               | 25        | [11, 12, 22, 25, 64] |

✅ Final sorted array:

```
[11, 12, 22, 25, 64]
```

---

### 💻 C++ Code Implementation

```cpp
#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // assume current index is smallest

        // find the index of the smallest element
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // swap the smallest with the first unsorted element
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
```

---

### ⚙️ Time & Space Complexity

| Case    | Time Complexity |
| ------- | --------------- |
| Best    | O(n²)           |
| Average | O(n²)           |
| Worst   | O(n²)           |

* **Space Complexity:** O(1) (in-place sorting)
* **Stable:** ❌ No (it can change the order of equal elements)
* **In-place:** ✅ Yes

---

### 🧩 Summary

| Feature      | Description                             |
| ------------ | --------------------------------------- |
| Type         | Comparison-based sorting                |
| Technique    | Selection                               |
| Stability    | Not stable                              |
| Complexity   | O(n²)                                   |
| Suitable for | Small datasets or when swaps are costly |


---
---
---


## 🧠 What is Time and Space Complexity?

| Type                 | Meaning                                                                           |
| -------------------- | --------------------------------------------------------------------------------- |
| **Time Complexity**  | How much **time (steps or operations)** your algorithm takes as input size grows. |
| **Space Complexity** | How much **extra memory** (RAM) your algorithm uses while running.                |

We measure both in terms of **n**, where `n` = number of input elements.

---

## ⚙️ Understanding **Time Complexity** of Selection Sort

Let’s look at this key part of the code 👇

```cpp
for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
        if (arr[j] < arr[minIndex]) {
            minIndex = j;
        }
    }
    swap(arr[i], arr[minIndex]);
}
```

Now let’s **count the number of operations** roughly.

---

### 🔍 Step-by-Step Count

#### Outer loop:

Runs from `i = 0` to `i = n - 2` → runs **(n - 1)** times → ≈ **n times**

#### Inner loop:

For each `i`, `j` runs from `i + 1` to `n - 1`:

* When i = 0 → j runs (n - 1) times
* When i = 1 → j runs (n - 2) times
* When i = 2 → j runs (n - 3) times
* …
* When i = n-2 → j runs 1 time

So total comparisons =

```
(n - 1) + (n - 2) + (n - 3) + ... + 1
```

That’s an arithmetic series:
$$[
\text{Sum} = \frac{n(n - 1)}{2}
]$$

---

### ⏱ Time Complexity = O(n²)

We only care about the **highest power of n**, so:

✅ **Best case:** O(n²)
✅ **Average case:** O(n²)
✅ **Worst case:** O(n²)

Because even if the array is already sorted, the inner loop **still runs** all comparisons.

---

## 🧮 Space Complexity of Selection Sort

Now look at memory usage:

Variables used:

```cpp
int i, j, minIndex;   // just a few variables
```

✅ No new array or data structure created
✅ Sorting happens **in the same array** (in-place)

So:

**Space Complexity = O(1)** (constant extra space)

---

## 📏 How to Measure in Future (General Rule)

### 1️⃣ **For Time Complexity**

Count **how many times each loop runs**, and multiply if they are nested.

Example:

```cpp
for(i = 0; i < n; i++)       // n times
  for(j = 0; j < n; j++)     // n times
     do something;
```

👉 Total steps = n * n = **O(n²)**

If you have:

```cpp
for(i = 0; i < n; i++)       // n times
  do something;
```

👉 Total steps = n = **O(n)**

---

### 2️⃣ **For Space Complexity**

Count **extra memory used** apart from the input.

Example:

```cpp
int arr[n];     // input array (not counted)
int temp;       // 1 variable → O(1)
```

✅ O(1)

But if you create another array:

```cpp
int temp[n];
```

Then ➡️ O(n) space.

---

### 3️⃣ **For Real Programs**

You can use a **timer** to *measure actual runtime* in C++:

```cpp
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    auto start = high_resolution_clock::now();

    // selection sort here
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken: " << duration.count() << " microseconds" << endl;
}
```

👉 This gives you **actual measured time**, not Big-O (theoretical) — useful for experiments.

---

## 🧩 Summary Table

| Aspect               | Selection Sort   |
| -------------------- | ---------------- |
| Outer loop           | n times          |
| Inner loop           | n-1, n-2, ..., 1 |
| Total comparisons    | n(n-1)/2         |
| **Time Complexity**  | O(n²)            |
| **Space Complexity** | O(1)             |
| **In-place**         | ✅ Yes            |
| **Stable**           | ❌ No             |
