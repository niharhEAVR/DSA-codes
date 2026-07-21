# Introduction to Graph

(DSA Beginner Friendly + Interview Perspective)

A **Graph** is a data structure used to represent **connections/relationships** between things.

It consists of:

* **Vertices (Nodes)** → entities
* **Edges** → connection between entities

Think of:

* Cities connected by roads
* People connected in social media
* Computers connected in a network
* Webpages connected by links

---

## Basic Representation

If A connected to B:

```text
A ---- B
```

Here:

* A, B = Nodes
* Line = Edge

---

# Real Life Example

Suppose cities:

Delhi, Kolkata, Mumbai

Roads:

* Delhi ↔ Kolkata
* Kolkata ↔ Mumbai

Graph:

```text
Delhi ---- Kolkata ---- Mumbai
```

---

# Why Graph is Important in Coding Interviews?

Because many problems are secretly graphs:

* Friend circles
* Number of islands
* Shortest path
* Network delay
* Course schedule
* Clone graph
* Word ladder

---

# Main Components

## 1. Vertex / Node

Each point.

```text
1   2   3
```

---

## 2. Edge

Connection between two nodes.

```text
1 ---- 2
```

---

# Types of Graphs

---

# 1️⃣ Undirected Graph

Connection both ways.

```text
1 ---- 2
```

Means:

* 1 connected to 2
* 2 connected to 1

Example:

Friendship

---

# 2️⃣ Directed Graph (Digraph)

Arrow direction matters.

```text
1 → 2
```

Means:

* 1 can go to 2
* 2 may not go to 1

Example:

Instagram follow

---

# 3️⃣ Weighted Graph

Edges have cost / distance.

```text
A --5-- B
```

Means distance = 5

Used in shortest path.

---

# 4️⃣ Unweighted Graph

Every edge equal cost.

---

# 5️⃣ Cyclic Graph

Contains cycle.

```text
1 → 2 → 3 → 1
```

Comes back to start.

---

# 6️⃣ Acyclic Graph

No cycle.

---

# 7️⃣ Connected Graph

Every node reachable.

---

# 8️⃣ Disconnected Graph

Some nodes isolated.

```text
1 -- 2      3 -- 4
```

Two components.

---

# Different Conventions Used in Graph

Very important for interviews.

---

# Convention 1: Numbering Nodes

Usually:

```text
0 to n-1
```

or

```text
1 to n
```

Example:

```text
0,1,2,3
```

Always check problem statement.

---

# Convention 2: Edge Pair Notation

```text
(u, v)
```

Means edge between u and v.

Example:

```text
(1,2)
(2,3)
```

---

# Convention 3: Adjacency Meaning

If node 1 connected to 2 and 3:

```text
adj[1] = [2,3]
```

Means neighbors of 1.

---

# Convention 4: For Undirected Graph

If edge (1,2)

Store both:

```cpp
adj[1].push_back(2);
adj[2].push_back(1);
```

---

# Convention 5: For Directed Graph

If edge 1 → 2

Store only:

```cpp
adj[1].push_back(2);
```

---

# Convention 6: Weighted Graph

Store pair:

```cpp
adj[u].push_back({v, wt});
```

Example:

```cpp
adj[1].push_back({2,5});
```

Means 1 to 2 weight 5

---

# Common Input Formats

## Format A

```text
n = 5
m = 4
edges = [[0,1],[0,2],[1,3],[2,4]]
```

n = nodes
m = edges

---

## Format B

Matrix:

```text
0 1 1
1 0 0
1 0 0
```

Means node connections.

---

# Terms You Must Know

| Term      | Meaning                       |
| --------- | ----------------------------- |
| Degree    | Number of edges touching node |
| Indegree  | Incoming edges                |
| Outdegree | Outgoing edges                |
| Path      | Route between nodes           |
| Cycle     | Comes back                    |
| Component | Separate connected part       |

---

# Visualization Example

Edges:

```text
(0,1)
(0,2)
(1,3)
(2,4)
```

Graph:

```text
      0
     / \
    1   2
    |   |
    3   4
```

---

# In Coding, Graph Stored Mainly As:

1. Adjacency Matrix
2. Adjacency List

(Next topic usually)

---

# Interview Secret

Trees are also graphs.

Tree = Graph with:

* connected
* no cycle
* n nodes, n-1 edges

---

# What You Should Strongly Understand Before Next Video

✅ Node
✅ Edge
✅ Directed vs Undirected
✅ Weighted vs Unweighted
✅ Cycle
✅ Connected Component
✅ Neighbor / adjacency

---

# If interviewer says:

“Given n nodes and edges…”

Immediately think:

👉 Build graph first.

---

# Simple Memory Trick

Graph = Nodes + Connections

---
---
---
---
---
---
---
---



Got you. “**Conventions**” simply means:

> **Standard ways people write graph problems in coding.**
> Not theory. Just the language / notation used in questions.

Think of it like traffic rules for graphs.

---

# Why Conventions Matter?

Because interviewers won’t explain:

> “What does edge (u,v) mean?”
> “Why nodes start from 0?”
> “What is adj[i]?”

They expect you already know.

---

# Let’s Decode Every Convention Properly

---

# 1️⃣ Nodes Numbering Convention

Instead of naming nodes A,B,C,D...
Coding problems use numbers.

Example:

```text id="j6l8au"
0 1 2 3 4
```

or

```text id="o2d8pk"
1 2 3 4 5
```

So if question says:

```text id="q4j4rd"
n = 5
```

Means total 5 nodes.

Could be:

* 0 to 4
  OR
* 1 to 5

Depends on problem.

---

## Why?

Because arrays use indexes.

---

# 2️⃣ Edge Convention

If two nodes connected:

```text id="91c2h6"
(1,2)
```

Means node 1 connected to node 2.

This pair is called an **edge**.

Example:

```text id="gwljg8"
edges = [(0,1), (1,2), (2,3)]
```

Means:

```text id="w8u5d5"
0 -- 1 -- 2 -- 3
```

---

# 3️⃣ Directed Edge Convention

If arrow direction:

```text id="rzg7zf"
(1,2)
```

Means:

```text id="tujk8h"
1 → 2
```

Not both sides.

Example:

Instagram follow.

---

# 4️⃣ Adjacency Convention

This is MOST important.

If node 1 connected to:

* 2
* 3
* 5

Then write:

```text id="u5l7a7"
adj[1] = [2,3,5]
```

Means:

> Neighbors of node 1

---

## Example Full Graph

```text id="i8x5hj"
0 -- 1
|    |
2 -- 3
```

Then:

```text id="px1m8l"
adj[0] = [1,2]
adj[1] = [0,3]
adj[2] = [0,3]
adj[3] = [1,2]
```

This is graph language.

---

# 5️⃣ Undirected Convention

If graph is normal road both ways:

Edge:

```text id="aqp8sq"
(1,2)
```

Store:

```cpp id="jok08r"
adj[1].push_back(2);
adj[2].push_back(1);
```

Because both can travel.

---

# 6️⃣ Directed Convention

If only:

```text id="1s1o6q"
1 → 2
```

Store only:

```cpp id="qqm7r9"
adj[1].push_back(2);
```

No reverse.

---

# 7️⃣ Weighted Convention

If edge has cost:

```text id="xen1z0"
1 --5-- 2
```

Means weight = 5

Store:

```text id="ifw3qv"
adj[1] = [(2,5)]
```

Means:

to node 2, cost 5

---

# 8️⃣ Input Convention

Many problems give:

```text id="r8m06u"
n = 4
edges = [[0,1],[1,2],[2,3]]
```

Means 4 nodes:

```text id="qz6g0t"
0 1 2 3
```

Connections:

```text id="wn1i3d"
0--1--2--3
```

---

# Real Meaning of Conventions

They are just shortcuts to represent graph quickly.

Instead of saying:

> node one connected to node two and node three...

We write:

```text id="7l9e0n"
adj[1] = [2,3]
```

---

# What Confuses Beginners Most

## “Why adj?”

adj = adjacency = nearby connected nodes

---

## “Why pair (u,v)?”

u = source node
v = destination node

Just variable names.

---

# Interview Example

If interviewer says:

```text id="jv6otx"
Given n=5 and edges=[[0,1],[0,2],[2,4]]
```

You should instantly visualize:

```text id="17m2fh"
0 connected to 1 and 2
2 connected to 4
```

---

# Golden Rule

Whenever you see graph problem:

1. Nodes kitne?
2. Edges kaun kaun?
3. Directed or undirected?
4. Weighted or not?
5. Build adj list.

---

# Super Short Summary

| Convention | Meaning             |
| ---------- | ------------------- |
| n = 5      | 5 nodes             |
| (u,v)      | edge                |
| adj[2]     | neighbors of node 2 |
| weight     | edge cost           |
| directed   | one way             |
| undirected | both way            |

---

# Honest Truth

You’re not confused in graph.
You’re just not used to graph language yet.

After 3–4 problems this becomes natural.

---