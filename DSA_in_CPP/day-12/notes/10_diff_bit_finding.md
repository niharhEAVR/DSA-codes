# ⭐ **Given:**

```
Xor = 4
```

In binary:

```
4 = 0100   (in 0-indexed bits: bit 2 is set)
```

You want to understand how this loop finds **bitNo = 2**.

Let’s do it **super visual**, step-by-step.

---

# ✅ Code you gave

```cpp
int bitNo{};
while(true){
    if((Xor & (1<<bitNo)) != 0){
        break;
    }
    bitNo++;
}
```

This finds **the first (rightmost) set bit** in `Xor`.

---

# 📌 First convert to binary

Let:

```
Xor = 4 = 0100
```

Bit positions (0-index):

```
bit2 bit1 bit0
  1    0    0
```

So the rightmost set bit is at **bit 2**.

---

# ⭐ Now we visualize the loop

---

# 🔵 **Iteration 1**

### bitNo = 0

Compute:

```
(1 << bitNo) = (1 << 0) = 1
```

Binary:

```
Xor = 0100
1<<0= 0001
--------------
AND = 0000
```

→ Result = 0 → not set → continue

`bitNo++ → bitNo = 1`

---

# 🔵 **Iteration 2**

### bitNo = 1

Compute:

```
(1 << 1) = 2
```

Binary:

```
Xor = 0100
1<<1= 0010
--------------
AND = 0000
```

→ still 0 → continue

`bitNo++ → bitNo = 2`

---

# 🔵 **Iteration 3**

### bitNo = 2

Compute:

```
(1 << 2) = 4
```

Binary:

```
Xor = 0100
1<<2= 0100
--------------
AND = 0100   (non-zero)
```

This time result ≠ 0
So the loop breaks.

```
break;
```

Final:

```
bitNo = 2
```

---

# 🎉 Output meaning:

The **first bit** (from LSB side) where Xor has 1 is **bit 2**.

This matches:

```
4 = 0100
       ↑ bit 2
```

---

# 🎯 Final Answer:

### ✔️ Your loop stops at `bitNo = 2`

because that is exactly where **Xor has its first 1-bit**.

---

# 💡 Why this works

* `1 << bitNo` creates masks like:

```
0001  (bit 0)
0010  (bit 1)
0100  (bit 2)
1000  (bit 3)
```

* When the mask’s bit matches the set bit in Xor → AND becomes non-zero.