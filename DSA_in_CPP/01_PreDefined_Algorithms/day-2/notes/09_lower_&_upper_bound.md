## 🎯 **lower_bound() and upper_bound() in C++**

Both are used to **find positions (iterators)** in a **sorted container** like `vector`, `set`, `map`, etc.

---

### 🧩 **1️⃣ lower_bound()**

#### 🔹 **Definition:**

`lower_bound()` returns **the first position where the element is **not less than (≥)** the given value.**

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



---
---
---
---
---


## 🧠 First: imagine a **sorted list of numbers**

```
[ 10, 20, 30, 30, 30, 40, 50 ]
```

Keep this picture in mind.
Everything works **ONLY because it is sorted**.

---

## 1️⃣ What is `lower_bound`? (SUPER SIMPLE)

👉 **lower_bound(x)**
means:

> “Give me the position of the **first number that is NOT smaller than x**.”

In simpler words:

```
first number ≥ x
```

---

### Example

Target = **30**

```
[ 10, 20, 30, 30, 30, 40, 50 ]
          ↑
       lower_bound(30)
```

So **lower_bound(30)** points to the **first 30**.

---

### Another example

Target = **25**

```
[ 10, 20, 30, 30, 30, 40, 50 ]
          ↑
       lower_bound(25)
```

Because **30 is the first number ≥ 25**

---

## 2️⃣ What is `upper_bound`? (SUPER SIMPLE)

👉 **upper_bound(x)**
means:

> “Give me the position of the **first number that is GREATER than x**.”

In simple words:

```
first number > x
```

---

### Example

Target = **30**

```
[ 10, 20, 30, 30, 30, 40, 50 ]
                     ↑
                 upper_bound(30)
```

So it points **after the last 30**.

---

## 3️⃣ ONE LINE DIFFERENCE (REMEMBER THIS)

```
lower_bound → ≥ x
upper_bound → > x
```

That’s it.
That’s the entire concept.

---

## 4️⃣ Why do we need them? (REAL REASON)

### 🔹 Count how many times a number appears

Example: count `30`

```
lower_bound = first 30
upper_bound = after last 30
```

Count =

```
upper_bound - lower_bound
```

✔ Very fast
✔ No loops
✔ Used everywhere in DSA

---

### 🔹 Insert a number at correct place

If you want to insert `25`:

```
lower_bound(25) gives correct position
```

Array remains sorted.

---

## 5️⃣ Tiny C++ example (don’t panic)

```cpp
vector<int> v = {10, 20, 30, 30, 30, 40};

auto lb = lower_bound(v.begin(), v.end(), 30);
auto ub = upper_bound(v.begin(), v.end(), 30);

cout << lb - v.begin() << endl; // index of first 30
cout << ub - v.begin() << endl; // index after last 30
```

Output:

```
2
5
```

So count = `5 - 2 = 3`

---

## 6️⃣ If number does NOT exist

Target = **35**

```
[ 10, 20, 30, 30, 30, 40, 50 ]
                     ↑
          lower_bound & upper_bound
```

Both point to **40**
Meaning: “35 should be inserted here”

---

## 7️⃣ Golden rule (MOST IMPORTANT)

❌ Unsorted array → WRONG answer
✅ Sorted array → CORRECT

---

## 8️⃣ Think of it like this (REAL LIFE)

People standing by height:

```
150 160 170 170 170 180
```

* `lower_bound(170)` → first person **170 or taller**
* `upper_bound(170)` → first person **taller than 170**

---

## 🧠 FINAL MEMORY HACK

```
lower → >=
upper → >
```

---
---
---
---
---




# 1️⃣ Step-by-step example (HOW it actually works)

We will use this **sorted array**:

```
Index:  0  1  2  3  4  5
Array: [1, 3, 5, 5, 5, 7]
```

Target = **5**

---

## 🔹 A) `lower_bound(5)` — step by step

### Meaning (again, very simple):

> first element **≥ 5**

### Binary search thinking (inside STL)

* Start with whole array
* Look at middle
* Decide left or right

### Steps:

1️⃣ Middle element = index 2 → value = **5**

Is `5 >= 5` ? ✅ YES
👉 This **can be an answer**, but maybe there is **earlier 5**
So **move LEFT**

---

2️⃣ Left half: indices `0..1`
Middle = index 0 → value = **1**

Is `1 >= 5` ? ❌ NO
👉 Move RIGHT

---

3️⃣ Now index 1 → value = **3**

Is `3 >= 5` ? ❌ NO
👉 Move RIGHT

---

4️⃣ We stop at **index 2**

### ✅ Final answer:

```
lower_bound = index 2
```

📌 Points to the **first 5**

---

## 🔹 B) `upper_bound(5)` — step by step

### Meaning:

> first element **> 5**

---

### Steps:

1️⃣ Middle = index 2 → value = **5**

Is `5 > 5` ? ❌ NO
👉 Move RIGHT

---

2️⃣ Right half: index 3 → value = **5**

Is `5 > 5` ? ❌ NO
👉 Move RIGHT

---

3️⃣ Index 4 → value = **5**

Is `5 > 5` ? ❌ NO
👉 Move RIGHT

---

4️⃣ Index 5 → value = **7**

Is `7 > 5` ? ✅ YES
👉 This is the **first greater**

### ✅ Final answer:

```
upper_bound = index 5
```

---

## 🔹 Visual summary

```
[1, 3, 5, 5, 5, 7]
        ↑        ↑
   lower_bound  upper_bound
```

---

## 🔹 Count of 5

```
count = upper_bound - lower_bound
count = 5 - 2 = 3
```

---

# 2️⃣ Common mistakes (VERY IMPORTANT)

### ❌ Mistake 1: Using on unsorted array

```cpp
vector<int> v = {5, 1, 7, 3};
lower_bound(v.begin(), v.end(), 5); // ❌ WRONG
```

✔ Always do this first:

```cpp
sort(v.begin(), v.end());
```

---

### ❌ Mistake 2: Expecting exact match always

```cpp
vector<int> v = {1, 3, 5, 7};
lower_bound(v.begin(), v.end(), 4);
```

This does **NOT fail**.

👉 It returns position of **5**
Because `5 >= 4`

---

### ❌ Mistake 3: Confusing `>=` and `>`

This is the MOST common confusion.

❌ Wrong thinking:

```
lower_bound → >
upper_bound → >=
```

✅ Correct:

```
lower_bound → >=
upper_bound → >
```

---

### ❌ Mistake 4: Forgetting iterator ≠ index

```cpp
auto it = lower_bound(v.begin(), v.end(), 5);
cout << it;   // ❌ WRONG
```

✔ Correct:

```cpp
cout << it - v.begin();
```

---

### ❌ Mistake 5: Using on `list`

```cpp
list<int> l = {1,2,3,4};
lower_bound(l.begin(), l.end(), 3);
```

⚠ This works, **but it becomes O(n)**
Because list has no random access.

---

# 3️⃣ Time Complexity (SUPER EASY)

### Why fast?

Because STL uses **binary search**.

Binary search:

* Half array each step
* Logarithmic time

---

## ⏱ Time complexity table

| Container         | Time         |
| ----------------- | ------------ |
| `vector` (sorted) | **O(log n)** |
| `array`           | **O(log n)** |
| `set / map`       | **O(log n)** |
| `list`            | **O(n)** ❌   |

---

### Why list is slow?

Because:

* No direct jump to middle
* Must move step by step

---

# 🔥 Final one-screen summary

```
lower_bound(x) → first element ≥ x
upper_bound(x) → first element > x

Works only on SORTED data
Uses binary search
Time: O(log n)
```