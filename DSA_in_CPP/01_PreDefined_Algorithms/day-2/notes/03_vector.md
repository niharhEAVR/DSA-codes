## 🧠 What is a `vector` in C++ STL?

A **vector** is a **dynamic array** in C++.
Unlike a normal array (which has a fixed size), a vector can **grow and shrink in size automatically** when elements are added or removed.

It’s defined in the header:

```cpp
#include <vector>
```

---

## ⚙️ Basic Syntax

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;  // declare a vector of integers
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";  // output: 10 20 30
}
```

---

## 🧩 Key Properties of `vector`

| **Property**                     | **Description**                                                                                                    | **Example / Behavior**                                                                     |
| -------------------------------- | ------------------------------------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------ |
| **Dynamic resizing**             | Automatically increases or decreases capacity when elements are added or removed.                                  | Adding a new element via `push_back()` doubles the capacity when current capacity is full. |
| **Contiguous memory**            | Elements are stored like arrays (continuous block of memory).                                                      | Allows random access with `v[i]`.                                                          |
| **Fast access**                  | Random access (via index) takes **O(1)** time.                                                                     | `v[3]` gives the 4th element instantly.                                                    |
| **Insertion/Deletion at end**    | Adding/removing at end is **O(1)** amortized.                                                                      | `push_back()`, `pop_back()`.                                                               |
| **Insertion/Deletion in middle** | Slow (O(n)) because elements need shifting.                                                                        | `v.insert(v.begin() + 1, 100);`                                                            |
| **Automatic memory management**  | You don’t manually allocate or free memory.                                                                        | Handled internally by STL.                                                                 |
| **Iterators support**            | Works with iterators for traversal and algorithms.                                                                 | `vector<int>::iterator it = v.begin();`                                                    |
| **Template class**               | Can hold any data type.                                                                                            | `vector<string>`, `vector<double>`, `vector<pair<int,int>>`                                |
| **Capacity & Size**              | - `size()` = number of elements <br> - `capacity()` = allocated memory <br> - `max_size()` = max possible elements |                                                                                            |
| **Shrink/Reserve**               | - `reserve(n)` allocates space in advance <br> - `shrink_to_fit()` reduces unused memory                           | Optimizes memory usage                                                                     |
| **Safe element access**          | `at(index)` checks bounds; `operator[]` doesn’t.                                                                   | `v.at(5)` throws exception if out of range.                                                |
| **Compatible with algorithms**   | Works with STL algorithms like `sort()`, `find()`, etc.                                                            | `sort(v.begin(), v.end());`                                                                |

---

## 🧮 Common Functions and Methods

| **Function**         | **Purpose**                               | **Example**                                 |
| -------------------- | ----------------------------------------- | ------------------------------------------- |
| `push_back(val)`     | Adds element at end                       | `v.push_back(5);`                           |
| `pop_back()`         | Removes last element                      | `v.pop_back();`                             |
| `size()`             | Returns current size                      | `v.size();`                                 |
| `capacity()`         | Returns current allocated memory capacity | `v.capacity();`                             |
| `empty()`            | Checks if vector is empty                 | `if(v.empty())`                             |
| `clear()`            | Removes all elements                      | `v.clear();`                                |
| `front()` / `back()` | Access first / last element               | `v.front();`, `v.back();`                   |
| `begin()` / `end()`  | Return iterators for start/end            | `for(auto it=v.begin(); it!=v.end(); ++it)` |
| `insert(pos, val)`   | Insert element at given position          | `v.insert(v.begin()+2, 50);`                |
| `erase(pos)`         | Erase element at position                 | `v.erase(v.begin()+1);`                     |
| `resize(n)`          | Change size (truncate or add 0s)          | `v.resize(10);`                             |
| `swap(v2)`           | Swap contents with another vector         | `v1.swap(v2);`                              |

---

## 🧱 Example: Showing Capacity Growth

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;

    for (int i = 1; i <= 10; i++) {
        v.push_back(i);
        cout << "Size: " << v.size() << " Capacity: " << v.capacity() << endl;
    }
}
```

**Output (example):**

```
Size: 1 Capacity: 1
Size: 2 Capacity: 2
Size: 3 Capacity: 4
Size: 4 Capacity: 4
Size: 5 Capacity: 8
...
```

→ Notice how **capacity doubles** when more space is needed.

---

## 🧭 Example with Iterators

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40};

    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";  // Output: 10 20 30 40
}
```

---

## 🧰 Advanced: 2D Vector Example

```cpp
vector<vector<int>> matrix = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

// Access
cout << matrix[1][2];  // Output: 6
```

---

## 🚀 Advantages

✅ Easy to use (dynamic sizing)
✅ Fast random access
✅ Integrates with all STL algorithms
✅ Memory managed automatically

---

## ⚠️ Disadvantages

❌ Inserting/removing elements **in the middle** is slow (O(n))
❌ If capacity grows too much, **reallocation** copies old data (expensive operation)

---
---
---

# 🧠 **VECTOR in C++ STL (Explained with Properties & Examples)**

---

## 🔹 **1. Dynamic Resizing**

**Property:**
A vector automatically increases its capacity (memory) when you insert more elements than it can currently hold.

**Example:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;

    for (int i = 1; i <= 5; i++) {
        v.push_back(i);
        cout << "Inserted: " << i
             << " | Size: " << v.size()
             << " | Capacity: " << v.capacity() << endl;
    }
}
```

**Output:**

```
Inserted: 1 | Size: 1 | Capacity: 1
Inserted: 2 | Size: 2 | Capacity: 2
Inserted: 3 | Size: 3 | Capacity: 4
Inserted: 4 | Size: 4 | Capacity: 4
Inserted: 5 | Size: 5 | Capacity: 8
```

🧩 **Explanation:**

* When the vector gets full, it **doubles its capacity** automatically (1 → 2 → 4 → 8).
* This is how vectors handle dynamic resizing efficiently.

---

## 🔹 **2. Contiguous Memory Allocation**

**Property:**
A vector stores its elements in **continuous (adjacent) memory blocks** — like an array.

**Example:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30};

    cout << &v[0] << endl;
    cout << &v[1] << endl;
    cout << &v[2] << endl;
}
```

**Output (example):**

```
0x61fe20
0x61fe24
0x61fe28
```

🧩 **Explanation:**
Each address is exactly **4 bytes apart** (for `int`), proving that all elements are stored **contiguously** in memory.

---

## 🔹 **3. Fast Random Access (O(1) Time)**

**Property:**
You can access any element directly using its index (like arrays).

**Example:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {100, 200, 300, 400};

    cout << v[0] << endl;   // 100
    cout << v.at(2) << endl; // 300
}
```

🧩 **Explanation:**

* `v[i]` → Direct access, **no looping needed**.
* `at()` checks bounds (throws exception if out of range).

---

## 🔹 **4. Insertion & Deletion at End are Fast**

**Property:**
Adding/removing at the end of the vector takes **O(1)** time (amortized).

**Example:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20};
    v.push_back(30);   // insert at end
    v.push_back(40);
    v.pop_back();      // delete last element

    for (int i : v)
        cout << i << " ";
}
```

**Output:**

```
10 20 30
```

🧩 **Explanation:**

* `push_back()` and `pop_back()` work at the **end**, so they are fast.
* No shifting of elements required.

---

## 🔹 **5. Insertion/Deletion in the Middle is Slow (O(n))**

**Property:**
If you insert or erase from the middle, **all elements after that point are shifted**.

**Example:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40};
    v.insert(v.begin() + 2, 25);   // Insert 25 at index 2
    v.erase(v.begin() + 1);        // Remove element at index 1

    for (int i : v)
        cout << i << " ";
}
```

**Output:**

```
10 25 30 40
```

🧩 **Explanation:**

* Inserted 25 at index 2 → `10 20 25 30 40`
* Erased element at index 1 (20) → `10 25 30 40`
* But each operation **moved many elements internally**, making it slower.

---

## 🔹 **6. Automatic Memory Management**

**Property:**
Vectors handle their own memory — you don’t need to `malloc` or `free`.

**Example:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3};
    v.push_back(4);
    v.clear(); // removes all elements

    cout << "Size: " << v.size() << endl;
}
```

**Output:**

```
Size: 0
```

🧩 **Explanation:**
No manual memory cleanup is needed; vector automatically frees memory when destroyed.

---

## 🔹 **7. Iterators Support**

**Property:**
You can use iterators to loop or use STL algorithms easily.

**Example:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40};

    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
}
```

**Output:**

```
10 20 30 40
```

🧩 **Explanation:**

* `v.begin()` → points to first element
* `v.end()` → points one past the last element
* Iterators make it easier to use STL algorithms like `sort(v.begin(), v.end())`

---

## 🔹 **8. Capacity vs Size**

**Property:**

* `size()` → number of elements actually stored
* `capacity()` → total space allocated (may be larger)
* `max_size()` → maximum elements vector can hold (theoretical)

**Example:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    for (int i = 0; i < 5; i++) v.push_back(i);

    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;
    cout << "Max Size: " << v.max_size() << endl;
}
```

**Output (example):**

```
Size: 5
Capacity: 8
Max Size: 1073741823
```

🧩 **Explanation:**

* `capacity()` may be greater than `size()` because extra memory is preallocated for efficiency.

---

## 🔹 **9. Reserve and Shrink**

**Property:**
You can manually control memory using `reserve()` and `shrink_to_fit()`.

**Example:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    v.reserve(100);   // pre-allocate memory for 100 elements
    cout << "Capacity after reserve: " << v.capacity() << endl;

    v.push_back(10);
    v.shrink_to_fit(); // reduce unused memory
    cout << "Capacity after shrink: " << v.capacity() << endl;
}
```

🧩 **Explanation:**

* `reserve()` prevents multiple reallocations.
* `shrink_to_fit()` releases unused space.

---

## 🔹 **10. Works with STL Algorithms**

**Property:**
Vectors work perfectly with algorithms like `sort()`, `reverse()`, `find()`, etc.

**Example:**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {40, 10, 30, 20};
    sort(v.begin(), v.end());

    for (int i : v)
        cout << i << " ";
}
```

**Output:**

```
10 20 30 40
```

🧩 **Explanation:**
Because vectors store data contiguously and support iterators, STL algorithms can easily manipulate them.

---

## 🔹 **11. Template Support**

**Property:**
Vectors can store **any data type** (int, string, pair, struct, etc.)

**Example:**

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> names = {"Alice", "Bob", "Charlie"};

    for (string s : names)
        cout << s << " ";
}
```

**Output:**

```
Alice Bob Charlie
```

---

## 🔹 **12. 2D Vectors (Vector of Vectors)**

**Property:**
You can create multi-dimensional vectors like matrices.

**Example:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for (auto row : matrix) {
        for (auto col : row)
            cout << col << " ";
        cout << endl;
    }
}
```

**Output:**

```
1 2 3
4 5 6
7 8 9
```

---

# 🏁 **Summary Table**

| Property           | Description                  | Example Function               |
| ------------------ | ---------------------------- | ------------------------------ |
| Dynamic resizing   | Auto expands capacity        | `push_back()`                  |
| Contiguous memory  | Elements stored sequentially | `&v[i]`                        |
| Fast random access | O(1) access time             | `v[i]`, `v.at()`               |
| Fast at end ops    | O(1) insert/remove           | `push_back()`, `pop_back()`    |
| Slow mid ops       | O(n) shifting needed         | `insert()`, `erase()`          |
| Automatic memory   | No manual allocation         | `clear()`, destructor          |
| Iterators          | Easy traversal               | `begin()`, `end()`             |
| Capacity mgmt      | Preallocate memory           | `reserve()`, `shrink_to_fit()` |
| STL friendly       | Works with algorithms        | `sort()`, `find()`             |
