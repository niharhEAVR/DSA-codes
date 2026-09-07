# Please read this after completing the basic dsa concepts:


Excellent. This is one of the **biggest misconceptions** beginners have.

Most people learn:

> "Nested loops = O(n²)"

**This is NOT always true.**

The correct rule is:

> **Time complexity depends on the total number of times the inner statement executes, not on the number of loops.**

Let's understand this from scratch.

---

# Case 1: Nested loops that ARE O(n²)

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        cout << "*";
    }
}
```

Let's take `n = 4`.

### First iteration (`i = 0`)

Inner loop:

```
j = 0
j = 1
j = 2
j = 3
```

Runs **4 times**.

---

### Second iteration (`i = 1`)

Again runs

```
4 times
```

---

It continues.

| Outer Loop | Inner Loop Runs |
| ---------- | --------------- |
| 1          | 4               |
| 2          | 4               |
| 3          | 4               |
| 4          | 4               |

Total work

```
4 + 4 + 4 + 4 = 16
```

which is

```
4 × 4
```

Generalizing,

```
n × n = n²
```

Therefore

```
O(n²)
```

---

# Case 2: Triangular loop

```cpp
for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
        cout << "*";
    }
}
```

Beginners often say

> "Two loops = O(n²)."

Let's actually count.

Take

```
n = 5
```

---

When

```
i = 0
```

Inner loop

```
0 1 2 3 4
```

Runs

```
5 times
```

---

When

```
i = 1
```

Runs

```
4 times
```

---

When

```
i = 2
```

Runs

```
3 times
```

---

When

```
i = 3
```

Runs

```
2 times
```

---

When

```
i = 4
```

Runs

```
1 time
```

Total

```
5 + 4 + 3 + 2 + 1
```

=

```
15
```

Formula:

```
n + (n-1) + (n-2) + ... + 1
```

which equals

[
\frac{n(n+1)}{2}
]

Big-O ignores constants.

So

[
\frac{n^2+n}{2}
]

becomes

```
O(n²)
```

Still quadratic, but **for a different reason**.

---

# Case 3: Nested loops that are NOT O(n²)

Now look carefully.

```cpp
int i = 0;
int j = 0;

while (i < n && j < n) {
    i++;
    j++;
}
```

Someone might think

```
Two variables

↓

Two loops?

↓

O(n²)
```

No.

Both variables move together.

If

```
n = 5
```

Iterations:

```
i=0 j=0

↓

i=1 j=1

↓

i=2 j=2

↓

i=3 j=3

↓

i=4 j=4

↓

stop
```

Only

```
5 iterations
```

Complexity

```
O(n)
```

---

# Case 4: The famous Two Pointer technique

```cpp
int left = 0;
int right = n - 1;

while (left < right) {

    if (...) {
        left++;
    } else {
        right--;
    }
}
```

There are **two pointers**.

Many beginners think

```
left moves

right moves

↓

O(n²)
```

Wrong.

Each iteration moves **only one pointer**.

For

```
n = 10
```

```
left can move at most 10 times

right can move at most 10 times
```

Total movement

```
20
```

Big-O ignores constants.

So

```
O(n)
```

This is why many two-pointer algorithms are linear even though two indices are involved.

---

# Case 5: Sliding Window

```cpp
while (right < n) {

    while (window is invalid) {
        left++;
    }

    right++;
}
```

This looks scary.

Two loops!

Nested!

Must be O(n²)... right?

No.

Let's see why.

Suppose

```
n = 8
```

Initially

```
left = 0
right = 0
```

During the whole algorithm,

```
right
```

only moves

```
0 → 1 → 2 → 3 → ... → 7
```

Exactly **8 moves**.

Similarly,

```
left
```

also only moves forward.

It never goes backward.

Maximum

```
8 moves
```

Total work

```
8 + 8 = 16
```

General

```
n + n
```

=

```
2n
```

Big-O ignores constants.

Therefore

```
O(n)
```

This idea is called **amortized analysis**: although the inner loop can run many times in one iteration, over the entire algorithm each pointer advances only a limited number of times.

---

# Case 6: Binary Search inside a loop

```cpp
for (int i = 0; i < n; i++) {
    binarySearch(arr, x);
}
```

Outer loop

```
n times
```

Binary Search

```
log n
```

Multiply

```
n × log n
```

Complexity

```
O(n log n)
```

Not

```
O(n²)
```

---

# The golden rule

Never count loops.

**Count how many times the important operation executes.**

For example:

```cpp
for (...) {
    for (...) {
        sum++;
    }
}
```

Ask:

> **How many times does `sum++` execute?**

That number determines the time complexity.

---

# A quick summary

| Code Pattern                     | Time Complexity    |
| -------------------------------- | ------------------ |
| One loop                         | O(n)               |
| Two independent loops            | O(n) + O(n) = O(n) |
| Two full nested loops            | O(n²)              |
| Outer loop + Binary Search       | O(n log n)         |
| Two pointers moving only forward | O(n)               |
| Sliding window                   | O(n)               |
| Divide by 2 or 10 repeatedly     | O(log n)           |

---

This "nested loops are not always O(n²)" idea is one of the most important concepts in DSA. Once you understand it, you'll analyze algorithms based on **how much total work is done**, not just how the code is written. That's exactly how experienced programmers think.
