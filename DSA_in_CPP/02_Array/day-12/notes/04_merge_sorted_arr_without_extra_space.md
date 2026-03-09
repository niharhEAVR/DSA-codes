# ✅ **Problem Name:** Merge Two Sorted Arrays *Without Extra Space*

---

# 🌟 **What is the problem? (Very Very Beginner Explanation)**

You are given **two arrays**, both are already sorted.

Example:

```
A = [1, 3, 5, 7]
B = [2, 4, 6, 8]
```

Your job:

👉 **Combine them in such a way that after merging, both arrays are still sorted — AND you are NOT allowed to create a new array.**
You must use only the given two arrays.

Meaning:

* You can touch the elements inside A
* You can touch the elements inside B
* But you **cannot create C = []**
* You **cannot use extra space**

At the end, if we combine A and B, it should form **one big sorted list**.

---

# 🧠 **Why is this problem tricky?**

Because usually merging means:

```
Take elements from A and B, put them into a new array C.
```

But here, you **cannot** create C.
You must rearrange elements **inside** A and B.

This means:

* Some elements from A might need to go to B
* Some elements from B might need to come to A
* You must do swapping, comparing, shifting… carefully
* And ensure **both arrays end sorted**

---

# 🎯 **What is the final goal?**

After you finish, if someone simply writes all elements of A and then all elements of B, the result must be sorted.

Example expected output:

```
A = [1, 2, 3, 4]
B = [5, 6, 7, 8]
```

---

# 🔍 **But WHY can’t we use extra space?**

Because this is a **DSA interview trick**.

It checks:

✔ How you think
✔ How you handle two sorted lists
✔ How you avoid unnecessary space
✔ How you manipulate arrays in-place

---

# 🧩 **What do we need to do conceptually?**

Let’s imagine:

* A has small numbers (mostly)
* B has small → big numbers

But sometimes:

```
A = [1, 4, 7, 8, 10]
B = [2, 3, 9]
```

Here notice:

* 4 (in A) is bigger than 2 (in B)
* Also 7 is bigger than 3
* But 1 is fine

So what should happen?

We fix the arrays like this:

```
A = [1, 2, 3, 4, 7]
B = [8, 9, 10]
```

---

# 🧠 **Intuition (VERY IMPORTANT)**

Think like this:

👉 If any element in **A** is **greater** than the **smallest element** in **B**,
then that A-element is in the wrong place.

Example:

A = [1, 4, 7]
B = [2, 3, 9]

Here:

* Compare `A[0]` with `B[0]`
  → 1 < 2 → fine
* Compare `A[1]` with `B[0]`
  → 4 > 2 → problem
  → Swap them so 2 goes into A, 4 into B
* Again fix B so it remains sorted
* Continue…

That’s the whole idea.

---

# 🧠 Simplified Story Version

Think of A and B as two boxes of sorted balls:

* A has mostly smaller balls
* B has mostly bigger balls

But sometimes A mistakenly contains a few bigger balls, and B contains a few smaller balls.

Your job:

👉 Move the **too big balls** from A into B
👉 Move the **too small balls** from B into A

Until both boxes are PERFECTLY sorted again.

And you must do this:

❌ Without creating a new box
✔ Only swapping inside A and B

---

# 🚦When are we done?

When every element in A is **smaller than or equal** to every element in B.

Because then:

```
A | B  (combined)  → will be sorted
```

Example:

A = [1, 2, 3]
B = [4, 5, 6]

Everything in A ≤ everything in B
➡ DONE

But:

A = [1, 5, 7]
B = [2, 4, 6]

Here:

5 > 2 → problem
We must fix.

---

# 🎯 Final Target Understanding

The mission is:

* Do NOT create a new array
* Both arrays should be sorted
* Combined result should be sorted
* Use swaps, comparisons, maybe gaps (in better approaches)

---
---
---



# ⭐ Understanding Example 1 of Leetcodes

### **Input:**

```
nums1 = [1,2,3,0,0,0]
m = 3

nums2 = [2,5,6]
n = 3
```

### ❓ What do m and n mean?

* `m = 3` → Only **first 3 elements** of nums1 are real sorted numbers
  → So nums1 real part:
  `[1, 2, 3]`

* After these 3 numbers, there are zeros:
  `[0, 0, 0]` → These ZEROES are **just placeholders**, empty spaces.

* `n = 3` → nums2 has 3 numbers:
  `[2, 5, 6]` (also sorted)

---

### 🧠 So the REAL merging is:

```
nums1 real part = [1, 2, 3]
nums2 = [2, 5, 6]
```

Imagine nums1 is like a big box:
`[1 2 3 _ _ _]`

The last 3 blanks (0s) are just empty spots where nums2 elements will go.

---

### 🎯 The result AFTER merging sorted:

```
[1, 2, 2, 3, 5, 6]
```

So nums1 becomes:

```
1, 2, 2, 3, 5, 6
```

These are the two lists combined in sorted order.

---

# ⭐ Understanding Example 2

### Input:

```
nums1 = [1]
m = 1

nums2 = []
n = 0
```

### Meaning:

* nums1 has **1 real element**: `[1]`
* nums2 has **no elements**: `[]`
* There is nothing to merge.

So result still:

```
[1]
```

Simple.

---

# ⭐ Understanding Example 3

### Input:

```
nums1 = [0]
m = 0

nums2 = [1]
n = 1
```

### Meaning (IMPORTANT):

* `m = 0` → nums1 has **0 real numbers**

* nums1 looks like `[0]` but the **0 is NOT a real value**
  It is an **empty space** kept for merging.

* nums2 = `[1]` has one number.

So real nums1 = `[]`
real nums2 = `[1]`

We merge them, result is:

```
[1]
```

And this replaces nums1.

---

# ⭐ Why does nums1 have 0 when m = 0?

Because nums1 must always have enough space to store all merged elements.

Since nums2 has 1 element, nums1 must have length = m + n = 0 + 1 = 1.

That’s why nums1 = `[0]`
The zero is just a placeholder.

---

# ⭐ Final Summary (Super Simple)

| Example | nums1 real | nums2 real | Merge result  | Why zeros?                    |
| ------- | ---------- | ---------- | ------------- | ----------------------------- |
| 1       | [1,2,3]    | [2,5,6]    | [1,2,2,3,5,6] | zeros = empty spaces          |
| 2       | [1]        | []         | [1]           | no merging                    |
| 3       | []         | [1]        | [1]           | nums1 had space for one value |



---
---
---
---




# ✅ We will use the the **“Three Pointer Backward Merge”** approach.

Also known as:

### ✔ **Two-pointer merge from the end**

### ✔ **In-place backward merge**

### ✔ **Reverse merging technique**

Why backward?

Because nums1 contains extra empty space **at the end**, and if we start filling from the front, we overwrite numbers before using them.

So we fill nums1 from the **backwards**.

This avoids the need for extra arrays.

---

# 🧠 **How it works (very small summary)**

Use three pointers:

```
i → end of real data in nums1       (m-1)
j → end of nums2                    (n-1)
k → very end of nums1 total array   (m+n-1)
```

Compare nums1[i] and nums2[j]:

* Put the **bigger** at nums1[k]
* Move pointers backward

This is EXACTLY how merging works in Merge Sort —
but done **from the back** to avoid overwriting.

---

# 📈 **Time Complexity (TC)**

### 👉 **O(m + n)**

Why?

* Every element of nums1 real part is processed **once**
* Every element of nums2 is processed **once**
* No element is visited more than once

So total work:

```
m + n operations
```

---

# 📦 **Space Complexity (SC)**

### 👉 **O(1)**

Why?

* We do not create any new arrays
* Only use a few integers: i, j, k
* Everything is done **in-place** inside nums1

So space usage is **constant**, not depending on m or n.

---

# ⭐ Final Answer Summary

| Concept          | Value                                               |
| ---------------- | --------------------------------------------------- |
| Approach         | **Three-pointer backward merge** / In-place merging |
| Time Complexity  | **O(m + n)**                                        |
| Space Complexity | **O(1)**                                            |

---
---
---


# 🥇 **This is the OPTIMAL approach**

Because:

* **Time Complexity = O(m + n)** → minimum possible
* **Space Complexity = O(1)** → also minimum possible
* Works in-place
* Uses the best merging technique

You cannot do better than:

* **Linear time**
* **Constant extra space**

So this is **optimal**.

---

# Levels of approaches (for your understanding)

### 1️⃣ Brute Force

* Combine both arrays into a new array
* Sort the new array
* TC = **O((m+n) log (m+n))**
* SC = **O(m+n)**
  ❌ Not allowed in this question
  ❌ Uses extra space
  ❌ Slower

---

### 2️⃣ Better Approach

* Copy nums1 real part into temp
* Merge temp + nums2 into nums1
* TC = **O(m+n)**
* SC = **O(m)**
  ⚠️ Uses extra space
  ⚠️ Still not optimal because SC≠O(1)

---

### 3️⃣ 🥇 **Optimal Approach**

* Three pointers
* Merge from the **backwards**
* No extra array
* TC = **O(m+n)**
* SC = **O(1)**
  ✔️ Fastest
  ✔️ No extra memory
  ✔️ Interviewer's favorite
  ✔️ LeetCode intended solution



---
---
---


This is the **standard optimal solution**, merging from the **backwards**.


```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;         // last real element of nums1
        int j = n - 1;         // last element of nums2
        int k = m + n - 1;     // last position of nums1

        // Merge from the back
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        // If nums2 still has elements left
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};
```

---

# ⭐ Why this code works

### ✔ We fill nums1 **from the end**, so we don’t overwrite useful data

### ✔ Compare largest remaining elements from both arrays

### ✔ Put the larger one at the back

### ✔ Decrease pointers

### ✔ If nums2 has leftover smaller elements, copy them

---

# 🔍 Dry Run (Beginner Friendly)

### Example:

```
nums1 = [1,2,3,0,0,0], m=3
nums2 = [2,5,6], n=3
```

Pointers:

```
i = 2 → nums1[2] = 3
j = 2 → nums2[2] = 6
k = 5 → last index to fill
```

Compare:

* 3 vs 6 → 6 bigger
  → nums1[5] = 6
  Update pointers: j--, k--

Next:

* Compare 3 vs 5 → 5 bigger
  → nums1[4] = 5

Next:

* Compare 3 vs 2 → 3 bigger
  → nums1[3] = 3

Next:

* Compare 2 vs 2 → 2 from nums2 goes
  → nums1[2] = 2

Next:

* Compare 2 vs ?
  nums2 finished? No

Finally nums2 leftover copied.

Final:

```
[1,2,2,3,5,6]
```

Sorted + correct.
