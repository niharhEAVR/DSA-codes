### **Representation of Binary Tree**

A **binary tree** can be represented in two common ways:

1. **Array Representation**:
   - A binary tree can be represented in an array, where the root node is at index 0, the left child of a node at index `i` is at index `2i + 1`, and the right child is at index `2i + 2`.
   - This representation is useful when the tree is complete and can be used efficiently in algorithms like heaps.

   Example:
   ```
   Binary Tree:
         10
       /    \
      5      15
     / \    /  \
    3   7  12   18

   Array Representation:
   [10, 5, 15, 3, 7, 12, 18]
   ```

2. **Linked Representation**:
   - A binary tree is represented using nodes, where each node contains:
     - **Data**: The value stored in the node.
     - **Left Pointer**: A reference to the left child node.
     - **Right Pointer**: A reference to the right child node.
   - This representation is more flexible and allows the tree to grow dynamically, unlike the array representation which requires a fixed size.

   Example (in C):
   ```c
   struct Node {
       int data;
       struct Node* left;
       struct Node* right;
   };
   ```

---

### **Linked Representation of Binary Tree**

In the **linked representation**, each node of the binary tree is represented by a structure (or class in object-oriented programming) containing:
- The **data** stored in the node.
- A **left pointer** (or reference) pointing to the left child node.
- A **right pointer** (or reference) pointing to the right child node.

For example, in C:
```c
#include <stdio.h>
#include <stdlib.h>

// Define a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
```

---

### **Traversal in Binary Tree**

Traversal refers to visiting all the nodes in a binary tree in a specific order. There are several types of tree traversal:

1. **Inorder Traversal**: Visit the left subtree, then the root, then the right subtree.
   - **Order**: Left → Root → Right
2. **Preorder Traversal**: Visit the root first, then the left subtree, and finally the right subtree.
   - **Order**: Root → Left → Right
3. **Postorder Traversal**: Visit the left subtree, then the right subtree, and finally the root.
   - **Order**: Left → Right → Root
4. **Level Order Traversal**: Visit nodes level by level, from top to bottom.

---

### **Preorder Traversal**

In **preorder traversal**, the nodes are visited in the following order:
- **Root**
- **Left Subtree**
- **Right Subtree**

Example of Preorder Traversal:
For the binary tree:
```
         10
       /    \
      5      15
     / \    /  \
    3   7  12   18
```
The preorder traversal would be:
```
10 → 5 → 3 → 7 → 15 → 12 → 18
```

**C Code for Preorder Traversal**:
```c
void preorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);  // Visit the root
    preorderTraversal(root->left);  // Traverse left subtree
    preorderTraversal(root->right);  // Traverse right subtree
}
```

---

### **Postorder Traversal**

In **postorder traversal**, the nodes are visited in the following order:
- **Left Subtree**
- **Right Subtree**
- **Root**

Example of Postorder Traversal:
For the binary tree:
```
         10
       /    \
      5      15
     / \    /  \
    3   7  12   18
```
The postorder traversal would be:
```
3 → 7 → 5 → 12 → 18 → 15 → 10
```

**C Code for Postorder Traversal**:
```c
void postorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    postorderTraversal(root->left);  // Traverse left subtree
    postorderTraversal(root->right);  // Traverse right subtree
    printf("%d ", root->data);  // Visit the root
}
```

---

### **Summary of Traversals**

| Traversal Type     | Order of Visit            | Example (For Tree: 10, 5, 15, 3, 7, 12, 18) |
|--------------------|---------------------------|-----------------------------------------------|
| **Preorder**       | Root → Left → Right       | 10 → 5 → 3 → 7 → 15 → 12 → 18                |
| **Inorder**        | Left → Root → Right       | 3 → 5 → 7 → 10 → 12 → 15 → 18                |
| **Postorder**      | Left → Right → Root       | 3 → 7 → 5 → 12 → 18 → 15 → 10                |
| **Level Order**    | Level by Level (Top to Bottom) | 10 → 5 → 15 → 3 → 7 → 12 → 18             |

These are the fundamental concepts and examples of binary tree representation and traversal methods. Let me know if you need further clarification!