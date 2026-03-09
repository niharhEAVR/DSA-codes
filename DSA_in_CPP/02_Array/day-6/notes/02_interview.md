**One of the most common DSA interview questions** for arrays!

> “Find the second largest element in the array.”

Interviewers use this to test:

* Your **problem-solving thinking path** (brute → better → optimal),
* Your understanding of **time and space trade-offs**,
* And how you **write efficient logic step by step**.

Let’s go through **all three approaches** — **Brute, Better, and Optimal** — with clear logic, code, and analysis.

---

# 🧩 Problem Statement

> Given an array of integers, find the **second largest element** (the number which is smaller than the largest but greater than all others).

Example:

```
Input: [10, 5, 8, 20, 2]
Output: 10
Explanation: Largest = 20, Second Largest = 10
```

---

# ⚙️ Step 1: Brute Force Approach

### 🧠 Idea:

* Sort the array.
* The second largest element will be **at the second last index** after sorting (if all are unique).

### 💻 Code:

```cpp
#include <bits/stdc++.h>
using namespace std;

int secondLargest(vector<int>& arr) {
    sort(arr.begin(), arr.end());          // Step 1: sort array
    int n = arr.size();
    for (int i = n - 2; i >= 0; i--) {     // Step 2: move backward
        if (arr[i] != arr[n - 1])          // first element smaller than max
            return arr[i];
    }
    return -1; // if no second largest exists (like all elements equal)
}
```

### ⏱️ Time Complexity:

* Sorting → **O(n log n)**
* Loop for second largest → **O(n)**
  ✅ Overall: **O(n log n)**

### 💾 Space Complexity:

* Sorting modifies the array or uses internal temp → **O(1)** (in-place) or **O(n)** (depending on sort implementation).

---

# ⚙️ Step 2: Better Approach

### 🧠 Idea:

We can find it **without sorting** — just **two passes**:

1. Find the **largest element**.
2. Find the **largest element smaller than that**.

### 💻 Code:

```cpp
int secondLargest(vector<int>& arr) {
    int n = arr.size();
    int largest = INT_MIN;

    // Pass 1: find largest
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest)
            largest = arr[i];
    }

    int second = INT_MIN;

    // Pass 2: find element smaller than largest
    for (int i = 0; i < n; i++) {
        if (arr[i] != largest && arr[i] > second)
            second = arr[i];
    }

    return (second == INT_MIN) ? -1 : second;
}
```

### ⏱️ Time Complexity:

* 2 passes through array → **O(2n) = O(n)**
  ✅ Linear time

### 💾 Space Complexity:

* Only a few variables → **O(1)**

---

# ⚙️ Step 3: Optimal Approach ✅ (Single Pass)

### 🧠 Idea:

We can find both **largest and second largest** in a **single loop**:

* Keep track of both as we traverse.
* Update both carefully when you find a new larger number.

### 💻 Code:

```cpp
int secondLargest(vector<int>& arr) {
    int n = arr.size();
    int largest = INT_MIN, second = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            second = largest;     // update second first
            largest = arr[i];     // update largest
        }
        else if (arr[i] > second && arr[i] != largest) {
            second = arr[i];      // update second largest
        }
    }

    return (second == INT_MIN) ? -1 : second;
}
```

### 🕒 Time Complexity:

* Single traversal → **O(n)**
  ✅ **Most efficient**

### 💾 Space Complexity:

* Constant variables → **O(1)**

---

# 📊 Summary Comparison

| Approach    | Logic                     | Time Complexity | Space Complexity | Explanation         |
| ----------- | ------------------------- | --------------- | ---------------- | ------------------- |
| **Brute**   | Sort array, pick 2nd last | O(n log n)      | O(1)             | Easiest but slow    |
| **Better**  | Two separate loops        | O(n)            | O(1)             | Simple + efficient  |
| **Optimal** | Single pass tracking      | O(n)            | O(1)             | Best for interviews |

---

# 💬 Why We Follow This Path (Brute → Better → Optimal)

Interviewers want to **see your thought process** — not just the final answer.

| Stage       | What You Show                                   | Why It Matters                            |
| ----------- | ----------------------------------------------- | ----------------------------------------- |
| **Brute**   | You can come up with a correct working solution | Shows your basic logic                    |
| **Better**  | You realize inefficiency (sorting not needed)   | Shows optimization thinking               |
| **Optimal** | You reduce passes & memory                      | Shows you can write clean, efficient code |

So even in interviews, **always start simple**, then **optimize step-by-step**, explaining *why* each improvement matters.

---

# ⚠️ Edge Cases to Mention in Interview

✔️ Array has all elements same → return -1
✔️ Array has only 1 element → no second largest
✔️ Negative numbers → works fine
✔️ Unsorted array → logic still holds

Example:

```
Input: [5, 5, 5]
Output: -1 (no second largest)
```

---

# ✅ Example Dry Run (Optimal)

Array: `[10, 5, 8, 20, 2]`

| i | arr[i] | largest | second | Explanation   |
| - | ------ | ------- | ------ | ------------- |
| 0 | 10     | 10      | -∞     | First element |
| 1 | 5      | 10      | -∞     | No change     |
| 2 | 8      | 10      | 8      | Update second |
| 3 | 20     | 20      | 10     | Update both   |
| 4 | 2      | 20      | 10     | No change     |

✅ Final: second largest = 10
