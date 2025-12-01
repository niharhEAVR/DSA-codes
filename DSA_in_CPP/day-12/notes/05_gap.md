# Before reading this doc, visit the [merge_sorted_arr_without_extra_space](./04_merge_sorted_arr_without_extra_space.md) to understand why the gap method needed

---

# 🧠 1. **Where did the GAP METHOD come from?**

The gap method originally comes from an ancient sorting algorithm called:

### 👉 **Shell Sort (1959, invented by Donald Shell)**

Shell sort uses the concept of:

> “Compare elements that are far apart using a *gap*,
> then gradually reduce the gap until it becomes 1.”

This makes the array more sorted early,
so fewer swaps happen later.

---

# 🎯 GAP METHOD was later reused for another purpose:

### ❗ Merging two sorted arrays **without using extra space**.

Because normally, merging two arrays requires an extra array.
But interviewers often ask:

> “Merge two sorted arrays with **O(1)** extra space.”

The backward 3-pointer method works **only** when the first array has extra space at the end (like the LeetCode problem).

But what if:

```
Array A = [1, 4, 8, 10]
Array B = [2, 3, 9]
```

There is NO extra space at the end of A.

So you cannot use the backward pointer method.

Here the **Gap Method** becomes useful.

---

# 🧩 2. **So what is the GAP method (in simple words)?**

Imagine you want to merge two arrays, but you are **not allowed** to create a new array.

So the idea is:

### 🔹 Instead of comparing adjacent elements

### 🔹 Compare elements that are “gap” distance apart

### 🔹 Gradually reduce the gap like Shell sort

### 🔹 Keep swapping until entire combined region is sorted

Eventually, when gap becomes 1 → you are doing adjacent comparisons → array is fully sorted.

---

# 🧪 Example intuition:

If gap = 5, compare:

```
arr[0] with arr[5]
arr[1] with arr[6]
arr[2] with arr[7]
...
```

Then reduce gap → 3
Then 2
Then 1

At the end, both arrays are merged and sorted.

---

# 📜 3. **History of the GAP Method**

### ✔ Invented in 1959 inside Shell Sort

Shell sort used the idea of *gap-based comparisons* to reduce the total number of swaps.

### ✔ Around 2000s, programmers realized:

This trick can also be used to **merge two sorted arrays without extra memory**.

### ✔ Competitive programmers started using it

Especially in:

* Interviews
* Codeforces
* GeeksForGeeks
* Old-school programming exams

Because it works even when the first array does *not* have extra space.

### ✔ Today, it is one of two main optimal solutions for in-place merging:

1. Three-pointer backward merge (optimal for LeetCode merge array problem)
2. Gap method (optimal when you have *two separate arrays*)

---

# 🎒 4. **Where GAP method is used today?**

### ⭐ In-place merging of two arrays

(When you cannot use extra memory)

### ⭐ Memory-restricted systems

(embedded systems, old hardware)

### ⭐ Interview problems

“Merge sorted arrays when no extra space is allowed.”

### ⭐ As a sub-step in some hybrid sorting algorithms

That optimize memory usage.

---

# 💡 5. **Why use the GAP method?**

Because:

### ✔ It requires **NO EXTRA SPACE (O(1))**

### ✔ It keeps time complexity efficient **O((n+m) log(n+m))**

### ✔ Works for ANY TWO ARRAYS (not necessarily like nums1+nums2 format)

### ✔ Very easy to implement compared to complex in-place merge techniques

### ✔ Derived from a proven algorithm (Shell Sort)

---

# 📘 6. **Why not just use normal merge like in merge sort?**

Because merge sort’s merge step needs:

* A temporary array
* Copies back into original array

That uses **O(n+m) extra space**, which is not allowed in many interview questions.

GAP METHOD solves that.

---

# 🏆 7. Summary in 5 points (VERY beginner-friendly)

### ⭐ Gap method came from Shell Sort (1959).

### ⭐ Uses a *gap* (distance) between compared elements.

### ⭐ Gradually reduces the gap until it becomes 1.

### ⭐ Helps merge two arrays **without extra space**.

### ⭐ Used in interviews & competitive programming.

---
---
---

<br>
<br>
<br>



# ✅ **We want to merge two sorted arrays WITHOUT extra space**

Example arrays:

```
A = [1, 4, 8, 10]
B = [2, 3, 9]
```

Total length = 7
So we treat A + B as one combined logical region.

```
Combined = [1, 4, 8, 10, | 2, 3, 9]
```

We do *not* actually join them —
we only **logically** think of them together.

---

# ⭐ Step 1: **Find initial GAP**

Initial gap = ceil((n + m) / 2)

Here:

```
(n + m) = 7
gap = ceil(7 / 2) = 4
```

That means:

👉 compare elements that are **4 positions apart**

---

# ⭐ Step 2: **Compare elements gap apart**

Visual:

Index:   0   1   2   3   4   5   6
Value:  [1,  4,  8, 10,  2,  3,  9]

Gap = 4 → compare pairs:

### Pair 1

Compare index 0 with 4:

```
1  vs  2  → correct order → no swap
```

### Pair 2

Compare index 1 with 5:

```
4  vs  3  → wrong order → swap
```

After swap:

```
[1, 3, 8, 10, 2, 4, 9]
```

### Pair 3

Compare index 2 with 6:

```
8  vs  9  → correct → no swap
```

Done for gap = 4.

---

# ⭐ Step 3: **Reduce gap**

Formula:

```
gap = ceil(gap / 2)
```

Previously gap = 4 → now:

```
gap = ceil(4 / 2) = 2
```

---

# ⭐ Step 4: Repeat comparing with gap = 2

Current array:

```
[1, 3, 8, 10, 2, 4, 9]
```

Compare pairs gap = 2:

### Pair 1

index 0 with 2:

```
1 vs 8 → ok
```

### Pair 2

index 1 with 3:

```
3 vs 10 → ok
```

### Pair 3

index 2 with 4:

```
8 vs 2 → wrong → swap
```

After swap:

```
[1, 3, 2, 10, 8, 4, 9]
```

### Pair 4

index 3 with 5:

```
10 vs 4 → wrong → swap
```

```
[1, 3, 2, 4, 8, 10, 9]
```

### Pair 5

index 4 with 6:

```
8 vs 9 → ok
```

Done.

---

# ⭐ Step 5: Reduce gap again

```
gap = ceil(2 / 2) = 1
```

This means we now do NORMAL ADJACENT comparison —
like bubble sort final pass.

This guarantees full sorted merge.

---

# ⭐ Step 6: Gap = 1 (final pass)

Current state:

```
[1, 3, 2, 4, 8, 10, 9]
```

Compare adjacently:

### idx 0 vs 1

1 vs 3 → ok

### idx 1 vs 2

3 vs 2 → swap

```
[1, 2, 3, 4, 8, 10, 9]
```

### idx 2 vs 3

3 vs 4 → ok

### idx 3 vs 4

4 vs 8 → ok

### idx 4 vs 5

8 vs 10 → ok

### idx 5 vs 6

10 vs 9 → swap

```
[1, 2, 3, 4, 8, 9, 10]
```

And now the entire combined region is sorted.

---

# 🌟 FINAL RESULT

A and B merged **in place**, no extra memory, using GAP:

```
[1, 2, 3, 4, 8, 9, 10]
```

Split back into A and B:

```
A = [1, 2, 3, 4]
B = [8, 9, 10]
```

Sorted & merged.

---

# 📌 Why does this work?

Because:

* Big gap = fixes large wrong placements quickly
* Smaller gap = fixes medium mistakes
* Gap = 1 = final full sorting

It’s exactly like **Shell Sort**, but applied to **two arrays merged mentally**.

---

# 🔥 Short summary (beginner-friendly)

* Think A + B as one long array
* Start with large GAP
* Compare + swap numbers that are GAP apart
* Shrink GAP until it becomes 1
* Result becomes fully sorted → arrays merged

---
---
---


# ✅ 1. **Gap Method — Full Correct Code (C++ Version)**

This is the fully correct and clean implementation:

```cpp
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // Step 1: Put nums2’s elements into nums1’s empty spaces
    for(int i = 0; i < n; i++){
        nums1[m + i] = nums2[i];
    }

    // Now nums1 contains m+n elements but not sorted yet
    int total = m + n;

    // Gap function
    auto nextGap = [&](int gap){
        if(gap <= 1) return 0;
        return (gap / 2) + (gap % 2);
    };

    // Step 2: Apply GAP sorting logic
    for(int gap = nextGap(total); gap > 0; gap = nextGap(gap)){
        int left = 0;
        int right = left + gap;

        while(right < total){
            if(nums1[left] > nums1[right]){
                swap(nums1[left], nums1[right]);
            }
            left++;
            right++;
        }
    }
}
```

---

# ✅ 2. **Time & Space Complexity (Gap Method)**

### **Time Complexity**

Gap reduces like:

\[
Gap = \frac{n}{2}, \frac{n}{4}, \frac{n}{8}, ...
\]

Total comparisons per phase:
\[
O(n)
\]

Total phases:
\[
O(\log n)
\]

So total time:

\[
O(n \log n)
\]

where (n = m + n)

---

### **Space Complexity**

\[
SC = O(1)
\]

✔ No extra array
✔ Only a few variables
✔ Modifies nums1 in-place

---

# ✅ 3. **Gap Method vs 3-Pointer Method (Backward Merge)**

---

## **Approach 1: 3-Pointer (Optimal for this specific LeetCode problem)**

✔ Works backward from the end
✔ Compares largest elements
✔ Stores result inside nums1

### **Time**

\[
O(m+n)
\]

### **Space**

\[
O(1)
\]

### **Best For**

When **nums1 has extra space at the end** (exactly like this problem).

---

## **Approach 2: Gap Method (Shell-sort idea)**

✔ Works like Shell Sort with reducing gap
✔ Compares far elements then near
✔ Eventually sorts everything

### **Time**

\[
O((m+n)\log(m+n))
\]

Not as fast as 3-pointer, but still good.

### **Space**

\[
O(1)
\]

### **Best For**

When:

* You must **merge two arrays without using any extra space**
* And **nums1 DOES NOT have guaranteed space at the end**
* Or merging **two separate arrays**, not necessarily inside nums1.
* Used in interview problems:
  **“Merge two sorted arrays without extra space”** (both arrays separate)

---

## **Comparison Table**

| Method                 | Time                 | Space  | When Useful                                              |
| ---------------------- | -------------------- | ------ | -------------------------------------------------------- |
| **3-Pointer Backward** | **O(m+n)**           | O(1)   | When nums1 has space at end (LeetCode version)           |
| **Gap Method**         | **O((m+n)log(m+n))** | O(1)   | When merging two arrays in-place, no extra space allowed |
| **Brute Copy & Sort**  | O((m+n)log(m+n))     | O(m+n) | Easiest but not allowed in interviews                    |

---

# ⭐ Summary (Super Beginner-Friendly)

* **3-pointer** = fast, easy, perfect for LeetCode.
* **Gap method** = mathematically beautiful Shell-sort idea, used when strict “no extra space” rule.
* **Gap method history** = inspired from **Shell Sort (1959)** with reducing GAP technique.
