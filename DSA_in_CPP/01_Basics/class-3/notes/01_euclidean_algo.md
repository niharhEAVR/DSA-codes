## 🧩 1. What is the Euclidean Algorithm?

The **Euclidean Algorithm** is a method to find the
👉 **GCD (Greatest Common Divisor)** of two numbers.

> **GCD (a, b)** is the largest number that divides both `a` and `b` without leaving a remainder.

---

## 💡 2. Main Logic / Core Idea

The main principle:

> **GCD(a, b) = GCD(b, a % b)**
> (where `%` means remainder)

We repeat this process until one number becomes 0.

Then:

> **GCD(a, b) = a**, if **b = 0**

---

### 🔹 Why It Works

If a number `d` divides both `a` and `b`,
it also divides their **difference** → `a - b`.

That’s the logic behind:

```
GCD(a, b) = GCD(b, a % b)
```

Because `a % b` is basically `a - b * floor(a/b)` —
and the remainder keeps getting smaller each step.

---

## ⚙️ 3. Step-by-Step Example

Let’s find **GCD(48, 18)**

| Step | a  | b  | a % b | New Pair (a,b) |
| ---- | -- | -- | ----- | -------------- |
| 1    | 48 | 18 | 12    | (18, 12)       |
| 2    | 18 | 12 | 6     | (12, 6)        |
| 3    | 12 | 6  | 0     | (6, 0)         |

When `b` becomes `0`, **GCD = a = 6**

✅ **Answer: GCD(48, 18) = 6**

---

## 🧾 4. C++ Code (Iterative)

```cpp
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a = 48, b = 18;
    cout << "GCD is: " << gcd(a, b);
}
```

**Output:**

```
GCD is: 6
```

---

## 🧾 5. Recursive Version (Shorter and Cleaner)

```cpp
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
```

👉 **Logic:**
Every recursive call reduces one step of the table until remainder is 0.

---

## ⚡ 6. Time Complexity

| Step              | Operation                                      |
| ----------------- | ---------------------------------------------- |
| Each step         | `a % b` → remainder gets smaller fast          |
| Worst Case        | When numbers are consecutive Fibonacci numbers |
| Time Complexity   | **O(log(min(a, b)))**                          |
| Space (recursive) | **O(log(min(a, b)))**                          |

✅ So, it’s **very efficient** — even for large numbers.

---

## 🧮 7. Extended Euclidean Algorithm (Bonus)

It not only finds GCD but also finds integers `x` and `y` such that:

```
a*x + b*y = gcd(a, b)
```

This is used in:

* Modular inverse
* Cryptography (RSA, etc.)
* Diophantine equations

(You can ask me later for a visual explanation of this too if you want.)

---

## 🧷 8. Properties of GCD

| Property                       | Example               |   |   |   |                     |
| ------------------------------ | --------------------- | - | - | - | ------------------- |
| GCD(a, 0) = a                  | GCD(5, 0) = 5         |   |   |   |                     |
| GCD(a, b) = GCD(b, a % b)      | GCD(48,18)=GCD(18,12) |   |   |   |                     |
| GCD(a, b) = GCD(               | a                     | , | b | ) | sign doesn’t matter |
| If a divides b → GCD(a, b) = a | GCD(4, 12) = 4        |   |   |   |                     |

---

## 🧭 9. Built-in C++ Function

C++ STL provides it directly (since C++17):

```cpp
#include <iostream>
#include <numeric> // for std::gcd
using namespace std;

int main() {
    int a = 48, b = 18;
    cout << gcd(a, b); // uses Euclidean algorithm internally
}
```

---

## 🧠 Summary Table

| Concept         | Meaning                                    |
| --------------- | ------------------------------------------ |
| Purpose         | Find Greatest Common Divisor (GCD)         |
| Formula         | GCD(a, b) = GCD(b, a % b)                  |
| Base Case       | if (b == 0) return a                       |
| Time Complexity | O(log(min(a, b)))                          |
| Used In         | Fractions, LCM, modular math, cryptography |

---

## ⚙️ 10. Example: GCD + LCM Relation

```cpp
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    cout << "GCD: " << gcd(15, 20) << endl;
    cout << "LCM: " << lcm(15, 20) << endl;
}
```

**Output:**

```
GCD: 5
LCM: 60
```

✅ Relation:

> **LCM × GCD = a × b**
