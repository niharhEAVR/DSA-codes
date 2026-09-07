Absolutely! Queue is the **other major linear data structure** you should know alongside stack.

The key difference is:

> **Stack → LIFO**
> **Queue → FIFO**

---

# 🚶 What is a Queue?

Think of a line of people waiting for a ticket:

```text
FRONT                              REAR
  ↓                                  ↓
[10] → [20] → [30] → [40]
 ↑
first person served
```

The person who **enters first leaves first**.

That's:

> **FIFO = First In, First Out**

If we do:

```cpp
enqueue(10)
enqueue(20)
enqueue(30)
```

we get:

```text
FRONT                 REAR
  ↓                     ↓
[10] → [20] → [30]
```

Then:

```cpp
dequeue()
```

removes `10`:

```text
FRONT          REAR
  ↓              ↓
[20] → [30]
```

---

# 1️⃣ Queue using STL

C++ gives you:

```cpp
#include <queue>

queue<int> q;
```

### Add

```cpp
q.push(10);
q.push(20);
q.push(30);
```

### Remove

```cpp
q.pop();
```

### See front

```cpp
q.front();
```

### See back

```cpp
q.back();
```

### Other operations

```cpp
q.empty();
q.size();
```

So remember:

| Operation    | Stack    | Queue     |
| ------------ | -------- | --------- |
| Insert       | `push()` | `push()`  |
| Remove       | `pop()`  | `pop()`   |
| See element  | `top()`  | `front()` |
| Last element | —        | `back()`  |

The confusing part is that **both use `push()` and `pop()`**, but they work differently.

---

# 2️⃣ Queue WITHOUT STL — Array

This is the important implementation to understand.

We can maintain:

```text
front
rear
```

Example:

```cpp
int arr[100];

int front = 0;
int rear = -1;
```

Initially:

```text
Array:

[ _ ][ _ ][ _ ][ _ ][ _ ]
  ↑
front = 0

rear = -1
```

---

## Enqueue

Let's add `10`.

```cpp
arr[++rear] = 10;
```

Now:

```text
[10][ _ ][ _ ][ _ ][ _ ]
 ↑
front = 0
 ↑
rear = 0
```

Add `20`:

```text
[10][20][ _ ][ _ ][ _ ]
 ↑    ↑
front rear
```

Add `30`:

```text
[10][20][30][ _ ][ _ ]
 ↑        ↑
front    rear
```

---

## Dequeue

Now:

```cpp
front++;
```

So:

```text
[10][20][30][ _ ][ _ ]
     ↑        ↑
   front     rear
```

`10` is now outside the **logical queue**.

The queue is:

```text
[20][30]
```

---

# 3️⃣ But there's a problem with this simple array

Suppose:

```text
[10][20][30][40][50]
 ↑                 ↑
front             rear
```

We remove:

```text
10
20
30
```

Now:

```text
[10][20][30][40][50]
             ↑     ↑
           front  rear
```

There is free space at the beginning:

```text
[ X ][ X ][ X ][40][50]
```

But `rear` has reached the end.

If we try to add another element, we'd say:

```cpp
arr[++rear] = 60;
```

but `rear` is already at the last index.

Even though we have unused space!

That's why a **circular queue** is commonly used with arrays.

---

# 4️⃣ Circular Queue ⭐

This is much more important than the simple queue implementation.

Think of the array as a circle:

```text
          [0]
       ↙       ↘
     [4]       [1]
      ↑         ↓
     [3] ←──── [2]
```

When `rear` reaches the end, it can go back to `0`.

The key formula is:

```cpp
rear = (rear + 1) % size;
```

For example, if:

```text
size = 5
rear = 4
```

then:

```text
(4 + 1) % 5
= 5 % 5
= 0
```

🔥 So it wraps around.

---

# 5️⃣ Queue using Vector

You can technically use a vector:

```cpp
vector<int> q;
```

Add:

```cpp
q.push_back(10);
q.push_back(20);
q.push_back(30);
```

But **don't normally use `erase(q.begin())` for every dequeue**, because removing from the beginning of a vector takes **O(n)**.

You can maintain an index instead:

```cpp
vector<int> q;

int front = 0;

q.push_back(10);
q.push_back(20);
q.push_back(30);

front++;
```

Then:

```cpp
q[front]
```

is the current front.

This can give **O(1)** logical dequeue.

---

# 6️⃣ Queue using Linked List

Another classic implementation.

```text
FRONT                         REAR
  ↓                             ↓
[10] → [20] → [30] → [40] → NULL
```

We maintain two pointers:

```cpp
Node* front;
Node* rear;
```

### Enqueue

Add at the **rear**:

```text
[10] → [20] → [30] → [40]
                         ↑
                        rear
```

### Dequeue

Remove from the **front**:

```text
[20] → [30] → [40]
 ↑                ↑
front            rear
```

Both operations can be **O(1)** if we maintain both pointers.

---

# 🧠 Queue implementations

| Implementation          | Enqueue |      Dequeue |
| ----------------------- | ------: | -----------: |
| `std::queue`            |    O(1) |         O(1) |
| Array + circular queue  |    O(1) |         O(1) |
| Linked List             |    O(1) |         O(1) |
| Vector with front index |    O(1) | O(1) logical |

---

# 🔥 Queue vs Stack

This is the thing you absolutely need to remember:

### Stack

```text
        TOP
         ↓
       [30] ← remove first
       [20]
       [10]
```

**LIFO**

> Last In → First Out

---

### Queue

```text
FRONT                    REAR
  ↓                        ↓
[10] → [20] → [30] → [40]
 ↑
remove first
```

**FIFO**

> First In → First Out

---

# 🎯 Where are queues used in DSA?

You'll see queues **everywhere** in:

### BFS ⭐

This is the big one.

For a graph:

```text
       1
      / \
     2   3
    /     \
   4       5
```

BFS uses a queue:

```text
queue:

[1]

remove 1
add 2, 3

[2, 3]

remove 2
add 4

[3, 4]

remove 3
add 5

[4, 5]
```

That's how BFS processes nodes **level by level**.

---

### Other uses

* BFS in graphs
* Level-order traversal of binary trees
* Scheduling
* CPU/task management
* Producer-consumer systems
* Buffering
* Request processing

---

# 🧠 What you should learn for DSA

I'd recommend this order:

```text
QUEUE
  │
  ├── FIFO
  │
  ├── enqueue
  │
  ├── dequeue
  │
  ├── front
  │
  └── rear
       │
       ├── STL queue
       │
       ├── Array
       │
       ├── Circular Queue ⭐
       │
       └── Linked List
```

And after that, learn:

**Deque → Priority Queue → BFS**

Those three build directly on this concept and are extremely common in DSA.
