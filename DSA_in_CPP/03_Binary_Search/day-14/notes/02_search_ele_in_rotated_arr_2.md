# **Search Element in Rotated Sorted Array II — Problem Explanation**

You are given:

* A **sorted array** (non-decreasing order)
* But the array has been **rotated at some pivot** (i.e., some prefix was moved to the end)
* The array **may contain duplicates**
* You are also given a **target** value

Your task:

👉 **Determine whether the target exists in the array or not.**
Return `true` if found, `false` otherwise.

---

## **What is a rotated sorted array?**

A sorted array:

```
[1, 2, 3, 4, 5, 6, 7]
```

If rotated, becomes something like:

```
[4, 5, 6, 7, 1, 2, 3]
```

It is still made from a sorted array, only rotated (cut at a pivot and rearranged).

---

## **What’s different in version II?**

In **version I** of the problem, all elements are **distinct**, so you can use clean binary-search logic to find which half is sorted.

But in **version II**, the array **may contain duplicates**, like:

```
[2, 5, 6, 0, 0, 1, 2]
```

or

```
[1,1,1,3,1]
```

Duplicates make it harder to detect which side is sorted.

---

## **Your goal**

Given such an array and a target like:

```
nums = [2, 5, 6, 0, 0, 1, 2]
target = 0
```

You must answer **yes** or **no** based on whether `target` is present.

---

## **Example Inputs/Outputs**

### **Example 1**

```
Input:
nums = [2, 5, 6, 0, 0, 1, 2], target = 0

Output:
true  (0 is present)
```

### **Example 2**

```
Input:
nums = [2, 5, 6, 0, 0, 1, 2], target = 3

Output:
false  (3 is NOT present)
```

### **Example 3 (with duplicates messing things)**

```
nums = [1,1,1,3,1], target = 3

Output:
true
```

---

## **In summary**

✔ The array was originally sorted
✔ It got rotated
✔ It may contain duplicates
✔ You must decide if the `target` exists

No need to find index — only **true/false**.

---
---
---
---

# ✅ **Why the duplicates break your original logic**

In the first problem (without duplicates), you compare:

* `nums[low] <= nums[mid]` → left half sorted
* else → right half sorted

But in **version II**, duplicates can destroy this check.

Example:

```
nums = [2, 2, 2, 3, 2]
           ^     ^
         low    high
           mid ->
```

Here:

* `nums[low] = 2`
* `nums[mid] = 2`
* `nums[high] = 2`

So:

```
nums[low] <= nums[mid]   // true
nums[mid] <= nums[high]  // also true
```

But are we **sure** left side OR right side is sorted?

NO.

The array could have been rotated **inside** the duplicate values.

So your normal binary-search logic **fails** because duplicates give FALSE signals.

This is the main issue.

---

# ✅ **What is the key idea?**

When:

```
nums[low] == nums[mid] == nums[high]
```

It means:

👉 **We have no idea which side is sorted.**
Duplicates make both sides appear sorted even if they’re not.

So in this situation **binary search cannot decide direction**.

Then what should we do?

We perform the **only safe operation**:

👉 Shrink the boundary by 1 from both sides.

Because removing a duplicate from either end does NOT remove the target.

---

# ✅ **Why shrinking works?**

If:

```
low ---->   mid   <---- high
```

and all three values are equal:

```
[2, 2, 2, 2, 2, 2, 2]
```

or even:

```
[2, 2, 2, 3, 2, 2]
```

Then:

* Removing `low` does NOT miss the target, because it’s identical to mid
* Removing `high` also does NOT miss the target

Shrinking is always safe because:

* If **target ≠ nums[mid]**, then removing the duplicates is harmless
* If **target = nums[mid]**, mid would already have returned `true`

So this move is safe.

---

# 💡 **Core intuition to remember**

### ❗ You cannot determine the sorted half when all three are equal.

Binary search relies on "which half is sorted".
Duplicates destroy this detection.

So we must **peel away the duplicates** until the structure becomes normal again.

This is EXACTLY why we do:

```cpp
if (nums[low] == nums[mid] && nums[mid] == nums[high])
{
    low++;
    high--;
    continue;
}
```

We are **removing the confusing edges**.

---

# ✔ Why only these 3 lines solve the entire problem?

Because this single condition covers the only scenario where:

* Your earlier logic fails
* You cannot detect sorted half
* Duplicates block decision-making

Once duplicates from boundary are removed, the array reduces to the **same form as version I**, and your original logic works perfectly:

```
sorted left vs sorted right
```

This is the ONLY extra case version II introduces.

---

# ⭐ How can someone think of this? (Very important)

Most people discovered this because:

1. They applied the normal rotated array logic
2. It failed on inputs like

   ```
   [1,1,1,3,1]
   ```
3. They printed values and saw:

   ```
   low = mid = high
   ```
4. They realized:
   ❗ Binary search cannot choose a direction
5. So the only safe fallback is:
   👉 Remove duplicates at the boundary
   👉 Try again

This is a **pattern** in many binary search problems:

### **When you lack information to decide direction, shrink the search space minimally until info appears.**

---

# 🧠 Final Intuition (One Line)

**Duplicates at both ends hide the rotation information.
Removing those duplicates reveals the true sorted half.**



---
---
---


# ✅ **Original problem (no duplicates)**

Your binary search does:

* Every step → cuts search space *almost in half*

So TC =
\[
O(\log n)
\]

---

# ❗ **With duplicates (this second problem)**

When this condition hits:

```cpp
if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
    low++;
    high--;
}
```

You are ** NOT cutting the search space in half.**

You are cutting it by only **1 from each side**, so effectively:

\[
\text{search space reduces from } n \rightarrow n-2
\]

In the worst case (all elements same):

```
[2, 2, 2, 2, 2, 2, 2, ...]
```

You will keep shrinking like this:

```
n → n-2 → n-4 → n-6 → ... → 0
```

This is **linear**, not logarithmic.

So WORST-CASE TC becomes:

\[
O(n)
\]

---

# 🌟 Why worst case becomes linear?

Because if ALL values are equal:

```
nums[low] == nums[mid] == nums[high]
```

always true.

So binary search NEVER gets a "sorted side".
It only shrinks edges one by one.

Linear shrinking → linear time.

---

# ⭐ Final Time Complexity Summary

| Case                            | Time Complexity |
| ------------------------------- | --------------- |
| **Average case**                | \( O(\log n) \)   |
| **Best case**                   | \( O(\log n) \)   |
| **Worst case (all duplicates)** | \( O(n) \)        |

---

# 🔥 One-line explanation

**Duplicates destroy your ability to divide the array by 2 each step, so binary search degrades to linear scan in the worst case.**