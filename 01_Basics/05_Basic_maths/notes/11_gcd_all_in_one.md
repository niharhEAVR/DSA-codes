Awesome! This is the next classic **Basic Maths** problem in DSA.

The learning order is actually:

1. ✅ Count Digits
2. ✅ Reverse Number
3. ✅ Palindrome Number
4. ✅ Armstrong Number
5. ✅ Print Divisors
6. ✅ Check Prime
7. **✅ GCD / HCF** ← We are here.

---

# What is GCD / HCF?

First, don't get confused by the names.

```text
GCD = Greatest Common Divisor

HCF = Highest Common Factor
```

They mean **exactly the same thing**.

---

# Let's understand from zero

Suppose we have two numbers:

```text
12 and 18
```

First, write all the factors.

Factors of 12

```text
1 2 3 4 6 12
```

Factors of 18

```text
1 2 3 6 9 18
```

Now ask yourself

> Which factors are common?

```text
1 2 3 6
```

Among them,

the **greatest** one is

```text
6
```

Therefore

```text
GCD(12,18)=6
```

---

Another example

```text
20 and 30
```

Factors of 20

```text
1 2 4 5 10 20
```

Factors of 30

```text
1 2 3 5 6 10 15 30
```

Common factors

```text
1 2 5 10
```

Largest

```text
10
```

Therefore

```text
GCD = 10
```

---

# Brute Force Idea

Ask yourself:

> What is the largest number that divides both?

The biggest possible answer cannot be larger than the smaller number.

So

```cpp
int ans = 1;

for(int i = 1; i <= min(a,b); i++)
{
    if(a%i==0 && b%i==0)
        ans = i;
}

return ans;
```

---

## Dry Run

Suppose

```text
a = 12

b = 18
```

Loop

| i    | Divides 12? | Divides 18? | ans |
| ---- | ----------- | ----------- | --- |
| 1    | ✅           | ✅           | 1   |
| 2    | ✅           | ✅           | 2   |
| 3    | ✅           | ✅           | 3   |
| 4    | ✅           | ❌           | 3   |
| 5    | ❌           | ❌           | 3   |
| 6    | ✅           | ✅           | 6   |
| 7-11 | ❌           | ❌           | 6   |
| 12   | ✅           | ❌           | 6   |

Answer

```text
6
```

---

# Time Complexity

Loop

```text
1 → min(a,b)
```

Therefore

```text
O(min(a,b))
```

---

# Can we optimize?

Yes.

A lot.

And this is one of the **most famous algorithms in computer science**.

It's called

> **Euclidean Algorithm**

---

# Before learning the algorithm...

I want you to notice a pattern.

Take

```text
12 and 18
```

GCD

```text
6
```

Now subtract the smaller number.

```text
18 - 12 = 6
```

Now the pair becomes

```text
12

6
```

What's the GCD?

Still

```text
6
```

Interesting...

---

Another

```text
20

30
```

Subtract

```text
30-20=10
```

New pair

```text
20

10
```

GCD?

Still

```text
10
```

Again...

Interesting.

---

One more

```text
15

25
```

Subtract

```text
25-15=10
```

New pair

```text
15

10
```

GCD?

```text
5
```

Same as before.

---

## The important observation

The GCD **doesn't change** if you replace the larger number by:

```text
larger - smaller
```

This is the key idea behind the Euclidean Algorithm.

---

# But subtraction is still slow

Imagine

```text
2

1000000
```

You'll subtract

```text
2
```

almost **500,000 times**.

Very slow.

---

So instead of repeated subtraction, we use **remainder (`%`)**.

Think of `%` as doing **many subtractions at once**.

Example:

```text
18 % 12 = 6
```

Instead of

```text
18-12=6
```

it's the same in one operation.

---

Another

```text
100 % 30 = 10
```

Instead of

```text
100-30=70

70-30=40

40-30=10
```

The `%` operator skips all those subtractions.

---

# Euclidean Algorithm

The rule is:

```text
GCD(a,b)=GCD(b,a%b)
```

This is one of the most important formulas in DSA.

Let's dry run it.

---

Suppose

```text
a = 48

b = 18
```

Step 1

```text
48 % 18 = 12
```

New pair

```text
18

12
```

---

Step 2

```text
18 % 12 = 6
```

New pair

```text
12

6
```

---

Step 3

```text
12 % 6 = 0
```

New pair

```text
6

0
```

When one number becomes

```text
0
```

the other number is the answer.

Therefore

```text
GCD=6
```

---

# Code

```cpp
int gcd(int a, int b)
{
    while(b != 0)
    {
        int rem = a % b;
        a = b;
        b = rem;
    }

    return a;
}
```

---

# Dry Run (Code)

Start

```text
a = 48

b = 18
```

### First iteration

```text
rem = 48 % 18

=12
```

Update

```text
a=18

b=12
```

---

Second

```text
rem = 18 % 12

=6
```

Update

```text
a=12

b=6
```

---

Third

```text
rem = 12 % 6

=0
```

Update

```text
a=6

b=0
```

Loop stops.

Return

```text
6
```

---

# Time Complexity

This is the beautiful part.

The Euclidean Algorithm runs in:

```text
O(log(min(a,b)))
```

which is **much faster** than

```text
O(min(a,b))
```

For very large numbers, the difference is enormous.

---

# Edge Cases

### Same numbers

```text
GCD(10,10)=10
```

Works correctly.

---

### One number is 0

```text
GCD(0,15)=15
```

The algorithm handles this naturally.

---

### Both numbers are 0

```text
GCD(0,0)
```

Mathematically, this is **undefined**. In programming, you should decide how your function should handle it (many libraries return `0`, but it's not a mathematically defined GCD).

---

## The interview thought process

When you see a GCD problem, think:

1. **Brute force:** Check every number up to `min(a,b)` → `O(min(a,b))`.
2. **Observation:** Replacing the larger number with its remainder when divided by the smaller doesn't change the GCD.
3. **Euclidean Algorithm:** Keep replacing `(a, b)` with `(b, a % b)` until `b` becomes `0`.
4. **Answer:** The remaining value of `a`.

This algorithm is so important that you'll use it again in:

* Finding **LCM**
* Fraction simplification
* Modular arithmetic
* Number theory
* Competitive programming
* Cryptography (like RSA)







---
---
---
---
---
---
---
---
---









Excellent. This is actually the **hardest part** of the Euclidean Algorithm. Most people just memorize:

> **TC = O(log(min(a, b)))**

without knowing **why**.

Let's build the intuition slowly.

---

# First, let's forget logarithms.

Let's compare the two approaches.

## Brute Force

Suppose

```text
a = 48
b = 18
```

The brute force loop is

```cpp
for(int i = 1; i <= 18; i++)
```

How many iterations?

```text
18
```

Easy.

---

## Euclidean Algorithm

```cpp
while(b != 0)
{
    int rem = a % b;
    a = b;
    b = rem;
}
```

Let's dry run it.

### Iteration 1

```text
a = 48
b = 18

48 % 18 = 12
```

New values

```text
18 12
```

---

### Iteration 2

```text
18 % 12 = 6
```

New values

```text
12 6
```

---

### Iteration 3

```text
12 % 6 = 0
```

New values

```text
6 0
```

Stop.

How many iterations?

```text
3
```

Instead of 18 iterations...

only **3**.

---

# Another example

Take

```text
100
30
```

### First

```text
100 % 30 = 10

↓

30 10
```

---

### Second

```text
30 % 10 = 0

↓

10 0
```

Done.

Only

```text
2 iterations
```

---

# Now comes the important observation

Look at the second number (`b`).

Initially

```text
18
```

Then

```text
12
```

Then

```text
6
```

Then

```text
0
```

Notice something?

It becomes **much smaller** every iteration.

---

Let's take another example.

```text
a = 101
b = 100
```

First iteration

```text
101 % 100 = 1
```

New pair

```text
100 1
```

Second iteration

```text
100 % 1 = 0
```

Done.

Only

```text
2 iterations
```

---

# Compare this with brute force

Brute force would check

```text
1

2

3

...

100
```

That's

```text
100 iterations
```

Euclid needed

```text
2 iterations
```

Huge difference.

---

# Why does it become logarithmic?

Here's the intuition.

Imagine every iteration **roughly cuts the problem size down**.

For example

```text
1000
```

becomes something much smaller.

Then that becomes even smaller.

Then smaller again.

It's **not subtracting 1 each time**.

It's making **big jumps**.

---

Think of it like this:

Suppose every step halves the number.

```text
1024

↓

512

↓

256

↓

128

↓

64

↓

32

↓

16

↓

8

↓

4

↓

2

↓

1
```

How many steps?

Not 1024.

Only

```text
10
```

because

```text
2¹⁰ = 1024
```

Whenever a problem size keeps shrinking by a constant factor (like half), the number of steps grows as a logarithm.

---

# Is Euclid exactly halving?

Not always.

Sometimes it shrinks even faster.

Sometimes a little slower.

But mathematicians have proved something amazing:

> In the worst case, the Euclidean Algorithm performs a number of iterations proportional to **log(min(a, b))**.

The slowest cases actually occur for **consecutive Fibonacci numbers**.

Example:

```text
34, 21

21, 13

13, 8

8, 5

5, 3

3, 2

2, 1

1, 0
```

Even in this worst case, the number of steps grows only logarithmically with the size of the input.

---

# The intuition you should remember

Forget the proof for now.

Just remember:

### Brute Force

Moves like this:

```text
18

17

16

15

14

13

...
```

Almost one step at a time.

---

### Euclidean Algorithm

Moves like this:

```text
48 18

↓

18 12

↓

12 6

↓

6 0
```

The numbers **collapse quickly**, so the loop finishes in very few iterations.

---

## Don't memorize this yet

For interviews, it's enough to know:

* **Brute Force:** `O(min(a, b))` because it checks every number up to the smaller one.
* **Euclidean Algorithm:** `O(log(min(a, b)))` because each iteration drastically reduces the size of the problem, and the worst-case number of iterations grows logarithmically.

---

### I have one question for you.

When we studied **Binary Search**, you'll also see **O(log n)**.

Do you know **why Binary Search is `O(log n)`**, or will that also be your first time?
