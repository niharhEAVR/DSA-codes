# DFS Traversal in Graph

Now we go to the second major traversal:

# DFS = Depth First Search

DFS means:

> Go as deep as possible in one path first, then come back, then explore other paths.

---

# Real Life Analogy

Imagine a maze.

You choose one path:

* keep going forward
* if dead end → come back
* try another path

That is DFS.

---

# BFS vs DFS Quick Difference

| BFS              | DFS               |
| ---------------- | ----------------- |
| Level by level   | Depth by depth    |
| Queue            | Recursion / Stack |
| Near nodes first | Deep nodes first  |

---

# Example Graph

```text id="ax8m3d"
      0
     / \
    1   2
   /
  3
```

Adjacency List:

```cpp id="z9u3fe"
adj[0] = {1,2}
adj[1] = {0,3}
adj[2] = {0}
adj[3] = {1}
```

---

# If DFS Starts from 0

Possible traversal:

```text id="a6g2ks"
0 1 3 2
```

Why?

Because:

* Start at 0
* Go to 1
* From 1 go to 3
* No more path → backtrack
* Return to 0
* Then go to 2

---

# Core Idea of DFS

```text id="wl1m9q"
Go deep
Then return
Then next path
```

---

# DFS Uses Recursion

Because recursion naturally helps:

```text id="c0y2na"
go forward
come back automatically
```

---

# Code

```cpp id="1n2q8b"
void dfs(int node, vector<int> adj[], vector<int>& visited, vector<int>& ans) {

    visited[node] = 1;
    ans.push_back(node);

    for(auto neighbor : adj[node]) {

        if(!visited[neighbor]) {
            dfs(neighbor, adj, visited, ans);
        }
    }
}
```

Main function:

```cpp id="5t7kcd"
vector<int> dfsTraversal(int V, vector<int> adj[]) {

    vector<int> visited(V, 0);
    vector<int> ans;

    dfs(0, adj, visited, ans);

    return ans;
}
```

---

# Now Understand Line by Line

---

# DFS Function Header

```cpp id="w4y6pa"
void dfs(int node, ...)
```

Means:

Currently process this node.

---

# Step 1

```cpp id="z0s7jk"
visited[node] = 1;
```

Mark node visited.

---

# Step 2

```cpp id="j1m3tr"
ans.push_back(node);
```

Store traversal answer.

---

# Step 3

```cpp id="h5p9lx"
for(auto neighbor : adj[node])
```

Check all neighbors.

---

# Step 4

```cpp id="r6u4bn"
if(!visited[neighbor])
```

If not visited.

---

# Step 5

```cpp id="f3e8qs"
dfs(neighbor, adj, visited, ans);
```

Go deeper.

This is heart of DFS.

---

# Dry Run Step by Step

Graph:

```text id="k2s8wa"
      0
     / \
    1   2
   /
  3
```

---

# Start

```cpp id="n9d2ce"
dfs(0)
```

Visited:

```text id="l8m5qy"
0
```

Ans:

```text id="v7x1ku"
{0}
```

---

# From 0 go to 1

```cpp id="e2c4fr"
dfs(1)
```

Ans:

```text id="x5p3tn"
{0,1}
```

---

# From 1 go to 3

```cpp id="q8j6sd"
dfs(3)
```

Ans:

```text id="g4w1hb"
{0,1,3}
```

3 has no new neighbor.

Return back to 1.

Return back to 0.

---

# From 0 next neighbor = 2

```cpp id="m7r2vp"
dfs(2)
```

Ans:

```text id="u1n8zk"
{0,1,3,2}
```

Done.

---

# Important Concept: Backtracking

When node has no unvisited neighbor:

```text id="c3y7ld"
return to previous node
```

That’s why recursion is perfect.

---

# Why Visited Needed?

Graph may have cycle:

```text id="j4t9sn"
0 -- 1
|    |
2----
```

Without visited:

```text id="h2v6ra"
0 ->1 ->2 ->0 -> infinite
```

---

# Time Complexity

Each node once, each edge checked.

[
O(V + E)
]

---

# DFS Using Stack (Iterative)

Can also do using stack instead of recursion.

But recursion is easier first.

---

# BFS vs DFS on Same Graph

Graph:

```text id="d7k5pm"
0 -> 1,2
1 -> 3
```

BFS:

```text id="a3r8ux"
0 1 2 3
```

DFS:

```text id="p6m2jw"
0 1 3 2
```

---

# One-Line Memory Trick

> DFS goes deep first, then comes back.

---

# Very Important for Interviews

DFS used in:

* Connected Components
* Cycle Detection
* Topological Sort
* Islands Problems
* Paths
* Tree recursion problems
