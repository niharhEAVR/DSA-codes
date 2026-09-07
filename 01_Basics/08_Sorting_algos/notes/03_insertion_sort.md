Absolutely — insertion sort is one of the easiest sorting algorithms to understand once you see the **idea behind it**.

## 1. What is Insertion Sort?

Think about how you arrange **playing cards in your hand**.

Suppose you receive cards one by one:

```text
5
5 2
2 5  ← insert 2 before 5

2 5 8
2 5 8  ← 8 is already in the right place

2 5 8 3
2 3 5 8  ← insert 3 between 2 and 5
```

That's basically **Insertion Sort**.

### Main idea

> Take one element and insert it into its correct position in the already-sorted part.

For example:

```text
[5, 2, 4, 6, 1, 3]
 ↑
sorted
```

Initially, we consider the first element `5` sorted.

Then take `2`:

```text
[5 | 2, 4, 6, 1, 3]
```

`2 < 5`, so move `5` to the right:

```text
[5, 5, 4, 6, 1, 3]
```

Put `2` where `5` was:

```text
[2, 5 | 4, 6, 1, 3]
```

Now `2,5` are sorted.

Then take `4`:

```text
[2, 5 | 4, 6, 1, 3]
```

`4 < 5`, so shift `5`:

```text
[2, 5, 5, 6, 1, 3]
```

Insert `4`:

```text
[2, 4, 5 | 6, 1, 3]
```

And so on.

genui{"learning_viz":{"type_id":"INSERTION_SORT"}}

---

# 2. How do we implement it?

The basic code is:

```cpp
#include <iostream>
using namespace std;

int main() {

    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = 6;

    for (int i = 1; i < n; i++) {

        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
```

Output:

```text
1 2 3 4 5 6
```

---

# 3. Understand these 3 lines VERY carefully

These are the heart of insertion sort:

```cpp
int key = arr[i];
int j = i - 1;

while (j >= 0 && arr[j] > key) {
    arr[j + 1] = arr[j];
    j--;
}

arr[j + 1] = key;
```

Let's understand them.

Suppose:

```text
arr = [2, 5, 8, 3]
             ↑
             i
```

We take `3`.

```cpp
int key = arr[i];
```

So:

```text
key = 3
```

Then:

```cpp
int j = i - 1;
```

`j` points to the element immediately before `3`:

```text
[2, 5, 8, 3]
       ↑  ↑
       j  i
```

Now:

```cpp
while (j >= 0 && arr[j] > key)
```

means:

> "As long as the element before me is bigger than `key`, move that element one position to the right."

So:

```text
[2, 5, 8, 3]
       ↑
       8 > 3
```

Move `8`:

```text
[2, 5, 8, 8]
```

Then:

```cpp
j--;
```

Now `j` points to `5`.

```text
[2, 5, 8, 8]
    ↑
    j
```

`5 > 3`, so move it:

```text
[2, 5, 5, 8]
```

Again `j--`.

Now `j` points to `2`.

```text
2 > 3
```

False.

So stop.

Then:

```cpp
arr[j + 1] = key;
```

Since `j` is at `2`:

```text
j + 1
  ↓
[2, _, 5, 8]
```

Put `3` there:

```text
[2, 3, 5, 8]
```

That's insertion sort.

---

# 4. The easiest way to remember the algorithm

Whenever you see insertion sort, think:

```text
        TAKE
         ↓
[sorted | element]
          ↑
         key

        ↓

COMPARE LEFT

        ↓

If left > key
      SHIFT RIGHT

        ↓

Repeat

        ↓

INSERT key
```

Or simply:

> **Take → Compare → Shift → Insert**

That's the entire algorithm.

---

# 5. Why do we start `i` from 1?

This is important.

```cpp
for (int i = 1; i < n; i++)
```

Why not `i = 0`?

Because:

```text
[5]
```

A single element is **already sorted**.

So we start with:

```text
[5 | 2, 4, 6, 1, 3]
```

The left side is our sorted portion.

Then we take `2`.

```text
[5 | 2, 4, 6, 1, 3]
     ↑
     key
```

After insertion:

```text
[2, 5 | 4, 6, 1, 3]
```

Then:

```text
[2, 5 | 4, 6, 1, 3]
         ↑
         key
```

After insertion:

```text
[2, 4, 5 | 6, 1, 3]
```

Notice something beautiful:

### The portion before `i` is always sorted.

```text
[ sorted | unsorted ]
```

And insertion sort keeps increasing the size of the sorted portion.

---

# 6. When do we use Insertion Sort?

This is the more important DSA question.

Insertion sort is **not usually the best choice for a huge random array**.

For example:

```text
[92, 5, 73, 12, 48, 1, 67, 23, ...]
```

For thousands/millions of elements, algorithms like:

* Merge Sort
* Quick Sort
* Heap Sort
* `std::sort()`

are generally better.

### Insertion sort is useful when:

**1. The array is already almost sorted**

Example:

```text
[1, 2, 3, 5, 4, 6, 7, 8]
```

Only `4` is slightly misplaced.

Insertion sort handles this very nicely.

---

**2. The array is small**

For small datasets, insertion sort is simple and can be quite efficient.

---

**3. You are receiving data one-by-one**

Imagine:

```text
5
2
8
3
```

and you want to keep the collection sorted as new values arrive.

Insertion-style insertion can be useful.

---

# 7. Time Complexity

For insertion sort:

### Best case

Array is already sorted:

```text
[1, 2, 3, 4, 5]
```

Almost no shifting happens.

```text
O(n)
```

### Worst case

Array is reverse sorted:

```text
[5, 4, 3, 2, 1]
```

Almost every element needs to move across the entire sorted section.

```text
O(n²)
```

### Average case

```text
O(n²)
```

Space:

```text
O(1)
```

because we don't create another array.

---

## The one thing I want you to remember

Don't memorize the code first.

Understand this picture:

```text
[ SORTED | UNSORTED ]
          ↑
        take this

[ SORTED | key ]
          ↓
    compare left

    bigger?
       ↓
     SHIFT →

    smaller?
       ↓
    INSERT HERE
```

So the code naturally becomes:

```cpp
for (int i = 1; i < n; i++) {

    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = key;
}
```

**Take → shift bigger elements → insert the key.**

That's insertion sort.
