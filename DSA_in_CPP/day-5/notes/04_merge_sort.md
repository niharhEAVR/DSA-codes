**Merge Sort** is a popular **divide and conquer** algorithm used for sorting data efficiently. It divides the input list into smaller parts, sorts them, and then merges them back together in order.

---

### 🧠 **Basic Idea**

1. **Divide:** Split the array into two halves.
2. **Conquer:** Recursively sort each half.
3. **Combine:** Merge the two sorted halves into one sorted array.

---

### ⚙️ **How It Works (Step-by-Step Example)**

Suppose you have the array:
`[38, 27, 43, 3, 9, 82, 10]`

**Step 1: Divide**
Split into halves repeatedly until each subarray has one element:

```
[38, 27, 43, 3, 9, 82, 10]
→ [38, 27, 43, 3] and [9, 82, 10]
→ [38, 27] [43, 3] [9, 82] [10]
→ [38] [27] [43] [3] [9] [82] [10]
```

**Step 2: Conquer (Sort small arrays)**
Now merge the smallest arrays in sorted order:

```
[38] + [27] → [27, 38]
[43] + [3] → [3, 43]
[9] + [82] → [9, 82]
[10] remains as is
```

**Step 3: Combine (Merge sorted arrays)**
Keep merging sorted subarrays:

```
[27, 38] + [3, 43] → [3, 27, 38, 43]
[9, 82] + [10] → [9, 10, 82]
Finally:
[3, 27, 38, 43] + [9, 10, 82] → [3, 9, 10, 27, 38, 43, 82]
```

✅ **Final Sorted Array:** `[3, 9, 10, 27, 38, 43, 82]`

---

### 🧩 **Algorithm (Pseudocode)**

```text
mergeSort(arr):
    if length of arr <= 1:
        return arr
    
    mid = length(arr) // 2
    left = mergeSort(arr[0:mid])
    right = mergeSort(arr[mid:])
    
    return merge(left, right)

merge(left, right):
    result = []
    while both left and right not empty:
        if left[0] <= right[0]:
            append left[0] to result and remove it from left
        else:
            append right[0] to result and remove it from right
    append remaining elements of left and right to result
    return result
```

---

### ⏱️ **Complexity Analysis**

| Case    | Time Complexity | Space Complexity |
| ------- | --------------- | ---------------- |
| Best    | O(n log n)      | O(n)             |
| Average | O(n log n)      | O(n)             |
| Worst   | O(n log n)      | O(n)             |

---

### 💡 **Key Points**

* **Stable:** Yes (preserves the order of equal elements)
* **Not in-place:** Requires extra memory for merging
* **Best for:** Large datasets and linked lists
* **Consistent:** Always O(n log n), even in the worst case (unlike quicksort)



---
---
---


Let's dry-run **How program executes it in memory**.

---

## 🧠 Array:

```
arr = [2, 8, 4, 7, 1, 6, 5, 3]
low = 0, high = 7
```

---

## 🪜 Step 1: Call stack starts

```
mergeSort(arr, 0, 7)
```

`mid = (0 + 7)/2 = 3`

So we will:

```
mergeSort(arr, 0, 3)   // Left half
mergeSort(arr, 4, 7)   // Right half
mergee(arr, mid=3, low=0, high=7)
```

But recursion goes **depth-first**, so we handle `(0,3)` first.

---

# 🧩 LEVEL 1 — mergeSort(arr, 0, 3)

mid = 1
We call:

```
mergeSort(arr, 0, 1)
mergeSort(arr, 2, 3)
mergee(arr, mid=1, low=0, high=3)
```

Now again, first `(0,1)` is handled.

---

# 🧩 LEVEL 2 — mergeSort(arr, 0, 1)

mid = 0
We call:

```
mergeSort(arr, 0, 0)
mergeSort(arr, 1, 1)
mergee(arr, mid=0, low=0, high=1)
```

---

## ▶️ mergeSort(arr, 0, 0)

`low >= high`, so it **returns immediately** (array of one element).

Return to parent call (arr, 0, 1).

---

## ▶️ mergeSort(arr, 1, 1)

`low >= high`, return immediately.

Now it’s time to **merge arr[0..1] = [2,8]**

---

# 🧩 mergee(arr, mid=0, low=0, high=1)

Let’s dry-run inside the merge step-by-step.

| Variables | Value       |
| --------- | ----------- |
| left      | 0           |
| right     | mid + 1 = 1 |
| temp      | []          |

Now we compare:

```
arr[left] = arr[0] = 2
arr[right] = arr[1] = 8
```

Since 2 <= 8 → push 2 → temp = [2]
Increment `left = 1`

Now `left = 1` > mid = 0, so exit first while loop.

Then copy remaining right side:
→ push arr[1] = 8 → temp = [2, 8]

Finally copy back:

```
arr[0] = 2
arr[1] = 8
```

✅ arr becomes `[2, 8, 4, 7, 1, 6, 5, 3]`

Return to mergeSort(arr, 0, 3).

---

# 🧩 LEVEL 2 — mergeSort(arr, 2, 3)

mid = 2
We call:

```
mergeSort(arr, 2, 2)
mergeSort(arr, 3, 3)
mergee(arr, mid=2, low=2, high=3)
```

Both left and right have single elements.

Now merge arr[2..3] = [4,7]

---

## ▶️ mergee(arr, mid=2, low=2, high=3)

```
left = 2, right = 3
arr[2] = 4, arr[3] = 7
4 <= 7 → push 4 → temp=[4]
left=3 → left>mid → exit loop
Remaining right: push 7 → temp=[4,7]
Copy back:
arr[2]=4, arr[3]=7
```

✅ arr stays `[2,8,4,7,1,6,5,3]`

---

# 🧩 mergee(arr, mid=1, low=0, high=3)

Now merge [2,8] and [4,7].

Initialize:

```
left=0, right=2, temp=[]
```

Now step by step:

| Step | Compare | Smaller | temp    | left | right            |
| ---- | ------- | ------- | ------- | ---- | ---------------- |
| 1    | 2 vs 4  | 2       | [2]     | 1    | 2                |
| 2    | 8 vs 4  | 4       | [2,4]   | 1    | 3                |
| 3    | 8 vs 7  | 7       | [2,4,7] | 1    | 4 (out of range) |

Now left part still has 8 left → push → [2,4,7,8]

Copy back to arr[0..3]:

```
arr = [2,4,7,8,1,6,5,3]
```

✅ Left half done and sorted.

---

# 🧩 LEVEL 1 — mergeSort(arr, 4, 7)

Now recursion continues for right side.

mid = (4+7)/2 = 5
We call:

```
mergeSort(arr, 4, 5)
mergeSort(arr, 6, 7)
mergee(arr, mid=5, low=4, high=7)
```

---

## ▶️ mergeSort(arr, 4, 5)

mid = 4

```
mergeSort(arr, 4, 4)
mergeSort(arr, 5, 5)
mergee(arr, mid=4, low=4, high=5)
```

### mergee for [1,6]:

left=4, right=5
1 <= 6 → push 1
Remaining → push 6
✅ arr unchanged `[2,4,7,8,1,6,5,3]`

---

## ▶️ mergeSort(arr, 6, 7)

mid = 6

```
mergeSort(arr, 6, 6)
mergeSort(arr, 7, 7)
mergee(arr, mid=6, low=6, high=7)
```

Merging [5,3]:

| Compare           | Smaller | temp |
| ----------------- | ------- | ---- |
| 5 vs 3            | 3       | [3]  |
| Remaining left: 5 | [3,5]   |      |

✅ arr becomes `[2,4,7,8,1,6,3,5]`

---

## ▶️ mergee(arr, mid=5, low=4, high=7)

Merging [1,6] and [3,5]
left=4, right=6

| Step               | Compare   | Smaller | temp    | left | right           |
| ------------------ | --------- | ------- | ------- | ---- | --------------- |
| 1                  | 1 vs 3    | 1       | [1]     | 5    | 6               |
| 2                  | 6 vs 3    | 3       | [1,3]   | 5    | 7               |
| 3                  | 6 vs 5    | 5       | [1,3,5] | 5    | 8(out of range) |
| Remaining left → 6 | [1,3,5,6] |         |         |      |                 |

✅ arr becomes `[2,4,7,8,1,3,5,6]`

---

# 🧩 FINAL MERGE → mergee(arr, mid=3, low=0, high=7)

Merging:
Left = [2,4,7,8] (0–3)
Right = [1,3,5,6] (4–7)

Initialize: `left=0, right=4`

| Step                       | Compare           | Smaller | temp          | left | right           |
| -------------------------- | ----------------- | ------- | ------------- | ---- | --------------- |
| 1                          | 2 vs 1            | 1       | [1]           | 0    | 5               |
| 2                          | 2 vs 3            | 2       | [1,2]         | 1    | 5               |
| 3                          | 4 vs 3            | 3       | [1,2,3]       | 1    | 6               |
| 4                          | 4 vs 5            | 4       | [1,2,3,4]     | 2    | 6               |
| 5                          | 7 vs 5            | 5       | [1,2,3,4,5]   | 2    | 7               |
| 6                          | 7 vs 6            | 6       | [1,2,3,4,5,6] | 2    | 8(out of range) |
| Remaining left → push 7, 8 | [1,2,3,4,5,6,7,8] |         |               |      |                 |

✅ Final arr = `[1,2,3,4,5,6,7,8]`

---

# 🧭 Execution Order Summary

```
mergeSort(0,7)
 ├── mergeSort(0,3)
 │    ├── mergeSort(0,1)
 │    │    ├── mergeSort(0,0)
 │    │    ├── mergeSort(1,1)
 │    │    └── mergee(0,1)
 │    ├── mergeSort(2,3)
 │    │    ├── mergeSort(2,2)
 │    │    ├── mergeSort(3,3)
 │    │    └── mergee(2,3)
 │    └── mergee(0,3)
 ├── mergeSort(4,7)
 │    ├── mergeSort(4,5)
 │    │    ├── mergeSort(4,4)
 │    │    ├── mergeSort(5,5)
 │    │    └── mergee(4,5)
 │    ├── mergeSort(6,7)
 │    │    ├── mergeSort(6,6)
 │    │    ├── mergeSort(7,7)
 │    │    └── mergee(6,7)
 │    └── mergee(4,7)
 └── mergee(0,7)
```

---

## 💡 What’s Happening Intuitively

Think of it like **splitting the array in half over and over**, until every part is just one number — then you start **gluing them back** together in sorted order.

Visually:

```
[2,8,4,7,1,6,5,3]
     ↓ split
[2,8,4,7]       [1,6,5,3]
   ↓                ↓
[2,8] [4,7]     [1,6] [5,3]
 ↓     ↓          ↓     ↓
[2,8] [4,7]     [1,6] [3,5]
   ↓                ↓
 [2,4,7,8]       [1,3,5,6]
         ↓ merge
   [1,2,3,4,5,6,7,8]
```
