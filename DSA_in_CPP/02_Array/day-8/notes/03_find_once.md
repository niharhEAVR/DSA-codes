## 🧩 Problem

> Given a non-empty array of integers `nums`, every element appears **twice** except for one.
> Find that **single** one.

### Example

```
Input: nums = [4,1,2,1,2]
Output: 4
```

---

## ❌ Brute Force (Not optimal)

### Logic:

* Count frequency of each number using a map.
* Return the one with frequency `1`.

### Code:

```cpp
int singleNumber(std::vector<int> &nums) {
    std::unordered_map<int, int> freq;
    for (int n : nums) freq[n]++;
    for (auto &p : freq) {
        if (p.second == 1) return p.first;
    }
    return -1;
}
```

### Time Complexity → **O(n)**

### Space Complexity → **O(n)**

(because of the hash map)

✅ Works fine, but **uses extra space**.

---

## ⚡ Optimal Solution (Using XOR Trick)

### Concept:

We use a **beautiful property of XOR (^)**:

| Operation   | Result                     |
| ----------- | -------------------------- |
| `a ^ a`     | `0`                        |
| `a ^ 0`     | `a`                        |
| `a ^ b ^ a` | `b` (order doesn’t matter) |

### Explanation:

If we XOR all numbers in the array:

* All numbers appearing **twice** will **cancel out** (because `x ^ x = 0`).
* The number appearing **once** will remain (because `x ^ 0 = x`).

So, the final XOR result = **the single number**.

---

### 🔍 Step-by-Step Example

Let’s take

```
nums = [4, 1, 2, 1, 2]
```

| Step  | Current num | XOR so far | Binary Operation   |
| ----- | ----------- | ---------- | ------------------ |
| Start | —           | 0          | —                  |
| 1     | 4           | 0 ^ 4 = 4  | 0000 ^ 0100 = 0100 |
| 2     | 1           | 4 ^ 1 = 5  | 0100 ^ 0001 = 0101 |
| 3     | 2           | 5 ^ 2 = 7  | 0101 ^ 0010 = 0111 |
| 4     | 1           | 7 ^ 1 = 6  | 0111 ^ 0001 = 0110 |
| 5     | 2           | 6 ^ 2 = 4  | 0110 ^ 0010 = 0100 |

✅ Final answer = **4**

---

### 🧠 Code:

```cpp
#include <bits/stdc++.h>
int singleNumber(std::vector<int> &nums) {
    int ans = 0;
    for (int n : nums) {
        ans ^= n;  // XOR each number
    }
    return ans;
}

int main() {
    std::vector<int> nums = {4, 1, 2, 1, 2};
    std::cout << singleNumber(nums);
    return 0;
}
```

---

### ⚙️ Time and Space Complexity

| Metric    | Complexity | Explanation                    |
| --------- | ---------- | ------------------------------ |
| **Time**  | O(n)       | Single pass through the array  |
| **Space** | O(1)       | Only one variable (`ans`) used |

---

### ✅ Advantages of XOR Approach:

* No extra memory
* Constant space
* Simple one-liner logic
* Very efficient — perfect for large arrays

---

### 🧾 Summary

| Approach      | Time | Space | Comment               |
| ------------- | ---- | ----- | --------------------- |
| Hash Map      | O(n) | O(n)  | Easy but extra memory |
| XOR (Optimal) | O(n) | O(1)  | Fastest and cleanest  |
