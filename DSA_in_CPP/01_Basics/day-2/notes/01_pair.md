In **C++ STL**, a **`pair`** is a **simple container** defined in the `<utility>` header that holds **two data elements (possibly of different types)** together as a **single unit**.

It’s mainly used when you want to **store two related values** — for example, a **key-value pair**, a **name-score**, or a **coordinate (x, y)**.

---

### 🧩 Syntax

```cpp
#include <utility> // for pair
#include <iostream>
using namespace std;

int main() {
    pair<int, string> p = {1, "Harsh"};

    cout << p.first << " " << p.second;
    return 0;
}
```

**Output:**

```
1 Harsh
```

---

### ⚙️ Declaration and Initialization

| Method                               | Example                                                                 | Description                      |
| ------------------------------------ | ----------------------------------------------------------------------- | -------------------------------- |
| **Using braces `{}`**                | `pair<int, string> p = {1, "Apple"};`                                   | Common, simple form.             |
| **Using `make_pair()`**              | `auto p = make_pair(2, "Banana");`                                      | Automatically infers data types. |
| **Default constructor + assignment** | <pre>pair<int, string> p;<br>p.first = 3;<br>p.second = "Cherry";</pre> | Set values later.                |

---

### 🧠 Accessing Elements

Each pair has two public data members:

* `p.first` → refers to the **first element**
* `p.second` → refers to the **second element**

Example:

```cpp
cout << p.first;  // prints first element
cout << p.second; // prints second element
```

---

### 📚 Example: Pair inside a Vector

Pairs are often used in **containers** like `vector`, `map`, etc.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<int, string>> v;

    v.push_back({1, "Harsh"});
    v.push_back({2, "Rohit"});
    v.push_back({3, "Ankit"});

    for (auto &p : v) {
        cout << p.first << " -> " << p.second << endl;
    }
}
```

**Output:**

```
1 -> Harsh
2 -> Rohit
3 -> Ankit
```

---

### 🔁 Pair Comparison

Pairs can be compared directly using relational operators (`==`, `<`, `>`, etc.)
They compare **lexicographically**, i.e.:

* First compares `first`,
* If `first` is equal, compares `second`.

Example:

```cpp
pair<int, int> a = {1, 2};
pair<int, int> b = {1, 3};

if (a < b)
    cout << "a is smaller";
```

✅ Output: `a is smaller`

(because 1 == 1 but 2 < 3)

---

### ⚡ Common Use Cases

1. **Return multiple values from a function**
2. **Store key-value data temporarily**
3. **Used in containers like `map`, `multimap`, `unordered_map`**
4. **Coordinate representation (x, y)**
5. **Custom sorting of pairs**

---

### 🧩 Example: Function Returning a Pair

```cpp
pair<int, int> getMinMax(vector<int> arr) {
    int mn = *min_element(arr.begin(), arr.end());
    int mx = *max_element(arr.begin(), arr.end());
    return {mn, mx};
}

int main() {
    vector<int> arr = {4, 1, 7, 3};
    auto p = getMinMax(arr);
    cout << "Min: " << p.first << ", Max: " << p.second;
}
```

**Output:**

```
Min: 1, Max: 7
```