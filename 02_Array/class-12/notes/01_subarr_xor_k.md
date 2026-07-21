**“Number of Subarrays with XOR = K”** — *Brute → Better → Optimal*.

---

# ✅ **What is “Subarray XOR = K”?**

You are given:

* An **array**
* A **number K**

You must find **how many subarrays have XOR equal to K**
(or sometimes find any one such subarray).

---

# 🔍 First: What is a Subarray?

A **subarray** means:

* Continuous elements
* No skipping allowed

Example:

Array:

```
[4, 2, 1]
```

Subarrays are:

```
[4]
[4, 2]
[4, 2, 1]
[2]
[2, 1]
[1]
```

---

# 🔍 Second: What is XOR?

XOR is a bitwise operator:

```
a XOR b = c
```

Truth table:

| a | b | a^b |
| - | - | --- |
| 0 | 0 | 0   |
| 1 | 1 | 0   |
| 0 | 1 | 1   |
| 1 | 0 | 1   |

Important properties:

1. **x ^ x = 0**
2. **x ^ 0 = x**
3. **XOR is reversible:**
   If

   ```
   A ^ B = C  
   → A = C ^ B  
   → B = A ^ C
   ```

This reversible property is the key to the optimal solution.

---

# 🎯 NOW: What does “Subarray XOR equals K” mean?

It means:

> You have to find those **continuous parts of the array whose XOR = K**.

Example:

```
arr = [4, 2, 2, 6, 4]
K = 6
```

We need all subarrays whose XOR is **exactly 6**.

---

# 🍃 Let’s visualize with XOR step by step

Compute XOR for every subarray:

### Example check:

Subarray: `[4, 2]`

```
4 ^ 2 = 6
```

So this subarray is valid!

Another one: `[2, 2, 6]`

```
2 ^ 2 ^ 6 = (2^2) ^ 6
         = 0 ^ 6
         = 6   ← valid
```

Another: `[6]`

```
6 = 6 ← valid
```

Another: `[4, 2, 2, 6, 4]`

```
4^2^2^6^4 = 6  ← valid
```

---

# 🟦 Summary

**Subarray XOR = K means → find continuous parts of array whose XOR result is equal to K.**

---
---
---



# 🟥 1. Brute Force (Very Simple, but Slow)

### **Idea**

Check **every possible subarray**.

### Steps

1. Pick a starting point `i`
2. Pick an ending point `j ≥ i`
3. Compute XOR of subarray `arr[i..j]`
4. If XOR = K → count++

### Time complexity

\[
O(n^3)
\]
because:

* Picking `i`: n
* Picking `j`: n
* Calculating XOR each time: n

### Visualization

All subarrays:

```
[4]
[4,2]
[4,2,2]
[4,2,2,6]
...

[2]
[2,2]
[2,2,6]
...

etc.
```

---


# 🚀 **Better Approach (Time: O(n²), Space: O(1))**

### 🌟 KEY IDEA:

Instead of recalculating XOR for every subarray from scratch, we:

### **Fix a starting index `l`**

and then **extend `r` forward**, updating a running XOR:

\[
\text{curXor} = arr[l] \oplus arr[l+1] \oplus \ldots \oplus arr[r]
\]

This saves repeating the XOR work.

---

# 🧠 **Why this is better than brute?**

Brute (O n³):

```
loop l
    loop r
        loop i = l to r  <-- bad!!
```

Better (O n²):

```
loop l
    curXor = 0
    loop r
        curXor ^= arr[r]
```

We do NOT re-scan from l to r each time.

---

# 🟦 Base Cases Explained

### ✔ Case 1: Empty array

```
arr = []
```

No subarrays → return 0.

### ✔ Case 2: One element

If:

* element == K → count = 1
* else → count = 0

### ✔ Case 3: K = 0

We simply check if a subarray XOR becomes 0.

### ✔ Case 4: Zeros inside the array

XOR naturally handles them:

```
curXor ^= 0  → no change
```

### ✔ Case 5: Negative numbers

XOR still works bitwise.
(Though DSA questions usually avoid negatives.)

---

# ✔️ **Better Approach Code (C++ with full explanation)**

```cpp
#include <bits/stdc++.h>
using namespace std;

int countSubarraysXorBetter(vector<int> &arr, int K) {
    int n = arr.size();
    if (n == 0) return 0; // base case: empty array

    int count = 0;

    // FIX left index l
    for (int l = 0; l < n; l++) {

        int curXor = 0; // reset running XOR for each l

        // EXPAND r from l to end
        for (int r = l; r < n; r++) {

            curXor ^= arr[r];  // update running XOR

            // if XOR of subarray arr[l..r] is K
            if (curXor == K) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    vector<int> arr = {4, 2, 2, 6, 4};
    int K = 6;
    cout << "Count = " << countSubarraysXorBetter(arr, K) << endl;
}
```

---

# 🔥 **Now FULL Dry Run (Very Detailed)**

Array:

```
arr = [4, 2, 2, 6, 4]
K = 6
```

---

## ▶ `l = 0`

`curXor = 0`

### r = 0

```
curXor = 0 ^ 4 = 4
4 != 6 → no count
```

### r = 1

```
curXor = 4 ^ 2 = 6
6 == 6 → count = 1
subarray = [4, 2]
```

### r = 2

```
curXor = 6 ^ 2 = 4
4 != 6
```

### r = 3

```
curXor = 4 ^ 6 = 2
2 != 6
```

### r = 4

```
curXor = 2 ^ 4 = 6
6 == 6 → count = 2
subarray = [4,2,2,6,4]
```

---

## ▶ `l = 1`

`curXor = 0`

### r = 1

```
curXor = 0 ^ 2 = 2
```

### r = 2

```
curXor = 2 ^ 2 = 0
```

### r = 3

```
curXor = 0 ^ 6 = 6
count = 3
subarray = [2,2,6]
```

### r = 4

```
curXor = 6 ^ 4 = 2
```

---

## ▶ `l = 2`

`curXor = 0`

### r = 2

```
curXor = 0 ^ 2 = 2
```

### r = 3

```
curXor = 2 ^ 6 = 4
```

### r = 4

```
curXor = 4 ^ 4 = 0
```

No matches.

---

## ▶ `l = 3`

`curXor = 0`

### r = 3

```
curXor = 0 ^ 6 = 6
count = 4
subarray = [6]
```

### r = 4

```
curXor = 6 ^ 4 = 2
```

---

## ▶ `l = 4`

`curXor = 0`

### r = 4

```
curXor = 0 ^ 4 = 4
```

No match.

---

# ⭐ **FINAL COUNT = 4 subarrays**

They are:

1. `[4,2]`
2. `[4,2,2,6,4]`
3. `[2,2,6]`
4. `[6]`

---

# 🎉 Recap of Better Approach

* Fix `l`
* Maintain a running XOR for expanding `r`
* Check if `curXor == K`
* Time: **O(n²)**
* Space: **O(1)**
* Much faster and cleaner than naive O(n³)

---
---
---
---

# 🟩 3. Optimal Approach Using Prefix XOR + Hash Map (Most Important)

This is the real DSA trick.

# 🟩 GOAL:

Count **how many subarrays** have XOR = **K**.

Example:

```
arr = [4, 2, 2, 6, 4]
K = 6
```

---

# 🟦 BEFORE ANYTHING


# ✅ **Goal**

Count number of subarrays whose **XOR = K**

Example base array:
\[
\text{arr} = [4, 2, 2, 6, 4],\quad K = 6
\]

---


# 🔥 **CORE IDEA**

Let:

\[
\text{prefixXor}[i] = arr[0] \oplus arr[1] \oplus \ldots \oplus arr[i]
\]

Now consider a subarray:

\[
arr[l..r]
\]

Its XOR is:

\[
arr[l] \oplus arr[l+1] \oplus \ldots \oplus arr[r]
\]

Using prefix XOR, that equals:

\[
\text{subarrayXor} = prefixXor[r] \oplus prefixXor[l-1]
\]

We want:

\[
prefixXor[r] \oplus prefixXor[l-1] = K
\]

Using XOR reversible property:

\[
prefixXor[l-1] = prefixXor[r] \oplus K
\]





```lua
[4 2 2 6 4]
-------^ = Xor (till six)

let 2 2 6 is hypothethitical imagine is xor = k
and 4 on the beginning is xor = x
and entire thing is xor

now we can say that x ^ k = xor

now take xor k both side => x^k^k = xor ^ k
x = xor ^ k and this is the formula

and now do the dry run
```


# ✅ **📘 YOUR INTUITION (CLEAN + CORRECT NOTES)**

## **Given array**

```
[4, 2, 2, 6, 4]
```

To understand how **prefix XOR** finds a subarray whose XOR = K, imagine this situation:

### ✔ Suppose the subarray `[2, 2, 6]` has XOR = K

(This is TRUE: `2 ^ 2 ^ 6 = 6`)

### ✔ The part BEFORE this subarray is `[4]`

Let the XOR of everything before the subarray be:

```
x = 4
```

### ✔ The XOR from start to the end of the subarray is:

```
xor = 4 ^ 2 ^ 2 ^ 6
```

Which is equal to:

```
xor = x ^ k
```

Because:

```
(entire prefix XOR) = (XOR before subarray) ^ (XOR of subarray)
xor = x ^ k
```

Now isolate `x`:

```
x ^ k = xor
x = xor ^ k
```

### 🎯 **This is the MAIN FORMULA**

> **If prefix XOR until index R is `xor`,
> then the prefix XOR immediately BEFORE the subarray must be:**

\[
x = xor \oplus k
\]

So we look in the hashmap:
“Has a prefix XOR equal to `xor ^ k` appeared before?”

If YES → A valid subarray exists ending at R.

---

# ⭐ PERFECT INTUITION STATEMENT

👉 The whole point is:

> If the XOR from 0 to L-1 is `x`,
> and the XOR from L to R is `k`,
> then the XOR from 0 to R is:
> \[
> x \oplus k
> \]

So if at index R we have:

\[
xor = \text{prefixXOR}[R]
\]

Then the starting boundary L-1 must have prefix XOR:

\[
x = xor \oplus k
\]

So we check if `xor ^ k` already exists in the map.

---

# 🔥 NOW LET’S DRY RUN USING **YOUR LOGIC EXACTLY**

Array:

```
[4, 2, 2, 6, 4]
K = 6
```

Initialize:

```
prefix = 0
map = {0:1}   // empty prefix
count = 0
```

---

# 📌 **i = 0**, value = 4

### 1️⃣ Update prefix:

```
prefix = 0 ^ 4 = 4
```

### 2️⃣ Using your logic:

```
x = prefix ^ K = 4 ^ 6 = 2
```

Question:

> Does previous prefix XOR = 2 exist?

NO → no subarray ends here.

### 3️⃣ Insert prefix 4

```
map = {0:1, 4:1}
```

count = 0

---

# 📌 **i = 1**, value = 2

### 1️⃣ Update prefix:

```
prefix = 4 ^ 2 = 6
```

### 2️⃣ Your logic:

```
x = prefix ^ K = 6 ^ 6 = 0
```

Ask:

> Does prefix XOR = 0 exist?

YES → map[0] = 1

This means:

```
x ^ K = prefix
0 ^ 6 = 6
```

So subarray from 0→1 has XOR = 6:

```
[4, 2]
```

count = 1

### 3️⃣ Insert 6:

```
map = {0:1, 4:1, 6:1}
```

---

# 📌 **i = 2**, value = 2

### 1️⃣ prefix:

```
prefix = 6 ^ 2 = 4
```

### 2️⃣ x = prefix ^ K:

```
4 ^ 6 = 2
```

Does 2 exist before?
NO.

count = 1

### Insert 4:

```
map = {0:1, 4:2, 6:1}
```

---

# 📌 **i = 3**, value = 6

### 1️⃣ prefix:

```
prefix = 4 ^ 6 = 2
```

### 2️⃣ x = prefix ^ K:

```
2 ^ 6 = 4
```

Ask:

> Is 4 present earlier?

YES → map[4] = 2
(meaning prefix 4 occurred twice)

So two subarrays end here:

1. From index 1→3: `[2,2,6]`
2. From index 3 alone? No.
   The second is from index 3→3 only when previous prefix is equal.
   Actually the second comes from prefix at index 2.

So count += 2 → count = 3.

### 3️⃣ Insert prefix 2:

```
map = {0:1, 4:2, 6:1, 2:1}
```

---

# 📌 **i = 4**, value = 4

### 1️⃣ prefix:

```
prefix = 2 ^ 4 = 6
```

### 2️⃣ x:

```
x = prefix ^ K = 6 ^ 6 = 0
```

Prefix 0 exists.

Meaning subarray 0→4 = XOR 6.

count = 4

---

# 🎉 FINAL ANSWER

### ✔ Total subarrays = **4**

They are:

1. `[4, 2]`
2. `[2, 2, 6]`
3. `[6]` (coming from prefix logic)
4. `[4, 2, 2, 6, 4]` whole array

---

# ⭐ PERFECT FINAL INTUITION SUMMARY (YOUR VERSION)

> Think of the prefix before the required subarray as **x**,
> the required subarray XOR as **k**,
> and the complete prefix XOR as **xor**.

\[
x \oplus k = xor
\]

So:

\[
x = xor \oplus k
\]

We search for this `x` in the map.

---

# 🟦 BASE CASES

### ✔ Case 1: If prefixXor itself equals K

Example:

```
[6]  → prefixXor = 6 → directly 1 subarray
```

We count this separately.

### ✔ Case 2: Empty prefix XOR (0)

Before iterating, we do:

```
freq[0] = 1
```

Because:

If `prefixXor[r] == K`,
that means subarray starts from index 0.

### ✔ Case 3: Negative numbers

Still fine (bitwise XOR).

### ✔ Case 4: K = 0

Looking for prefixXor[r] that appeared before → means subarray XOR is 0.

---

# 🔥 BEFORE ANYTHING — FINAL FORMULA WE USE

When we reach index `i`,

\[
\text{prefixXOR}[i] \oplus K = \text{some\ previous\ prefixXOR}
\]

If this matches → we found a valid subarray.

BUT I’ll explain EXACTLY WHAT THIS MEANS using examples.

---

# 🎯 STEP 1 — What is Prefix XOR?

Prefix XOR till index `i` means:

\[
px[i] = arr[0] \oplus arr[1] \oplus ... \oplus arr[i]
\]

Let’s CALCULATE prefix XOR **with full steps**:

| i | arr[i] | prefix XOR calculation | px[i] |
| - | ------ | ---------------------- | ----- |
| 0 | 4      | 4                      | 4     |
| 1 | 2      | 4 ⊕ 2 = 6              | 6     |
| 2 | 2      | 6 ⊕ 2 = 4              | 4     |
| 3 | 6      | 4 ⊕ 6 = 2              | 2     |
| 4 | 4      | 2 ⊕ 4 = 6              | 6     |

So:

\[
px = [4, 6, 4, 2, 6]
\]

---

# 🎯 Let's See Real Subarrays Calculated With This Trick

## Example 1:

`px[3] = 2`,
need `= 2 ⊕ 6 = 4`

Where do we have prefix XOR = 4 ?
→ index 0
→ index 2

Meaning TWO subarrays end at index 3:

### Subarray 1 (l = 1 to r = 3)

\[
[2, 2, 6] \rightarrow 2 \oplus 2 \oplus 6 = 6
\]

### Subarray 2 (l = 3 to r = 3)

\[
[6] \rightarrow 6
\]

BOTH GIVE XOR = 6

---

# 🔥 WHY HASHMAP?

We maintain frequency of prefix XORs:

```
freq[px[i]]
```

Because if `need` occurs `X` times before,
then there are **X subarrays** ending here.

---

# 🚀 FULL OPTIMAL APPROACH CODE (WITH COMMENTS FOR BEGINNERS)

```cpp
int subarrayXor(vector<int>& arr, int k)
{
    unordered_map<int, int> freq;
    int px = 0;
    int count = 0;

    // prefix XOR = 0 occurs once before starting (very important)
    freq[0] = 1;

    for (int x : arr)
    {
        px ^= x; // update prefix xor

        // we want: px ^ k = previousPrefix
        int need = px ^ k;

        // if need exists, add how many times it occurred
        if (freq.count(need))
            count += freq[need];

        // store this prefix xor
        freq[px]++;
    }

    return count;
}
```

---

# 💥 SUPER SMALL TEST TO PROVE EVERYTHING

For arr = [4,2,2,6,4], K = 6
The valid subarrays actually are:

1. `[4, 2]` → 4 ⊕ 2 = 6
2. `[2, 2, 6]`
3. `[6]`
4. `[2, 6, 4]`

Total = **4 subarrays**

The code outputs: **4** ✔️