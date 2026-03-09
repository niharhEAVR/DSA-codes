## 🧩 What is Quick Sort?

Quick Sort works by:

1. **Choosing a pivot** element from the array.
2. **Partitioning** the array around that pivot —
   all elements smaller than the pivot go to its left,
   and all greater elements go to its right.
3. **Recursively sorting** the left and right parts.

---

## ⚙️ Step-by-Step Working Example

Let’s say our array is:

```
[8, 4, 7, 3, 10, 5]
```

### Step 1: Choose a Pivot

Let’s take the **last element** as the pivot.
👉 `pivot = 5`

### Step 2: Partition the array

We rearrange elements so that:

* Elements smaller than pivot (5) come **before it**
* Elements larger than pivot come **after it**

After partition:

```
[4, 3, 5, 8, 10, 7]
```

Now pivot `5` is in the correct sorted position.

Left subarray: `[4, 3]`
Right subarray: `[8, 10, 7]`

### Step 3: Recursively apply quick sort

* Sort `[4, 3]`

  * Pivot = 3 → rearrange → `[3, 4]`
* Sort `[8, 10, 7]`

  * Pivot = 7 → rearrange → `[7, 8, 10]`

Final sorted array:

```
[3, 4, 5, 7, 8, 10]
```

---

## 💻 C++ Code for Quick Sort

```cpp
#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // choose last element as pivot
    int i = low - 1;       // pointer for smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]); // move smaller element to left
        }
    }
    swap(arr[i + 1], arr[high]); // place pivot in correct position
    return i + 1; // return pivot index
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // partition index

        // Recursively sort left and right subarrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {8, 4, 7, 3, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
```

---

## 🧠 Time Complexity

| Case    | Time Complexity | Explanation                                              |
| ------- | --------------- | -------------------------------------------------------- |
| Best    | **O(n log n)**  | Pivot divides array evenly                               |
| Average | **O(n log n)**  | Typical case                                             |
| Worst   | **O(n²)**       | When pivot is always smallest/largest (unbalanced split) |

> Example of worst case: already sorted array `[1, 2, 3, 4, 5]` with last element as pivot.

---

## 💾 Space Complexity

* **O(log n)** → for recursive calls
  (Quick Sort is an **in-place** sort — no extra array used)

---

## 🧮 Characteristics

✅ Fast and widely used (used internally in many libraries)
✅ In-place sorting (no extra memory like merge sort)
⚠️ Not stable (relative order of equal elements may change)
⚠️ Worst case can be O(n²)

---
---
---
---




Let’s do a full **dry run and visualization step-by-step** for the array:

```
arr = [8, 4, 7, 3, 10, 5]
```

We’ll use this **C++ code** (same as before):

```cpp
quickSort(arr, 0, 5);
```

---

## 🧩 Step 1: quickSort(arr, 0, 5)

**Pivot = arr[5] = 5**
`i = -1` initially (it keeps track of where smaller elements end)

We loop `j` from `0` to `4`.

| j | arr[j] | Compare with pivot(5) | i value | Action                                     |
| - | ------ | --------------------- | ------- | ------------------------------------------ |
| 0 | 8      | 8 > 5                 | i = -1  | no swap                                    |
| 1 | 4      | 4 < 5                 | i = 0   | swap(arr[0], arr[1]) → [4, 8, 7, 3, 10, 5] |
| 2 | 7      | 7 > 5                 | i = 0   | no swap                                    |
| 3 | 3      | 3 < 5                 | i = 1   | swap(arr[1], arr[3]) → [4, 3, 7, 8, 10, 5] |
| 4 | 10     | 10 > 5                | i = 1   | no swap                                    |

After loop ends:

* `i = 1`
* Swap `arr[i+1]` with `pivot` → swap(arr[2], arr[5])
  👉 `[4, 3, 5, 8, 10, 7]`

✅ Now **pivot 5** is in its **correct position** → index `2`

**Left part:** `[4, 3]` (low=0, high=1)
**Right part:** `[8, 10, 7]` (low=3, high=5)

---

## 🧩 Step 2: quickSort(arr, 0, 1)

Pivot = arr[1] = 3
`i = -1`

| j | arr[j] | Compare with pivot(3) | i      | Action  |
| - | ------ | --------------------- | ------ | ------- |
| 0 | 4      | 4 > 3                 | i = -1 | no swap |

Swap arr[i+1] and pivot → swap(arr[0], arr[1])
→ `[3, 4, 5, 8, 10, 7]`

✅ Pivot 3 fixed at index 0
Left: none
Right: `[4]` (only one element → already sorted)

---

## 🧩 Step 3: quickSort(arr, 3, 5)

Pivot = arr[5] = 7
`i = 2`

| j | arr[j] | Compare with pivot(7) | i     | Action  |
| - | ------ | --------------------- | ----- | ------- |
| 3 | 8      | 8 > 7                 | i = 2 | no swap |
| 4 | 10     | 10 > 7                | i = 2 | no swap |

Swap arr[i+1] with pivot → swap(arr[3], arr[5])
→ `[3, 4, 5, 7, 10, 8]`

✅ Pivot 7 fixed at index 3
Left: none
Right: `[10, 8]` (low=4, high=5)

---

## 🧩 Step 4: quickSort(arr, 4, 5)

Pivot = arr[5] = 8
`i = 3`

| j | arr[j] | Compare with pivot(8) | i     | Action  |
| - | ------ | --------------------- | ----- | ------- |
| 4 | 10     | 10 > 8                | i = 3 | no swap |

Swap arr[i+1] and pivot → swap(arr[4], arr[5])
→ `[3, 4, 5, 7, 8, 10]`

✅ Pivot 8 fixed at index 4

Left: none
Right: none

---

## 🧾 FINAL RESULT

```
[3, 4, 5, 7, 8, 10]
```

---

## 🧠 Visualization of Recursive Calls

Let’s visualize it as a **recursion tree** showing how the array breaks down:

```
quickSort([8,4,7,3,10,5])
        pivot=5
     /                \
[4,3]               [8,10,7]
pivot=3              pivot=7
  |                   |
[3,4]             [7,8,10]
                      pivot=8
                       |
                   [7,8,10]
```

---

## 🔍 Key Observations

| Step | Pivot | Result after partition | Pivot Position |
| ---- | ----- | ---------------------- | -------------- |
| 1    | 5     | [4, 3, 5, 8, 10, 7]    | 2              |
| 2    | 3     | [3, 4, 5, 8, 10, 7]    | 0              |
| 3    | 7     | [3, 4, 5, 7, 10, 8]    | 3              |
| 4    | 8     | [3, 4, 5, 7, 8, 10]    | 4              |


---
---
---

Yes — **Quick Sort absolutely uses the concept of *backtracking*** — but not in the same “search and undo” way we see in problems like *N-Queens* or *Sudoku*.

Let’s go step by step and deeply understand **how and why backtracking happens inside Quick Sort.**

---

## 🧠 First — What is Backtracking?

**Backtracking** means:

> “Going back (returning) after exploring one recursive path completely, and then exploring other paths.”

So in any algorithm that:

1. Makes a **recursive call**,
2. **Returns back** once that subproblem is solved,
3. And then **continues with the next part** of the problem…

👉 It is *using* backtracking.

---

## ⚙️ How Quick Sort Uses Backtracking

Let’s recall the main recursive function:

```cpp
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);   // left part
        quickSort(arr, pi + 1, high);  // right part
    }
}
```

---

### 🔹 Step 1: The Recursive Call Stack

When you call `quickSort(arr, 0, 5)`,
it partitions and calls:

* `quickSort(arr, 0, pi-1)` (left side)
* `quickSort(arr, pi+1, high)` (right side)

Each call goes **deeper and deeper** into the recursion stack.

That stack works like this:

| Stack Frame          | What It’s Doing             |
| -------------------- | --------------------------- |
| quickSort(0,5)       | Main call                   |
| → quickSort(0,1)     | Sorting left of pivot       |
| → quickSort(0,0)     | Base case reached           |
| ← Return (backtrack) | Goes back up to parent call |
| → quickSort(3,5)     | Then sorts right of pivot   |

When one recursive call finishes (like left part),
the function **returns** to the previous stack frame —
and then continues sorting the right side.

➡️ **That "return and continue" movement is backtracking.**

---

### 🔹 Step 2: The Flow of Backtracking (Visualized)

Let’s visualize the recursion and backtracking for array:

```
[8, 4, 7, 3, 10, 5]
```

#### Call tree (simplified):

```
quickSort(0,5)
 ├── quickSort(0,1)
 │     ├── quickSort(0,0)
 │     └── quickSort(1,1)
 └── quickSort(3,5)
       ├── quickSort(3,3)
       └── quickSort(4,5)
```

Now watch the flow:

1. Start → `quickSort(0,5)`
2. It calls `quickSort(0,1)` → goes **deeper**
3. Inside `quickSort(0,1)`, it calls `quickSort(0,0)`

   * Base case reached → **returns** (backtrack)
4. Then `quickSort(1,1)` called

   * Base case reached → **returns**
5. Now left side done → returns to parent `quickSort(0,5)`
6. Then proceeds with `quickSort(3,5)` → deeper again
7. Similarly sorts its left and right → backtrack after each

So at each step:

* You **go deeper** into recursion for a smaller subarray,
* Then **come back up (backtrack)** after sorting it,
* And continue sorting the other side.

---

### 🔹 Step 3: Why Backtracking Is Necessary

Without backtracking, Quick Sort would:

* Go into one recursive call,
* Never return to complete the other half,
* Leaving half the array unsorted.

Backtracking allows it to:
✅ Complete sorting of **one subarray**,
✅ Then **return** to handle the **next subarray**,
✅ Until all partitions are sorted.

---

## 🔁 Analogy — "Sorting with Two Doors"

Imagine:

* You’re standing in a hallway with two doors (left and right).
* You always go through the **left door first** until you can’t (base case).
* Then you **come back (backtrack)** to where you were,
* And now go through the **right door**.

This is exactly what happens in Quick Sort:

* “Left door” = left partition
* “Right door” = right partition
* “Coming back” = backtracking to parent call

---

## 🧩 In Short:

| Concept          | In Quick Sort                                             |
| ---------------- | --------------------------------------------------------- |
| **Recursion**    | Divides the array into smaller subarrays                  |
| **Backtracking** | Returns after finishing one subarray to process the other |
| **Base case**    | When `low >= high`, recursion stops                       |
| **Stack memory** | Keeps track of all active recursive calls                 |

---

## 🔍 Example of Stack Activity

Imagine a stack (top = latest function call):

```
quickSort(0,5)
 ├── partition done
 ├── calls quickSort(0,1)
     ├── calls quickSort(0,0) → returns (backtrack)
     └── calls quickSort(1,1) → returns (backtrack)
 └── calls quickSort(3,5)
     ├── calls quickSort(3,3) → returns
     └── calls quickSort(4,5)
         ├── calls quickSort(4,4) → returns
         └── calls quickSort(5,5) → returns
```

Each **return** = one **backtracking** step.

---

### 🔚 Final Thought

So, in short:

> Quick Sort uses **recursion to divide** and **backtracking to return** after completing each side of the partition.

It’s like exploring all left subarrays first (depth-first),
then **backtracking up** to handle the right ones.



---
---
---




> some people says that space complexity of the quicksort is O(1)

---

## 🧠 The Short Answer:

> ❌ **No**, Quick Sort’s **space complexity is not O(1)**.
> ✅ It’s **O(log n)** on average (and **O(n)** in the worst case).

---

## 🧩 Why People Say It’s O(1)

Because Quick Sort:

* Sorts the array **in-place** (it doesn’t create a new array like Merge Sort).
* Only uses a few **variables** during partitioning (like `i`, `j`, `pivot`).

So, in terms of **extra array storage**,
it **does** use **O(1)** additional memory.

👉 That’s why people *loosely* say “Quick Sort is O(1) space.”

But that’s only **part of the story**.

---

## 🧮 The Full Story — Recursive Calls Use Stack Memory

Even though the array is sorted **in-place**,
Quick Sort is a **recursive** algorithm.

Each recursive call (function call) is stored on the **call stack** until it finishes.

So if Quick Sort divides the array many times,
the recursion depth becomes significant —
and each level of recursion **consumes stack space**.

---

### 🔹 Example

Let’s say you call:

```cpp
quickSort(arr, 0, n-1);
```

Each recursive call pushes:

* `low`
* `high`
* Local variables (pivot, i, j)

onto the **stack**.

If the recursion depth is `log n` (typical balanced partitioning),
then the **stack space = O(log n)**.

---

## 📉 But in the Worst Case…

If your pivot choice is **bad** (e.g., always smallest or largest element),
then the partition is **unbalanced** every time.

That means:

* 1 side has 0 elements,
* the other side has `n-1` elements.

So recursion depth becomes **n**,
and **stack memory = O(n)**.

---

## 📊 So the Real Space Complexity

| Case                  | Space Complexity | Reason                                                   |
| --------------------- | ---------------- | -------------------------------------------------------- |
| **Best / Average**    | **O(log n)**     | Balanced partitions → log n recursion depth              |
| **Worst**             | **O(n)**         | Unbalanced partitions (already sorted input + bad pivot) |
| **Extra (non-stack)** | **O(1)**         | In-place partitioning uses constant variables            |

---

## 💡 In Summary

| Type of Space                    | Complexity                    | Notes                      |
| -------------------------------- | ----------------------------- | -------------------------- |
| **Extra memory (array storage)** | O(1)                          | In-place sorting           |
| **Recursion stack memory**       | O(log n) average / O(n) worst | From recursive calls       |
| **Total (real)**                 | ✅ O(log n) average            | Realistic space complexity |

---

## 🧠 So Why Confusion Happens

People sometimes **ignore recursion stack space**
and only count **extra variables** → O(1).
But in **DSA and theory**, we must include recursion stack usage.

That’s why **officially**, Quick Sort’s space complexity is:

> ✅ **O(log n)** on average
> ❌ **Not O(1)**
