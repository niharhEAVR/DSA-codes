# ✅ First — what your method does

You wrote:

```cpp
int bitNo = 0;
while(true){
    if (Xor & (1 << bitNo)) break;
    bitNo++;
}
```

This keeps shifting:

* `1 << 0` → 0001
* `1 << 1` → 0010
* `1 << 2` → 0100
* …

You’re searching for **the first (rightmost) bit where Xor has 1**.

This works perfectly.

---

# 🟦 Now — What is “mask = Xor & -Xor” ?

This expression:

```cpp
int mask = Xor & -Xor;
```

is a famous bit manipulation trick that directly extracts the **lowest (rightmost) set bit** from a number.

Example:

```
Xor = 12 = 1100
```

Then:

```
mask = Xor & -Xor
```

Let’s decode it.

---

# 🧠 Key idea: Two’s Complement

`-Xor` = two’s complement:

```
-Xor = (~Xor + 1)
```

For any number:

* it flips all bits
* then adds 1
* the effect makes only the *lowest set bit* remain common between `Xor` and `-Xor`

---

# ⭐ Example 1: Xor = 12 (binary 1100)

### Step 1 — Write Xor

```
Xor = 1100
```

### Step 2 — Compute -Xor (two’s complement)

Invert bits:

```
~Xor = 0011
```

Add 1:

```
0011 + 0001 = 0100
```

So:

```
-Xor = 0100
```

### Step 3 — AND them:

```
    1100   (Xor)
AND 0100   (-Xor)
----------------
    0100   (mask)
```

**mask = 4**

That’s the lowest set bit.

---

# ⭐ Example 2: Xor = 1 (binary 0001)

```
Xor = 0001
-Xor = 1111 + 1 = 0001
mask = 0001 & 0001 = 0001
```

(mask = 1)

---

# ⭐ Example 3: Xor = 10 (binary 1010)

```
 Xor  = 1010
-Xor:
   ~  = 0101
  +1  = 0110

mask = 1010 & 0110 = 0010
```

(mask = 2)

---

# 💡 Why this works

Because in two’s complement, `-Xor` always has **all 0s below the lowest set bit and flips after it**, so only that one bit survives the AND.

This gives you the rightmost set bit instantly.

---

# 🔥 Why mask is better than your bitNo method?

### ✔ 1. No loop

Your method searches bit by bit:

```
0th bit
1st bit
2nd bit
3rd bit
...
```

Worst case: up to 31 or 63 iterations.

`mask = Xor & -Xor` takes **O(1)** time.

---

### ✔ 2. No shifting

With your method you compute:

```
1 << bitNo
```

Multiple times.

Mask avoids all of that.

---

### ✔ 3. More readable in bit manipulation circles

Every competitive programmer, DSA interview, and codebase recognizes:

```
mask = Xor & -Xor;
```

as “extract lowest set bit”.

---

### ✔ 4. Fewer bugs

No worry about:

* overflowing when `bitNo` becomes large
* using `1 << bitNo` on `int`
* infinite loops
* manual counting

Mask is clean and safe.

---

# 🟩 Your method vs Mask — Visual Comparison

Assume:

```
Xor = 20 = 10100
```

### Your loop:

```
bitNo = 0 --> 1<<0 = 00001 (AND gives 0)
bitNo = 1 --> 1<<1 = 00010 (AND gives 0)
bitNo = 2 --> 1<<2 = 00100 (AND gives NONZERO) ✔
```

Found rightmost bit = 2.

---

### mask:

```
-Xor = ~10100 + 1 = 01011 + 1 = 01100
mask = 10100 & 01100 = 00100
```

In one step.

---

# 🏁 Final: Using mask in your code

Instead of finding:

```cpp
int bitNo = 0;
while (!(Xor & (1 << bitNo))) bitNo++;
```

Use:

```cpp
int mask = Xor & -Xor;
```

Then replace:

```
(nums[i] & (1 << bitNo))
```

with:

```
(nums[i] & mask)
```

Same logic, shorter, cleaner, faster.
