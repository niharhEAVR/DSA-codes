### 🧩 Your code

```cpp
std::vector<int> sum2(std::vector<int> &nums, int k)
{
    int l{-1}, m{-1};
    std::map<int,int> mpp;

    for (int i = 0; i < nums.size(); i++)
    {
        int moreNeed = k - nums[i];
        if(mpp.find(moreNeed) != mpp.end()){
            l = i;
            m = mpp[moreNeed];
            break;
        }
    }
    
    return {l,m};
}
```

---

### ❌ Problem

You never **inserted the current number into the map** inside the loop!
That means `mpp` is always **empty**, so `mpp.find(moreNeed)` will **never succeed** — the `if` condition never runs.

💡 The idea of the two-sum “better” approach is:

* Keep a map storing `{num -> index}` as you go.
* For each `nums[i]`, check if the **complement** (`k - nums[i]`) exists in the map.
* If it does → we found a pair.
* If not → insert `nums[i]` into the map.

---

### ✅ Corrected version

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> sum2(vector<int> &nums, int k)
{
    int l{-1}, m{-1};
    map<int, int> mpp; // {number -> index}

    for (int i = 0; i < nums.size(); i++)
    {
        int moreNeed = k - nums[i];

        // Check if complement is found
        if (mpp.find(moreNeed) != mpp.end())
        {
            l = i;              // current index
            m = mpp[moreNeed];  // index of the complement
            break;
        }

        // Store current number and its index
        mpp[nums[i]] = i;
    }

    return {l, m};
}

void traverse(vector<int> &arr, int n)
{
    cout << "[ ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

int main()
{
    vector<int> nums = {2, 7, 9, 15, 12};
    int target = 14;

    vector<int> arr = sum2(nums, target);
    traverse(arr, arr.size());

    return 0;
}
```

---

### 🔍 Visualization

Let’s walk through it step-by-step for
`nums = {2, 7, 9, 15, 12}` and `k = 14`.

| i | nums[i] | k - nums[i] | mpp before         | Is complement found?       | Action                | mpp after          |
| - | ------- | ----------- | ------------------ | -------------------------- | --------------------- | ------------------ |
| 0 | 2       | 12          | {}                 | ❌ No                       | store 2:0             | {2:0}              |
| 1 | 7       | 7           | {2:0}              | ❌ No                       | store 7:1             | {2:0, 7:1}         |
| 2 | 9       | 5           | {2:0,7:1}          | ❌ No                       | store 9:2             | {2:0,7:1,9:2}      |
| 3 | 15      | -1          | {...}              | ❌ No                       | store 15:3            | {2:0,7:1,9:2,15:3} |
| 4 | 12      | 2           | {2:0,7:1,9:2,15:3} | ✅ YES (2 found at index 0) | Found pair (i=4, j=0) | —                  |

✅ **Answer:** indices `{4, 0}` → nums[4]=12 and nums[0]=2
`12 + 2 = 14`

Output:

```
[ 4 0 ]
```

---

### 🧠 Time and Space Complexity

* **Time:** O(n) — each element visited once.
* **Space:** O(n) — for storing the map.

---
---
---


<br>
<br>
<br>



So yes — you’re correct that while `unordered_map` gives **average O(1)** lookup, in the **worst case** (due to hash collisions), it can degrade to **O(n)** per operation → total **O(n²)** in the worst case.

That’s why there’s another **truly O(n log n)** deterministic solution — which is what you’re now aiming for.
Let’s go through it step by step. 👇

---

## ⚡ True Optimal Approach — Using Sorting + Two Pointers

This method avoids hashing completely and guarantees **O(n log n)** (because of sorting).

---

### 🧠 Concept

1. **Sort the array** first.
2. Use **two pointers**:

   * One pointer `left` starting at the beginning.
   * Another pointer `right` starting at the end.
3. Calculate `sum = nums[left] + nums[right]`:

   * If `sum == k` → found the pair ✅
   * If `sum < k` → move `left++` (need a bigger number)
   * If `sum > k` → move `right--` (need a smaller number)
4. Continue until `left < right`.

---

### 🧩 Example

`nums = [2, 7, 9, 15, 12], k = 14`

Step 1️⃣ → Sort it
`nums = [2, 7, 9, 12, 15]`

| left | right | nums[left] | nums[right] | sum | Action                  |
| ---- | ----- | ---------- | ----------- | --- | ----------------------- |
| 0    | 4     | 2          | 15          | 17  | sum > 14 → move right-- |
| 0    | 3     | 2          | 12          | 14  | ✅ Found pair (2, 12)    |

---

### ⏱️ Complexity

* Sorting → **O(n log n)**
* Two-pointer scan → **O(n)**
  ✅ Total: **O(n log n)**
  🧮 Space: **O(1)** (in-place)

---

### ⚠️ Small Note

If you also need the **original indices**, you must store the `(value, index)` pairs before sorting.
After finding the values that make the pair, retrieve their original indices.

---

So your options are:

| Approach               | Time                  | Space | Notes               |
| ---------------------- | --------------------- | ----- | ------------------- |
| Brute force            | O(n²)                 | O(1)  | check all pairs     |
| Hashing                | O(n) avg, O(n²) worst | O(n)  | fastest in practice |
| Sorting + Two Pointers | O(n log n)            | O(1)  | safe deterministic  |



---
---
---


<br>
<br>
<br>

### Leetcode solution

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size()-1;
        int left{}, right{n};
        sort(nums.begin(), nums.end());
        while(left<right){
            int sum = nums[left]+ nums[right];
            if(sum == target){
                return {left, right};
                break;
            }
            else if(sum<target) left++;
            else right++;
        }
        return {-1,-1};
    }
};
```


Perfect 👏 you’re very close — your thought process is 100% right (two-pointer after sorting),
but there are a few **critical issues** in your code that make it fail on LeetCode.

Let’s go through them carefully.

---

## ❌ Problems in Your Code

### 1️⃣ Lost original indices after sorting

When you call:

```cpp
sort(nums.begin(), nums.end());
```

You’re rearranging the numbers — their **original indices** are lost.
But LeetCode’s **Two Sum** problem asks for the **original indices** of the two numbers that sum to `target`.

➡️ Fix: Before sorting, store `(value, index)` pairs so you can recover the original indices later.

---

### 2️⃣ Wrong pointer movement in the `else` case

You wrote:

```cpp
else right++;
```

That should be:

```cpp
else right--;
```

because:

* If `sum > target`, the total is **too large**,
  so you must move `right` **leftward** to reduce the sum.
  Increasing `right` goes out of bounds.

---

### 3️⃣ The `break` after `return` is useless

`return` already exits the function. The `break` will never execute.

---

## ✅ Correct and Optimal Code

Here’s the **fully working O(n log n)** version that preserves original indices:

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Store (value, index)
        vector<pair<int,int>> arr;
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i});
        }

        // Sort based on value
        sort(arr.begin(), arr.end());

        int left = 0, right = arr.size() - 1;

        while (left < right) {
            int sum = arr[left].first + arr[right].first;

            if (sum == target) {
                return {arr[left].second, arr[right].second};
            } 
            else if (sum < target) {
                left++;
            } 
            else {
                right--;
            }
        }

        return {-1, -1};
    }
};
```

---

## 🧠 Concept Recap (Two-Pointer + Sort)

| Step | Action                                                      |
| ---- | ----------------------------------------------------------- |
| 1    | Create pairs `(value, index)` to preserve original indices. |
| 2    | Sort by value → `O(n log n)`.                               |
| 3    | Use `left` and `right` pointers to find target sum.         |
| 4    | Return the **original indices** (from pairs).               |

---

### 🔍 Example Dry Run

Input:

```cpp
nums = [2, 7, 9, 15, 12]
target = 14
```

After step 1:
`arr = [(2,0), (7,1), (9,2), (15,3), (12,4)]`

After sorting by value:
`arr = [(2,0), (7,1), (9,2), (12,4), (15,3)]`

| left  | right  | sum | Action                 |
| ----- | ------ | --- | ---------------------- |
| 0 (2) | 4 (15) | 17  | sum>target → right--   |
| 0 (2) | 3 (12) | 14  | ✅ Found → return {0,4} |

Output indices correspond to original array positions → correct!

---

✅ **Complexity:**

* Time: `O(n log n)` (due to sort)
* Space: `O(n)` (for storing value-index pairs)
