In a **Binary Search Tree (BST)**, *ceil* and *floor* are very important concepts based on how values are arranged.

---

## 🌳 First, recall BST property

For any node:

* Left subtree → values **smaller**
* Right subtree → values **greater**

---

## 🔹 What is FLOOR in BST?

👉 **Floor of a value `x` = the largest value in BST that is ≤ x**

### 🧠 Think like:

> "x se chhota ya equal jo sabse bada number mile"

### 📌 Example:

BST contains: `2, 4, 6, 8, 10`

* Floor of `7` → **6**
* Floor of `4` → **4**
* Floor of `1` → ❌ (doesn't exist)

---

## 🔹 What is CEIL in BST?

👉 **Ceil of a value `x` = the smallest value in BST that is ≥ x**

### 🧠 Think like:

> "x se bada ya equal jo sabse chhota number mile"

### 📌 Example:

Same BST: `2, 4, 6, 8, 10`

* Ceil of `7` → **8**
* Ceil of `4` → **4**
* Ceil of `11` → ❌ (doesn't exist)

---

## 🔥 How it works in BST (IMPORTANT intuition)

Because BST is sorted structure, you don’t need to check all nodes.

---

### 🔻 FLOOR Logic

Start from root:

* If `node->val == x` → return it (perfect floor)
* If `node->val > x` → go **left** (too big)
* If `node->val < x` → this could be answer, go **right** to find a bigger valid one

---

### 🔺 CEIL Logic

Start from root:

* If `node->val == x` → return it (perfect ceil)
* If `node->val < x` → go **right** (too small)
* If `node->val > x` → this could be answer, go **left** to find a smaller valid one

---

## 🧩 Visual Example

Consider this BST:

```
        8
      /   \
     4     12
    / \    /
   2   6  10
```

### For x = 7:

* Floor → **6**
* Ceil → **8**

---

## ⚡ Time Complexity

* **O(h)** → height of tree

  * Best case (balanced BST): **O(log n)**
  * Worst case (skewed): **O(n)**

---

## 🚨 Common Mistake

Many people:

* Try to traverse entire tree ❌
* But BST allows **smart skipping** ✅

---
---
---
---


