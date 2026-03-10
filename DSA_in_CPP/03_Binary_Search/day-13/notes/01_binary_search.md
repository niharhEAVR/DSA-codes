# ⭐ What is Binary Search?

Binary Search is a searching algorithm used to **find an element in a sorted array** efficiently.

### 👉 Key idea:

You **do NOT** search the whole array.
Instead, you repeatedly split the array into half and decide which half to keep.

---

# 🧠 Intuition (feel this properly)

Suppose you have a phonebook with names sorted alphabetically.

You want to find **“Rohan”**.

Do you check every name from A → Z?

No!

You open the book near the middle:

* If the page shows names around **T**, you know **Rohan** must be **before** T → check left half.
* If the page shows names around **M**, you know **Rohan** must be **after** M → check right half.

You throw away HALF of the book every time.

This is exactly what Binary Search does.

---

# 🕰 History of Binary Search (very interesting!)

Binary Search might look simple today,
but it **once was considered one of the hardest algorithms to implement correctly.**

### 📌 Timeline:

### **1. 1940s – Concept existed**

The idea of halving search space was described in early computer science literature.

### **2. 1946 – Published formally**

Researchers like **John Mauchly** (ENIAC creator) described the halving technique.

### **3. 1946–1960 – Shocking fact**

Even though binary search is simple in theory,
**almost all programmers implemented it incorrectly** due to boundary issues
(low, high, mid mistakes).

A published study in 1988 proved that:

> **Out of 20 research papers and books, 16 had an incorrect binary search code.**

This shows how tricky it was!

### **4. Today – Standard algorithm**

Binary Search is now one of the **foundation algorithms** taught everywhere.

---

# 🔥 Why is Binary Search Preferred? (Very important)

Let's compare:

## ✔ Linear Search (Brute):

* Check elements one by one
* Time complexity:
  \[
  O(N)
  \]
* Very slow for large lists

## ✔ Binary Search (Optimal):

* Throw away half of search space each step
* Time complexity:
  \[
  O(\log N)
  \]

### 🔍 Example:

If N = 1,000,000 elements:

* Linear Search → 1,000,000 steps (worst)
* Binary Search →
  \[
  \log_2(1{,}000{,}000) \approx 20 \text{ steps only!}
  \]

ONLY **20 operations** instead of **1 million**.

This is why companies like Google, Amazon, Microsoft always use binary search in real systems.

---

# 📌 Where is Binary Search used?

Binary Search is NOT only used to find an element.

It is used in:

### ✔️ Searching in sorted arrays

### ✔️ Lower Bound / Upper Bound

### ✔️ Search on answer (very famous DSA technique)

### ✔️ Finding first/last occurrence

### ✔️ Peak element / mountain array

### ✔️ Binary search on floating point numbers

### ✔️ Binary search in applications (like load balancing, network routing)

---

# 🎯 Why is it considered *better*?

Because it gives massive improvement:

| Method        | Worst Time | Good for large data? |
| ------------- | ---------- | -------------------- |
| Linear Search | O(N)       | ❌ Slow               |
| Binary Search | O(log N)   | ✅ Very fast          |

---

# 🧩 Requirements of Binary Search

To use binary search:

1. **The array MUST be sorted.**
2. You maintain **low, high, and mid** indices.
3. You decide whether to go **left** or **right** based on comparison.

---

# 🔍 Final Summary (super short)

* Binary search = cutting search space in half every time.
* History: simple in theory but surprisingly difficult to implement correctly, mistakes found even in textbooks.
* Preferred because **O(log N)** is extremely fast.
* Used everywhere in DSA and real-world systems.

---
---
---

# 🔥 What are Binary Search Edge Cases?

Binary Search is simple in idea but tricky in implementation.
The main edge cases occur due to:

* boundaries (low, high)
* mid calculation
* search direction
* duplicates
* empty arrays
* sorted order changes

Let’s break it down properly.

---

# ⭐ 1. Empty Array Case

If the array has **0 elements**:

```cpp
low = 0
high = -1
```

Since `low > high` from start → loop never runs.
Return "not found" immediately.

---

# ⭐ 2. Single Element Array Case

Example: `[5]`

You must check:

* if `mid == target`
* or update the correct boundary

This helps ensure no infinite loop.

---

# ⭐ 3. Low > High (Termination Condition)

Binary search stops when:

```cpp
while (low <= high)
```

Edge case:
If you use `low < high`, your code becomes incorrect for arrays of size 1, and sometimes you skip the last element.

---

# ⭐ 4. Mid Overflow Case (VERY FAMOUS)

Classic mistake:

```cpp
mid = (low + high) / 2;  // ❌ overflow can happen
```

For large numbers, `low + high` can overflow `int`.

Correct version:

```cpp
mid = low + (high - low) / 2;  // ✅ safest
```

---

# ⭐ 5. Infinite Loop Edge Case

Happens if boundaries are not updated correctly.

Example:

```cpp
low = mid;   // ❌ wrong
high = mid;  // ❌ wrong
```

Correct:

```
low = mid + 1;
high = mid - 1;
```

Otherwise, you may get stuck because mid does not change.

---

# ⭐ 6. Duplicates in the Array

Binary search normally returns **any one index** of the target.

But when duplicates exist:

Example:
`[2, 4, 4, 4, 5]`

Edge case issues:

* First occurrence search
* Last occurrence search

You must adjust conditions carefully:

### For First Occurrence:

```cpp
if (arr[mid] == target)
     high = mid - 1;
```

### For Last Occurrence:

```cpp
if (arr[mid] == target)
     low = mid + 1;
```

---

# ⭐ 7. Array Sorted in Descending Order

Binary search normally assumes **ascending order**.

If array is descending, you must reverse conditions:

Example:

```cpp
if (arr[mid] > target)  // then go RIGHT (reverse)
```

This is a common edge mistake.

---

# ⭐ 8. Target Out of Range

Example:
Array: `[10, 20, 30, 40]`
Target: `5` or `100`

Binary search still works, but:

* You exit without finding
* Must return `-1`

Some implementations incorrectly access out-of-bound indices.

---

# ⭐ 9. Two-Element Array Case (Tricky Boundary)

Example: `[3, 9]`

Check both:

* mid becomes either 0 or 1
* low/high must be updated properly:

```cpp
if (target < arr[mid])
    high = mid - 1;
else
    low = mid + 1;
```

If someone uses wrong conditions, 2-element arrays break.

---

# ⭐ 10. Wrong Comparison Operator

Very common mistake:

```cpp
if (arr[mid] <= target)   // ❌ wrong for many problems
```

Correct for pure search:

```cpp
if (arr[mid] < target)
```

Because if equal, you should return index.

This mistake especially breaks "first/last occurrence" variations.

---

# ⭐ 11. Searching in Rotated Sorted Array

A rotated array like:
`[4, 5, 6, 7, 0, 1, 2]`

Edge case:
Normal binary search does **NOT** work because sorted order breaks.

You must detect left/right sorted halves.

---

# ⭐ Summary — All Binary Search Edge Cases

| Edge Case                 | Description                         |
| ------------------------- | ----------------------------------- |
| Empty array               | low > high from start               |
| Single element            | must check mid correctly            |
| mid overflow              | must use `low + (high-low)/2`       |
| Infinite loop             | low=mid or high=mid                 |
| Duplicates                | special handling for first/last occ |
| Descending array          | reverse comparison logic            |
| Out-of-range target       | must return -1 safely               |
| Two-element array         | must update boundaries properly     |
| Wrong comparison operator | breaks many patterns                |
| Rotated array             | requires modified logic             |

---
---
---
---

### ✔ Sorting first takes

\[
O(N \log N)
\]

### ✔ And then Binary Search takes

\[
O(\log N)
\]

Total =
\[
O(N \log N + \log N) \approx O(N \log N)
\]

While **linear search** is
\[
O(N)
\]

---

# 🔥 So is linear search better for unsorted arrays?

### YES — **If you only need to search once.**

Because:

* Sorting = *expensive*
* One linear scan = *cheaper*

Example:
N = 1,000,000

* Sorting → ~20,000,000 operations
* Linear search → 1,000,000 operations
* Binary search → 20 operations (but AFTER sorting)

So for **single search**, linear is better for unsorted data.

---

# ⭐ HOWEVER — This is where binary search shows its real power:

## ✔ If you need to search multiple times

Suppose the array is large and you need to answer **many queries**:

Example:
You need to search **10,000 values** inside the same array.

Then:

### 1️⃣ Sort once →

\[
O(N \log N)
\]

### 2️⃣ Binary Search for each query →

\[
10{,}000 \times O(\log N)
\approx 10{,}000 \times 20 = 2,00,000\text{ operations}
\]

Total operations ≈ **20M + 0.2M = 20.2M**

But with **Linear Search**:

\[
10{,}000 \times 1{,}000{,}000 = 10^{10}
\]

= **10 billion operations → extremely slow**

So for **multiple queries**, binary search destroys linear search.

---

# ⭐ Real-world systems prefer binary search because:

Real databases, search engines, and apps:

* Keep data **sorted**
* Run **millions of queries**
* Sorting is done only **once**
* Searching is extremely fast after that

Examples:

* Facebook friend list
* Google contacts
* Phonebook app
* Search in dictionaries
* Database indexes (B-trees use binary search internally)
* CPU instruction lookups
* Compilers

Binary search is used everywhere **because data stays sorted**.

---

# ⭐ When to use which?

### ✔ Use **Linear Search** when:

* Array is **unsorted**
* Only **one search** or a few searches
* Data is very small

### ✔ Use **Binary Search** when:

* Array is **sorted**
* You need **fast search**
* You have **many search queries**
* Or searching needs to be predictable and optimized

---

# 🧠 Final Summary

| Condition                     | Best Search              |
| ----------------------------- | ------------------------ |
| Unsorted array, 1 search      | **Linear Search**        |
| Unsorted array, many searches | **Sort + Binary Search** |
| Sorted array                  | **Binary Search**        |
| Real systems with large data  | **Binary Search**        |

---
---
---
---


# ⭐ The REAL reason Binary Search is preferred (beyond sorted array)

People think:

> "Binary Search is good because array is sorted."

But the **actual** power is deeper:

## 🔥 Binary Search gives *guaranteed logarithmic decisions*

Every step cuts the search space **in half**, no matter what.

That means:

* No matter how large the input,
* You make at most **log₂(n)** decisions,
* And each decision is constant time.

This structure is powerful enough that…

---

# ⭐ Binary Search is used EVEN when the array is not sorted

Yes, this is the surprising part!

Binary Search is used for problems where the **data is not sorted at all**, but the **answer space is sorted**.

This is called:

# 🔥 “Binary Search on Answer”

(very advanced but most important technique in DSA)

Examples:

### ✔ Allocate minimum number of pages

### ✔ Aggressive cows

### ✔ Painters partition

### ✔ Koko eating bananas

### ✔ Shipping packages in D days

### ✔ Minimum speed to arrive on time

In all these problems:

* The **array is not sorted**
* But the **possible answer** is monotonic (increasing or decreasing)
* So binary search still works!

This is the **non-obvious** beauty of binary search.

---

# ⭐ Another deep reason: structure matters more than data

Binary search cares about **order**, not sorting algorithm.

If your data structure naturally keeps things ordered (like trees):

### BST → O(log n)

### AVL tree → O(log n)

### Red-Black tree → O(log n)

### B-Tree / B+Tree (databases) → O(log n)

These structures are basically doing binary-search logic internally.

---

# ⭐ When is Linear Search actually better in practice?

Here’s the **real** answer (not the obvious one):

### ✔ For very small arrays (n < 30)

Linear search is faster than binary search due to:

* CPU cache friendliness
* no mid-calculation
* no branch misprediction

That's why in competitive programming:

If the array is tiny → just use linear search.

---

# ⭐ Unsorted + Single Search → Linear

(This you already knew)

Nothing special.

---

# ⭐ Unsorted + Many searches → Use hash table

Better than binary search!

This is the **best, non-obvious point**:

### If you repeatedly search in an unsorted array,

💥 Don’t sort the array → use a hash map.

HashMap average complexity:
[
O(1)
]

Much better than **O(log n)** of binary search.

This is why:

* Python dict
* C++ unordered_map
* Java HashMap

are so important.

---

# ⭐ Final high-level comparison (professional level)

| Data                            | 1 search | Many searches | Insert/Delete | Best method                 |
| ------------------------------- | -------- | ------------- | ------------- | --------------------------- |
| Unsorted                        | Linear   | HashMap       | Easy          | HashMap                     |
| Sorted                          | Binary   | Binary        | Hard          | Binary Search               |
| Not sorted but answer monotonic | —        | —             | —             | **Binary search on answer** |
| Dynamic + always sorted         | Binary   | Binary        | Easy          | Balanced BST / Heaps        |

---

# ✔ Final Short Summary (Non-Obvious Insights)

* Binary search isn't important for *sorted arrays* — it's important for *logarithmic decision making*.
* It works even when the array is **not sorted**, if the **answer space** is ordered.
* For unsorted data with many searches → use **hash tables**, not sorting + binary search.
* For tiny arrays, **linear search is faster** in practice.
* For large static data, **binary search dominates**.



---
---
---


# ⭐ Does Binary Search Always Use Recursion?

**No.**

Binary Search can be implemented in **two ways**:

---

## ✔ 1. Recursive Binary Search

Example style:

```cpp
int bs(arr, low, high, target) {
    if (low > high) return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == target) return mid;
    if (arr[mid] < target)
        return bs(arr, mid + 1, high, target);
    else
        return bs(arr, low, mid - 1, target);
}
```

### Space complexity (recursive):

* Each recursive call goes one level deeper.
* Maximum recursion depth = **log₂(n)**

\[
\text{Space} = O(\log n)
\]

So yes, **recursive binary search uses extra space**.

---

## ✔ 2. Iterative Binary Search (MOST COMMON, USED IN INTERVIEWS)

This is the preferred version:

```cpp
int binarySearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
```

### Space complexity (iterative):

* No recursion
* Only 3–4 variables (`low`, `high`, `mid`)

\[
\text{Space} = O(1)
\]

So iterative binary search has the **same space complexity as linear search**.

---

# ⭐ So what’s the final answer?

| Algorithm                     | Time Complexity | Space Complexity |
| ----------------------------- | --------------- | ---------------- |
| **Linear Search**             | O(n)            | O(1)             |
| **Binary Search (recursive)** | O(log n)        | O(log n)         |
| **Binary Search (iterative)** | O(log n)        | O(1)             |

---

# ✔ Which one is used in DSA + interviews?

Almost always **iterative binary search**, because:

* No recursion overhead
* No stack frame memory
* Predictable and safe
* Matches real-world implementations (C++ STL uses it)

Thus:

### 🔥 Binary Search (iterative) → O(1) space

### 🔥 Linear Search → O(1) space

Both are the same in space, but binary search wins in **time**.

---

# ⭐ Key takeaway

Binary Search **does NOT require recursion**.
Recursion is just one way to write it.

The **optimal** and commonly used form uses **iteration**, so:

\[
\text{Space} = O(1)
\]
