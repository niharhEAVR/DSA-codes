# 🧠 Problem Understanding (Super Simple)

You are given a **sorted array** where:

* Every element appears **exactly twice**
* Except **one element** which appears **only once**

👉 Your task: **Find that single element**

---

### 📌 Example

```
[1,1,2,2,3,4,4,5,5]
```

👉 Here:

* 1 → twice
* 2 → twice
* 4 → twice
* 5 → twice
* **3 → only once ✅ (answer)**

---

# 🔍 Key Observation (Most Important Part)

Since the array is **sorted**, duplicates appear **next to each other**

So normally pairs look like:

```
(index)
0 1 | 2 3 | 4 5 | 6 7 ...
a a | b b | c c | d d ...
```

👉 Notice:

* First occurrence at **even index**
* Second occurrence at **odd index**

---

# ⚡ What changes because of the single element?

Once the single element appears, **this pattern breaks**

---

### Before single element:

```
Index:  0 1 2 3 4 5
Array:  a a b b c c
Pattern: even-odd pairs ✔
```

---

### After single element:

```
Index:  0 1 2 3 4 5 6
Array:  a a b x c c d d
               ↑ single element

Now pairs shift ❌
```

👉 After the single element:

* Pair starts at **odd index**
* Pattern becomes **wrong**

---

# 🎯 Core Concept (Binary Search Trick)

We use **binary search on index pattern**

At any `mid`:

---

### Case 1: Pair is correct (left side)

If:

* `mid` is even AND `arr[mid] == arr[mid+1]`
* OR
* `mid` is odd AND `arr[mid] == arr[mid-1]`

👉 Means:
✅ We are on the **left side of the single element**

---

### Case 2: Pattern is broken

👉 Means:
❌ We are on the **right side (or at the single element)**

---

# 🚀 Strategy

* If pattern is correct → go **right**
* If pattern is broken → go **left**
* Continue until you land on the single element

---

# 🧩 Why Binary Search Works?

Because:

* Left side → perfect pairing pattern
* Right side → broken pattern
* So the array is like:

```
[ correct pattern | single element | broken pattern ]
```

👉 This is exactly what binary search needs:
**a monotonic property (true → false)**

---

# ⏱️ Complexity

* Time: **O(log n)** ✅ (because binary search)
* Space: **O(1)**

---

# 💡 Intuition in One Line

👉 “Check if pairing pattern is intact — if yes, go right; if broken, go left.”

---
---
---
---
---
---
---
---



# 🧠 Why Edge Cases Even Matter Here?

In this problem, we often check:

* `arr[mid - 1]`
* `arr[mid + 1]`

👉 So if `mid` is at:

* `0` → `mid - 1` ❌ invalid
* `n-1` → `mid + 1` ❌ invalid

That’s why edge handling is important.

---

# ⚠️ Common Edge Cases

## ✅ 1. Single element at the beginning

```text
[2,3,3,4,4]
```

👉 `arr[0] != arr[1]` → answer is **2**

---

## ✅ 2. Single element at the end

```text
[1,1,2,2,3]
```

👉 `arr[n-1] != arr[n-2]` → answer is **3**

---

## ✅ 3. Array size = 1

```text
[7]
```

👉 Direct answer = 7

---

# 🔥 Now Your Idea: “Trim and Start from 1 to n-2”

Yes, this is a **valid and clean approach** 👇

### 👉 Why we do this?

So we can safely check:

* `mid - 1`
* `mid + 1`

without worrying about out-of-bounds.

---

### So we:

* Handle edges **separately**
* Then apply binary search on:

```text
low = 1
high = n - 2
```

---

# 🎯 But There’s an EVEN BETTER Trick (No Edge Hassle)

Instead of checking both sides (`mid-1`, `mid+1`), we use:

👉 **Index parity (even/odd)**

---

## 💡 Trick:

Always make `mid` **even**

Then compare:

```text
arr[mid] with arr[mid + 1]
```

---

### Why this works?

Because pairs always start at **even index** (before the single element)

---

## 🧠 Cases:

### ✔ If equal:

👉 Pair is correct → go right

### ❌ If not equal:

👉 Single element is on left (including mid)

---

# 🚀 Advantage of This Trick

* No need to check `mid-1`
* No need to trim array
* No edge-case headache
* Cleaner logic

---

# 🧩 Final Intuition Comparison

### Your approach:

✔ Check both sides
✔ Handle edges manually
❌ Slightly complex

---

### Optimal concept:

✔ Use index parity
✔ Always compare with `mid+1`
✔ No boundary issues

---

# 💡 Golden Insight

👉 “Before the single element, pairs start at even index. After it, the pattern breaks.”
