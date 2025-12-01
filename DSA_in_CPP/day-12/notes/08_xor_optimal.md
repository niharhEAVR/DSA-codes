# ✅ **Optimal Approach 2 — XOR Method (Best for beginners, NO math)**

**This is the real BEST optimal approach — no formulas, no overflow risk.**

### ✔ **Time Complexity:** O(n)

### ✔ **Space Complexity:** O(1)

### ✔ **Very easy logic** (just XOR + bit trick)

---
---

# 🔥 XOR Optimal Approach — Explained Like You Are New to XOR


# 🎯 Step 1: What is XOR?


### **If a number appears twice in XOR, it cancels out.**

Example:

```
5 ^ 7 ^ 5 = (5 ^ 5) ^ 7 = 0 ^ 7 = 7
```

This cancellation property is the key to everything.

---

# 🌟 Step 2: XOR of array and XOR of 1 to n

Let:

```
xor1 = XOR of all array elements
xor2 = XOR of all numbers from 1 to n
```

If array had no errors:

```
xor1 == xor2
```

But because array has:

* x (repeating) → appears twice
* y (missing) → never appears

So XOR logic becomes:

### Real array XOR:

\[
xor1 = 1 \oplus 2 \oplus 3 \oplus ... \oplus x \oplus ... \oplus x \oplus ... \oplus n
\]

### Expected XOR:

\[
xor2 = 1 \oplus 2 \oplus 3 \oplus ... \oplus y \oplus ... \oplus n
\]

Now do:

\[
xor = xor1 \oplus xor2
\]

This cancels out all numbers appearing exactly once.

What remains?

### Only x and y remain:

\[
xor = x \oplus y
\]

This is the first key idea:

# ⭐ Equation (i):

\[
xor = x \oplus y
\]

---

# ❓ But we don't know which is x and which is y

So how do we separate them?

This is the tricky part…
and also the smartest part of the XOR approach.

---

# 🌟 Step 3: Find a bit where x and y are different

In `xor = x ⊕ y`,
if a bit is **1**, it means:

* x has 1
* y has 0

or

* x has 0
* y has 1

This means that this bit can **separate the two numbers**.

We pick the **rightmost set bit** (RSB).

Example:

```
xor = 6  (binary 110)
rightmost set bit = 2 (binary 010)
```

This bit guarantees:

👉 One of (x, y) has this bit **set**
👉 The other has this bit **unset**

So we can divide numbers into TWO groups:

### Group A → bit is 1

### Group B → bit is 0

---

# 🌟 Step 4: Why split into two groups?

Because:

* x goes into ONE group
* y goes into OTHER group

But all other numbers 1 to n appear once and cancel perfectly.

And all numbers in array also enter one of the two groups:

* Numbers that appear twice cancel in their group
* Numbers that appear once cancel across array vs (1..n)

So XOR inside each group leaves **only one number**:

### Group A XOR = either x or y

### Group B XOR = the other one

This gives us the values.

---

# 🎯 Step 5: But which one is repeating and which is missing?

After getting two values:

Let:

```
num1 = value from group A
num2 = value from group B
```

We check the array:

* If num1 appears twice → repeating = num1
* Else → repeating = num2

Then the other one is missing.

---

# 🎉 FINAL INTUITION (VERY SIMPLE SUMMARY)

### 1️⃣ XOR of everything gives:

\[
xor = x ⊕ y
\]

### 2️⃣ Find a bit where x and y differ

Split all numbers in two groups based on that bit.

### 3️⃣ XOR each group

Each group gives one number:

* one contains repeating
* one contains missing

### 4️⃣ Check which appears twice

---

# 🌈 Ultra-simple visual understanding

Think of XOR like this:

* XOR cancels matching pairs
* Whatever is left is the answer

The whole method is about:

* Cancelling everything that should be there
* Leaving only the two wrong numbers
* Separating them using a bit where they differ

---
---


# 🔥 Example

Array size `n = 5`

```
nums = [1, 3, 4, 5, 3]
```

Repeating number = **3**
Missing number = **2**

We will discover these using XOR.

---

# ⭐ STEP 1: XOR of all array elements (xor1)

```
xor1 = 1 ^ 3 ^ 4 ^ 5 ^ 3
```

Let’s compute:

```
1 ^ 3 = 2
2 ^ 4 = 6
6 ^ 5 = 3
3 ^ 3 = 0
```

So:

✔ `xor1 = 0`

---

# ⭐ STEP 2: XOR of numbers from 1 to n (xor2)

```
xor2 = 1 ^ 2 ^ 3 ^ 4 ^ 5
```

Compute:

```
1 ^ 2 = 3
3 ^ 3 = 0
0 ^ 4 = 4
4 ^ 5 = 1
```

So:

✔ `xor2 = 1`

---

# ⭐ STEP 3: XOR them to get “xor = x ⊕ y”

```
xor = xor1 ^ xor2
xor = 0 ^ 1 = 1
```

So:

\[
xor = x ⊕ y = 1
\]

Binary of `1`:

```
0001
```

Meaning:
x and y differ at the **LSB (left most bit)**.

---

# ⭐ STEP 4: Find the left most set bit (rsb)

```
xor = 1 = 0001
left most set bit = 1
```

This bit separates numbers into 2 groups:

* **Group A (bit = 1)**
* **Group B (bit = 0)**

---

# ⭐ STEP 5: Split and XOR numbers according to this bit

We XOR **two things separately**:

* Array elements
* Numbers from 1 to n

## ✔ Group A → numbers with bit 1

Binary check:

* 1 → 0001 → bit 1 → yes
* 3 → 0011 → bit 1 → yes
* 5 → 0101 → bit 1 → yes

Group A numbers from array:

```
1, 3, 5, 3
```

Group A numbers from (1..n):

```
1, 3, 5
```

XOR them all:

```
(1 ^ 3 ^ 5 ^ 3)  ^  (1 ^ 3 ^ 5)
```

Let’s compute slowly:

Array side:

```
1 ^ 3 = 2
2 ^ 5 = 7
7 ^ 3 = 4
```

So arrayGroup = 4

Natural numbers side:

```
1 ^ 3 = 2
2 ^ 5 = 7
```

So naturalGroup = 7

Now XOR the two groups:

```
4 ^ 7 = 3
```

So:

✔ **num1 = 3**

---

## ✔ Group B → numbers with bit 0

Check numbers:

* 2 → 0010 → bit 0 → yes
* 4 → 0100 → bit 0 → yes

Group B from array:

```
4
```

(only 4 has bit zero)

Group B from 1..5:

```
2, 4
```

Now XOR:

```
4  ^  (2 ^ 4)
```

Compute:

```
2 ^ 4 = 6
4 ^ 6 = 2
```

So:

✔ **num2 = 2**

---

# ⭐ STEP 6: Identify repeating vs missing

We have two candidates:

```
num1 = 3
num2 = 2
```

Check which occurs twice in original array `[1,3,4,5,3]`:

* 3 appears twice
* 2 appears 0 times

So:

```
Repeating = 3
Missing   = 2
```

---

# 🎉 FINAL RESULT

| Value | Meaning   |
| ----- | --------- |
| **3** | repeating |
| **2** | missing   |

---

# 🌈 Ultra-Clean Summary (One Page)

1. XOR array and XOR 1..n
2. Combined XOR = x ⊕ y
3. Pick a bit where x and y differ
4. Split numbers into two XOR groups
5. One XOR result gives x, the other gives y
6. Check which appears twice

---
---
---
---

<br>
<br>
<br>

# Code Explanation and Dry run

# Problem / assumptions

You have an array `nums` of size `n` containing numbers from `1` to `n`, except:

* **one number is missing**, and
* **one number repeats** (appears twice).

Goal: return `{missing, repeating}` (your function returns pair and chooses order by checking counts).

---

# High level idea (intuition)

1. If there were no mistakes, XOR of all `nums` and XOR of `1..n` would cancel and give `0`.
2. Because one number is missing (`M`) and one repeats (`R`), the XOR of `nums` with `1..n` equals `M ^ R`. Call this `Xor`.
3. `Xor = M ^ R` is nonzero, so at least one bit is different between `M` and `R`. Find any bit where they differ (a set bit in `Xor`).
4. Use that differing bit to **partition** all numbers into two groups: those with that bit = 1 and those with bit = 0. Do the same partition for `1..n`.
5. Because `M` and `R` differ on that bit, they fall into different groups; XORing each group's members (array elements + 1..n elements) yields one group = either `M` or `R`, and the other group = the other value.
6. Finally, tell which of the two results is the repeating number by counting occurrences in the original array.

This yields O(n) time, O(1) extra space.

---

# Detailed step-by-step with bit visuals

### Step 1 — Find `Xor = XOR(all array elements) ^ XOR(1..n)`

```cpp
int Xor = 0;
for (int i = 0; i < nums.size(); i++) {
    Xor ^= nums[i];
    Xor ^= (i + 1); // because i goes 0..n-1
}
```

Reason: XOR cancels identical numbers. After looping you get `Xor = M ^ R`.

Visual: if `M = 2 (0010)` and `R = 5 (0101)`, then `Xor = 0010 ^ 0101 = 0111`.

---

### Step 2 — Find a set bit in `Xor` (a bit where `M` and `R` differ)

Your loop:

```cpp
int bitNo{};
while (true) {
    if ((Xor & (1 << bitNo)) != 0) break;
    bitNo++;
}
```

This finds the 0-based index of the **first** bit (from LSB) that is 1 in `Xor`.
**Optimization** (common trick): instead of loop, get rightmost set bit directly:

```cpp
int mask = Xor & -Xor; // isolates lowest set bit
```

Then test membership by `(num & mask) != 0`. Using `mask` avoids shifting and indexing and is slightly faster/cleaner.

Why it works: `Xor` has 1s wherever `M` and `R` differ; any 1 bit separates them into different groups.

---

### Step 3 — Partition and XOR within groups

You create two accumulators:

```cpp
int bucketOfOnes = 0, bucketOfZeros = 0;
for (int i = 0; i < nums.size(); i++) {
    if ((nums[i] & (1 << bitNo)) != 0) bucketOfOnes ^= nums[i];
    else bucketOfZeros ^= nums[i];

    if (((i+1) & (1 << bitNo)) != 0) bucketOfOnes ^= (i+1);
    else bucketOfZeros ^= (i+1);
}
```

Because each group XORs all array members and 1..n members that fall into that group, and because all numbers except `M` and `R` appear once in both `nums` and `1..n` and will cancel, you end up with:

* `bucketOfOnes` = either `M` or `R` (whichever has that bit = 1)
* `bucketOfZeros` = the other one

Again, if you used `mask = Xor & -Xor`, replace `(1 << bitNo)` with `mask`.

---

### Step 4 — Determine which is missing and which repeats

You have `a = bucketOfOnes`, `b = bucketOfZeros`. To tell which is repeating, count how many times `a` appears in `nums`. If `count == 2` then `a` is the repeating, else `b` is repeating.

Your code:

```cpp
int cnt{};
for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == bucketOfZeros) cnt++;
}
if (cnt == 2) return {bucketOfZeros, bucketOfOnes};
return {bucketOfOnes, bucketOfZeros};
```

(You counted `bucketOfZeros`. That works — you just check one of them. Make sure the check is consistent with the returned pair order.)

---

# Complexity

* Time: O(n) — one pass to compute XOR, one pass to partition and XOR, one small pass to count.
* Space: O(1) extra.

---

# Dry run (full) on your example `nums = [1, 3, 4, 5, 3]` (n = 5)

**Array**: `1, 3, 4, 5, 3`
**1..n**: `1, 2, 3, 4, 5`

**Step 1: compute Xor**
We XOR array and 1..n interleaved:

Start `Xor = 0`

i=0: `Xor ^= nums[0] (1)` → `Xor = 1`
`Xor ^= (i+1) (1)` → `Xor = 1 ^ 1 = 0`

i=1: `Xor ^= nums[1] (3)` → `Xor = 0 ^ 3 = 3`
`Xor ^= 2` → `Xor = 3 ^ 2 = 1`

i=2: `Xor ^= 4` → `Xor = 1 ^ 4 = 5`
`Xor ^= 3` → `Xor = 5 ^ 3 = 6`

i=3: `Xor ^= 5` → `Xor = 6 ^ 5 = 3`
`Xor ^= 4` → `Xor = 3 ^ 4 = 7`

i=4: `Xor ^= 3` → `Xor = 7 ^ 3 = 4`
`Xor ^= 5` → `Xor = 4 ^ 5 = 1`

Final `Xor = 1`

(This matches the math shortcut: XOR(nums) = 0, XOR(1..5) = 1, so `Xor = 1`.)

Binary: `Xor = 1` → `...0001`

**Step 2: find differing bit**
Your loop checks bits from LSB:

* `bitNo = 0`: `(Xor & (1<<0)) = (1 & 1) = 1` → nonzero → break → `bitNo = 0`.

So the differing bit is bit 0 (LSB).

**Alternative**: `mask = Xor & -Xor = 1 & -1 = 1` (same).

**Step 3: partition and XOR**

Initialize `bucketOfOnes = 0`, `bucketOfZeros = 0`.

We iterate i=0..4 and do for `nums[i]` and `i+1`:

* i=0:

  * `nums[0] = 1`: `(1 & 1) != 0` → `bucketOfOnes ^= 1` → `bucketOfOnes = 1`
  * `i+1 = 1`: `(1 & 1) != 0` → `bucketOfOnes ^= 1` → `bucketOfOnes = 0`

* i=1:

  * `nums[1] = 3` (binary `11`): `(3 & 1) != 0` → `bucketOfOnes ^= 3` → `bucketOfOnes = 3`
  * `i+1 = 2` (binary `10`): `(2 & 1) == 0` → `bucketOfZeros ^= 2` → `bucketOfZeros = 2`

* i=2:

  * `nums[2] = 4` (`100`): `(4 & 1) == 0` → `bucketOfZeros ^= 4` → `bucketOfZeros = 2 ^ 4 = 6`
  * `i+1 = 3`: `(3 & 1) != 0` → `bucketOfOnes ^= 3` → `bucketOfOnes = 3 ^ 3 = 0`

* i=3:

  * `nums[3] = 5` (`101`): `(5 & 1) != 0` → `bucketOfOnes ^= 5` → `bucketOfOnes = 5`
  * `i+1 = 4`: `(4 & 1) == 0` → `bucketOfZeros ^= 4` → `bucketOfZeros = 6 ^ 4 = 2`

* i=4:

  * `nums[4] = 3`: `(3 & 1) != 0` → `bucketOfOnes ^= 3` → `bucketOfOnes = 5 ^ 3 = 6`
  * `i+1 = 5`: `(5 & 1) != 0` → `bucketOfOnes ^= 5` → `bucketOfOnes = 6 ^ 5 = 3`

Final results:

* `bucketOfOnes = 3`
* `bucketOfZeros = 2`

So the two candidates are `3` and `2`. They are `M` and `R` in some order.

**Step 4: figure which is repeating**
Count occurrences in `nums` of one candidate (you counted `bucketOfZeros` in code). Let’s count both for clarity:

* Count of `2` in `nums` = 0
* Count of `3` in `nums` = 2

So `3` is repeating, `2` is missing.

Your code counted `cnt` for `bucketOfZeros` (which is 2) and would see `cnt == 2`? No — count of 2 is 0; so it returns `{bucketOfOnes, bucketOfZeros}` i.e. `{3,2}`. That is `{repeating, missing}` if your intention was `{missing, repeating}` you must be consistent; currently your code returns `{bucketOfOnes,bucketOfZeros}` when `cnt != 2`. That produced `{3,2}` — **which is {repeating, missing}**. If you want to return `{missing, repeating}` change return ordering accordingly.

**Conclusion of dry run:** The algorithm finds `3` and `2`, identifies `3` as repeating and `2` as missing.

---

# Minor code suggestions / polishing

1. **Use mask instead of bitNo loop**:

```cpp
int mask = Xor & -Xor; // isolates lowest set bit
// then use (num & mask) instead of (num & (1 << bitNo))
```

2. **Be careful with return order** — decide whether your function should return `{missing, repeating}` or `{repeating, missing}` and keep the `cnt` check consistent. Example returning `{missing, repeating}`:

```cpp
// after bucketOfOnes and bucketOfZeros computed
int x = bucketOfOnes;
int y = bucketOfZeros;

// check which one is repeating
int cnt = 0;
for (int v : nums) if (v == x) cnt++;

if (cnt == 2) return {y, x}; // x repeated -> return {missing, repeating}
else return {x, y};
```

3. **Edge-safety**: if `n` could be > 31 and you use `1<<bitNo` with `int`, consider using `1LL << bitNo` or `unsigned` types.

---

# Short recap

* `Xor` gives `M ^ R`.
* Pick any set bit of `Xor` (e.g. `mask = Xor & -Xor`).
* Partition numbers using that mask and XOR within groups → get `M` and `R`.
* Count one candidate to decide which is repeating.

---

If you want I can:

* convert your function to a cleaned, final version that **returns `{missing, repeating}`** and uses `mask` optimization,
* or run another dry run on a different example (e.g., where `Xor = 4`) and show the same bit-by-bit visuals.

Which would you like?
