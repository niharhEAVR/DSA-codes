Good. Then let's **forget the code completely**.

You already understood divisors and prime by reasoning. We'll do the same here.

---

# Problem

Find the GCD of

```text
12 and 18
```

## Step 1: What does GCD mean?

GCD means:

> **The biggest number that divides BOTH numbers.**

So first ask yourself,

"What numbers divide 12?"

```text
1 2 3 4 6 12
```

Now ask,

"What numbers divide 18?"

```text
1 2 3 6 9 18
```

Now compare them.

```text
12 : 1 2 3 4 6 12
18 : 1 2 3 6 9 18
```

Common numbers are

```text
1 2 3 6
```

Largest is

```text
6
```

Therefore,

```text
GCD = 6
```

---

# Now imagine you're the computer.

The computer **doesn't know** which numbers are common.

It has to check them one by one.

So it thinks:

> "I'll try every number."

---

## Try 1

Does 1 divide both?

```text
12 % 1 == 0 ✅

18 % 1 == 0 ✅
```

Yes.

Current answer

```text
1
```

---

## Try 2

Does 2 divide both?

```text
12 % 2 == 0 ✅

18 % 2 == 0 ✅
```

Yes.

Current answer becomes

```text
2
```

---

## Try 3

```text
12 % 3 == 0 ✅

18 % 3 == 0 ✅
```

Answer becomes

```text
3
```

---

## Try 4

```text
12 % 4 == 0 ✅

18 % 4 == 2 ❌
```

No.

Answer stays

```text
3
```

---

## Try 5

```text
12 % 5 != 0 ❌
```

Skip.

---

## Try 6

```text
12 % 6 == 0 ✅

18 % 6 == 0 ✅
```

Answer becomes

```text
6
```

---

Continue...

7

8

9

10

11

12

Nothing bigger divides both.

Final answer

```text
6
```

---

# Now the code should make sense.

```cpp
int ans = 1;

for(int i = 1; i <= min(a,b); i++)
{
    if(a % i == 0 && b % i == 0)
        ans = i;
}

return ans;
```

Let's understand every line.

---

## Line 1

```cpp
int ans = 1;
```

Initially, we assume the GCD is 1.

Why?

Because every positive integer is divisible by 1.

---

## The loop

```cpp
for(int i=1;i<=min(a,b);i++)
```

Suppose

```text
a = 12

b = 18
```

Question:

Can the GCD ever be

```text
20
```

?

No.

Why?

Because **20 doesn't even divide 12**.

Can the GCD ever be

```text
15
```

?

No.

Because **15 is bigger than 12**.

A divisor can never be larger than the number itself.

So the biggest possible GCD is the **smaller number**.

That's why we loop only till

```cpp
min(a,b)
```

and not

```cpp
max(a,b)
```

---

## This line

```cpp
if(a%i==0 && b%i==0)
```

means

> "Does `i` divide BOTH numbers?"

If yes,

```cpp
ans = i;
```

---

Notice something.

We never do

```cpp
ans++;
```

We do

```cpp
ans = i;
```

Why?

Because we're moving from small numbers to big numbers.

Example:

```text
i = 1

ans = 1
```

Then

```text
i = 2

ans = 2
```

Then

```text
i = 3

ans = 3
```

Then

```text
i = 6

ans = 6
```

Since the loop moves in increasing order, the **last common divisor found is automatically the largest one**.

That's why we simply overwrite `ans`.

---

# Now your Time Complexity doubt

Suppose

```text
a = 12

b = 18
```

Loop runs

```text
1
2
3
4
5
6
7
8
9
10
11
12
```

How many iterations?

```text
12
```

which is

```text
min(12,18)
```

---

Suppose

```text
100

150
```

Loop runs

```text
1 → 100
```

100 iterations.

Again,

```text
min(100,150)
```

---

Suppose

```text
1000

250
```

Loop runs

```text
1 → 250
```

250 iterations.

Again,

```text
min(1000,250)
```

---

So the number of iterations is always:

```text
min(a,b)
```

Hence,

**Time Complexity = O(min(a, b))**

---

## The biggest problem with this approach

Imagine:

```text
a = 999999937

b = 999999929
```

Both are around **1 billion**.

The brute-force algorithm may have to check **almost one billion numbers**.

That's extremely slow.

**This is exactly why the Euclidean Algorithm was invented.** It reduces the complexity from **O(min(a,b))** to **O(log(min(a,b)))**, which is a massive improvement.

---

### Before we move to Euclid's Algorithm, I want to check one thing.

Can you answer this?

Suppose:

```text
a = 20
b = 30
```

Without writing code, tell me:

1. Why does the loop stop at **20** and not **30**?
2. During the loop, what values will `ans` take before the final answer?

Try answering these yourself. If you get them right, you'll have fully understood the brute-force approach.
