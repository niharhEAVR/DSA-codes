When graph problems come, first task is usually:

> **How to store graph in C++?**

There are **2 main ways**:

1. Adjacency Matrix
2. Adjacency List

---

# Why Need Representation?

Graph is:

* Nodes
* Edges

Computer needs a structure to store connections.

Like:

```text id="b8j3a2"
0 -- 1
|    |
2 -- 3
```

Need to store this in memory.

---

# 1️⃣ Adjacency Matrix

## Idea:

Use a **2D matrix**.

If node `i` connected to node `j`

Store:

```text id="q4n7ke"
matrix[i][j] = 1
```

Else:

```text id="3x1rcu"
matrix[i][j] = 0
```

---

# Example Graph

```text id="6cavb0"
0 -- 1
|    |
2 -- 3
```

Edges:

```text id="t2h3pd"
(0,1)
(0,2)
(1,3)
(2,3)
```

---

# Matrix Form

```text id="b4r7st"
    0 1 2 3
0 [ 0 1 1 0 ]
1 [ 1 0 0 1 ]
2 [ 1 0 0 1 ]
3 [ 0 1 1 0 ]
```

---

## Meaning

Row = current node
Column = connected node

Example:

```text id="g6p0rz"
matrix[0][2] = 1
```

Means 0 connected to 2

---

# C++ Code

```cpp id="c8o7ld"
int n = 4;
vector<vector<int>> matrix(n, vector<int>(n, 0));

matrix[0][1] = 1;
matrix[1][0] = 1;

matrix[0][2] = 1;
matrix[2][0] = 1;

matrix[1][3] = 1;
matrix[3][1] = 1;

matrix[2][3] = 1;
matrix[3][2] = 1;
```

---

# For Directed Graph

Only one side:

```cpp id="i2r8qz"
matrix[0][1] = 1;
```

Means:

```text id="pyc7sx"
0 → 1
```

---

# Time Complexity

## Check connection quickly:

```text id="3e6x4d"
Is 2 connected to 3?
```

Answer:

```cpp id="0l5wqm"
matrix[2][3]
```

O(1)

Very fast.

---

# Space Complexity

Need:

[
n \times n
]

So:

```text id="l9p2dv"
O(n²)
```

Bad for large graphs.

---

---

# 2️⃣ Adjacency List

## Idea:

For every node, store its neighbors.

---

# Same Graph

```text id="9u7zpc"
0 -- 1
|    |
2 -- 3
```

---

# List Form

```text id="jlwm4x"
0 -> [1,2]
1 -> [0,3]
2 -> [0,3]
3 -> [1,2]
```

---

# Meaning

Node 0 connected to 1 and 2

---

# C++ Code

```cpp id="8k2wsp"
int n = 4;
vector<vector<int>> adj(n);

adj[0].push_back(1);
adj[1].push_back(0);

adj[0].push_back(2);
adj[2].push_back(0);

adj[1].push_back(3);
adj[3].push_back(1);

adj[2].push_back(3);
adj[3].push_back(2);
```

---

# Visual Memory

```text id="j7v4n0"
adj[0] = [1,2]
```

Means roads from 0 go to 1 and 2

---

# Time Complexity

To check if 0 connected to 2:

Need to search list.

Worst case:

```text id="x2h9ru"
O(degree of node)
```

---

# Space Complexity

Only store edges.

Undirected graph:

[
O(2E)
]

So total:

```text id="2v1l8m"
O(V + E)
```

Much better.

---

# Matrix vs List

| Feature            | Matrix | List      |
| ------------------ | ------ | --------- |
| Space              | O(n²)  | O(V+E)    |
| Check edge         | O(1)   | O(degree) |
| Traverse neighbors | Slow   | Fast      |
| Sparse graph       | Bad    | Best      |
| Dense graph        | Good   | Good      |

---

# Sparse vs Dense

## Sparse Graph

Few edges

Example:

1000 nodes, 1200 edges

Use list ✅

---

## Dense Graph

Almost every node connected

Use matrix can work.

---

# Interview Reality

95% of DSA graph problems use:

✅ **Adjacency List**

Because efficient.

---

# Weighted Graph Representation

Use pair:

```cpp id="x5m2kc"
vector<vector<pair<int,int>>> adj(n);
```

Example:

```cpp id="n8p1qy"
adj[0].push_back({1,5});
```

Means:

0 connected to 1 with weight 5

---

# Important Beginner Confusion

## Why `vector<vector<int>> adj(n)` ?

Means:

```text id="1o6dpk"
n lists bana do
```

Each node gets one list.

---

## Example

If n = 4

```text id="n6c7jf"
adj[0]
adj[1]
adj[2]
adj[3]
```

Each stores neighbors.

---

# How Interview Starts

Given:

```text id="r7q0pl"
n = 5
edges = [[0,1],[0,2],[1,3]]
```

You should think:

👉 Build adjacency list first.

---

# Best Memory Trick

## Matrix = Table of Yes/No

```text id="9g8cwa"
connected ? 1 : 0
```

## List = Neighbor list

```text id="y5n3rf"
who can I visit?
```

---

# My Advice for You

Master adjacency list first.

Because BFS, DFS, Graph algorithms all use it.

---
---
---
---
---
---
---


# Graph Input + Build Adjacency List from Edges (C++)

This is one of the **most important beginner graph skills**.

Because in many problems, input comes like:

```text id="r4z8pd"
n = 5
edges = [[0,1],[0,2],[1,3],[2,4]]
```

And your first job is:

> Convert this into graph structure (Adjacency List)

---

# Why This Matters

Interview problems usually don’t give ready graph.

They give:

* number of nodes
* list of edges

You must build graph first.

Then apply:

* BFS
* DFS
* Cycle detection
* etc.

---

# Example Input

```text id="3j2tla"
n = 5
edges = [[0,1],[0,2],[1,3],[2,4]]
```

Means nodes:

```text id="b7s1rm"
0 1 2 3 4
```

Connections:

```text id="d9n3xq"
0--1
0--2
1--3
2--4
```

---

# Goal: Build Adjacency List

Final result:

```text id="k5m8ut"
0 -> [1,2]
1 -> [0,3]
2 -> [0,4]
3 -> [1]
4 -> [2]
```

---

# Step 1️⃣ Create Container

```cpp id="u2k7nx"
vector<vector<int>> adj(n);
```

If n = 5:

```text id="c4v9hz"
adj[0]
adj[1]
adj[2]
adj[3]
adj[4]
```

Each node gets one list.

---

# Step 2️⃣ Traverse Edges

Each edge has 2 nodes:

```text id="1g8zpx"
(u, v)
```

So:

```cpp id="m7q2sl"
for(auto edge : edges)
```

---

# Step 3️⃣ Extract Nodes

```cpp id="z6t4wy"
int u = edge[0];
int v = edge[1];
```

---

# Step 4️⃣ Store Connection

For **undirected graph**:

```cpp id="n3j8pk"
adj[u].push_back(v);
adj[v].push_back(u);
```

Why both?

Because:

```text id="w5r1md"
u ↔ v
```

Two-way road.

---

# Full Code

```cpp id="a9x3cr"
int n = 5;

vector<vector<int>> edges = {
    {0,1},
    {0,2},
    {1,3},
    {2,4}
};

vector<vector<int>> adj(n);

for(auto edge : edges)
{
    int u = edge[0];
    int v = edge[1];

    adj[u].push_back(v);
    adj[v].push_back(u);
}
```

---

# Dry Run Properly

## Edge = {0,1}

```cpp id="w8t4fy"
adj[0].push_back(1);
adj[1].push_back(0);
```

Now:

```text id="v1n7dp"
0 -> [1]
1 -> [0]
```

---

## Edge = {0,2}

Now:

```text id="u5m2qx"
0 -> [1,2]
2 -> [0]
```

---

## Edge = {1,3}

```text id="r3k9sa"
1 -> [0,3]
3 -> [1]
```

---

## Edge = {2,4}

```text id="f6j1cl"
2 -> [0,4]
4 -> [2]
```

---

# Final Graph

```text id="q8z5nt"
0 -> [1,2]
1 -> [0,3]
2 -> [0,4]
3 -> [1]
4 -> [2]
```

---

# If Directed Graph

Suppose:

```text id="t9w4rb"
0 → 1
1 → 2
```

Then only:

```cpp id="j4p8ke"
adj[u].push_back(v);
```

No reverse push.

---

# Weighted Graph Input

Suppose:

```text id="n1v6qx"
(0,1,5)
```

Means:

0 to 1 weight 5

Use:

```cpp id="s7m2ra"
vector<vector<pair<int,int>>> adj(n);
```

Store:

```cpp id="p3k9ud"
adj[0].push_back({1,5});
adj[1].push_back({0,5});
```

---

# Time Complexity

If E edges:

Loop runs E times.

Each push O(1)

Total:

[
O(E)
]

---

# Space Complexity

[
O(V + E)
]

---

# Common Beginner Mistakes

---

## ❌ Forget reverse push in undirected graph

Wrong:

```cpp id="d4q7lm"
adj[u].push_back(v);
```

Need:

```cpp id="e8n2st"
adj[v].push_back(u);
```

---

## ❌ Wrong size

Wrong:

```cpp id="h1m9cz"
vector<vector<int>> adj;
```

Correct:

```cpp id="x6r3pk"
vector<vector<int>> adj(n);
```

---

## ❌ Mixing 0-index / 1-index

If nodes are 1 to n:

Use:

```cpp id="g2t8vj"
vector<vector<int>> adj(n+1);
```

---

# Interview Pattern

Many problems start:

```text id="y7p5rw"
Given n nodes and edges...
```

You should instantly think:

👉 Build adjacency list first.

---

# Super Important Memory Trick

If edge:

```text id="m3k1sa"
(u,v)
```

Then:

## Undirected

```cpp id="b6q2fd"
u gets v
v gets u
```

## Directed

```cpp id="j9r4tx"
u gets v only
```

---

# Is This Topic Done?

✅ Yes — enough to move ahead.
