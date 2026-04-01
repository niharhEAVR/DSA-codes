# 🧩 **Merge Sort – Super Simple Explanation**

## 👶 **Think of it like this:**

You have a big messy pile of cards.
You **cannot** sort the whole pile at once.
So you do something smart:

### **Step 1: Keep splitting the pile into half**

Split → split → split → until every pile has **1 card** only.

A single card is always sorted.

### **Step 2: Start merging those piles back**

But while merging, you **combine two sorted piles into one sorted pile**.

That’s it.
This whole process is called **Merge Sort**.

---

# 🧠 **Why this works?**

Because it’s easy to merge two already sorted groups.

Example:
Group A = [2, 7]
Group B = [3, 5]

When merging:

* Compare 2 and 3 → smaller is 2
* Compare 7 and 3 → smaller is 3
* Compare 7 and 5 → smaller is 5
* Put remaining 7

You get:
\[
[2,3,5,7]
\]

---

# 🎨 **Visual Explanation (Very Simple)**

Suppose array =
**[4, 2, 7, 1]**

### **Step 1: Split**

```
[4 2 7 1]
   /    \
[4 2]   [7 1]
 / \     / \
[4][2] [7][1]
```

### **Step 2: Merge**

Merge [4] and [2]:

```
[4] + [2] → [2,4]
```

Merge [7] and [1]:

```
[7] + [1] → [1,7]
```

Now merge [2,4] and [1,7]:

```
[2,4] + [1,7] → [1,2,4,7]
```

### **Final Sorted Output:**

\[
[1,2,4,7]
\]

---

# 🏁 **One-Line Definition**

**Merge Sort = Split the array until 1 element + merge them back in sorted order.**

---

# ⭐ Time & Space Complexity

\[
\text{Time} = O(n\log n)
\]
\[
\text{Space} = O(n)
\]

---

# Example

![](./images/img_mergesort_long.png)


# Dry run

```
int arr[] = {12, 8, 9, 3, 11, 5, 4}; 
// size = 7
```
---

# ⚙️ **Step 0 — Array**

```
[12, 8, 9, 3, 11, 5, 4]
```

Merge sort works like this C code structure:

```
mergeSort(arr, l, r):
    mid = (l + r) / 2
    mergeSort(l, mid)
    mergeSort(mid+1, r)
    merge(...)
```

---

# 🔥 **Step 1 — Keep Splitting**

### Level 1 Split

```
[12, 8, 9, 3, 11, 5, 4]
          /              \
 [12, 8, 9, 3]        [11, 5, 4]
```

---

# 🔥 **Step 2 — Split Left Part [12, 8, 9, 3]**

```
[12, 8, 9, 3]
      /       \
 [12, 8]     [9, 3]
```

### Split [12, 8]

```
[12, 8]
  /   \
[12] [8]   → merge → [8, 12]
```

### Split [9, 3]

```
[9, 3]
  /   \
[9] [3]   → merge → [3, 9]
```

### Now merge the two results:

```
Left:  [8, 12]
Right: [3, 9]

Merge comparison:
8 vs 3 → take 3
8 vs 9 → take 8
12 vs 9 → take 9
Take leftover 12

→ [3, 8, 9, 12]
```

Left half sorted becomes:

```
[3, 8, 9, 12]
```

---

# 🔥 **Step 3 — Split Right Part [11, 5, 4]**

```
[11, 5, 4]
     /      \
  [11]    [5, 4]
```

### Split [5, 4]

```
[5, 4]
  /   \
[5]  [4]   → merge → [4, 5]
```

### Now merge:

Left = [11]
Right = [4, 5]

```
11 vs 4 → take 4
11 vs 5 → take 5
leftover 11

→ [4, 5, 11]
```

Right half sorted becomes:

```
[4, 5, 11]
```

---

# 🔥 **Final Merge (Left + Right)**

Left sorted  =

```
[3, 8, 9, 12]
```

Right sorted =

```
[4, 5, 11]
```

### Now merge step-by-step:

| L  | R  | Action           |
| -- | -- | ---------------- |
| 3  | 4  | take 3           |
| 8  | 4  | take 4           |
| 8  | 5  | take 5           |
| 8  | 11 | take 8           |
| 9  | 11 | take 9           |
| 12 | 11 | take 11          |
| 12 | —  | take leftover 12 |

### Result after merging:

```
[3, 4, 5, 8, 9, 11, 12]
```

---

# 🎉 **FINAL OUTPUT**

\[
\boxed{3,\ 4,\ 5,\ 8,\ 9,\ 11,\ 12}
\]



---
---
---


> **“How does recursion actually flow?”**
> Why left splits… then right… and when does merge get called?

---

# ✅ **First: Your mergeSort Function**

```
void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;

    mergeSort(arr, low, mid);      // 1. sort left
    mergeSort(arr, mid + 1, high); // 2. sort right

    mergee(arr, mid, low, high);   // 3. merge both sorted parts
}
```

---

# ⭐ KEY CONCEPT (SUPER IMPORTANT)

**Recursion always goes FULL left first**
(because of the first `mergeSort(arr, low, mid)`).

It will keep splitting left left left left…
until a single element remains.

Then it returns back and merges.

After finishing left half completely,
only then it goes to right half.

---

# 🎯 We will dry-run EXACTLY your code for:

```
arr = {12, 8, 9, 3, 11, 5, 4}    // indexes 0 to 6
```

---

# 🚀 **FULL EXECUTION FLOW (Like CPU does it)**

### 📌 Initial call:

```
mergeSort(arr, 0, 6)
```

## 1️⃣ First split (Level 0)

```
low=0, high=6
mid=3
```

So it calls:

### LEFT:

```
mergeSort(arr, 0, 3)
```

---

# 🟦 **GO LEFT (deep recursion)**

## 2️⃣ Level 1: mergeSort(arr, 0, 3)

```
low=0, high=3 → mid=1
```

Call left again:

### LEFT:

```
mergeSort(arr, 0, 1)
```

---

# 🟩 **Go deeper left**

## 3️⃣ Level 2: mergeSort(arr, 0, 1)

```
low=0, high=1 → mid=0
```

Call left:

### LEFT:

```
mergeSort(arr, 0, 0)
```

---

# 🟥 **Single element → returns**

```
mergeSort(0,0) → low>=high → return
```

Now right:

```
mergeSort(arr, 1, 1)
```

Also returns.

Now merge:

```
mergee(arr, mid=0, low=0, high=1)
```

This merges **[12] and [8]**.

---

# ⬅️ Backtracking to Level 1

Now right branch of (0,3):

```
mergeSort(arr, 2, 3)
```

---

# 🟦 **New right subproblem**

## 4️⃣ mergeSort(arr, 2, 3)

```
low=2, high=3 → mid=2
```

Call left:

```
mergeSort(arr, 2, 2) → returns
```

Call right:

```
mergeSort(arr, 3, 3) → returns
```

Merge:

```
mergee(arr, mid=2, low=2, high=3)
```

This merges **[9] and [3]**.

---

# ⬅️ Back to (0,3)

Now merge two sorted halves:

```
Left sorted part  = indexes 0 to 1 
Right sorted part = indexes 2 to 3

mergee(arr, mid=1, low=0, high=3)
```

This gives **[3, 8, 9, 12]**.

---

# ⬅️ Finished full left half of the main call.

Now CPU goes to original right half:

```
mergeSort(arr, 4, 6)
```

---

# 🟪 **Handle Right Half (4,6)**

## 5️⃣ mergeSort(arr, 4, 6)

```
low=4, high=6 → mid=5
```

Call left:

```
mergeSort(arr, 4, 5)
```

---

# 🟨 Splitting (4,5)

## 6️⃣ mergeSort(arr, 4, 5)

```
mid = 4
```

Left:

```
mergeSort(arr, 4, 4) → returns
```

Right:

```
mergeSort(arr, 5, 5) → returns
```

Merge:

```
mergee(arr, mid=4, low=4, high=5)
```

This merges **[11] and [5] → [5,11]**.

---

# ⬅️ Back to (4,6)

Right:

```
mergeSort(arr, 6, 6) → returns
```

Now merge:

```
mergee(arr, mid=5, low=4, high=6)
```

This merges **[5,11]** and **[4] → [4,5,11]**

---

# ⬆️ Finally merge left + right of main call

Merge:

```
mergee(arr, mid=3, low=0, high=6)
```

Left  = **[3,8,9,12]**
Right = **[4,5,11]**

Final array =

```
[3,4,5,8,9,11,12]
```

---

# 🧠 **SUMMARY OF EXECUTION FLOW**

Think of recursion as:

```
LEFT → LEFT → LEFT → (merge)
    ↑ return
LEFT → RIGHT → (merge)
↑ merge whole left

then go RIGHT half

RIGHT → LEFT → (merge)
RIGHT → RIGHT → (merge)
↑ merge whole right

finally merge everything
```

---
---

# 🌳 **FULL MERGE SORT RECURSION TREE**

(For `mergeSort(arr, 0, 6)`)

```
                                     mergeSort(0,6)
                                   /                \
                              (0,3)                 (4,6)
                           /        \             /       \
                       (0,1)       (2,3)       (4,5)     (6,6)
                     /      \     /     \     /     \
                (0,0)     (1,1) (2,2) (3,3) (4,4) (5,5)
```

---

# 🔥 **NOW LET’S ADD MERGE STEPS**

Merge only happens **when returning**, after both children are done.

I will show STEP-BY-STEP.

---

# ⭐ Level 3 → Base cases

```
(0,0) (1,1) (2,2) (3,3) (4,4) (5,5) (6,6)
```

These RETURN immediately (they are single elements).

---

# ⭐ Level 2 → Merges happening now

### After (0,0) and (1,1) return:

```
merge(0,1)
```

After (2,2) and (3,3) return:

```
merge(2,3)
```

After (4,4) and (5,5) return:

```
merge(4,5)
```

Tree with merges:

```
                    (0,6)
                 /           \
          (0,3)                (4,6)
         /     \              /     \
    (0,1)     (2,3)       (4,5)     (6,6)
    /   \     /   \       /   \
(0,0)(1,1)(2,2)(3,3) (4,4)(5,5)

     ↑        ↑        ↑
  merge     merge     merge
  (0,1)     (2,3)     (4,5)
```

---

# ⭐ Level 1 → More merges

Now left part `(0,3)` merges its children:

```
merge(0,3)
```

Right part `(4,6)` merges its children:

```
merge(4,6)
```

Tree now:

```
                    (0,6)
                 /           \
          (0,3)                (4,6)
           ↑                    ↑
       merge(0,3)         merge(4,6)

         /     \            /    \
    merge    merge     merge     (6,6)
    (0,1)    (2,3)     (4,5)
```

---

# ⭐ FINAL MERGE (root level)

After both sides `(0,3)` and `(4,6)` are sorted:

```
merge(0,6)
```

This gives the **final sorted array**.

---

# 🎉 **FINAL RECURSION + MERGE TREE**

```
                                   mergeSort(0,6)
                                  /               \
                         mergeSort(0,3)       mergeSort(4,6)
                           /        \            /       \
                  mergeSort(0,1)  mergeSort(2,3)  mergeSort(4,5)  (6,6)
                   /      \        /      \        /      \
               (0,0)    (1,1)   (2,2)   (3,3)   (4,4)   (5,5)

               <-- merge(0,1)    <-- merge(2,3)   <-- merge(4,5)
                      \               /               /
                     merge(0,3)     merge(4,6)
                          \           /
                          merge(0,6)   <-- FINAL
```

---

# ✔️ **IMPORTANT: Flow order CPU follows**

### **SPLIT phase (going down the tree):**

```
left → left → left → hit base
```

### **MERGE phase (going up the tree):**

```
backtrack → merge → backtrack → merge → backtrack → merge
```