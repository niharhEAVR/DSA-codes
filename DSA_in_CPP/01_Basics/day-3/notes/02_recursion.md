### 🌀 **What is Recursion?**

**Recursion** means **a function calling itself** to solve a smaller part of the same problem.

👉 In simple terms:

> Recursion is when a function keeps calling itself until it reaches a certain condition (called the *base case*).

---

### ⚙️ **How It Works (Simple Example)**

Example:
Let’s find the factorial of a number `n! = n × (n-1) × (n-2) × … × 1`

```cpp
int factorial(int n) {
    if (n == 1)       // Base Case
        return 1;
    else
        return n * factorial(n - 1);  // Recursive Call
}
```

**Call flow when you do `factorial(4)`**

| Function Call | What Happens              |
| ------------- | ------------------------- |
| factorial(4)  | 4 × factorial(3)          |
| factorial(3)  | 3 × factorial(2)          |
| factorial(2)  | 2 × factorial(1)          |
| factorial(1)  | returns 1 (Base case hit) |
| Backtracking  | 2×1 → 3×2 → 4×6 = 24      |

✅ Final result = **24**

---

### 🧩 **What is Base Case?**

The **base case** is the **condition that stops recursion**.
Without it, the function would keep calling itself forever.

👉 It’s like the “exit door” of recursion.

In the factorial example:

```cpp
if (n == 1)
    return 1;
```

This is the **base case**, because it stops calling further.

---

### 💣 **What is Stack Overflow?**

Every time a function is called, its variables and data are stored in **the call stack (a special memory area)**.

When recursion happens:

* Each function call waits for the next one to finish.
* If there’s **no base case**, or it’s incorrect → infinite calls happen.
* The stack becomes **too full**, and the program **crashes**.

This crash is called a **Stack Overflow**.

---

### ⚠️ **Example of Stack Overflow**

```cpp
void printHello() {
    cout << "Hello\n";
    printHello();  // no base case ❌
}
```

🧠 What happens:

* `printHello()` calls itself again and again
* Stack keeps storing each unfinished call
* Memory fills up → **Stack Overflow Error**

---

### 🧠 Summary

| Term               | Meaning                                    | Example                                 |
| ------------------ | ------------------------------------------ | --------------------------------------- |
| **Recursion**      | Function calling itself                    | `factorial(n)` calling `factorial(n-1)` |
| **Base Case**      | Condition that stops recursion             | `if (n == 1) return 1;`                 |
| **Stack Overflow** | Too many recursive calls filling up memory | Infinite recursion without base case    |
