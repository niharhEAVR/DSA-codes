This is an excellent question because **Segmentation Fault** is one of the most common runtime errors in C and C++. To understand it forever, you first need to understand **memory**.

---

# What is a Segmentation Fault?

A **Segmentation Fault (Segfault)** occurs when your program tries to **access memory that it is not allowed to access**.

Think of memory as a huge apartment building.

```text
Memory

+-----------------------+
| Apartment 1           |
| Apartment 2           |
| Apartment 3           |
| Apartment 4           |
| Apartment 5           |
+-----------------------+
```

Your program is given permission to enter only certain apartments.

If it tries to enter someone else's apartment...

🚨

The operating system immediately stops your program.

That crash is called a **Segmentation Fault**.

---

# Why is it called "Segmentation"?

Memory is divided into different **segments** (regions).

For example:

```text
+----------------------+
| Code Segment         |
+----------------------+
| Global Variables     |
+----------------------+
| Heap                 |
+----------------------+
| Stack                |
+----------------------+
```

Each segment has rules.

For example:

* Code segment → execute instructions
* Stack → local variables and function calls
* Heap → dynamically allocated memory

If your program violates these rules or accesses an invalid address, the OS raises a segmentation fault.

---

# Example 1: Accessing a Null Pointer

```cpp
int *ptr = nullptr;

cout << *ptr;
```

Memory

```text
ptr
 │
 ▼
NULL
```

You're asking:

> "Give me the value stored at address 0."

There is no valid memory there.

Result:

```text
Segmentation Fault
```

---

# Example 2: Invalid Pointer

```cpp
int *ptr;

*ptr = 10;
```

Here,

`ptr` contains garbage because it was never initialized.

Example:

```text
ptr

↓

0xAB23456
```

Maybe that address belongs to another process.

The OS says:

> ❌ No.

Crash.

---

# Example 3: Array Out of Bounds

```cpp
int arr[5];

arr[100] = 10;
```

Array

```text
Index

0
1
2
3
4
```

You asked for

```text
100
```

That memory doesn't belong to your array.

Sometimes it crashes.

Sometimes it doesn't (this is **undefined behavior**).

---

# Example 4: Infinite Recursion

```cpp
void fun()
{
    fun();
}
```

Every recursive call creates a new stack frame.

```text
fun()

↓

fun()

↓

fun()

↓

fun()

↓

fun()

↓

...
```

Eventually,

```text
Stack Memory
```

becomes full.

The program can no longer create another function call.

Result:

```text
Stack Overflow
```

On most systems, this eventually appears as a **Segmentation Fault**, because the program tries to grow the stack into memory it is not allowed to use.

---

# Example 5: Using Deleted Memory

```cpp
int *ptr = new int(10);

delete ptr;

cout << *ptr;
```

Imagine

```text
new int

↓

Memory allocated
```

Then

```text
delete
```

The memory is returned to the system.

Now

```cpp
*ptr
```

tries to use memory that no longer belongs to you.

This is called a **dangling pointer**.

It may:

* Crash
* Print garbage
* Seem to work

All are undefined behavior.

---

# Example 6: Accessing Freed Array

```cpp
int *arr = new int[100];

delete[] arr;

arr[5] = 100;
```

Same problem.

Memory is gone.

Still trying to use it.

Possible Segmentation Fault.

---

# Stack Overflow vs Segmentation Fault

Many students think they're the same.

They are **not**.

## Stack Overflow

Means

> The stack memory is exhausted.

Usually because of:

* Infinite recursion
* Very large local variables

---

## Segmentation Fault

Means

> Invalid memory access.

Stack overflow is **one possible cause** of a segmentation fault, but there are many others.

---

# Why Doesn't Every Invalid Access Crash?

Consider

```cpp
int arr[5];

arr[6] = 100;
```

Maybe memory looks like

```text
arr

0
1
2
3
4
5
6
```

Index 6 might accidentally point to another valid location in your program.

The CPU doesn't know it's logically wrong.

So the program might continue.

That's why C++ calls it:

> **Undefined Behavior**

Sometimes:

```text
Works

Sometimes

Garbage

Sometimes

Segmentation Fault
```

---

# Real Memory Picture

Suppose

```cpp
int a = 5;
```

Memory

```text
Address      Value

1000         5
```

Pointer

```cpp
int *p = &a;
```

```text
p

↓

1000
```

Access

```cpp
*p
```

Reads

```text
1000
```

Everything is valid.

---

Now

```cpp
int *p = (int*)999999999;
```

Memory

```text
999999999
```

Probably doesn't belong to your program.

When you do

```cpp
*p
```

The OS immediately stops you.

Segmentation Fault.

---

# Common Causes in DSA

While solving DSA problems, you'll most often see segmentation faults because of:

* ❌ Infinite recursion (missing base case)
* ❌ Accessing `nullptr`
* ❌ Wrong array index
* ❌ Incorrect linked list pointer (`head->next` when `head == nullptr`)
* ❌ Accessing an empty vector with invalid indexing
* ❌ Using memory after deleting it
* ❌ Dereferencing an uninitialized pointer

---

# Easy Way to Remember

Think of your program as a guest in a hotel.

* You have a room key (permission to access certain memory).
* You can enter **your own room**.
* You **cannot** enter someone else's room.

If you try...

🚔 Security throws you out immediately.

That "security" is the **operating system**, and being thrown out is a **Segmentation Fault**.

---

# Final Summary

| Term                         | Meaning                                                                                              |
| ---------------------------- | ---------------------------------------------------------------------------------------------------- |
| **Segmentation Fault**       | Your program accessed memory it doesn't have permission to access.                                   |
| **Stack Overflow**           | The stack memory became full (often due to infinite recursion).                                      |
| **Null Pointer Dereference** | Accessing memory through `nullptr`.                                                                  |
| **Dangling Pointer**         | Using memory after it has been freed.                                                                |
| **Out-of-Bounds Access**     | Reading or writing beyond an array or container's valid range.                                       |
| **Undefined Behavior**       | Incorrect code whose result is unpredictable—it may appear to work, produce wrong results, or crash. |

## One sentence to remember for life:

> **A segmentation fault happens when your program tries to read from or write to memory that it does not own or is not allowed to access.**
