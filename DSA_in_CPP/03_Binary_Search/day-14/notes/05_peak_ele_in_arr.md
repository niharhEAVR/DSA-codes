# 🧠 What is “Peak Element” Problem?

👉 You are given an array.

👉 A **peak element** is an element which is:

\[
\text{greater than its neighbors}
\]

---

### 📌 Example

```text
[1, 3, 2, 5, 4]
```

Peaks:

* `3` (greater than 1 and 2)
* `5` (greater than 2 and 4)

👉 You can return **any one peak**

---

# ⚠️ Important Clarification

* Array is **NOT necessarily sorted**
* There can be **multiple peaks**
* You just need to return **one peak index/value**

---

# 🧩 Special Assumption (VERY IMPORTANT)

We assume:

[
arr[-1] = -\infty,\quad arr[n] = -\infty
]

👉 Meaning:

* First element can be a peak
* Last element can also be a peak

---

# 🔍 Understanding the Pattern

Think of the array like a **mountain landscape ⛰️**

* Increasing → going uphill
* Decreasing → going downhill

👉 A peak is where:

* uphill → downhill

---

# 🎯 Key Insight (CORE CONCEPT)

👉 If you are at index `mid`:

Compare:

* `arr[mid]` and `arr[mid+1]`

---

## 🧠 Case 1: Going UP

```text
arr[mid] < arr[mid+1]
```

👉 You are on an **increasing slope**

✔ Means: A peak **must exist on the right side**

---

## 🧠 Case 2: Going DOWN

```text
arr[mid] > arr[mid+1]
```

👉 You are on a **decreasing slope**

✔ Means: A peak is **on the left side (including mid)**

---

# 🚀 Strategy (Binary Search Concept)

* If increasing → go **right**
* If decreasing → go **left**
* Eventually → you land on a peak

---

# 📉 Why Binary Search Works?

Because:

👉 The array behaves like:

```text
uphill → peak → downhill
```

Even if there are multiple peaks, **at least one always exists**

---

# ⚡ Complexity

* Time: **O(log n)**
* Space: **O(1)**

---

# ⚠️ ALL Edge Cases (Very Important)

---

## ✅ 1. Single Element

```text
[10]
```

👉 It’s automatically a peak

---

## ✅ 2. Two Elements

```text
[1, 2] → peak = 2  
[2, 1] → peak = 1
```

👉 Just return the larger one

---

## ✅ 3. Peak at Beginning

```text
[5, 3, 2, 1]
```

👉 `5` is peak (greater than right neighbor)

---

## ✅ 4. Peak at End

```text
[1, 2, 3, 6]
```

👉 `6` is peak

---

## ✅ 5. Strictly Increasing

```text
[1, 2, 3, 4, 5]
```

👉 Last element is peak

---

## ✅ 6. Strictly Decreasing

```text
[5, 4, 3, 2, 1]
```

👉 First element is peak

---

## ✅ 7. Multiple Peaks

```text
[1, 3, 2, 4, 1]
```

👉 Peaks = 3 and 4
👉 Return any one

---

# ⚠️ Boundary Safety (Important)

We only compare:

```text
arr[mid] and arr[mid+1]
```

👉 So we ensure:

* `mid < n-1`

That’s why binary search runs like:

```text
low = 0, high = n-1
while low < high
```

---

# 💡 Golden Intuition (Remember This)

👉 “If I’m going up → peak is ahead
If I’m going down → peak is behind”

---

# 🧩 Visual Understanding

```text
1   3   5   4   2
        ↑
      peak
```

* Left side increasing
* Right side decreasing

Binary search helps you **climb toward the peak**
