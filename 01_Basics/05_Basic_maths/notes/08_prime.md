Perfect. This is the **next logical problem** after "Print All Divisors."

Why?

Because once you know how to find divisors efficiently, checking for a prime number becomes very easy.

---

# Step 1: What is a Prime Number?

A **prime number** is a number that has **exactly two positive divisors**:

1. 1
2. The number itself

Examples:

```text
2  → 1, 2          ✅ Prime

3  → 1, 3          ✅ Prime

5  → 1, 5          ✅ Prime

7  → 1, 7          ✅ Prime

11 → 1, 11         ✅ Prime
```

---

Now look at:

```text
6
```

Its divisors are

```text
1 2 3 6
```

Four divisors.

So

```text
6
```

is **not prime**.

---

Another

```text
9
```

Divisors

```text
1 3 9
```

Three divisors.

Not prime.

---

# The idea

You have already learned:

> **Prime number = only 2 divisors.**

So the first idea is

> Count the divisors.

If divisor count == 2

Return

```text
true
```

Else

```text
false
```

---

# Brute Force Solution

```cpp
int count = 0;

for(int i = 1; i <= n; i++)
{
    if(n % i == 0)
        count++;
}

return count == 2;
```

---

## Dry Run

Suppose

```text
n = 7
```

| i | 7 % i | Count |
| - | ----- | ----: |
| 1 | 0     |     1 |
| 2 | 1     |     1 |
| 3 | 1     |     1 |
| 4 | 3     |     1 |
| 5 | 2     |     1 |
| 6 | 1     |     1 |
| 7 | 0     |     2 |

Count = 2

Prime ✅

---

Now

```text
n = 12
```

| i  | 12 % i | Count |
| -- | ------ | ----: |
| 1  | 0      |     1 |
| 2  | 0      |     2 |
| 3  | 0      |     3 |
| 4  | 0      |     4 |
| 5  | 2      |     4 |
| 6  | 0      |     5 |
| 7  | 5      |     5 |
| 8  | 4      |     5 |
| 9  | 3      |     5 |
| 10 | 2      |     5 |
| 11 | 1      |     5 |
| 12 | 0      |     6 |

Count = 6

Not Prime ❌

---

# Time Complexity

Loop runs

```text
1 → n
```

Therefore

```
O(n)
```

---

# Can we optimize?

Now think back to the previous problem.

Did we really need to check till

```text
n
```

No.

We stopped at

```text
√n
```

because of **factor pairs**.

Exactly the same idea applies here.

---

## Suppose

```text
n = 35
```

Factor pairs

```text
1 × 35

5 × 7
```

genui{"integer_number_operations_learning_block":{"type_id":"FACTOR_PAIRS_ARRAYS"}}

After √35 (~5.9), every factor is just the reverse of one we've already found.

So instead of checking

```text
1
2
3
...
35
```

we check only

```text
1
2
3
4
5
```

---

# Even better observation ⭐

Do we actually need to count all divisors?

No.

To prove a number is **not prime**, we only need **one divisor** other than 1 and itself.

Example

```text
n = 35
```

Start checking.

```text
2
```

No.

```text
3
```

No.

```text
4
```

No.

```text
5
```

Yes!

Since

```text
35 % 5 == 0
```

we immediately know

```text
35 = 5 × 7
```

That means 35 has more than two divisors.

We don't need to continue.

We already know it's **not prime**.

This is the biggest optimization.

---

# Optimal Algorithm

```cpp
if(n <= 1)
    return false;

for(int i = 2; i * i <= n; i++)
{
    if(n % i == 0)
        return false;
}

return true;
```

---

# Dry Run

Take

```text
n = 29
```

Start

```text
i = 2

29 % 2 = 1
```

Continue.

```text
i = 3

29 % 3 = 2
```

Continue.

```text
i = 4

29 % 4 = 1
```

Continue.

```text
i = 5

29 % 5 = 4
```

Next

```text
i = 6
```

Condition

```text
6 × 6 = 36 > 29
```

Stop.

Never found a divisor.

Return

```text
true
```

Prime.

---

Now

```text
n = 21
```

```text
i = 2

21 % 2 ≠ 0
```

Continue.

```text
i = 3

21 % 3 == 0
```

Immediately

```cpp
return false;
```

We don't check

```text
4

5

6

...

21
```

because one divisor is enough to prove it's not prime.

---

# Edge Cases (Very Important)

### Case 1

```text
n = 1
```

Many beginners think

```text
1 is prime
```

Wrong.

A prime number must have **exactly two** divisors.

```text
1
```

has only one divisor.

Not Prime.

---

### Case 2

```text
n = 0
```

Not Prime.

---

### Case 3

```text
n = -5
```

Negative numbers are not prime.

That's why we write

```cpp
if(n <= 1)
    return false;
```

---

# Time Complexity

Loop runs only till

```text
√n
```

Therefore

```
O(√n)
```

Space Complexity

```
O(1)
```

---

## Interview Thought Process

Whenever you see **"Check Prime"**, train your brain to think in this order:

1. **Prime means exactly two divisors.**
2. **A single extra divisor proves it's not prime.**
3. **Because of factor pairs, I only need to search up to √n.**
4. **As soon as I find one divisor, return `false`.**
5. **If I finish the loop without finding one, return `true`.**

---

### A small challenge for you

Without running the code, dry-run it for:

```text
n = 49
```

Tell me:

* What values of `i` are checked?
* At which value does the function return?
* Does it ever check `i = 8`? Why or why not?

Try it yourself first. This is the best way to make the √n concept stick.
