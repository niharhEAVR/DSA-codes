# 🚀 **WHAT ARE FLOOR AND CEIL IN ARRAYS (DSA meaning)?**

Given a **sorted array**, and a **target x**, we want:

### ⭐ Floor

**The largest element in the array that is ≤ x**

### ⭐ Ceil

**The smallest element in the array that is ≥ x**

Exact translation:

| Math Concept | Array DSA equivalent |
| ------------ | -------------------- |
| floor(x)     | max element ≤ x      |
| ceil(x)      | min element ≥ x      |

---

# 🧠 Example Array

```
arr = [1, 2, 4, 7, 10, 12]
```

---

# 📌 Example 1: x = 5

### floor(5) = 4

(because 4 ≤ 5 and it’s the biggest such number)

### ceil(5) = 7

(because 7 ≥ 5 and it's the smallest such number)

---

# 📌 Example 2: x = 7

### floor(7) = 7

### ceil(7) = 7

When x exists, both are the number itself.

---

# 📌 Example 3: x = 0

(no element ≤ 0)

### floor = none (usually return -1 or something)

### ceil = 1

---

# 📌 Example 4: x = 100

(no element ≥ 100)

### floor = 12

### ceil = none

---

# 😮 INTERESTING TRUTH (VERY IMPORTANT)

### ✔ Ceil = Lower Bound(x)

because lower bound gives the:

> first index where arr[i] ≥ x
> which is EXACTLY ceil.

### ✔ Floor = Upper Bound(x) - 1

Upper bound gives:

> first index where arr[i] > x

So the element **just before** it is:

> largest element ≤ x = floor

So:

```
floorIndex = upperBound(x) - 1
ceilIndex = lowerBound(x)
```

---

# 🧠 LET’S DO A FULL DRY RUN

Array:

```
arr = [1, 2, 4, 7, 10, 12]
```

x = 5

---

## ⭐ Ceil (lower bound)

We want the first element ≥ 5.

Perform lower bound logic:

* 1 < 5 → go right
* 2 < 5 → go right
* 4 < 5 → go right
* 7 ≥ 5 → this is the first ≥ 5

### ✔ Ceil = 7

---

## ⭐ Floor (upper bound - 1)

Upper bound finds first > 5:

* 1 ≤ 5
* 2 ≤ 5
* 4 ≤ 5
* 7 > 5 → this is upper bound

UpperBound(5) = index of 7 = 3

Floor index = 3 - 1 = 2
arr[2] = 4

### ✔ Floor = 4

---

# 🧩 CODE IMPLEMENTATION

## ⭐ Ceil using Lower Bound

```cpp
int ceilValue(vector<int>& arr, int x) {
    int idx = lowerBound(arr, x); // first >= x
    if (idx == arr.size()) return -1;  // ceil does not exist
    return arr[idx];
}
```

---

## ⭐ Floor using Upper Bound

```cpp
int floorValue(vector<int>& arr, int x) {
    int idx = upperBound(arr, x); // first > x
    if (idx == 0) return -1;      // no element <= x
    return arr[idx - 1];
}
```

---

# 🎯 SUMMARY (VERY VERY IMPORTANT)

| Concept   | Definition           | How to compute      |
| --------- | -------------------- | ------------------- |
| **Ceil**  | smallest element ≥ x | `lowerBound(x)`     |
| **Floor** | largest element ≤ x  | `upperBound(x) - 1` |

This is 100% correct and used in all DSA problems.

---
---
---



# ✅ **1. Ceil (smallest element ≥ x)**

This is **Lower Bound**.

```cpp
int findCeil(vector<int> &arr, int x) {
    int low = 0, high = arr.size() - 1;
    int ans = -1; // if ceil does not exist

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x) {
            ans = arr[mid];   // possible ceil
            high = mid - 1;   // try to find smaller ≥ x
        } else {
            low = mid + 1;
        }
    }

    return ans;
}
```

### ✔ Logic:

Find first element **≥ x** → that’s the ceil.

---

# ✅ **2. Floor (largest element ≤ x)**

This is based on **Upper Bound - 1** logic.

```cpp
int findFloor(vector<int> &arr, int x) {
    int low = 0, high = arr.size() - 1;
    int ans = -1; // if floor does not exist

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= x) {
            ans = arr[mid];   // possible floor
            low = mid + 1;    // try to find bigger ≤ x
        } else {
            high = mid - 1;
        }
    }

    return ans;
}
```

### ✔ Logic:

Find last element **≤ x** → that’s the floor.

---

# 🎯 **EXAMPLE**

```
arr = [1, 2, 4, 7, 10, 12]
x = 5
```

* Ceil = 7
* Floor = 4

Both functions will return exactly these.

---

# ⭐ BONUS: STL one-liners (if allowed)

```cpp
int ceilStl = *lower_bound(arr.begin(), arr.end(), x);
int floorStl = *(upper_bound(arr.begin(), arr.end(), x) - 1);
```

(With boundary checks.)

---

---
---
---


# ✅ **1. What is this code?**

```cpp
auto it = lower_bound(arr.begin(), arr.end(), target);
auto it2 = upper_bound(arr.begin(), arr.end(), target);
```

These are **STL binary-search functions** from `<algorithm>`:

### ✔ `lower_bound(begin, end, x)`

Returns an iterator pointing to the **first element ≥ x**.

### ✔ `upper_bound(begin, end, x)`

Returns iterator to the **first element > x**.

---

# ✅ **2. How do FLOOR and CEIL come from this?**

### 👉 **Ceil(x)** = smallest element **≥ x**

So we use **lower_bound**.

### 👉 **Floor(x)** = largest element **≤ x**

So we use **upper_bound(x) – 1**.

---

# ✅ **3. The C++ Code**

```cpp
int ceilValue(vector<int>& arr, int x) {
    auto it = lower_bound(arr.begin(), arr.end(), x);
    if (it == arr.end()) return -1;     // no ceil exists
    return *it;
}

int floorValue(vector<int>& arr, int x) {
    auto it = upper_bound(arr.begin(), arr.end(), x);
    if (it == arr.begin()) return -1;   // no floor exists
    return *(it - 1);
}
```

---

# ✅ **4. Dry Run (Very Detailed)**

We use this sorted array:

```
arr = [2, 3, 5, 9, 14, 16, 18]
```

Target:

```
x = 10
```

---

# ⭐ **CEIL Dry Run (using `lower_bound`)**

Goal: **first element ≥ 10**

`lower_bound(arr.begin(), arr.end(), 10)` uses binary search internally.

### Array:

```
Index: 0 1 2 3  4  5  6
Value: 2 3 5 9 14 16 18
```

### Step-by-step search:

#### Step 1

L = 0, R = 6
mid = (0 + 6) / 2 = 3
arr[3] = 9

9 < 10 → go right
L = 4

#### Step 2

L = 4, R = 6
mid = (4 + 6) / 2 = 5
arr[5] = 16

16 ≥ 10 → possible answer, go left
R = 5 - 1 = 4

#### Step 3

L = 4, R = 4
mid = 4
arr[4] = 14

14 ≥ 10 → possible answer, go left
R = 4 - 1 = 3

Loop ends.

### Output iterator → **arr[4] = 14**

✔ **CEIL(10) = 14**

---

# ⭐ **FLOOR Dry Run (using `upper_bound`)**

Goal: **largest element ≤ 10**

`upper_bound(arr.begin(), arr.end(), 10)` returns iterator to **first element > 10**.

### Step-by-step:

#### Step 1

L = 0, R = 6
mid = 3
arr[3] = 9

9 ≤ 10 → go right
L = 4

#### Step 2

L = 4, R = 6
mid = 5
arr[5] = 16

16 > 10 → go left
R = 5 - 1 = 4

#### Step 3

L = 4, R = 4
mid = 4
arr[4] = 14

14 > 10 → go left
R = 4 - 1 = 3

Loop ends.

### upper_bound returns iterator to index 4

Now floor = *(it - 1) = arr[3] = 9

✔ **FLOOR(10) = 9**

---

# 🎉 Final Answers

| Query     | Output |
| --------- | ------ |
| Ceil(10)  | **14** |
| Floor(10) | **9**  |

---
---
---
---



# ✅ **Correct Rule for `upper_bound()`**

`upper_bound(arr.begin(), arr.end(), x)` returns the **first index where:**

\[
arr[i] > x
\]

✔ **FIRST element strictly GREATER than x**
✔ NOT ≥ x
✔ NOT equal to x
✔ STRICTLY “> x”

---

# 👉 BUT THEN WHY DO WE USE `upper_bound(x) - 1` FOR FLOOR?

Let’s break that.

### upper_bound gives:

\[
\text{first element > x}
\]

If this element is at index `i`,
then the element just before that (`i - 1`) must be:

\[
\le x
\]

So:

\[
\text{floor} = arr[i - 1]
\]

---

# 🧠 **Illustration with a simple example**

```
arr = [2, 3, 5, 9, 14, 16]
x = 10
```

### Step 1: upper_bound(arr, 10)

Find first element > 10 → **14**

14 is at index **4**
So iterator points to index 4.

### Step 2: floor = *(it - 1)

(it - 1) → index 3 → value **9**

✔ Floor(10) = 9
✔ Because 9 ≤ 10
✔ 14 is the first value > 10

---

# 🔥 SUMMARY TABLE (REMEMBER THIS FOREVER)

| Function           | Condition  | Meaning                            |
| ------------------ | ---------- | ---------------------------------- |
| **lower_bound(x)** | arr[i] ≥ x | first element ≥ x → CEIL           |
| **upper_bound(x)** | arr[i] > x | first element > x → used for FLOOR |

---

# 📌 Let’s verify with another example

```
arr = [1, 4, 7, 9, 12]
x = 7
```

### lower_bound(7)

* first ≥ 7 → **7** → ceil = 7

### upper_bound(7)

* first > 7 → **9**
* so floor = *(index of 9 - 1) = 7

---

# 🏁 FINAL ANSWER

✔ **Yes, upper_bound uses `arr[i] > x`**
✔ And that is exactly why we take *one step back* to get the floor.

---
---
---

### **upper_bound(x) gives the first element > x**

→ Then **floor = previous element** (i.e., ≤ x)

---

# 🔥 EXAMPLE ARRAY (with repeats)

```
arr = [1, 2, 2, 2, 4, 4, 7, 9, 9, 15]
x = 8
```

Our goal: **Floor(8)**
Meaning → largest value **≤ 8**

Correct answer should be: **7**

Now we’ll **visualize how upper_bound finds this**.

---

# ✅ **Binary Search Dry Run for `upper_bound(arr, x)`**

### Search condition:

```
arr[mid] > x   --> move high = mid - 1
else           --> move low = mid + 1
```

Because upper bound = **first element strictly > x**.

---

# 🔍 Step-by-step Dry Run

```
arr = [1, 2, 2, 2, 4, 4, 7, 9, 9, 15]
x = 8

low = 0
high = 9
```

---

## **Step 1**

```
mid = (0 + 9) / 2 = 4
arr[4] = 4
```

Check condition:

```
4 > 8 ? NO
```

So:

```
low = mid + 1 = 5
```

---

## **Step 2**

```
low = 5, high = 9
mid = (5 + 9) / 2 = 7
arr[7] = 9
```

Check condition:

```
9 > 8 ? YES
```

So:

```
high = mid - 1 = 6
```

---

## **Step 3**

```
low = 5, high = 6
mid = (5 + 6) / 2 = 5
arr[5] = 4
```

Check:

```
4 > 8 ? NO
```

So:

```
low = mid + 1 = 6
```

---

## **Step 4**

```
low = 6, high = 6
mid = 6
arr[6] = 7
```

Check:

```
7 > 8 ? NO
```

So:

```
low = mid + 1 = 7
```

---

## **STOP**

Now:

```
low = 7
high = 6
```

Loop ends.

### 📌 RESULT:

`upper_bound` returns index `low = 7`
Because that is the **first index where arr[i] > x**.

Let's check:

```
arr[7] = 9
```

Correct — 9 is the **first value greater than 8**.

---

# 🎯 Now FIND FLOOR

> Floor = largest element ≤ x
> In upper_bound logic → **previous index**

```
upper_bound index = 7
so floor index = 7 - 1 = 6
```

Value at index 6:

```
arr[6] = 7
```

✔ **FLOOR(8) = 7**

---

# 💡 WHY THIS WORKS (VISUALIZE)

After upper_bound finishes:

```
Elements 0 to 6  → all ≤ x  
Element 7        → first > x
Elements after   → all > x
```

So the floor MUST be at index 6.

```
[ 1, 2, 2, 2, 4, 4, 7 | 9, 9, 15 ]
                          ↑
                 first > 8 (upper_bound result)
```

Look left from this position → you get the floor.

---

# 🧠 ANOTHER EXAMPLE (EVEN MORE REPEATS)

If you want, we can also dry run this case:

```
arr = [2,2,2,2,5,5,5,8,8,10,10]
x = 5
```

Or

```
arr = [1,1,1,1,1]
x = 1
```
