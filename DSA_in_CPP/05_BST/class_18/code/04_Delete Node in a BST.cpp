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
    TreeNode* findMin(TreeNode* root) {
        while (root->left!=nullptr) {
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;

        if(root->val > key ){
            root->left = deleteNode(root->left,key);
        }else if(root->val < key){
            root->right = deleteNode(root->right,key);
        }else{
            if(root->left == nullptr && root->right == nullptr){
                return nullptr;
            }else if(root->left == nullptr || root->right == nullptr){
                if(root->left != nullptr) return root->left;
                else return root->right;
            }else{
                TreeNode* succ = findMin(root->right);
                root->val = succ->val;
                root->right = deleteNode(root->right, succ->val);
            }
        }
        return root;
    }
};