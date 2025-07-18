### **What is a Binary Tree?**

A **binary tree** is a type of hierarchical data structure in which each node has at most **two children**. These children are referred to as the **left child** and the **right child**.

---

### **Key Characteristics of a Binary Tree**
1. **Root Node**: The topmost node of the tree.
2. **Children**: Each node can have zero, one, or two children.
3. **Leaf Nodes**: Nodes that do not have any children.
4. **Height**: The number of edges on the longest path from the root to a leaf.
5. **Depth**: The number of edges from the root to a specific node.

---

### **Types of Binary Trees**
1. **Full Binary Tree**: Every node has either 0 or 2 children.
2. **Complete Binary Tree**: All levels are completely filled except possibly the last, and all nodes are as far left as possible.
3. **Perfect Binary Tree**: All internal nodes have two children, and all leaf nodes are at the same level.
4. **Balanced Binary Tree**: The height difference between the left and right subtrees of any node is at most 1.
5. **Binary Search Tree (BST)**: A binary tree where the left subtree contains nodes with values less than the parent, and the right subtree contains nodes with values greater than the parent.

---

### **Visualization of a Binary Tree**

Example of a binary tree:

```
         10
       /    \
      5      15
     / \    /  \
    3   7  12   18
```

- **Root Node**: 10
- **Left Subtree**: Rooted at 5
- **Right Subtree**: Rooted at 15
- **Leaf Nodes**: 3, 7, 12, 18

---

### **Applications of Binary Trees**
1. **Binary Search Tree (BST)**: Used for efficient searching, insertion, and deletion.
2. **Heap**: A binary tree used in priority queues.
3. **Expression Trees**: Represent mathematical expressions.
4. **Decision Trees**: Used in machine learning for classification and regression.
5. **File Systems**: Organize hierarchical data.

---

### **Binary Tree Operations**
1. **Traversal**: Visiting all nodes in a specific order.
   - **Inorder Traversal**: Left → Root → Right
   - **Preorder Traversal**: Root → Left → Right
   - **Postorder Traversal**: Left → Right → Root
   - **Level Order Traversal**: Visit nodes level by level.

2. **Insertion**: Add a new node to the tree.
3. **Deletion**: Remove a node while maintaining the tree's properties.
4. **Search**: Find a node with a specific value.

---

### **Binary Tree Example in C**

```c
#include <stdio.h>
#include <stdlib.h>

// Define a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Inorder Traversal (Left, Root, Right)
void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Main function
int main() {
    // Create the binary tree
    struct Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->left = createNode(12);
    root->right->right = createNode(18);

    // Print the tree using inorder traversal
    printf("Inorder Traversal: ");
    inorderTraversal(root);

    return 0;
}
```

---

### **Output**
```
Inorder Traversal: 3 5 7 10 12 15 18
```

---

### **Real-World Example**
Consider a **binary search tree** representing a phonebook:
- Each node contains a name and phone number.
- Searching for a name involves comparing it with the current node and moving left (smaller names) or right (larger names).

Binary trees are versatile and widely used for efficient data organization and manipulation.


---
---
---


Here’s how different types of binary trees can be visualized in a similar way:

---

### **1. Full Binary Tree**
Every node has either 0 or 2 children:
```
         10
       /    \
      5      15
     / \    /  \
    3   7  12   18
```

---

### **2. Complete Binary Tree**
All levels are completely filled except possibly the last, which is filled from left to right:
```
         10
       /    \
      5      15
     / \    /  
    3   7  12  
```

---

### **3. Perfect Binary Tree**
All internal nodes have two children, and all leaf nodes are at the same level:
```
         10
       /    \
      5      15
     / \    /  \
    3   7  12   18
```

---

### **4. Balanced Binary Tree**
The height difference between left and right subtrees is minimal:
```
         10
       /    \
      5      15
     / \    /  
    3   7  12  
```

---

### **5. Binary Search Tree (BST)**
For every node, the left subtree contains values smaller, and the right subtree contains values larger:
```
         10
       /    \
      5      15
     / \    /  \
    3   7  12   18
```



Here are additional examples of binary tree types with variations and explanations:

---

### **6. Degenerate (or Pathological) Tree**
A tree where each parent node has only one child, effectively behaving like a linked list:
```
         10
           \
            15
              \
               20
                 \
                  25
```

---

### **7. Skewed Binary Tree**
A tree that is unbalanced and leans entirely to one side:
- **Left-Skewed Tree**:
  ```
         10
        /
       5
      /
     3
    /
   1
  ```
- **Right-Skewed Tree**:
  ```
         10
           \
            15
              \
               20
                 \
                  25
  ```

---

### **8. Complete Binary Tree (Alternate Example)**
This is another example of a complete binary tree where the last level is partially filled from left to right:
```
         1
       /   \
      2     3
     / \   /
    4   5 6
```

---

### **9. Balanced Binary Tree (Alternate Example)**
A balanced binary tree with minimal height difference between subtrees:
```
         8
       /   \
      4     12
     / \   /  \
    2   6 10  14
```

---

### **10. Perfect Binary Tree (Alternate Example)**
A perfect binary tree with all leaf nodes at the same level and internal nodes having two children:
```
         1
       /   \
      2     3
     / \   / \
    4   5 6   7
```

---

### **11. Binary Search Tree (BST) with Unique Keys**
A BST showing how insertion works to maintain the property:
```
         50
       /    \
      30     70
     / \    /  \
    20  40 60   80
```

---

### **12. Expression Tree**
A binary tree used to represent mathematical expressions:
```
         +
       /   \
      *     -
     / \   / \
    a   b c   d
```
This tree represents the expression: `(a * b) + (c - d)`

---

### **13. Huffman Tree**
A special binary tree used in data compression:
```
         *
       /   \
      *     c:5
     / \
    a:2 b:3
```
This tree shows frequency-based character encoding.

---

### **14. AVL Tree**
A self-balancing binary search tree:
```
         30
       /    \
      20     40
     / \       \
    10  25      50
```

---

### **15. Heap**
- **Max-Heap**: Parent nodes are greater than their children:
  ```
         50
       /    \
      30     40
     / \    /
    10  20 35
  ```
- **Min-Heap**: Parent nodes are smaller than their children:
  ```
         10
       /    \
      20     15
     / \    /
    30  25 35
  ```


Here are examples of trees that **do not match** any of the binary tree types previously mentioned:

---

### **1. Tree That Is Not a Full Binary Tree**
A **full binary tree** requires that every node has either 0 or 2 children. This tree does not meet that criterion because node 5 has only one child.

```
         10
       /    \
      5      15
     /
    3
```

---

### **2. Tree That Is Not a Complete Binary Tree**
A **complete binary tree** requires that all levels are completely filled except possibly the last, which must be filled from left to right. This tree does not meet that criterion because the second level is not completely filled.

```
         10
       /    \
      5      15
     /  
    3
```

---

### **3. Tree That Is Not a Perfect Binary Tree**
A **perfect binary tree** requires that all internal nodes have two children and all leaf nodes are at the same level. This tree does not meet that criterion because node 5 only has one child.

```
         10
       /    \
      5      15
     / 
    3
```

---

### **4. Tree That Is Not a Balanced Binary Tree**
A **balanced binary tree** requires that the height difference between the left and right subtrees of any node is minimal. This tree is unbalanced because the left subtree of node 10 has a height of 2, while the right subtree has a height of 0.

```
         10
       /    
      5     
     / 
    3
```

---

### **5. Tree That Is Not a Binary Search Tree (BST)**
A **binary search tree (BST)** requires that for each node, the left subtree contains values smaller than the node, and the right subtree contains values greater than the node. This tree is not a BST because node 15 is on the left of node 10, violating the BST property.

```
         10
       /    \
     15      20
    /  \
   5    8
```

---

### **6. Tree That Is Not a Degenerate Tree**
A **degenerate (or pathological) tree** behaves like a linked list, where each node has only one child. This tree has nodes with two children, so it is not degenerate.

```
         10
       /    \
      5      15
     / \    /  \
    3   7  12   18
```

---

### **7. Tree That Is Not a Skewed Tree**
A **skewed tree** is one where all nodes are on one side (either left or right). This tree is neither left-skewed nor right-skewed because it has a balanced structure with nodes on both sides.

```
         10
       /    \
      5      15
     / \    /  \
    3   7  12   18
```

---

### **8. Tree That Is Not a Heap**
A **heap** (max-heap or min-heap) requires that the parent node is either greater (max-heap) or smaller (min-heap) than its children. This tree does not follow the heap property because node 15 is greater than its parent node 10.

```
         10
       /    \
      15     5
     /  \
    7    3
```
