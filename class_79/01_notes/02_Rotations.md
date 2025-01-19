oIn an **AVL tree**, rotations are used to maintain balance when the balance factor of a node becomes either greater than 1 or less than -1 after an insertion or deletion. There are **four types of rotations** that can be performed to restore balance:

1. **Left Rotation (Single Rotation)**
2. **Right Rotation (Single Rotation)**
3. **Left-Right Rotation (Double Rotation)**
4. **Right-Left Rotation (Double Rotation)**

### **Balance Factor**:
The **balance factor** of a node is calculated as:
```
Balance Factor = Height of Left Subtree - Height of Right Subtree
```
- If the balance factor is `-1`, `0`, or `1`, the node is balanced.
- If the balance factor is `>1`, it is **left heavy**.
- If the balance factor is `<-1`, it is **right heavy**.

### **Rotations**

---

### **1. Left Rotation (Single Rotation)**

A **Left Rotation** is performed when the right subtree of a node is too tall (balance factor of `-2`), meaning the tree is right-heavy.

#### **Example**: Right-Heavy Tree (balance factor = -2)

Before the rotation:

```
      10
        \
        20
          \
          30
```

- The balance factor of `10` is `-2` (right-heavy), so we need to perform a **left rotation** on node `10`.

**Left Rotation on node 10**:

```
      20
     /  \
    10   30
```

- Now, the tree is balanced.

### **2. Right Rotation (Single Rotation)**

A **Right Rotation** is performed when the left subtree of a node is too tall (balance factor of `2`), meaning the tree is left-heavy.

#### **Example**: Left-Heavy Tree (balance factor = 2)

Before the rotation:

```
      30
     /
    20
   /
  10
```

- The balance factor of `30` is `2` (left-heavy), so we need to perform a **right rotation** on node `30`.

**Right Rotation on node 30**:

```
      20
     /  \
    10   30
```

- Now, the tree is balanced.

### **3. Left-Right Rotation (Double Rotation)**

A **Left-Right Rotation** is needed when the left child of a node is right-heavy. This is a combination of a **left rotation** followed by a **right rotation**.

#### **Example**: Left-Right Heavy Tree

Before the rotation:

```
      30
     /
    10
      \
      20
```

- The balance factor of `30` is `2` (left-heavy), but the balance factor of `10` is `-1` (right-heavy). This requires a **left-right rotation**.

**Step 1: Left Rotation on node 10**:

```
      30
     /
    20
   /
  10
```

**Step 2: Right Rotation on node 30**:

```
      20
     /  \
    10   30
```

- Now, the tree is balanced.

### **4. Right-Left Rotation (Double Rotation)**

A **Right-Left Rotation** is needed when the right child of a node is left-heavy. This is a combination of a **right rotation** followed by a **left rotation**.

#### **Example**: Right-Left Heavy Tree

Before the rotation:

```
      10
        \
        30
       /
      20
```

- The balance factor of `10` is `-2` (right-heavy), but the balance factor of `30` is `1` (left-heavy). This requires a **right-left rotation**.

**Step 1: Right Rotation on node 10**:

```
      30
     /
    10
     \
     20
```

**Step 2: Left Rotation on node 30**:

```
      20
     /  \
    10   30
```

- Now, the tree is balanced.

---

### **Insertion in AVL Tree with Rotations**

Now, let's combine **insertion** and **rotations** with an example. We'll insert nodes and perform the necessary rotations.

#### **Example Insertion Sequence**: Insert **10, 20, 30, 15, 25**

#### **Step 1: Insert 10**

```
    10
```

- The tree is balanced (only one node), so no rotations are needed.

#### **Step 2: Insert 20**

```
    10
     \
     20
```

- The balance factor of `10` is `-1` (right-heavy), which is acceptable. No rotations are needed.

#### **Step 3: Insert 30**

```
    10
     \
     20
       \
       30
```

- The balance factor of `10` is `-2` (right-heavy), so a **left rotation** is needed on node `10`.

**Left Rotation on node 10**:

```
    20
   /  \
  10   30
```

- Now, the tree is balanced.

#### **Step 4: Insert 15**

```
    20
   /  \
  10   30
    \
    15
```

- The balance factor of `10` is `-1` (right-heavy), which is acceptable.
- The balance factor of `20` is `0`, so the tree is balanced.

#### **Step 5: Insert 25**

```
    20
   /  \
  10   30
    \  /
    15 25
```

- The balance factor of `30` is `1` (left-heavy), which is acceptable.
- The balance factor of `20` is `0`, so the tree is balanced.

---

### **Final AVL Tree after Insertions**:

```
    20
   /  \
  10   30
    \  /
    15 25
```

---

### **Summary of Rotations**:

1. **Left Rotation**: Used when the tree is **right-heavy**.
2. **Right Rotation**: Used when the tree is **left-heavy**.
3. **Left-Right Rotation**: Used when the left child is **right-heavy**.
4. **Right-Left Rotation**: Used when the right child is **left-heavy**.

These rotations ensure that the AVL tree remains balanced, keeping the time complexity of operations like search, insertion, and deletion at **O(log n)**.