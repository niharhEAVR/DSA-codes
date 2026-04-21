# 📌 Pascal's Triangle — Explanation

Pascal’s Triangle is a triangular arrangement of binomial coefficients:

\[
\text{Row }0: ; 1
\]
\[
\text{Row }1: ; 1;;1
\]
\[
\text{Row }2: ; 1;;2;;1
\]
\[
\text{Row }3: ; 1;;3;;3;;1
\]

General formula:

\[
\text{row}[j] = \binom{i}{j} = \frac{i!}{j!(i-j)!}
\]

---

# ✅ **BRUTE APPROACH (Using factorial formula)**

### **Idea**

For every row `i` and every column `j`, compute:

\[
C(i,j) = \frac{i!}{j!(i-j)!}
\]

Put each value into a row vector and add it to `ans`.

---

### **Time Complexity**

To compute factorial each time:

* Computing factorial:
  \[
  O(\text{row number}) = O(i)
  \]
* For each of (n) rows you compute every element again.

Worst case:
\[
O(n^3)
\]

(You compute factorial repeatedly in nested loops → extremely slow.)

---

# ⚠️ Why brute is bad?

* repeated factorial calculations
* overflow chances
* unnecessary recomputation

---

# ⚡ BETTER APPROACH (Use property inside a row)

Instead of factorials, compute elements using:

\[
C(i,j) = C(i, j-1) \times \frac{i-j+1}{j}
\]

This creates each row in **O(row length)**.

---

### Time Complexity

\[
O(n^2) \quad \text{(because triangle has 1 + 2 + ... + n = } O(n^2))
\]

Space Complexity:
\[
O(1) \text{ (excluding output)}
\]

---

# 🚀 **OPTIMAL APPROACH (Most optimal in DSA interviews)**

> **Build the triangle row-by-row using previous row**.

### **Key Observation**

Each element except the edges is:

\[
\text{row}[j] = \text{prevRow}[j-1] + \text{prevRow}[j]
\]

### **Steps**

1. Start with row0 = [1]
2. For each row `i`:

   * Start with 1
   * Middle elements = sum of two elements from previous row
   * End with 1
3. Push to `ans`

---

### **Why this is optimal?**

* No factorials
* No multiplications
* Pure additions
* Uses the definition of Pascal’s triangle
* Minimum possible work: we must produce all numbers anyway

---

### **Time Complexity**

\[
O(n^2)
\]

(There is **no approach faster than O(n^2)** because the triangle itself has (O(n^2)) elements.)

---

### **Space Complexity**

\[
O(n^2) \text{ for ans}
O(n) \text{ for a single row}
\]

---

# 🎯 Summary Table

| Approach    | Method                              | Time         | Space | Comments                       |
| ----------- | ----------------------------------- | ------------ | ----- | ------------------------------ |
| **Brute**   | Factorial formula                   | (O(n^3))     | O(1)  | Never used in DSA              |
| **Better**  | Use combinatorics iterative formula | (O(n^2))     | O(1)  | Good but not most common       |
| **Optimal** | Use previous row to build next row  | **(O(n^2))** | O(n)  | **Most accepted DSA approach** |
