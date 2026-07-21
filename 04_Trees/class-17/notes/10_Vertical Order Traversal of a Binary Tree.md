# 🧠 Step 1: Data structure (MOST IMPORTANT)

```cpp
map<int, map<int, multiset<int>>> nodes;
```

👉 What this does:

* `map<int, ...>` → **columns sorted automatically**
* inner `map<int, ...>` → **rows sorted automatically**
* `multiset<int>` → **values sorted automatically**

---

## 🔥 Mental picture

```text
col → row → sorted values
```

---

# 🧠 Step 2: Queue for BFS

```cpp
queue<pair<TreeNode*, pair<int,int>>> q;
```

👉 Each element stores:

```text
(node, (row, col))
```

---

# 🧠 Step 3: Start with root

```cpp
q.push({root, {0, 0}});
```

👉 Meaning:

* root at row = 0
* col = 0

---

# 🔁 Step 4: BFS loop

```cpp
while (!q.empty())
```

👉 Keep processing until all nodes are visited

---

# 🧠 Step 5: Take one node

```cpp
auto front = q.front();
q.pop();
```

👉 Remove one element from queue

---

```cpp
TreeNode* node = front.first;
int row = front.second.first;
int col = front.second.second;
```

👉 Extract:

* current node
* its row
* its column

---

# 🧠 Step 6: Store it

```cpp
nodes[col][row].insert(node->val);
```

👉 This line is EVERYTHING 🔥

### What happens here:

1. Go to correct **column**
2. Inside that → go to correct **row**
3. Insert value in **sorted order**

---

## 🧠 Example effect

```text
nodes[0][2] = {4, 5}   // automatically sorted
```

---

# 🧠 Step 7: Add left child

```cpp
if (node->left)
    q.push({node->left, {row+1, col-1}});
```

👉 Move:

* down → `row + 1`
* left → `col - 1`

---

# 🧠 Step 8: Add right child

```cpp
if (node->right)
    q.push({node->right, {row+1, col+1}});
```

👉 Move:

* down → `row + 1`
* right → `col + 1`

---

# 🔁 Repeat

👉 This continues until queue becomes empty

---

# 🧠 What you have now

After BFS:

```text
nodes = {
  -1: {1: [9]},
   0: {0: [3], 2: [15]},
   1: {1: [20]},
   2: {2: [7]}
}
```

---

# 🧠 Step 9: Read the structure

```cpp
for (auto &p : nodes)
```

👉 Iterate columns (sorted automatically)

---

```cpp
for (auto &q : p.second)
```

👉 Iterate rows inside that column

---

```cpp
q.second   // gives multiset (sorted values)
```

👉 Add all values to answer

---

# 🎯 Final mental flow

```text
1. BFS traversal
2. Store in col → row → sorted values
3. Read column-wise
```

---

# 🔥 Most important line

👉 If you understand THIS, you understand everything:

```cpp
nodes[col][row].insert(node->val);
```

---

# ⚡ One-line understanding

👉
**“Queue gives positions, map + multiset keeps everything sorted.”**

---
---
---
---
---
---
---
---
---
---
---
---



# 🧠 What you already have after BFS

Your structure looks like this:

```text
nodes = {
  -1: {1: [9]},
   0: {0: [3], 2: [15]},
   1: {1: [20]},
   2: {2: [7]}
}
```

👉 Meaning:

* Key = **column**
* Inside → key = **row**
* Inside → **sorted values (multiset)**

---

# 🎯 Goal now

Convert this into:

```text
[
 [9],
 [3,15],
 [20],
 [7]
]
```

---

# 🚀 Step-by-step (AFTER BFS)

---

## 🔹 Step 1: Start iterating columns

```cpp
for (auto &p : nodes)
```

👉 What is `p`?

* `p.first` → column (like -1, 0, 1…)
* `p.second` → all rows inside that column

---

## 🧠 First iteration

```text
p = (-1, {1: [9]})
```

👉 Start a new column list:

```text
temp = []
```

---

## 🔹 Step 2: Iterate rows inside this column

```cpp
for (auto &q : p.second)
```

👉 What is `q`?

* `q.first` → row
* `q.second` → multiset (sorted values)

---

### For column -1:

```text
q = (1, [9])
```

👉 Add all values from multiset:

```text
temp = [9]
```

---

## 🔹 Step 3: Push this column to answer

```text
ans = [ [9] ]
```

---

# 🔁 Move to next column

---

## 🧠 Column 0

```text
p = (0, {0: [3], 2: [15]})
```

👉 New temp:

```text
temp = []
```

---

### Row 0

```text
q = (0, [3])
```

👉 Add:

```text
temp = [3]
```

---

### Row 2

```text
q = (2, [15])
```

👉 Add:

```text
temp = [3, 15]
```

---

## 🔹 Push to answer

```text
ans = [ [9], [3,15] ]
```

---

# 🔁 Continue

---

## 🧠 Column 1

```text
temp = [20]
ans = [ [9], [3,15], [20] ]
```

---

## 🧠 Column 2

```text
temp = [7]
ans = [ [9], [3,15], [20], [7] ]
```

---

# ✅ Final Answer

```text
[
 [9],
 [3,15],
 [20],
 [7]
]
```

---

# 🔥 Key Understanding (VERY IMPORTANT)

👉 You are doing **3 nested levels**:

```text
for each column
    for each row
        take all sorted values
```

---

# ⚡ Why no sorting here?

Because already:

* `map` sorted columns ✅
* `map` sorted rows ✅
* `multiset` sorted values ✅

👉 So here you just **READ**, not sort

---

# 🧠 One-line understanding

👉
**“After BFS, just traverse col → row → values and collect.”**

---






---
---
---
---
---


Great — now let’s compare this **properly and deeply**, not just surface-level.

---

# 🧠 Let’s define `n`

* `n = number of nodes in the tree`

---

# 🚀 1. DFS + Sorting Approach

## 🔹 Steps involved

1. DFS traversal → visit all nodes
2. Store `(col, row, val)` → O(n)
3. Sort the list → **main cost**
4. Group → O(n)

---

## ⏱️ Time Complexity

### 🔥 Dominant step = Sorting

\[
O(n \log n)
\]

👉 Because we sort `n` elements

---

## 📦 Space Complexity

* Vector storing all nodes → `O(n)`
* Recursion stack → `O(h)` (height of tree)

👉 Worst case:
\[
O(n)
\]

---

# 🚀 2. BFS + Map + Multiset Approach

## 🔹 Steps involved

For each node:

* Insert into:

  ```cpp
  map<col, map<row, multiset>>
  ```

---

## 🧠 Important: Cost of each insertion

### 🔹 `map` insertion:

\[
O(\log n)
\]

### 🔹 `multiset` insertion:

\[
O(\log n)
\]

---

## ⏱️ Total Time Complexity

For each of `n` nodes:

\[
O(\log n) + O(\log n) = O(\log n)
\]

So total:

\[
O(n \log n)
\]

---

## 📦 Space Complexity

* Map + multiset storing all nodes → `O(n)`
* Queue for BFS → `O(n)`

👉 Total:
\[
O(n)
\]

---

# ⚖️ Final Comparison (VERY IMPORTANT)

| Factor           | DFS + Sort     | BFS + Map       |
| ---------------- | -------------- | --------------- |
| Time Complexity  | **O(n log n)** | **O(n log n)**  |
| Space Complexity | O(n)           | O(n)            |
| Implementation   | Simple ✅       | Complex ❌       |
| Sorting          | Done once      | Done repeatedly |
| Constants        | Smaller 🚀     | Larger 🐢       |

---

# 🔥 Hidden Insight (THIS IS GOLD)

👉 Both are **same Big-O**, but:

### DFS + Sort:

* Sorting happens **once**
* Very efficient in practice

### BFS + Map:

* Sorting happens **during every insertion**
* Slower due to:

  * multiple `log n` operations
  * heavy data structures

---

# 🎯 Which one should YOU use?

👉 In interviews:

* ✅ Prefer **DFS + sort**
* Only use BFS + map if interviewer hints at it

---

# 🧠 Final Understanding

👉
**Both do sorting, but:**

* DFS → “collect first, sort once”
* BFS → “keep things sorted all the time”

---

# ⚡ One-line conclusion

👉
**Same complexity, but DFS is faster and cleaner in real life**