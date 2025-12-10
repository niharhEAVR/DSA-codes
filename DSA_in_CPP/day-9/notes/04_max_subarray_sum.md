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


# 🧠 **What is Kadane’s Algorithm?**

Kadane’s Algorithm is a very famous technique to find:

### **Maximum Subarray Sum**

(i.e., find the contiguous subarray with the maximum possible sum).

Example:
Array = `[5, -2, 3, -1, 2]`
Maximum subarray = `[5, -2, 3, -1, 2]`
Maximum sum = `7`.

Kadane finds this **in O(n)** — linear time — using just **one loop**.

---

# 🏛️ **History & Background**

* Kadane’s Algorithm was introduced by **Joseph B. Kadane** in **1984**.
* It was part of research on **dynamic programming and optimization**.
* Before Kadane, the best known solutions were:

  * **Brute force = O(n³)**
  * **Better = O(n²)** using cumulative sums
* Kadane reduced it to **O(n)**, which was groundbreaking.

It became extremely popular because:

✔ No extra space
✔ Only one loop
✔ Works for **any range of integers**
✔ Can be extended to **2D**, **circular arrays**, **DP problems**

Today, it is considered one of the most important algorithms in computer science.

---

# 🌍 **Where is Kadane Used Today?**

Kadane is used in many real-world systems:

### **1. Stock Market Analysis**

Finding:

* maximum profit window
* best period of gain
* longest upward trend

### **2. Sensor Data & Analytics**

Example:
Detecting the period with maximum increase in temperature, pressure, traffic values, etc.

### **3. Machine Learning / AI**

Feature extraction from signals:

* ECG/EEG wave analysis
* audio signal enhancement
* peak detection

### **4. Gaming / Graphics**

* energy/stamina regeneration patterns
* analyzing continuous streaks
* optimizing segments

### **5. Financial Algorithms**

* detecting best profit interval
* computing rolling sums

### **6. Coding Interviews**

It’s a **must-know** algorithm for companies like
**Google, Amazon, Meta, Netflix, Microsoft**.

---

# ⚙️ **What is the Core Idea of Kadane? (Intuition)**

Kadane maintains two things:

### 1️⃣ `currSum` → current running subarray sum

### 2️⃣ `maxSum` → best answer so far

The logic:

* **Add the current element** to the running sum.
* **If the running sum becomes negative**, then drop it (reset to 0).
  Because a negative sum will only reduce future totals.

This is like:

> “If your score becomes negative, start fresh.”

---

# 📝 **Kadane’s Algorithm (Simple Form)**

```cpp
int maxSubArray(vector<int>& nums) {
    int currSum = 0;
    int maxSum = INT_MIN;

    for (int x : nums) {
        currSum += x;
        maxSum = max(maxSum, currSum);
        if (currSum < 0) currSum = 0;
    }
    return maxSum;
}
```

---

# 🔍 **Example + Dry Run**

### **Array:**

`[4, -1, 2, -7, 5, 3]`

We track two values:

* `currSum`
* `maxSum`

---

## **Step-by-step Dry Run**

### Element = 4

`currSum = 4`
`maxSum = 4`

### Element = -1

`currSum = 3`
`maxSum = 4`

### Element = 2

`currSum = 5`
`maxSum = 5`

### Element = -7

`currSum = -2` (negative → RESET to 0)
`maxSum = 5`

### Element = 5

`currSum = 5`
`maxSum = 5`

### Element = 3

`currSum = 8`
`maxSum = 8`

---

### ✔️ **Final Maximum Subarray Sum = 8**

Subarray = `[5, 3]`

---

# ⭐ Special Case: All Numbers Are Negative

Example: `[-5, -2, -3]`

Normal Kadane resets to 0 — wrong here.

So we modify Kadane:

```cpp
int maxSubArray(vector<int>& nums) {
    int currSum = nums[0];
    int maxSum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        currSum = max(nums[i], currSum + nums[i]);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}
```

This ensures correct behavior for negative-only arrays.

---

# 🎯 Summary (Easy to Remember)

| Concept                | Meaning                                       |
| ---------------------- | --------------------------------------------- |
| **Kadane's Algorithm** | Find max sum of any contiguous subarray       |
| **Time Complexity**    | O(n)                                          |
| **Space Complexity**   | O(1)                                          |
| **Core Idea**          | Drop negative sum, keep maximum               |
| **Uses**               | Stock analysis, signals, ML, finance, sensors |
| **History**            | Made in 1984 by Joseph Kadane                 |
