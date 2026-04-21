## 💭 The Question:

**"Find the length of the Longest Subarray with sum K"**

---

### 🧩 1. What is a *subarray*?

A **subarray** is a **continuous part of the array** — meaning you can only take elements that are next to each other, without skipping.

Example:
For

```
arr = [1, 2, 3, 4]
```

✅ These are valid subarrays:

```
[1], [2,3], [1,2,3], [3,4]
```

❌ These are NOT subarrays:

```
[1,3], [2,4]
```

(because they skip elements)

---

### 🎯 2. What the question *wants* from you

It wants you to find **the longest continuous portion of the array** (subarray) such that
➡️ the **sum of all numbers inside it = K**

And then return the **length** (how many elements) of that subarray.

---

### 💡 Example

Let’s say:

```
arr = [1, 2, 3, 1, 1, 1, 1, 4, 2, 3]
K = 3
```

We need to find **all subarrays whose sum = 3**, then choose the **longest** one.

---

### 🔍 Step-by-step check:

| Subarray                 | Sum | Length | Valid? |
| ------------------------ | --- | ------ | ------ |
| [1, 2]                   | 3   | 2      | ✅      |
| [3]                      | 3   | 1      | ✅      |
| [1, 1, 1]                | 3   | 3      | ✅      |
| [1, 1, 1, 1, -something] | >3  | ❌      |        |
| [4, 2, 3]                | 9   | ❌      |        |

So we found three valid subarrays where the **sum = 3**:

* [1, 2] → length 2
* [3] → length 1
* [1, 1, 1] → length 3

Among these, the **longest** one is `[1, 1, 1]`
👉 Length = **3**

✅ **Final Answer: 3**

---

### 🧠 3. In simple English

The question is basically saying:

> "In this array, find the **biggest continuous group of elements** whose **total adds up exactly to K**.
> And tell me how many elements are in that group."

---

### 📘 4. Important things to remember

| Concept      | Meaning                                             |
| ------------ | --------------------------------------------------- |
| **Subarray** | Continuous (no skipping)                            |
| **Sum = K**  | Add up all numbers inside subarray = K              |
| **Longest**  | Maximum number of elements among all such subarrays |
| **Output**   | Just the **length**, not the actual subarray        |

---

### 🧾 Example summary

| Input                              | Output | Explanation                              |
| ---------------------------------- | ------ | ---------------------------------------- |
| arr = [1,2,3,1,1,1,1,4,2,3], K = 3 | 3      | `[1,1,1]` has sum = 3 and is the longest |

---
---
---



<br>
<br>
<br>
<br>

## 💪 Brute Force Approach

### 🎯 Goal reminder:

We need to find the **longest continuous subarray** whose **sum = K**.

---

### 🧠 Basic idea:

We will:

1. Check **every possible subarray** in the array.
2. For each subarray, calculate its **sum**.
3. If the sum equals **K**, update the **maximum length** seen so far.

It’s like testing all possibilities manually — that’s why it’s called *brute force*.

---

### 🧩 Example

Let’s use:

```
arr = [1, 2, 3, 1, 1, 1, 1, 4, 2, 3]
K = 3
```

We will:

* Start from index `i = 0`

  * Take `j = 0` to end of array
  * Calculate `sum` of `arr[i...j]`
  * If `sum == K`, record `(j - i + 1)` as a possible length
  * Continue checking all combinations

---

### 🔹 Step-by-Step Visual Example:

| i | j | Subarray | Sum | Equals K? | Max Length        |
| - | - | -------- | --- | --------- | ----------------- |
| 0 | 0 | [1]      | 1   | ❌         | 0                 |
| 0 | 1 | [1,2]    | 3   | ✅         | 2                 |
| 0 | 2 | [1,2,3]  | 6   | ❌         | 2                 |
| 1 | 1 | [2]      | 2   | ❌         | 2                 |
| 1 | 2 | [2,3]    | 5   | ❌         | 2                 |
| 2 | 2 | [3]      | 3   | ✅         | 2                 |
| 3 | 5 | [1,1,1]  | 3   | ✅         | 3 ← (new longest) |

So final `maxLen = 3`.

---

### 🧾 Algorithm (Step-by-Step)

1. Initialize `maxLen = 0`.
2. Run a loop `i` from `0` to `n-1` (start of subarray).
3. Inside that, run another loop `j` from `i` to `n-1` (end of subarray).
4. Maintain a running sum:

   ```
   sum += arr[j];
   ```
5. If `sum == K`, then:

   ```
   maxLen = max(maxLen, j - i + 1);
   ```
6. After both loops, print or return `maxLen`.

---

### 💻 C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int longestSubarrayBrute(vector<int> &arr, int K) {
    int n = arr.size();
    int maxLen = 0;

    // Outer loop -> starting point
    for (int i = 0; i < n; i++) {
        int sum = 0;
        // Inner loop -> ending point
        for (int j = i; j < n; j++) {
            sum += arr[j];

            if (sum == K) {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }

    return maxLen;
}

int main() {
    vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    int K = 3;
    cout << longestSubarrayBrute(arr, K);
}
```

---

### 📊 Dry Run (Short)

```
arr = [1, 2, 3, 1, 1, 1, 1, 4, 2, 3]
K = 3
```

When you run it:

* It will find `[1,2]`, `[3]`, `[1,1,1]`, `[3]`
* Longest among them = `[1,1,1]`
  ✅ Output → `3`

---

### ⏱ Time Complexity:

O(n²)
(because we check every possible subarray — two nested loops)

### 💾 Space Complexity:

O(1)
(no extra space except variables)

---

### ⚠️ Note:

This method **always works** (for negative, zero, positive numbers),
but it’s **slow** for large arrays (n > 10⁴) because of O(n²) time.

---

<br>
<br>
<br>
<br>






## Optimal Approach

# 🧠 Problem Recap

> Find the **length of the longest subarray** whose **sum = K**.

---

## ⚙️ Code You Wrote (Sliding Window / Two Pointer)

```cpp
int longestSubarray(vector<int> &arr, int k)
{
    int left{}, right{}, maxLen{};
    long long sum = arr[0];
    int n = arr.size();

    while (right < n)
    {
        // shrink from left if sum > k
        while (left <= right && sum > k)
        {
            sum -= arr[left];
            left++;
        }

        // if sum == k → update answer
        if (sum == k)
            maxLen = std::max(maxLen, right - left + 1);

        // expand the window to include next element
        right++;
        if (right < n)
            sum += arr[right];
    }

    return maxLen;
}
```

---

# 🧩 INTUITION – Sliding Window Idea

This approach uses a **window** between two pointers `left` and `right`.
You **expand** the window by moving `right`, and **shrink** it from the `left` when the sum becomes too large.

This logic **only works when all array elements are non-negative**.

---

### ✅ Step-by-Step Example (Works Perfectly)

Let’s dry run this for:

```
arr = [1, 2, 3, 1, 1, 1, 1, 4, 2, 3], k = 3
```

| Step | left | right | sum | Action                                               | maxLen  |
| ---- | ---- | ----- | --- | ---------------------------------------------------- | ------- |
| Init | 0    | 0     | 1   | start                                                | 0       |
| →    | 0    | 1     | 3   | ✅ sum==k → len=2                                     | 2       |
| →    | 0    | 2     | 6   | sum>k → shrink left (sum=5) → shrink again (sum=3) ✅ | len=1→3 |
| →    | 1    | 3     | 4   | sum>k → shrink (sum=2)                               |         |
| →    | 2    | 4     | 3 ✅ | update len=3                                         | 3       |
| ...  | ...  | ...   | ... | continues                                            | 3       |

✅ Final Answer: **3**

---

# ❌ When It Fails (Negative Numbers Present)

### Example

```
arr = [1, 2, -1, 2, -1, 3], k = 3
```

| Step | left | right | sum | Comment                                                |
| ---- | ---- | ----- | --- | ------------------------------------------------------ |
| Init | 0    | 0     | 1   | ok                                                     |
| →    | 0    | 1     | 3 ✅ | ok (len=2)                                             |
| →    | 0    | 2     | 2   | ok                                                     |
| →    | 0    | 3     | 4   | shrink (sum=3 ✅ len=3)                                 |
| →    | 0    | 4     | 2   | ok                                                     |
| →    | 0    | 5     | 5   | shrink (sum=4) → shrink (sum=2) ❌ skipped valid window |

💥 Here, after adding a negative number, the sum decreases —
so the condition `while(sum > k)` no longer works predictably.

That’s why this approach breaks.

---

# 🔍 WHY THIS APPROACH FAILS FOR NEGATIVES

The **core assumption** behind this approach is:

> “If I increase the window (move `right`), the sum will either increase or stay same.”

This is only true when all elements ≥ 0.

If negative numbers exist — sum can **decrease unexpectedly**, so the logic of shrinking the window when sum > k no longer holds true.

---

# ⚡ COMPLEXITY ANALYSIS

| Complexity Type           | Explanation                                                           | Value    |
| ------------------------- | --------------------------------------------------------------------- | -------- |
| **Time Complexity (TC)**  | Each element visited at most twice (once by `right`, once by `left`). | **O(n)** |
| **Space Complexity (SC)** | Only uses a few variables (`sum`, `left`, `right`, etc.)              | **O(1)** |



### 🔹 Why it **looks** like O(N²)

Because:

* There is a **`while (right < n)`** loop (outer loop).
* Inside it, another **`while (left <= right && sum > k)`** loop (inner loop).
  So, visually it seems like a nested loop ⇒ **O(N²)**.

### 🔹 Why it’s actually **O(2N)** ⇒ **O(N)**

The key idea is this:

> Both `left` and `right` pointers **only move forward**, never backward.

Let's reason step-by-step 👇

#### 1️⃣ Outer loop (`right`)

* The variable `right` starts from 0 and increments until it reaches `n-1`.
* Hence, it moves **n times** in total.

#### 2️⃣ Inner loop (`left`)

* The `while (sum > k)` loop moves `left` forward.
* But `left` can **never exceed n**, and once it moves forward, it **never moves back**.

So across the entire execution:

* `right` increments **at most n times**
* `left` increments **at most n times**

Hence, **total pointer movements = n + n = 2n**,
which is **O(2n) = O(n)** time complexity.

### 🔹 Intuitive explanation

Think of the window `[left, right]` sliding across the array:

* `right` expands the window (one step at a time),
* `left` shrinks it when needed.

Even though the inner `while` exists, it doesn’t run **for every iteration** of the outer loop; it just continues moving `left` forward **across the array once** in total.

### 🔹 Example Trace

Suppose `arr = [1,2,3,4,5]`, `k = 5`.

| Step | left | right | sum | Action                   |
| ---- | ---- | ----- | --- | ------------------------ |
| 1    | 0    | 0     | 1   | expand                   |
| 2    | 0    | 1     | 3   | expand                   |
| 3    | 0    | 2     | 6   | sum>k → shrink left to 1 |
| 4    | 1    | 2     | 5   | sum==k → update maxLen   |
| 5    | 1    | 3     | 9   | shrink left twice        |
| 6    | 3    | 4     | 9   | shrink left again        |

→ both `left` and `right` just move forward; they never re-scan old elements.

### ✅ Final Conclusion

Even though it looks like two loops, the **total number of iterations** is linear because both pointers move at most `n` times.

Hence,
**Time Complexity:** `O(n)` (or more precisely `O(2n)` = `O(n)`)
**Space Complexity:** `O(1)`

---
---
---

# 🧾 Summary

| Case                           | Works for Negatives? | Technique  | TC   | SC   | Notes                            |
| ------------------------------ | -------------------- | ---------- | ---- | ---- | -------------------------------- |
| **Sliding Window (this code)** | ❌ No                 | 2-pointer  | O(n) | O(1) | Only for positive / zero numbers |
| **Prefix Sum + Hashmap**       | ✅ Yes                | Prefix sum | O(n) | O(n) | Works for any integers           |

---

### ✅ Final Takeaway:

Use this **two-pointer sliding window** when:

* All elements are non-negative (like 0, 1, 2, 3, …)
* You want O(n) time and O(1) space

Use the **hashmap prefix-sum** when:

* Array has negative values
* You want to handle all cases safely

---



<br>
<br>
<br>

## Better Approach only for Positive numbers and Optimal approach for Positive + Negative numbers



# 🧠 Problem Recap

We need to find the **length** of the longest continuous subarray whose **sum = K**.

Example:

```cpp
arr = {1, 2, -1, 2, -1, 3}, K = 3
```

✅ The longest subarray is `[1, 2, -1, 2, -1]` → sum = 3 → length = 5

---

# ⚙️ Full Code Explanation

```cpp
int longSubArrBetter(vector<int> &arr, int K) {
    unordered_map<int, int> mp;  // stores prefixSum -> first index
    int sum = 0;                 // running prefix sum
    int maxLen = 0;              // stores answer
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        sum += arr[i];           // update running prefix sum

        // Case 1: if sum itself == K → whole subarray from 0..i
        if (sum == K)
            maxLen = max(maxLen, i + 1);

        // Case 2: check if (sum - K) exists → subarray between indices
        if (mp.find(sum - K) != mp.end()) {
            int len = i - mp[sum - K];
            maxLen = max(maxLen, len);
        }

        // Case 3: store current prefix sum if first time seen
        if (mp.find(sum) == mp.end())
            mp[sum] = i;
    }

    return maxLen;
}
```

---

# 🔍 Step-by-Step Dry Run

Let’s dry-run for:
`arr = {1, 2, -1, 2, -1, 3}, K = 3`

| i | arr[i] | sum | Case 1 (`sum==K`) | sum−K | Found in mp?            | len = i−mp[sum−K] | maxLen | mp (prefixSum → index) |
| - | ------ | --- | ----------------- | ----- | ----------------------- | ----------------- | ------ | ---------------------- |
| 0 | 1      | 1   | ❌                 | -2    | ❌                       | -                 | 0      | {1:0}                  |
| 1 | 2      | 3   | ✅ Yes → len=2     | 0     | ❌                       | -                 | **2**  | {1:0, 3:1}             |
| 2 | -1     | 2   | ❌                 | -1    | ❌                       | -                 | 2      | {1:0, 3:1, 2:2}        |
| 3 | 2      | 4   | ❌                 | 1     | ✅ Yes (mp[1]=0) → len=3 | 3                 | **3**  | {1:0,3:1,2:2,4:3}      |
| 4 | -1     | 3   | ✅ Yes → len=5     | 0     | ❌                       | -                 | **5**  | {1:0,3:1,2:2,4:3}      |
| 5 | 3      | 6   | ❌                 | 3     | ✅ Yes (mp[3]=1) → len=4 | 5                 | **5**  | {1:0,3:1,2:2,4:3,6:5}  |

✅ Final answer = `maxLen = 5`

---

# 🧩 Why This Works

We use **prefix sum** and **hash map** to track where each prefix sum was first seen.

* If `sum == K`, that means subarray `[0..i]` has sum `K`.
* If `(sum - K)` exists in map, then there was an earlier prefix sum such that:

  ```
  current_sum - previous_sum = K
  ⇒ subarray between (previous_index+1 .. i) has sum K
  ```

By storing **only the first occurrence** of each sum, we ensure we get the **longest possible** subarray.

---

# ⚡ Time and Space Complexity

| Type                 | Complexity | Why                                                                          |
| -------------------- | ---------- | ---------------------------------------------------------------------------- |
| **Time Complexity**  | **O(n)**   | We traverse array once; each hashmap operation (find/insert) is O(1) average |
| **Space Complexity** | **O(n)**   | In the worst case, we store every prefix sum once in the unordered_map       |

---

# 🧮 Example Visual (Intuition Diagram)

Imagine this array as a running total (prefix sums):

```
Index:     0   1   2   3   4   5
Element:   1   2  -1   2  -1   3
PrefixSum: 1   3   2   4   3   6
```

We are checking:

```
Does there exist a previous prefixSum = currentSum - K?
```

So when sum=4 and K=3 → need prefixSum = 1 → found at index 0
→ Subarray from index 1..3 has sum = 3 ✅

---

# 🏁 Final Summary

| Concept                   | Meaning                                              |
| ------------------------- | ---------------------------------------------------- |
| Approach                  | Prefix Sum + Hash Map                                |
| Handles Negative Numbers? | ✅ Yes                                                |
| Time Complexity           | **O(n)**                                             |
| Space Complexity          | **O(n)**                                             |
| Logic                     | If `(sum - K)` exists, subarray in between sums to K |
| Works For                 | Positive, Negative, Zero numbers                     |
