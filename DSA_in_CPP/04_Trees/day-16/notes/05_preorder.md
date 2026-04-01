# 🌳 Tree

```text
        1
       / \
      2   3
     / \   \
    4   5   6
```

---

# 💻 Code (focus)

```cpp
void preorder(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
```

---

# 🧠 IMPORTANT IDEA

👉 Every function call goes into a **STACK (LIFO)**
👉 Top = currently executing function

---

# 🔥 FULL DRY RUN WITH STACK

---

## 🔹 Step 1: Call preorder(1)

```text
STACK:
[ preorder(1) ]   ← top

Print: 1
```

👉 Now it calls left → `preorder(2)`

---

## 🔹 Step 2: Call preorder(2)

```text
STACK:
[ preorder(1)
  preorder(2) ]   ← top

Print: 2
```

👉 Call left → `preorder(4)`

---

## 🔹 Step 3: Call preorder(4)

```text
STACK:
[ preorder(1)
  preorder(2)
  preorder(4) ]   ← top

Print: 4
```

👉 Call left → NULL

---

## 🔹 Step 4: Left of 4 is NULL

```text
STACK:
[ preorder(1)
  preorder(2)
  preorder(4) ]

Return (nothing happens)
```

👉 Now call right → NULL

---

## 🔹 Step 5: Right of 4 is NULL

```text
STACK:
[ preorder(1)
  preorder(2)
  preorder(4) ]

Return
```

👉 Now **preorder(4) is DONE → POP**

---

## 🔹 Step 6: Back to preorder(2)

```text
STACK:
[ preorder(1)
  preorder(2) ]   ← top
```

👉 Now go right → `preorder(5)`

---

## 🔹 Step 7: Call preorder(5)

```text
STACK:
[ preorder(1)
  preorder(2)
  preorder(5) ]   ← top

Print: 5
```

👉 Left NULL → return
👉 Right NULL → return

👉 POP `preorder(5)`

---

## 🔹 Step 8: Back to preorder(2)

```text
STACK:
[ preorder(1)
  preorder(2) ]
```

👉 Both sides done → POP `preorder(2)`

---

## 🔹 Step 9: Back to preorder(1)

```text
STACK:
[ preorder(1) ]   ← top
```

👉 Now go right → `preorder(3)`

---

## 🔹 Step 10: Call preorder(3)

```text
STACK:
[ preorder(1)
  preorder(3) ]   ← top

Print: 3
```

👉 Left NULL → return
👉 Right → `preorder(6)`

---

## 🔹 Step 11: Call preorder(6)

```text
STACK:
[ preorder(1)
  preorder(3)
  preorder(6) ]   ← top

Print: 6
```

👉 Left NULL
👉 Right NULL

👉 POP `preorder(6)`

---

## 🔹 Step 12: Back to preorder(3)

```text
STACK:
[ preorder(1)
  preorder(3) ]
```

👉 Done → POP

---

## 🔹 Step 13: Back to preorder(1)

```text
STACK:
[ preorder(1) ]
```

👉 Done → POP

---

## 🔹 FINAL STACK

```text
STACK: [ empty ]
```

---

# ✅ FINAL OUTPUT

```text
1 2 4 5 3 6
```

---

# 🧠 WHAT YOU SHOULD NOTICE (VERY IMPORTANT)

### 1. Stack grows when going LEFT

👉 `1 → 2 → 4`

---

### 2. Stack shrinks when hitting NULL

👉 That’s when **backtracking happens**

---

### 3. Right child is processed ONLY after left is fully done

---

# 🔥 SIMPLE MEMORY MODEL

```text
Go LEFT until you can't
Then come back
Then go RIGHT
```

---

# ⚡ SUPER IMPORTANT INSIGHT

👉 Recursion = **implicit stack**

Equivalent iterative thinking:

```text
Push node → process → go left
If no left → go back → go right
```
