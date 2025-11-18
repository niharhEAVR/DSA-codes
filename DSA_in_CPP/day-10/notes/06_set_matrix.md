## 🧩 Problem: “Set Matrix Zeroes”

### 🔷 Problem Statement

Given an `m x n` matrix,
**if any cell contains `0`, you must set its entire row and column to 0.**

You must do it **in-place** (meaning you modify the same matrix).

---

### Example

Input:

```
1 1 1
1 0 1
1 1 1
```

Output:

```
1 0 1
0 0 0
1 0 1
```

Explanation:

* The cell `(1,1)` (2nd row, 2nd column) is `0`.
* So its **entire 2nd row** and **2nd column** become 0.

---

Another example:

Input:

```
0 1 2 0
3 4 5 2
1 3 1 5
```

Output:

```
0 0 0 0
0 4 5 0
0 3 1 0
```

Because:

* First row has `0` → entire row 1 and column 1 set to 0
* Last column also has `0` → all rows get that column zeroed

---

## 🧠 Let’s Think Before Coding

The challenge is:
when we see a `0`, we must make **its row and column** zero —
but if we start doing it immediately,
we’ll **create new zeroes**, and those new zeroes will cause even more rows and columns to zero out incorrectly.

So we need a **way to mark** which rows and columns should be zeroed —
without disturbing the rest of the matrix while checking.

---

## 🪜 Step-by-Step: Brute Force Approach

### 🎯 Idea

Whenever you find a `0`,
go and mark all elements in its row and column with some **temporary marker** (for example, `-1`),
so that later you can convert all `-1`s into `0`s.

---

### 🧩 Step 1 — Traverse the entire matrix

Find all positions where the element = 0.

For every such cell `(i, j)`:

* traverse **that row i** and mark non-zero elements as `-1`
* traverse **that column j** and mark non-zero elements as `-1`

---

### 🧩 Step 2 — After marking all,

convert every `-1` to `0`.

---

### Example Walkthrough

Let’s take:

```
1 1 1
1 0 1
1 1 1
```

#### Step 1:

Found `0` at position (1,1).

→ mark its entire row and column (except the zero itself):

```
1 -1 1
-1  0 -1
1 -1 1
```

#### Step 2:

Convert all `-1` to `0`:

```
1 0 1
0 0 0
1 0 1
```

✅ Output done.

---

### ⏱️ Time & Space Complexity

| Step                            | Work Done         | Complexity         |
| ------------------------------- | ----------------- | ------------------ |
| Traversing whole matrix         | O(m×n)            | O(m×n)             |
| For every 0 → mark row + column | O(m + n) per zero | O(m×n×(m+n)) worst |
| Final conversion                | O(m×n)            | O(m×n)             |

So total **Time Complexity = O((m×n) × (m+n))** (very high)
and **Space = O(1)** (no extra array used).

---

### ✅ Code (Brute Force)

```cpp
#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Step 1: mark with -1
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                // mark row
                for (int k = 0; k < cols; k++) {
                    if (matrix[i][k] != 0)
                        matrix[i][k] = -1;
                }
                // mark column
                for (int k = 0; k < rows; k++) {
                    if (matrix[k][j] != 0)
                        matrix[k][j] = -1;
                }
            }
        }
    }

    // Step 2: replace all -1 with 0
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == -1)
                matrix[i][j] = 0;
        }
    }
}
```

---

### 🔍 Dry Run

Input:

```
1 1 1
1 0 1
1 1 1
```

After marking:

```
1 -1 1
-1 0 -1
1 -1 1
```

After conversion:

```
1 0 1
0 0 0
1 0 1
```

✅ Correct Output.

---
---
---



You noticed that if the **matrix originally contains `-1`**,
our **brute-force method** (which uses `-1` as a temporary marker) will **break** — because we can’t tell which `-1` was *originally there* and which one we added as a *marker*.

Let’s unpack this carefully 👇

---

## 🧩 Problem Recap

Brute force marks cells as `-1` when it wants to “remember”
that this cell should eventually become `0`.

But what if the matrix already has negative numbers like this:

```cpp
[[-1], [2], [3]]
```

Then after marking, we lose track of which `-1` came from our marking and which was part of the input.

So you are **absolutely correct** — the brute force using `-1` fails in this case.

---

## ⚠️ Why It Happens

Because the marking value (`-1`) is not guaranteed to be unique.
If the original matrix has any negative numbers,
you’ll accidentally turn them into zeros even though they shouldn’t be.

---

## 🧠 How to Fix This in the Brute Approach

We have **two options**:

---

### ✅ Option 1 — Use a Unique Marker (Very Unlikely to Appear)

Choose a **special value** that’s extremely unlikely to appear in the input.
For example, `-99999` or `INT_MIN`.

Example:

```cpp
if (matrix[i][k] != 0)
    matrix[i][k] = -99999;
```

Later you replace all `-99999` → `0`.

👉 Still a bit risky — if the problem ever allows that number in input, it breaks again.

---

### ✅ Option 2 — Use an Extra Copy of the Matrix (Safe)

Create another matrix to store which cells should become 0.

This makes it a **true brute-force** (using extra space).

### Steps:

1. Create a copy of the original matrix.
2. Whenever you see a `0` in the original,
   modify the corresponding row and column in the *copy*.
3. Finally, copy the result back.

---

### Example Code (100% Safe Brute Force)

```cpp
#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> result = matrix; // make a copy

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                // make that row and column 0 in result
                for (int k = 0; k < cols; k++)
                    result[i][k] = 0;
                for (int k = 0; k < rows; k++)
                    result[k][j] = 0;
            }
        }
    }

    // copy result back
    matrix = result;
}
```

✅ This works safely even if matrix contains `-1`, `-999`, etc.

---

### 🧮 Complexity

| Metric | Value            |
| ------ | ---------------- |
| Time   | O((m×n) × (m+n)) |
| Space  | O(m×n)           |

That’s why it’s truly **brute-force** — very expensive but safe and simple.

---

So you’re 100% correct:

> If the matrix contains values like `-1`, our first brute-force (using `-1` as a marker) **fails**.

✅ The correct brute-force should instead use a **separate matrix copy** to avoid this problem.
