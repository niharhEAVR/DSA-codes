Let's analyze the **time complexity** of the given `func` function step by step.

---

### **Code Analysis**
```c
void func(int n)
{
    int sum = 0;         // Constant time operation O(1)
    int product = 1;     // Constant time operation O(1)

    for (int i = 0; i < n; i++) // Outer loop
    {
        for (int j = 0; j < n; j++) // Inner loop
        {
            printf("%d , %d\n", i, j); // Constant time operation O(1)
        }
    }
}
```

---

### **Step-by-Step Analysis**

#### **1. Outer Loop**
```c
for (int i = 0; i < n; i++)
```
- The outer loop runs from \( i = 0 \) to \( i = n - 1 \).
- Total number of iterations: \( n \).

---

#### **2. Inner Loop**
```c
for (int j = 0; j < n; j++)
```
- For each iteration of the outer loop, the inner loop runs from \( j = 0 \) to \( j = n - 1 \).
- Total number of iterations for the inner loop: \( n \).

---

#### **3. Nested Loops**
- The inner loop executes \( n \) times for each of the \( n \) iterations of the outer loop.
- Total number of iterations of the nested loops: \( n \times n = n^2 \).
- In each iteration, the `printf` statement is executed, which is a constant-time operation (\( O(1) \)).

---

### **4. Other Operations**
- The assignments for `sum` and `product` are constant-time operations (\( O(1) \)).
- These operations do not depend on \( n \) and are insignificant compared to the nested loops.

---

### **Time Complexity**
- The nested loops dominate the time complexity.
- The total time complexity is:
  \[
  O(n^2)
  \]

---

### **Final Answer**
The **time complexity** of the `func` function is:
\[
O(n^2)
\]

---

### **Explanation in Simple Terms**
- The function has two loops: the outer loop runs \( n \) times, and for each iteration of the outer loop, the inner loop also runs \( n \) times.
- This results in a total of \( n \times n = n^2 \) iterations.
- Each iteration performs a constant-time operation (printing), so the overall complexity is \( O(n^2) \).