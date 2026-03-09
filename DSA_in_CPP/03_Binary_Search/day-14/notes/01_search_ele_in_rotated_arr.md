# ⭐ Problem: Search in Rotated Sorted Array (Part-I)

You are given:

* A **sorted array**
* But it has been **rotated** at some pivot
* You must **find the index** of a given **target**
* If not found, return **–1**

### Example

Original sorted array:

```
[1, 2, 3, 4, 5, 6, 7]
```

Rotated version:

```
[4, 5, 6, 7, 1, 2, 3]
```

Target = `6`
Answer → index `2`

---

# ⚠️ What is a Rotated Sorted Array?

A **sorted array** rotated at one pivot:

```
[1,2,3,4,5,6,7] 
     ↓ rotate at 3
[4,5,6,7,1,2,3]
```

It still contains two important facts:

1. **Exactly one part is sorted**, left or right
2. The array is **still made of two sorted chunks**

This is the key property used in the optimal solution.

---

# 1️⃣ **Brute Force Approach**

## **Intuition**

Simply scan the entire array from left to right.

* Compare each element with target
* If found → return index

## **Time Complexity**

\[
O(n)
\]

## **Space Complexity**

\[
O(1)
\]

▶ Works always
▶ NOT efficient for big inputs

---

# 2️⃣ **Better Approach (Two Steps Binary Search)**

Still **not optimal**, but better than brute.

## **Intuition**

1. **Find the pivot**
   (Pivot = the smallest element's index, i.e., where rotation happened)

2. After pivot, the array becomes like:

   * Left part: sorted
   * Right part: sorted

3. Perform binary search on the correct sorted part where target might exist.

## **Time Complexity**

* Finding pivot = (O(\log n))
* Binary search again = (O(\log n))

Total:
\[
O(\log n)
\]

## **Space Complexity**

\[
O(1)
\]

This method is good but still two separate operations.

---

# 3️⃣ ⭐ **Optimal Approach (Modified Binary Search in One Pass)**

### This is the **famous single-pass binary search for rotated array**.

### The one interviewers expect.

### This is the BEST approach.

---

# 💡 Optimal Intuition

At every `mid`, at least **one side is sorted**:

### Case 1: **Left side is sorted**

Check:

```
nums[low] <= nums[mid]
```

If true → left part is sorted.

Now check whether target lies in this sorted region:

* If `nums[low] <= target < nums[mid]`
  → target is in left part → go **left**
* Else
  → target is in right part → go **right**

---

### Case 2: **Right side is sorted**

Check:

```
nums[mid] <= nums[high]
```

If true → right part is sorted.

Now check whether target lies in this sorted region:

* If `nums[mid] < target <= nums[high]`
  → target is in right part → go **right**
* Else
  → target is in left part → go **left**

---

# 🤯 Why does this work?

Because a rotated sorted array **always** has one side properly sorted:

```
[4,5,6,7 | 1,2,3]
 sorted   sorted
```

Binary search is used,
but the direction is chosen using **which side is sorted**.

---

# ⏳ Time & Space Complexity (Optimal Approach)

### **Time Complexity**

One pass binary search:

\[
O(\log n)
\]

### **Space Complexity**

\[
O(1)
\]

---

# 🏆 Summary Table

| Approach    | Idea                                            | Time         | Space    |
| ----------- | ----------------------------------------------- | ------------ | -------- |
| **Brute**   | Linear search                                   | O(n)         | O(1)     |
| **Better**  | Find pivot + binary search                      | O(log n)     | O(1)     |
| **Optimal** | **Modified binary search based on sorted half** | **O(log n)** | **O(1)** |

---
---
---
---


```cpp
int optimal(std::vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int ans{-1};
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if(nums[mid] == target) return mid;

        if (nums[low] <= nums[mid])
        {
            if (nums[low] <= target && target <= nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else 
        {
            if (nums[mid] < target && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return ans;
}
```


Here is a example where **both the outer cases happen**:

### ✔ Case-1:

`if (nums[low] <= nums[mid])`
→ **Left half is sorted**

### ✔ Case-2:

`else`
→ **Right half is sorted**

Meaning:
**In one full run of the algorithm (same input array), the code should enter BOTH the left-sorted case and right-sorted case in different iterations.**

This happens when:

* In one iteration → mid falls in the sorted left region
* In another iteration → mid falls in the sorted right region

So the algorithm explores both branches.

---

# ⭐ Best Example Where Both Cases Occur

Use this rotated array:

```
nums = [6, 7, 8, 1, 2, 3, 4, 5]
index  0  1  2  3  4  5  6  7

target = 3
```

This is perfect because:

* The **left half ([6,7,8])** is sorted at first
* The **right half ([1,2,3,4,5])** is sorted later

👉 So the algorithm will enter **both**:

* The big IF (left sorted)
* And the ELSE (right sorted)

---

# ⭐ FULL DRY RUN (Showing Both Parent IF + ELSE)

---

# 🔵 **Iteration 1**

```
low = 0
high = 7

mid = (0 + 7) / 2 = 3
nums[mid] = 1
```

Check sorted side:

```
nums[low] = 6
nums[mid] = 1

6 <= 1 → FALSE
```

So:

➡️ Enters **ELSE** block
➡️ Meaning: **Right half is sorted**

This region:

```
[1,2,3,4,5]
```

Check if target = 3 lies here:

```
nums[mid] < target <= nums[high]
1 < 3 <= 5 → TRUE
```

So go right:

```
low = mid + 1 = 4
```

---

# 🔵 **Iteration 2**

Now subarray:

```
[2, 3, 4, 5]
 idx: 4  5  6  7
```

```
low = 4
high = 7

mid = (4 + 7)/2 = 5
nums[mid] = 3
```

FOUND target → return 5.

---

# But wait — where is the LEFT SORTED case?

Let’s rerun with **target = 7**
so the algorithm explores both sides.

---

# ⭐ Example That Uses BOTH Branches in Different Iterations

(THIS is what you asked)

```
nums = [6, 7, 8, 1, 2, 3, 4, 5]
target = 2
```

---

## 🔵 Iteration 1 — Enters IF (Left Half Sorted)

```
low=0, high=7
mid=3 → nums[mid]=1
```

Check:

```
nums[low] <= nums[mid] ?
6 <= 1 → FALSE
```

No — this is ELSE
(we will use that later)

Let’s choose a target that causes both IF and ELSE.

---

# ⭐ Correct Example (FINAL)

To trigger **both parent IF and parent ELSE**, we use:

```
nums = [4,5,6,7,0,1,2,3]
target = 6
```

Because:

* First mid falls in right side → ELSE
* Next mid falls in left sorted side → IF

Let’s dry run:

---

## 🔵 Iteration 1 — **ELSE branch**

```
low = 0, high = 7
mid = 3 → nums[mid] = 7

nums[low] = 4
nums[mid] = 7

4 <= 7 → TRUE → enters IF
```

Oops—not ELSE.
Let’s adjust target.

---

# ⭐ The PERFECT EXAMPLE

That *guaranteed* hits BOTH branches:

```
nums = [7,8,1,2,3,4,5,6]
target = 5
```

Because:

* First mid falls in rotated zone → ELSE
* Next mid falls in sorted left side → IF

Let’s dry run:

---

# 🔵 Iteration 1 — enters **ELSE**

```
low=0, high=7
mid=3 → nums[mid]=2

nums[low]=7
nums[mid]=2

7 <= 2 ?  FALSE  
→ enters ELSE
```

This is the first parent ELSE.

Target = 5 lies in sorted region:

Sorted region from mid to high:

```
[2,3,4,5,6]
```

Check:

```
nums[mid] < target <= nums[high]
2 < 5 <= 6 → TRUE
```

So:

```
low = mid + 1 = 4
```

---

# 🔵 Iteration 2 — enters **IF**

Now subarray:

```
[3,4,5,6]
```

```
low=4, high=7
mid = (4+7)/2 = 5
nums[mid] = 4
```

Check:

```
nums[low] <= nums[mid]
3 <= 4 → TRUE
```

So enters **IF** this time.

This is the first parent IF.

Check if target 5 lies in this sorted region:

```
3 <= 5 <= 4 → FALSE
```

So target is not here → go right:

```
low = mid + 1 = 6
```

---

# 🔵 Iteration 3

```
low=6, high=7
mid=6 → nums[mid]=5 → FOUND
```

---

# ⭐ Final Answer

### The array that triggers BOTH parent cases:

```
nums   = [7,8,1,2,3,4,5,6]
index    0 1 2 3 4 5 6 7
target = 5
```

### Execution:

* Iteration 1 → enters **ELSE** (right half sorted)
* Iteration 2 → enters **IF** (left half sorted)

YOU GET BOTH CASES.