To check whether a binary tree is a **Binary Search Tree (BST)**, we need to ensure that for every node:

1. All nodes in its left subtree have values smaller than the node's value.
2. All nodes in its right subtree have values greater than the node's value.
3. The left and right subtrees must also be BSTs.

### **Approach to Check if a Tree is a BST**

We can perform this check using **inorder traversal** or a **recursive approach** with range limits. The key idea is to traverse the tree and at each node, ensure that the node's value lies within the valid range (defined by its ancestors).

- **Inorder Traversal Method**: In an inorder traversal of a BST, the nodes' values should be visited in **ascending order**. If we find any value that is not in ascending order, the tree is not a BST.
  
- **Recursive Method**: This method checks whether each node's value lies within a valid range. For each node:
  - The left subtree must have values strictly less than the node's value.
  - The right subtree must have values strictly greater than the node's value.
  
### **C Code to Check if a Binary Tree is a BST**

Here’s the C code to check whether a given binary tree is a BST:

```c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define a node structure for the tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to check if a binary tree is a BST
int isBST(struct Node* root, int min, int max) {
    // Base case: If the tree is empty, it's a BST
    if (root == NULL)
        return 1;

    // Check if the current node's value is within the valid range
    if (root->data <= min || root->data >= max)
        return 0;

    // Recursively check the left and right subtrees with updated ranges
    return isBST(root->left, min, root->data) && isBST(root->right, root->data, max);
}

// Main function to test the BST check
int main() {
    struct Node* root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    root->right->left = createNode(60);
    root->right->right = createNode(80);

    // Check if the tree is a BST
    if (isBST(root, INT_MIN, INT_MAX))
        printf("The tree is a Binary Search Tree (BST).\n");
    else
        printf("The tree is NOT a Binary Search Tree (BST).\n");

    return 0;
}
```

### **Explanation of the Code**

1. **Node Structure**: The `struct Node` defines each node of the tree, containing:
   - `data`: The value of the node.
   - `left`: Pointer to the left child node.
   - `right`: Pointer to the right child node.

2. **`isBST` Function**:
   - This function checks whether the binary tree rooted at `root` is a BST.
   - It uses two parameters, `min` and `max`, to track the valid range for the current node's value. Initially, `min` is set to `INT_MIN` and `max` to `INT_MAX`.
   - The function checks if the current node's value is within the valid range (`min < node->data < max`). If it is, it recursively checks the left and right subtrees, updating the range for each subtree:
     - The left subtree should have values less than the current node's value.
     - The right subtree should have values greater than the current node's value.

3. **Main Function**:
   - Creates a sample binary tree.
   - Calls the `isBST` function to check if the tree is a BST.

### **Sample Output**

For the tree:
```
         50
       /    \
      30     70
     / \    /  \
    20  40 60   80
```

The output will be:
```
The tree is a Binary Search Tree (BST).
```

If you modify the tree to break the BST property, like changing the value of the left child of `70` to `90`, the output will be:
```
The tree is NOT a Binary Search Tree (BST).
```

### **Time Complexity**

- **Time Complexity**: O(n), where `n` is the number of nodes in the tree. This is because we visit each node once.
- **Space Complexity**: O(h), where `h` is the height of the tree. This is the space used by the recursion stack in the worst case (for a skewed tree, `h` could be `n`).

### **Conclusion**
This method efficiently checks whether a binary tree satisfies the properties of a Binary Search Tree by recursively validating the range of each node’s value. If any node violates the BST property, the function returns `0`, indicating that the tree is not a BST.