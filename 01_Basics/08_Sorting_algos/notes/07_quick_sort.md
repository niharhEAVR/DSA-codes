## 🔥 What is Quick Sort?

**Quick Sort is a Divide & Conquer sorting algorithm**, just like Merge Sort.

The main idea is:

> **Pick one element as a `pivot`, put it in its correct position, then do the same thing on the left and right parts.**

Think of it like this:

```text
[ 7  2  1  6  8  5  3  4 ]

Choose pivot = 4

Smaller than 4       Pivot       Greater than 4
[ 2  1  3 ]            4          [ 7  6  8  5 ]
```

Now **4 is in its final/correct position**.

Then we recursively sort:

```text
[2 1 3]                [7 6 8 5]
   ↓                       ↓
choose pivot            choose pivot
   ↓                       ↓
sort them                sort them
```

Eventually:

```text
[1 2 3]  4  [5 6 7 8]

        ↓

[1 2 3 4 5 6 7 8]
```

---

# 🧠 The most important thing

Quick Sort does **NOT** work like Merge Sort.

### Merge Sort:

```text
Split
 ↓
[7 2 1 6] [8 5 3 4]
 ↓
Split again
 ↓
...
 ↓
Merge everything
```

### Quick Sort:

```text
Choose pivot
      ↓
Put pivot in correct position
      ↓
Left side | Pivot | Right side
      ↓
Recursively sort both sides
```

So the key operation in Quick Sort is:

> **PARTITION**

---

# 🎯 What is partition?

Suppose:

```text
[7, 2, 1, 6, 8, 5, 3, 4]
```

Choose:

```text
pivot = 4
```

After partitioning, we want:

```text
[2, 1, 3]  4  [7, 6, 8, 5]
             ↑
           pivot
```

We don't necessarily get the left and right sides sorted yet.

We only guarantee:

```text
EVERYTHING LEFT OF 4 < 4

EVERYTHING RIGHT OF 4 > 4
```

Then Quick Sort recursively handles those two sides.

---

# 🚀 Why is it called "Quick" Sort?

Because on average it is:

```text
O(n log n)
```

which is very fast for sorting large arrays.

Its average performance is similar to Merge Sort:

```text
Merge Sort  → O(n log n)
Quick Sort  → O(n log n) average
```

But Quick Sort has an important advantage:

### Merge Sort

Needs extra array space:

```text
O(n)
```

### Quick Sort

Can be implemented **in-place**, so it usually needs only recursion stack:

```text
O(log n) average
```

That's one reason Quick Sort is very popular.

---

# 📍 Where is Quick Sort used?

Quick Sort is useful when you need to **sort a large collection efficiently**, especially when:

* You want **fast average-case sorting**
* You want **low extra memory usage**
* You are working with arrays/vectors
* You don't specifically need a stable sort

For example:

```cpp
vector<int> arr = {7, 2, 1, 6, 8, 5, 3, 4};
```

Quick Sort can efficiently sort it:

```text
1 2 3 4 5 6 7 8
```

---

## ⚠️ One important problem

Quick Sort's performance depends heavily on the **pivot**.

Good pivot:

```text
[1 2 3 4 5 6 7]

       ↑
     pivot
```

If pivot is near the middle, the array divides reasonably well.

Bad pivot:

```text
[1 2 3 4 5 6 7]

↑
pivot
```

Then you get something like:

```text
[ ] 1 [2 3 4 5 6 7]
```

Then again:

```text
[ ] 2 [3 4 5 6 7]
```

This can make Quick Sort:

```text
O(n²)
```

in the worst case.

---

### So remember Quick Sort in ONE line:

> **Choose a pivot → partition the array around it → recursively sort the left and right parts.**

And **partition is the heart of Quick Sort**.

Since you're learning this for DSA, the next thing you should understand is **exactly how partition works with `i` and `j` pointers**, because that's where Quick Sort usually becomes confusing.




---
---
---




Ahh, yes 😄 — you mean **“show me how Quick Sort is actually written in C++.”**

Let's build it from the idea we just learned.

### 1. The main Quick Sort function

```cpp
void quickSort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);   // left side
        quickSort(arr, pivotIndex + 1, high);  // right side
    }
}
```

The important thing here is:

```cpp
int pivotIndex = partition(arr, low, high);
```

`partition()` does the actual work of:

> **putting the pivot in its correct position.**

---

## 2. The `partition()` function

We'll use the **last element as pivot**.

```cpp
int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;

            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}
```

---

# 3. Complete code

```cpp
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    vector<int> arr = {7, 2, 1, 6, 8, 5, 3, 4};

    quickSort(arr, 0, arr.size() - 1);

    for (int x : arr)
        cout << x << " ";
}
```

Output:

```text
1 2 3 4 5 6 7 8
```

---

## 🧠 But don't memorize this code yet

The **only difficult part** is understanding this:

```cpp
int i = low - 1;

for (int j = low; j < high; j++)
{
    if (arr[j] < pivot)
    {
        i++;
        swap(arr[i], arr[j]);
    }
}
```

Think of the two variables like this:

```text
i → boundary of SMALL elements
j → scans the array
```

For:

```text
[7, 2, 1, 6, 8, 5, 3, 4]
                         ↑
                       pivot
```

`j` walks through:

```text
7 → 2 → 1 → 6 → 8 → 5 → 3
```

Whenever `j` finds something **smaller than pivot**, we move `i` forward and put that small element on the left.

Finally:

```cpp
swap(arr[i + 1], arr[high]);
```

puts the pivot between the smaller and larger elements.

**That's the entire trick behind this version of Quick Sort.**

If you understand `i`, `j`, and that final `swap`, you understand the core of Quick Sort.
