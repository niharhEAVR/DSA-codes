Yes, exactly. ✅

In DSA, **"Print All Divisors"** and **"Print All Factors"** usually mean the same thing.

A **divisor (or factor)** of a number is a number that divides it **without leaving a remainder**.

For example:

```text
n = 12
```

Check each number:

```text
1  → 12 % 1 = 0  ✅
2  → 12 % 2 = 0  ✅
3  → 12 % 3 = 0  ✅
4  → 12 % 4 = 0  ✅
5  → 12 % 5 = 2  ❌
6  → 12 % 6 = 0  ✅
7  → 12 % 7 = 5  ❌
8  → 12 % 8 = 4  ❌
9  → 12 % 9 = 3  ❌
10 → 12 % 10 = 2 ❌
11 → 12 % 11 = 1 ❌
12 → 12 % 12 = 0 ✅
```

So the divisors are:

```text
1 2 3 4 6 12
```

---

# Brute Force Approach

The most straightforward way is:

```cpp
for (int i = 1; i <= n; i++) {
    if (n % i == 0)
        cout << i << " ";
}
```

### Time Complexity

The loop runs from `1` to `n`.

So,

```text
O(n)
```

---

# Optimal Approach (Most Asked in Interviews)

Instead of checking all numbers until `n`, check only up to **√n**.

Why?

Take:

```text
n = 36
```

Divisors come in pairs:

```text
1  × 36
2  × 18
3  × 12
4  × 9
6  × 6
```

Notice something?

When you find

```text
2
```

you automatically know

```text
18
```

because

```text
2 × 18 = 36
```

So there is **no need to check beyond √36 = 6**.

---

For

```text
n = 36
```

Loop:

```text
i = 1 → print 1 and 36
i = 2 → print 2 and 18
i = 3 → print 3 and 12
i = 4 → print 4 and 9
i = 5 → nothing
i = 6 → print 6 only once
```

Notice that `6` is printed only once because:

```text
6 × 6 = 36
```

---

## Why stop at √n?

Suppose

```text
n = 100
```

If there were a divisor larger than 10 **without** a corresponding divisor smaller than 10, then:

```text
11 × 11 = 121
```

which is already greater than 100.

So every divisor greater than √n has a matching divisor smaller than √n.

That's why checking beyond √n is unnecessary.

---

# Optimal Code

```cpp
vector<int> divisors;

for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
        divisors.push_back(i);

        if (i != n / i)
            divisors.push_back(n / i);
    }
}

sort(divisors.begin(), divisors.end());

for (int x : divisors)
    cout << x << " ";
```

---

## Time Complexity

The loop runs only until √n.

```text
O(√n)
```

Sorting the divisors takes:

```text
O(k log k)
```

where `k` is the number of divisors (usually much smaller than `n`).

If the problem doesn't require sorted output, you can skip sorting and keep the complexity at **O(√n)**.

---

### A common interview question

> **Why do we write `i * i <= n` instead of `i <= sqrt(n)`?**

Because:

* `sqrt(n)` is a function call and involves floating-point arithmetic.
* `i * i <= n` uses only integer arithmetic, is typically faster, and avoids precision issues.

This "print all divisors" problem is one of the classic **Basic Maths** problems in DSA, and it teaches the very important concept of **factor pairs** and the **√n optimization**, which you'll use again in problems like:

* Prime checking
* Counting divisors
* Prime factorization
* Sieve-related algorithms







---
---
---
---
---
---
---
---






😂 That's completely okay. The **√n optimization** is one of those concepts that almost nobody understands the first time. Let's forget formulas and think visually.

---

# Imagine this question

Someone asks you:

> **Find all the numbers that can multiply together to make 36.**

Let's try.

```text
1 × 36 = 36 ✅

2 × 18 = 36 ✅

3 × 12 = 36 ✅

4 × 9 = 36 ✅

5 × ?  = 36 ❌

6 × 6 = 36 ✅

7 × ?  = 36 ❌

8 × ?  = 36 ❌

9 × 4 = 36 ← Wait...
```

Look carefully.

When you reached **9**, didn't you already find **4**?

Because earlier you already found

```text
4 × 9 = 36
```

So checking 9 is useless.

---

Then

```text
12 × 3
```

Already found.

---

Then

```text
18 × 2
```

Already found.

---

Then

```text
36 × 1
```

Already found.

---

## So what happened?

Every divisor has a **partner**.

```
1 ↔ 36

2 ↔ 18

3 ↔ 12

4 ↔ 9

6 ↔ 6
```

These are called **factor pairs**.

---

# Let's draw it

```
1 -------- 36

2 -------- 18

3 -------- 12

4 -------- 9

6 -------- 6
```

Notice something?

The left numbers are getting bigger.

The right numbers are getting smaller.

Eventually...

They meet.

Where do they meet?

At

```
6
```

---

# Why 6?

Ask yourself

```
6 × 6 = ?
```

```
36
```

Now think.

What number gives 36 when multiplied by itself?

Answer:

```
6
```

That number is called

```
√36 = 6
```

---

# Now let's take 100

Pairs are

```
1 × 100

2 × 50

4 × 25

5 × 20

10 × 10
```

Again...

The two numbers move toward each other.

```
1 → 2 → 4 → 5 → 10

100 → 50 → 25 → 20 → 10
```

They meet at

```
10
```

because

```
10 × 10 = 100
```

---

# Another example

Take

```
64
```

Pairs

```
1 × 64

2 × 32

4 × 16

8 × 8
```

Meet at

```
8
```

because

```
√64 = 8
```

---

# Now let's use a number that isn't a perfect square.

Take

```
20
```

Pairs

```
1 × 20

2 × 10

4 × 5
```

Now

```
5 × 4
```

is just the reverse of

```
4 × 5
```

The meeting point is around

```
√20 ≈ 4.47
```

Meaning:

After checking **4**, everything else is just repeating what you've already found.

---

# So why do we stop at √n?

Let's use 20.

Suppose I check

```
i = 5
```

If

```
5 divides 20
```

then I automatically know

```
20 / 5 = 4
```

But I already checked 4!

So checking 5 gave me nothing new.

---

Check

```
10
```

Partner is

```
2
```

Already checked.

---

Check

```
20
```

Partner is

```
1
```

Already checked.

---

So after √n, **you're only finding the same pairs in reverse order**.

---

# That's why the optimal code is

```cpp
for (int i = 1; i * i <= n; i++) {

    if (n % i == 0) {

        cout << i << " ";

        if (i != n / i)
            cout << n / i << " ";
    }
}
```

When `i = 4` for `n = 36`:

```
36 % 4 == 0
```

You print

```
4
```

Then immediately print its partner

```
36 / 4 = 9
```

So **one check gives you two divisors**.

---

# One question for you

Let's take:

```
n = 24
```

Can you tell me the factor pairs?

Try to complete this:

```
1 × __ = 24

2 × __ = 24

3 × __ = 24

4 × __ = 24

6 × __ = 24
```

Don't worry about √n yet. Just tell me the pairs. Once you can see the pairs naturally, the √n optimization will suddenly make perfect sense.




---
---
---
---
---
---
---
---




Excellent question. This is exactly the kind of thing you should understand instead of just memorizing.

You're asking:

> **Why do we write**
>
> ```cpp
> i * i <= n
> ```
>
> instead of
>
> ```cpp
> i <= sqrt(n)
> ```
>
> **And why is the first one preferred?**

Let's start from zero.

---

# Method 1 (The mathematical way)

You know we want to stop at √n.

So the most natural code is:

```cpp
for (int i = 1; i <= sqrt(n); i++)
```

This looks perfectly correct.

For example,

```text
n = 20

sqrt(20) ≈ 4.472
```

The loop becomes

```text
i <= 4.472
```

So `i` runs

```text
1
2
3
4
```

Works perfectly.

So...

**What's wrong with it?**

---

# Problem 1 — `sqrt()` is a function

Whenever you write

```cpp
sqrt(n)
```

the CPU has to calculate the square root.

Think of it like this:

```cpp
sqrt(20)
```

The computer cannot magically know the answer.

Internally it performs mathematical calculations to get

```text
4.47213595...
```

Every time you call `sqrt()`, extra work is done.

---

Imagine this:

```cpp
for(int i = 1; i <= sqrt(n); i++)
```

Suppose the compiler **doesn't optimize it**.

Then each iteration becomes

```text
Iteration 1

Calculate sqrt(20)

↓

Compare

↓

Run body
```

---

Next iteration

```text
Calculate sqrt(20)

↓

Compare

↓

Run body
```

Again...

Again...

Again...

Even though `n` never changed!

---

Now, modern compilers are smart and often compute `sqrt(n)` only once if `n` doesn't change. But as programmers, we don't like relying on compiler optimizations when a simpler solution exists.

---

# Problem 2 — `sqrt()` returns a `double`

This is the bigger reason.

Look at the type:

```cpp
sqrt(20)
```

returns

```cpp
double
```

not

```cpp
int
```

Example

```text
sqrt(20)

↓

4.47213595
```

Now you're comparing

```cpp
int <= double
```

Example

```cpp
4 <= 4.47213595
```

The compiler handles this conversion automatically, but you're mixing **integer arithmetic** with **floating-point arithmetic**.

---

# What is floating-point?

Integers are exact.

```text
5

10

17
```

No confusion.

---

Floating-point numbers have decimals.

```text
3.141592653...

2.71828...

4.47213595...
```

Computers cannot represent every decimal number exactly in binary.

For example,

```text
0.1
```

cannot be stored exactly.

It is actually stored as something like

```text
0.10000000000000000555...
```

You don't see that, but it's happening internally.

This is called **floating-point precision**.

---

# A famous example

```cpp
cout << (0.1 + 0.2);
```

Many beginners expect

```text
0.3
```

Sometimes you'll actually get something like

```text
0.30000000000000004
```

because of floating-point representation.

---

# Can `sqrt()` have precision issues?

Usually, `sqrt()` is very accurate, but it still returns a floating-point value.

Example:

```text
sqrt(81)

Expected

9
```

Internally it might be represented as

```text
8.999999999999998
```

or

```text
9.000000000000002
```

Depending on the system and compiler.

Most standard library implementations handle this well, but in competitive programming and interviews, it's a good habit to avoid floating-point arithmetic when you don't need it.

---

# Method 2 — Pure integer arithmetic

Instead of asking

> "Is `i` less than or equal to √n?"

ask a mathematically equivalent question:

> "Is `i²` less than or equal to `n`?"

Because

\[
i \le \sqrt{n}
\]

is exactly the same as

\[
i^2 \le n
\]

Example

```text
n = 20
```

Instead of

```cpp
i <= sqrt(20)
```

write

```cpp
i * i <= 20
```

Let's check:

```text
i = 1

1 × 1 = 1 <= 20 ✅

i = 2

2 × 2 = 4 <= 20 ✅

i = 3

9 <= 20 ✅

i = 4

16 <= 20 ✅

i = 5

25 <= 20 ❌
```

Same stopping point.

No `sqrt()` needed.

---

# Why is `i * i <= n` preferred?

Because it has several advantages:

1. **No floating-point arithmetic**

   * Only integers are used.
   * No precision concerns.

2. **No `sqrt()` call**

   * Simpler expression.
   * Doesn't depend on compiler optimizations.

3. **It's the standard pattern**

   * You'll see it in almost every DSA book, interview, and competitive programming solution.

---

# One small thing to remember

If `n` can be **very large**, then this can overflow:

```cpp
i * i
```

Example:

```cpp
int i = 50000;

i * i
```

equals

```text
2,500,000,000
```

which is larger than the maximum value an `int` can hold (`2,147,483,647`).

In those cases, people write:

```cpp
(long long)i * i <= n
```

or

```cpp
i <= n / i
```

to avoid overflow.

For beginner DSA problems like **Print All Divisors**, **Prime Check**, and **Count Divisors**, where `n` fits comfortably in an `int`, writing

```cpp
i * i <= n
```

is the standard and recommended approach.

---

## Rule of thumb for your DSA journey

Whenever you see a condition like:

```cpp
i <= sqrt(n)
```

your brain should immediately think:

> **"I can probably replace this with `i * i <= n` and avoid floating-point arithmetic."**

You'll see this exact pattern repeatedly in:

* Prime checking
* Counting divisors
* Printing divisors
* Prime factorization
* Many number theory problems

Once you recognize it, it becomes second nature.

