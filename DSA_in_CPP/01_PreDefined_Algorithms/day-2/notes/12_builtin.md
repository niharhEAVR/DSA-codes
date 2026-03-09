## 🧩 1. What are `__builtin_()` Functions?


In C++ (specifically GCC and Clang compilers),
`__builtin_` functions are **compiler-provided functions** that perform **low-level, highly optimized operations**.

They are not part of the C++ standard library —
they are **built directly into the compiler** (that’s why “builtin”).

---

### ✅ Think of them as:

> “Special fast versions of common operations that the compiler can execute more efficiently.”

---

## ⚙️ 2. Why Use `__builtin_` Functions?

Because:

* They are **extremely fast** (often compiled into **a single CPU instruction** ⚡).
* You don’t have to manually write loops for counting bits or checking powers.
* They are **compiler intrinsics** (the compiler directly replaces them with efficient machine code).

---

## 🧠 3. Commonly Used `__builtin_` Functions

Let’s go through the most important ones 👇

---

### 🔹 a) `__builtin_popcount(x)`

Counts the **number of 1-bits** (set bits) in the integer `x`.

#### Example:

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 13;  // binary: 1101 (3 ones)
    cout << __builtin_popcount(x);  
}
```

**Output:**

```
3
```

👉 It’s equivalent to counting how many bits are `1` in the binary representation.

---

### 🔹 b) `__builtin_clz(x)`

Counts **leading zeros** in the binary form of an integer.

> "How many zeros are there before the first 1-bit from the left?"

#### Example:

```cpp
#include <iostream>
using namespace std;

int main() {
    unsigned int x = 16;  // binary: 00000000...010000
    cout << __builtin_clz(x);
}
```

**Output (for 32-bit int):**

```
27
```

💡 Because 16 = `00000000000000000000000000010000` → 27 zeros before first 1.

---

### 🔹 c) `__builtin_ctz(x)`

Counts **trailing zeros** — how many zeros are after the last 1-bit (from the right).

#### Example:

```cpp
#include <iostream>
using namespace std;

int main() {
    unsigned int x = 40; // binary: 101000
    cout << __builtin_ctz(x);
}
```

**Output:**

```
3
```

(There are 3 zeros at the end of 101000.)

---

### 🔹 d) `__builtin_parity(x)`

Returns whether the number of set bits (1s) is **even or odd**.

#### Example:

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 7; // binary: 111 (3 ones)
    cout << __builtin_parity(x);
}
```

**Output:**

```
1
```

👉 Because number of 1s is odd (3).

---

### 🔹 e) `__builtin_popcountll(x)`

Same as `__builtin_popcount()` but for **long long int (64-bit)** numbers.

#### Example:

```cpp
long long x = 123456789123456789;
cout << __builtin_popcountll(x);
```

---

### 🔹 f) `__builtin_clzll(x)` and `__builtin_ctzll(x)`

Same as above but for **long long** types (64-bit integers).

---

## 🧮 4. Time Complexity

All these functions are **O(1)** —
✅ They execute in **constant time**, because they’re compiled directly to a single CPU instruction.

---

## 🧾 5. Example — Using All Together

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 40; // binary: 101000

    cout << "Number of set bits: " << __builtin_popcount(n) << endl;
    cout << "Leading zeros: " << __builtin_clz(n) << endl;
    cout << "Trailing zeros: " << __builtin_ctz(n) << endl;
    cout << "Parity (0-even,1-odd): " << __builtin_parity(n) << endl;
}
```

**Output (for 32-bit int):**

```
Number of set bits: 2
Leading zeros: 26
Trailing zeros: 3
Parity (0-even,1-odd): 0
```

---

## 🧩 6. Properties and Notes

| Function                  | Meaning                 | Works On     | Time Complexity |
| ------------------------- | ----------------------- | ------------ | --------------- |
| `__builtin_popcount(x)`   | Counts 1s               | int          | O(1)            |
| `__builtin_popcountll(x)` | Counts 1s               | long long    | O(1)            |
| `__builtin_clz(x)`        | Leading zeros           | unsigned int | O(1)            |
| `__builtin_ctz(x)`        | Trailing zeros          | unsigned int | O(1)            |
| `__builtin_parity(x)`     | Odd or even count of 1s | int          | O(1)            |
| `__builtin_clzll(x)`      | Leading zeros           | long long    | O(1)            |
| `__builtin_ctzll(x)`      | Trailing zeros          | long long    | O(1)            |

---

## 🧠 7. Important Notes

⚠️ **1. Undefined for 0**
If you use `__builtin_clz(0)` or `__builtin_ctz(0)`, it’s **undefined behavior**, because there is **no 1-bit** in 0.

⚠️ **2. GCC/Clang only**
These functions are supported by **GCC** and **Clang compilers**, not guaranteed in MSVC (Windows Visual Studio).

⚡ **3. Used in Competitive Programming**
They’re extremely common in competitive coding for **bit manipulation**, **masking**, and **optimization**.

---

## 🎯 8. Real-Life Uses

* Count bits quickly for bitmask problems.
* Find position of first or last set bit.
* Optimize math-heavy or low-level algorithms.
* Check parity of numbers (even or odd number of 1s).