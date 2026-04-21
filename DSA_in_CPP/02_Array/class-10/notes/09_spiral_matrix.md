# ✅ **What is “Print Matrix in Spiral Order”?**

You are given a **2D matrix** like:

```
1   2   3
4   5   6
7   8   9
```

You must print elements in a **spiral pattern**, starting from the **top-left corner**, moving:

➡️ Right
⬇️ Down
⬅️ Left
⬆️ Up

…and repeat this “spiral loop” until all elements are printed.

### Spiral Output for above matrix:

```
1 2 3 6 9 8 7 4 5
```

---

# 🧠 **Understanding the Spiral Path**

Imagine your finger slowly tracing the outline of the matrix and going inward:

### **Layer 1 (outer layer):**

```
1 2 3 6 9 8 7 4
```

### **Layer 2 (inner layer):**

```
5
```

---

# 🎯 **What the Problem is Actually Asking**

* You need to **visit each element exactly once**, but in spiral order.
* You must understand when to **change direction** (right → down → left → up).
* You must understand how to **shrink boundaries** once a complete row/column is printed.

---

# 🧭 **How YOU Should Approach the Problem**

Let’s think like a beginner-friendly step-by-step breakdown.

---

# 🥉 **Step 1: Brute-force Thinking (NOT final code, only idea)**

Brute-force idea usually means:

❌ Hardcoding directions
❌ Checking all possible index movements
❌ Using many if-else blocks

But even for brute, **logic remains same**:

### **Keep Track of Directions:**

* Right: `(row, col++)`
* Down: `(row++, col)`
* Left: `(row, col--)`
* Up: `(row--, col)`

### **Use a visited matrix**

Create a matrix `visited[m][n]` initialized to false.

Then:

* Move in a direction until you hit boundary or visited cell.
* Change direction.
* Continue.

➡️ This is brute because you’re using extra space and many direction checks.

### Time & Space

* **TC:** O(m × n)
* **SC:** O(m × n) for visited

---

# 🥈 **Step 2: Better Approach (Boundary Method — MOST IMPORTANT)**

This is the approach interviewers expect and you should learn.

### Maintain 4 boundaries:

```
top = 0
bottom = m-1
left = 0
right = n-1
```

Now think:

### 1️⃣ Move LEFT → RIGHT

Print row `top` from `left` to `right`,
then `top++`

### 2️⃣ Move TOP → BOTTOM

Print col `right` from `top` to `bottom`,
then `right--`

### 3️⃣ Move RIGHT → LEFT

Print row `bottom` from `right` to `left`,
then `bottom--`

### 4️⃣ Move BOTTOM → TOP

Print col `left` from `bottom` to `top`,
then `left++`

You keep doing this while:

```
top <= bottom AND left <= right
```

This naturally creates the spiral.

### Time & Space

* **TC:** O(m × n)
* **SC:** O(1) auxiliary space
  (because no visited array)

---

# 🧠 **How to Think While Implementing (Your Personal Strategy)**

When coding, think like this:

1. **First step?** → Always go left to right on the top row.
2. **After this step, what changed?**
   → top boundary moves down.
3. **Next direction?** → Go down on the right column.
4. **What changed?** → right boundary moves left.
5. **Next?** → Go right to left on bottom row.
6. **What changed?** → bottom boundary moves up.
7. **Next?** → Go bottom to top on left column.
8. **What changed?** → left boundary moves right.
9. **When to stop?**
   → When boundaries cross.

---
---
---


<br>
<br>
<br>

# 🧩 Optimal idea (concise)

Maintain four boundaries:

```
top = 0
bottom = m - 1
left = 0
right = n - 1
```

Repeat these four moves while `top <= bottom && left <= right`:

1. Traverse left → right along row `top`. Then `top++`.
2. Traverse top → bottom along column `right`. Then `right--`.
3. **If** `top <= bottom`: traverse right → left along row `bottom`. Then `bottom--`.
4. **If** `left <= right`: traverse bottom → top along column `left`. Then `left++`.

Those `if` checks (steps 3 & 4) prevent double-visiting elements when matrix has collapsed to a single row or single column.

**Complexity:**

* Time: `O(m * n)` — each element printed once.
* Extra space: `O(1)` auxiliary (excluding the output list).

---

# ✅ Why this is optimal

* No extra `visited` matrix.
* Only four pointers and simple loops.
* Minimal condition checks to avoid repetition.

---

# 🧾 Clean C++ implementation (readable)

```cpp
#include <vector>
using std::vector;

vector<int> spiralOrder(const vector<vector<int>>& mat) {
    vector<int> ans;
    if (mat.empty() || mat[0].empty()) return ans;

    int top = 0;
    int bottom = mat.size() - 1;
    int left = 0;
    int right = mat[0].size() - 1;

    while (top <= bottom && left <= right) {
        // 1) left -> right on top row
        for (int c = left; c <= right; ++c) ans.push_back(mat[top][c]);
        ++top;

        // 2) top -> bottom on right column
        for (int r = top; r <= bottom; ++r) ans.push_back(mat[r][right]);
        --right;

        // 3) right -> left on bottom row (only if still valid)
        if (top <= bottom) {
            for (int c = right; c >= left; --c) ans.push_back(mat[bottom][c]);
            --bottom;
        }

        // 4) bottom -> top on left column (only if still valid)
        if (left <= right) {
            for (int r = bottom; r >= top; --r) ans.push_back(mat[r][left]);
            ++left;
        }
    }

    return ans;
}
```

---

# 🔎 Step-by-step dry run

Use this matrix (3 rows × 4 cols):

```
[ [ 1,  2,  3,  4 ],
  [ 5,  6,  7,  8 ],
  [ 9, 10, 11, 12 ] ]
```

Initial pointers:

```
top = 0, bottom = 2, left = 0, right = 3
ans = []
```

### Iteration 1

1. left → right on row `top=0`: take `1,2,3,4`
   `ans = [1,2,3,4]`
   `top = 1`

2. top → bottom on col `right=3`: take `8,12`  (rows 1..2)
   `ans = [1,2,3,4,8,12]`
   `right = 2`

3. since `top(1) <= bottom(2)`, right → left on row `bottom=2`: take `11,10,9`
   `ans = [1,2,3,4,8,12,11,10,9]`
   `bottom = 1`

4. since `left(0) <= right(2)`, bottom → top on col `left=0`: take `5` (row 1..1)
   `ans = [1,2,3,4,8,12,11,10,9,5]`
   `left = 1`

Pointers now:

```
top = 1, bottom = 1, left = 1, right = 2
```

### Iteration 2

1. left → right on row `top=1`: take `6,7` (cols 1..2)
   `ans = [1,2,3,4,8,12,11,10,9,5,6,7]`
   `top = 2`

2. top → bottom on col `right=2`: no rows because `top(2) > bottom(1)` → nothing; `right = 1`

3. check `top <= bottom` → `2 <= 1` is false → skip step 3

4. check `left <= right` → `1 <= 1` true, but bottom (1) >= top (2)? step 4 loop uses `for (r = bottom; r >= top; --r)` — since `bottom(1) < top(2)` it loops zero times → no change. Then `left = 2`

Now `top = 2, bottom = 1` → `top > bottom` so loop stops.

Final `ans = [1,2,3,4,8,12,11,10,9,5,6,7]` — correct.

---

# 🔁 Short notes on tricky cases

1. **Single row**: `m=1, n>1`

   * Step 1 prints the whole row, `top` becomes `1` and loop ends. Good.

2. **Single column**: `n=1, m>1`

   * Step 1 prints top element, then step 2 prints remaining; `if` checks prevent duplication.

3. **Empty matrix**: return empty vector immediately.

4. **Square / rectangular**: same code handles all.
