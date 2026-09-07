Yes! This one is **very important in DSA**, especially for array/string problems. The name sounds complicated, but the idea is actually pretty simple.

# 🪟 What is Sliding Window?

**Sliding Window = keeping a continuous part of an array/string and moving that part forward.**

Imagine this array:

```text
[2, 4, 1, 7, 3, 6, 5]
```

Suppose we want the **sum of every 3 consecutive elements**.

Our window size = `3`.

```text
[2, 4, 1]  7  3  6  5
 ↑──────↑
  window
```

Calculate:

```text
2 + 4 + 1 = 7
```

Now **slide the window one step right**:

```text
  2  [4, 1, 7]  3  6  5
      ↑──────↑
```

Sum:

```text
4 + 1 + 7 = 12
```

Slide again:

```text
  2  4  [1, 7, 3]  6  5
         ↑───────↑
```

Sum:

```text
1 + 7 + 3 = 11
```

And so on.

---

# 🚨 Why do we need Sliding Window?

Without sliding window, you might calculate every window from scratch.

For:

```text
[2, 4, 1, 7, 3, 6, 5]
```

First window:

```text
2 + 4 + 1
```

Second:

```text
4 + 1 + 7
```

Notice something?

The second window already contains:

```text
4 + 1
```

from the previous calculation!

So instead of calculating everything again:

```text
Old sum = 2 + 4 + 1 = 7

Remove 2
Add 7

New sum = 7 - 2 + 7 = 12
```

🔥 **That's the main idea of sliding window.**

---

# 🧠 The visual idea

Think of a window moving across the array:

```text
Array:

2   4   1   7   3   6   5
└───────┘
 window


    2   4   1   7   3   6   5
    └───────┘
     window


        2   4   1   7   3   6   5
        └───────┘
         window
```

The window doesn't recreate itself.

It **slides**.

---

# 1️⃣ Fixed-Size Sliding Window

This is the easiest type.

Suppose:

> Find the maximum sum of `k = 3` consecutive elements.

Array:

```text
[2, 4, 1, 7, 3, 6, 5]
```

### Step 1

```text
[2, 4, 1] 7 3 6 5
```

sum = `7`

### Step 2

Remove `2`, add `7`:

```text
2 [4, 1, 7] 3 6 5
```

sum:

```text
7 - 2 + 7 = 12
```

### Step 3

Remove `4`, add `3`:

```text
2 4 [1, 7, 3] 6 5
```

sum:

```text
12 - 4 + 3 = 11
```

### Step 4

```text
2 4 1 [7, 3, 6] 5
```

sum:

```text
11 - 1 + 6 = 16
```

### Step 5

```text
2 4 1 7 [3, 6, 5]
```

sum:

```text
16 - 7 + 5 = 14
```

So:

```text
Maximum = 16
```

---

# 💻 C++ Implementation

```cpp
int maxSum(vector<int>& arr, int k)
{
    int windowSum = 0;

    // First window
    for (int i = 0; i < k; i++)
    {
        windowSum += arr[i];
    }

    int maxSum = windowSum;

    // Slide the window
    for (int i = k; i < arr.size(); i++)
    {
        windowSum += arr[i];       // add new element
        windowSum -= arr[i - k];   // remove old element

        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}
```

The important part is:

```cpp
windowSum += arr[i];
windowSum -= arr[i - k];
```

### Think of it like:

```text
ADD the guy entering the window
REMOVE the guy leaving the window
```

---

# 2️⃣ Variable-Size Sliding Window

This is where sliding window becomes **really powerful**.

Here the window size isn't fixed.

For example:

> Find the longest subarray whose sum is ≤ 10.

You use two pointers:

```text
left
 ↓
[2, 4, 1, 7, 3, 6]
 ↑
right
```

The window can **grow**:

```text
[2]
[2, 4]
[2, 4, 1]
[2, 4, 1, 7]
```

If the condition becomes invalid, you **shrink from the left**:

```text
[2, 4, 1, 7]  → sum too large

remove 2

[4, 1, 7]
```

So variable sliding window generally uses:

```cpp
int left = 0;

for (int right = 0; right < n; right++)
{
    // add arr[right]

    while (condition_is_bad)
    {
        // remove arr[left]
        left++;
    }

    // process current window
}
```

---

# 🎯 The BIG picture

There are basically **two major sliding-window patterns** you should learn:

### Fixed window

Window size is known:

```text
k = 3

[---]
   [---]
      [---]
```

Typical questions:

* Maximum sum of `k` elements
* Minimum sum of `k` elements
* Average of every `k` elements
* Maximum number of something in `k` consecutive elements

---

### Variable window

Window size changes:

```text
[-]
[---]
[-----]
  [---]
    [-----]
```

Usually:

```text
left  → moves when condition breaks
right → continuously expands
```

Typical questions:

* Longest subarray with condition X
* Smallest subarray with sum ≥ X
* Longest substring without repeating characters
* Longest substring containing at most K distinct characters

---

## 🧠 One sentence to remember

> **Sliding Window means maintaining a continuous range `[left...right]` and moving its boundaries instead of repeatedly processing the same elements.**

And the biggest advantage is usually reducing something like:

```text
O(n²) → O(n)
```

That's why sliding window is such a big deal in DSA.



---
---
---
---


Yep. Let's take the **most common variable sliding-window pattern** and code it in C++.

### Problem

> Find the **longest subarray whose sum is ≤ 10**.

Example:

```text
arr = [2, 1, 3, 2, 4, 1]
```

We use two pointers:

```text
left
 ↓
[2, 1, 3, 2, 4, 1]
             ↑
            right
```

### C++ code

```cpp
int longestSubarray(vector<int>& arr, int k)
{
    int left = 0;
    int sum = 0;
    int maxLen = 0;

    for (int right = 0; right < arr.size(); right++)
    {
        // Add the new element entering the window
        sum += arr[right];

        // If window becomes invalid, shrink it
        while (sum > k)
        {
            sum -= arr[left];
            left++;
        }

        // Current window is valid
        int len = right - left + 1;

        maxLen = max(maxLen, len);
    }

    return maxLen;
}
```

### 🔥 The 4 things to understand

```cpp
int left = 0;
```

`left` marks the **start of the window**.

```cpp
for (int right = 0; right < arr.size(); right++)
```

`right` keeps moving forward and **expands the window**.

```cpp
sum += arr[right];
```

The new element enters the window.

```cpp
while (sum > k)
{
    sum -= arr[left];
    left++;
}
```

If the window becomes **invalid**, keep removing elements from the left until it's valid again.

Then:

```cpp
int len = right - left + 1;
```

gives the current window size.

---

### Visualize the movement

For:

```text
[2, 1, 3, 2, 4, 1]
```

Initially:

```text
[2]
 ↑
L,R
sum = 2
```

Expand:

```text
[2, 1]
 ↑  ↑
 L  R

sum = 3
```

Expand:

```text
[2, 1, 3]
 ↑     ↑
 L     R

sum = 6
```

Expand:

```text
[2, 1, 3, 2]
 ↑       ↑
 L       R

sum = 8
```

Expand:

```text
[2, 1, 3, 2, 4]
 ↑           ↑
 L           R

sum = 12 ❌
```

Too large!

So shrink:

```text
2 [1, 3, 2, 4]
↑
remove 2

sum = 10 ✅
```

Now the valid window is:

```text
[1, 3, 2, 4]
 ↑         ↑
 L         R
```

Length:

```text
right - left + 1
= 4 - 1 + 1
= 4
```

So far:

```text
maxLen = 4
```

That's the **core variable sliding-window pattern**:

```text
RIGHT → expand
        ↓
   condition broken?
        ↓
LEFT → shrink
        ↓
   condition valid
        ↓
   calculate answer
```

**One important caveat:** this exact sum-based pattern assumes the array has **non-negative numbers**. With negative numbers, this simple sliding-window logic doesn't generally work.



---
---
---
---
---



Yep — **both fixed-size and variable-size sliding window are usually O(n) time and O(1) space.**

### 1. Fixed-Size Sliding Window

For example:

```cpp
for (int i = 0; i < k; i++)
    sum += arr[i];

for (int i = k; i < n; i++)
{
    sum += arr[i];
    sum -= arr[i - k];
}
```

**Time Complexity: `O(n)`**

Why?

* First loop → `O(k)`
* Second loop → `O(n-k)`
* Total → `O(k + n-k)` = **O(n)**

**Space Complexity: `O(1)`**

We only use variables like:

```text
sum
maxSum
i
```

No extra array.

---

### 2. Variable-Size Sliding Window

```cpp
int left = 0;
int sum = 0;

for (int right = 0; right < n; right++)
{
    sum += arr[right];

    while (sum > k)
    {
        sum -= arr[left];
        left++;
    }
}
```

**Time Complexity: `O(n)`**

This is the part that confuses people because there's a `for` loop **and** a `while` loop.

You might think:

```text
for → O(n)
while → O(n)
----------------
O(n²) ❌
```

But that's **not** what happens.

`left` only moves **forward**.

```text
left:  0 → 1 → 2 → 3 → ... → n
right: 0 → 1 → 2 → 3 → ... → n
```

So across the **entire algorithm**:

* `right` moves at most `n` times
* `left` moves at most `n` times

Therefore:

```text
O(n) + O(n)
= O(2n)
= O(n)
```

**Space Complexity: `O(1)`**

Again, we're only storing:

```text
left
right
sum
maxLen
```

No extra data structure.

---

### 🧠 Remember this

| Sliding Window    |     Time |    Space |
| ----------------- | -------: | -------: |
| **Fixed Size**    | **O(n)** | **O(1)** |
| **Variable Size** | **O(n)** | **O(1)** |

The **most important thing** to understand is the variable one:

> **Nested `while` inside `for` does NOT automatically mean O(n²).**

If both pointers only move forward and each moves at most `n` times, it's **O(n)**. 🔥
