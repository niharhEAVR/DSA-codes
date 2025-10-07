The **`std::pair`** in C++ can only store **exactly two values** — no more, no less.
If you need to store **three values** (or more), then C++ provides another STL container for that:
👉 **`std::tuple`**

---

## 🧩 When You Have 3 or More Values — Use `tuple`

### ✅ Syntax

```cpp
#include <tuple>
#include <iostream>
using namespace std;

int main() {
    tuple<int, string, float> t = {1, "Harsh", 95.5};

    cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t);
    return 0;
}
```

**Output:**

```
1 Harsh 95.5
```

---

### ⚙️ Explanation

| Function              | Description                             | Example                              |
| --------------------- | --------------------------------------- | ------------------------------------ |
| `get<i>(tuple_name)`  | Access the **i-th** element (0-indexed) | `get<1>(t)` → `"Harsh"`              |
| `make_tuple(a, b, c)` | Create a tuple easily                   | `auto t = make_tuple(10, 'A', 5.5);` |
| `tie(x, y, z)`        | Unpack a tuple into variables           | `tie(a, b, c) = t;`                  |

---

### 📚 Example — Tuple with 3 Values

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    tuple<int, string, double> student = make_tuple(101, "Harsh", 8.9);

    int roll;
    string name;
    double cgpa;

    tie(roll, name, cgpa) = student;

    cout << "Roll: " << roll << "\nName: " << name << "\nCGPA: " << cgpa;
}
```

**Output:**

```
Roll: 101
Name: Harsh
CGPA: 8.9
```

---

### 🔁 Comparison Between `pair` and `tuple`

| Feature                | `pair`                                  | `tuple`                              |
| ---------------------- | --------------------------------------- | ------------------------------------ |
| **Header**             | `<utility>`                             | `<tuple>`                            |
| **Number of elements** | 2                                       | Any number                           |
| **Access syntax**      | `.first`, `.second`                     | `get<index>(tuple)`                  |
| **Common use**         | `map`, `vector<pair<>>`, 2D coordinates | Complex data, multiple return values |

---

### ⚡Example: Tuple with 4 Values

```cpp
tuple<int, string, double, bool> info = {1, "Kolkata", 99.5, true};
cout << get<0>(info) << " " << get<1>(info);
```

---

### 🔍 Bonus: Nested `pair` (Alternative Way)

You *can* store 3 values using a nested pair, but it’s **less readable**:

```cpp
pair<int, pair<string, float>> p = {1, {"Harsh", 9.5}};

cout << p.first << " " << p.second.first << " " << p.second.second;
```

**Output:**

```
1 Harsh 9.5
```

But this becomes messy for more than 3 values — so use `tuple` instead.
