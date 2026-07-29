This is one of the **most important STL topics** because almost every interview asks something related to `sort()`.

But before I explain `sort()`, let me ask you one question.

Suppose I give you

```cpp
vector<int> v = {5, 2, 8, 1, 9};
```

and you write

```cpp
sort(v.begin(), v.end());
```

How much time does it take?

Most people answer:

```text
O(N log N)
```

That's correct.

But here's the interesting question:

> **Which sorting algorithm gives O(N log N)?**

* Merge Sort? 🤔
* Heap Sort? 🤔
* Quick Sort? 🤔

The answer is...

**None of them alone.**

---

# What is std::sort()?

`std::sort()` is a function provided by the STL.

```cpp
#include <algorithm>

sort(begin, end);
```

Example

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = {5, 2, 8, 1, 9};

    sort(v.begin(), v.end());

    for (int x : v)
        cout << x << " ";
}
```

Output

```
1 2 5 8 9
```

---

# Descending Order

Use a comparator.

```cpp
sort(v.begin(), v.end(), greater<int>());
```

Output

```
9 8 5 2 1
```

---

# What do begin() and end() mean?

Suppose

```cpp
vector<int> v = {5,2,8,1,9};
```

Memory

```
5   2   8   1   9
^               ^
|               |
begin()       last element

                    ^
                    |
                  end()
```

Remember

`end()` points **after** the last element.

So

```cpp
sort(v.begin(), v.end());
```

means

```
Sort everything.
```

---

# Can we sort only part of a vector?

Yes.

```cpp
vector<int> v = {9,8,7,6,5};

sort(v.begin()+1, v.begin()+4);
```

Before

```
9 8 7 6 5
```

Sorting only

```
8 7 6
```

After

```
9 6 7 8 5
```

---

# How does sort() work internally?

This is the most interesting part.

Many people think

```
sort()

↓

Quick Sort
```

Wrong.

Others think

```
sort()

↓

Merge Sort
```

Also wrong.

---

The real answer is

```
sort()

↓

Introsort
```

---

# What is Introsort?

Introsort means

```
Intro + Sort
```

or

```
Introspective Sort
```

It is a hybrid algorithm.

It combines

```
Quick Sort

+

Heap Sort

+

Insertion Sort
```

Three algorithms together.

---

# Why not just Quick Sort?

Quick Sort average

```
O(N log N)
```

Worst case

```
O(N²)
```

Example

Already sorted array

```
1 2 3 4 5 6
```

If a poor pivot is chosen every time, Quick Sort becomes very slow.

---

# Why not Merge Sort?

Merge Sort always gives

```
O(N log N)
```

But

it needs

```
O(N)
```

extra memory.

The STL designers wanted an in-place algorithm.

---

# Why not Heap Sort?

Heap Sort

```
O(N log N)
```

Worst case

```
O(N log N)
```

Good.

But

it's slower in practice because of poor cache locality and larger constant factors.

---

# So Introsort combines the best parts.

Think of it like this:

```
Start with Quick Sort

↓

If recursion becomes too deep

↓

Switch to Heap Sort

↓

If partition becomes very small

↓

Use Insertion Sort
```

---

# Why Insertion Sort?

Suppose only

```
7 elements
```

remain.

Quick Sort still performs recursive calls.

Insertion Sort simply does

```
4

↓

2 4

↓

2 4 6

↓

2 4 5 6
```

Very fast.

For tiny arrays,

Insertion Sort is actually faster than Quick Sort.

That's why almost every modern sorting library uses it for small partitions.

---

# Introsort Step by Step

Suppose

```
9 4 6 2 7 1 8 5
```

### Step 1

Quick Sort partitions

```
Pivot = 5
```

```
4 2 1

5

9 6 7 8
```

---

### Step 2

Recursively partition

```
4 2 1
```

and

```
9 6 7 8
```

---

### Step 3

Suppose recursion gets unusually deep.

Instead of continuing Quick Sort,

Introsort says

```
Stop.

Use Heap Sort now.
```

Worst-case time becomes

```
O(N log N)
```

instead of

```
O(N²)
```

---

### Step 4

Suppose only

```
3 elements
```

remain.

Instead of Quick Sort,

```
Insertion Sort
```

finishes them.

Done.

---

# Complexity

| Case    | Time       |
| ------- | ---------- |
| Best    | O(N log N) |
| Average | O(N log N) |
| Worst   | O(N log N) |

This is one of the biggest reasons `std::sort()` is preferred over writing your own Quick Sort.

---

# Memory

```
O(log N)
```

because of recursion.

---

# Why is std::sort() so fast?

Several reasons:

### 1. Hybrid algorithm

Uses the strengths of multiple algorithms.

---

### 2. Optimized in C++

The library implementation is written and tuned by compiler experts.

---

### 3. Cache friendly

It works on contiguous memory like arrays and vectors.

This makes excellent use of the CPU cache.

---

### 4. Switches algorithms intelligently

Instead of using one algorithm for everything.

---

# Can sort() work on a set?

No.

```cpp
set<int> s;

sort(s.begin(), s.end());
```

❌ Error.

Why?

Because `sort()` requires **random-access iterators**.

A vector provides them:

```
v.begin() + 5
```

works.

A set uses a tree.

There is no "5th element" in constant time.

---

# Which containers can use sort()?

✅ Array

```cpp
int arr[] = {4,2,7};

sort(arr, arr+3);
```

---

✅ Vector

```cpp
sort(v.begin(), v.end());
```

---

❌ Set

Already sorted.

---

❌ Map

Already sorted by key.

---

❌ Unordered Map

Not random access.

---

# Custom Comparator

Suppose

```cpp
vector<pair<int,int>> v =
{
    {1,5},
    {2,3},
    {3,7}
};
```

Sort by second value.

```cpp
bool cmp(pair<int,int> a, pair<int,int> b)
{
    return a.second < b.second;
}

sort(v.begin(), v.end(), cmp);
```

Result

```
2 3

1 5

3 7
```

This is asked very frequently in interviews.

---

# Stable vs Unstable

`std::sort()` is **not stable**.

Suppose

```
(90, Alice)

(90, Bob)
```

After sorting by marks,

it may become

```
(90, Bob)

(90, Alice)
```

Their relative order may change.

If you want to preserve it,

use

```cpp
stable_sort(v.begin(), v.end());
```

Internally, `stable_sort()` is typically based on Merge Sort, so it uses extra memory but guarantees that equal elements keep their original order.

---

# Cheat Sheet

| Function        | Internal Algorithm                       | Stable | Extra Space | Worst Time |
| --------------- | ---------------------------------------- | ------ | ----------- | ---------- |
| `sort()`        | **Introsort** (Quick + Heap + Insertion) | ❌ No   | O(log N)    | O(N log N) |
| `stable_sort()` | Merge Sort–based                         | ✅ Yes  | O(N)        | O(N log N) |

---

## Interview Tip

If an interviewer asks:

> **"What algorithm does `std::sort()` use?"**

Don't answer **Quick Sort**.

The best answer is:

> **"`std::sort()` uses Introsort, a hybrid algorithm that starts with Quick Sort, switches to Heap Sort if recursion becomes too deep to avoid Quick Sort's O(N²) worst case, and uses Insertion Sort for small partitions because it performs better on tiny arrays."**

That answer demonstrates a much deeper understanding than simply memorizing the time complexity.
