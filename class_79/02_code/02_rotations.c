#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the AVL Tree
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

// Function to get the height of a node
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

// Function to get the balance factor of a node
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Function to perform a right rotation
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    // Return new root
    return x;
}

// Function to perform a left rotation
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    // Return new root
    return y;
}

// Function to perform a left-right rotation
struct Node *leftRightRotate(struct Node *node)
{
    node->left = leftRotate(node->left);
    return rightRotate(node);
}

// Function to perform a right-left rotation
struct Node *rightLeftRotate(struct Node *node)
{
    node->right = rightRotate(node->right);
    return leftRotate(node);
}

// Function to create a new node
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1; // New node is initially at height 1
    return node;
}

// Function to insert a node into the AVL tree
struct Node *insert(struct Node *node, int data)
{
    // 1. Perform the normal BST insert
    if (node == NULL)
        return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node; // Duplicate data is not allowed

    // 2. Update the height of this ancestor node
    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));

    // 3. Get the balance factor to check whether this node became unbalanced
    int balance = getBalance(node);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && data > node->left->data)
        return leftRightRotate(node);

    // Right Left Case
    if (balance < -1 && data < node->right->data)
        return rightLeftRotate(node);

    // Return the (unchanged) node pointer
    return node;
}

// Function to print the tree (in-order traversal)
void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Main function to test the AVL tree
int main()
{
    struct Node *root = NULL;

    // Insert nodes into the AVL tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 15);
    root = insert(root, 25);

    // Print the in-order traversal of the AVL tree
    printf("In-order traversal of the AVL tree: ");
    inOrder(root);

    return 0;
}
