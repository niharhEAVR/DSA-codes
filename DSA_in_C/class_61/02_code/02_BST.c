#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, int data)
{

    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

Node *search(Node *root, int data)
{

    if (root == NULL || root->data == data)
        return root;

    if (data > root->data)
        return search(root->right, data);

    return search(root->left, data);
}

void inorderTraversal(Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

Node *findMin(Node *root)
{
    Node *current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

Node *deleteNode(Node *root, int data)
{

    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {

        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        else if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        else
        {

            Node *temp = findMin(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int main()
{
    Node *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    int searchValue = 40;
    Node *searchResult = search(root, searchValue);
    if (searchResult != NULL)
        printf("Node with value %d found in the BST.\n", searchValue);
    else
        printf("Node with value %d not found in the BST.\n", searchValue);

    int deleteValue = 20;
    root = deleteNode(root, deleteValue);
    printf("Inorder Traversal after deletion of %d: ", deleteValue);
    inorderTraversal(root);
    printf("\n");

    deleteValue = 70;
    root = deleteNode(root, deleteValue);
    printf("Inorder Traversal after deletion of %d: ", deleteValue);
    inorderTraversal(root);
    printf("\n");

    return 0;
}