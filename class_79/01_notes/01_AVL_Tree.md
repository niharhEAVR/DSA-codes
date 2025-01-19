### **AVL Tree in DSA**

An **AVL tree** is a **self-balancing binary search tree (BST)**, where the difference between the heights of the left and right subtrees of any node (called the **balance factor**) is at most 1. This property ensures that the tree remains balanced, which in turn guarantees that operations like search, insertion, and deletion are efficient, with a time complexity of **O(log n)**, where `n` is the number of nodes in the tree.

### **Properties of an AVL Tree**
1. **Binary Search Tree Property**: Like any BST, for every node:
   - The left subtree contains nodes with values **smaller** than the node.
   - The right subtree contains nodes with values **greater** than the node.
   
2. **Balance Factor**: The balance factor of a node is the difference between the height of the left subtree and the height of the right subtree. For a node `N`:
   - Balance Factor = Height of Left Subtree - Height of Right Subtree
   - The balance factor must be **-1, 0, or 1** for every node.
   - If the balance factor is **greater than 1** or **less than -1**, the tree is unbalanced and requires rebalancing.

3. **Height of the Tree**: The height of an AVL tree is **logarithmic** in terms of the number of nodes, ensuring efficient operations.

### **Rotations in AVL Tree**

To maintain the balance factor within the range of `-1`, `0`, or `1`, AVL trees use **rotations** when inserting or deleting nodes. There are four types of rotations:
1. **Left Rotation (Single Rotation)**
2. **Right Rotation (Single Rotation)**
3. **Left-Right Rotation (Double Rotation)**
4. **Right-Left Rotation (Double Rotation)**

### **AVL Tree Operations**

1. **Insertion**: When inserting a node, we follow the standard BST insertion rules. After inserting the node, we check the balance factor of each node from the inserted node up to the root. If any node becomes unbalanced, we perform the necessary rotation to restore the balance.

2. **Deletion**: After deleting a node, we check the balance factors of the ancestors of the deleted node. If any ancestor becomes unbalanced, we perform the necessary rotation to restore the balance.

3. **Rotation**: A rotation is used to fix the imbalance of the tree. There are four types of rotations:
   - **Left Rotation**: Used when the right subtree is taller than the left subtree.
   - **Right Rotation**: Used when the left subtree is taller than the right subtree.
   - **Left-Right Rotation**: A combination of a left rotation followed by a right rotation, used when the left subtree of the right child is taller.
   - **Right-Left Rotation**: A combination of a right rotation followed by a left rotation, used when the right subtree of the left child is taller.

### **C Code for AVL Tree**

Here's a basic implementation of an AVL tree in C with insertion and rotations:

```c
#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;  // New node is initially at height 1
    return newNode;
}

// Function to get the height of a node
int height(struct Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to get the balance factor of a node
int getBalance(struct Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Right Rotation (Single Rotation)
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    return x;  // New root
}

// Left Rotation (Single Rotation)
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    return y;  // New root
}

// Function to insert a node into the AVL tree
struct Node* insert(struct Node* node, int data) {
    // 1. Perform the normal BST insertion
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;  // Duplicate values are not allowed

    // 2. Update the height of this ancestor node
    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));

    // 3. Get the balance factor to check whether this node became unbalanced
    int balance = getBalance(node);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case (Right Rotation)
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Right Right Case (Left Rotation)
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Left Right Case (Left-Right Rotation)
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case (Right-Left Rotation)
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the (unchanged) node pointer
    return node;
}

// Function to print the tree (Inorder Traversal)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main function to test the AVL tree
int main() {
    struct Node* root = NULL;

    // Insert nodes
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 15);
    root = insert(root, 25);

    // Print the inorder traversal of the AVL tree
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    return 0;
}
```

### **Explanation of the Code:**

1. **Node Structure**:
   - `data`: The value stored in the node.
   - `left` and `right`: Pointers to the left and right children.
   - `height`: The height of the node (used to calculate the balance factor).

2. **Height Function**:
   - Returns the height of a node. If the node is `NULL`, it returns `0`.

3. **Balance Factor Function**:
   - Returns the balance factor of a node, which is the difference between the heights of the left and right subtrees.

4. **Rotations**:
   - **Right Rotation**: Used when the left subtree is too tall.
   - **Left Rotation**: Used when the right subtree is too tall.
   - **Left-Right and Right-Left Rotations**: These are double rotations that are used when there is an imbalance in the left or right subtree of the opposite side.

5. **Insert Function**:
   - First, it performs the standard BST insertion.
   - After insertion, it updates the height of the node.
   - It then checks the balance factor of the node. If the balance factor is outside the range of `-1` to `1`, it performs the appropriate rotation to restore balance.

6. **Inorder Traversal**:
   - This function prints the tree in **ascending order** (since it's a BST).

### **Example Output:**
For the input sequence of insertions: `10, 20, 30, 15, 25`

The output will be:
```
Inorder Traversal: 10 15 20 25 30
```

### **Time Complexity**:
- **Insertion**: O(log n), because the tree is balanced and the height is logarithmic.
- **Rotation**: O(1), since rotations only involve a constant number of operations.

### **Conclusion**:
An **AVL tree** is a self-balancing binary search tree where the balance factor of every node is maintained to ensure efficient operations. The **insert** function ensures that the tree remains balanced by performing rotations when necessary, resulting in O(log n) time complexity for operations.


---
---
---


To help visualize how an **AVL Tree** works, let's go through a few steps of **insertion** and **rotation** with an example.

### **Example: Inserting Nodes into an AVL Tree**

We'll insert the following nodes in sequence: **10, 20, 30, 15, 25**.

#### **Step 1: Insert 10**
- The tree is initially empty. Insert `10` as the root.
  
```
    10
```

#### **Step 2: Insert 20**
- `20` is greater than `10`, so it goes to the right of `10`.

```
    10
     \
     20
```

- The balance factor of node `10` is `-1` (left height = 0, right height = 1). This is acceptable, so no rotation is needed.

#### **Step 3: Insert 30**
- `30` is greater than both `10` and `20`, so it goes to the right of `20`.

```
    10
     \
     20
       \
       30
```

- The balance factor of node `10` is `-2` (left height = 0, right height = 2), which is **out of balance**. This requires a **left rotation** on node `10`.

**Left Rotation on 10**:

After the left rotation, `20` becomes the new root, and `10` becomes the left child of `20`.

```
    20
   /  \
  10   30
```

- Now, the balance factors are:
  - Node `20`: Balance factor = 0 (left height = 1, right height = 1)
  - Node `10`: Balance factor = 0 (no children)
  - Node `30`: Balance factor = 0 (no children)

This is a balanced tree.

#### **Step 4: Insert 15**
- `15` is greater than `10` but less than `20`, so it goes to the right of `10`.

```
    20
   /  \
  10   30
    \
    15
```

- The balance factor of node `10` is `-1` (left height = 0, right height = 1), which is acceptable.
- The balance factor of node `20` is `0` (left height = 2, right height = 1), which is also acceptable.

No rotations are needed.

#### **Step 5: Insert 25**
- `25` is greater than `20` but less than `30`, so it goes to the left of `30`.

```
    20
   /  \
  10   30
    \  /
    15 25
```

- The balance factor of node `30` is `1` (left height = 1, right height = 0), which is acceptable.
- The balance factor of node `20` is `0` (left height = 2, right height = 2), which is also acceptable.

No rotations are needed.

### **Final AVL Tree Visualization:**

```
    20
   /  \
  10   30
    \  /
    15 25
```

### **Recap of Rotations**:

- After inserting `30`, the tree became unbalanced at node `10` (balance factor = -2). We performed a **left rotation** on node `10` to restore balance.
- No further rotations were required after inserting `15` and `25` because the tree remained balanced.

### **Balance Factor Summary**:
- The balance factor of a node is the difference between the heights of its left and right subtrees.
  - **Balance Factor = Height of Left Subtree - Height of Right Subtree**
  - A balance factor of `-1`, `0`, or `1` is acceptable.
  - A balance factor of `-2` or `2` indicates that the tree is unbalanced and requires a rotation.

---

This process ensures that the tree remains balanced and allows for efficient operations like search, insertion, and deletion, all of which run in **O(log n)** time complexity due to the tree being balanced.