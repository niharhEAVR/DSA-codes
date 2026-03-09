## 🌳 1️⃣ **set**

### 🔹 **Main Logic**

* Stores **unique elements** in **sorted order (ascending by default)**.
* Internally implemented as a **Balanced Binary Search Tree (Red-Black Tree)**.
* No duplicates allowed.
* Automatically keeps elements sorted.

### 🔹 **Header**

```cpp
#include <set>
```

### 🔹 **Common Operations**

| Operation       | Meaning                    | Time Complexity |
| --------------- | -------------------------- | --------------- |
| `insert(x)`     | Insert element             | O(log n)        |
| `erase(x)`      | Remove element             | O(log n)        |
| `find(x)`       | Search element             | O(log n)        |
| `count(x)`      | Returns 1 if exists else 0 | O(log n)        |
| `begin()/end()` | Start & end iterator       | O(1)            |
| `size()`        | Number of elements         | O(1)            |

### 🔹 **Example**

```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    s.insert(5);
    s.insert(2);
    s.insert(5);  // Duplicate ignored
    s.insert(8);

    cout << "Elements in set: ";
    for (int x : s) cout << x << " ";  // Sorted: 2 5 8
    cout << endl;

    s.erase(5);
    cout << "After erase(5): ";
    for (int x : s) cout << x << " ";  // 2 8
}
```

✅ **Output:**

```
Elements in set: 2 5 8
After erase(5): 2 8
```

---

## 🪶 2️⃣ **multiset**

### 🔹 **Main Logic**

* Same as `set`, **but allows duplicates**.
* Internally still a **balanced BST (Red-Black Tree)**.
* Automatically **sorted**.

### 🔹 **Header**

```cpp
#include <set>
```

### 🔹 **Common Operations**

| Operation        | Meaning                                     | Time Complexity |
| ---------------- | ------------------------------------------- | --------------- |
| `insert(x)`      | Insert element (duplicates allowed)         | O(log n)        |
| `erase(x)`       | Removes **all** occurrences of x            | O(log n)        |
| `find(x)`        | Finds first occurrence                      | O(log n)        |
| `count(x)`       | Counts how many times x appears             | O(log n)        |
| `equal_range(x)` | Gives pair of iterators (first & last of x) | O(log n)        |

### 🔹 **Example**

```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<int> ms;
    ms.insert(5);
    ms.insert(5);
    ms.insert(2);
    ms.insert(8);

    cout << "Elements in multiset: ";
    for (int x : ms) cout << x << " ";  // 2 5 5 8
    cout << endl;

    cout << "Count of 5: " << ms.count(5) << endl;  // 2

    ms.erase(ms.find(5));  // removes one occurrence of 5
    cout << "After erasing one 5: ";
    for (int x : ms) cout << x << " ";  // 2 5 8
}
```

✅ **Output:**

```
Elements in multiset: 2 5 5 8
Count of 5: 2
After erasing one 5: 2 5 8
```

---

## ⚡ 3️⃣ **unordered_set**

### 🔹 **Main Logic**

* Stores **unique elements**, **but no order** (neither sorted nor insertion order).
* Internally implemented using **hash table** (like Python `set`).
* Faster than `set` on average for insert/search/delete.

### 🔹 **Header**

```cpp
#include <unordered_set>
```

### 🔹 **Common Operations**

| Operation   | Meaning                    | Average Time | Worst Case |
| ----------- | -------------------------- | ------------ | ---------- |
| `insert(x)` | Insert element             | O(1)         | O(n)       |
| `erase(x)`  | Remove element             | O(1)         | O(n)       |
| `find(x)`   | Search element             | O(1)         | O(n)       |
| `count(x)`  | Returns 1 if exists else 0 | O(1)         | O(n)       |
| `size()`    | Number of elements         | O(1)         | O(1)       |

### 🔹 **Example**

```cpp
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> us;
    us.insert(5);
    us.insert(2);
    us.insert(5);  // Duplicate ignored
    us.insert(8);

    cout << "Unordered set elements: ";
    for (int x : us) cout << x << " ";  // Order unpredictable
    cout << endl;

    if (us.find(2) != us.end())
        cout << "2 found" << endl;
    us.erase(5);
    cout << "After erase(5): ";
    for (int x : us) cout << x << " ";
}
```

✅ **Possible Output (order varies):**

```
Unordered set elements: 8 2 5 
2 found
After erase(5): 8 2
```

---

## 🧠 4️⃣ **erase() Logic**

Let’s summarize the `erase()` behavior in all:

| Container       | `erase(x)` removes     | Example Result                      |
| --------------- | ---------------------- | ----------------------------------- |
| `set`           | The unique element `x` | removes one                         |
| `multiset`      | All occurrences of `x` | removes all (unless using iterator) |
| `unordered_set` | The unique element `x` | removes one                         |

---

## ⚙️ **Comparison Summary Table**

| Feature                  | `set`              | `multiset`                  | `unordered_set`                    |
| ------------------------ | ------------------ | --------------------------- | ---------------------------------- |
| **Order**                | Sorted (ASC)       | Sorted (ASC)                | No order                           |
| **Duplicates**           | ❌ No               | ✅ Yes                       | ❌ No                               |
| **Underlying structure** | Red-Black Tree     | Red-Black Tree              | Hash Table                         |
| **Insertion**            | O(log n)           | O(log n)                    | O(1)*                              |
| **Deletion**             | O(log n)           | O(log n)                    | O(1)*                              |
| **Search**               | O(log n)           | O(log n)                    | O(1)*                              |
| **Best for**             | Sorted unique data | Sorted data with duplicates | Fast lookup, unordered unique data |

> ⚠️ `*` — Average case for hash-based containers; worst case can degrade to O(n).