# 1. With a perfect Square Number:


Perfect! Since you've understood **factor pairs**, the code will now make much more sense.

Let's dry-run it **line by line**.

---

# Code

```cpp
for (int i = 1; i * i <= n; i++) {

    if (n % i == 0) {

        cout << i << " ";

        if (i != n / i)
            cout << n / i << " ";
    }
}
```

We'll use

```text
n = 36
```

---

# Initial State

```
n = 36
i = 1
```

Loop condition

```cpp
i * i <= n

1 * 1 <= 36
```

✅ True

---

## Iteration 1

```
i = 1
```

Check

```cpp
36 % 1 == 0
```

Yes.

Print

```
1
```

Now

```cpp
n / i
```

means

```
36 / 1 = 36
```

Print

```
36
```

Output

```
1 36
```

---

## Iteration 2

```
i = 2
```

Condition

```
2 × 2 = 4 <= 36
```

True.

Check

```
36 % 2 == 0
```

Yes.

Print

```
2
```

Partner

```
36 / 2 = 18
```

Print

```
18
```

Output

```
1 36 2 18
```

---

## Iteration 3

```
i = 3
```

```
3 × 3 = 9 <= 36
```

True.

```
36 % 3 == 0
```

Print

```
3
```

Partner

```
36 / 3 = 12
```

Print

```
12
```

Output

```
1 36 2 18 3 12
```

---

## Iteration 4

```
i = 4
```

```
4 × 4 = 16 <= 36
```

True.

```
36 % 4 == 0
```

Print

```
4
```

Partner

```
36 / 4 = 9
```

Print

```
9
```

Output

```
1 36 2 18 3 12 4 9
```

---

## Iteration 5

```
i = 5
```

```
5 × 5 = 25 <= 36
```

True.

```
36 % 5 == 1
```

Not divisible.

Nothing printed.

---

## Iteration 6

```
i = 6
```

```
6 × 6 = 36
```

True.

```
36 % 6 == 0
```

Print

```
6
```

Now partner

```
36 / 6 = 6
```

Wait...

It is the same number.

If we printed again

```
6 6
```

that would be wrong.

That's why we write

```cpp
if(i != n/i)
```

Here

```
6 != 6
```

False.

So we **don't print the partner again**.

Output

```
1 36 2 18 3 12 4 9 6
```

---

## Next iteration

```
i = 7
```

Condition

```
7 × 7 = 49

49 <= 36
```

False.

Loop stops.

---

# Why `if(i != n/i)`?

Imagine

```
n = 49
```

When

```
i = 7
```

Partner is

```
49 / 7 = 7
```

Without the condition

```cpp
cout << i;
cout << n/i;
```

Output would be

```
7 7
```

Wrong.

The condition avoids duplicate printing for **perfect squares**.

---

# Why `i * i <= n`?

You could write

```cpp
i <= sqrt(n)
```

But

```cpp
sqrt()
```

returns a floating-point (`double`) value.

Using

```cpp
i * i <= n
```

* avoids floating-point calculations,
* is generally faster,
* and avoids precision issues.

---

# Final Output

Notice the order:

```
1 36 2 18 3 12 4 9 6
```

This is **not sorted**.

If the problem asks for sorted divisors, store them in a vector and sort them afterward, or use two vectors (small divisors and large divisors).

---

# Where is this concept used?

This is one of the most important ideas in number theory. You'll use it in many DSA problems.

### 1. Print all divisors ✅

Exactly the problem you just learned.

---

### 2. Count the number of divisors

Instead of printing them, count them.

Example:

```
36

Divisors:

1 2 3 4 6 9 12 18 36

Count = 9
```

---

### 3. Check if a number is prime ⭐⭐⭐

A prime number has exactly **2 divisors**.

Naive approach:

```cpp
for(int i = 1; i <= n; i++)
```

Better approach:

```cpp
for(int i = 2; i * i <= n; i++)
```

If any `i` divides `n`, it's not prime.

Time complexity improves from **O(n)** to **O(√n)**.

---

### 4. Prime factorization

Example:

```
84
```

Factors:

```
2 × 2 × 3 × 7
```

The algorithm repeatedly checks divisibility up to `√n`.

---

### 5. Perfect Number

Example:

```
28
```

Proper divisors:

```
1 + 2 + 4 + 7 + 14 = 28
```

Again, you need all divisors efficiently.

---

### 6. GCD / LCM (Basic approach)

A simple method finds common divisors by checking divisors.

(Although the optimal solution is the Euclidean Algorithm.)

---

### 7. Number Theory Problems

Many competitive programming problems ask questions like:

* Sum of divisors
* Number of divisors
* Common divisors
* Highly composite numbers

Almost all of them start with the **factor-pair** idea.

---

# The key concept you should remember

Don't memorize the code. Remember the reasoning:

> Every divisor `i` has a partner `n / i`.

For example, with `36`:

```
1 ↔ 36
2 ↔ 18
3 ↔ 12
4 ↔ 9
6 ↔ 6
```

By checking only the **smaller member of each pair** (up to `√n`), you automatically discover the **larger member**. That's why one iteration can give you **two divisors**, reducing the complexity from **O(n)** to **O(√n)**.

This "factor pair" concept is the real lesson. The code is just a way of implementing it.





---
---
---
---
---
---
---



# 2. Without a perfect Square Number:


Good idea. A **non-perfect square** is actually easier to understand because we don't have to worry about the `i != n/i` condition.

Let's take:

```text
n = 20
```

---

# Step 1: Initial Code

```cpp
for (int i = 1; i * i <= n; i++) {

    if (n % i == 0) {

        cout << i << " ";

        if (i != n / i)
            cout << n / i << " ";
    }
}
```

---

# Initial State

```text
n = 20
i = 1
```

Loop condition

```text
1 × 1 <= 20
```

✅ True

---

# Iteration 1

```text
i = 1
```

Check

```cpp
20 % 1 == 0
```

✅ Yes

Print

```text
1
```

Now find its partner

```text
20 / 1 = 20
```

Print

```text
20
```

Output so far

```text
1 20
```

---

# Iteration 2

```text
i = 2
```

Loop condition

```text
2 × 2 = 4 <= 20
```

✅ True

Check

```cpp
20 % 2 == 0
```

✅ Yes

Print

```text
2
```

Partner

```text
20 / 2 = 10
```

Print

```text
10
```

Output

```text
1 20 2 10
```

---

# Iteration 3

```text
i = 3
```

Condition

```text
3 × 3 = 9 <= 20
```

✅ True

Check

```cpp
20 % 3 == 0
```

❌ No

Nothing happens.

Output remains

```text
1 20 2 10
```

---

# Iteration 4

```text
i = 4
```

Condition

```text
4 × 4 = 16 <= 20
```

✅ True

Check

```cpp
20 % 4 == 0
```

✅ Yes

Print

```text
4
```

Partner

```text
20 / 4 = 5
```

Print

```text
5
```

Output

```text
1 20 2 10 4 5
```

---

# Next Iteration

```text
i = 5
```

Loop condition

```text
5 × 5 = 25 <= 20
```

❌ False

Loop stops.

---

# Final Output

```text
1 20 2 10 4 5
```

These are exactly all the divisors of 20.

Notice something:

```
1 ↔ 20
2 ↔ 10
4 ↔ 5
```

We **never checked**:

```
5
6
7
8
9
10
...
20
```

Yet we still found **5, 10, and 20**.

Why?

Because every time we found a divisor `i`, we immediately found its partner:

```cpp
n / i
```

---

# Let's see it visually

Imagine the factor pairs like this:

```
1 -------- 20

2 -------- 10

4 -------- 5
```

Your loop only visits the **left side**.

```
✓ 1

✓ 2

✓ 3 (not a divisor)

✓ 4

STOP
```

Whenever it finds a divisor, it **jumps** to the right side using:

```cpp
n / i
```

For example,

When

```text
i = 4
```

Instead of later checking

```text
5
```

the program instantly computes

```text
20 / 4 = 5
```

So **one calculation gives you two divisors**.

---

## Now let me ask you a question.

Suppose

```text
n = 30
```

Without writing any code, tell me what happens in each iteration.

Fill this table:

| i | Is `30 % i == 0`? | What gets printed? |
| - | ----------------- | ------------------ |
| 1 | ?                 | ?                  |
| 2 | ?                 | ?                  |
| 3 | ?                 | ?                  |
| 4 | ?                 | ?                  |
| 5 | ?                 | ?                  |

Remember, the loop stops because after `i = 5`:

```
6 × 6 = 36 > 30
```

Try filling the table yourself. If you can do that correctly, you've truly understood the √n optimization.
