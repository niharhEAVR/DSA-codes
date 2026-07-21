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
class Solution
{
public:
    vector<int> verticalTraversal(TreeNode *root)
    {
        map<int, int> nodes;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();

            TreeNode *node = front.first;
            int hd = front.second;

            nodes[hd] = node->val;

            if (node->left)
                q.push({node->left, hd - 1});

            if (node->right)
                q.push({node->right, hd + 1});
        }

        vector<int> ans;
        for (auto p : nodes)
        {
            ans.push_back(p.second);
        }
        return ans;
    }
};