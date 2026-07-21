# What is BFS in Graph?

**BFS** stands for **Breadth First Search**.

It is a graph traversal algorithm that visits nodes **level by level**.

That means:

* First visit starting node
* Then all its direct neighbors
* Then neighbors of those neighbors
* Then next level...

So BFS spreads outward like a wave.

---

# Real Life Analogy

Imagine throwing a stone into water.

Waves move:

* First near circle
* Then bigger circle
* Then next bigger circle

BFS works similarly.

---

# Why Use Queue?

Because BFS follows **First In First Out (FIFO)**.

The first discovered node should be processed first.

So we use:

```text
Queue
```

---

# Example Graph

```text
      1
    /   \
   2     3
  / \     \
 4   5     6
```

Adjacency list:

```cpp
1 -> 2,3
2 -> 1,4,5
3 -> 1,6
4 -> 2
5 -> 2
6 -> 3
```

---

# If BFS Starts from Node 1

Traversal order:

```text
1 2 3 4 5 6
```

Why?

### Level wise:

```text
Level 0: 1
Level 1: 2 3
Level 2: 4 5 6
```

---

# How Traversal Works Step by Step

We need:

* Queue
* Visited array

---

## Initial State

```text
Queue = [1]
Visited = {1}
```

---

## Step 1

Pop front:

```text
Take 1
Answer = 1
```

Push unvisited neighbors:

```text
2,3
```

Now:

```text
Queue = [2,3]
```

---

## Step 2

Pop:

```text
Take 2
Answer = 1 2
```

Neighbors:

* 1 already visited
* 4 unvisited
* 5 unvisited

Push:

```text
Queue = [3,4,5]
```

---

## Step 3

Pop:

```text
Take 3
Answer = 1 2 3
```

Neighbor:

* 6 unvisited

Queue:

```text
[4,5,6]
```

---

## Step 4

Pop 4

```text
Answer = 1 2 3 4
```

Queue:

```text
[5,6]
```

---

## Step 5

Pop 5

```text
Answer = 1 2 3 4 5
```

Queue:

```text
[6]
```

---

## Step 6

Pop 6

```text
Answer = 1 2 3 4 5 6
```

Queue empty → stop.

---

# Visual Queue Movement

```text
[1]
[2,3]
[3,4,5]
[4,5,6]
[5,6]
[6]
[]
```

---

# BFS Code in C++

```cpp
vector<int> bfs(int V, vector<int> adj[]) {
    
    vector<int> ans;
    vector<int> visited(V, 0);
    queue<int> q;

    q.push(0);
    visited[0] = 1;

    while(!q.empty()) {

        int node = q.front();
        q.pop();

        ans.push_back(node);

        for(auto neighbor : adj[node]) {

            if(!visited[neighbor]) {
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }

    return ans;
}
```

---

# Why Mark Visited Before Push?

Correct:

```cpp
visited[x] = 1;
q.push(x);
```

Because if you delay it, same node may enter queue many times.

---

# In Graphs Why Needed?

Unlike trees, graphs can have cycles.

Example:

```text
1 -- 2
|    |
4 -- 3
```

Without visited array:

```text
1 -> 2 -> 3 -> 4 -> 1 -> infinite
```

---

# BFS Time Complexity

Each node visited once.

Each edge checked once/twice.

[
O(V + E)
]

Where:

* (V) = vertices
* (E) = edges

---

# BFS vs DFS

| BFS                               | DFS                             |
| --------------------------------- | ------------------------------- |
| Queue                             | Stack / Recursion               |
| Level wise                        | Depth wise                      |
| Shortest path in unweighted graph | Good for recursion/backtracking |

---

# Important Graph Traversal Note

If graph is **disconnected**:

```text
1--2    3--4
```

Starting BFS from `1` gives only:

```text
1 2
```

To traverse full graph:

```cpp
for each node:
   if not visited:
      bfs(node)
```

---

# One-Line Memory Trick

> BFS = Visit nearest nodes first, then go farther level by level.

---
---
---
---
---
---
---
---
---

```cpp
vector<int> bfs(int V, vector<int> adj[]) {

    vector<int> ans;
    vector<int> visited(V, 0);
    queue<int> q;

    q.push(0);
    visited[0] = 1;

    while(!q.empty()) {

        int node = q.front();
        q.pop();

        ans.push_back(node);

        for(auto neighbor : adj[node]) {

            if(!visited[neighbor]) {
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }

    return ans;
}
```

You understood the **concept**, now let’s deeply understand the **code line by line** in beginner style.

---

# First Understand Function Header

```cpp
vector<int> bfs(int V, vector<int> adj[])
```

Means:

### This function takes:

### 1. `int V`

Total number of vertices(nodes)

Example:

```text
0 1 2 3 4
```

Then:

```cpp
V = 5
```

---

### 2. `vector<int> adj[]`

This is the **adjacency list**.

Means for every node, store its neighbors.

Example graph:

```text
0 -- 1
|    |
2 -- 3
```

Adjacency list:

```cpp
adj[0] = {1,2}
adj[1] = {0,3}
adj[2] = {0,3}
adj[3] = {1,2}
```

---

# Now Inside Function

---

## Line 1

```cpp
vector<int> ans;
```

This stores BFS traversal answer.

Example final output:

```cpp
{0,1,2,3}
```

---

## Line 2

```cpp
vector<int> visited(V, 0);
```

Create visited array of size `V`.

All initially `0`.

Means nobody visited yet.

If `V = 5`

```cpp
visited = {0,0,0,0,0}
```

Meaning:

| Node | Visited |
| ---- | ------- |
| 0    | No      |
| 1    | No      |
| 2    | No      |
| 3    | No      |
| 4    | No      |

---

## Line 3

```cpp
queue<int> q;
```

Queue for BFS.

FIFO:

First in → First out

---

# Start BFS from Node 0

## Line 4

```cpp
q.push(0);
```

Put node `0` inside queue.

```text
Queue = [0]
```

---

## Line 5

```cpp
visited[0] = 1;
```

Mark node 0 visited.

```cpp
visited = {1,0,0,0,0}
```

---

# Main BFS Loop

## Line 6

```cpp
while(!q.empty())
```

Run until queue becomes empty.

Means:

As long as nodes remain to process.

---

# Inside While Loop

---

## Step A

```cpp
int node = q.front();
```

Take front element.

Suppose queue:

```text
[0,1,2]
```

Then:

```cpp
node = 0
```

---

## Step B

```cpp
q.pop();
```

Remove front node.

Queue becomes:

```text
[1,2]
```

---

## Step C

```cpp
ans.push_back(node);
```

Store visited node in answer.

```cpp
ans = {0}
```

---

# Visit Neighbors

## Step D

```cpp
for(auto neighbor : adj[node])
```

Means:

Go through every neighbor of current node.

If:

```cpp
node = 0
adj[0] = {1,2}
```

Then loop runs:

```cpp
neighbor = 1
neighbor = 2
```

---

# Check If Already Visited

## Step E

```cpp
if(!visited[neighbor])
```

Means:

If not visited.

Example:

```cpp
visited[1] = 0
```

Then true.

---

## Step F

```cpp
visited[neighbor] = 1;
```

Mark visited.

---

## Step G

```cpp
q.push(neighbor);
```

Add to queue.

So future processing will happen.

---

# Full Dry Run Example

Graph:

```text
    0
   / \
  1   2
 /
3
```

Adjacency:

```cpp
adj[0]={1,2}
adj[1]={0,3}
adj[2]={0}
adj[3]={1}
```

---

# Initial

```text
Queue = [0]
Visited = {1,0,0,0}
Ans = {}
```

---

# Iteration 1

Take 0

```text
Queue = []
Ans = {0}
```

Neighbors: 1,2

Push both

```text
Queue = [1,2]
Visited = {1,1,1,0}
```

---

# Iteration 2

Take 1

```text
Queue = [2]
Ans = {0,1}
```

Neighbors: 0,3

0 already visited

Push 3

```text
Queue = [2,3]
Visited = {1,1,1,1}
```

---

# Iteration 3

Take 2

```text
Queue = [3]
Ans = {0,1,2}
```

Neighbor 0 visited

---

# Iteration 4

Take 3

```text
Queue = []
Ans = {0,1,2,3}
```

Done.

---

# Why Queue Needed?

Because:

```text
0 first
then neighbors 1,2
then next level 3
```

That is BFS level order.

---

# Important Line You Must Understand

```cpp
visited[neighbor] = 1;
q.push(neighbor);
```

We mark visited **before pushing**.

Why?

If not, same node can enter queue many times.

---

# Final Return

```cpp
return ans;
```

Returns:

```cpp
{0,1,2,3}
```

---

# One-Line Meaning of Whole Code

> Start from node 0, visit neighbors level by level using queue.

---
---
---
---
---
---
---


Excellent question. You noticed an important thing.

Yes — in that code:

```cpp
q.push(0);
visited[0] = 1;
```

we are **manually starting BFS from node 0**.

That does **not** mean every graph starts from 0.

It means:

> We chose node `0` as the starting node.

---

# BFS Can Start From Any Node

You can start BFS from:

* 0
* 1
* 2
* any valid node

Depends on problem statement.

---

# Example Graph

```text id="9sv0vl"
1 -- 2 -- 3
```

If nodes are:

```text id="xk7v7q"
1,2,3
```

Then starting from `0` makes no sense because node 0 doesn't exist.

So we do:

```cpp id="p1p7jl"
q.push(1);
visited[1] = 1;
```

---

# Then Why Many Codes Use 0?

Because many coding problems label nodes:

```text id="4tk75l"
0 to V-1
```

Example:

If `V = 5`

Nodes are:

```text id="1v08zl"
0 1 2 3 4
```

So starting from 0 is natural.

---

# If Graph Uses 1-Based Indexing

Nodes:

```text id="s4e7q9"
1 2 3 4 5
```

Then do:

```cpp id="j55otj"
q.push(1);
visited[1] = 1;
```

And visited size often:

```cpp id="7o8o0c"
vector<int> visited(V + 1, 0);
```

Because index 1 to V used.

---

# Important Concept

BFS syntax is:

```cpp id="vlw1ef"
bfs(startNode)
```

So really it should look like:

```cpp id="drtk3d"
vector<int> bfs(int start, int V, vector<int> adj[])
```

Then:

```cpp id="ep0ey8"
q.push(start);
visited[start] = 1;
```

Now flexible.

---

# Example Start From 2

Graph:

```text id="x7d6e3"
0 -- 1 -- 2 -- 3
```

If BFS starts from 2:

```cpp id="v2l6wd"
q.push(2);
```

Traversal:

```text id="l5e8dh"
2 1 3 0
```

---

# In Disconnected Graph

```text id="9q7n0n"
0--1     2--3
```

If start from 2:

```text id="d0glk0"
2 3
```

Only that component gets visited.

---

# Full Graph Traversal Uses Loop

That’s why often we do:

```cpp id="j4s3zv"
for(int i = 0; i < V; i++) {
    if(!visited[i]) {
        bfs(i);
    }
}
```

This ensures every component covered.

---

# Core Answer to Your Question

```cpp id="p85t2j"
q.push(0);
```

is **not compulsory**.

It only means:

> “Start BFS from node 0.”

You can replace `0` with any starting node.

---

# Interview Insight

If interviewer says:

> Perform BFS traversal from node 3

Then do:

```cpp id="v12z9z"
q.push(3);
visited[3] = 1;
```

---

# One-Line Memory Trick

> BFS doesn’t depend on 0 — it depends on the chosen starting node.

---

# You caught a smart observation.

Most beginners memorize code.
You questioned **why 0?** That’s how real understanding starts.
