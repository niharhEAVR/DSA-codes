# ✅ How do we get the equation

\[
x - y = \text{arrSum} - \text{originalSum}
\]

This is **very simple logic** once you understand what is happening inside the array.

---

# 🔍 Step-by-step Explanation

Let the array be of size **n** and contain numbers from **1 to n**.

But:

* One number is **repeating** → call it **x**
* One number is **missing** → call it **y**

### So the array looks like this:

Normal array should be:

```
1, 2, 3, ..., y, ..., n
```

But the real array is:

```
1, 2, 3, ..., x, ..., x, ..., n   ← y is missing
```

---

# ⭐ Idea

### 1️⃣ First, calculate **Original Sum** (without errors)

\[
S = 1 + 2 + 3 + \dots + n = \frac{n(n+1)}{2}
\]

### 2️⃣ Then calculate **Array Sum** (with repeating + missing)

\[
arrSum = (1 + 2 + \dots + x + \dots + x + \dots + n) - y
\]

This array sum contains:

* **+x** one extra time
* **-y** because y is missing

So mathematically:

\[
arrSum = S + x - y
\]

---

# ⭐ Now subtract S from both sides

\[
arrSum - S = (S + x - y) - S
\]

Cancel S:

\[
arrSum - S = x - y
\]

---

# 🎉 Final Equation (i)

\[
x - y = arrSum - S
\]

That’s the equation you used:

```
x - y = arrSum - originalSum;
```

---

# 🧠 Summary in One Line

**Array sum becomes bigger because of +x (extra) and smaller because y is missing.
So the total extra amount is (x – y).**



---
---
---


# why the **square equation exists**,
why we even need it, and **how both equations work together** to find the missing & repeating numbers.

---

# 🌟 First recap the two unknown values

We want:

* **Repeating number = x**
* **Missing number = y**

So we have **two unknowns**.

To solve two unknowns, we always need **two equations**.

This is why we create:

1. Equation using **sum** → gives **(x – y)**
2. Equation using **square sum** → gives **(x² – y²)**

Then combining them lets us solve x and y.

---

# 🎯 WHY do we need the square equation?

Imagine you only had:

\[
x - y = D_1
\]

This gives only **their difference**.

Example:
x – y = 4
This could mean many pairs:

| x   | y  |
| --- | -- |
| 6   | 2  |
| 10  | 6  |
| 100 | 96 |
| 1   | -3 |

We cannot find exact x and y from **one equation**.

That’s why we need **another equation**.

And that’s where square sums help.

---

# 🌟 Now visualize the squared-array logic

What happens when a number repeats and another number disappears?

### Normal square sum should be:

\[
S_2 = 1^2 + 2^2 + ... + n^2
\]

But real array square sum:
\[
arrSqSum = 1^2 + 2^2 + ... + x^2 + ... + x^2 + ... + n^2 - y^2
\]

Because:

* You add **x²** one extra time
* You remove **y²** (because y is missing)

So:

\[
arrSqSum = S_2 + x^2 - y^2
\]

Subtract S₂ from both sides:

\[
arrSqSum - S_2 = x^2 - y^2
\]

This becomes our **second equation**:

\[
x^2 - y^2 = D_2
\]

---

# 👀 But why use squares?

Because **x – y** is not enough to find two unknowns.
Square equations give **another relationship** between them.

Now observe a magic identity:

\[
x^2 - y^2 = (x - y)(x + y)
\]

We already know:
\[
x - y = D_1
\]

And:
\[
x^2 - y^2 = D_2
\]

So divide:

\[
x + y = \frac{D_2}{D_1}
\]

---

# 🎉 Now we have two equations:

1.

\[
x - y = D_1
\]

2.

\[
x + y = \frac{D_2}{D_1}
\]

Now solving these two gives **exact x and y**.

This is **why both equations are needed**.

---

# 🧠 VISUAL SUMMARY (SUPER SIMPLE)

### For the first equation:

Array sum becomes:

```
+ repeating number
- missing number
```

→ gives **x − y**

### For the second equation:

Square sum becomes:

```
+ repeating number squared
- missing number squared
```

→ gives **x² − y²**

### Combine them:

* One equation gives **difference**
* Other gives **sum**
  → From sum & difference → we can find actual numbers.

Just like solving:

```
x - y = 4
x + y = 10
```

Add → 2x = 14 → x = 7
Then y = 3

---

# 💡 Why was this approach invented?

Because this problem has **exactly two unknowns**, so mathematicians naturally figured:

* Use **first power (sum)** → Equation 1
* Use **second power (square)** → Equation 2
* Solve them together → Find exact values

It's a classic algebra trick used since 1800s.