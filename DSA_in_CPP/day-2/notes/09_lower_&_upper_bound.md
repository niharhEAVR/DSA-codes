## 🎯 **lower_bound() and upper_bound() in C++**

Both are used to **find positions (iterators)** in a **sorted container** like `vector`, `set`, `map`, etc.

---

### 🧩 **1️⃣ lower_bound()**

#### 🔹 **Definition:**

`lower_bound()` returns **the first position where the element is **not less than (≥)** the given value.

In simple terms:
👉 It gives **the first element that is ≥ the target**.

#### 🔹 **Syntax:**

```cpp
auto it = lower_bound(container.begin(), container.end(), value);
```

#### 🔹 **Time Complexity:**

* **O(log n)** → For ordered containers like `set`, `map`.
* **O(log n)** → For sorted vectors (binary search internally).

#### 🔹 **Example with vector**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1, 3, 3, 5, 7, 9};
    
    auto it = lower_bound(v.begin(), v.end(), 3);
    cout << "lower_bound of 3 is at index: " << (it - v.begin()) << endl;
    cout << "Value: " << *it << endl;
}
```

✅ **Output:**

```
lower_bound of 3 is at index: 1
Value: 3
```

If the element is **not present**, it returns the position of the **next greater element**.

Example:

```cpp
auto it2 = lower_bound(v.begin(), v.end(), 4);
cout << *it2 << endl;  // prints 5 (first ≥ 4)
```

---

### 🧩 **2️⃣ upper_bound()**

#### 🔹 **Definition:**

`upper_bound()` returns **the first position where the element is strictly greater (>)** than the given value.

In simple terms:
👉 It gives **the first element that is > the target**.

#### 🔹 **Syntax:**

```cpp
auto it = upper_bound(container.begin(), container.end(), value);
```

#### 🔹 **Time Complexity:**

Same as lower_bound → **O(log n)**.

#### 🔹 **Example**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1, 3, 3, 5, 7, 9};
    
    auto it = upper_bound(v.begin(), v.end(), 3);
    cout << "upper_bound of 3 is at index: " << (it - v.begin()) << endl;
    cout << "Value: " << *it << endl;
}
```

✅ **Output:**

```
upper_bound of 3 is at index: 3
Value: 5
```

So:

* `lower_bound(3)` → points to **first 3**
* `upper_bound(3)` → points to **next after last 3**

---

### 💡 **Summary Difference Table**

| Function                             | Returns first element | Comparison    | Example (v = {1,3,3,5,7}) | Points to   |
| ------------------------------------ | --------------------- | ------------- | ------------------------- | ----------- |
| `lower_bound(v.begin(), v.end(), x)` | **≥ x**               | Not less than | lower_bound(3)            | 3 (index 1) |
| `upper_bound(v.begin(), v.end(), x)` | **> x**               | Greater than  | upper_bound(3)            | 5 (index 3) |

---

### 📘 **With set**

Works exactly the same but returns an **iterator** to the element in the set.

```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s = {1, 3, 5, 7, 9};
    
    auto it1 = s.lower_bound(5);  // ≥ 5
    auto it2 = s.upper_bound(5);  // > 5

    cout << "lower_bound(5): " << *it1 << endl;  // 5
    cout << "upper_bound(5): " << *it2 << endl;  // 7
}
```

✅ **Output:**

```
lower_bound(5): 5
upper_bound(5): 7
```

---

### ⚠️ **If element not found**

If the value is greater than all elements → iterator points to `container.end()`

Example:

```cpp
auto it = lower_bound(v.begin(), v.end(), 100);
if (it == v.end())
    cout << "Not found (past end)";
```

---

### ⚙️ **Typical Use Cases**

1. **Binary search range queries**

   ```cpp
   int count = upper_bound(v.begin(), v.end(), x) - lower_bound(v.begin(), v.end(), x);
   // Gives how many times x appears
   ```
2. **Finding first element ≥ / > x**
3. **Used with ordered sets/maps for fast range queries**

---

✅ **In short:**

| Function         | Meaning           | Returns  | Time     |
| ---------------- | ----------------- | -------- | -------- |
| `lower_bound(x)` | First element ≥ x | iterator | O(log n) |
| `upper_bound(x)` | First element > x | iterator | O(log n) |
