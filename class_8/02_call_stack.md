The **function call stack** is a mechanism in programming that keeps track of function calls and returns. Each function call is pushed onto the stack, and when the function completes, it is popped from the stack. Here's how the function call stack works in your program:

---

### Code Execution Flow

1. **`main` function starts execution:**
   - The program begins with the `main` function.
   - It prompts the user to input values for `n` and `r`.

2. **User inputs `n` and `r`:**
   - Let's say the user enters `n = 5` and `r = 2`.

3. **`nCr` function is called:**
   - `nCr(5, 2)` is invoked.
   - The function calculates the numerator by calling `factorial(5)`.
     - At this point, the stack looks like this:
       ```
       main -> nCr(5,2) -> factorial(5)
       ```

---

### `factorial(5)` Execution:
   - **Step 1:** `factorial(5)` starts execution.
   - **Step 2:** A loop runs from 1 to 5, computing \( 5! = 1 \times 2 \times 3 \times 4 \times 5 = 120 \).
   - **Step 3:** Once completed, `factorial(5)` returns 120 to `nCr(5, 2)` and is removed from the stack.
     - The stack after returning:
       ```
       main -> nCr(5,2)
       ```

---

### `factorial(2)` Execution:
   - The `factorial` function is called again to compute `factorial(2)` for the denominator.
   - Stack now:
     ```
     main -> nCr(5,2) -> factorial(2)
     ```
   - A loop computes \( 2! = 1 \times 2 = 2 \).
   - Once done, it returns 2 to `nCr(5, 2)` and is removed from the stack.

---

### `factorial(3)` Execution:
   - Finally, `factorial(3)` is called to compute `factorial(n - r)` where \( n - r = 3 \).
   - Stack now:
     ```
     main -> nCr(5,2) -> factorial(3)
     ```
   - A loop computes \( 3! = 1 \times 2 \times 3 = 6 \).
   - Once done, it returns 6 to `nCr(5, 2)` and is removed from the stack.

---

### Back in `nCr` Function:
   - Now, `nCr(5, 2)` has:
     - `numerator = 120`
     - `denominator = 2 \times 6 = 12`
   - It computes the result as \( \frac{120}{12} = 10 \).
   - The result is returned to the `main` function, and `nCr(5, 2)` is removed from the stack.

---

### Back in `main` Function:
   - The `main` function receives the result `10` and prints:
     ```
     The answer is: 10
     ```

---

### Visualizing the Stack at Key Points:
1. Before calling `nCr(5, 2)`:
   ```
   main
   ```

2. While inside `nCr(5, 2)` and calling `factorial(5)`:
   ```
   main -> nCr(5, 2) -> factorial(5)
   ```

3. While inside `nCr(5, 2)` and calling `factorial(2)`:
   ```
   main -> nCr(5, 2) -> factorial(2)
   ```

4. After all `factorial` calls return and `nCr(5, 2)` completes:
   ```
   main
   ```

5. When the program exits:
   - Stack is empty.

---

### Key Takeaways:
1. **Stack grows and shrinks dynamically:** Each function call adds to the stack, and when the function completes, it is removed.
2. **Independent execution of each call:** Each `factorial` function runs independently with its own variables.
3. **Order of operations:** The stack ensures that the program executes functions in the correct order, handling nested calls properly.


---
---

Here’s a visual representation of the function call stack during the execution of your program. Let's assume the inputs are \( n = 5 \) and \( r = 2 \).

---

### Step 1: Start of `main` Function

Stack:
```
| main |  <-- Currently running
```

---

### Step 2: Calling `nCr(5, 2)`

Stack:
```
| nCr(5, 2) |  <-- Currently running
| main      |
```

---

### Step 3: Inside `nCr(5, 2)` → Calling `factorial(5)`

Stack:
```
| factorial(5) |  <-- Currently running
| nCr(5, 2)    |
| main         |
```

---

### Step 4: `factorial(5)` Completes and Returns 120

Stack:
```
| nCr(5, 2) |  <-- Currently running
| main      |
```

---

### Step 5: Inside `nCr(5, 2)` → Calling `factorial(2)`

Stack:
```
| factorial(2) |  <-- Currently running
| nCr(5, 2)    |
| main         |
```

---

### Step 6: `factorial(2)` Completes and Returns 2

Stack:
```
| nCr(5, 2) |  <-- Currently running
| main      |
```

---

### Step 7: Inside `nCr(5, 2)` → Calling `factorial(3)`

Stack:
```
| factorial(3) |  <-- Currently running
| nCr(5, 2)    |
| main         |
```

---

### Step 8: `factorial(3)` Completes and Returns 6

Stack:
```
| nCr(5, 2) |  <-- Currently running
| main      |
```

---

### Step 9: `nCr(5, 2)` Completes and Returns 10

Stack:
```
| main |  <-- Currently running
```

---

### Step 10: `main` Completes and Program Ends

Stack:
```
(Empty)       <-- Program exits
```

---

### Diagram Summary

Here’s a time-based visual:

```
Time --->

| main |
|------|

| nCr(5, 2) |
| main      |
|-----------|

| factorial(5) |
| nCr(5, 2)    |
| main         |
|--------------|

| nCr(5, 2) |   <-- factorial(5) returns
| main      |
|-----------|

| factorial(2) |
| nCr(5, 2)    |
| main         |
|--------------|

| nCr(5, 2) |   <-- factorial(2) returns
| main      |
|-----------|

| factorial(3) |
| nCr(5, 2)    |
| main         |
|--------------|

| nCr(5, 2) |   <-- factorial(3) returns
| main      |
|-----------|

| main |       <-- nCr(5, 2) returns
|------|

(Empty)         <-- Program ends
```

This shows how the stack grows and shrinks as function calls are made and completed.