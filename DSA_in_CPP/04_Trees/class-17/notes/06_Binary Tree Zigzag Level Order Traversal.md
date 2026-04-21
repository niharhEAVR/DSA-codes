# 🌳 What is

## **Binary Tree Zigzag Level Order Traversal?**

It’s a variation of **level order traversal** (BFS), but with a twist:

> Instead of going **left → right** at every level,
> you **alternate direction at each level**.

---

# 🧠 First, recall normal Level Order Traversal

For a tree like:

```
        1
       / \
      2   3
     / \   \
    4   5   6
```

### Normal Level Order:

```
Level 0 → [1]
Level 1 → [2, 3]
Level 2 → [4, 5, 6]
```

Output:

```
[[1], [2, 3], [4, 5, 6]]
```

---

# ⚡ Now, Zigzag Traversal (the twist)

Here’s the rule:

| Level | Direction    |
| ----- | ------------ |
| 0     | Left → Right |
| 1     | Right → Left |
| 2     | Left → Right |
| 3     | Right → Left |
| ...   | Alternate    |

---

# 🔄 Same Tree, Zigzag Output

```
        1
       / \
      2   3
     / \   \
    4   5   6
```

---

### 🔹 Level 0 (Left → Right)

```
[1]
```

---

### 🔹 Level 1 (Right → Left)

Normal would be:

```
[2, 3]
```

But zigzag flips it:

```
[3, 2]
```

---

### 🔹 Level 2 (Left → Right again)

```
[4, 5, 6]
```

---

# ✅ Final Answer:

```
[[1], [3, 2], [4, 5, 6]]
```

---

# 🎯 What the problem is REALLY testing

It’s checking if you understand:

### 1. **Tree Levels**

* Nodes grouped by depth

---

### 2. **Order manipulation**

* Same nodes
* Just changing **reading direction**

---

### 3. **Pattern recognition**

* Even level → normal
* Odd level → reversed

---

# 🔥 Important Insight

👉 The **structure of the tree does NOT change**
👉 Only the **order in which you read nodes changes**

---

# 🧠 Think of it like this (BEST VISUAL)

Imagine writing levels like:

```
Level 0: →
Level 1: ←
Level 2: →
Level 3: ←
```

Like a **zigzag path**:

```
→ → →
      ↓
← ← ←
↓
→ → →
```

---

# ❗ Common Confusion

### ❌ It is NOT:

* Changing child connections
* Swapping nodes
* Reversing the tree

### ✅ It IS:

* Just reversing the **output order at alternate levels**

---

# 💡 Real-world analogy

Think of reading lines:

```
Line 1 → read left to right
Line 2 → read right to left
Line 3 → left to right
```

Like a snake 🐍 moving back and forth.

---
---
---
---
---




# 🧠 Your Idea (Cleaned Up)

You said:

* ✅ **Flag** → controls direction (left→right or right→left)
* ✅ **Queue** → stores nodes level by level
* ✅ **Vector list** → stores final answer

✔️ This is correct.

---

# 🔥 What you might be missing (IMPORTANT)

The **core difficulty** in this problem is NOT traversal.

👉 It’s this:

> “How do I store values in the correct order for each level?”

Because:

* Queue always gives nodes in **left → right**
* But sometimes you want **right → left**

---

# 🌳 Let’s visualize YOUR approach properly

Take this tree:

```id="h0v8h1"
        1
       / \
      2   3
     / \   \
    4   5   6
```

---

# 🔄 Step-by-step with YOUR logic

## 🔹 Initial

* Queue = `[1]`
* flag = **true** (Left → Right)

---

## 🔹 Level 0

Process queue:

```id="u72f4g"
Nodes: [1]
```

Since flag = true:

```id="u8t8dn"
Store as → [1]
```

Add children to queue:

```id="r8fj0c"
Queue = [2, 3]
```

Flip flag ❗

---

## 🔹 Level 1

Queue:

```id="6ns2kq"
[2, 3]
```

Normal order from queue:

```id="6q3lj6"
[2, 3]
```

But flag = false (Right → Left)

So you store:

```id="s7tr6t"
[3, 2]
```

Add children:

```id="b2n4lg"
Queue = [4, 5, 6]
```

Flip flag ❗

---

## 🔹 Level 2

Queue:

```id="5kg0ye"
[4, 5, 6]
```

flag = true (Left → Right)

Store:

```id="v7qg0q"
[4, 5, 6]
```

---

# ✅ Final Output

```id="8b1n6c"
[[1], [3, 2], [4, 5, 6]]
```

---

# ⚠️ The REAL tricky part (where most people get stuck)

👉 Queue **always** gives:

```id="p9dzs7"
left → right
```

So the question becomes:

> How do I reverse the order WHEN needed?

---

# 💡 Mental clarity (VERY IMPORTANT)

There are ONLY 2 possibilities per level:

### Case 1: flag = true

👉 Store normally

```id="zfy9nd"
push_back(node value)
```

---

### Case 2: flag = false

👉 Store in reverse

You mentally do:

```id="lm6m6x"
insert from right side
```

---

# 🧠 Final Understanding (One Line)

> “Traverse level by level using queue,
> and depending on the flag,
> store values either normally or in reverse order.”

---

# 🔥 One mistake to avoid

❌ Don’t try to reverse the queue
❌ Don’t change traversal

✅ Only change **how you store values**



---
---
---
---
---
---
---


# ⏱️ Time Complexity (TC)

### 👉 **O(N)**

### Why?

* You visit **each node exactly once**
* For every node:

  * You push it into queue → O(1)
  * You pop it → O(1)
  * You place it in vector → O(1)

👉 Total work per node = constant

So:

[
\text{TC} = O(N)
]

where **N = number of nodes in the tree**

---

# 💾 Space Complexity (SC)

### 👉 **O(N)**

But let’s break it properly (this is what interviewers want 👇)

---

## 1. Queue space

* In worst case (last level), queue holds **~N/2 nodes**
* So:

[
O(N)
]

---

## 2. Output vector

* You are storing all nodes in result:

[
O(N)
]

---

## 3. Temporary level vector

* At each level, max size = width of tree → ≤ N
* But not extra (it goes into result)

---

# ✅ Final Space Complexity

[
\text{SC} = O(N)
]

---

# 🔥 Important Interview Insight

### You can say:

> “Auxiliary space is O(N) due to queue,
> and overall space is O(N) including output.”

---

# ⚡ Bonus Understanding

| Case          | Space                             |
| ------------- | --------------------------------- |
| Balanced tree | O(N/2) ≈ O(N)                     |
| Skewed tree   | O(1) queue, but still O(N) result |

---

# 🧠 Final Answer (clean)

* **Time Complexity:** `O(N)`
* **Space Complexity:** `O(N)`