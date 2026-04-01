# 🌳 1. Binary Tree

### 🧠 Idea

Each node has **at most 2 children**

```text
        A
       / \
      B   C
     /
    D
```

👉 No restriction on values
👉 Just structure rule

---

# 🌳 2. Binary Search Tree (BST)

### 🧠 Rule

```text
Left < Root < Right
```

```text
        10
       /  \
      5    15
     / \     \
    2   7     20
```

👉 Used for **searching fast**

---

# 🌳 3. Full Binary Tree

### 🧠 Rule

Each node has:

* either **0 children**
* or **2 children**

```text
        A
       / \
      B   C
         / \
        D   E
```

👉 No node with only 1 child

---

# 🌳 4. Complete Binary Tree

### 🧠 Rule

* All levels filled
* Last level filled **left → right**

```text
        A
       / \
      B   C
     / \  /
    D  E F
```

👉 Used in **heaps**

---

# 🌳 5. Perfect Binary Tree

### 🧠 Rule

* All levels completely filled

```text
        A
       / \
      B   C
     / \ / \
    D  E F  G
```

👉 Nodes = `2^h - 1`

---

# 🌳 6. Balanced Binary Tree

Example: AVL Tree

### 🧠 Rule

Height difference between left & right is small

```text
        10
       /  \
      5    15
```

👉 Keeps operations **fast (log n)**

---

# 🌳 7. Heap (Min / Max Heap)

### 🧠 Rule

**Min Heap**

```text
Parent ≤ children
```

**Max Heap**

```text
Parent ≥ children
```

👉 Always a **complete binary tree**

---

# ⚡ Quick Comparison (VERY IMPORTANT)

| Type        | Rule                | Key Use              |
| ----------- | ------------------- | -------------------- |
| Binary Tree | ≤ 2 children        | Base structure       |
| BST         | Left < Root < Right | Searching            |
| Full        | 0 or 2 children     | Structure constraint |
| Complete    | Filled left → right | Heaps                |
| Perfect     | All levels full     | Ideal tree           |
| Balanced    | Height small        | Fast ops             |
| Heap        | Parent order rule   | Priority queue       |

---

# 🧠 Final Intuition (Lock This)

Think like:

```text
Binary Tree → structure
BST → ordering
Complete → shape
Balanced → performance
Heap → priority
```





---
---
---
---
---
---
---
---
---






# 🌳 Heap Tree Structure (Min & Max Heap)

# 🧠 What is a Heap?

A **Heap** is a special type of **Complete Binary Tree** with an extra rule.

---

## 🔹 1. Min Heap

### Rule:

```text
Parent ≤ Children
```

### Example:

```text
        2
       / \
      4   5
     / \   \
    10 8    7
```

👉 Smallest element always at **root**

---

## 🔹 2. Max Heap

### Rule:

```text
Parent ≥ Children
```

### Example:

```text
        20
       /  \
     15    10
     / \     \
    8   7     5
```

👉 Largest element always at **root**

---

# ⚡ MOST IMPORTANT PROPERTY

👉 Heap is always a **Complete Binary Tree**

```text
        ✔ filled level by level
        ✔ left to right
```

❌ You can’t randomly shape it like BST

---

# 🧠 Super Important Insight (INTERVIEW GOLD)

Heap is usually stored as an **array**, not pointers.

---

## 🔹 Array Representation

For this heap:

```text
        10
       /  \
      5    8
     / \
    2   3
```

Array becomes:

```text
[10, 5, 8, 2, 3]
```

---

## 🔹 Index Relations

If index = `i`:

```text
Left child  = 2*i + 1
Right child = 2*i + 2
Parent      = (i-1)/2
```

👉 This is VERY IMPORTANT

---

# 🔁 Why Heap is Useful?

* Priority Queue
* Scheduling
* Dijkstra’s Algorithm
* Heap Sort

---

# ⚠️ Common Mistakes

---

## ❌ Heap ≠ Sorted Tree

This is valid heap:

```text
        10
       /  \
      9    8
     /
    7
```

👉 But NOT sorted like BST

---

## ❌ Only parent-child relation matters

Heap does NOT guarantee:

```text
Left subtree < right subtree ❌
```

Only:

```text
Parent vs children ✔
```

---

# 🧠 Final Intuition (Lock This)

```text
BST → ordered globally
Heap → ordered locally (parent vs children only)
```

---

# 🔥 One-Line Summary

```text
Heap = Complete Binary Tree + Priority Rule
```
