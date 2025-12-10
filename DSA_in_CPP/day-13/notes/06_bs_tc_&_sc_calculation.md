# ⭐ 1. What happens inside Binary Search?

Binary Search always does the following:

* Look at the middle element
* Throw away **half** of the array
* Repeat on the remaining half

So the **search space shrinks by 1/2 each time**.

---

# ⭐ 2. Mathematical Analysis of Time Complexity

Let’s assume:

* Array size = **N**
* Each iteration reduces the size to **N/2**

So the number of operations:

1st step → N
2nd step → N/2
3rd step → N/4
4th step → N/8
…
k-th step → N / 2^k

Binary search stops when the remaining size becomes 1.

So:

\[
\frac{N}{2^k} = 1
\]

Solve this for **k**:

\[
N = 2^k
\]

Take log base 2 (because binary) on both sides:

\[
\log_2(N) = k
\]

This means:

👉 **Binary Search makes log₂(N) iterations**

Thus:

\[
\boxed{T(N) = O(\log N)}
\]

---

# ⭐ 3. Full Time Complexity Derivation (Proper Math)

Binary search recurrence relation:

\[
T(N) = T(N/2) + 1
\]

We expand this:

```
T(N) = T(N/2) + 1
      = T(N/4) + 2
      = T(N/8) + 3
      = T(N/16) + 4
      ...
      = T(N / 2^k) + k
```

It ends when:

\[
N / 2^k = 1 \Rightarrow 2^k = N \Rightarrow k = \log_2 N
\]

So,

\[
T(N) = \log_2 N + 1
\]

Final:

\[
\boxed{T(N) = O(\log N)}
\]

---

# ⭐ 4. Visual Example (Best for understanding)

Let's take an array of size:

\[
N = 16
\]

Binary search splits like this:

| Step | Remaining Elements | Operation Count |
| ---- | ------------------ | --------------- |
| 1    | 16                 | 1               |
| 2    | 8                  | 2               |
| 3    | 4                  | 3               |
| 4    | 2                  | 4               |
| 5    | 1                  | 5               |

Binary Search stops after **5 steps**.

Now check:

\[
\log_2(16) = 4
\]

We got 5 because there's +1 initial step.
Still complexity is:

\[
O(\log N)
\]

---

# ⭐ 5. More examples to feel the growth

| N (array size) | log₂(N) | Steps           |
| -------------- | ------- | --------------- |
| 8              | 3       | ~3 steps        |
| 16             | 4       | ~4 steps        |
| 128            | 7       | ~7 steps        |
| 1,024          | 10      | ~10 steps       |
| 1,000,000      | ~20     | ~20 steps       |
| 1,000,000,000  | ~30     | only ~30 steps! |

Notice how **N increases insanely**,
but steps increase **very slowly**.

That's why binary search is so powerful.

---

# ⭐ 6. Intuition of O(log n)

Every time you divide by 2, you reduce the problem drastically.

\[
N,; \frac{N}{2},; \frac{N}{4},; \frac{N}{8},; \frac{N}{16},; ...,1
\]

How many times can you divide a number by 2 until it becomes 1?

Exactly **log₂(N)** times.

This is the whole logic.

---

# ⭐ 7. Best, Worst, Average Case

### ✔ Best Case:

Element is at mid on first check
\[
O(1)
\]

### ✔ Worst Case:

We keep halving until one element remains
\[
O(\log N)
\]

### ✔ Average Case:

Still proportional to depth of the search tree
\[
O(\log N)
\]

---

# ⭐ 8. Why logarithm comes in binary search?

Binary search is based on **binary decision-making**:

* go left (0)
* go right (1)

This creates a **binary decision tree** of height log₂(N).

That’s why:

* binary numbers
* binary trees
* binary search

all involve **logarithmic complexity**.

---

# ⭐ Final Summary

\[
\boxed{T(N) = O(\log N)}
\]

Because:

* The problem size is halved each step
* Number of halvings = log₂(N)
* Recurrence: T(N) = T(N/2) + 1
* Depth of binary decision = log₂(N)



---
---
---





# 🔥 **HOW Recursive Binary Search Takes Space — VISUALIZED**

Recursive functions use the **Call Stack**.

Every time a function calls itself, the system allocates:

* function parameters (`low`, `high`, `mid`)
* return address
* local variables

This is stored in a **stack frame**.

The more recursive calls → the more stack frames → the more space used.

Binary Search cuts the array in half every time, so max recursion depth = **log₂(n)**.

---

# 📌 Let's Take Example: Array of Size n = 16

Call:

```
binarySearch(arr, 0, 15)
```

---

# ⭐ STEP 1 — First Call (full array)

```
STACK:
| Call 1: binarySearch(0, 15) |
--------------------------------
```

mid = 7
Suppose target < arr[7], so we search left half.

---

# ⭐ STEP 2 — Second Call (size = 8)

```
STACK:
| Call 2: binarySearch(0, 7)  |
| Call 1: binarySearch(0, 15) |
--------------------------------
```

mid = 3
Target < arr[3], so go left.

---

# ⭐ STEP 3 — Third Call (size = 4)

```
STACK:
| Call 3: binarySearch(0, 3)  |
| Call 2: binarySearch(0, 7)  |
| Call 1: binarySearch(0, 15) |
--------------------------------
```

mid = 1
Target < arr[1], so go left.

---

# ⭐ STEP 4 — Fourth Call (size = 2)

```
STACK:
| Call 4: binarySearch(0, 1)  |
| Call 3: binarySearch(0, 3)  |
| Call 2: binarySearch(0, 7)  |
| Call 1: binarySearch(0, 15) |
--------------------------------
```

mid = 0

---

# ⭐ STEP 5 — Fifth Call (size = 1, base case)

```
STACK:
| Call 5: binarySearch(0, 0)  |
| Call 4: binarySearch(0, 1)  |
| Call 3: binarySearch(0, 3)  |
| Call 2: binarySearch(0, 7)  |
| Call 1: binarySearch(0, 15) |
--------------------------------
```

Now `low == high`, so base case returns.

---

# ⭐ Now the Stack Shrinks (unwinding)

Binary Search returns back step-by-step:

```
POP Call 5
POP Call 4
POP Call 3
POP Call 2
POP Call 1
```

This is called **stack unwinding**.

---

# 📌 Maximum Space Used = Maximum Stack Height

How many calls were stacked at maximum?

There were **5 calls**.

But mathematically:

[
\log_2(16) = 4
]

Binary Search uses **log₂(n)** recursive depth.

Thus:

[
\text{Space Complexity} = O(\log n)
]

---

# 🧠 Why does space grow like this?

Because at each recursive call:

* You WAIT for the answer from the next call
* So your current stack frame *stays alive*
* New frame is added on top

This chain continues until base case.

That’s why recursion = extra memory.

---

# ✔ FINAL ANSWER

### **Recursive Binary Search uses O(log n) space**

because the recursion depth = **log₂(n)**
and each depth adds **one stack frame**.

### **Iterative Binary Search uses O(1) space**

because there is no recursion → no stack growth.
