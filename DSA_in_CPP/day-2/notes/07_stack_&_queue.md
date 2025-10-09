## 🧱 1️⃣ Stack (LIFO — Last In First Out)

### **Main Logic**

* Stack works like a pile of plates — you can **insert and remove only from the top**.
* It uses **LIFO** principle: last inserted = first removed.
* Internally implemented using **deque** or **vector**.

### **Header**

```cpp
#include <stack>
```

### **Main Operations**

| Operation | Description               | Time Complexity |
| --------- | ------------------------- | --------------- |
| `push(x)` | Insert element at top     | O(1)            |
| `pop()`   | Remove element from top   | O(1)            |
| `top()`   | Access top element        | O(1)            |
| `empty()` | Check if empty            | O(1)            |
| `size()`  | Return number of elements | O(1)            |

### **Example**

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    
    cout << "Top: " << s.top() << endl; // 30
    s.pop();
    cout << "After pop, top: " << s.top() << endl; // 20
}
```

✅ **Output:**

```
Top: 30
After pop, top: 20
```

---

## 🚶‍♂️ 2️⃣ Queue (FIFO — First In First Out)

### **Main Logic**

* Works like a line of people — **first come, first served**.
* Insert from **rear**, remove from **front**.

### **Header**

```cpp
#include <queue>
```

### **Main Operations**

| Operation | Description          | Time Complexity |
| --------- | -------------------- | --------------- |
| `push(x)` | Insert at rear       | O(1)            |
| `pop()`   | Remove from front    | O(1)            |
| `front()` | Access first element | O(1)            |
| `back()`  | Access last element  | O(1)            |
| `empty()` | Check if empty       | O(1)            |

### **Example**

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front: " << q.front() << endl; // 1
    q.pop();
    cout << "After pop, front: " << q.front() << endl; // 2
}
```

✅ **Output:**

```
Front: 1
After pop, front: 2
```

---

## ⚙️ 3️⃣ Priority Queue (Heap — Max or Min)

### **Main Logic**

* It’s a **heap-based** data structure.
* Always keeps the **largest (default)** or **smallest (custom)** element on top.
* Internally implemented using **heap (usually max-heap)**.

### **Header**

```cpp
#include <queue>
```

### **Syntax**

```cpp
priority_queue<int> maxpq; // Max-Heap (default)
priority_queue<int, vector<int>, greater<int>> minpq; // Min-Heap
```

### **Main Operations**

| Operation | Description          | Time Complexity |
| --------- | -------------------- | --------------- |
| `push(x)` | Insert element       | O(log n)        |
| `pop()`   | Remove top (max/min) | O(log n)        |
| `top()`   | Access top (max/min) | O(1)            |
| `empty()` | Check if empty       | O(1)            |

### **Example**

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> maxpq;
    maxpq.push(5);
    maxpq.push(10);
    maxpq.push(1);

    cout << "Top (Max): " << maxpq.top() << endl; // 10
    maxpq.pop();
    cout << "After pop, top: " << maxpq.top() << endl; // 5

    // Min-heap
    priority_queue<int, vector<int>, greater<int>> minpq;
    minpq.push(5);
    minpq.push(10);
    minpq.push(1);
    cout << "Top (Min): " << minpq.top() << endl; // 1
}
```

✅ **Output:**

```
Top (Max): 10
After pop, top: 5
Top (Min): 1
```

---

## 🔁 4️⃣ Deque (Double Ended Queue)

### **Main Logic**

* “Double-ended queue” → insert and remove **from both ends**.
* Supports **both stack and queue** operations.
* Internally implemented as **a dynamic array of blocks**.

### **Header**

```cpp
#include <deque>
```

### **Main Operations**

| Operation            | Description       | Time Complexity |
| -------------------- | ----------------- | --------------- |
| `push_back(x)`       | Insert at rear    | O(1)            |
| `push_front(x)`      | Insert at front   | O(1)            |
| `pop_back()`         | Remove from rear  | O(1)            |
| `pop_front()`        | Remove from front | O(1)            |
| `front()` / `back()` | Access ends       | O(1)            |
| `at(i)`              | Random access     | O(1)            |
| `empty()` / `size()` | Check size        | O(1)            |

### **Example**

```cpp
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> d;
    d.push_back(10);
    d.push_front(20);
    d.push_back(30);

    cout << "Front: " << d.front() << ", Back: " << d.back() << endl; // 20, 30
    d.pop_front();
    cout << "After pop_front, front: " << d.front() << endl; // 10
}
```

✅ **Output:**

```
Front: 20, Back: 30
After pop_front, front: 10
```

---

## ⚡ Summary Table

| Container | Order Type | Access Type | Insertion | Deletion | Access | Internal |
|------------|-------------|--------------|------------|-----------|-----------|
| **Stack** | LIFO | Only top | O(1) | O(1) | O(1) | Deque / Vector |
| **Queue** | FIFO | Front/Back | O(1) | O(1) | O(1) | Deque / List |
| **Priority Queue** | Sorted (by priority) | Top element | O(log n) | O(log n) | O(1) | Heap |
| **Deque** | None (random) | Random access | O(1) | O(1) | O(1) | Array of blocks |
