# 🗺️ MAP and MULTIMAP in C++ STL

Both `map` and `multimap` are **associative containers** — meaning they store **key-value pairs** where **each key is associated with some value**.

---

## 🧩 1️⃣ What is a **map**?

### 🔹 **Basic Definition**

A **map** is a container that stores **unique keys** in **sorted order** along with their corresponding values.

Each element is stored as a **pair**:

```
(key, value)
```

### 🔹 **Example Concept**

Think of a **dictionary**:

```
Word → Meaning
Roll Number → Student Name
Username → Password
```

Each **word** (key) must be **unique**, but values can repeat.

---

### 🔹 **Header**

```cpp
#include <map>
```

### 🔹 **Syntax**

```cpp
map<KeyType, ValueType> name;
```

Example:

```cpp
map<int, string> students;
```

This stores integer keys (roll numbers) with string values (names).

---

### 🔹 **Internal Working**

* `map` is implemented using a **balanced binary search tree** (specifically a Red-Black Tree).
* Keys are **automatically sorted** in ascending order.
* Each key must be **unique**.
* Lookup, insertion, and deletion are all **O(log n)**.

---

### 🔹 **Main Operations**

| Function               | Description                     | Time Complexity |
| ---------------------- | ------------------------------- | --------------- |
| `insert({key, value})` | Adds new key-value pair         | O(log n)        |
| `erase(key)`           | Removes key                     | O(log n)        |
| `find(key)`            | Finds key and returns iterator  | O(log n)        |
| `count(key)`           | Returns 1 if key exists, else 0 | O(log n)        |
| `size()`               | Number of elements              | O(1)            |
| `clear()`              | Removes all elements            | O(n)            |
| `begin() / end()`      | Start / End iterator            | O(1)            |
| `operator[]`           | Access or insert a value by key | O(log n)        |

---

### 🧠 **Example 1 — Basic Usage**

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> students;

    // Insertion
    students[101] = "Rahul";
    students[102] = "Aman";
    students.insert({103, "Priya"});

    // Access
    cout << "Roll 101: " << students[101] << endl;

    // Iteration (sorted by key)
    cout << "All students:\n";
    for (auto it : students) {
        cout << it.first << " -> " << it.second << endl;
    }

    // Find
    if (students.find(102) != students.end())
        cout << "Found roll 102\n";

    // Erase
    students.erase(103);
}
```

✅ **Output:**

```
Roll 101: Rahul
All students:
101 -> Rahul
102 -> Aman
103 -> Priya
Found roll 102
```

> Note: Elements are **automatically sorted by key** (ascending).

---

### 🧠 **Example 2 — Operator [] and Default Insertion**

If you access a non-existing key, `map` **creates** it with a **default value**:

```cpp
map<int, int> m;
cout << m[5] << endl; // prints 0 (default value)
```

That’s why `operator[]` is not available in `multimap`.

---

### ⚙️ **Properties of map**

| Property               | Description                      |
| ---------------------- | -------------------------------- |
| **Order**              | Automatically sorted by key      |
| **Unique keys**        | Each key must be unique          |
| **Duplicates**         | Not allowed                      |
| **Underlying DS**      | Red-Black Tree                   |
| **Time complexity**    | O(log n) for insert, find, erase |
| **Values**             | Can be duplicate                 |
| **Iterator traversal** | Always in sorted key order       |

---

## 🧩 2️⃣ What is a **multimap**?

### 🔹 **Basic Definition**

A **multimap** is just like `map`, but it **allows duplicate keys**.

Each key can appear **multiple times**, each possibly with a different value.

---

### 🔹 **Header**

```cpp
#include <map>
```

### 🔹 **Syntax**

```cpp
multimap<KeyType, ValueType> name;
```

Example:

```cpp
multimap<int, string> marks;
```

---

### 🔹 **Internal Working**

* Also uses a **Red-Black Tree**.
* Keys are **sorted automatically**.
* **Duplicates allowed**.
* No random access via `[]` (because multiple keys may exist).

---

### 🔹 **Main Operations**

| Function               | Description                                          | Time Complexity |
| ---------------------- | ---------------------------------------------------- | --------------- |
| `insert({key, value})` | Inserts a pair (duplicates allowed)                  | O(log n)        |
| `erase(key)`           | Removes **all** pairs with that key                  | O(log n)        |
| `find(key)`            | Returns iterator to first occurrence                 | O(log n)        |
| `count(key)`           | Returns how many times key occurs                    | O(log n)        |
| `equal_range(key)`     | Returns pair of iterators (start & end of key range) | O(log n)        |

---

### 🧠 **Example 1 — Basic multimap**

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    multimap<int, string> students;

    students.insert({101, "Rahul"});
    students.insert({102, "Aman"});
    students.insert({101, "Rohit"}); // duplicate key allowed

    cout << "All students:\n";
    for (auto it : students)
        cout << it.first << " -> " << it.second << endl;

    cout << "Count of key 101: " << students.count(101) << endl;
}
```

✅ **Output:**

```
All students:
101 -> Rahul
101 -> Rohit
102 -> Aman
Count of key 101: 2
```

---

### 🧠 **Example 2 — Using equal_range()**

To access all values for a specific key:

```cpp
auto range = students.equal_range(101);

for (auto it = range.first; it != range.second; ++it) {
    cout << it->first << " -> " << it->second << endl;
}
```

---

### ⚙️ **Properties of multimap**

| Property                   | Description    |
| -------------------------- | -------------- |
| **Order**                  | Sorted by key  |
| **Duplicates**             | ✅ Allowed      |
| **Underlying DS**          | Red-Black Tree |
| **Access via []**          | ❌ Not allowed  |
| **Insertion, Find, Erase** | O(log n)       |
| **Iterators**              | Bidirectional  |

---

## ⚡ **Comparison Table**

| Feature               | **map**                | **multimap**               |
| --------------------- | ---------------------- | -------------------------- |
| **Order**             | Sorted by key          | Sorted by key              |
| **Duplicates**        | ❌ No                   | ✅ Yes                      |
| **Key access (`[]`)** | ✅ Allowed              | ❌ Not allowed              |
| **Underlying DS**     | Red-Black Tree         | Red-Black Tree             |
| **Insertion**         | O(log n)               | O(log n)                   |
| **Deletion**          | O(log n)               | O(log n)                   |
| **Search**            | O(log n)               | O(log n)                   |
| **Best for**          | Unique key-value pairs | Grouped data with same key |

---

## 📘 Example Comparison

### ✅ Using `map`

```cpp
map<int, string> m;
m[1] = "Apple";
m[2] = "Banana";
m[2] = "Cherry"; // Overwrites Banana
```

🧩 Output:

```
1 -> Apple
2 -> Cherry
```

### ✅ Using `multimap`

```cpp
multimap<int, string> mm;
mm.insert({1, "Apple"});
mm.insert({2, "Banana"});
mm.insert({2, "Cherry"}); // Both stored
```

🧩 Output:

```
1 -> Apple
2 -> Banana
2 -> Cherry
```

---

## 🧠 Quick Tip Summary

| Function           | map              | multimap                        |
| ------------------ | ---------------- | ------------------------------- |
| `insert()`         | Add (unique)     | Add (duplicates)                |
| `erase(key)`       | Remove key       | Remove all same keys            |
| `find(key)`        | Returns iterator | Returns first occurrence        |
| `count(key)`       | 1 or 0           | Returns how many                |
| `operator[]`       | Yes              | No                              |
| `equal_range(key)` | Not used much    | Common to access all duplicates |

---

### 🕒 **Time Complexities Recap**

| Operation | map      | multimap |
| --------- | -------- | -------- |
| Insert    | O(log n) | O(log n) |
| Erase     | O(log n) | O(log n) |
| Find      | O(log n) | O(log n) |
| Count     | O(log n) | O(log n) |
| Traverse  | O(n)     | O(n)     |

---

## 💡 Real-Life Use Cases

| Use Case                                             | Best Container |
| ---------------------------------------------------- | -------------- |
| Student roll no → name                               | map            |
| Bank account → balance                               | map            |
| Marks → student names (multiple students same marks) | multimap       |
| City code → list of areas                            | multimap       |
