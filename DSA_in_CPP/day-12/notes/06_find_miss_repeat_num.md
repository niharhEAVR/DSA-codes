# ✅ **Problem: Find the Missing and Repeating Number**

You are given an array of size **n** containing numbers from **1 to n**, but:

* **One number is missing**
* **One number is repeating**

Example:
`arr = [1, 3, 3]`
Here, **3 is repeating**, **2 is missing**.

Your task → **Find (repeating, missing)**.

---

# ✅ **Brute Force Approach (Simplest method)**

### **Idea**

For each number **1 to n**, count how many times it appears in the array.

* If count = **2** → that number is **repeating**
* If count = **0** → that number is **missing**

---

# ✅ **Brute Force Code (C++ / any language logic)**

### ✔️ **Approach 1: Count each number using 2 loops**

```cpp
pair<int,int> findMissingAndRepeating(vector<int>& arr) {
    int n = arr.size();
    int repeating = -1, missing = -1;

    for (int num = 1; num <= n; num++) {
        int count = 0;

        // count frequency of num in array
        for (int x : arr) {
            if (x == num) count++;
        }

        if (count == 2) repeating = num;
        if (count == 0) missing = num;
    }

    return {repeating, missing};
}
```

---

# ⏳ **Time & Space Complexity**

\[
\text{Time Complexity} = O(n^2)
\]

Because for every number 1…n, you scan the whole array again.

\[
\text{Space Complexity} = O(1)
\]

---

# 🧠 **Simple Explanation**

* The brute approach checks **every number**, counts how many times it appears.
* It works but is **slow** because of nested loops.

---
---
---


# ✅ **Better Approach (Using Extra Array / Hashing)**

### **Idea**

Instead of counting each number with nested loops,
we keep a **frequency array** (size = n+1) where:

* `freq[x]` = how many times number **x** appears.

Then:

* If `freq[x] == 2` → **x is repeating**
* If `freq[x] == 0` → **x is missing**

This removes the inner loop → much faster.

---

# ✅ **Steps**

1. Create an array `freq` of size `n+1` initialized to 0
2. Loop through the input array and do:
   `freq[arr[i]]++`
3. Loop from `1` to `n`:

   * if `freq[x] == 2` → repeating
   * if `freq[x] == 0` → missing

---

# ✅ **Code (C++ Logic)**

```cpp
pair<int,int> findMissingAndRepeating(vector<int>& arr) {
    int n = arr.size();
    vector<int> freq(n + 1, 0);

    // Step 1: Count frequencies
    for (int x : arr) {
        freq[x]++;
    }

    int repeating = -1, missing = -1;

    // Step 2: Check which number is freq=0 and freq=2
    for (int i = 1; i <= n; i++) {
        if (freq[i] == 2) repeating = i;
        if (freq[i] == 0) missing = i;
    }

    return {repeating, missing};
}
```

---

# ⏳ **Time & Space Complexity**

### **Time Complexity:**

\[
O(n)
\]
We traverse the array once to count, once to inspect.

### **Space Complexity:**

\[
O(n)
\]
Because we use a frequency array of size `n+1`.

---

# 🧠 **Why is this better?**

The brute force repeated scanning → **slow**
Here we store counts only once → **faster**

---
---
---





<br>
<br>
<br>


# There are **two optimal methods**:

# ✅ **Optimal Approach 1 — Math (Sum + Sum of Squares)**

* Time: **O(n)**
* Space: **O(1)**
* Uses formulas for sum and sum of squares.

You already learned this.



# ✅ **Why does the Math Approach work?**

Think about two facts:

### **1. Sum of first n natural numbers**

\[
S = \frac{n(n+1)}{2}
\]

### **2. Sum of squares of first n natural numbers**

\[
S_2 = \frac{n(n+1)(2n+1)}{6}
\]

Now compute:

* Actual array sum = `arrSum`
* Actual array square sum = `arrSquareSum`

There will be differences:

---

# ⭐ Step 1: Form Equation (i)

### Difference of sums:

\[
arrSum - S = x - y
\]

Let:
\[
D_1 = x - y
\]

---

# ⭐ Step 2: Form Equation (ii)

### Difference of square sums:

\[
arrSquareSum - S_2 = x^2 - y^2
\]

Recall the identity:
\[
x^2 - y^2 = (x - y)(x + y)
\]

So:
\[
arrSquareSum - S_2 = D_1 \cdot (x + y)
\]

Let:
\[
D_2 = arrSquareSum - S_2
\]

Then:
\[
x + y = \frac{D_2}{D_1}
\]

---

# ⭐ Step 3: Solve the two equations

We now have:

1. \[
   x - y = D_1
   \]
2. \[
   x + y = \frac{D_2}{D_1}
   \]

Add both equations:

\[
2x = D_1 + \frac{D_2}{D_1}
\]

\[
x = \frac{D_1 + \frac{D_2}{D_1}}{2}
\]

Then:

\[
y = x - D_1
\]

This gives the **Repeating (x)** and **Missing (y)** numbers.

---

---

### **!!. You must use `long long`, not `int`**

Otherwise overflow will kill your calculation.

---

# ✅ **Let’s choose an example to demonstrate**

Suppose:

```
nums = [1, 5, 3, 4, 5]   (n = 5)
```

Here:

* Repeating = 5
* Missing = 2

Let’s compute step-by-step.

---

# 🧮 Step 1 — Compute sums

### **Expected sum**

\[
E_1 = \frac{n(n+1)}{2} = \frac{5\cdot6}{2} = 15
\]

### **Actual sum**

\[
S_1 = 1 + 5 + 3 + 4 + 5 = 18
\]

### **Difference**

\[
D = S_1 - E_1 = 18 - 15 = 3
\]

So:

\[
x - y = 3 \quad \text{(Equation 1)}
\]

---

# 🧮 Step 2 — Square sums

### **Expected square sum**

\[
E_2 = \frac{n(n+1)(2n+1)}{6} = \frac{5\cdot6\cdot11}{6} = 55
\]

### **Actual square sum**

\[
S_2 = 1 + 25 + 9 + 16 + 25 = 76
\]

### **Difference**

\[
Q = S_2 - E_2 = 76 - 55 = 21
\]

Now:

\[
x^2 - y^2 = 21
\]

Factor:

\[
x^2 - y^2 = (x-y)(x+y)
\]

So:

\[
(x+y) = \frac{Q}{D} = \frac{21}{3} = 7
\]

Now:

* Eq(1): x − y = 3
* Eq(2): x + y = 7

Add:

\[
2x = 10 \Rightarrow x = 5
\]

Now:

\[
y = x - 3 = 5 - 3 = 2
\]

### So final answer:

**Repeating = 5**
**Missing = 2**

---

# 🎯 **NOW THE FINAL OPTIMAL C++ CODE (Correct & Clean)**

```cpp
std::pair<int, int> optimalMath(std::vector<int> &nums, int n)
{
    long long E1 = (1LL * n * (n + 1)) / 2;                 // expected sum
    long long E2 = (1LL * n * (n + 1) * (2*n + 1)) / 6;     // expected square sum

    long long S1 = 0, S2 = 0;
    for(long long x : nums){
        S1 += x;
        S2 += 1LL * x * x;
    }

    long long D  = S1 - E1;        // x - y
    long long Q  = S2 - E2;        // x^2 - y^2 = (x-y)(x+y)

    long long sum_xy = Q / D;      // x + y

    long long x = (D + sum_xy) / 2;
    long long y = x - D;

    return { (int)x , (int)y };    // (repeating, missing)
}
```

---

# 🚀 Output for test array

If `nums = {1,5,3,4,5}` →
returns: `{5, 2}` → Correct.