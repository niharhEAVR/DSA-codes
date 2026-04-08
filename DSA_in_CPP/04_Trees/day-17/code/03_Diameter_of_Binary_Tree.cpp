/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root, int *balanced){
        if(root == nullptr) return 0;
        int lh = helper(root->left, balanced);
        int rh = helper(root->right, balanced);
        *balanced = max(*balanced, (lh+rh));
        return 1+max(lh,rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int balanced{};
        helper(root, &balanced);
        return balanced;
    }
};