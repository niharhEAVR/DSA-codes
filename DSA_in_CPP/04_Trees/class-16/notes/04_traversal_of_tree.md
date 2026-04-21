# 🌳 What is Tree Traversal?

Traversal = **visiting every node exactly once in some order**

---

# 🌳 Step 1: Think of Tree Like This

```text
        1
       / \
      2   3
     / \   \
    4   5   6
```

👉 Traversal = **the order in which you visit nodes**

---

# 🔥 First Understand the CORE IDEA

There are only **2 ways to move in a tree**:

### 1. Go DEEP first → DFS

👉 Like exploring a maze fully before coming back

### 2. Go LEVEL by LEVEL → BFS

👉 Like checking all nodes at same distance first

---

# 🧠 PART 1: DFS (Depth First Search)

👉 You go **down one branch completely**, then come back

---

## 💡 Trick to Understand DFS

At every node, ask:

👉 “When should I print this node?”

---

## 🔵 1. PREORDER

### Rule:

```text
Print → Left → Right
```

### Walk step-by-step:

```text
Start at 1 → print 1
Go left → 2 → print 2
Go left → 4 → print 4
Back → go right of 2 → 5 → print 5
Back → go right of 1 → 3 → print 3
Go right → 6 → print 6
```

### ✅ Final:

```text
1 2 4 5 3 6
```

---

## 🔵 2. INORDER

### Rule:

```text
Left → Print → Right
```

### Walk:

```text
Go left of 1 → 2
Go left of 2 → 4 → print 4
Back → print 2
Go right → 5 → print 5
Back → print 1
Go right → 3 → print 3
Go right → 6 → print 6
```

### ✅ Final:

```text
4 2 5 1 3 6
```

---

## 🔵 3. POSTORDER

### Rule:

```text
Left → Right → Print
```

### Walk:

```text
Go left → 2
Go left → 4 → print 4
Go right → 5 → print 5
Now print 2
Go right → 3
Go right → 6 → print 6
Now print 3
Now print 1
```

### ✅ Final:

```text
4 5 2 6 3 1
```

---

## 🎯 One Line Memory Trick

| Type      | Rule            | Meaning      |
| --------- | --------------- | ------------ |
| Preorder  | Root Left Right | Print early  |
| Inorder   | Left Root Right | Print middle |
| Postorder | Left Right Root | Print last   |

---

# 🌊 PART 2: BFS (Level Order)

👉 Instead of going deep, you go **level by level**

---

## 💡 Think Like This:

👉 “First I will visit all nodes at level 1, then level 2, then level 3”

---

### Levels:

```text
Level 1 → 1
Level 2 → 2, 3
Level 3 → 4, 5, 6
```

---

### ✅ Final BFS:

```text
1 2 3 4 5 6
```

---

## 🧠 How BFS Works Internally

👉 Uses **QUEUE (FIFO)**

Step-by-step:

```text
Queue = [1]

Take 1 → print → add 2,3  
Queue = [2,3]

Take 2 → print → add 4,5  
Queue = [3,4,5]

Take 3 → print → add 6  
Queue = [4,5,6]

Take 4 → print  
Take 5 → print  
Take 6 → print
```

---

# ⚡ FINAL DIFFERENCE (SUPER SIMPLE)

| DFS             | BFS                 |
| --------------- | ------------------- |
| Goes deep first | Goes level by level |
| Uses recursion  | Uses queue          |
| 3 types         | Only 1 type         |

---

# 🧠 REAL LIFE ANALOGY

### DFS 🧗

👉 Go inside one path fully (like exploring one tunnel)

### BFS 🏢

👉 Visit floor by floor (like checking each floor of a building)

---
---
---
---
---
---


