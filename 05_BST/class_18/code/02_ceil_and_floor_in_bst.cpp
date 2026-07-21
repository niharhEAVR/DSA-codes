/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution
{
public:
    int floor(TreeNode *root, int key)
    {
        int floori = -1;
        while (root)
        {
            if (root->data == key)
            {
                floori = root->data;
                return floori;
            }
            if (root->data < key)
            {
                floori = root->data;
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }
        return floori;
    }

    int ceil(TreeNode *root, int key)
    {
        int ceili = -1;
        while (root)
        {
            if (root->data == key)
            {
                ceili = root->data;
                return ceili;
            }
            if (root->data < key)
            {
                root = root->right;
            }
            else
            {
                ceili = root->data;
                root = root->left;
            }
        }
        return ceili;
    }

    vector<int> floorCeilOfBST(TreeNode *root, int key)
    {
        vector<int> ans;
        ans.push_back(floor(root, key));
        ans.push_back(ceil(root, key));
        return ans;
    }
};