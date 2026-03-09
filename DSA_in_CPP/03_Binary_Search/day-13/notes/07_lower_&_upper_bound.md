# 🚀 1. LOWER BOUND

### **Definition (Very Important)**

**Lower Bound** = first position where
\[
arr[i] \geq x
\]

i.e., **first element not less than x**.

If `x` exists → lower bound gives the **first occurrence** of `x`.
If `x` doesn’t exist → it gives the **position to insert x** to keep array sorted.

---

## ⭐ Example 1

```
arr = [1, 3, 3, 5, 7]
x = 3
```

Lower Bound = index of **first element ≥ 3**
→ element = 3 at index **1**

✔ **Answer = 1**

## ⭐ Example 2 (x not present)

```
arr = [1, 3, 3, 5, 7]
x = 4
```

First element ≥ 4 = **5** at index **3**

✔ **Answer = 3**

---

## 🔥 Binary Search Implementation

```cpp
int lowerBound(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high) {
        int mid = (low + high) >> 1;

        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
```

---

# 🚀 2. UPPER BOUND

### **Definition**

**Upper Bound** = first position where
\[
arr[i] > x
\]

i.e., **first element strictly greater than x**.

---

## ⭐ Example 1

```
arr = [1, 3, 3, 5, 7]
x = 3
```

First element > 3 = **5** at index **3**

✔ **Answer = 3**

---

## ⭐ Example 2

```
arr = [1, 3, 3, 5, 7]
x = 6
```

First element > 6 = 7, index **4**

✔ **Answer = 4**

---

## 🔥 Binary Search Implementation

```cpp
int upperBound(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high) {
        int mid = (low + high) >> 1;

        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
```

---
---
---


# 🔥 PART 1 — LOWER BOUND (Ultimate In-Depth Explanation)

## ⭐ **CORE IDEA (If you remember only this, you're a master)**

Lower Bound =
**the first index `i` where `arr[i] >= x`**

It doesn’t care whether `x` exists or not.

---

# 🔍 WHY DO WE NEED LOWER BOUND?

We want to find the **earliest place** where `x` can fit in sorted order.

Examples:

### If array is:

```
[1, 3, 3, 5, 7]
```

### Query 1: x = 3

Where does 3 start?
→ at index **1**

### Query 2: x = 4

Where can we place 4 such that array stays sorted?
→ at index **3** (before 5)

**Lower bound gives both answers using one logic.**

---

# 🎯 KEY OBSERVATION THAT MAKES LOWER BOUND WORK

We are searching for the:

👉 **leftmost element that is ≥ x**

This means:

* when `arr[mid] >= x`,
  **mid might be the answer**,
  but maybe there is an even better one on the LEFT
  → so we move `high = mid - 1`

* when `arr[mid] < x`,
  `mid` is too small
  → look RIGHT
  → `low = mid + 1`

We keep shrinking the search window.

---

# 🔥 LOWER BOUND DRY RUN (Super detailed)

Let:

```
arr = [1, 3, 3, 5, 7]
x = 3
```

### Start:

```
low = 0, high = 4
ans = 5 (default)
```

---

### Step 1:

mid = (0+4)/2 = 2
arr[2] = 3 → (>= x)

So this mid is a valid answer.
But maybe there's another 3 on left.

So:

```
ans = 2
high = 1
```

---

### Step 2:

mid = (0+1)/2 = 0
arr[0] = 1 (< x)

Too small → go right

```
low = 1
```

---

### Step 3:

mid = (1+1)/2 = 1
arr[1] = 3 (>= x)

Valid → store it
But try to find smaller index

```
ans = 1
high = 0
```

Then loop stops.

---

### Final lower bound = 1

(first index where arr[i] ≥ 3)

✔ Correct!

---

# ⚠️ LOWER BOUND EDGE CASES

### Case 1 — x smaller than all elements

```
arr = [10, 20, 30]
x = 5
```

First ≥ 5 is 10 → index 0.

### Case 2 — x greater than all elements

```
arr = [1,2,3]
x = 10
```

No element ≥ 10
Return arr.size() = 3

### Case 3 — duplicates

```
arr = [2,4,4,4,5]
x = 4
```

Lower bound gives 4's 1st index = 1.

---

# 🎯 LOWER BOUND RETURNS:

* index of x’s first appearance if x exists
* where x should be inserted if x doesn’t

---

# 🔥 Code (perfect binary search)

```cpp
int lowerBound(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high) {
        int mid = (low + high) >> 1;

        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1; // go LEFT
        } else {
            low = mid + 1;  // go RIGHT
        }
    }
    return ans;
}
```

---

# 🚀 PART 2 — UPPER BOUND (Ultimate In-Depth)

## ⭐ **CORE IDEA**

Upper Bound =
**the first index `i` where `arr[i] > x`**

Important: NOT ≥ x
It is **strictly greater**.

---

# 🎯 WHY DO WE NEED UPPER BOUND?

Example:

```
arr = [2, 4, 4, 4, 6, 8]
```

### lowerBound(4) = 1

### upperBound(4) = 4

That means:

* 4 starts at index 1
* 4 ends just before index 4

Number of 4s = `upper - lower = 3`.

Also used in:

* ranges
* order statistics
* frequency count
* finding elements greater than x

---

# 🔥 UPPER BOUND DRY RUN (Fully detailed)

```
arr = [1, 3, 3, 5, 7]
x = 3
```

We want first element **greater** than 3.

### Start:

```
low = 0, high = 4
ans = 5
```

---

### Step 1:

mid = 2
arr[2] = 3 (NOT > x)

So ignore left → look right

```
low = 3
```

---

### Step 2:

mid = (3+4)/2 = 3
arr[3] = 5 (> x)

Valid answer → but check if any > x is on left

```
ans = 3
high = 2
```

Loop ends.

✔ Upper Bound = 3

---

# ⚠️ UPPER BOUND EDGE CASES

### Case 1 — all elements smaller:

```
arr = [1,2,3]
x = 5
```

No element > 5
Return arr.size() = 3

### Case 2 — x is biggest element

similar to above.

### Case 3 — duplicates:

```
arr = [2,4,4,4,6]
x = 4
```

Upper bound = index of first 6 = 4.

---

# 🔥 Code (perfect)

```cpp
int upperBound(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high) {
        int mid = (low + high) >> 1;

        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1;  // go LEFT
        } else {
            low = mid + 1;   // go RIGHT
        }
    }
    return ans;
}
```

---

# 🎉 SUPER IMPORTANT DIFFERENCE (Understanding in your bones)

| Query           | Condition     | Returns                            |
| --------------- | ------------- | ---------------------------------- |
| **Lower Bound** | `arr[i] >= x` | first occurrence / insert position |
| **Upper Bound** | `arr[i] > x`  | end of duplicates / next bigger    |

---

# 🧠 BEST WAY TO VISUALIZE (Magic Trick)

Take array:

```
arr = [1,2,2,2,3,7,9]
```

Search x = 2.

### Lower Bound = 1

(First 2)

### Upper Bound = 4

(First > 2, i.e., index of 3)

### Count of x:

\[
\text{upperBound} - \text{lowerBound} = 4 - 1 = 3
\]

This is EXACTLY how C++ STL works internally.

---

# 🎯 TIME & SPACE COMPLEXITY

| Operation     | Meaning      | Time     | Space |
| ------------- | ------------ | -------- | ----- |
| Lower Bound   | first ≥ x    | O(log n) | O(1)  |
| Upper Bound   | first > x    | O(log n) | O(1)  |

All are implemented using **Binary Search**.



---
---
---



# ✅ 1. Normal division method

```cpp
int mid = (low + high) / 2;
```

# ✅ 2. Bitwise right-shift method

```cpp
int mid = (low + high) >> 1;
```

---

# 🔥 Why are they the same?

Because:

\[
x >> 1 \quad \text{means} \quad \frac{x}{2}
\]

Bit shifting right by 1 bit divides the number by 2 (floor division).

Example:

```
8 >> 1 = 4
9 >> 1 = 4
10 >> 1 = 5
15 >> 1 = 7
```

So:

```
(low + high) >> 1 == (low + high) / 2
```

Both give exactly the SAME midpoint.

---

# ⚠️ But then why do people use “>> 1” ?

### Because bit operations are:

* slightly **faster** than division
* used historically in old competitive programming
* considered a small optimization

In modern compilers, BOTH produce identical machine code, so **there is no performance difference today**.

---

# ⚠️ One important caution

Using `(low + high) / 2` can overflow in some languages when integers are large.

So the **best safe way** (which you’ll see in interviews) is:

```cpp
int mid = low + (high - low) / 2;
```

This avoids overflow because `high - low` can never exceed array size.

---

# ⭐ Conclusion

| Version                  | Same? | Safe?           | Recommended?    |
| ------------------------ | ----- | --------------- | --------------- |
| `(low + high) / 2`       | ✔ Yes | ❌ overflow risk | Not recommended |
| `(low + high) >> 1`      | ✔ Yes | ❌ overflow risk | Not recommended |
| `low + (high - low) / 2` | ✔ Yes | ✔ Safe          | ⭐ Best practice |


---
---
---

No problem.
I will explain it **from absolute zero** without talking about overflow formulas.

Let’s go slowly and clearly.

---

# ❓ **THE REAL QUESTION**

Why can’t we just write this?

```cpp
int mid = (low + high) / 2;
```

What PROBLEM does this cause?

---

# 🚨 **THE ACTUAL PROBLEM: INTEGER OVERFLOW**

This formula can **break your binary search**, even if your logic is 100% correct.

Let me show with a real example.

---

# 📌 EXAMPLE THAT BREAKS BINARY SEARCH

Imagine:

```
low  = 2,000,000,000
high = 2,000,000,010
```

(You are searching in a VERY large array.)

Both values **fit safely in int**.

### Now compute mid using old formula:

```
(low + high)
= 2,000,000,000 + 2,000,000,010
= 4,000,000,010   ❌
```

But a 32-bit int can only store up to:

```
2,147,483,647
```

So the value **overflows**, becomes negative, becomes garbage.

Your mid becomes some random weird number like:

```
mid = -294748364 ? (something wrong)
```

Binary search jumps to negative indexes → program crashes or infinite loops.

---

# ❗ WHY DID OVERFLOW HAPPEN?

Because you added two HUGE numbers.

Even though:

* low is valid
* high is valid

Their sum exceeded the int limit.

---

# ⭐ OKAY, SO WHAT’S THE SOLUTION?

Avoid adding big numbers.

So instead of:

```
(low + high)
```

We compute it like this:

```cpp
(low + (high - low) / 2)
```

Here:

* `(high - low)` is always small
  (max = array size)
* dividing by 2 makes it even smaller
* adding that small number to `low` is safe

So **this cannot overflow.**

---

# 🤯 SUPER SIMPLE VISUAL WAY TO GET IT

Say you want the midpoint between two values on a number line:

```
low --------------------------- high
```

Distance between them =

```
(high - low)
```

Half of that distance =

```
(high - low)/2
```

So midpoint =

```
start at low + half the distance
```

= `low + (high - low)/2`

---

# ✔️ Both formulas give SAME midpoint

But only one is SAFE.

---

# 🔥 Quick Summary (the whole thing in 2 lines)

❌ **Problem:**
`(low + high)/2` can **overflow** when low and high are huge.

✔️ **Fix:**
`low + (high - low)/2` never overflows.
