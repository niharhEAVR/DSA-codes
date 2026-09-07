This is one of the most important topics in DSA. If you truly understand recursion, you'll stop *memorizing* recursive code and start **creating** it yourself.

I'm going to explain recursion from **zero**, as if you've never seen it before. By the end, you should understand not just *what* recursion is, but *how your computer thinks* when executing recursive functions.

---

# What is Recursion?

## The official definition

> **Recursion is a technique where a function calls itself to solve a smaller version of the same problem until a stopping condition is reached.**

But this definition is difficult to visualize.

Let's understand it differently.

---

# Imagine This...

Suppose there are 100 locked doors.

You need to open Door 100.

But there is a rule.

To open Door 100,
you first need Door 99's key.

To open Door 99,
you first need Door 98's key.

Door 98 needs Door 97.

...

Door 2 needs Door 1.

Door 1 doesn't need anything.
It can be opened directly.

So what happens?

```
Open 100
 ↓
Need 99
 ↓
Need 98
 ↓
Need 97
 ↓
...
 ↓
Need 2
 ↓
Need 1
```

Once Door 1 is opened,

you now return.

```
Door 1 opened
↑
Open Door 2
↑
Open Door 3
↑
Open Door 4
↑
...
↑
Open Door 100
```

This is recursion.

Notice something.

You go **down first**.

Then you come **back up**.

Every recursion works exactly like this.

---

# The Three Golden Rules of Recursion

Every recursive function has ONLY three parts.

```
1. Base Case

2. Recursive Case

3. Faith
```

We'll understand each.

---

# Rule 1 — Base Case

This is the stopping condition.

Without it...

the function never stops.

Example

```cpp
void fun()
{
    fun();
}
```

What happens?

```
fun()

calls

fun()

calls

fun()

calls

fun()

calls

fun()

calls

...
```

Forever.

Eventually

```
Stack Overflow
```

Program crashes.

Why?

Because there is no stopping point.

---

Now add a base case.

```cpp
void fun(int n)
{
    if(n==0)
        return;

    fun(n-1);
}
```

Now

```
fun(5)

↓

fun(4)

↓

fun(3)

↓

fun(2)

↓

fun(1)

↓

fun(0)

STOP
```

That's the base case.

---

# Rule 2 — Recursive Case

After checking the base case,

the function should make the problem smaller.

Example

Suppose

```
Print numbers from 5 to 1.
```

Observe.

```
Print 5

Then print

4 to 1
```

How do we print 4 to 1?

Exactly the same problem.

Just smaller.

So

```
print(5)

↓

print(4)

↓

print(3)

↓

print(2)

↓

print(1)

↓

print(0)
```

Every call solves a smaller problem.

---

# Rule 3 — Faith (Most Important)

This is where beginners struggle.

Imagine writing

```cpp
print(5);
```

Inside it

```cpp
print(4);
```

You DON'T think

> "How will print(4) work?"

You simply assume

> "If I ask print(4), it will correctly print 4 to 1."

This assumption is called

**Faith**.

Without faith,

recursion becomes impossible to write.

---

# What Actually Happens Inside Memory?

This is the most important part.

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
fun(3);
```

Let's see.

---

## Step 1

```
fun(3)
```

Memory Stack

```
-------------
fun(3)
-------------
```

Print

```
3
```

Calls

```
fun(2)
```

---

## Step 2

Stack

```
-------------
fun(2)
-------------
fun(3)
-------------
```

Print

```
2
```

Calls

```
fun(1)
```

---

Stack

```
-------------
fun(1)
-------------
fun(2)
-------------
fun(3)
-------------
```

Print

```
1
```

Calls

```
fun(0)
```

---

Stack

```
-------------
fun(0)
-------------
fun(1)
-------------
fun(2)
-------------
fun(3)
-------------
```

Now

```
n==0

return;
```

So

```
fun(0)
```

gets removed.

Stack

```
-------------
fun(1)
-------------
fun(2)
-------------
fun(3)
-------------
```

Then

```
fun(1)
```

finishes.

Removed.

```
-------------
fun(2)
-------------
fun(3)
-------------
```

Then

```
fun(2)
```

Removed.

Then

```
fun(3)
```

Removed.

Finally

Stack becomes empty.

---

This stack is called the **Call Stack**.

Every recursive call gets its own memory.

Remember this forever:

> **Every recursive call is an independent function with its own local variables and execution state.**

---

# Why Do People Say "Stack Overflow"?

Suppose

```cpp
fun(100000000);
```

Stack becomes

```
fun(100000000)

fun(99999999)

fun(99999998)

...

millions of calls
```

Eventually

Memory fills.

Program crashes.

This is

```
Stack Overflow
```

---

# How to Think Recursively

This is the biggest secret.

Never think

> How do I solve the whole problem?

Instead ask

> If someone solves a smaller version,
>
> what tiny work is left for me?

That's recursion.

---

Example

Find

```
Sum of first N numbers
```

For

```
5
```

Don't think

```
1+2+3+4+5
```

Think

```
Sum(5)

=

5

+

Sum(4)
```

Now forget about Sum(4).

Have faith.

Then

```
Sum(4)

=

4

+

Sum(3)
```

Eventually

```
Sum(1)=1
```

Done.

---

Code

```cpp
int sum(int n)
{
    if(n==1)
        return 1;

    return n + sum(n-1);
}
```

---

# The Most Common Pattern

Every recursion looks like

```cpp
return small_work + recursion(smaller_problem);
```

Examples

Sum

```cpp
return n + sum(n-1);
```

Factorial

```cpp
return n * fact(n-1);
```

Power

```cpp
return a * power(a,n-1);
```

Count digits

```cpp
return 1 + count(n/10);
```

---

# Types of Recursion

## 1. Linear Recursion

One recursive call.

```
f()

↓

f()

↓

f()

↓

f()
```

Example

Factorial

---

## 2. Binary Recursion

Two recursive calls.

```
f()

↓

f()   f()
```

Example

Fibonacci

---

## 3. Multiple Recursion

Three or more recursive calls.

Used in Trees and Graphs.

---

## 4. Tail Recursion

Recursive call is the last operation.

```cpp
fun(n)
{
    if(n==0)
        return;

    fun(n-1);
}
```

Nothing happens after the call returns.

---

## 5. Head Recursion

Work happens after recursion.

```cpp
fun(n)
{
    if(n==0)
        return;

    fun(n-1);

    cout<<n;
}
```

---

# Head vs Tail (Very Important)

Tail

```cpp
cout<<n;

fun(n-1);
```

Output

```
5 4 3 2 1
```

---

Head

```cpp
fun(n-1);

cout<<n;
```

Output

```
1 2 3 4 5
```

Why?

Because printing happens while coming back.

---

# The Five-Step Recipe to Solve Any Recursion Problem

Whenever you see a recursion question, follow these steps:

### Step 1: Identify the smallest input.

Ask: *When can I stop?*

This is the **base case**.

---

### Step 2: Assume the smaller problem is already solved.

This is **faith**.

---

### Step 3: Reduce the problem size.

Usually `n-1`, `n/2`, one less node, one less character, etc.

---

### Step 4: Do your small piece of work.

Combine the current value with the result from the smaller problem.

---

### Step 5: Return or continue.

Let the call stack automatically return control to previous calls.

---

# Common Mistakes

❌ No base case.

❌ Problem size never decreases.

```cpp
fun(n);
```

instead of

```cpp
fun(n-1);
```

❌ Changing the wrong variable.

❌ Forgetting to `return` a recursive result when the function has a return type.

❌ Trying to track every call mentally instead of trusting the recursive definition.

---

# When Should You Use Recursion?

Recursion shines when the problem is naturally defined in terms of smaller versions of itself, such as:

* Factorial
* Fibonacci (though not the most efficient implementation)
* Tree traversals
* Binary Search (can also be iterative)
* Backtracking (N-Queens, Sudoku)
* Divide and Conquer (Merge Sort, Quick Sort)
* Depth-First Search (DFS)

---

# The Mental Model to Remember for Life

Whenever you see a recursion problem, ask yourself these four questions:

1. **What is the smallest case?** (Base case)
2. **How can I make the problem smaller?** (Recursive call)
3. **What small work should I do now?** (Current step)
4. **Can I trust the recursive call to solve the smaller problem?** (Faith)

If you answer these four questions, you can derive most recursive solutions without memorizing code.

---

# One Final Analogy

Think of recursion like climbing down and back up a ladder.

```
Call stack growing:

Step 5
│
Step 4
│
Step 3
│
Step 2
│
Step 1   ← Base case (bottom)

Then return:

Step 1
↑
Step 2
↑
Step 3
↑
Step 4
↑
Step 5
```

* **Going down** = recursive calls are being made.
* **Bottom** = base case stops further calls.
* **Coming up** = each waiting function resumes execution after its recursive call returns.

If you always visualize recursion as **"go down until the smallest problem, then come back while finishing the remaining work,"** you'll have a durable mental model that applies to almost every recursion problem you'll encounter.
