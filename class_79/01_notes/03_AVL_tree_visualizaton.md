Let’s break down the **insertion process** step by step with a **visual tree structure** after each operation to help you understand what's happening. Each step will explain how the tree evolves and maintains balance.

---

### **Step 1**: Insert 10  
The tree is empty (`root = NULL`).  
We insert `10` as the root of the tree.  

**Tree After Step 1**:
```
   10
  /  \
NULL  NULL
```
- `10` is now the root.
- No balancing needed as the tree is already balanced.

---

### **Step 2**: Insert 20  
We compare `20` with the root (`10`). Since `20 > 10`, we go to the **right subtree**, which is currently `NULL`.  
We insert `20` as the right child of `10`.  

**Tree After Step 2**:
```
   10
  /  \
NULL   20
       / \
    NULL  NULL
```
- **Height** of root (`10`):  
  `max(Height of left, Height of right) + 1 = max(0, 1) + 1 = 2`.  
- **Balance Factor** of root (`10`):  
  `Height of left - Height of right = 0 - 1 = -1`.  
  - The balance factor is `-1`, so no rotation is needed.

---

### **Step 3**: Insert 30  
We compare `30` with `10` → go **right**.  
We compare `30` with `20` → go **right** again.  
We insert `30` as the right child of `20`.  

**Tree After Step 3 (Unbalanced)**:
```
    10
   /  \
 NULL   20
       /  \
    NULL   30
           / \
        NULL  NULL
```
- **Height** of root (`10`):  
  `max(Height of left, Height of right) + 1 = max(0, 2) + 1 = 3`.  
- **Balance Factor** of root (`10`):  
  `Height of left - Height of right = 0 - 2 = -2`.  

Since the balance factor is `-2`, the tree is **right-heavy** → apply a **Left Rotation** at `10`.

#### **Left Rotation** at `10`:
1. `20` becomes the new root.  
2. `10` becomes the left child of `20`.  
3. Subtrees are rearranged.

**Tree After Rotation (Balanced)**:
```
      20
     /  \
   10    30
  /  \   / \
NULL NULL NULL NULL
```
- The tree is balanced again.

---

### **Step 4**: Insert 15  
We compare `15` with `20` → go **left**.  
We compare `15` with `10` → go **right**.  
We insert `15` as the right child of `10`.  

**Tree After Step 4**:
```
      20
     /  \
   10    30
  /  \
NULL  15
     /  \
  NULL  NULL
```
- **Height** of root (`20`):  
  `max(Height of left, Height of right) + 1 = max(2, 1) + 1 = 3`.  
- **Balance Factor** of root (`20`):  
  `Height of left - Height of right = 2 - 1 = 1`.  

Since the balance factor is `1`, the tree remains balanced.

---

### **Step 5**: Insert 25  
We compare `25` with `20` → go **right**.  
We compare `25` with `30` → go **left**.  
We insert `25` as the left child of `30`.  

**Tree After Step 5 (Unbalanced)**:
```
      20
     /  \
   10    30
  /  \   /  \
NULL  15 25  NULL
      / \ / \
   NULL NULL NULL NULL
```
- **Height** of root (`20`):  
  `max(Height of left, Height of right) + 1 = max(2, 2) + 1 = 3`.  
- **Balance Factor** of root (`20`):  
  `Height of left - Height of right = 2 - 2 = 0`.  

The tree is balanced, so no rotation is needed.

---

### Final Tree After All Insertions
The final AVL tree after inserting all nodes (`10`, `20`, `30`, `15`, `25`) is:
```
      20
     /  \
   10    30
  /  \   /  \
NULL 15 25  NULL
      / \ / \
   NULL NULL NULL NULL
```

### How AVL Maintains Balance During Insertions:
1. After each insertion, calculate the height and balance factor of all nodes from the newly inserted node back to the root.
2. Apply rotations to fix any imbalance (when balance factor is not in `[-1, 0, 1]`).
