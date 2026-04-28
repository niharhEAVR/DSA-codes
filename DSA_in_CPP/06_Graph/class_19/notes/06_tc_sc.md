# DFS and BFS Time Complexity (TC) and Space Complexity (SC)

This is one of the most asked interview questions, and many students memorize:

\[
O(V+E)
\]

without understanding **why**.

Today I’ll explain properly.

---

# First Meaning of Symbols

* (V) = Number of Vertices (nodes)
* (E) = Number of Edges

Example:

```text id="j39n7q"
0 -- 1
|    |
2 -- 3
```

Here:

* Vertices = 4
* Edges = 4

So:

```text id="z5m2yc"
V = 4
E = 4
```

---

# BFS Time Complexity

---

# BFS Code Reminder

```cpp id="s8p4ld"
queue<int> q;

q.push(start);

while(!q.empty()) {

   node = q.front();
   q.pop();

   for(auto neighbor : adj[node]) {
       if(not visited)
          q.push(neighbor);
   }
}
```

---

# Why O(V + E)?

We analyze 2 parts.

---

## Part 1: Visiting Nodes = O(V)

Every node enters queue once.

Why once?

Because after first time:

```cpp id="n4u6zr"
visited[node] = 1;
```

So node never added again.

So:

* push = V times max
* pop = V times max

Thus:

\[
O(V)
\]

---

## Part 2: Checking Edges = O(E)

For every node, we traverse adjacency list.

Example:

```cpp id="h7t1qx"
adj[0] = {1,2}
adj[1] = {0,3}
adj[2] = {0,3}
adj[3] = {1,2}
```

Total neighbors scanned = all edges.

In undirected graph each edge appears twice:

```text id="m8w2fa"
0-1 means:
adj[0] has 1
adj[1] has 0
```

Still total proportional to edges.

So:

\[
O(E)
\]

---

## Final BFS TC

\[
O(V + E)
\]

---

# Why Not O(V * E)?

Because nested loop looks scary, but inner loop across whole algorithm runs total edge count times, not for every node repeatedly.

---

# BFS Space Complexity

Need:

---

## 1. Visited Array

```cpp id="t3n5vb"
visited[V]
```

Space:

\[
O(V)
\]

---

## 2. Queue

Worst case queue may contain many nodes.

Example star graph:

```text id="q6r2mc"
      0
   / /|\ \
 1 2 3 4 5
```

After processing 0:

Queue has:

```text id="f1k9ud"
1 2 3 4 5
```

Can hold up to V nodes.

So:

\[
O(V)
\]

---

## Total BFS SC

\[
O(V)
\]

(visited + queue)

---

---

# DFS Time Complexity

---

# DFS Code Reminder

```cpp id="u4p8yr"
dfs(node){
   visited[node]=1;

   for(neighbor : adj[node]) {
      if(!visited[neighbor])
         dfs(neighbor);
   }
}
```

---

# Why O(V + E)?

---

## Part 1: Nodes = O(V)

Each node visited once.

Once visited:

```cpp id="d2v7xp"
visited[node]=1
```

Never processed again.

So:

\[
O(V)
\]

---

## Part 2: Edges = O(E)

All adjacency lists scanned once overall.

Same as BFS.

So:

\[
O(E)
\]

---

## Final DFS TC

\[
O(V+E)
\]

---

# DFS Space Complexity

Depends on method.

---

# Recursive DFS

Need:

---

## 1. Visited Array

\[
O(V)
\]

---

## 2. Recursion Stack

Worst case graph like chain:

```text id="y7g4mw"
0 - 1 - 2 - 3 - 4
```

Calls become:

```text id="s5j1kc"
dfs(0)
 dfs(1)
  dfs(2)
   dfs(3)
    dfs(4)
```

Depth = V

So recursion stack:

\[
O(V)
\]

---

## Total DFS Recursive SC

\[
O(V)
\]

(visited + recursion stack)

---

# Iterative DFS Using Stack

If using manual stack:

```cpp id="a9k6tr"
stack<int> st;
```

Worst case stack can hold V nodes.

So still:

\[
O(V)
\]

---

# Summary Table

| Traversal     | Time Complexity | Space Complexity |
| ------------- | --------------- | ---------------- |
| BFS           | (O(V+E))        | (O(V))           |
| DFS Recursive | (O(V+E))        | (O(V))           |
| DFS Iterative | (O(V+E))        | (O(V))           |

---

# Important Understanding by Graph Type

---

# Sparse Graph

Few edges.

Example:

```text id="p2z8lw"
V = 1000
E = 1200
```

Then:

\[
O(V+E)=O(2200)
\]

Fast.

---

# Dense Graph

Almost every node connected.

```text id="h6m3qs"
E ≈ V^2
```

Then:

\[
O(V+E)=O(V^2)
\]

Because edges dominate.

---

# Why Queue/Stack Not O(E)?

Because nodes are stored, not edges.

At most nodes wait for processing.

So auxiliary structure size usually bounded by V.

---

# Interview Trap Question

### “Why DFS recursive SC is O(V), not O(1)?”

Because recursion call stack stores pending function calls.

---

# Memory Visualization

Chain graph:

```text id="u8x4pn"
0-1-2-3-4
```

DFS stack:

```text id="v9r2le"
dfs(0)
dfs(1)
dfs(2)
dfs(3)
dfs(4)
```

5 calls in memory.

---

# One-Line Trick

> Graph traversal cost = Visit nodes once + inspect edges once.

So:

\[
O(V+E)
\]

---

# For Trees Special Case

Tree has:

\[
E = V-1
\]

So:

\[
O(V+E)=O(V)
\]

That’s why tree DFS/BFS often said O(N).

---

# Most Common Mistake

Students say:

```text id="w4q1az"
DFS = O(V)
```

Wrong for graph, because edges must also be checked.
