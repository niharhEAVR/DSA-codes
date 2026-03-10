# if you dont understand this count inversion by the doc then see the striver video again [Count Inversions in an Array](https://www.youtube.com/watch?v=AseUmwVNaoY&list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&index=42&t=1166s)

# ⭐ **What is an Inversion in an Array?**

An **inversion** is a pair of elements `(i, j)` such that:

\[
i < j \quad \text{AND} \quad arr[i] > arr[j]
\]

Meaning:

➡ The earlier element is **greater** than the later element.
➡ The array is **breaking** the ascending order at that point.

---

# 🌟 **Simple Example**

```
arr = [3, 1, 2]
```

Let’s list all pairs `(i, j)` where `i < j`:

| Pair (i, j) | Elements | Is arr[i] > arr[j]? | Inversion? |
| ----------- | -------- | ------------------- | ---------- |
| (0,1)       | (3,1)    | 3 > 1               | YES        |
| (0,2)       | (3,2)    | 3 > 2               | YES        |
| (1,2)       | (1,2)    | 1 > 2? No           | NO         |

### ✔ Total Inversions = **2**

---

# 🎯 Why is this important?

Inversions tells you **how far the array is from being sorted**.

* Fully sorted array → **0 inversions**
* Reverse sorted array → **maximum inversions**

This is used in:

✔ Sorting analytics
✔ Merge Sort problems
✔ Big coding questions (Amazon, Google, etc.)
✔ Fenwick Trees & segment trees
✔ Calculating how “unsorted” data is

---

# ⭐ Example 2

```
arr = [1, 20, 6, 4, 5]
```

Let’s find all inversions:

Pairs:

| (i,j)  | arr[i], arr[j] | Inversion? |
| ------ | -------------- | ---------- |
| (1,20) | ok             | no         |
| (20,6) | 20 > 6         | yes        |
| (20,4) | 20 > 4         | yes        |
| (20,5) | 20 > 5         | yes        |
| (6,4)  | 6 > 4          | yes        |
| (6,5)  | 6 > 5          | yes        |
| (4,5)  | no             |            |

### ✔ Total = **5 inversions**

---

# ❌ Brute Force Method

Check all pairs `(i, j)`:

```cpp
int count = 0;
for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
        if(arr[i] > arr[j]) count++;
    }
}
```

### ❌ Time Complexity = **O(n²)**

Too slow for large arrays.

---

# ✔ Optimal Method — **Modified Merge Sort**

Merge Sort can count inversions in **O(n log n)**.

### 🧠 Why does merge sort help?

When merging two sorted halves:

Left half = L
Right half = R

If:

```
L[i] <= R[j] → no inversion
L[i] > R[j]  → inversion!
```

But here comes the trick:

If `L[i] > R[j]`, then ALL elements from `L[i]` to the end of L are greater than R[j].

\[
\text{inversions} += (mid - i + 1)
\]

Because left and right are individually sorted.

---

# ⭐ Small visualization

Array:

```
[3, 5] and [1, 2]
```

During merge:

Compare 3 vs 1 → 3 > 1 → inversion
But also:

5 > 1
so 3 & 5 are both > 1 → 2 inversions

Then:

3 vs 2 → 3 > 2 → 1 inversion
5 vs 2 → 5 > 2 → 1 inversion

Total = 4

---

# ✔ FULL INTUITION (Very Clear)

When merging:

```
Left = [3, 5]
Right = [1, 2]
```

Both are already sorted inside themselves.

Pointer i at 3
Pointer j at 1

3 > 1 → inversion
But since left is sorted:
5 also > 1

So instead of checking pair-by-pair, we add:

\[
(\text{size of left} - i)
\]

This gives massive speedup → O(n log n)

---

---
---
---
---

# ⭐ 1. What Is an Inversion?

Given an array **A**, an inversion is a pair:

\[
(i, j) \quad \text{such that} \quad i < j \text{ and } A[i] > A[j]
\]

**Example:**
Array = `[3, 1, 2]`
Inversions are:

* (3,1)
* (3,2)

Total = **2**

---

# ⭐ 2. Why Brute Force Fails

Brute approach:

Check every pair `(i, j)` → O(N²)

If N = 10⁵ → 10¹⁰ comparisons → Impossible.

So we need a smarter method.

---

# ⭐ 3. How Merge Sort Helps (High-Level Idea)

Merge sort does this:

1. Split array into left and right halves.
2. Sort the left half.
3. Sort the right half.
4. Merge them.

**During merge step**, we see:

Left half is sorted.
Right half is sorted.

When you merge two sorted halves, **you naturally compare elements from left and right**.

And *this is the exact moment* we can detect inversions efficiently.

---

# ⭐ 4. The REAL INTUITION

This is VERY important and I’ll explain slowly.

### 📌 When do we find an inversion during merge?

Suppose:

Left = sorted
Right = sorted

We have two pointers:

* `i` → points in left
* `j` → points in right

During merging:

### If:

\[
Left[i] \le Right[j]
\]

→ NO inversion
→ Because all elements in right are ≥ Right[j], so they are ≥ Left[i].

### BUT IF:

\[
Left[i] > Right[j]
\]

➡️ This means:
Left[i] is bigger than Right[j].

But the left part is SORTED.
So ALL elements from `Left[i]` to `Left[end]` are bigger than Right[j].

Example:

Left = [2, 4, 6]
Right = [1, 5]

Compare:

Left[i] = 2
Right[j] = 1

Since 2 > 1 → Inversion found.

But not only (2,1).
Also (4,1)
Also (6,1)

These 3 elements in left are all > 1.

So we add **all remaining left elements**:

\[
\text{inversions} += (mid - i + 1)
\]

mid is nothing but this:
```cpp
        0 1 2
Left = [2,3,5]
        ^   ^
        i   mid
```
ex: 2-0+1 = 3

This is the HEART of the algorithm.

---

# ⭐ 5. Full Dry Run (Super Beginner Level)

Let's take:

```
arr = [5, 3, 2, 4, 1]
```

### Step 1 → Break using merge sort (just understand structure)

```
[5,3,2,4,1]
→ [5,3,2]   and   [4,1]
→ [5] [3,2]    and    [4] [1]
→ [3] [2]
```

Now start merging back while counting.

---

## 🔥 Merge [3] & [2]

Compare:

* 3 > 2 → inversion
  Also 3 is the only element in left.

So inversions += 1

Sorted: [2, 3]

---

## 🔥 Merge [5] & [2, 3]

Left = [5]
Right = [2, 3]

Compare:

* 5 > 2 → inversion (all elements in left)
  inversions += 1

* 5 > 3 → inversion
  inversions += 1

Sorted: [2, 3, 5]

**Total so far = 3**

---

## 🔥 Merge [4] & [1]

4 > 1 → inversion
inversions += 1

Sorted: [1, 4]

**Total so far = 4**

---

## 🔥 Merge [2, 3, 5] & [1, 4]

Left = [2,3,5]
Right = [1,4]

Start merging:

### 1st comparison:

* 2 > 1 → inversion
  Elements in left after index of 2 = [2,3,5] → 3 elements
  inversions += 3

### 2nd comparison:

Left = [2,3,5]
Right = [4]

2 ≤ 4 → no inversion
3 ≤ 4 → no inversion

### 3rd comparison:

5 > 4 → inversion
Elements left = [5] → 1
inversions += 1

Total from this merge = 4

**Grand Total = 4 (before) + 4 (now) = 8**

So answer = **8 inversions**

---

# ⭐ 6. The Coding Idea (Very Simple Pseudocode)

```
mergeSort(arr, low, high):
    if low >= high:
        return 0
    mid = (low + high) / 2

    leftCount = mergeSort(arr, low, mid)
    rightCount = mergeSort(arr, mid+1, high)
    mergeCount = merge(arr, low, mid, high)

    return leftCount + rightCount + mergeCount
```

And the **merge** function:

```
merge(arr, low, mid, high):
    i = low
    j = mid+1
    count = 0

    while i <= mid AND j <= high:
        if arr[i] <= arr[j]:
            take arr[i]
            i++
        else:
            take arr[j]
            count += (mid - i + 1)
            j++

    copy remaining elements

    return count
```

---

# ⭐ Summary of the Intuition

✔ Inversion means left element bigger than right element
✔ Merge sort naturally compares left vs right
✔ Both halves are sorted
✔ If **Left[i] > Right[j]**, then all remaining left elements are also > Right[j]
✔ So we add:

\[
(mid - i + 1)
\]

mid is nothing but this:
```cpp
        0 1 2
Left = [2,3,5]
        ^   ^
        i   mid
```

ex: 2-0+1 = 3


✔ That makes the algorithm:

\[
O(N \log N)
\]

Much faster than O(N²).


---

# 🎯 Final Code (Clean & Standard)

```cpp
long long mergeAndCount(vector<int> &arr, int l, int m, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);

    int i = 0, j = 0, k = l;
    long long inversions = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            inversions += (left.size() - i); // key line
        }
    }

    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];

    return inversions;
}

long long mergeSortAndCount(vector<int> &arr, int l, int r) {
    if (l >= r) return 0;

    int m = l + (r - l) / 2;
    long long inv = 0;

    inv += mergeSortAndCount(arr, l, m);
    inv += mergeSortAndCount(arr, m + 1, r);
    inv += mergeAndCount(arr, l, m, r);

    return inv;
}
```