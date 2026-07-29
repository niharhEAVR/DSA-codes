Absolutely. `std::set` is one of the most important STL containers, especially in coding interviews and competitive programming.

If you understand **vector**, **priority_queue**, and **set**, you'll already know a large part of the STL.

---

# What is a Set?

A **set** is a container that stores **unique elements** in **sorted order**.

Think of it as a box with two strict rules:

1. ❌ No duplicate values
2. ✅ Elements are always kept sorted

Example:

```cpp
set<int> s;

s.insert(30);
s.insert(10);
s.insert(20);
s.insert(10);
```

Result:

```text
10 20 30
```

Notice:

* `10` was inserted twice.
* Only one `10` exists.

---

# Internal Implementation

A `set` is usually implemented using a **Red-Black Tree** (a self-balancing Binary Search Tree).

It looks something like this:

```text
        20
       /  \
     10    30
```

Unlike a vector:

```text
10 20 30
```

the elements are **not stored contiguously in memory**.

Each node stores:

```text
+---------+
| value   |
| left *  |
| right * |
| parent* |
| color   |
+---------+
```

So a set uses **more memory** than a vector.

---

# Properties of Set

## 1. Unique Elements

```cpp
set<int> s;

s.insert(5);
s.insert(5);
s.insert(5);
```

Output:

```text
5
```

Duplicates are ignored.

---

## 2. Automatically Sorted

```cpp
set<int> s;

s.insert(40);
s.insert(5);
s.insert(100);
s.insert(1);
```

Output:

```text
1 5 40 100
```

You never call `sort()`.

---

## 3. Elements Cannot Be Modified

Suppose

```cpp
set<int> s={10,20,30};
```

You cannot do

```cpp
*s.begin() = 50;
```

❌ Error

Why?

Suppose

```text
10 20 30
```

If you change

```text
10
```

to

```text
100
```

you would get

```text
100 20 30
```

which breaks the sorted structure.

If you want to change a value:

```cpp
s.erase(10);
s.insert(100);
```

---

# Creating a Set

```cpp
#include <set>

set<int> s;
```

Or

```cpp
set<int> s = {5,2,8,1};
```

Output:

```text
1 2 5 8
```

---

# Inserting Elements

```cpp
s.insert(50);
s.insert(20);
s.insert(80);
```

Time Complexity:

```text
O(log N)
```

because of the balanced tree.

---

# Traversing

```cpp
for(int x : s)
{
    cout << x << " ";
}
```

Output

```text
10 20 30
```

Or

```cpp
for(auto it=s.begin(); it!=s.end(); it++)
{
    cout<<*it<<" ";
}
```

---

# Size

```cpp
cout<<s.size();
```

Example

```cpp
set<int> s;

s.insert(1);
s.insert(1);
s.insert(2);
```

Output

```text
2
```

because duplicates aren't counted.

---

# Empty

```cpp
if(s.empty())
```

Returns

```text
true
```

or

```text
false
```

---

# Find

```cpp
set<int> s={10,20,30};

auto it=s.find(20);
```

If found

```text
it points to 20
```

Otherwise

```cpp
it==s.end()
```

Example

```cpp
if(s.find(50)!=s.end())
    cout<<"Found";
else
    cout<<"Not Found";
```

Output

```text
Not Found
```

Complexity

```text
O(log N)
```

---

# Count

Since duplicates aren't allowed,

count can only return

```text
0
```

or

```text
1
```

Example

```cpp
set<int> s={1,2,3};

cout<<s.count(2);
```

Output

```text
1
```

---

```cpp
cout<<s.count(10);
```

Output

```text
0
```

---

# Erase

Erase by value

```cpp
s.erase(20);
```

Before

```text
10 20 30
```

After

```text
10 30
```

---

Erase using iterator

```cpp
auto it=s.find(20);

s.erase(it);
```

---

# Clear

```cpp
s.clear();
```

Everything disappears.

---

# lower_bound()

Returns the first element **greater than or equal to** the given value.

Example

```cpp
set<int> s={10,20,30,40};
```

```cpp
auto it=s.lower_bound(25);
```

Points to

```text
30
```

---

Example

```cpp
lower_bound(20)
```

returns

```text
20
```

because

```text
20 >=20
```

---

# upper_bound()

Returns the first element **strictly greater** than the given value.

```cpp
upper_bound(20)
```

returns

```text
30
```

---

Difference

```text
Set

10 20 30 40
```

| Function        | Result |
| --------------- | ------ |
| lower_bound(20) | 20     |
| upper_bound(20) | 30     |
| lower_bound(25) | 30     |
| upper_bound(25) | 30     |

---

# begin()

Returns iterator to first element.

```cpp
cout<<*s.begin();
```

Output

```text
10
```

---

# rbegin()

Returns reverse iterator.

```cpp
cout<<*s.rbegin();
```

Output

```text
40
```

---

# end()

Points **after** the last element.

Never do

```cpp
*s.end();
```

This is invalid.

---

# Time Complexity

| Operation     | Complexity |
| ------------- | ---------- |
| insert()      | O(log N)   |
| erase()       | O(log N)   |
| find()        | O(log N)   |
| count()       | O(log N)   |
| lower_bound() | O(log N)   |
| upper_bound() | O(log N)   |
| begin()       | O(1)       |
| size()        | O(1)       |

---

# Vector vs Set

| Feature                | vector               | set            |
| ---------------------- | -------------------- | -------------- |
| Duplicate Allowed      | ✅ Yes                | ❌ No           |
| Sorted Automatically   | ❌ No                 | ✅ Yes          |
| Memory                 | Less                 | More           |
| Internal Structure     | Dynamic Array        | Red-Black Tree |
| Insert                 | O(1) amortized (end) | O(log N)       |
| Search                 | O(N)                 | O(log N)       |
| Random Access (`v[i]`) | ✅ Yes                | ❌ No           |

---

# When Should You Use a Set?

Use a `set` when you need one or more of these:

* **Keep only unique values**

  ```cpp
  vector<int> v = {5,2,5,1,2};

  set<int> s(v.begin(), v.end());

  // s = {1,2,5}
  ```

* **Always keep elements sorted**

  ```cpp
  set<int> scores;

  scores.insert(80);
  scores.insert(60);
  scores.insert(90);

  // Automatically: 60 80 90
  ```

* **Fast searching**

  ```cpp
  if (s.find(42) != s.end())
      cout << "Exists";
  ```

* **Need operations like `lower_bound()` or `upper_bound()`**
  These are extremely useful in interview questions involving ranges or the "next greater/equal" element.

---

## Interview Tip

A very common interview pattern is:

> **Remove duplicates from an array**

```cpp
vector<int> arr = {4, 2, 4, 1, 2};

set<int> s(arr.begin(), arr.end());

for (int x : s)
    cout << x << " ";
```

Output:

```text
1 2 4
```

In just one line, you've removed duplicates **and** sorted the elements.

---

After you're comfortable with `set`, the next STL containers to learn are:

1. **`multiset`** (allows duplicates)
2. **`unordered_set`** (hash table, average O(1) operations, not sorted)
3. **`map`** (stores key-value pairs)
4. **`unordered_map`** (the most commonly used associative container in interviews)

Understanding the differences among these four is essential for solving DSA problems efficiently.



---
---
---
---
---
---



Perfect. Once you understand **set**, learning **multiset** and **unordered_set** becomes much easier because they're basically variations of `set`.

Let's compare all three first.

| Feature            | `set`          | `multiset`     | `unordered_set` |
| ------------------ | -------------- | -------------- | --------------- |
| Duplicate elements | ❌ No           | ✅ Yes          | ❌ No            |
| Sorted             | ✅ Yes          | ✅ Yes          | ❌ No            |
| Internal Structure | Red-Black Tree | Red-Black Tree | Hash Table      |
| Search             | O(log N)       | O(log N)       | O(1) average    |
| Insert             | O(log N)       | O(log N)       | O(1) average    |
| Random Access      | ❌              | ❌              | ❌               |

---

# 1. multiset

A **multiset** is exactly like a `set`, except:

> **Duplicates are allowed.**

## Example

```cpp
#include <iostream>
#include <set>
using namespace std;

int main()
{
    multiset<int> ms;

    ms.insert(10);
    ms.insert(20);
    ms.insert(10);
    ms.insert(30);
    ms.insert(20);

    for(int x : ms)
        cout << x << " ";
}
```

Output

```
10 10 20 20 30
```

Notice:

* Sorted ✅
* Duplicates preserved ✅

---

# Internal Structure

Still a Red-Black Tree.

```
          20
         /  \
      10     30
        \
        10
          \
          20
```

(Actual structure may differ.)

---

# count()

Unlike `set`:

```cpp
multiset<int> ms={10,20,20,20,30};

cout<<ms.count(20);
```

Output

```
3
```

Whereas in `set`

```
1
```

at most.

---

# find()

```cpp
auto it = ms.find(20);
```

Returns an iterator to **the first occurrence** of `20`.

---

# erase(value)

This is where beginners make mistakes.

Suppose

```cpp
multiset<int> ms={10,20,20,20,30};
```

Now

```cpp
ms.erase(20);
```

Result

```
10 30
```

**All** `20`s are removed.

---

## Remove only one occurrence

```cpp
auto it = ms.find(20);

ms.erase(it);
```

Result

```
10 20 20 30
```

Only one `20` is erased.

---

# When do we use multiset?

### Frequency problems

Suppose

```
10
10
20
20
20
30
```

You want duplicates because they matter.

Examples:

* Student marks
* Repeated words
* Card games
* Maintaining a sorted collection with repeated values

---

# 2. unordered_set

This is completely different.

Instead of a tree,

it uses a **Hash Table**.

---

## What is a Hash Table?

Imagine lockers.

```
Locker 0

Locker 1

Locker 2

Locker 3

Locker 4
```

You insert

```
25
```

Hash function

```
25 % 5 = 0
```

So

```
Locker 0

25
```

Insert

```
17
```

```
17 % 5 = 2
```

```
Locker 2

17
```

Insert

```
31
```

```
31 % 5 = 1
```

```
Locker 1

31
```

Instead of searching the whole container,

the hash function immediately tells where to look.

That's why average search is

```
O(1)
```

instead of

```
O(log N)
```

---

# Example

```cpp
unordered_set<int> us;

us.insert(30);
us.insert(10);
us.insert(20);
us.insert(50);
```

Printing

```cpp
for(int x:us)
    cout<<x<<" ";
```

Possible output

```
20 50 10 30
```

or

```
50 30 10 20
```

or

```
10 30 50 20
```

Every run could be different.

No ordering guarantee.

---

# Duplicates?

```cpp
unordered_set<int> us;

us.insert(10);
us.insert(10);
us.insert(10);
```

Output

```
10
```

Still unique.

---

# Complexity

Average

| Operation | Complexity |
| --------- | ---------- |
| Insert    | O(1)       |
| Find      | O(1)       |
| Erase     | O(1)       |

Worst case

```
O(N)
```

Why?

Suppose every number hashes to the same bucket.

```
Locker 0

10

20

30

40

50
```

Now searching

```
50
```

requires checking everything.

Modern hash tables reduce this problem, so worst-case performance is uncommon.

---

# lower_bound()

Not available.

Because there is no sorting.

---

# upper_bound()

Not available.

---

# begin()

Works.

---

# end()

Works.

---

# Why can't unordered_set stay sorted?

Suppose

```
10

20

30
```

Hash function says

```
10 -> Bucket 4

20 -> Bucket 1

30 -> Bucket 9
```

They're stored according to **hash values**, not numerical order.

Sorting would defeat the purpose of the hash table.

---

# Memory

Hash tables need extra buckets.

So

```
unordered_set
```

uses more memory than

```
set
```

---

# When should you use which?

### Use set when

* Need sorted order
* Need `lower_bound()`
* Need `upper_bound()`
* Need the smallest/largest element easily

Example

```
1
4
7
9
```

---

### Use multiset when

Need sorted order **and duplicates**.

Example

```
10
10
20
20
30
```

---

### Use unordered_set when

Need

* Fast lookup
* Fast insertion
* Order doesn't matter

Example

Checking whether a username has already been used:

```cpp
unordered_set<string> usernames;

if(usernames.find("nihar") != usernames.end())
{
    cout << "Username already exists";
}
else
{
    usernames.insert("nihar");
}
```

Average time is **O(1)**, making it much faster than scanning a vector.

---

# A Quick Cheat Sheet

| Property          | `set`    | `multiset` | `unordered_set` |
| ----------------- | -------- | ---------- | --------------- |
| Sorted            | ✅        | ✅          | ❌               |
| Duplicate Allowed | ❌        | ✅          | ❌               |
| Tree              | ✅        | ✅          | ❌               |
| Hash Table        | ❌        | ❌          | ✅               |
| Search            | O(log N) | O(log N)   | O(1) average    |
| Insert            | O(log N) | O(log N)   | O(1) average    |
| `count()`         | 0 or 1   | Any count  | 0 or 1          |
| `lower_bound()`   | ✅        | ✅          | ❌               |
| `upper_bound()`   | ✅        | ✅          | ❌               |

## Interview tip

For DSA and coding interviews, a simple rule works most of the time:

* Need **sorted unique elements** → `set`
* Need **sorted elements with duplicates** → `multiset`
* Need **fast existence checking and don't care about order** → `unordered_set`

These three containers cover a huge number of interview problems involving uniqueness, frequency, ordering, and fast lookups.
