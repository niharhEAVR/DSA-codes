# Its a same problem from the count inversion, but in here the we are comparing it by multiply by 2.
# if any confusion then watch strivers video: [Reverse Pairs](https://www.youtube.com/watch?v=0e4bZaP3MDI&list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&index=43)

---

**Reverse Pairs Problem**:

Given an array, count pairs
\[
(i, j) \quad i < j \quad \text{and} \quad A[i] > 2 \times A[j]
\]

This is just a **modified merge sort**, EXACTLY like count inversions, but the **condition is different**.

---

# ⭐ INTUITION (VERY IMPORTANT)

During merge sort:

* Left half is sorted
* Right half is sorted

So before merging, you can find how many **reverse pairs** there are between the two halves.

### You only need to check:

\[
A[i] > 2 \times A[j]
\]

Because both halves are sorted, for every `i` in left:

* The values in the right half that satisfy this condition will be in a **continuous segment**.

So you can use a pointer `j` that moves forward only once.

---

# ⭐ HOW TO THINK OF THE LOGIC (Beginner Explanation)

Compare this with Normal Inversions:

### Count Inversion:

Condition →
\[
A[i] > A[j]
\]

### Reverse Pairs:

Condition →
\[
A[i] > 2 \times A[j]
\]

The problem is we **cannot count continuous remaining left side** like inversion, because:

For inversion we used:

```
count += (mid - i + 1)
```

But that was because condition was strictly based on sorted left.

Here, right pointer moves based on **multiplication** condition.
So we need:

### A scanning loop BEFORE merge step:

```
i = left pointer
j = mid+1

for every i in left part:
    while j <= high AND A[i] > 2*A[j]:
        j++
    count += (j - (mid+1))
```

Meaning:

* For each `i`, we find how many `j` in right satisfy the condition.
* Because right is sorted, once `j` moves forward, it never moves back.

This gives O(N) for the counting step.

---

# ⭐ STEP-BY-STEP FLOW

Here is THE logic:

```
mergeSort(left, right):
    mid = (left + right)/2
    countLeft = mergeSort(left, mid)
    countRight = mergeSort(mid+1, right)
    countCross = countReversePairs(left, mid, right)
    merge two sorted halves
    return countLeft + countRight + countCross
```

Now the special logic is inside **countReversePairs**:

```
i = left
j = mid+1

while i <= mid:
    while j <= right and A[i] > 2*A[j]:
        j++
    count += (j - (mid+1))
    i++
```

Then merge as normal.

---

# ⭐ FULL WORKING CODE (C++)

```cpp
class Solution {
public:
    int mergeAndCount(vector<int>& nums, int low, int mid, int high) {
        int cnt = 0;
        int j = mid + 1;

        // Count reverse pairs
        for (int i = low; i <= mid; i++) {
            while (j <= high && nums[i] > 2LL * nums[j]) {
                j++;
            }
            cnt += (j - (mid + 1));
        }

        // Merge both halves
        vector<int> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }

        while (left <= mid) temp.push_back(nums[left++]);
        while (right <= high) temp.push_back(nums[right++]);

        // Copy back
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }

        return cnt;
    }

    int mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high) return 0;

        int mid = (low + high) / 2;

        int cnt = mergeSort(nums, low, mid);
        cnt += mergeSort(nums, mid+1, high);
        cnt += mergeAndCount(nums, low, mid, high);

        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
```

---

# ⭐ DRY RUN EXAMPLE (You Will Understand Completely)

Input:

```
nums = [1, 3, 2, 3, 1]
```

Reverse pairs:
(3,1), (3,1), (2,1), (3,1)

Total = 4

Let me know if you want the **FULL dry run step-by-step diagram** — I will explain with i, j movement line by line.

---

# ⭐ What You Should Remember:

1. Same merge sort as inversion
2. But counting step is different
3. We use two pointers i, j
4. j only moves forward
5. For each i:
   \[
   \text{count} += (j - (mid + 1))
   \]


---
---
---

# **step–by–step full dry run**, exactly like merge sort flow, with a **tree structure**, and at each level I will show:

✔ `low`, `mid`, `high`
✔ values of `i`, `j`
✔ values compared
✔ count updates
✔ merge results

We will do the dry run for:

```
nums = {2, 4, 3, 5, 1}
```

---

# 🌳 **MERGE SORT TREE STRUCTURE**

```
mergeSort(0,4)
│
├── mergeSort(0,2)
│   │
│   ├── mergeSort(0,1)
│   │   │
│   │   ├── mergeSort(0,0) → returns 0
│   │   ├── mergeSort(1,1) → returns 0
│   │   └── merge + countRev(0,0,1)
│   │
│   └── mergeSort(2,2) → returns 0
│
└── mergeSort(3,4)
    │
    ├── mergeSort(3,3) → returns 0
    ├── mergeSort(4,4) → returns 0
    └── merge + countRev(3,3,4)
```

Then we finally merge:

```
mergeSort(0,4):
    left = [0,2]
    right = [3,4]
    merge + countRev(0,2,4)
```

---

# ✅ **NOW FULL DRY RUN WITH VALUES**

---

# 🔥 **1) mergeSort(0,4)**

Split → mid = 2
Call mergeSort(0,2)

---

# 🔥 **2) mergeSort(0,2)**

Split → mid = 1
Call mergeSort(0,1)

---

# 🔥 **3) mergeSort(0,1)**

mid = 0
Call mergeSort(0,0) → 0
Call mergeSort(1,1) → 0

Now call:

```
countRev(nums, 0, 0, 1)
nums = [2,4,3,5,1]
low=0 mid=0 high=1

Left: nums[0] = 2
Right: nums[1] = 4
```

### countRev(0,0,1)

```
i = 0
j = 1

Check while:
nums[i] > 2*nums[j] ?
2 > 2*4 ?  → 2 > 8 → NO
So j stays 1

count += j - (mid+1) = 1 - 1 = 0
```

Count = **0**

---

### MERGE (0,1)

Left = [2]
Right = [4]
Merged = [2,4]

No change.

---

# 🔥 **4) mergeSort(2,2)**

Single element → returns 0

---

# 🔥 Now merge (0,2)

We call:

```
countRev(nums, 0, 1, 2)
nums = [2,4,3,5,1]
Left: [2,4]
Right: [3]
```

### countRev(0,1,2)

```
i = 0, j = 2
nums[0] = 2
nums[2] = 3

Check:
2 > 2*3 → 2 > 6 → NO
j stays 2
count += 0
-----------------------------------

i = 1
nums[1] = 4
nums[2] = 3

Check:
4 > 2*3 → 4 > 6 → NO
j stays 2
count += 0
```

Total count = **0**

---

### MERGE (0,2)

Left sorted: [2,4]
Right sorted: [3]

Merge:

```
Compare 2 vs 3 → take 2
Compare 4 vs 3 → take 3
Take remaining 4
```

Merged result:

```
nums = [2,3,4,5,1]
```

---

# 🔥 **5) mergeSort(3,4)**

mid = 3
Left: mergeSort(3,3) → 0
Right: mergeSort(4,4) → 0

Now countRev(3,3,4)

Left = nums[3] = 5
Right = nums[4] = 1

### countRev(3,3,4)

```
i = 3
j = 4

Check:
nums[3] = 5
nums[4] = 1

5 > 2*1 → 5 > 2 → YES  

So j moves:
j = 5 (out of range)

count += j - (mid+1)
      = 5 - 4
      = 1
```

So count = **1**

---

### MERGE (3,4)

Left = [5]
Right = [1]

Merge result → [1,5]

```
nums = [2,3,4,1,5]
```

---

# 🔥 **6) FINAL MERGE of (0,4)**

Left: [2,3,4]
Right: [1,5]

Call:

```
countRev(nums, 0, 2, 4)
```

### countRev(0,2,4)

```
i = 0, j = 3
nums[0] = 2
nums[3] = 1

Check:
2 > 2*1 ? → 2 > 2 → NO
count += 0
-----------------------------------

i = 1, j = 3
nums[1] = 3
nums[3] = 1

Check:
3 > 2*1 ? → 3 > 2 → YES
j = 4
-----------------------------------

Now j = 4, nums[4] = 5
Check:
3 > 2*5 → 3 > 10 → NO

count += (j - (mid+1)) = 4 - 3 = 1
-----------------------------------

i = 2, j = 4
nums[2] = 4
nums[4] = 5

Check:
4 > 2*5 ? → 4 > 10 → NO

count += (4 - 3) = 1
```

Total = **2**

---

# 🧮 TOTAL COUNT

```
From left merges: 0
From right merges: 1
From final merge: 2
--------------------------------
Total Reverse Pairs = 3
```

---

# FINAL RESULT

```
reverse pairs: 3
```

For array:

```
[2,4,3,5,1]
```

Correct answer is **3**
Pairs are:

1. (4,1)
2. (3,1)
3. (5,1)