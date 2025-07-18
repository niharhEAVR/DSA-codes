To calculate the **time complexity** of an algorithm, you analyze the number of operations or steps the algorithm performs as a function of the input size \( n \). Below are the **basic rules** and steps to calculate time complexity.

---

### **1. Understand the Algorithm**
- Break the algorithm into parts (loops, conditions, and function calls).
- Identify the input size \( n \), which usually represents the number of elements in the input (e.g., size of an array).

---

### **2. Count the Dominant Operations**
Focus on the number of **basic operations** (like comparisons, additions, assignments) that grow with the input size \( n \). Ignore constants and lower-order terms.

---

### **3. Basic Rules for Different Constructs**

#### **(a) Loops**
- A loop running \( n \) times contributes \( O(n) \).
- Nested loops multiply their complexities:
  - Example: Two nested loops, each running \( n \) times → \( O(n \times n) = O(n^2) \).

#### **(b) Conditional Statements**
- For `if-else` blocks, take the time complexity of the **heavier branch** (the one with more operations).
  - Example:
    ```python
    if condition:
        do_something()  # O(n)
    else:
        do_something_else()  # O(1)
    ```
    Time complexity: \( O(n) \) (from the heavier branch).

#### **(c) Function Calls**
- If a function is called inside a loop, multiply the complexity of the function by the number of loop iterations.
  - Example:
    ```python
    for i in range(n):  # O(n)
        some_function()  # O(log n)
    ```
    Total time complexity: \( O(n \times \log n) \).

#### **(d) Recursion**
- Recursion complexity depends on:
  - The **number of recursive calls**.
  - The **work done in each call**.
- Use the **recurrence relation** to solve:
  - Example: \( T(n) = T(n/2) + O(1) \) → \( O(\log n) \).

---

### **4. Drop Constants and Lower-Order Terms**
- In asymptotic analysis, constants and smaller terms are ignored.
- Example:
  - \( f(n) = 3n^2 + 5n + 10 \)
  - Dominant term: \( 3n^2 \).
  - Time complexity: \( O(n^2) \).

---

### **5. Combine Complexities**
- If an algorithm has multiple independent parts, add their complexities.
  - Example:
    ```python
    for i in range(n):  # O(n)
        do_something()

    for j in range(n):  # O(n)
        do_something_else()
    ```
    Total time complexity: \( O(n) + O(n) = O(n) \).

- If parts are dependent (e.g., nested loops), multiply their complexities.

---

### **6. Common Time Complexities**
Here are some common time complexities and their meanings:

| **Complexity** | **Name**           | **Example**                               |
|----------------|--------------------|-------------------------------------------|
| \( O(1) \)     | Constant Time      | Accessing an array element by index.      |
| \( O(\log n) \)| Logarithmic Time   | Binary search.                            |
| \( O(n) \)     | Linear Time        | Iterating through an array.               |
| \( O(n \log n) \)| Linearithmic Time| Merge sort, Quick sort (average case).    |
| \( O(n^2) \)   | Quadratic Time     | Nested loops for an \( n \times n \) grid.|
| \( O(2^n) \)   | Exponential Time   | Solving the Tower of Hanoi.               |

---

### **7. Examples**

#### **Example 1: Simple Loop**
```python
for i in range(n):
    print(i)
```
- The loop runs \( n \) times → \( O(n) \).

---

#### **Example 2: Nested Loops**
```python
for i in range(n):
    for j in range(n):
        print(i, j)
```
- Outer loop: \( O(n) \).
- Inner loop: \( O(n) \).
- Total: \( O(n \times n) = O(n^2) \).

---

#### **Example 3: Recursion**
```python
def fibonacci(n):
    if n <= 1:
        return n
    return fibonacci(n-1) + fibonacci(n-2)
```
- Recurrence relation: \( T(n) = T(n-1) + T(n-2) + O(1) \).
- Time complexity: \( O(2^n) \) (exponential).

---

### **8. General Tips**
- Focus on **dominant operations** and **input size**.
- Ignore constants and smaller terms.
- Simplify the analysis for large \( n \) (asymptotic behavior).

By following these rules, you can calculate the time complexity of most algorithms!