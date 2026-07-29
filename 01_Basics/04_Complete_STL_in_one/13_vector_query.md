Excellent question. This is exactly why `std::vector` sometimes has to **reallocate** its memory.

Let's walk through it step by step.

### Initially

Suppose your vector looks like this:

```
Memory

1000   1004   1008
+----+ +----+ +----+
| 10 | | 20 | | 30 |
+----+ +----+ +----+

vector = {10, 20, 30}
size = 3
capacity = 3
```

The vector owns this contiguous block from address `1000` to `1008`.

Now you do:

```cpp
v.push_back(40);
```

The vector needs one more contiguous location:

```
1012
+----+
| ?? |
+----+
```

But imagine that address `1012` is already being used by another object or another part of your program.

```
1000 1004 1008 1012
10   20   30   XYZ   <- occupied
```

The vector **cannot** simply continue.

Why?

Because a vector guarantees that all elements are stored contiguously.

It cannot have:

```
10 20 30       40
1000 1004 1008 5000
```

That would no longer be contiguous.

---

## So what does vector do?

It asks the heap (using the memory allocator):

> "Please give me a new contiguous block that's large enough."

Suppose the allocator finds space starting at address `5000`.

```
5000 5004 5008 5012 5016 5020
```

Now the vector:

### Step 1

Allocates a larger block.

```
Old block

1000 1004 1008
10   20   30

New block

5000 5004 5008 5012 5016 5020
```

---

### Step 2

Copies (or moves) every element.

```
5000 5004 5008
10   20   30
```

---

### Step 3

Inserts the new element.

```
5000 5004 5008 5012
10   20   30   40
```

---

### Step 4

Frees the old memory.

```
1000 1004 1008
^^^^ old block returned to the heap
```

Now the vector internally stores the new starting address (`5000`).

---

## This is called **reallocation**.

It usually happens when:

```
size == capacity
```

and you insert another element.

---

## Why does vector usually double the capacity?

Instead of allocating just one more slot:

```
3 → 4
```

it often allocates much more:

```
3 → 6
or
4 → 8
or
8 → 16
```

This way, the next several `push_back()` operations don't need another expensive reallocation.

For example:

```
capacity = 3

push_back()

↓

capacity becomes 6

Memory

5000
5004
5008
5012
5016
5020

10
20
30
40
__
__
```

The last two locations are empty but already reserved.

---

## What if the allocator cannot find a large enough contiguous block anywhere?

For example, suppose you need 100 MB of contiguous memory, but the heap is fragmented and no single 100 MB block exists.

Then the allocation fails.

The vector throws an exception:

```cpp
std::bad_alloc
```

which means memory allocation failed.

---

## A real-life analogy

Imagine you're sitting in a row of seats:

```
🙂 🙂 🙂
```

You want one more friend to sit next to you.

But the next seat is already occupied.

```
🙂 🙂 🙂 😎
```

You can't magically squeeze your friend in.

Instead, everyone gets up and moves to another row with more empty seats:

```
🙂 🙂 🙂 🙂
_  _  _
```

That's exactly what `std::vector` does during reallocation.

---

### One important consequence

Because the vector may move to a completely new memory location, **all pointers, references, and iterators to its elements become invalid after a reallocation**.

```cpp
std::vector<int> v = {10, 20, 30};

int* p = &v[0];

v.push_back(40); // may reallocate

// p might now point to freed memory!
```

This is one of the most important things to remember when using `std::vector`.

So your understanding is correct: if the next contiguous memory location is occupied, the vector **does not** try to grow in place. Instead, it allocates an entirely new contiguous block elsewhere, moves/copies all elements there, frees the old block, and continues.
