# 🔥 Maximum Product Subarray — FULL EXPLANATION (Beginner Friendly)

## ✅ **What is the problem?**

Given an array of integers (may include positive, negative, or zero), you must find the **maximum product of any subarray**.

A **subarray** means continuous elements.

### Example:

```
Input: [2, 3, -2, 4]
Output: 6
Explanation: Maximum product = 2 × 3 = 6
```

---

# ❓ Why is this problem tricky?

Because:

### ### **1. Negative numbers flip sign**

(-2) × (4) = -8
But (-2) × (-3) = +6 → suddenly very large.

### **2. Zero breaks the product**

Any product with 0 becomes 0.
You must restart after a zero.

### **3. The maximum product can come from:**

* continuous positives
* or two negatives (because - × - = +)
* or restarting after zero

Therefore, just multiplying in one direction does NOT work.

---

# 🧠 **KEY IDEA (VERY IMPORTANT)**

At every index you must track two things:

\[
\textbf{maxProd} = \text{maximum product ending at current index}
\]
\[
\textbf{minProd} = \text{minimum product ending at current index}
\]

Why minProd?

👉 Because a **big negative** can become **big positive** if multiplied by another negative later.

So at each index:

```
maxProd = max( current_number,
               maxProd * current_number,
               minProd * current_number )

minProd = min( current_number,
               maxProd * current_number,
               minProd * current_number )
```

And update a global answer.

---

# ⚙️ **Optimal Algorithm (O(n), Kadane-like but for products)**

## STEP-WISE UNDERSTANDING

### 1. Initialize:

```
maxProd = nums[0]
minProd = nums[0]
answer = nums[0]
```

### 2. Loop from index 1:

Let the current element be `x`.

Three cases:

* `x`
* `maxProd * x`
* `minProd * x`

All possible products.

We choose the maximum for new maxProd
We choose the minimum for new minProd

### 3. Update global maximum:

```
answer = max(answer, maxProd)
```

---

# ✔️ **Let’s do a FULL DRY RUN**

Array:

```
[2, 3, -2, 4]
```

---

## **Start:**

```
maxProd = 2
minProd = 2
answer  = 2
```

---

## **i = 1 → element = 3**

Possible products:

* just 3
* maxProd * 3 = 2*3 = 6
* minProd * 3 = 2*3 = 6

So:

```
maxProd = 6
minProd = 3
answer = 6
```

---

## **i = 2 → element = -2**

Negative flips!

Possible:

* just -2
* maxProd * -2 = 6 * -2 = -12
* minProd * -2 = 3 * -2 = -6

So:

```
maxProd = max(-2, -12, -6) = -2
minProd = min(-2, -12, -6) = -12
answer = max(6, -2) = 6
```

---

## **i = 3 → element = 4**

Possible:

* just 4
* maxProd * 4 = -2 * 4 = -8
* minProd * 4 = -12 * 4 = -48

So:

```
maxProd = 4
minProd = -48
answer = max(6, 4) = 6
```

---

# 🎉 FINAL ANSWER = **6**

---

# 💡 Intuition Summary (In Simple Words)

* Positive number makes max bigger
* Negative number flips max/min
* Zero resets everything
* min is stored because future negative can turn it into max
* Track at each index:
  ✓ biggest product ending here
  ✓ smallest product ending here

---
---
---
---



# ✅ **OPTIMAL APPROACH (O(n) Time, O(1) Space) for Negative**

This is the solution that passes **LeetCode 152 — Maximum Product Subarray**.

The trick is:

### ⭐ Keep track of both:

\[
\text{maxProd} \quad \text{and} \quad \text{minProd}
\]

Because a negative number can turn your current **min** into a **max**.

---

# 🔥 **Intuition (EXACTLY what you need for LeetCode)**

At every element `x`, calculate 3 things:

* `x` itself
* `maxProd * x` → extend positive streak
* `minProd * x` → negative × negative becomes positive

Your new:

\[
\text{maxProd} = \max(x, \ maxProd \cdot x,\ minProd \cdot x)
\]

\[
\text{minProd} = \min(x, \ maxProd \cdot x,\ minProd \cdot x)
\]

Maintain a global:

\[
\text{answer} = \max(answer,\ maxProd)
\]

---

# 🧠 **IMPORTANT RULE**

### ❗ Before calculating, if the number is **negative**, swap:

```
if (x < 0) swap(maxProd, minProd)
```

Because a negative flips everything.

This is the easiest way to implement it.

---

# 🧾 **Optimal Code (Accepted on LeetCode)**

```cpp
int maxProduct(vector<int>& nums) {
    int maxProd = nums[0];
    int minProd = nums[0];
    int ans = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        int x = nums[i];

        // If x is negative, swap max and min
        if (x < 0) {
            swap(maxProd, minProd);
        }

        maxProd = max(x, maxProd * x);
        minProd = min(x, minProd * x);

        ans = max(ans, maxProd);
    }

    return ans;
}
```

---

# 🟦 FULL DRY RUN (like you want)

Array:

```
[-2, 3, -4]
```

---

## Start:

```
maxProd = -2
minProd = -2
ans = -2
```

---

## i = 1 → x = 3

Since 3 is positive → no swap.

```
maxProd = max(3, -2*3 = -6) = 3
minProd = min(3, -2*3 = -6) = -6
ans = max(-2, 3) = 3
```

---

## i = 2 → x = -4

Negative → **swap maxProd and minProd**

Before swap:

```
maxProd = 3
minProd = -6
```

After swap:

```
maxProd = -6
minProd = 3
```

Now compute:

```
maxProd = max(-4, -6 * -4 = 24) = 24
minProd = min(-4,  3 * -4 = -12) = -12
ans = max(3, 24) = 24
```

---

# ⭐ Final Answer = **24**

---

# 🟢 Explanation Summary (in 15 seconds)

* Track max & min because negatives flip signs
* Swap if current number is negative
* Update maxProd and minProd
* Record best maxProd in ans
* Runs in O(n) and passes all LeetCode tests

---
---
---

It is **Kadane’s Algorithm *modified for products***.


---

# ✅ **Kadane vs Maximum Product Subarray (Your Confusion Solved)**

## ✔️ **Normal Kadane Algorithm**

Used for:

### → Maximum *sum* subarray

Formula:

```
currSum = max(nums[i], currSum + nums[i])
answer = max(answer, currSum)
```

**Only one variable (`currSum`) needed**,
because sum does **NOT** flip sign when multiplying by negative.

---

# ❌ Why we CANNOT use pure Kadane for product?

Because product has 3 problems:

### 1. Negative flips the sign

2 → OK
-2 → flips
(-2) × (-3) → becomes +6 (big!)

### 2. Zero destroys the product

Kadane resets on negative sum but product behaves differently.

### 3. Need to track BOTH max and min

Because a negative min could become the new max.

Kadane only tracks 1 running value.
Maximum Product requires 2 variables (max & min).

---

# ⭐ **Modified Kadane = Maximum Product Subarray**

We still do "choose the best at each step"
(so the greedy idea is same as Kadane),

BUT instead of 1 value, we keep **two**:

```
maxProd
minProd
```

And handle negative values by **swapping**.

This version is called:

### ✔️ “Kadane’s Algorithm for Products”

### ✔️ “Modified Kadane for Product”

### ✔️ “Product Kadane”

All are correct names.

---

# 🟩 So FINAL ANSWER:

### **YES — this is the Kadane algorithm *adapted for multiplication***

→ same greedy idea
→ but extended to handle negative × negative and zeros.
