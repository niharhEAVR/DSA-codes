## 🧩 Problem Understanding

You are given an integer array (it can have positive and negative numbers).

👉 You have to find the **contiguous subarray (continuous elements)** that gives the **maximum possible sum**.
Then, return that sum.

---

### 🧠 Example 1

```
nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
```

We have to find which *continuous part* of this array gives the **largest sum**.

Let’s look at all possible subarrays (just for understanding):

| Subarray      | Sum               |
| ------------- | ----------------- |
| [-2]          | -2                |
| [1]           | 1                 |
| [1, -3]       | -2                |
| [4, -1, 2, 1] | **6** ✅ (largest) |
| [-5, 4]       | -1                |

So, the **maximum subarray sum = 6**,
from the subarray `[4, -1, 2, 1]`.

---

## 🧮 What’s Happening Conceptually

You’re walking through the array and building a subarray as long as it’s beneficial.

If adding the current number **increases the sum**, keep it.
If adding the current number **drops the sum below 0**, start a new subarray from that point.

---

## ⚙️ Kadane’s Algorithm (Optimal — O(n) Time)

We use two variables:

* `maxSum` → keeps track of the maximum sum found so far.
* `currSum` → keeps track of the current subarray sum.

### Steps

1. Start with:

   ```cpp
   int maxSum = nums[0];
   int currSum = 0;
   ```

2. For each element `x` in `nums`:

   * Add it to `currSum`.
   * If `currSum` becomes greater than `maxSum`, update `maxSum`.
   * If `currSum` becomes **negative**, reset `currSum = 0` (because a negative sum will only reduce future sums).

---

### 🔢 Dry Run Example

```
nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
```

| i | nums[i] | currSum (before reset)    | maxSum      |
| - | ------- | ------------------------- | ----------- |
| 0 | -2      | currSum = -2 → reset to 0 | maxSum = -2 |
| 1 | 1       | currSum = 1               | maxSum = 1  |
| 2 | -3      | currSum = -2 → reset to 0 | maxSum = 1  |
| 3 | 4       | currSum = 4               | maxSum = 4  |
| 4 | -1      | currSum = 3               | maxSum = 4  |
| 5 | 2       | currSum = 5               | maxSum = 5  |
| 6 | 1       | currSum = 6               | maxSum = 6  |
| 7 | -5      | currSum = 1               | maxSum = 6  |
| 8 | 4       | currSum = 5               | maxSum = 6  |

✅ **Result: 6**

---

## 🧩 C++ Code

```cpp
int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0];
    int currSum = 0;

    for (int x : nums) {
        currSum += x;
        if (currSum > maxSum) maxSum = currSum;
        if (currSum < 0) currSum = 0;
    }
    return maxSum;
}
```

---

## ✅ Time & Space Complexity

* **Time:** O(n) (only one pass)
* **Space:** O(1)



---
---
---

<br>
<br>


## 🧑‍🔬 The Origin

**Kadane’s Algorithm** is named after **Joseph Bernard Kadane**,
an American computer scientist and statistician.

He introduced this algorithm in **1984**, in a short but influential note called:

> “Algorithm 210: An O(n) Algorithm for Finding the Maximum Subarray Sum”
> *(Published in Communications of the ACM, Vol. 27, Issue 5, 1984)*

That’s where the name **Kadane’s Algorithm** comes from —
because *Joseph Kadane* was the one who published it.

---

## 🧩 The Backstory (Fun & Interesting)

Before Kadane’s paper, computer scientists already knew the **Maximum Subarray Sum problem**,
but the solutions were **O(n²)** or **O(n³)** time complexity (by checking all subarrays).

Kadane showed that the problem could be solved in **O(n)** — linear time —
using a single pass with a clever logic of maintaining a running sum and resetting when it turns negative.

That was a big deal in 1984! 🚀
So the community started calling it **“Kadane’s Algorithm”** in his honor.

---

## 🧠 Bonus Fact: It’s Related to Another Famous Result

Later, researchers discovered that this algorithm is actually a **special case** of a general technique used in **dynamic programming**.

It’s basically doing:

```cpp
maxEndingHere = max(nums[i], maxEndingHere + nums[i]);
maxSoFar = max(maxSoFar, maxEndingHere);
```

So Kadane’s Algorithm is essentially **Dynamic Programming** simplified to an elegant one-pass form.

---

### 🔹 Summary

| Question                       | Answer                                                 |
| ------------------------------ | ------------------------------------------------------ |
| **Who invented it?**           | Joseph Bernard Kadane                                  |
| **When?**                      | 1984                                                   |
| **Where published?**           | Communications of the ACM                              |
| **Why is it named after him?** | He proposed the O(n) method for Maximum Subarray Sum   |
| **What’s special about it?**   | It reduces an O(n²) problem to O(n) using simple logic |