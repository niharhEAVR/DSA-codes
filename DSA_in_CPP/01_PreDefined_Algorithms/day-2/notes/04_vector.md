# 🧭 Understanding Vector Iterator Functions in C++

Let’s start with a simple vector:

```cpp
vector<int> v = {10, 20, 30, 40, 50};
```

---

## 🔹 1. `v.begin()` and `v.end()`

### 🧠 What it means:

* `begin()` → points to the **first element** of the vector
* `end()` → points **one position past the last element**

### 🧩 Example:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50};

    vector<int>::iterator it = v.begin();  // iterator to first element
    cout << *it << endl;  // Output: 10

    it = v.end() - 1;     // iterator to last element
    cout << *it << endl;  // Output: 50
}
```

### 🧱 Visual representation:

```
Vector:  [10] [20] [30] [40] [50]
Index:    0    1    2    3    4

begin() → points to [10]
end()   → points here (after last element) ---->
```

### ✅ Use case:

You use `begin()` and `end()` in loops:

```cpp
for (auto it = v.begin(); it != v.end(); ++it)
    cout << *it << " ";
```

**Output:**

```
10 20 30 40 50
```

---

## 🔹 2. `v.rbegin()` and `v.rend()`

### 🧠 What it means:

These are **reverse iterators** — they let you **traverse backward**.

* `rbegin()` → points to the **last element**
* `rend()` → points **before the first element**

### 🧩 Example:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50};

    for (auto it = v.rbegin(); it != v.rend(); ++it)
        cout << *it << " ";
}
```

**Output:**

```
50 40 30 20 10
```

### 🧱 Visual representation:

```
Vector:     [10] [20] [30] [40] [50]
rbegin()     --------------------^ (points to last element)
rend()    ^--------------------  (points before first element)
```

🧩 **Explanation:**

* `rbegin()` starts from **end**
* `rend()` marks **before start**
* Loop moves in **reverse order**

---

## 🔹 3. `v.back()`

### 🧠 What it means:

`back()` returns the **last element** of the vector directly.

### 🧩 Example:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50};
    cout << v.back() << endl; // Output: 50
}
```

🧩 **Explanation:**

* `v.back()` is same as `v[v.size() - 1]`
* You can also modify it:

  ```cpp
  v.back() = 100;  // changes last element to 100
  ```

---

## 🔹 4. `vector<int>::iterator it = v.begin()`

### 🧠 What it means:

* `vector<int>::iterator` is a **data type** — like a “pointer” for vector elements.
* `v.begin()` gives the **address** (iterator) of the first element.
* `it` is now pointing to the **first element**.

### 🧩 Example:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {5, 10, 15};

    vector<int>::iterator it = v.begin(); // iterator to first element
    cout << *it << endl;  // Output: 5
}
```

🧩 **Explanation:**

* `it` behaves like a pointer
* `*it` gives the value of element it points to
* You can move it forward with `++it`

### 🧱 Visual idea:

```
Vector:  [5] [10] [15]
           ^
           it = v.begin()
```

---

# ✅ **Summary Table**

| Function                   | Points To            | Traverses          | Example Output     | Use Case                         |
| -------------------------- | -------------------- | ------------------ | ------------------ | -------------------------------- |
| `begin()`                  | First element        | Forward            | `*v.begin()` → 10  | Normal looping                   |
| `end()`                    | After last element   | Forward            | -                  | Loop end condition               |
| `rbegin()`                 | Last element         | Reverse            | `*v.rbegin()` → 50 | Reverse looping                  |
| `rend()`                   | Before first element | Reverse            | -                  | Reverse end condition            |
| `back()`                   | Last element         | Direct access      | `v.back()` → 50    | Quick last element access        |
| `vector<int>::iterator it` | Iterator type        | Forward or reverse | `*it` gives value  | Used in loops and STL algorithms |

---

## 🔄 Example combining all

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50};

    cout << "Forward: ";
    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";

    cout << "\nReverse: ";
    for (auto it = v.rbegin(); it != v.rend(); ++it)
        cout << *it << " ";

    cout << "\nFirst Element: " << *v.begin();
    cout << "\nLast Element (back): " << v.back();
}
```

**Output:**

```
Forward: 10 20 30 40 50
Reverse: 50 40 30 20 10
First Element: 10
Last Element (back): 50
```

---
---
---


# 🧠 `push_back()` vs `emplace_back()` in C++ STL

Both functions are used to **insert an element at the end of a vector**.

But the **key difference** is **how** they insert the element.

---

## ⚙️ 1️⃣ `push_back()`

### ✅ **What it does:**

`push_back()` **creates an object first**, then **copies or moves it** into the vector.

### 🧩 Example:

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> v;
    string name = "Alice";

    v.push_back(name);      // copies 'name' into vector
    v.push_back("Bob");     // creates a temporary string, then copies it
}
```

🧠 **Explanation:**

* When you use `push_back("Bob")`, it first constructs a **temporary string object**,
  then **copies/moves** it into the vector.
* So, it involves an **extra copy or move operation.**

---

## ⚙️ 2️⃣ `emplace_back()`

### ✅ **What it does:**

`emplace_back()` **constructs the object directly inside the vector’s memory** — no copying or moving.

### 🧩 Example:

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> v;

    v.emplace_back("Alice");
    v.emplace_back(5, 'x'); // directly constructs string of 5 x's
}
```

**Output:**

```
Alice
xxxxx
```

🧠 **Explanation:**

* `"Alice"` is **constructed in place** inside the vector.
* `(5, 'x')` calls the **string constructor** that creates `"xxxxx"` directly.
* No temporary object is made — **more efficient**.

---

## 🔍 Example showing difference in action

Let’s define a small class to see how each behaves internally.

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    string name;
    int age;

    Student(string n, int a) {
        cout << "Constructor called for " << n << endl;
        name = n;
        age = a;
    }

    Student(const Student &s) {
        cout << "Copy constructor called for " << s.name << endl;
    }
};

int main() {
    vector<Student> v;

    cout << "Using push_back:\n";
    v.push_back(Student("Alice", 20));

    cout << "\nUsing emplace_back:\n";
    v.emplace_back("Bob", 22);
}
```

### 🧾 Output:

```
Using push_back:
Constructor called for Alice
Copy constructor called for Alice

Using emplace_back:
Constructor called for Bob
```

🧩 **Explanation:**

* `push_back()` → created `Student("Alice", 20)` first, then copied it into vector → 2 calls
* `emplace_back()` → constructed `"Bob", 22` **directly inside** vector → only 1 call

✅ `emplace_back()` is **faster and more efficient** (avoids copy).

---

## ⚖️ **Comparison Table**

| Feature                     | `push_back()`       | `emplace_back()`           |
| --------------------------- | ------------------- | -------------------------- |
| Adds element at end         | ✅                   | ✅                          |
| Creates temporary object    | ✅ Yes               | ❌ No                       |
| Constructs in-place         | ❌                   | ✅                          |
| Calls copy/move constructor | ✅                   | ❌                          |
| Syntax                      | `v.push_back(obj);` | `v.emplace_back(args...);` |
| Performance                 | Slightly slower     | Faster                     |
| Introduced in               | C++98               | **C++11**                  |

---

## 🧩 Simple Real Example

### Using `push_back()`:

```cpp
vector<pair<int, int>> v;
v.push_back(make_pair(1, 2));  // Need make_pair
```

### Using `emplace_back()`:

```cpp
vector<pair<int, int>> v;
v.emplace_back(1, 2);  // Directly constructs pair(1, 2)
```

✅ `emplace_back` is **shorter**, **cleaner**, and **faster**.

---

## 🧠 Summary in One Line

> 🔸 `push_back()` → adds a **ready-made object** to vector.
> 🔹 `emplace_back()` → **constructs the object directly inside** the vector (no temporary, no copy).
