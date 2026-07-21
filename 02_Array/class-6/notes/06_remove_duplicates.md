### 🧩 Step 1: Understand the Problem

> You’re given a **sorted array** (example: `[0,0,1,1,1,2,2,3,3,4]`),
> You need to remove **duplicate elements** **in-place** — i.e., modify the same array without using extra space — and return the number of **unique elements**.

So the **output** should be:

```
Array becomes: [0,1,2,3,4,_,_,_,_,_]
Return 5
```

(`_` means those positions don’t matter anymore)

---

### 💡 Step 2: Notice the Key Property — “Sorted Array”

When an array is **sorted**, duplicates will **always be next to each other**.
That’s a huge hint!

So:

```
[0,0,1,1,1,2,2,3,3,4]
  ↑ ↑
  | |
 duplicates are side-by-side
```

This means you don’t need to search the whole array for a duplicate — just check **neighboring elements**.

---

### 🧠 Step 3: Think of a Way to Overwrite Duplicates

You can’t “remove” elements from an array directly (in C++, Java, etc.),
but you *can* **overwrite** them.

Let’s imagine you had two pointers:

* **`i`** — tracks the position of the last unique element found
* **`j`** — scans through the array, checking for new elements

---

### 🚶 Step 4: Visualize the Process

Example:
`arr = [0,0,1,1,1,2,2,3,3,4]`

| Step  | i (unique index) | j (current index) | arr[i] | arr[j] | Action                                        |
| ----- | ---------------- | ----------------- | ------ | ------ | --------------------------------------------- |
| Start | 0                | 1                 | 0      | 0      | same → do nothing                             |
| →     | 0                | 2                 | 0      | 1      | new element → move i+1, copy arr[j] to arr[i] |
| →     | 1                | 3                 | 1      | 1      | same → skip                                   |
| →     | 1                | 5                 | 1      | 2      | new element → move i+1, copy arr[j] to arr[i] |
| …     | …                | …                 | …      | …      | …                                             |
| Final | i = 4            | —                 | —      | —      | Done                                          |

Final array:

```
[0,1,2,3,4,2,2,3,3,4]
```

Only the first 5 elements matter (`i + 1 = 5` unique).

---

### ⚙️ Step 5: The Algorithm

1. If array is empty, return 0.
2. Start `i = 0` (first unique).
3. For each `j` from 1 to n-1:

   * If `arr[j] != arr[i]`:

     * Increment `i`
     * Set `arr[i] = arr[j]`
4. Return `i + 1` (the count of unique elements)

---

### 💻 Step 6: Code (C++)

```cpp
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;

    int i = 0;
    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}
```

---

### 🔍 Step 7: Intuitive Summary — How to *Think* of It

When you see:

* “Sorted array” → think **neighbor comparisons**
* “Remove duplicates in-place” → think **two-pointer overwriting**
* “Return number of unique elements” → think **position index + 1**

So the *pattern recognition* is:

```
Sorted array + remove/modify condition  →  Two-pointer approach
```

---
---
---

Let’s analyze the **Time Complexity (TC)** and **Space Complexity (SC)** carefully.

---

## ⚙️ Code Recap

```cpp
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;

    int i = 0;
    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}
```

---

## ⏱️ Time Complexity (TC)

Let’s see what happens step by step:

* You start with `i = 0`
* You run a **single for loop**: `for (int j = 1; j < nums.size(); j++)`
* Inside the loop, only a **constant number of operations** happen each time (`if`, increment, assignment).

✅ So total operations ≈ proportional to the number of elements `n`.

Hence,

> **Time Complexity = O(n)**

---

## 💾 Space Complexity (SC)

Now, what extra memory are we using?

* Just a few integer variables (`i`, `j`) → constant space.
* We are modifying the input array **in-place**, no extra arrays or data structures are used.

✅ So,

> **Space Complexity = O(1)** (constant space)

---

### 🔹 Final Answer

| Complexity Type      | Value    | Explanation                             |
| -------------------- | -------- | --------------------------------------- |
| **Time Complexity**  | **O(n)** | Each element checked once               |
| **Space Complexity** | **O(1)** | Only two variables used, no extra array |
