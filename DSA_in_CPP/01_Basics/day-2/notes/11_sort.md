## 🧩 1. What is `sort()` in C++?

`sort()` is a **function in the STL (Standard Template Library)** used to **arrange elements of a container** (like an array or vector) in **ascending or descending order**.

It is defined in the header:

```cpp
#include <algorithm>
```

---

## 🧠 2. Basic Syntax

```cpp
sort(start_iterator, end_iterator);
```

👉 You can also add a **custom comparator**:

```cpp
sort(start_iterator, end_iterator, comparator);
```

---

## 🧱 3. Main Logic (How it Works Internally)

* C++ `sort()` is **not a simple bubble or insertion sort**.
* It uses a highly optimized algorithm called **Introsort**:

  * It starts with **Quick Sort**,
  * Switches to **Heap Sort** when recursion depth is too large,
  * And uses **Insertion Sort** for small partitions.

✅ This combination makes it **very fast and efficient**.

---

## ⚡ 4. Time Complexity

| Case    | Time Complexity | Explanation                                  |
| ------- | --------------- | -------------------------------------------- |
| Best    | O(n log n)      | Uses divide and conquer                      |
| Average | O(n log n)      | Same as quick sort                           |
| Worst   | O(n log n)      | Because it switches to heap sort when needed |
| Space   | O(log n)        | Uses recursion stack only                    |

---

## 🧾 5. Example 1 — Simple Sorting (Ascending Order)

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {5, 1, 8, 3, 2};
    
    sort(v.begin(), v.end()); // Ascending order

    cout << "Ascending order: ";
    for (int x : v)
        cout << x << " ";
    return 0;
}
```

**Output:**

```
Ascending order: 1 2 3 5 8
```

---

## 🧾 6. Example 2 — Descending Order using Comparator

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(int a, int b) {
    return a > b; // Return true if a should come before b
}

int main() {
    vector<int> v = {5, 1, 8, 3, 2};

    sort(v.begin(), v.end(), compare); // Descending order

    cout << "Descending order: ";
    for (int x : v)
        cout << x << " ";
    return 0;
}
```

**Output:**

```
Descending order: 8 5 3 2 1
```

---

## 💡 7. Example 3 — Sorting an Array

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = {10, 2, 7, 1, 8};
    int n = 5;

    sort(arr, arr + n); // sort from index 0 to n-1

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
```

**Output:**

```
Sorted array: 1 2 7 8 10
```

---

## 🧩 8. Example 4 — Sorting in Partial Range

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {9, 7, 5, 3, 1};
    // Only sort first 3 elements
    sort(v.begin(), v.begin() + 3);

    for (int x : v)
        cout << x << " ";
}
```

**Output:**

```
5 7 9 3 1
```

---

## 🧮 9. Example 5 — Sorting Custom Data (like pairs)

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool sortBySecond(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second; // sort by second element
}

int main() {
    vector<pair<int, int>> v = {{1, 30}, {2, 20}, {3, 10}};

    sort(v.begin(), v.end(), sortBySecond);

    for (auto p : v)
        cout << "(" << p.first << ", " << p.second << ") ";
}
```

**Output:**

```
(3, 10) (2, 20) (1, 30)
```

---

## 🧷 10. Properties of `sort()`

| Property               | Description                                                 |
| ---------------------- | ----------------------------------------------------------- |
| 🔹 Header              | `<algorithm>`                                               |
| 🔹 Works with          | Random Access Iterators (like array, vector, deque)         |
| 🔹 Stable?             | ❌ No (does not maintain relative order of equal elements)   |
| 🔹 Use `stable_sort()` | ✅ If you need order of equal elements preserved             |
| 🔹 Default order       | Ascending (`<`)                                             |
| 🔹 Custom order        | Use comparator (like `greater<int>()` or your own function) |

---

## 🧭 11. Example using Built-in Comparator

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> v = {9, 4, 7, 2, 8};

    sort(v.begin(), v.end(), greater<int>()); // built-in comparator

    for (int x : v)
        cout << x << " ";
}
```

**Output:**

```
9 8 7 4 2
```

---

## ⚙️ Summary Table

| Concept                                    | Description                       | Default Order | Time Complexity |
| ------------------------------------------ | --------------------------------- | ------------- | --------------- |
| `sort()`                                   | Sorts elements in range           | Ascending     | O(n log n)      |
| `sort(v.begin(), v.end(), greater<int>())` | Descending order                  | Descending    | O(n log n)      |
| `stable_sort()`                            | Maintains order of equal elements | Ascending     | O(n log² n)     |



---
---
---




## 🧩 Concept: `sort(arr, arr + n)` — What does `+n` mean?

When we call

```cpp
sort(arr, arr + n);
```

it means:

> Sort the elements in the range **starting from** `arr` (index `0`) **up to but NOT including** `arr + n`.

So it sorts **from index `0` to index `n-1`** (the full array).

---

## ⚙️ Example 1 — Full Array

```cpp
int arr[] = {5, 3, 8, 1, 9};
int n = 5;

sort(arr, arr + n); // sorts from arr[0] to arr[4]
```

✅ **It sorts all elements**
**Output:** `1 3 5 8 9`

---

## ⚙️ Example 2 — Partial Sort

Now suppose:

```cpp
int arr[] = {5, 3, 8, 1, 9};
int n = 5;

sort(arr, arr + 3); // sort from arr[0] to arr[2]
```

That means → sort only **first 3 elements (index 0,1,2)**
Indexes involved: `0, 1, 2` → values `{5, 3, 8}`

So, sorted part → `{3, 5, 8}`
Rest elements stay same → `{1, 9}`

✅ **Output:**

```
3 5 8 1 9
```

---

## 🧮 So in General:

| Expression               | Meaning                           | Affected Index Range |
| ------------------------ | --------------------------------- | -------------------- |
| `sort(arr, arr + n)`     | Sort full array                   | `0 to n-1`           |
| `sort(arr, arr + 3)`     | Sort first 3 elements             | `0 to 2`             |
| `sort(arr + 2, arr + n)` | Sort elements from index 2 to end | `2 to n-1`           |

---

## 🔍 Visual Example

Let’s say we have:

| Index | 0 | 1 | 2 | 3 | 4 |
| ----- | - | - | - | - | - |
| Value | 9 | 5 | 2 | 7 | 1 |

👉 `sort(arr, arr + 3)` sorts only `[9, 5, 2]`
→ becomes `[2, 5, 9, 7, 1]`

👉 `sort(arr + 2, arr + 5)` sorts `[2, 7, 1]`
→ becomes `[9, 5, 1, 2, 7]`

---

## ✅ Final Rule to Remember:

> The **second argument (`arr + k`) is always exclusive** —
> sorting goes from `start` **up to but not including** `end`.