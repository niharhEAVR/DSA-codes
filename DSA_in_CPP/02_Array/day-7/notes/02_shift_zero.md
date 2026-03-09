## 🔹 Your Current Code (Two-Pointer – "Better Approach")

### Function:

```cpp
void rotate(std::vector<int> &nums)
{
    if (nums.size() <= 1)
        return;

    int j{-1};
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            j = i;
            break;
        }
    }
    if (j == -1)
        return;
    for (size_t i = j + 1; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            std::swap(nums[i], nums[j]);
            j++;
        }
    }
}
```

---

### 🧠 What It Does

* First loop: Finds the **first zero index** (`j`).
* Second loop: Whenever it sees a non-zero **after** that, it swaps with the `j`th zero and increments `j`.

✅ Works perfectly for examples like:
`[0,1,0,3,12] → [1,3,12,0,0]`
`[0] → [0]`

---

## 🔹 Time Complexity (TC)

1. **First loop**: finds first zero → worst case runs `n` times.
2. **Second loop**: iterates from that position to the end → again at most `n`.

[
O(n) + O(n) = O(n)
]

✅ **Time Complexity = O(n)**
(every element is visited at most twice)

---

## 🔹 Space Complexity (SC)

You only use a few integer variables (`i`, `j`).

✅ **Space Complexity = O(1)**
(no extra data structure used)

---

### ✅ Final Complexity Summary

| Complexity Type      | Big-O    | Explanation                  |
| -------------------- | -------- | ---------------------------- |
| **Time Complexity**  | **O(n)** | Linear scan of the array     |
| **Space Complexity** | **O(1)** | Only a few integer variables |

---

## 🔹 Even Cleaner / Standard Optimal Solution (Recommended for LeetCode)

Here’s the **simplest and most efficient** version widely used:

```cpp
void moveZeroes(std::vector<int> &nums)
{
    int j = 0;  // pointer for placing next non-zero

    // Move all non-zero elements forward
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            std::swap(nums[i], nums[j]);
            j++;
        }
    }
}
```

---

### ✅ How it works

* `j` keeps track of the **next index where a non-zero should go**.
* For every non-zero `nums[i]`, swap it with `nums[j]` and increment `j`.
* Zeros automatically end up at the end.

---

### Example walkthrough

Input: `[0,1,0,3,12]`

| i | nums[i] | j | action     | nums         |
| - | ------- | - | ---------- | ------------ |
| 0 | 0       | 0 | skip       | [0,1,0,3,12] |
| 1 | 1       | 0 | swap → j++ | [1,0,0,3,12] |
| 2 | 0       | 1 | skip       | [1,0,0,3,12] |
| 3 | 3       | 1 | swap → j++ | [1,3,0,0,12] |
| 4 | 12      | 2 | swap → j++ | [1,3,12,0,0] |

✅ Output: `[1,3,12,0,0]`

---

### ✅ Complexity of this version

| Type      | Complexity | Why               |
| --------- | ---------- | ----------------- |
| **Time**  | O(n)       | One single pass   |
| **Space** | O(1)       | In-place swapping |

---

### 🧾 Summary

| Version         | Time Complexity | Space Complexity | Comment                        |
| --------------- | --------------- | ---------------- | ------------------------------ |
| Your code       | O(n)            | O(1)             | Works fine, two loops          |
| Cleaner version | O(n)            | O(1)             | Standard, shorter, single loop |
