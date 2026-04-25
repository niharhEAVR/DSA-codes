# ✅ 1. Are both correct?

### ✔ Recursive version

```cpp
if(root->val > val) return searchBST(root->left, val);
else return searchBST(root->right, val);
```

* Follows BST rule correctly
* Returns result properly (you fixed your earlier mistake 👍)

---

### ✔ Iterative version

```cpp
while (root != nullptr && root->val != val) {
    root = val < root->val ? root->left : root->right;
}
return root;
```

* Same logic, just without recursion
* Cleaner and efficient

👉 So yes, **both are logically 100% correct**

---

# ⏱ Time Complexity (VERY IMPORTANT)

For both approaches:

### 🌿 Best / Average Case:

[
O(\log n)
]

👉 Because each step:

* You eliminate **half of the tree** (like binary search)

---

### 🌲 Worst Case:

[
O(n)
]

👉 When tree becomes skewed:

```
1 → 2 → 3 → 4 → 5
```

* You traverse all nodes

---

# 💾 Space Complexity

### 🔁 Recursive

[
O(h)
]

* `h = height of tree`
* Because of **function call stack**

👉 Worst case:
[
O(n)
]

---

### 🔄 Iterative

[
O(1)
]

* No recursion
* Just one pointer moving

---

# ⚔️ Which one is better?

### 🥇 Iterative → Preferred in most cases

**Why?**

* No extra stack memory
* Safer (no stack overflow for large trees)
* Slightly more efficient

---

### 🤔 Then why use recursion?

Because:

* Easier to write
* More intuitive
* Good for learning / interviews (if interviewer allows)

---

# 🧠 Interview-Level Answer

If interviewer asks:

> Which one would you prefer?

Say:

👉 “Both have same time complexity, but iterative is preferred due to O(1) space and no recursion overhead. However, recursive is more readable.”

---

# 🔥 Deep Insight (Important for you)

Both are doing **exact same work**:

```id="y4jl8u"
Recursive = system stack handles movement
Iterative = you manually move pointer
```

👉 Only difference = **who manages the stack**

---

# 🚀 What Next?

Now that you understand search:

👉 Next best step is:

* **Insert in BST**
* then **Validate BST (VERY IMPORTANT for interviews)**








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




# ❌ What’s wrong in your code?

Look at this part:

```cpp
if(root->val > val) searchBST(root->left, val);
else searchBST(root->right, val);

return nullptr;
```

👉 You are **calling recursion**, but **not returning its result**.

So what happens?

* Even if the value is found deeper in the tree
* That result is **lost**
* And your function will always end up returning `nullptr` (unless found at root)

---

# 🧠 Think of it like this

Recursive call gives you an answer:

```cpp
TreeNode* ans = searchBST(root->left, val);
```

But you’re ignoring it ❌

---

# ✅ Fix (Minimal Change)

Just **return the recursive calls**:

```cpp
if(root->val > val) return searchBST(root->left, val);
else return searchBST(root->right, val);
```

---

# ✔️ Correct Version

```cpp
TreeNode* searchBST(TreeNode* root, int val) {
    if(root == nullptr) return nullptr;
    if(root->val == val) return root;
    
    if(root->val > val) return searchBST(root->left, val);
    else return searchBST(root->right, val);
}
```

---

# 🔥 Key Insight (VERY IMPORTANT)

👉 In recursion:

> If a function returns something → you must **return the recursive result**

Otherwise:

* You’re doing the work
* But throwing away the answer 😅