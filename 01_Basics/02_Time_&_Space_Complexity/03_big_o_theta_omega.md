### **1. Big O (Worst-Case Scenario)**
- **Definition**: Big O tells us the **maximum time** an algorithm can take to complete its task as the input size grows. It’s the **upper bound**.
- **Use**: Helps predict the worst-case behavior, ensuring the algorithm won't take longer than this time.

#### **Example**: Linear Search
- You are searching for a number in an unsorted list.
- In the **worst case**, the number might be the last element, or it might not exist at all.
- Time complexity: **O(n)** (you check all `n` elements).

---

### **2. Big Ω (Best-Case Scenario)**
- **Definition**: Big Omega tells us the **minimum time** an algorithm will take, even in the best-case scenario. It’s the **lower bound**.
- **Use**: Helps predict the best-case behavior, showing the fastest the algorithm can run.

#### **Example**: Linear Search
- If the number you’re searching for is the **first element**, the algorithm stops immediately.
- Time complexity: **Ω(1)** (you check only 1 element).

---

### **3. Big Θ (Average/Exact Case)**
- **Definition**: Big Theta tells us the **exact time** an algorithm will take, considering both the best and worst cases. It’s the **tight bound** (sandwiched between the upper and lower bounds).
- **Use**: Gives a realistic picture of the algorithm’s performance.

#### **Example**: Linear Search
- On average, the number you’re searching for might be somewhere in the middle of the list.
- Time complexity: **Θ(n)** (you check about half of the elements on average).

---

### **Key Differences**
| **Aspect**         | **Big O**                     | **Big Ω**                    | **Big Θ**                  |
|---------------------|-------------------------------|------------------------------|----------------------------|
| **What it measures**| Worst-case performance        | Best-case performance        | Average or exact performance|
| **Bound type**      | Upper bound                  | Lower bound                  | Tight bound (both upper and lower) |
| **Focus**           | Guarantees it won’t be slower| Guarantees it won’t be faster| Shows the exact behavior   |

---

### **Example: Sorting an Array**
Let’s use **Bubble Sort** as an example.

1. **Worst Case (Big O)**:
   - If the array is in reverse order, every element needs to be compared and swapped.
   - Time complexity: **O(n²)**.

2. **Best Case (Big Ω)**:
   - If the array is already sorted, Bubble Sort can detect this in one pass.
   - Time complexity: **Ω(n)**.

3. **Average Case (Big Θ)**:
   - For an average unsorted array, the algorithm will perform a mix of comparisons and swaps.
   - Time complexity: **Θ(n²)**.

---

### **Analogy: Finding a Seat in a Theater**
Imagine you're looking for a seat in a theater.

1. **Big O (Worst Case)**:
   - The theater is almost full, and the only seat left is in the back row. You have to check every row.
   - **O(n)**.

2. **Big Ω (Best Case)**:
   - You walk in, and there’s a seat right at the entrance.
   - **Ω(1)**.

3. **Big Θ (Average Case)**:
   - On average, the seat might be somewhere in the middle of the theater.
   - **Θ(n)**.

---

### **Another Example: Binary Search**
Binary Search is a fast way to find an item in a sorted list.

1. **Big O (Worst Case)**:
   - You might have to divide the list repeatedly until only one element is left.
   - Time complexity: **O(log n)**.

2. **Big Ω (Best Case)**:
   - The item you’re looking for might be the very first middle element.
   - Time complexity: **Ω(1)**.

3. **Big Θ (Average Case)**:
   - On average, you’ll divide the list a few times to find the item.
   - Time complexity: **Θ(log n)**.

---

### **Summary**
- **Big O**: Focuses on the **worst-case scenario** (slowest time).
- **Big Ω**: Focuses on the **best-case scenario** (fastest time).
- **Big Θ**: Gives the **average or exact time** (realistic performance).
