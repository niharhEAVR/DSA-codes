# 1️⃣ What is `list` in C++ STL?

`std::list` is a **container** in the C++ Standard Template Library (STL).

👉 It stores elements **in a sequence**, just like an array or vector
👉 But internally it is implemented as a **Doubly Linked List**

---

## Simple definition (one-line)

> **`std::list` is a sequence container that allows fast insertion and deletion anywhere, but does not support random access.**

---

# 2️⃣ How `std::list` works internally (VERY IMPORTANT)

Unlike `vector` or `array`, `list` **does NOT store elements in contiguous memory**.

### Internal Structure (Doubly Linked List)

Each element (node) contains:

```
[ prev | data | next ]
```

Example list:

```
10 ⇄ 20 ⇄ 30 ⇄ 40
```

Memory view:

```
Node1      Node2      Node3      Node4
[NULL|10| ]⇄[ |20| ]⇄[ |30| ]⇄[ |40|NULL]
```

✔ Each node knows:

* previous element
* next element

---

# 3️⃣ Why do we need `list`?

| Feature                  | vector | list   |
| ------------------------ | ------ | ------ |
| Random access (`arr[i]`) | ✅ Yes  | ❌ No   |
| Insert/Delete in middle  | ❌ Slow | ✅ Fast |
| Memory contiguous        | ✅ Yes  | ❌ No   |
| Cache friendly           | ✅ Yes  | ❌ No   |

👉 Use `list` when:

* **frequent insertion/deletion**
* **position is known**
* **random access not required**

---

# 4️⃣ Declaring a `list`

```cpp
#include <list>
using namespace std;

list<int> l;
```

With initial values:

```cpp
list<int> l = {10, 20, 30};
```

---

# 5️⃣ Basic Operations with Examples

---

## 🔹 1. Insert elements

### `push_back()` – insert at end

```cpp
l.push_back(40);
```

Result:

```
10 20 30 40
```

---

### `push_front()` – insert at beginning

```cpp
l.push_front(5);
```

Result:

```
5 10 20 30 40
```

---

## 🔹 2. Remove elements

### `pop_back()` – remove last

```cpp
l.pop_back();
```

---

### `pop_front()` – remove first

```cpp
l.pop_front();
```

---

## 🔹 3. Traversing a list

### Using iterator

```cpp
for(auto it = l.begin(); it != l.end(); it++)
{
    cout << *it << " ";
}
```

### Using range-based loop

```cpp
for(int x : l)
{
    cout << x << " ";
}
```

---

# 6️⃣ Why no `l[2]` in list?

❌ **NOT allowed**

```cpp
l[2];   // ERROR
```

Reason:

* Elements are **not stored contiguously**
* List has **no index**

To reach 3rd element:

```cpp
auto it = l.begin();
advance(it, 2);
cout << *it;
```

---

# 7️⃣ Insert at any position (POWER of list)

### Example: Insert `100` after 2nd element

```cpp
auto it = l.begin();
advance(it, 2);

l.insert(it, 100);
```

Before:

```
10 20 30 40
```

After:

```
10 20 100 30 40
```

✔ **O(1)** insertion (once iterator is known)

---

# 8️⃣ Erase elements

### Erase using iterator

```cpp
auto it = l.begin();
advance(it, 1);

l.erase(it);
```

Deletes 2nd element.

---

# 9️⃣ Important Built-in Functions

| Function    | Meaning                       |
| ----------- | ----------------------------- |
| `size()`    | Number of elements            |
| `empty()`   | Check if list is empty        |
| `clear()`   | Remove all elements           |
| `front()`   | First element                 |
| `back()`    | Last element                  |
| `reverse()` | Reverse list                  |
| `sort()`    | Sort list                     |
| `remove(x)` | Remove all occurrences of `x` |
| `unique()`  | Remove consecutive duplicates |

---

### Example:

```cpp
list<int> l = {3, 1, 2, 2, 4};

l.sort();     // 1 2 2 3 4
l.unique();   // 1 2 3 4
l.reverse();  // 4 3 2 1
```

---

# 🔟 Time Complexity (VERY IMPORTANT FOR EXAMS)

| Operation                | Time     |
| ------------------------ | -------- |
| Insert at known position | **O(1)** |
| Delete at known position | **O(1)** |
| Search                   | **O(n)** |
| Access element           | **O(n)** |
| Push front/back          | **O(1)** |

---

# 11️⃣ When to use `list` vs `vector`

### Use `list` when:

✔ Frequent insert/delete
✔ No need of indexing
✔ Stable iterators

### Use `vector` when:

✔ Fast access needed
✔ Cache friendly
✔ Less memory overhead

---

# 12️⃣ Complete Example Program

```cpp
#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> l;

    l.push_back(10);
    l.push_back(20);
    l.push_front(5);

    for(int x : l)
        cout << x << " ";

    return 0;
}
```

Output:

```
5 10 20
```

---

# 🔥 Summary (One-shot)

* `std::list` = **Doubly Linked List**
* Fast insert/delete
* No random access
* Uses iterators
* Best for dynamic data modification



---
---
---
---


# 1️⃣ Iterators in `std::list` (VERY IMPORTANT)

Since `list` has **no indexing**, **iterators are EVERYTHING**.

---

## 🔹 Types of iterators in list

`std::list` supports:

* **Bidirectional iterators**

  * can move **forward (`++`)**
  * can move **backward (`--`)**

❌ No random access (`it + 2` not allowed)

---

### Example: moving iterator

```cpp
list<int> l = {10, 20, 30, 40};

auto it = l.begin();   // points to 10
it++;                  // points to 20
it++;                  // points to 30

cout << *it;           // 30
```

---

### Move backward

```cpp
it--;   // now points to 20
```

✔ This is possible because list is **doubly linked**

---

# 2️⃣ `advance()` vs `next()` vs `prev()`

---

## 🔹 `advance(it, n)`

Moves the same iterator

```cpp
auto it = l.begin();
advance(it, 3);
cout << *it;   // 4th element
```

---

## 🔹 `next(it, n)`

Returns **new iterator**

```cpp
auto it2 = next(l.begin(), 2);
cout << *it2;
```

---

## 🔹 `prev(it, n)`

Moves backward

```cpp
auto it3 = prev(l.end(), 1);
cout << *it3;   // last element
```

---

# 3️⃣ Insert multiple elements

---

### Insert same value multiple times

```cpp
list<int> l = {1, 2, 5};

auto it = l.begin();
advance(it, 2);

l.insert(it, 3, 100);
```

Result:

```
1 2 100 100 100 5
```

---

### Insert another list inside a list

```cpp
list<int> a = {1, 2, 3};
list<int> b = {10, 20, 30};

auto it = a.begin();
advance(it, 1);

a.insert(it, b.begin(), b.end());
```

Result:

```
1 10 20 30 2 3
```

---

# 4️⃣ `erase()` carefully (COMMON MISTAKE)

---

### ❌ Wrong way (iterator becomes invalid)

```cpp
for(auto it = l.begin(); it != l.end(); it++)
{
    if(*it == 20)
        l.erase(it);  // ❌ BAD
}
```

---

### ✅ Correct way

```cpp
for(auto it = l.begin(); it != l.end(); )
{
    if(*it == 20)
        it = l.erase(it);
    else
        it++;
}
```

✔ `erase()` returns next valid iterator

---

# 5️⃣ `remove()` vs `erase()`

---

## 🔹 `remove(value)`

Removes **ALL occurrences** of a value

```cpp
list<int> l = {1, 2, 2, 3, 2};

l.remove(2);
```

Result:

```
1 3
```

---

## 🔹 `erase(iterator)`

Removes **single element**

---

# 6️⃣ `unique()` – tricky behavior

`unique()` removes **ONLY consecutive duplicates**

```cpp
list<int> l = {1, 2, 2, 3, 2};

l.unique();
```

Result:

```
1 2 3 2
```

👉 To remove all duplicates:

```cpp
l.sort();
l.unique();
```

---

# 7️⃣ `splice()` – MOST POWERFUL LIST FEATURE

Moves nodes **without copying** (O(1)) 🔥

---

## 🔹 Move entire list

```cpp
list<int> a = {1, 2, 3};
list<int> b = {10, 20};

a.splice(a.begin(), b);
```

Result:

```
a = 10 20 1 2 3
b = empty
```

---

## 🔹 Move one element

```cpp
auto it = b.begin();
a.splice(a.end(), b, it);
```

Moves single node.

---

## 🔹 Move range

```cpp
auto first = b.begin();
auto last = b.end();

a.splice(a.begin(), b, first, last);
```

---

# 8️⃣ Sorting with custom comparator

---

### Default sort

```cpp
l.sort();
```

---

### Descending order

```cpp
l.sort(greater<int>());
```

---

### Custom rule

```cpp
bool comp(int a, int b)
{
    return (a % 10) < (b % 10);
}

l.sort(comp);
```

Sort by last digit.

---

# 9️⃣ Merge two sorted lists

---

### Requirements:

✔ Both lists must be sorted

```cpp
list<int> a = {1, 3, 5};
list<int> b = {2, 4, 6};

a.merge(b);
```

Result:

```
a = 1 2 3 4 5 6
b = empty
```

---

# 🔟 Why `list` uses more memory?

Each node stores:

* data
* pointer to next
* pointer to previous

So:

```
vector<int> → 4 bytes per element
list<int>   → ~24 bytes per element
```

❌ Memory heavy
❌ Cache unfriendly

---

# 11️⃣ Real-world use cases

✔ LRU Cache
✔ Undo / Redo
✔ Music playlist
✔ Browser history
✔ Task scheduling

---

# 12️⃣ GATE / Interview traps

❓ **Can we do binary search on list?**
❌ NO (no random access)

❓ **Time to reach middle?**
👉 O(n)

❓ **Why splice is O(1)?**
👉 Pointer manipulation, no copying

---

# 13️⃣ Mini Practice Example

### Problem:

Remove all even numbers from list

```cpp
list<int> l = {1, 2, 3, 4, 5};

for(auto it = l.begin(); it != l.end(); )
{
    if(*it % 2 == 0)
        it = l.erase(it);
    else
        it++;
}
```

Result:

```
1 3 5
```

---

# 🔥 Final Summary

* `std::list` = doubly linked list
* Iterators are key
* Fast insert/delete
* Powerful operations: `splice`, `merge`
* Heavy memory usage
* No random access
