## 🎯 Problem Summary

We have an array:

```
nums = [1, 2, 3, 4, 5, 6, 7]
k = 3
```

We must **rotate the array to the right** by 3 steps:

```
→ [5, 6, 7, 1, 2, 3, 4]
```

---

## ⚙️ Step 1: Understand What “Rotate Right by 1” Means

Let’s simulate one rotation manually:

```
Original: [1, 2, 3, 4, 5, 6, 7]
Right by 1 → [7, 1, 2, 3, 4, 5, 6]
```

So each element moves **one step to the right**, and the **last element wraps around** to the start.

---

## 🔁 Step 2: Now What Happens If You Do It 3 Times?

We can rotate 1 step 3 times:

| Step      | Array State             |
| --------- | ----------------------- |
| 0 (start) | [1, 2, 3, 4, 5, 6, 7]   |
| 1         | [7, 1, 2, 3, 4, 5, 6]   |
| 2         | [6, 7, 1, 2, 3, 4, 5]   |
| 3         | [5, 6, 7, 1, 2, 3, 4] ✅ |

That’s correct.
But — this takes **O(k × n)** time, because every rotation does **O(n)** work, and we repeat it `k` times.

So total = **O(n * k)** → **O(n²)** when `k ≈ n`.

---

## 🧩 Step 3: Let’s Visualize What’s Actually Happening

When rotating `k = 3` to the right, we’re really **moving the last 3 elements to the front**.

```
Original: [1, 2, 3, 4, 5, 6, 7]
                |_________|
                     ↑
                last k = 3 elements

Result: [5, 6, 7, 1, 2, 3, 4]
```

💡 You can see that we didn’t need to do 3 full shifts.
We could’ve **just split the array and rejoined** it in one go.

---

## 🧠 Step 4: Key Idea — “Reverse Technique” Visualization

Here’s a trick to do this in **O(n)**:

To rotate right by `k`, we can:

1. Reverse the **whole array**.
2. Reverse the **first k elements**.
3. Reverse the **remaining (n - k) elements**.

Let’s **see this visually**:

### Example:

`nums = [1, 2, 3, 4, 5, 6, 7]`, `k = 3`

**Step 1:** Reverse entire array

```
[7, 6, 5, 4, 3, 2, 1]
```

**Step 2:** Reverse first `k = 3` elements

```
[5, 6, 7, 4, 3, 2, 1]
```

**Step 3:** Reverse remaining `n - k = 4` elements

```
[5, 6, 7, 1, 2, 3, 4] ✅
```

Perfect rotation done **in-place** with **O(n)** time and **O(1)** space!

---

## ⏱️ Step 5: Compare Both Approaches

| Approach                    | Steps             | Time Complexity | Space | Notes                       |
| --------------------------- | ----------------- | --------------- | ----- | --------------------------- |
| **Nested loop** (your code) | Repeated shifting | O(n × k)        | O(1)  | Works, but slow if k is big |
| **Reverse method**          | 3 reversals       | O(n)            | O(1)  | Efficient and elegant       |

---

## 🧠 Step 6: Visual Intuition Summary

Think of rotation like **cutting and gluing** the array:

```
Original: [1, 2, 3, 4, 5, 6, 7]
Cut at n - k = 4 → [1, 2, 3, 4] | [5, 6, 7]
Glue: [5, 6, 7] + [1, 2, 3, 4]
```

The **reverse trick** is just a clever way to achieve that *without* using extra memory.


---
---
---


Let’s analyze the **Time Complexity (TC)** and **Space Complexity (SC)** clearly.

---

### 🔍 Code Summary

Your function:

```cpp
void rotate(std::vector<int> &nums, int k)
{
    int n = nums.size(), d = k % n;
    if (d <= 0) return;

    int temp[d]; // store last d elements

    // 1️⃣ Copy last d elements
    for (int i = 0; i < d; i++)
        temp[i] = nums[i + (n - d)];

    // 2️⃣ Shift first n-d elements to right by d
    for (int i = n - 1; i >= d; i--)
        nums[i] = nums[i - d];

    // 3️⃣ Copy back temp into front
    for (int i = 0; i < d; i++)
        nums[i] = temp[i];
}
```

---

### 🧮 Step-by-Step Complexity Analysis

#### Step 1: Copy last `d` elements

```cpp
for (int i = 0; i < d; i++)
    temp[i] = nums[i + (n - d)];
```

* Runs **d times**
* ⇒ Time = **O(d)**

#### Step 2: Shift elements

```cpp
for (int i = n - 1; i >= d; i--)
    nums[i] = nums[i - d];
```

* Runs approximately **(n - d)** times
* ⇒ Time = **O(n - d)**

#### Step 3: Copy back `temp`

```cpp
for (int i = 0; i < d; i++)
    nums[i] = temp[i];
```

* Runs **d times**
* ⇒ Time = **O(d)**

---

### ⏱️ Total Time Complexity (TC)

Combine all:

[
O(d) + O(n - d) + O(d) = O(n)
]

✅ **Time Complexity = O(n)**
(because every element is moved a constant number of times)

---

### 💾 Space Complexity (SC)

You are creating a **temporary array of size `d`**:

```cpp
int temp[d];
```

So:

* Extra memory = proportional to `d`
* In the worst case, `d` could be as large as `n - 1`

✅ **Space Complexity = O(d)**
and in worst case → **O(n)**

---

### ⚡ Final Answer

| Complexity Type      | Big-O                   | Explanation                         |
| -------------------- | ----------------------- | ----------------------------------- |
| **Time Complexity**  | **O(n)**                | Each element is moved at most once  |
| **Space Complexity** | **O(d)** (→ O(n) worst) | Temporary array for last d elements |
