#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the BST
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

// Function to insert a node in the BST
struct Node* insert(struct Node* root, int data) {
    // If the tree is empty, return a new node
    if (root == NULL)
        return createNode(data);

    // Otherwise, recur down the tree
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    // return the (unchanged) node pointer
    return root;
}

// Function to search a value in the BST
struct Node* search(struct Node* root, int data) {
    // Base case: root is null or data is present at the root
    if (root == NULL || root->data == data)
        return root;

    // Data is greater than root's data, search in the right subtree
    if (data > root->data)
        return search(root->right, data);

    // Data is smaller than root's data, search in the left subtree
    return search(root->left, data);
}

// Function for inorder traversal of the BST (Left, Root, Right)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);  // Traverse left subtree
        printf("%d ", root->data);     // Visit root
        inorderTraversal(root->right); // Traverse right subtree
    }
}

// Function to find the minimum value node in the BST (used for deletion)
struct Node* findMin(struct Node* root) {
    struct Node* current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a node in the BST
struct Node* deleteNode(struct Node* root, int data) {
    // Base case: if the tree is empty
    if (root == NULL)
        return root;

    // Recur down the tree
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        // Node to be deleted is found

        // Case 1: Node has no child (leaf node)
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: Node has one child
        else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Node has two children
        else {
            // Get the inorder successor (smallest in the right subtree)
            struct Node* temp = findMin(root->right);

            // Copy the inorder successor's content to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// Main function to demonstrate the BST operations
int main() {
    struct Node* root = NULL;

    // Insert nodes into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Print inorder traversal of the BST
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Search for a value in the BST
    int searchValue = 40;
    struct Node* searchResult = search(root, searchValue);
    if (searchResult != NULL)
        printf("Node with value %d found in the BST.\n", searchValue);
    else
        printf("Node with value %d not found in the BST.\n", searchValue);

    // Delete a node in the BST
    int deleteValue = 20;
    root = deleteNode(root, deleteValue);
    printf("Inorder Traversal after deletion of %d: ", deleteValue);
    inorderTraversal(root);
    printf("\n");

    return 0;
}