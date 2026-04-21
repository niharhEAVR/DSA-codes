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

TreeNode *buildTree(vector<string> &arr)
{
	if (arr.size() == 0 || arr[0] == "null")
		return NULL;

	TreeNode *root = new TreeNode(stoi(arr[0]));
	queue<TreeNode *> q;
	q.push(root);

	int i = 1;

	while (!q.empty() && i < arr.size())
	{
		TreeNode *curr = q.front();
		q.pop();

		// Left child
		if (i < arr.size() && arr[i] != "null")
		{
			curr->left = new TreeNode(stoi(arr[i]));
			q.push(curr->left);
		}
		i++;

		// Right child
		if (i < arr.size() && arr[i] != "null")
		{
			curr->right = new TreeNode(stoi(arr[i]));
			q.push(curr->right);
		}
		i++;
	}

	return root;
}

void traverse(std::vector<int> &nums)
{
	std::cout << "[ ";
	for (auto it = nums.begin(); it != nums.end(); it++)
	{
		it + 1 == nums.end() ? std::cout << *it << " " : std::cout << *it << ", ";
	}
	std::cout << "]";
}

bool isLeaf(TreeNode *node)
{
	return (node->left == NULL && node->right == NULL);
}

void addLeftBoundary(TreeNode *root, vector<int> &res)
{
	TreeNode *curr = root->left;
	while (curr)
	{
		if (!isLeaf(curr))
			res.push_back(curr->val);
		if (curr->left)
			curr = curr->left;
		else
			curr = curr->right;
	}
}

void addLeaves(TreeNode *root, vector<int> &res)
{
	if (root == nullptr)
		return;
	addLeaves(root->left, res);
	addLeaves(root->right, res);
	if (isLeaf(root))
		res.push_back(root->val);
}

void addRightBoundary(TreeNode *root, vector<int> &res)
{
	vector<int> temp;
	TreeNode *curr = root;
	while (curr)
	{
		if (!isLeaf(curr))
			temp.push_back(curr->val);
		if (curr->right)
			curr = curr->right;
		else
			curr = curr->left;
	}
	for (int i = temp.size() - 1; i >= 0; i--)
	{
		res.push_back(temp[i]);
	}
}

// Optimal Approach
vector<int> optimal(TreeNode *root)
{
	vector<int> res;
	if (root == nullptr)
		return res;
	if (!isLeaf(root))
		res.push_back(root->val);
	addLeftBoundary(root, res);
	addLeaves(root, res);
	addRightBoundary(root->right, res);
	return res;
}
//   TC=O(), SC=O()

int main()
{
	// vector<string> arr = {"1", "2", "null", "4", "9", "6", "5", "3", "null", "null", "null", "null", "null", "7", "8"};

	vector<string> arr = {"1", "2", "3", "4", "5", "6", "7", "null", "null", "8", "9"};

	TreeNode *root = buildTree(arr);

	vector<int> result = optimal(root);
	traverse(result);

	return 0;
}