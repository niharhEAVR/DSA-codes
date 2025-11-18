Let’s analyze your function **`SecondVarietyOptimal()`** carefully step by step to calculate its **Time Complexity (TC)** and **Space Complexity (SC)** 👇

---

### 🔹 Step 1: Input

```cpp
std::vector<int> &nums
```

Let the size of the vector be `n`.

---

### 🔹 Step 2: Separation into positive and negative arrays

```cpp
for (int i = 0; i < nums.size(); i++)
{
    if (nums[i] < 0)
        neg.push_back(nums[i]);
    else
        pos.push_back(nums[i]);
}
```

✅ **Work done:** iterate through all `n` elements once.
✅ **Time:** `O(n)`
✅ **Space:** Two new vectors (`pos` and `neg`) together hold all elements → **O(n)**

---

### 🔹 Step 3: Rearranging into `ans`

Depending on which side (pos/neg) is larger:

#### Case 1: `pos.size() > neg.size()`

```cpp
for (int i = 0; i < neg.size(); i++)
{
    ans[i * 2] = pos[i];
    ans[i * 2 + 1] = neg[i];
}
int index = neg.size()*2;
for (int i = neg.size(); i < pos.size(); i++)
{
    ans[index++] = pos[i];
}
```

✅ Both loops together go through all elements once — **O(n)** time.
✅ No new array is created (you only modify `ans`, which already exists) → **O(1)** extra space here.

#### Case 2: `neg.size() >= pos.size()`

Similar logic — still **O(n)**.

---

### 🔹 Step 4: Return statement

```cpp
return ans;
```

Returning a vector takes **O(n)** (copy), but if you use **RVO (Return Value Optimization)** (which modern compilers do), this is **O(1)** in practice.

---

## ✅ Final Time and Space Complexity

| Type                      | Step                    | Complexity                     |
| ------------------------- | ----------------------- | ------------------------------ |
| **Time Complexity (TC)**  | Traversal + Rearranging | **O(n) + O(n) = O(2n) ≈ O(n)** |
| **Space Complexity (SC)** | `pos`, `neg`, and `ans` | **O(3n) ≈ O(n)**               |

---

### 🔹 So final answer:

```
Time Complexity  = O(n)
Space Complexity = O(n)
```

---

### 🧠 Optional Optimization Idea:

If you wanted to reduce **extra space**, you could rearrange elements **in-place** using indices without creating `pos` and `neg` vectors — but that would complicate the logic since alternating positives and negatives safely in-place is tricky.

So this implementation is already **optimal and clean** in O(n) time.
