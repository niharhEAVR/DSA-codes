# ✅ **What is the Majority Element II problem?**

(LC-229)

You are given an integer array:

\[
\text{nums} = [x_1, x_2, \ldots, x_n]
\]

You must return **all elements that appear more than**:

\[
\left\lfloor \frac{n}{3} \right\rfloor
\]

times in the array.

---

# 📌 **Step-by-step Understanding**

## **1️⃣ What does more than $(\left\lfloor \frac{n}{3} \right\rfloor)$ mean?**

If the size of array = ( n )

Then threshold =

\[
\text{threshold} = \left\lfloor \frac{n}{3} \right\rfloor
\]

An element is a "majority element" **only if**:

\[
\text{frequency(element)} > \text{threshold}
\]

---

# 📌 **2️⃣ Let's take small examples**

## **Example 1**

```
nums = [3, 2, 3]
```

n = 3

\[
\left\lfloor \frac{3}{3} \right\rfloor = 1
\]

Threshold = 1

Count:

* 3 → occurs 2 times → **2 > 1 (yes)**
* 2 → occurs 1 time → **1 > 1 (no)**

**Answer = [3]**

---

## **Example 2**

```
nums = [1, 1, 1, 3, 3, 2, 2, 2]
```

n = 8

\[
\left\lfloor \frac{8}{3} \right\rfloor = 2
\]

Threshold = 2

Count:

* 1 → occurs 3 times → **3 > 2 (YES)**
* 2 → occurs 3 times → **3 > 2 (YES)**
* 3 → occurs 2 times → **2 > 2 (NO)**

**Answer = [1, 2]**

---

## **Example 3**

```
nums = [1]
```

n = 1

\[
\left\lfloor \frac{1}{3} \right\rfloor = 0
\]

Threshold = 0

Count:

* 1 → occurs 1 time → **1 > 0 (YES)**

👉 Answer = **[1]**

---

# 📌 **3️⃣ MOST IMPORTANT INSIGHT**

Since the threshold is:

\[
 \frac{n}{3}
\]

It is **mathematically impossible** for more than 2 elements to satisfy this.

Why?

Because:

If 3 elements appeared more than $( \frac{n}{3} )$,
their counts would sum to more than ( n ) → **impossible**.

So maximum answers = **2 elements**.

---


### We’ll take different array sizes and **try to force 3 elements to appear more than ( n/3 )** and see why it becomes impossible.


# ✅ **Example 1: n = 6**

\[
\left\lfloor \frac{6}{3} \right\rfloor = 2
\]

So an element must appear **more than 2 times** → minimum frequency = **3**.

Let’s try to force **3 different elements** to be majority.

* element A appears 3 times
* element B appears 3 times
* element C appears 3 times

Total =
\[
3 + 3 + 3 = 9
\]

But array size = 6 → **IMPOSSIBLE**.

👉 **You cannot fit 9 items in an array of size 6.**

So **3 majority elements is impossible**.

---

# ✅ **Example 2: n = 7**

\[
\left\lfloor \frac{7}{3} \right\rfloor = 2
\]

To be majority: frequency > 2 → minimum **3** times

Try to fit 3 elements:

* A → 3 times
* B → 3 times
* C → 3 times

Total = 9 again.

But array size = 7 → **IMPOSSIBLE**.

---

# ✅ **Example 3: n = 10**

\[
\left\lfloor \frac{10}{3} \right\rfloor = 3
\]

Threshold = 3 → must appear **at least 4 times**

Try to have 3 majority elements:

* A → 4 times
* B → 4 times
* C → 4 times

Total =

\[
4 + 4 + 4 = 12
\]

But array size = 10 → **IMPOSSIBLE**.

---

# ⭐ FINAL LOGIC (PROOF)

If an element appears more than ( n/3 ),
minimum occurrences = ( \left(\frac{n}{3} + 1\right) )

So for 3 such elements:

\[
3 \times \left(\frac{n}{3} + 1\right)
\]

Simplify:

\[
= n + 3
\]

But the array has **only n elements**, not ( n + 3 ).

Therefore:

\[
\textbf{At most 2 elements can appear more than } \left\lfloor \frac{n}{3} \right\rfloor \text{ times}
\]


---

# 📌 **4️⃣ Problem is NOT asking for:**

❌ not asking for elements > n/2 (that is Majority Element I)
❌ not asking for most frequent elements
❌ not asking for top K frequent

It is asking:

✔️ find the elements (max 2) that appear **more than n/3 times**.

---

# ⭐ Final Summary (Super Simple)

> **Return all elements that appear more than one-third of the array length.
> At most 2 such elements can exist.**

---



