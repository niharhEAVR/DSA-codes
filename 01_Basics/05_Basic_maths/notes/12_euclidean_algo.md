That's actually a very good question.

Many people think **Euclidean Algorithm is just the code we use for GCD**. It's not.

**The Euclidean Algorithm is an independent mathematical algorithm.**
**Finding GCD is simply its most famous application.**

Let's understand it from the beginning.

---

# Before Euclid (around 300 BC)

Imagine someone asks:

> Find GCD(48,18)

Without Euclid, what would you do?

You'd probably list factors.

48 → 1,2,3,4,6,8,12,16,24,48

18 → 1,2,3,6,9,18

Largest common = **6**

Works.

But what if numbers are

```
987654321
123456789
```

Listing factors?

Impossible.

People needed a smarter method.

---

# Then came Euclid

Around **300 BC**, the Greek mathematician Euclid discovered something amazing.

He didn't invent a faster way to list factors.

He discovered a **property of numbers**.

That property became known as the **Euclidean Algorithm**.

---

# The Core Observation

Suppose we have

```
a = 48
b = 18
```

Instead of thinking about factors...

Euclid thought:

> What happens if I subtract the smaller number from the larger?

```
48 - 18 = 30
```

Now compare

```
30 and 18
```

Notice something.

The GCD didn't change.

```
GCD(48,18)
=
GCD(30,18)
```

Again

```
30 - 18 = 12

GCD(30,18)
=
GCD(18,12)
```

Again

```
18-12=6

GCD(18,12)
=
GCD(12,6)
```

Again

```
12-6=6

GCD(12,6)
=
GCD(6,6)
```

Answer

```
6
```

This is Euclid's original idea.

---

# Why does subtraction work?

Let's take

```
48
18
```

Common factors are

```
1
2
3
6
```

Subtract

```
48-18 =30
```

Factors of 30

```
1
2
3
5
6
10
15
30
```

Common factors with 18

```
1
2
3
6
```

Exactly the same.

Nothing changed.

That means

```
GCD(a,b)
=
GCD(a-b,b)
```

This is the heart of Euclid's discovery.

---

# But subtraction is slow

Imagine

```
1000000
2
```

Subtraction

```
1000000-2
999998-2
999996-2
...
```

Five lakh subtractions.

Very slow.

---

# Euclid became even smarter

Instead of subtracting repeatedly,

suppose

```
100
30
```

Subtract repeatedly

```
100-30=70
70-30=40
40-30=10
```

Three subtractions.

Instead...

```
100 % 30 =10
```

One operation.

Exactly the same result.

So he replaced repeated subtraction with remainder.

That gives

```
GCD(a,b)
=
GCD(b,a%b)
```

This is the modern Euclidean Algorithm.

---

# Why does remainder work?

Suppose

```
100
30
```

Division says

```
100 = 30×3 +10
```

The remainder is

```
10
```

Now think.

If a number divides both

```
100
30
```

then it must also divide

```
100−30×3
```

because

```
100−90=10
```

So every common divisor of

```
100 and 30
```

is also a divisor of

```
30 and 10
```

Nothing changes.

Therefore

```
GCD(100,30)
=
GCD(30,10)
```

That's the mathematical proof behind the algorithm.

---

# The algorithm itself

```
While b != 0

    remainder = a % b

    a = b

    b = remainder

Answer = a
```

---

Example

```
GCD(48,18)

48 %18 =12

18 %12 =6

12 %6 =0

Answer =6
```

---

# Why does it stop?

Each time

```
a % b
```

is **strictly smaller than** `b`.

Example

```
48 %18 =12

12 <18
```

Next

```
18 %12 =6

6 <12
```

Next

```
12 %6 =0
```

The numbers keep getting smaller.

Eventually,

```
remainder =0
```

At that point,

the other number is the GCD.

---

# So what exactly is the Euclidean Algorithm?

It is **not** "the GCD algorithm."

It is an algorithm based on the mathematical identity:

\[
\boxed{\gcd(a,b)=\gcd(b,;a\bmod b)}
\]

Using this identity repeatedly reduces the problem to smaller and smaller numbers until one becomes 0. The remaining number is the greatest common divisor.

---

# Why is it famous?

Because this single algorithm is used in many areas of computer science and mathematics:

* Finding **GCD (HCF)**.
* Simplifying fractions.
* Computing **LCM** using `LCM = (a × b) / GCD`.
* Extended Euclidean Algorithm, which finds integers `x` and `y` such that `ax + by = gcd(a, b)` (very important in cryptography).
* Algorithms used in cryptography, including RSA, rely on the Extended Euclidean Algorithm to compute modular inverses.

---

## One sentence to remember

> **The Euclidean Algorithm is a general algorithm for reducing a pair of numbers while preserving their GCD. Finding the GCD is the main problem it solves, not the algorithm itself.**

Once you understand this idea, the time complexity of **O(log(min(a, b)))** becomes much more intuitive. That's the next piece to learn.
