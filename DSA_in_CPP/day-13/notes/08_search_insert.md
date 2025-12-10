# 🚀 1. SEARCH INSERT POSITION

This is the same as **lower bound**.

### DEFINITION

Return the index where `x` is found,
or where it should be inserted to remain sorted.

So:
\[
\text{Search Insert Position} = \text{Lower Bound}
\]

---

## ⭐ Example

```
arr = [1, 3, 5, 6]
x = 5 → index 2  
x = 2 → insert at index 1  
x = 7 → insert at index 4  
```

---

## 🔥 Implementation

Just return the **lower bound**.

```cpp
int searchInsert(vector<int>& arr, int x) {
    return lowerBound(arr, x);
}
```

---


# 🎯 TIME & SPACE COMPLEXITY

| Operation     | Meaning      | Time     | Space |
| ------------- | ------------ | -------- | ----- |
| Search Insert | first ≥ x    | O(log n) | O(1)  |


---
---
---

Because **Search Insert Position = Lower Bound**.
Exactly same thing.
1-to-1 match.

Let me explain cleanly.

---

# 🔥 WHAT IS SEARCH INSERT POSITION?

You are given a **sorted array** and a **target x**.

You must return:

👉 the index where `x` is FOUND
**OR**
👉 if `x` is NOT FOUND, the index where it should be INSERTED to keep the array sorted.

This is EXACTLY the same meaning as:

### ⭐ **“first index where arr[i] ≥ x”**

Which = **Lower Bound**

---

# 🧠 WHY IS IT SAME?

Think:

* If `x` already exists
  → the first place where `arr[i] ≥ x` is the first `x`.

* If `x` doesn’t exist
  → the first place where `arr[i] ≥ x` is where it should be inserted.

So both are same.

---

# 📌 LET'S SEE EXAMPLES

Array is always sorted.

```
arr = [1, 3, 5, 6]
```

---

## Case 1: x = 5

5 exists at index 2
Search Insert Position = 2
Lower Bound(5) = 2
✔ same

---

## Case 2: x = 2

2 does NOT exist.

Array:

```
[1, 3, 5, 6]
     ↑
Insert 2 here
```

Search Insert Position = 1
Lower Bound(2) = 1
✔ same

---

## Case 3: x = 7

7 bigger than all elements
It should be inserted at end.

Search Insert Position = 4
Lower Bound(7) = 4
✔ same

---

## Case 4: x = 0

0 smaller than all elements
Insert at beginning.

Search Insert Position = 0
Lower Bound(0) = 0
✔ same

---

# ⭐ GENERAL RULE

### Search Insert Position = Lower Bound

Easy.

---

# 🔥 Code

Since you already know lower bound, this is literally the same code:

```cpp
int searchInsert(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}
```

---

# 🎯 Final Conclusion

| Concept                | Meaning                           |
| ---------------------- | --------------------------------- |
| Lower Bound            | first index where arr[i] ≥ x      |
| Search Insert Position | the same: place where x should go |

They are **identical algorithms**.
