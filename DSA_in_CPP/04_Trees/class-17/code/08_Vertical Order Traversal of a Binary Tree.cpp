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
    // void dfs(TreeNode* root, int row, int col,
    //          vector<tuple<int, int, int>>& nodes) {
    //     if (!root)
    //         return;
    //     nodes.push_back({col, row, root->val});
    //     dfs(root->left, row + 1, col - 1, nodes);
    //     dfs(root->right, row + 1, col + 1, nodes);
    // }
    // vector<vector<int>> verticalTraversal(TreeNode* root) {
    //     vector<tuple<int, int, int>> nodes;
    //     dfs(root, 0, 0, nodes);
    //     sort(nodes.begin(), nodes.end());
    //     vector<vector<int>> ans;
    //     int prev_col = INT_MIN;
    //     for (auto& [col, row, val] : nodes) {
    //         if (col != prev_col) {
    //             ans.push_back({});
    //             prev_col = col;
    //         }
    //         ans.back().push_back(val);
    //     }
    //     return ans;
    // }

    /* another approach: */

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;

        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            TreeNode* node = front.first;
            int row = front.second.first;
            int col = front.second.second;

            nodes[col][row].insert(node->val);

            if (node->left)
                q.push({node->left, {row + 1, col - 1}});

            if (node->right)
                q.push({node->right, {row + 1, col + 1}});
        }

        vector<vector<int>> ans;

        for (auto& p : nodes) { // col
            vector<int> colVals;

            for (auto& q : p.second) { // row
                colVals.insert(colVals.end(), q.second.begin(), q.second.end());
            }

            ans.push_back(colVals);
        }

        return ans;
    }
};