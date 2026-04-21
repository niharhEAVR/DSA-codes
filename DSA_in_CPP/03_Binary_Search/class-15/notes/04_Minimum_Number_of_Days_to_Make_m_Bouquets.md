# 🌸 Imagine this situation

You have a **line of flowers in a garden**.

Each flower blooms on a certain day.

Example:

```cpp
bloomDay = [1, 4, 3, 2]
```

👉 Means:

* Flower 0 blooms on day 1
* Flower 1 blooms on day 4
* Flower 2 blooms on day 3
* Flower 3 blooms on day 2

---

# 🎯 Your goal

You want to make:

* `m` = number of bouquets
* Each bouquet needs `k` **adjacent flowers**

---

# ⚠️ Two VERY IMPORTANT RULES

### 1. Only bloomed flowers can be used

If day = 2 → only flowers with value ≤ 2 are usable

---

### 2. Flowers must be **adjacent**

You cannot pick random flowers

❌ Wrong:

```
[1, ❌, 3]  → not adjacent
```

✅ Correct:

```
[1, 2] → adjacent
```

---

# 🧠 What are we actually asked?

> Find the **minimum day** when you can make **m bouquets**

---

# 🔍 Let’s take a small example

```cpp
bloomDay = [1, 10, 3, 10, 2]
m = 3
k = 1
```

---

## Try Day = 1

Available flowers:

```
[1, ❌, ❌, ❌, ❌]
```

👉 Only 1 bouquet possible
❌ Not enough

---

## Try Day = 2

```
[1, ❌, ❌, ❌, 2]
```

👉 2 bouquets
❌ Not enough

---

## Try Day = 3

```
[1, ❌, 3, ❌, 2]
```

👉 3 flowers → 3 bouquets (k=1)

✅ YES!

---

👉 So answer = **3**

---

# 💡 Another example (important for adjacency)

```cpp
bloomDay = [1, 2, 4, 9, 3]
m = 2
k = 2
```

---

## Try Day = 3

```
[1, 2, ❌, ❌, 3]
```

Now check **adjacent groups of size 2**:

* `[1,2]` → ✅ 1 bouquet
* `[3]` → only 1 flower ❌

👉 Total = 1 bouquet ❌

---

## Try Day = 4

```
[1,2,4,❌,3]
```

Now:

* `[1,2]` → bouquet 1
* `[4,3]` → bouquet 2

✅ Works!

---

👉 Answer = **4**

---

# 🧠 Core idea (SUPER IMPORTANT)

Instead of thinking:

> “Which flowers to pick?”

Think:

> “On day D, how many bouquets can I make?”

---

# 🔄 So the problem becomes:

👉 Try a day `D`
👉 Count how many bouquets we can make
👉 Check if it’s ≥ m

---

# ⚠️ Important edge case

## ❌ Impossible case

```cpp
bloomDay = [1,2,3]
m = 2
k = 2
```

You need:

```
2 * 2 = 4 flowers
```

But only 3 exist ❌

👉 Answer = **-1**

---

# 🎯 Final simple understanding

* You wait for some day `D`
* See which flowers bloomed
* Try to form groups of `k adjacent flowers`
* Count bouquets
* Find the **smallest D** where bouquets ≥ m

---

# 🧠 One-line intuition

👉 “Wait just enough days so that I can form m groups of k adjacent bloomed flowers.”

---
---
---
---
---
---
---
---
---


# ⚙️ Why Binary Search?

Because:

* If day `D` works → any day **> D also works**
* If day `D` doesn’t work → any day **< D also doesn’t work**

👉 This is **monotonic**

So we can apply **binary search on answer**

---

# 🧩 Algorithm Flow

1. Find:

   ```cpp
   low = min(bloomDay)
   high = max(bloomDay)
   ```

2. Binary search:

   * mid = candidate day
   * check: can we make ≥ m bouquets?

3. If yes:

   * store answer
   * try smaller day

4. Else:

   * increase day

---

# 🔥 Edge Cases (VERY IMPORTANT)

---

## 1️⃣ Not enough flowers overall

```cpp
if (m * k > bloomDay.size()) return -1;
```

👉 Example:

```
bloomDay = [1,2,3]
m = 2, k = 2
Need = 4 flowers, have only 3 ❌
```

---

## 2️⃣ All flowers bloom very late

```
[1000000000, 1000000000]
```

👉 Your test case

* Only valid day = `1000000000`
* Make sure your binary search handles large numbers

---

## 3️⃣ k > 1 (adjacency matters)

```
[1,2,4,9,3,4]
k = 2
```

👉 You need **continuous flowers**

* `[1,2]` → valid
* `[4,9]` → ❌ (9 breaks chain)

---

## 4️⃣ Reset counter on gap

VERY IMPORTANT:

```cpp
if (bloomDay[i] <= mid)
    count++;
else
    count = 0;
```

👉 Missing this → wrong answer

---

## 5️⃣ Extra flowers > k

```
[1,1,1,1], k = 2
```

👉 You can make:

* `[1,1]` → bouquet 1
* `[1,1]` → bouquet 2

So:

```
count == k → reset to 0
```

---

## 6️⃣ Equality mistake (your bug)

❌ Wrong:

```cpp
bouquets == m
```

✅ Correct:

```cpp
bouquets >= m
```

---

## 7️⃣ Single element case

```
bloomDay = [5], m=1, k=1 → answer = 5
```

---

## 8️⃣ All same values

```
[7,7,7,7]
```

👉 Answer = 7 (if possible)

---

## 9️⃣ Large constraints (performance)

* n up to **1e5**
* bloomDay up to **1e9**

👉 Linear scan inside binary search → OK
👉 Brute force → TLE ❌

---

# 🧠 Final Intuition (lock this in)

Think of it like:

> “On day D, can I form enough bouquets?”

* If YES → try earlier day
* If NO → wait longer

---

# 🚀 One-line summary

👉 **Binary search on day + greedy check for bouquets**