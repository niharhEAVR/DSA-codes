This is **exactly the right question**. Many beginners think:

> "If `vector` can also store duplicates, why does `multiset` even exist?"

The answer is:

> **Because the purpose of a container is not just to store data. It's about *how* you want to use that data.**

Let's compare them.

---

# Suppose you have

```text
5 3 5 2 8 3
```

## Using vector

```cpp
vector<int> v = {5,3,5,2,8,3};
```

Memory:

```text
Index

0   1   2   3   4   5

5   3   5   2   8   3
```

Notice:

* Keeps insertion order ✅
* Duplicates allowed ✅
* Not sorted ❌

---

## Using multiset

```cpp
multiset<int> ms;

ms.insert(5);
ms.insert(3);
ms.insert(5);
ms.insert(2);
ms.insert(8);
ms.insert(3);
```

Output

```text
2 3 3 5 5 8
```

Notice

* Sorted automatically ✅
* Duplicates allowed ✅

---

# Difference 1: Searching

Suppose there are

```text
100000 elements
```

and you want to know

```text
Is 5000 present?
```

## Vector

```cpp
find(v.begin(), v.end(), 5000);
```

Worst case

```text
O(N)
```

May check all 100000 elements.

---

## Multiset

```cpp
ms.find(5000);
```

Complexity

```text
O(log N)
```

Much faster.

---

# Difference 2: Sorting

Suppose

```cpp
vector<int> v={5,3,8,2,7};
```

If you insert

```cpp
v.push_back(1);
```

Now vector becomes

```text
5 3 8 2 7 1
```

Still unsorted.

Need

```cpp
sort(v.begin(), v.end());
```

every time.

---

Multiset

```cpp
ms.insert(1);
```

Immediately becomes

```text
1 2 3 5 7 8
```

No sorting required.

---

# Difference 3: Smallest element

Suppose

```text
5 8 2 1 9 6
```

Vector

Need

```cpp
sort()
```

or

```cpp
min_element()
```

Both require scanning or sorting.

---

Multiset

```cpp
cout<<*ms.begin();
```

Output

```text
1
```

Instantly.

---

# Difference 4: Largest element

Vector

Need

```cpp
max_element()
```

O(N)

---

Multiset

```cpp
cout<<*ms.rbegin();
```

O(1)

---

# Difference 5: Delete one occurrence

Suppose

```text
2 3 3 3 5
```

Need to remove **one** `3`.

Vector

```cpp
erase(find(...))
```

After erasing

Everything after it shifts.

Complexity

```text
O(N)
```

---

Multiset

```cpp
auto it=ms.find(3);

ms.erase(it);
```

Complexity

```text
O(log N)
```

No shifting.

---

# Real Interview Example

Suppose the stream is

```text
5
2
8
1
9
```

After every insertion,

print the smallest element.

---

Using vector

Every insertion

```text
Insert

↓

Sort

↓

Print
```

Very slow.

---

Using multiset

```cpp
ms.insert(x);

cout<<*ms.begin();
```

Done.

---

# Another Interview Example

Suppose numbers are arriving continuously.

```text
10

5

8

3

12

6
```

After every insertion,

print them in sorted order.

---

Vector

```text
Insert

↓

Sort

↓

Insert

↓

Sort

↓

Insert

↓

Sort
```

Lots of repeated sorting.

---

Multiset

```cpp
ms.insert(x);
```

Always sorted.

---

# Why not always use multiset then?

Because vector has advantages.

Suppose

```cpp
vector<int> v;
```

Access

```cpp
v[500]
```

Complexity

```text
O(1)
```

---

Multiset

Can you do

```cpp
ms[500];
```

No.

Impossible.

Because it's a tree.

---

Vector is also

* More memory efficient
* Cache friendly (contiguous memory)
* Faster iteration
* Better for random access

---

# Think of them like real life

## Vector 📦

Imagine a notebook.

```
Page 1 -> 5
Page 2 -> 3
Page 3 -> 5
Page 4 -> 2
```

You can instantly go to page 4.

But the notebook isn't sorted.

---

## Multiset 📚

Imagine a librarian.

Every time you give a new book,

the librarian immediately places it in the correct alphabetical position.

Later,

finding a book is easy,

but adding/removing books requires reorganizing the tree structure.

---

# Rule of Thumb

Use a **vector** when:

* You need indexing (`v[i]`)
* You mostly append elements
* You don't care about automatic sorting
* You want the best iteration speed

Use a **multiset** when:

* You need duplicates
* You always want the data sorted
* You need fast `find()`
* You frequently need the smallest/largest element
* You perform many insertions and deletions while keeping order

---

## Interview Insight

One of the **most common uses of `multiset`** is in **sliding window problems**.

Example:

```
Window size = 3

Array:
5 2 8 1 9 6
```

As the window moves:

```
[5 2 8] 1 9 6
  ↓
5 [2 8 1] 9 6
  ↓
5 2 [8 1 9] 6
```

At each step, you:

* Remove one element.
* Insert one new element.
* Instantly get the minimum (`*begin()`) or maximum (`*rbegin()`).

Doing this with a `vector` would require shifting elements and often re-sorting. A `multiset` keeps the window sorted automatically, making these problems much easier and more efficient.

So the container you choose isn't about "which one can store duplicates?"—it's about **which operations you need to perform efficiently**.
