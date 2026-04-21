// #include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <queue>
// #include <unordered_map>
// #include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Optimal Approach
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> result;
    if(root == nullptr) return result;

    queue<TreeNode*> q;
    q.push(root);
    bool flag = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode* node = q.front();
            q.pop();
            if(node->left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
            int index = flag == true ? i : size-1-i;
            level[index] = node->val;
            
        }
        flag = !flag;
        result.push_back(level);
    }
    return result;
}
//   TC=O(n), SC=O(n)

int main()
{

    return 0;
}