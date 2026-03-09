# ✅ **Fastest Sorting Algorithm in DSA (Practically)**

### **1. Quicksort**

* **Average Time Complexity:**
  \[
  O(n \log n)
  \]
* **Worst Case:**
  \[
  O(n^2)
  \]
* **Space Complexity:**
  \[
  O(\log n)
  \] (because of recursion stack)
* **Why Fast?**

  * Super small constants
  * In-place
  * Great cache locality
  * Used in many STL/internal library implementations
* **Conclusion:**
  👉 **Fastest in real-world practice.**

---

# 🚀 **Fastest (Guaranteed) Sorting Algorithm**

### **2. Merge Sort**

* **Time Complexity:**
  \[
  O(n \log n)
  \] (best/avg/worst)
* **Space Complexity:**
  \[
  O(n)
  \]
* **Why Good?**

  * Stable
  * Guaranteed performance
  * No worst-case trap like quicksort
* **Used in many languages for stable sorting.**

---

# ☑️ **Most Optimal Sorting (Theoretical Option)**

### **3. Heap Sort**

* **Time Complexity:**
  \[
  O(n \log n)
  \]
* **Space Complexity:**
  \[
  O(1)
  \]
* **Why Good?**

  * In-place
  * Guaranteed time
* **But**

  * Slower than quicksort in practice because constants are bigger.
  * Worse cache locality.

---

# 🎯 **Conclusion (Final Answer)**

| Algorithm      | Avg TC       | Worst TC     | SC          | Practical Speed         | Notes                                  |
| -------------- | ------------ | ------------ | ----------- | ----------------------- | -------------------------------------- |
| **Quicksort**  | $(O(n\log n))$ | $(O(n^2))$     | $(O(\log n))$ | ⭐ Fastest in practice   | Used in STL (`sort()`)                 |
| **Merge Sort** | $(O(n\log n))$ | $(O(n\log n))$ | (O(n))      | ⭐ Stable + guaranteed   | Used in Java, Python (`stable_sort()`) |
| **Heap Sort**  | $(O(n\log n))$ | $(O(n\log n))$ | (O(1))      | ❗ Slower than quicksort | In-place                               |

---

# 👍 **If your question is:**

### **"Which sorting algorithm is fastest?"**

✔ **Quicksort (practically)**
✔ **Merge Sort (theoretically guaranteed)**

---

# 🧠 **What about Linear Time Sorts?**

If array elements are **integers in a range**, these beat everything:

### **Counting Sort — (O(n+k))**

### **Radix Sort — \(O(n \cdot \text{digits})\)**

### **Bucket Sort — avg (O(n))**

But these **do not work for general comparisons**.