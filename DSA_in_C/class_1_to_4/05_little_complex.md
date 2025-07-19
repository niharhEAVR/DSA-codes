In the context of **Big O**, **Big Ω**, and **Big Θ** notations, functions like \( f(n) \), \( g(n) \), and constants like \( c \) have specific meanings. Let’s break them down with clear explanations.

---

### **1. What is \( f(n) \)?**
- \( f(n) \): Represents the **actual runtime** or **resource consumption** (like time or memory) of an algorithm for an input size \( n \).
- Example: If you’re measuring the time it takes to sort an array with \( n \) elements, \( f(n) \) might be the exact number of comparisons or operations performed.

---

### **2. What is \( g(n) \)?**
- \( g(n) \): Represents a **reference function** that we use to compare \( f(n) \) against.
- Example: In Big O, \( g(n) \) could be \( n^2 \), \( n \log n \), or any other mathematical expression. It’s used to describe the growth rate of \( f(n) \).

---

### **3. What is \( c \)?**
- \( c \): Represents a **constant multiplier**. It adjusts \( g(n) \) to bound \( f(n) \) from above or below. This ensures the relationship between \( f(n) \) and \( g(n) \) is valid.
- Example: If \( f(n) \leq c \cdot g(n) \), the constant \( c \) scales \( g(n) \) to ensure it covers \( f(n) \) for sufficiently large \( n \).

---

### **How They Work Together**
Let’s see how \( f(n) \), \( g(n) \), and \( c \) are used in **Big O**, **Big Ω**, and **Big Θ**.

---

#### **Big O (Upper Bound)**
- **Definition**: \( f(n) \) is \( O(g(n)) \) if:
  \[
  f(n) \leq c \cdot g(n), \quad \text{for all } n \geq n_0
  \]
  - \( g(n) \): The function that sets the upper bound.
  - \( c \): A constant that scales \( g(n) \) to cover \( f(n) \).

- **Example**:
  - \( f(n) = 3n + 2 \)
  - \( g(n) = n \)
  - Here, \( f(n) \leq 4n \) for \( n \geq 2 \), so \( f(n) \) is \( O(n) \).

---

#### **Big Ω (Lower Bound)**
- **Definition**: \( f(n) \) is \( \Omega(g(n)) \) if:
  \[
  f(n) \geq c \cdot g(n), \quad \text{for all } n \geq n_0
  \]
  - \( g(n) \): The function that sets the lower bound.
  - \( c \): A constant that scales \( g(n) \) to ensure it doesn’t drop below \( f(n) \).

- **Example**:
  - \( f(n) = 3n + 2 \)
  - \( g(n) = n \)
  - Here, \( f(n) \geq 3n \) for all \( n \geq 1 \), so \( f(n) \) is \( \Omega(n) \).

---

#### **Big Θ (Tight Bound)**
- **Definition**: \( f(n) \) is \( \Theta(g(n)) \) if:
  \[
  c_1 \cdot g(n) \leq f(n) \leq c_2 \cdot g(n), \quad \text{for all } n \geq n_0
  \]
  - \( g(n) \): The function that sets both the upper and lower bounds.
  - \( c_1, c_2 \): Constants that scale \( g(n) \) for both bounds.

- **Example**:
  - \( f(n) = 3n + 2 \)
  - \( g(n) = n \)
  - Here, \( 3n \leq f(n) \leq 4n \) for \( n \geq 2 \), so \( f(n) \) is \( \Theta(n) \).

---

### **Intuitive Example**
Imagine a train on a track.

- \( f(n) \): The train’s **actual speed**.
- \( g(n) \): The **speed limit** or **reference speed**.
- \( c \): A constant that adjusts the speed limit to match reality.

#### Big O:
- The train’s speed \( f(n) \) **does not exceed** \( g(n) \cdot c \).
- Example: If \( g(n) = 100 \) km/h and \( c = 1.5 \), the train won’t go faster than \( 150 \) km/h.

#### Big Ω:
- The train’s speed \( f(n) \) **does not drop below** \( g(n) \cdot c \).
- Example: If \( g(n) = 50 \) km/h and \( c = 0.8 \), the train always goes at least \( 40 \) km/h.

#### Big Θ:
- The train’s speed \( f(n) \) **stays between** \( c_1 \cdot g(n) \) and \( c_2 \cdot g(n) \).
- Example: If \( g(n) = 80 \) km/h, \( c_1 = 0.9 \), and \( c_2 = 1.1 \), the train’s speed is between \( 72 \) km/h and \( 88 \) km/h.

---

### Summary
- \( f(n) \): The algorithm’s actual runtime or resource usage.
- \( g(n) \): The reference growth rate for comparison.
- \( c \): A constant that scales \( g(n) \) to match \( f(n) \).
- Big O, Ω, and Θ show how \( f(n) \) grows relative to \( g(n) \) under worst, best, or average conditions.