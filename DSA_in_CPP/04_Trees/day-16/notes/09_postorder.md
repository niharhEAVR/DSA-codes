# 🌳 Postorder Traversal (Core Idea)

[
\textbf{Left → Right → Root}
]

---

# 🧠 Golden Rule

> “Don’t process the node until BOTH left and right are done”

This is the **big difference from inorder**.

---

# 🌲 Same Tree

```
        1
       / \
      2   3
     / \
    4   5
```

---

# 🔄 Flow Thinking (Recursion + Stack Together)

We’ll move exactly like before — but now **we delay visiting**.

---

## Start at 1

* Push `1` → go left

Stack: `[1]`

---

## At 2

* Push `2` → go left

Stack: `[1, 2]`

---

## At 4

* Push `4` → go left → NULL

Stack: `[1, 2, 4]`

---

# ⚡ Now decision point (IMPORTANT)

At `4`:

* Left done ✅
* Right also NULL ✅

👉 Now we can finally **visit 4**

Pop `4` → Output: `4`

Stack: `[1, 2]`

---

## Back to 2

* Left done ✅
* Now go right → `5`

---

## At 5

* Push `5` → go left → NULL

Stack: `[1, 2, 5]`

---

At `5`:

* Left done ✅
* Right done ✅

👉 Visit `5`

Pop `5` → Output: `4 5`

Stack: `[1, 2]`

---

## Back to 2 AGAIN

Now:

* Left done ✅
* Right done ✅

👉 Visit `2`

Pop `2` → Output: `4 5 2`

Stack: `[1]`

---

## Back to 1

* Left done ✅
* Go right → `3`

---

## At 3

* Push `3` → go left → NULL

Stack: `[1, 3]`

---

At `3`:

* Left done ✅
* Right done ✅

👉 Visit `3`

Pop `3` → Output: `4 5 2 3`

Stack: `[1]`

---

## Back to 1 (FINAL)

Now:

* Left done ✅
* Right done ✅

👉 Visit `1`

Pop `1` → Output: `4 5 2 3 1`

---

# ✅ Final Output

```
4 5 2 3 1
```

---

# 🔥 KEY INTUITION (VERY IMPORTANT)

### Inorder:

> Go left → process → go right

### Postorder:

> Go left → go right → process

---

# 💥 The REAL DIFFERENCE (this is interview gold)

| Traversal | When do you process node? |
| --------- | ------------------------- |
| Inorder   | After left                |
| Postorder | After left **AND right**  |

---

# 🧠 Mental Model (Super Simple)

Think:

> 🕒 “I will come back twice before processing”

* First return → after left
* Second return → after right
* THEN process

---

# ⚠️ Why Postorder Feels Hard

Because:

* You can’t process immediately after popping
* You must **remember if right is visited or not**

👉 That’s why iterative version is tricky

---

# 🚀 One-Line Trick

> 💡 “Node is processed only when it becomes useless (no children left to explore)”
