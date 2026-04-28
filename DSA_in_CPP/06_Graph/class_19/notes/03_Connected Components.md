In graphs, **Connected Components** are one of the most important basic concepts.

---

# Definition

A **connected component** is a group of vertices (nodes) in an **undirected graph** where:

1. Every node can reach every other node in that group.
2. No extra node outside the group can be added while keeping it connected.

In simple words:

> A connected component is a separate "island" of connected nodes.

---

# Example 1

```text
Graph:

1 --- 2 --- 3

4 --- 5

6
```

Here:

* `1,2,3` are connected together
* `4,5` are connected together
* `6` is alone

So total connected components = **3**

### Components are:

```text
{1,2,3}
{4,5}
{6}
```

---

# Why "Connected"?

Because you can travel from one node to another using edges.

For example:

* `1 → 2 → 3` possible
  So same component.

But:

* `1` cannot reach `4`

So different component.

---

# Visual Understanding

```text
(1)--(2)--(3)      (4)--(5)      (6)
   Component 1      Component 2   Component 3
```

---

# In Coding Problems

Usually asked:

## Find number of connected components

Input:

```text
n = 6
edges = [[1,2],[2,3],[4,5]]
```

Output:

```text
3
```

---

# How to Find Them?

Use:

* **DFS**
* **BFS**
* **Disjoint Set Union (DSU / Union Find)**

---

# DFS Logic

1. Visit node `1`
2. DFS marks `1,2,3`
3. One component found

Then:

4. Visit next unvisited node `4`
5. DFS marks `4,5`

Then:

6. Visit node `6`

Total = 3

---

# C++ Style Pseudocode

```cpp
for each node:
    if not visited:
        dfs(node)
        components++
```

---

# Time Complexity

Using DFS/BFS:

[
O(V + E)
]

Where:

* `V = vertices`
* `E = edges`

---

# Important Note

Connected Components are mainly for **Undirected Graphs**.

For Directed Graphs:

* Strongly Connected Components (SCC)
* Weakly Connected Components

Different topic.

---

# Real Life Analogy

Think of cities and roads:

* Cities connected by roads form one component.
* If another set of cities has no road to first set, it's another component.

---

# Interview Style Example

```text
0---1     2---3---4     5
```

Connected Components:

```text
{0,1}
{2,3,4}
{5}
```

Answer = **3**

---

# One-Line Memory Trick

> Connected Components = Number of separate connected groups in an undirected graph.

---

# In DSA Why Important?

Used in:

* Network problems
* Friend circles
* Number of provinces
* Islands problems
* Cluster detection
* Social networks
