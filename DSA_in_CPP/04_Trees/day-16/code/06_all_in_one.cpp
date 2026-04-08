#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void allTraversal(Node* root) {
    if (root == NULL) return;

    stack<pair<Node*, int>> st;

    vector<int> pre, in, post;

    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        Node* node = it.first;
        int state = it.second;

        // Preorder
        if (state == 1) {
            pre.push_back(node->data);

            st.push({node, 2}); // next state

            if (node->left)
                st.push({node->left, 1});
        }

        // Inorder
        else if (state == 2) {
            in.push_back(node->data);

            st.push({node, 3}); // next state

            if (node->right)
                st.push({node->right, 1});
        }

        // Postorder
        else {
            post.push_back(node->data);
        }
    }

    // Print results
    cout << "Preorder: ";
    for (int x : pre) cout << x << " ";

    cout << "\nInorder: ";
    for (int x : in) cout << x << " ";

    cout << "\nPostorder: ";
    for (int x : post) cout << x << " ";
}

void deleteTree(Node* root) {
    if (root == NULL) return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    allTraversal(root);
    deleteTree(root);

    return 0;
}