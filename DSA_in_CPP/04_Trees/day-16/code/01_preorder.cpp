// #include <bits/stdc++.h>

#include <iostream>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

void deleteTree(TreeNode* root)
{
    if (root == NULL)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void preorder(TreeNode *root)
{
    if (root == NULL)
        return;

    std::cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->left->left = new TreeNode(9);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(4);

    std::cout << "Preorder Traversal: ";
    preorder(root);

    // Free memory
    deleteTree(root);

    return 0;
}