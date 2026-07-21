# 🌳 What are you given?

A **binary tree**, like this:

```
        10
       /  \
      2   10
     / \     \
    20  1    -25
               / \
              3   4
```

Each node has a **value** (can be positive or negative).

---

# 🎯 What do you need to find?

👉 The **maximum sum of any path** in the tree.

---

# 🧠 What exactly is a “path”?

A path is:

* A sequence of nodes connected by edges
* Must be continuous (no jumping)
* You **cannot reuse nodes**
* You can start **anywhere**
* You can end **anywhere**

---

# 🚫 Common misunderstandings

❌ It does NOT have to:

* Start from root
* End at leaf
* Be straight (it can bend at a node)

---

# ✅ Valid paths examples (from the tree above)

Some possible paths:

* `20 → 2 → 1` → sum = 23
* `2 → 10` → sum = 12
* `3 → -25 → 4` → sum = -18
* `20 → 2 → 10 → 10` → sum = 42 ✅
* `10` alone → 10

👉 The goal is to find the **maximum among ALL such paths**

---

# 🔥 Key intuition

Think like this:

> “If I pick ANY node in the tree…
> what is the best path I can form using connected nodes?”

---

# 🧩 Important rule

A path can look like:

### 1. Straight line

```
A → B → C
```

### 2. Or “V” shape (this is the tricky part)

```
   B
  / \
 A   C
```

👉 This means:

* Path can go **left → node → right**

---

# ⚠️ Very important edge case

All values can be negative.

Example:

```
   -3
```

👉 Answer = **-3** (you must pick at least one node)

---

# 🧠 Another way to think

Imagine:

* You are allowed to pick **any connected segment of the tree**
* Your job is to find the segment with **maximum sum**

---

# 💬 Super simple summary

👉 “Find the highest sum you can get by walking along connected nodes in the tree, starting and ending anywhere.”

---
---
---
---
---
---
---
---


# Some Examples

# 🌳 Example 1

```
    1
   / \
  2   3
```

### Possible paths:

* `1` → sum = 1
* `2` → sum = 2
* `3` → sum = 3
* `2 → 1` → sum = 3
* `1 → 3` → sum = 4
* `2 → 1 → 3` → sum = **6 ✅**

👉 **Answer = 6**

---

# 🌳 Example 2

```
     -10
     /  \
    9   20
        / \
       15  7
```

### Try some paths:

* `15 → 20 → 7` → sum = **42 ✅**
* `9 → -10 → 20` → sum = 19
* `20 → 7` → sum = 27
* `15 → 20` → sum = 35

👉 **Answer = 42**

⚠️ Notice:

* Best path does **NOT include root (-10)**

---

# 🌳 Example 3 (All negatives)

```
   -3
```

### Paths:

* Only one node → `-3`

👉 **Answer = -3**

⚠️ You must pick at least one node

---

# 🌳 Example 4 (Important shape)

```
      5
     / \
    4   8
   /   / \
 11   13  4
```

### Interesting paths:

* `11 → 4 → 5 → 8 → 13` → sum = **41 ✅**
* `4 → 5 → 8 → 4` → sum = 21
* `13 → 8 → 4` → sum = 25

👉 **Answer = 41**

---

# 🧠 What you should notice from all examples

### 🔹 1. Path can start anywhere

Not always from root

---

### 🔹 2. Path can end anywhere

Not always at leaf

---

### 🔹 3. Best path often looks like this:

```
left → node → right
```

👉 Like:

```
15 → 20 → 7
```

---

### 🔹 4. Sometimes you should IGNORE nodes

Example 2:

* We ignore `-10` because it reduces sum

---

# 💬 Final intuition

Think:

> “If I try every possible connected path in this tree…
> which one gives the highest sum?”

---
---
---
---
---

# 🧠 Step 1: Think like this

At every node, ask **two different questions**:

### 👉 Q1. “What is the best path passing THROUGH this node?”

This path can be:

```
left → node → right
```

---

### 👉 Q2. “What is the best path I can extend upward to my parent?”

This path must be:

```
node → ONE side only (left OR right)
```

⚠️ You cannot go both sides upward (that would split the path)

---

# 🌳 Visual intuition

At a node:

```
     node
    /    \
 left    right
```

You have 2 roles:

### ✅ Role 1 (Global answer candidate)

Take both sides:

```
left + node + right
```

---

### ✅ Role 2 (Return to parent)

Take only one side:

```
node + max(left, right)
```

---

# ⚠️ Step 2: Handle negative values

If a subtree gives negative sum, **ignore it**.

So instead of:

```
left = dfs(left)
```

You do:

```
left = max(0, dfs(left))
```

👉 Meaning:

> “If this side hurts me, I don’t take it.”

---

# 🔥 Step 3: What do we track?

We need a **global variable**:

```
maxSum = -∞
```

Because:

* The best path can be anywhere in the tree

---

# 🧩 Step 4: Combine everything

At each node:

### 1. Get left & right contributions

```
left  = max(0, dfs(left))
right = max(0, dfs(right))
```

---

### 2. Try making a full path through node

```
current = left + node.val + right
```

👉 Update answer:

```
maxSum = max(maxSum, current)
```

---

### 3. Return best single path upward

```
return node.val + max(left, right)
```

---

# 🧠 Why this works (important)

* **Global max** checks all possible “V-shaped” paths
* **Return value** ensures valid path (no splitting upward)

---

# ⚡ Dry intuition in one line

> “At each node, I try to form the best complete path,
> but I only pass one side upward.”

---

# 🚀 Mental shortcut (for interviews)

If stuck, remember:

* “Take both sides → update answer”
* “Take one side → return”

---

# 🧾 Clean structure (pseudo)

```text
dfs(node):
    if null → return 0

    left  = max(0, dfs(left))
    right = max(0, dfs(right))

    maxSum = max(maxSum, left + node + right)

    return node + max(left, right)
```
