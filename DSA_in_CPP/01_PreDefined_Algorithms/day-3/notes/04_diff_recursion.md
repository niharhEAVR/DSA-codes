## 🧠 The Problem:

“Find the **sum of first N natural numbers** using recursion.”

That means:

```
sum(3) = 3 + 2 + 1 = 6
```

We can solve this in **two recursive styles**:

1. **Parameterized Recursion**
2. **Functional Recursion**

---

## 🧩 1️⃣ Parameterized Recursion (uses a *parameter* to carry the result)

In **parameterized recursion**, we pass a variable (parameter) that keeps track of some accumulated result as the recursion goes deeper.

Think of it like — “I keep passing the *partial sum* down into the next call.”

### Example:

```cpp
#include <iostream>
using namespace std;

void sumParameterized(int n, int sum) {
    if (n == 0) {
        cout << "Final Sum: " << sum << endl;
        return;
    }
    sumParameterized(n - 1, sum + n); // pass accumulated sum
}

int main() {
    sumParameterized(3, 0);
    return 0;
}
```

### Step-by-step (trace):

| Call                   | n           | sum      |
| ---------------------- | ----------- | -------- |
| sumParameterized(3, 0) | → next call | sum = 3  |
| sumParameterized(2, 3) | → next call | sum = 5  |
| sumParameterized(1, 5) | → next call | sum = 6  |
| sumParameterized(0, 6) | base case   | prints 6 |

✅ **Output:**

```
Final Sum: 6
```

### 🔍 Key idea:

* The function **does not return anything**, but **keeps updating the result via parameters**.
* The **result travels through parameters** during recursive calls.

---

## 🧮 2️⃣ Functional Recursion (returns the result directly)

In **functional recursion**, each function call **returns** a value to its caller.
Here, we don’t pass the accumulated sum — instead, we let recursion build and return it.

### Example:

```cpp
#include <iostream>
using namespace std;

int sumFunctional(int n) {
    if (n == 0)
        return 0;   // base case
    return n + sumFunctional(n - 1); // combine current + result of smaller problem
}

int main() {
    cout << "Final Sum: " << sumFunctional(3) << endl;
    return 0;
}
```

### Step-by-step (trace):

| Call                                    | Expression |
| --------------------------------------- | ---------- |
| sumFunctional(3) = 3 + sumFunctional(2) |            |
| sumFunctional(2) = 2 + sumFunctional(1) |            |
| sumFunctional(1) = 1 + sumFunctional(0) |            |
| sumFunctional(0) = 0                    |            |
| Return values → 1 + 2 + 3 = 6           |            |

✅ **Output:**

```
Final Sum: 6
```

---

## ⚖️ Comparison Table

| Feature                          | Parameterized Recursion                       | Functional Recursion   |
| -------------------------------- | --------------------------------------------- | ---------------------- |
| **Returns value?**               | ❌ No (void)                                   | ✅ Yes                  |
| **Carries result as parameter?** | ✅ Yes                                         | ❌ No                   |
| **When is the result known?**    | During the call (parameter updated each step) | After all calls return |
| **Example idea**                 | Passing partial sum                           | Returning sub-sums     |

---

## 🧠 Summary

| Style             | Code Idea                   | Example                         |
| ----------------- | --------------------------- | ------------------------------- |
| **Parameterized** | Pass the sum as an argument | `sumParameterized(n-1, sum+n)`  |
| **Functional**    | Return `n + f(n-1)`         | `return n + sumFunctional(n-1)` |

---

So, in short:

> 🗣️ **Parameterized recursion** carries the result *down* through parameters.
> 🗣️ **Functional recursion** builds the result *up* through return values.
