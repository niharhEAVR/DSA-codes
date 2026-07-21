Now this is 🔥 **top-tier interview concept** —
**All 3 traversals (Pre, In, Post) in ONE traversal using ONE stack**

---

# 🌳 Goal

👉 In **one pass**, get:

```text
Preorder  → Root Left Right
Inorder   → Left Root Right
Postorder → Left Right Root
```

---

# 🧠 Core Idea (VERY IMPORTANT)

👉 We simulate recursion manually using a stack

```text
Each node will be visited 3 times:
1st time → Preorder
2nd time → Inorder
3rd time → Postorder
```

---

# 🔑 Trick: Use a Pair

```cpp
stack<pair<Node*, int>> st;
```

👉 `int` = state of node

| State | Meaning        |
| ----- | -------------- |
| 1     | Preorder time  |
| 2     | Inorder time   |
| 3     | Postorder time |

---

# 🌳 Example Tree

```text
        1
      /   \
     2     3
    / \   /
   4   5 6
```

---

# 💻 Code (VERY IMPORTANT)

```cpp
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
```

---

# 🌳 Tree Used in Your Code

```
        1
       / \
      2   3
     / \
    4   5
```

---

# 🧠 Core Idea (VERY IMPORTANT)

Each node is visited **3 times**, controlled by `state`:

| State | Meaning         | Action    |
| ----- | --------------- | --------- |
| 1     | First time seen | Preorder  |
| 2     | Second time     | Inorder   |
| 3     | Third time      | Postorder |

---

# 📦 Stack Stores

```
stack<pair<Node*, state>>
```

Example:

```
(1,1) → Node 1, first visit
```

---

# 🚀 Initial Step

```
Stack: [(1,1)]
```

---

# 🔍 FULL DRY RUN (STEP BY STEP)

---

## 👉 Step 1

Pop:

```
(1,1)
```

👉 State 1 → Preorder

```
Pre: [1]
```

Push:

```
(1,2)
(2,1)
```

Stack:

```
TOP → (2,1)
       (1,2)
```

---

## 👉 Step 2

Pop:

```
(2,1)
```

👉 Preorder

```
Pre: [1,2]
```

Push:

```
(2,2)
(4,1)
```

Stack:

```
TOP → (4,1)
       (2,2)
       (1,2)
```

---

## 👉 Step 3

Pop:

```
(4,1)
```

👉 Preorder

```
Pre: [1,2,4]
```

Push:

```
(4,2)
```

Stack:

```
TOP → (4,2)
       (2,2)
       (1,2)
```

---

## 👉 Step 4

Pop:

```
(4,2)
```

👉 Inorder

```
In: [4]
```

Push:

```
(4,3)
```

Stack:

```
TOP → (4,3)
       (2,2)
       (1,2)
```

---

## 👉 Step 5

Pop:

```
(4,3)
```

👉 Postorder

```
Post: [4]
```

Stack:

```
TOP → (2,2)
       (1,2)
```

---

## 👉 Step 6

Pop:

```
(2,2)
```

👉 Inorder

```
In: [4,2]
```

Push:

```
(2,3)
(5,1)
```

Stack:

```
TOP → (5,1)
       (2,3)
       (1,2)
```

---

## 👉 Step 7

Pop:

```
(5,1)
```

👉 Preorder

```
Pre: [1,2,4,5]
```

Push:

```
(5,2)
```

Stack:

```
TOP → (5,2)
       (2,3)
       (1,2)
```

---

## 👉 Step 8

Pop:

```
(5,2)
```

👉 Inorder

```
In: [4,2,5]
```

Push:

```
(5,3)
```

Stack:

```
TOP → (5,3)
       (2,3)
       (1,2)
```

---

## 👉 Step 9

Pop:

```
(5,3)
```

👉 Postorder

```
Post: [4,5]
```

Stack:

```
TOP → (2,3)
       (1,2)
```

---

## 👉 Step 10

Pop:

```
(2,3)
```

👉 Postorder

```
Post: [4,5,2]
```

Stack:

```
TOP → (1,2)
```

---

## 👉 Step 11

Pop:

```
(1,2)
```

👉 Inorder

```
In: [4,2,5,1]
```

Push:

```
(1,3)
(3,1)
```

Stack:

```
TOP → (3,1)
       (1,3)
```

---

## 👉 Step 12

Pop:

```
(3,1)
```

👉 Preorder

```
Pre: [1,2,4,5,3]
```

Push:

```
(3,2)
```

Stack:

```
TOP → (3,2)
       (1,3)
```

---

## 👉 Step 13

Pop:

```
(3,2)
```

👉 Inorder

```
In: [4,2,5,1,3]
```

Push:

```
(3,3)
```

Stack:

```
TOP → (3,3)
       (1,3)
```

---

## 👉 Step 14

Pop:

```
(3,3)
```

👉 Postorder

```
Post: [4,5,2,3]
```

Stack:

```
TOP → (1,3)
```

---

## 👉 Step 15

Pop:

```
(1,3)
```

👉 Postorder

```
Post: [4,5,2,3,1]
```

Stack:

```
EMPTY ✅
```

---

# 🎯 FINAL OUTPUT

```
Preorder:  1 2 4 5 3
Inorder:   4 2 5 1 3
Postorder: 4 5 2 3 1
```

---

# 🔥 KEY INSIGHT (MOST IMPORTANT)

Instead of recursion:

```
function(node):
   process
   left
   right
```

👉 We simulate it using:

```
(node, state)
```

| State | What recursion would do |
| ----- | ----------------------- |
| 1     | Before left call        |
| 2     | Between left & right    |
| 3     | After right             |

---

# 💡 WHY THIS IS POWERFUL

✅ Only **one stack**
✅ Only **one traversal loop**
✅ Gives **all 3 traversals together**
❌ Slightly complex to understand (but now you're good 😄)
