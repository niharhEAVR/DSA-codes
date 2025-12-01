# ✅ **What is Bit Manipulation?**

Bit manipulation = **working directly with bits** (0s and 1s).

Every number in your computer is stored as bits.

For example:

```
5  ->  0101
7  ->  0111
```

We use **bitwise operators** to change, check, or compare bits:

* AND (`&`)
* OR (`|`)
* XOR (`^`)
* NOT (`~`)
* Left shift (`<<`)
* Right shift (`>>`)

---

# ⭐ **Statement:**

### **“If two numbers are different, then they MUST differ in at least one bit.”**

This means:

> If A ≠ B, then their binary forms WILL NOT be 100% identical.
> At least one position will have a different value (0 vs 1).

If all bits were same → numbers would be same.

Let’s visualize.

---

# 🔍 **Example 1: 5 vs 7**

Binary:

```
5 : 0101
7 : 0111
```

Compare bit-by-bit:

```
0 1 0 1
0 1 1 1
    ↑ difference here (0 vs 1)
```

There are **bits different**, so the numbers are different.

---

# 🔍 **Example 2: 10 vs 8**

Binary:

```
10 : 1010
 8 : 1000
```

Compare:

```
1 0 1 0
1 0 0 0
    ↑ difference (0 vs 1)
```

Again, they differ → so numbers are not equal.

---

# 🔍 **Example 3: Numbers differing by exactly ONE bit**

### 4 and 5

```
4 -> 0100
5 -> 0101
```

Compare:

```
0100
0101
   ↑ ONLY ONE BIT different
```

So, 4 and 5 differ by exactly one bit.

This is the smallest possible difference in bits.

---

# 🧠 **Why MUST there be a different bit?**

Imagine two numbers are truly different:

```
A = 13
B = 9
```

This means:

```
A - B ≠ 0
```

Numbers are represented by bitstrings.

If every bit was exactly same:

```
A_bits == B_bits
```

then

```
A == B   (since binary is identical)
```

Which is impossible because A ≠ B.

Therefore, **the only way two numbers differ is because at least one BIT is different**.

---

# 🎯 **Perfect Visualization Trick**

Think of a number as a row of light bulbs:

```
10 -> 1010
```

If you compare two rows, and every bulb is the same ON/OFF pattern → numbers are same.

If even ONE bulb differs → numbers are different.

---

# 💡 **Connection With XOR**

XOR (`^`) outputs **1** when bits are different.

Example:

```
5 ^ 7

0101
0111
----
0010   (XOR result)
```

The XOR result **marks exactly where bits differ**.

If A ≠ B → XOR result ≠ 0
If A == B → XOR result = 0

---

# 🧪 **Quick Test (Try yourself)**

Are these numbers different in at least one bit?

1. 6 (110)
   3 (011)

Compare:

```
1 1 0
0 1 1
↑   ↑ bits differ
```

Yes → different.

2. 9 (1001)
   9 (1001)

All bits same → numbers identical.