# ⭐ Problem: First and Last Occurrence in Array

You are given:

* An **array**, usually **sorted** (most interview questions assume sorted)
* A **target value**
* You must find:

  1. **First occurrence** (leftmost index)
  2. **Last occurrence** (rightmost index)

Example:

```
arr = [2, 4, 4, 4, 7, 9]
target = 4
```

Output:

```
first = 1
last  = 3
```

---

# 1️⃣ **Brute Force Approach**

## **Intuition**

* Traverse the entire array from **left to right**, find the **first** time the element appears.
* Traverse again from **right to left**, find the **last** time it appears.

OR, you can do it in a single pass:

* Initialize `first = -1`, `last = -1`
* Loop from `i = 0` to `n-1`:

  * Every time you find the target, update `last = i`
  * First time you find target, set `first = i` (only once)

## **Time Complexity**

\[
O(n)
\]

## **Space Complexity**

\[
O(1)
\]

## **When is it useful?**

* When array is **unsorted**
* When you cannot use binary search

---

# 2️⃣ **Better Approach (Using Two Binary Searches) BUT WITHOUT OPTIMIZATION**

⚠️ This “better” is basically still not perfect.

## **Intuition**

Binary search normally gives **any one occurrence**, not the first or last.

So we modify it:

### **First-occurrence logic:**

* Do a normal binary search
* When you find the target, **don’t stop**
* Move **left** to see if there are earlier occurrences

### **Last-occurrence logic:**

* Same logic
* When you find the target, **move right** to check if there are more

This uses **two binary searches**:

* One for **first**
* One for **last**

## **Time Complexity**

\[
O(\log n) + O(\log n) = O(\log n)
\]

## **Space Complexity**

\[
O(1)
\]

---

# 3️⃣ **Optimal Approach (Single Modified Binary Search)**

## **Intuition**

We can further optimize the *thought process*:

### 🔥 Key Idea

Binary search can be **modified** to behave like:

* "Find left boundary" (first occurrence)
* "Find right boundary" (last occurrence)

The optimal approach is still **two binary searches**, but the logic is highly optimized:

### Why it is still optimal?

Because **finding boundaries** in a sorted array will always require:

* One binary search for the **left boundary**
* One for the **right boundary**

This is mathematically **optimal** because any algorithm looking for *boundaries* needs at least (O(\log n)) time.

---

## ⭐ How the optimal intuition works

### **For first occurrence:**

* If `arr[mid] == target`,
  → store mid as potential answer
  → go **left** to see if an earlier target exists
* If `arr[mid] < target`, go **right**
* If `arr[mid] > target`, go **left**

### **For last occurrence:**

* If `arr[mid] == target`,
  → store mid
  → go **right** for more occurrences
* If `arr[mid] < target`, go **right**
* If `arr[mid] > target`, go **left**

### Why does this guarantee boundaries?

Because binary search eliminates half the array every time, but still ensures:

* For **first**, you always push left until boundary is found
* For **last**, you always push right until boundary is found

---

## **Time Complexity**

\[
O(\log n)
\]

## **Space Complexity**

\[
O(1)
\]

---

# 🎯 Summary Table

| Approach    | Idea                                          | Time        | Space  |
| ----------- | --------------------------------------------- | ----------- | ------ |
| **Brute**   | Scan entire array                             | \(O(n)\)      | \(O(1)\) |
| **Better**  | 2× binary search                              | \(O(\log n)\) | \(O(1)\) |
| **Optimal** | Modified boundary binary search (still 2× BS) | \(O(\log n)\) | \(O(1)\) |
