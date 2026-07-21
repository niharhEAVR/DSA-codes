# 🧠 Problem: Find the Nth Root of an Integer

You are given:

* An integer **`x`**
* An integer **`n`**

You need to find a number **`r`** such that:

\[
r^n = x
\]

---

## 🔍 What does this actually mean?

* Square root → ( n = 2 )
* Cube root → ( n = 3 )
* Nth root → general case

### Example:

* ( x = 27, n = 3 ) → answer = **3** (because (3^3 = 27))
* ( x = 16, n = 4 ) → answer = **2**
* ( x = 10, n = 3 ) → ❌ no integer root

---

## ⚠️ Important Clarification (VERY important in interviews)

Most problems expect:

👉 **Return the integer root if it exists, otherwise return -1**

Because:

* Not all numbers have exact integer roots
* Example: ( \sqrt[3]{10} ) is not an integer

---

# 🧠 How should you think about solving it?

We are trying to find **r** such that:

\[
r^n = x
\]

So basically:
👉 “Find a number whose power equals x”

---

## ❌ Brute Force Idea (not good)

Try all numbers:

* Start from 1 → keep checking ( i^n )

Problem:

* Too slow if x is large (like (10^9))

---

## ✅ Optimal Idea → Binary Search

This is the key insight 🔥

### Why binary search?

Because:

* If ( r^n < x ) → go right
* If ( r^n > x ) → go left

👉 The function is **monotonic increasing**

---

## 🧩 Binary Search Thinking

Search space:
\[
[1, x]
\]

Steps:

1. Take mid
2. Compute ( mid^n )
3. Compare with x:

   * If equal → found answer
   * If smaller → search right
   * If larger → search left

---

# ⚠️ VERY IMPORTANT: Overflow Issue

If you directly compute:
\[
mid^n
\]

It can overflow (even for medium values)

👉 So instead:

* Multiply step by step
* Stop early if it exceeds x

---

# 🧠 Edge Cases (Interview gold 💯)

### 1. x = 0

* Root is always **0**

---

### 2. x = 1

* Root is always **1**

---

### 3. n = 1

* Answer is always **x**

---

### 4. No integer root exists

* Return **-1**

---

### 5. Large values

* Use overflow-safe multiplication

---

### 6. Negative numbers

Depends on constraints:

* If allowed:

  * Odd n → valid (e.g., cube root of -8 = -2)
  * Even n → invalid (no real integer root)

---

# 🧠 Implementation Logic (Step-by-step, no code)

Here’s exactly how you'd implement it:

---

## Step 1: Handle edge cases

* If x == 0 → return 0
* If x == 1 → return 1
* If n == 1 → return x

---

## Step 2: Define search space

* low = 1
* high = x

---

## Step 3: Binary search loop

Repeat while low ≤ high:

### a. Find mid

* mid = (low + high) / 2

---

### b. Compute mid^n safely

* Initialize result = 1
* Loop n times:

  * result *= mid
  * If result > x → stop early

---

### c. Compare

* If result == x → return mid
* If result < x → low = mid + 1
* If result > x → high = mid - 1

---

## Step 4: If not found

* Return **-1**

---

# 🧠 Time Complexity

* Binary Search: ( O(\log x) )
* Power calculation: ( O(n) )

👉 Total:
\[
O(n \cdot \log x)
\]

---

# 💡 Interview Insight

If interviewer pushes further:

You can optimize power calculation using:

* Fast exponentiation (binary exponentiation)

Then complexity becomes:
\[
O(\log x \cdot \log n)
\]

---

# 🎯 Summary (what you should say in interview)

> “I’ll use binary search on range [1, x].
> For each mid, I’ll compute mid^n carefully to avoid overflow.
> Based on comparison, I’ll adjust search space.
> If I find exact match, return mid; else return -1.”



---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
---

Your logic is correct, but the **problem is NOT binary search** — it’s this line:

```cpp
std::pow(mid, n)
```

---

# 🚨 Why your code gives wrong answers

## 1. ❌ `pow()` uses floating point (double)

`std::pow()` returns a **double**, not an integer.

So instead of exact values, you get approximations:

```cpp
pow(3, 5) → 242.999999999 (maybe)
```

Now your condition:

```cpp
if (pow(mid, n) == num)
```

👉 will often FAIL even if mathematically correct.

---

## 2. ❌ Equality check with double is unsafe

Comparing:

```cpp
double == int
```

is unreliable due to precision errors.

Even if:

* actual = 243
* computed = 242.9999999

👉 condition becomes false ❌

---

## 3. ❌ Recomputing pow multiple times

You are doing:

```cpp
pow(mid, n)
pow(mid, n)
```

multiple times per iteration → unnecessary overhead.

---

## 4. ❌ Overflow / undefined behavior (hidden issue)

For large values:

```cpp
pow(mid, n)
```

can exceed limits or lose precision badly.

---

# 🧠 What actually goes wrong (example)

Let’s say:

```cpp
num = 64, n = 3
```

You expect:

```cpp
mid = 4 → 4^3 = 64
```

But `pow(4, 3)` might be:

```cpp
63.9999999
```

So:

```cpp
if (pow(mid, n) == num) → false ❌
```

Then binary search moves incorrectly → wrong answer.

---

# ✅ Correct Approach (what you should do)

👉 NEVER use `pow()` here

Instead:

* Compute power manually
* Use integer math
* Stop early if value exceeds `num`

---

# 🔥 Key Insight (what interviewer wants)

> “Floating point operations introduce precision errors, so I’ll avoid `pow()` and compute the power using integer multiplication with early stopping.”

---

# ⚡ Minimal Fix Concept

Instead of:

```cpp
pow(mid, n)
```

Do:

* Multiply `mid` n times
* If result > num → break early

---

# 🎯 Summary

Your code fails because:

* ❌ `pow()` → floating point → precision loss
* ❌ equality check fails
* ❌ repeated computation
* ❌ possible overflow

---





# ✅ C++ Implementation (Binary Search + Safe Power)

```cpp
class Solution {
public:
    int nthRoot(int n, int x) {
        // Edge cases
        if (x == 0) return 0;
        if (x == 1) return 1;
        if (n == 1) return x;

        int low = 1, high = x;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int check = power(mid, n, x);

            if (check == 1) {
                return mid; // exact match
            } 
            else if (check == 0) {
                low = mid + 1; // mid^n < x
            } 
            else {
                high = mid - 1; // mid^n > x
            }
        }

        return -1; // no integer root
    }

private:
    // Returns:
    // 1 -> mid^n == x
    // 0 -> mid^n < x
    // 2 -> mid^n > x (or overflow)
    int power(int mid, int n, int x) {
        long long result = 1;

        for (int i = 0; i < n; i++) {
            result *= mid;

            // Early stopping to prevent overflow
            if (result > x) return 2;
        }

        if (result == x) return 1;
        return 0;
    }
};
```


# 🧠 Why this is solid (interview perspective)

* ✅ Uses **binary search** → (O(\log x))
* ✅ Avoids overflow using:

  * `long long`
  * early break when `result > x`
* ✅ Handles all edge cases:

  * `x = 0, 1`
  * `n = 1`
  * no root → returns `-1`

---

# ⚠️ Common Mistakes (avoid these)

* ❌ Using `pow()` → floating point issues
* ❌ Not handling overflow → wrong answers
* ❌ Not early breaking → TLE for large inputs
* ❌ Returning floor instead of exact match (depends on problem)
