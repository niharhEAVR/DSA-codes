Excellent question.

A **recursion tree** is one of the most important concepts in recursion because it lets you **see every recursive call** as a tree. It is especially useful for:

* Calculating **Time Complexity (TC)**
* Understanding **how recursive calls are made**
* Solving Divide & Conquer algorithms like Merge Sort and Quick Sort
* Understanding problems like Fibonacci

Let's build the idea from scratch.

---

# What is a Recursion Tree?

A recursion tree is simply a **tree representation of all recursive function calls**.

Think of it like this:

Every time a function calls itself,
draw a child node.

So instead of imagining the program,

```text
function()
```

you draw

```text
      function()
      /
function()
```

If it calls itself twice,

```text
         function()
        /          \
 function()     function()
```

Every node is **one function call**.

---

# Example 1 — Simple Recursion

Suppose

```cpp
void fun(int n)
{
    if(n==0)
        return;

    cout<<n<<" ";

    fun(n-1);
}
```

Call

```cpp
fun(4);
```

---

The recursion tree becomes

```text
fun(4)
   |
fun(3)
   |
fun(2)
   |
fun(1)
   |
fun(0)
```

Notice something.

There is only **one child**.

Because

```cpp
fun(n)
```

calls only

```cpp
fun(n-1)
```

This is called **Linear Recursion**.

---

# Execution

First it goes downward.

```text
fun(4)

↓

fun(3)

↓

fun(2)

↓

fun(1)

↓

fun(0)
```

Then

Base Case

Now it returns upward.

```text
fun(1)

↑

fun(2)

↑

fun(3)

↑

fun(4)
```

Exactly like climbing down a ladder and climbing back.

---

# Example 2 — Factorial

```cpp
int fact(int n)
{
    if(n==1)
        return 1;

    return n * fact(n-1);
}
```

Suppose

```cpp
fact(5)
```

Tree

```text
fact(5)
   |
fact(4)
   |
fact(3)
   |
fact(2)
   |
fact(1)
```

Going downward

```text
Need fact(4)

Need fact(3)

Need fact(2)

Need fact(1)
```

Coming upward

```text
fact(1)=1

fact(2)=2×1

fact(3)=3×2

fact(4)=4×6

fact(5)=5×24
```

Notice

The multiplication happens while returning.

---

# Example 3 — Fibonacci (The Most Important)

Now look at

```cpp
int fib(int n)
{
    if(n<=1)
        return n;

    return fib(n-1)+fib(n-2);
}
```

Suppose

```cpp
fib(5)
```

Tree

```text
                  fib(5)
                /        \
           fib(4)       fib(3)
          /     \       /     \
      fib(3) fib(2) fib(2) fib(1)
      /   \    /  \   /  \
 fib(2) fib(1)1 0 1 0
 /   \
1     0
```

Notice

Every function creates

Two children.

Because

```cpp
fib(n)
```

calls

```cpp
fib(n-1)

fib(n-2)
```

---

# Observe Carefully

Look at this.

```text
fib(3)
```

appears

Twice.

```text
fib(2)
```

appears

Three times.

The computer keeps solving

the same problem

again

and again

and again.

That's why Fibonacci recursion is slow.

---

# Why Draw a Recursion Tree?

There are three major reasons.

---

## 1. To Understand Calls

Instead of imagining

```cpp
fib(5)
```

you can literally see

```text
fib(5)

├── fib(4)

└── fib(3)
```

Very easy.

---

## 2. To Find Time Complexity

Suppose every node does

```cpp
1 operation
```

Then

Total Time

=

Number of Nodes.

For Fibonacci

The number of nodes grows almost exponentially.

Therefore

```text
Time Complexity ≈ O(2ⁿ)
```

---

## 3. To Solve Divide and Conquer

Merge Sort

Quick Sort

Binary Search

Segment Tree

All use recursion trees.

---

# Difference Between Call Stack and Recursion Tree

Many students confuse these.

## Call Stack

Shows **which functions are currently active**.

```text
fun(4)

↓

fun(3)

↓

fun(2)
```

Memory

```text
fun(2)
fun(3)
fun(4)
```

---

## Recursion Tree

Shows **every recursive call**.

```text
fun(4)
   |
fun(3)
   |
fun(2)
   |
fun(1)
```

One is memory.

One is visualization.

---

# A Trick to Draw Any Recursion Tree

Whenever you see recursion,

ask

> **How many recursive calls does one function make?**

If one recursive call

```cpp
fun(n-1);
```

Tree

```text
O
|
O
|
O
|
O
```

---

If two recursive calls

```cpp
fun(n-1);

fun(n-2);
```

Tree

```text
      O
     / \
    O   O
   /\   /\
```

---

If four recursive calls

```cpp
fun()

fun()

fun()

fun()
```

Tree

```text
          O
      / / | \
     O O  O  O
```

Just draw one child for each recursive call.

---

# Golden Rule

Whenever you see recursion, ask these questions in order:

1. **How many recursive calls does one function make?**
   → This tells you the **shape** of the recursion tree.

2. **When does recursion stop?**
   → This tells you where the **leaf nodes** (base cases) are.

3. **What work is done at each node?**
   → This helps calculate the **time complexity**.

---

## Visual Summary

```text
                    RECURSION

            One recursive call
                   │
                   ▼
                Linear Tree

                  A
                  |
                  B
                  |
                  C
                  |
                  D

      Time ≈ Number of Nodes = O(n)


            Two recursive calls
                   │
                   ▼
                Binary Tree

                    A
                  /   \
                 B     C
               /  \   /  \
              D   E  F   G

      Time grows much faster (often exponential if work repeats, like naive Fibonacci).
```

Once you understand recursion trees, you'll find it much easier to analyze recursive algorithms, especially when you move on to Merge Sort, Quick Sort, Binary Trees, and Dynamic Programming.
