# 🌳 What is Level Order Traversal?

👉 It means visiting nodes **level by level**

```
Level 0 → Root
Level 1 → Children of root
Level 2 → Grandchildren
...
```

### Example Tree:

```
        1
      /   \
     2     3
    / \   /
   4   5 6
```

### Output:

```
1 → 2 → 3 → 4 → 5 → 6
```

---

# 🧠 Core Idea (VERY IMPORTANT)

👉 BFS uses a **Queue (FIFO)**

Why?

* We process nodes **in order of arrival**
* First node comes → first processed

---

# ⚙️ Algorithm (Concept First)

### Steps:

1. Create an empty **queue**
2. Push **root node**
3. While queue is not empty:

   * Take front node
   * Print it
   * Push its left child (if exists)
   * Push its right child (if exists)

---

# 🔄 Dry Run (Step-by-step)

### Initial:

```
Queue = [1]
```

---

### Step 1:

* Pop → 1
* Print → 1
* Push → 2, 3

```
Queue = [2, 3]
```

---

### Step 2:

* Pop → 2
* Print → 2
* Push → 4, 5

```
Queue = [3, 4, 5]
```

---

### Step 3:

* Pop → 3
* Print → 3
* Push → 6

```
Queue = [4, 5, 6]
```

---

### Step 4:

* Pop → 4 → print
* Pop → 5 → print
* Pop → 6 → print

```
Final Output: 1 2 3 4 5 6
```

---

# 💻 C++ Code (Clean + Simple)

```cpp
#include <iostream>
#include <queue>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Level Order Traversal (BFS)
void levelOrder(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left != NULL)
            q.push(temp->left);

        if (temp->right != NULL)
            q.push(temp->right);
    }
}

int main() {
    // Creating tree manually
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    levelOrder(root);
}
```

---

# 📦 Key Concepts You Must Remember

### 1. Data Structure Used:

👉 `queue<Node*>`

---

### 2. Why Queue?

| Structure | Behavior | Use |
| --------- | -------- | --- |
| Queue     | FIFO     | BFS |
| Stack     | LIFO     | DFS |

---

### 3. Time Complexity:

```
O(N)
```

👉 Every node visited once

---

### 4. Space Complexity:

```
O(N)
```

👉 Queue stores nodes

---

# 🔥 Important Variations (Very Important for Exams)

### 1. Level-wise printing:

```
1
2 3
4 5 6
```

👉 Use:

* Queue + NULL marker OR
* Queue size method

---

### 2. Zig-Zag Traversal

```
1
3 2
4 5 6
```

---

### 3. Right View / Left View

---

# 🚀 Intuition Summary

👉 Think like this:

> “Process nodes **layer by layer** using a queue”

---
---
---
---


# 🌳 Tree Used in Code

```
        1
      /   \
     2     3
    / \   /
   4   5 6
```

---

# 💻 Code Focus (Main Logic Only)

```cpp
queue<Node*> q;
q.push(root);

while (!q.empty()) {
    Node* temp = q.front();
    q.pop();

    cout << temp->data << " ";

    if (temp->left != NULL)
        q.push(temp->left);

    if (temp->right != NULL)
        q.push(temp->right);
}
```

---

# 🎯 FULL DRY RUN (WITH VISUALS)

---

## 🟢 Step 0: Initialization

```
q = [1]
output = ""
```

👉 Only root is inserted

---

## 🔵 Step 1:

### Before pop:

```
q = [1]
```

### Process:

* temp = 1
* print → 1
* push 2, 3

### After:

```
q = [2, 3]
output = 1
```

---

## 🔵 Step 2:

### Before pop:

```
q = [2, 3]
```

### Process:

* temp = 2
* print → 2
* push 4, 5

### After:

```
q = [3, 4, 5]
output = 1 2
```

---

## 🔵 Step 3:

### Before pop:

```
q = [3, 4, 5]
```

### Process:

* temp = 3
* print → 3
* push 6

### After:

```
q = [4, 5, 6]
output = 1 2 3
```

---

## 🔵 Step 4:

### Before pop:

```
q = [4, 5, 6]
```

### Process:

* temp = 4
* print → 4
* no children

### After:

```
q = [5, 6]
output = 1 2 3 4
```

---

## 🔵 Step 5:

### Before pop:

```
q = [5, 6]
```

### Process:

* temp = 5
* print → 5
* no children

### After:

```
q = [6]
output = 1 2 3 4 5
```

---

## 🔵 Step 6:

### Before pop:

```
q = [6]
```

### Process:

* temp = 6
* print → 6
* no children

### After:

```
q = []
output = 1 2 3 4 5 6
```

---

# 🔥 FINAL OUTPUT

```
1 2 3 4 5 6
```

---

# 🧠 ULTRA IMPORTANT VISUAL INTUITION

Think like this 👇

```
Queue acts like a waiting line:

Step 1: [1]
Step 2: [2, 3]
Step 3: [3, 4, 5]
Step 4: [4, 5, 6]
Step 5: [5, 6]
Step 6: [6]
Step 7: []
```

👉 Nodes enter from **back**
👉 Nodes leave from **front**

---

# ⚡ KEY INSIGHT (THIS MAKES BFS CLICK)

👉 At any moment:

```
Queue = "next nodes to visit in level order"
```