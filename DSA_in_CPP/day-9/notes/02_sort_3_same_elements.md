The **Dutch National Flag Algorithm** (often called **DNF algorithm**) is a **classic array partitioning algorithm** in DSA — invented by **Edsger W. Dijkstra**.

It’s one of the most elegant ways to **sort or rearrange elements with three distinct categories**, all in **one single pass (O(n))** and **constant space (O(1))**.

---

## 🧩 Real Problem Statement

Imagine you have an array that contains only **three types of elements**, for example:

```
0, 1, 2
```

You need to **sort them** such that all `0`s come first, then all `1`s, then all `2`s.

Example:

```
Input:  [2, 0, 1, 2, 1, 0]
Output: [0, 0, 1, 1, 2, 2]
```

You must do it:

* in **one traversal** (O(n) time),
* and **without using extra space** (O(1)).

---

## 🚩 Why "Dutch National Flag"?

The algorithm is named after the **Dutch national flag**, which has **three colors** — red, white, and blue.
The array’s three distinct values (e.g., 0, 1, 2) represent these **three colors**.

Your task is like **arranging colored balls** so that:

* All **reds (0)** come first,
* All **whites (1)** come next,
* All **blues (2)** come last.

---

## ⚙️ Core Concept

We use **three pointers**:

| Pointer | Role                                |
| ------- | ----------------------------------- |
| `low`   | boundary for 0s (red zone)          |
| `mid`   | current element under consideration |
| `high`  | boundary for 2s (blue zone)         |

---

### 🔁 Algorithm Steps

1️⃣ Initialize:

```cpp
low = 0, mid = 0, high = n - 1
```

2️⃣ While `mid <= high`:

* If `arr[mid] == 0`
  → swap(`arr[low]`, `arr[mid]`),
  → increment both `low++` and `mid++`.

* Else if `arr[mid] == 1`
  → just `mid++` (correct zone).

* Else if `arr[mid] == 2`
  → swap(`arr[mid]`, `arr[high]`),
  → decrement `high--` only (don’t increment mid yet).

3️⃣ Loop ends when `mid > high`.

---

## 🔍 Example Visualization

Let’s take:

```
arr = [2, 0, 1, 2, 1, 0]
low=0, mid=0, high=5
```

| Step | Array              | low | mid | high | Action                                                    |
| ---- | ------------------ | --- | --- | ---- | --------------------------------------------------------- |
| 1    | [2, 0, 1, 2, 1, 0] | 0   | 0   | 5    | arr[mid]==2 → swap(mid,high) → [0, 0, 1, 2, 1, 2], high-- |
| 2    | [0, 0, 1, 2, 1, 2] | 0   | 0   | 4    | arr[mid]==0 → swap(low,mid), low++, mid++                 |
| 3    | [0, 0, 1, 2, 1, 2] | 1   | 1   | 4    | arr[mid]==0 → swap(low,mid), low++, mid++                 |
| 4    | [0, 0, 1, 2, 1, 2] | 2   | 2   | 4    | arr[mid]==1 → mid++                                       |
| 5    | [0, 0, 1, 2, 1, 2] | 2   | 3   | 4    | arr[mid]==2 → swap(mid,high) → [0,0,1,1,2,2], high--      |
| 6    | [0,0,1,1,2,2]      | 2   | 3   | 3    | arr[mid]==1 → mid++                                       |
| ✅    | End                |     |     |      | Sorted ✅                                                  |

---

## ✅ Code (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

void dutchNationalFlag(vector<int> &arr) {
    int low = 0, mid = 0, high = arr.size() - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } 
        else if (arr[mid] == 1) {
            mid++;
        } 
        else { // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    vector<int> arr = {2, 0, 1, 2, 1, 0};
    dutchNationalFlag(arr);
    
    for (int x : arr)
        cout << x << " ";
}
```

Output:

```
0 0 1 1 2 2
```

---

## 🧮 Complexity

* **Time:** O(n) — one pass.
* **Space:** O(1) — in-place swaps.
* **Stable?** ❌ Not stable (may change relative order of equal elements).

---

## 🧠 Real Use-Cases

* Sorting arrays with **three distinct values** (like 0/1/2).
* Partitioning problems (e.g., **quicksort** partition step).
* RGB / flag color problems.
* Problems like “Sort colors” on LeetCode (#75).

---
---
---


That line:

> ❌ **Not stable (may change relative order of equal elements)**

refers to a concept called ***stability*** in sorting algorithms.

Let’s break that down clearly 👇

---

### 🧩 What is “stable sorting”?

A **stable sort** means that **if two elements are equal**, their **original order** in the array is **preserved** after sorting.

#### Example

Say you have an array of **(value, position)** pairs:

```
[(0, A), (1, B), (1, C), (0, D)]
```

Here, the values are what we sort by (`0, 1, 1, 0`).

A **stable sort** will give:

```
[(0, A), (0, D), (1, B), (1, C)]
```

→ Notice how `(1, B)` comes **before** `(1, C)** — the same order as before sorting.

✅ **Original relative order preserved for equal elements.**

---

### ⚠️ Why DNF is **not stable**

In the **Dutch National Flag Algorithm**, we **swap elements** without caring about their original positions.
So, two equal elements (like two 1s) can change order because of the swaps.

#### Example

If input:

```
[2a, 0, 1a, 2b, 1b, 0]
```

After DNF sorting, output might be:

```
[0, 0, 1b, 1a, 2b, 2a]
```

Here `1a` and `1b` swapped their original relative order → ❌ **unstable.**

---

### 🧠 TL;DR

| Term                              | Meaning                                   |
| --------------------------------- | ----------------------------------------- |
| **Stable Sort**                   | Keeps the same order among equal elements |
| **Unstable Sort**                 | Equal elements may swap positions         |
| **Dutch National Flag Algorithm** | ✅ Fast (O(n)), ✅ In-place, ❌ Not stable   |
