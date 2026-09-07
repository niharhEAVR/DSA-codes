Yep! Let's do **Bubble Sort** the same way — from the absolute basic idea first, then code, then complexity and where it's used.

## 1. What is Bubble Sort?

The easiest definition is:

> **Bubble Sort repeatedly compares two neighboring elements and swaps them if they are in the wrong order.**

For ascending order:

```text
if left > right
    → swap them
```

The interesting part is that after every complete pass, the **largest unsorted element moves ("bubbles") to the end**.

genui{"learning_viz":{"type_id":"BUBBLE_SORT"}}

---

## 2. Example

Take:

```text
[5, 3, 8, 1, 2]
```

We compare **neighbors**.

### First comparison

```text
5  3  8  1  2
↑  ↑
```

Is `5 > 3`?

Yes → swap.

```text
[3, 5, 8, 1, 2]
```

---

### Next comparison

Now compare:

```text
3  5  8  1  2
   ↑  ↑
```

Is `5 > 8`?

No.

So nothing happens:

```text
[3, 5, 8, 1, 2]
```

---

### Next comparison

```text
3  5  8  1  2
      ↑  ↑
```

Is `8 > 1`?

Yes → swap:

```text
[3, 5, 1, 8, 2]
```

---

### Next comparison

```text
[3, 5, 1, 8, 2]
         ↑  ↑
```

Is `8 > 2`?

Yes → swap:

```text
[3, 5, 1, 2, 8]
```

Notice something:

```text
[3, 5, 1, 2, 8]
            ↑
         largest
```

`8` has **bubbled to the end**.

That's why it's called **Bubble Sort**.

---

# 3. Then we repeat

Now `8` is already in its correct position, so we don't need to touch it again.

We work with:

```text
[3, 5, 1, 2 | 8]
```

Compare:

```text
3 and 5 → no swap
5 and 1 → swap
1 and 2 → no swap
```

Result:

```text
[3, 1, 2, 5 | 8]
```

Now `5` is also in its correct position.

Then:

```text
[3, 1, 2 | 5, 8]
```

Next pass:

```text
3 and 1 → swap
1 and 2 → no swap
```

Result:

```text
[1, 3, 2 | 5, 8]
```

Next:

```text
3 and 2 → swap
```

Result:

```text
[1, 2, 3, 5, 8]
```

Sorted!

---

# 4. How is it implemented?

Here's the basic implementation:

```cpp
void bubbleSort(vector<int>& arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
```

The **most important line** is:

```cpp
if (arr[j] > arr[j + 1])
```

We're comparing **adjacent elements**:

```text
arr[j]       arr[j+1]
   ↓            ↓
  [5]          [3]
```

If:

```text
5 > 3
```

we swap:

```text
[3, 5]
```

---

# 5. Why `n - i - 1`?

This is probably the part that initially looks confusing.

Remember our first pass:

```text
[3, 5, 1, 2, 8]
             ↑
          sorted
```

After the first pass, `8` is guaranteed to be at the end.

So next time we don't need to compare it.

After the second pass:

```text
[3, 1, 2, 5, 8]
          ↑     ↑
        sorted sorted
```

So every pass gives us one more element at the end that doesn't need to be checked.

That's why:

```cpp
j < n - i - 1
```

### Think of it like this:

```text
Pass 1:
[ ?, ?, ?, ?, 8 ]
              ↑
           don't touch

Pass 2:
[ ?, ?, ?, 5, 8 ]
           ↑  ↑
        don't touch

Pass 3:
[ ?, ?, 3, 5, 8 ]

Pass 4:
[1, 2, 3, 5, 8]
```

---

# 6. Bubble Sort vs Selection Sort

This distinction is **very important** for DSA.

### Selection Sort

It asks:

> "What is the smallest element in the remaining array?"

Then puts it at the beginning.

```text
Find minimum → Swap
```

Example:

```text
[5, 3, 8, 1, 2]

Find 1
↓
[1, 3, 8, 5, 2]
```

---

### Bubble Sort

It asks:

> "Are these two neighboring elements in the wrong order?"

Then swaps them.

```text
Compare neighbors → Swap if needed
```

Example:

```text
[5, 3, 8, 1, 2]

5 > 3 → swap
3 < 8 → don't swap
8 > 1 → swap
8 > 2 → swap
```

So remember:

```text
Selection Sort:
FIND minimum

Bubble Sort:
COMPARE neighbors
```

That's the main difference.

---

# 7. Time and Space Complexity

Basic Bubble Sort:

```text
Worst case  → O(n²)
Average     → O(n²)
Best case   → O(n²)
Space       → O(1)
```

But there is an **optimized version**.

We can detect if no swaps happened during a pass:

```cpp
void bubbleSort(vector<int>& arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}
```

Suppose the array is already sorted:

```text
[1, 2, 3, 4, 5]
```

First pass:

```text
1 < 2 → no swap
2 < 3 → no swap
3 < 4 → no swap
4 < 5 → no swap
```

`swapped` remains `false`.

So:

```cpp
if (!swapped)
    break;
```

We stop immediately.

Therefore optimized Bubble Sort has:

```text
Best case → O(n)
Worst case → O(n²)
Space → O(1)
```

---

## The one thing I want you to remember

For your DSA preparation, don't memorize the entire code first. Remember the **movement pattern**:

### Selection Sort

```text
Find smallest
      ↓
Put it at front
      ↓
Repeat
```

### Bubble Sort

```text
Compare neighbors
      ↓
Swap if wrong
      ↓
Largest moves to end
      ↓
Repeat
```

Once these two ideas are clear, the code becomes much easier to write.



---
---
---
---
---
---
---
---
---
---
---


Yes — and there's an important distinction here between **the algorithm's space complexity** and **whether you're passing an array by reference**.

## 1. Where is Bubble Sort used?

Honestly, **Bubble Sort is rarely used in real-world applications** for large data.

Why?

Because its worst/average time is:

```text
O(n²)
```

For a large array, that's slow.

It's mainly useful for:

* **Learning DSA** — understanding sorting, loops, swapping, complexity.
* **Very small datasets** where simplicity matters more than speed.
* **Nearly sorted data**, especially with the optimized version, where it can finish quickly.
* **Teaching/interview questions** — because the logic is simple and tests whether you understand sorting.

In real C++ programs, you'd normally use:

```cpp
sort(arr, arr + n);
```

or:

```cpp
sort(v.begin(), v.end());
```

rather than manually implementing Bubble Sort.

---

# 2. Now your question about normal arrays

Suppose you have:

```cpp
void bubbleSort(int arr[], int n)
{
    // sorting
}
```

and:

```cpp
int arr[] = {5, 3, 8, 1, 2};

bubbleSort(arr, 5);
```

You might think:

> "I'm passing `arr` to the function. Isn't a new array being created?"

**No.**

This is the important part:

```cpp
int arr[]
```

in a function parameter is actually treated as:

```cpp
int* arr
```

So the function receives the **address of the first element**, not a complete copy of the array.

Think of it like:

```text
Original array:

arr
 ↓
[5][3][8][1][2]
 ↑
 |
 address
 |
Function receives this address
```

There is **no new 5-element array** created.

---

# 3. What about the `&`?

This is different from vectors.

With a vector:

```cpp
void bubbleSort(vector<int>& arr)
```

we use `&` to avoid copying the vector.

Without `&`:

```cpp
void bubbleSort(vector<int> arr)
```

a complete vector copy is created → **O(n)** extra space.

But with a normal C-style array:

```cpp
void bubbleSort(int arr[], int n)
```

you don't need `&`.

Because the array parameter automatically behaves like a pointer:

```cpp
void bubbleSort(int arr[], int n)
```

is essentially:

```cpp
void bubbleSort(int* arr, int n)
```

---

# 4. So what's the space complexity?

Consider:

```cpp
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
```

The algorithm creates only:

```text
i → one integer
j → one integer
```

and `swap()` uses a constant amount of temporary storage.

So:

**Auxiliary Space = O(1)**

The original array itself is **not counted as extra space**, because it was already given as input.

---

## 5. Very important distinction

Suppose the input is:

```text
[5, 3, 8, 1, 2]
```

### Case A — Normal array

```cpp
void bubbleSort(int arr[], int n)
```

No array copy.

```text
Input array
    ↓
[5][3][8][1][2]
    ↑
function works directly on it
```

**Extra space = O(1)**

---

### Case B — Vector with reference

```cpp
void bubbleSort(vector<int>& arr)
```

No vector copy.

**Extra space = O(1)**

---

### Case C — Vector without reference

```cpp
void bubbleSort(vector<int> arr)
```

A new vector is created:

```text
Original:  [5][3][8][1][2]
                ↓ copy
Function:  [5][3][8][1][2]
```

**Extra space = O(n)**

---

### Easy rule to remember

```text
Normal array:
int arr[]
      ↓
already behaves like pointer
      ↓
NO copy

Vector:
vector<int> arr
      ↓
COPY

Vector:
vector<int>& arr
      ↓
NO copy
```

So when you see:

```cpp
void bubbleSort(int arr[], int n)
```

you should **not** think "new array is being created."

It's basically:

```cpp
void bubbleSort(int* arr, int n)
```

and the function is working directly on your original array.
