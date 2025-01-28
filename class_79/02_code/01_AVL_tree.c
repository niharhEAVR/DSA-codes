#include <stdio.h>
#include <stdlib.h>

// Define a node structure
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->height = 1; // New node is initially at height 1
    return newNode;
}

// Function to get the height of a node
int height(Node *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to get the balance factor of a node
int getBalance(Node *node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Right Rotation (Single Rotation)
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    return x; // New root
}

// Left Rotation (Single Rotation)
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    return y; // New root
}

// Function to insert a node into the AVL tree
Node *insert(Node *node, int data)
{
    // 1. Perform the normal BST insertion
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node; // Duplicate values are not allowed

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
    if (balance > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case (Right-Left Rotation)
    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the (unchanged) node pointer
    return node;
}

// Function to print the tree (Inorder Traversal)
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main function to test the AVL tree
int main()
{
    Node *root = NULL;

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
