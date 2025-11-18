## 🧩 Problem Statement

You are given an array `arr[]` of size `n`.

👉 An element is called a **leader** if **it is strictly greater than all the elements to its right**.

Return all the **leaders** in the array.

---

### Example 1:

```
Input: arr = [16, 17, 4, 3, 5, 2]
Output: [17, 5, 2]
```

✅ Explanation:

* 2 → last element → leader by default
* 5 > 2 → leader
* 3 < 5 → not leader
* 4 < 5 → not leader
* 17 > all to its right → leader
* 16 < 17 → not leader

Final leaders: [17, 5, 2]

---

## 🧠 Step 1: Understand the brute force approach

For each element, check if it’s greater than **all elements on its right side**.

### 🧮 Example

For `arr = [16, 17, 4, 3, 5, 2]`:

* For 16 → compare with [17,4,3,5,2] → fails
* For 17 → compare with [4,3,5,2] → passes
* For 4 → compare with [3,5,2] → fails
* For 3 → compare with [5,2] → fails
* For 5 → compare with [2] → passes
* For 2 → last element → passes

✅ Output: [17, 5, 2]

### ⏱️ Time Complexity

O(n²) — nested loop for each element.

---

## ⚙️ Step 2: Think efficiently — any pattern?

Let’s look from **right to left** instead of left to right.

➡️ Why?
Because a leader is defined as *greater than everything to its right* —
So if we move **from the right**, we can **keep track of the maximum** so far.

---

### Example Walkthrough

`arr = [16, 17, 4, 3, 5, 2]`

Start from the **last element**:

| Step | Element | Max from right | Is Leader? | Leaders so far |
| ---- | ------- | -------------- | ---------- | -------------- |
| 1    | 2       | -∞             | ✅ yes      | [2]            |
| 2    | 5       | 2              | ✅ yes      | [2, 5]         |
| 3    | 3       | 5              | ❌ no       | [2, 5]         |
| 4    | 4       | 5              | ❌ no       | [2, 5]         |
| 5    | 17      | 5              | ✅ yes      | [2, 5, 17]     |
| 6    | 16      | 17             | ❌ no       | [2, 5, 17]     |

Now reverse it → `[17, 5, 2]`

---

## ✅ Step 3: Optimal Approach (Right-to-left traversal)

### 💡 Idea:

* Start from rightmost element (always a leader)
* Keep a variable `maxRight`
* Traverse array backwards:

  * If current element > `maxRight`, mark it as leader and update `maxRight`

---

### 💻 Code Implementation (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans;

    int maxRight = arr[n - 1];
    ans.push_back(maxRight); // last element is always leader

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > maxRight) {
            ans.push_back(arr[i]);
            maxRight = arr[i];
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
```

---

### ✅ Example Run

For `arr = [16, 17, 4, 3, 5, 2]`:

```
maxRight = 2
→ i = 4: arr[4] = 5 > 2 → add 5, maxRight = 5
→ i = 3: arr[3] = 3 < 5 → skip
→ i = 2: arr[2] = 4 < 5 → skip
→ i = 1: arr[1] = 17 > 5 → add 17, maxRight = 17
→ i = 0: arr[0] = 16 < 17 → skip
```

Final reversed output → `[17, 5, 2]`

---

## ⏱️ Time and Space Complexity

| Complexity | Description                                        |
| ---------- | -------------------------------------------------- |
| **Time**   | O(n) (single pass)                                 |
| **Space**  | O(n) (to store leaders), O(1) if printing directly |

---

## 🔍 Step-by-Step Recap

| Step | Concept                      | Why                               |
| ---- | ---------------------------- | --------------------------------- |
| 1    | Start from rightmost element | It’s always a leader              |
| 2    | Track maxRight               | To compare current element easily |
| 3    | If arr[i] > maxRight         | It’s a leader                     |
| 4    | Reverse result               | Because we traverse from right    |

---

## 🧩 Final Output Example

Input:

```cpp
arr = [16, 17, 4, 3, 5, 2]
```

Output:

```
Leaders: [17, 5, 2]
```
