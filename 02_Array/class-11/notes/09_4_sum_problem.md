# 🟥 What Is the 4-Sum Problem? (Very Simple Explanation)

You are given:

* an array of integers → `nums`
* a target value → `target`

### You must find:

**all combinations of 4 numbers** in the array
whose sum equals the target.

That’s it.

Not 3 numbers.
Not 2 numbers.
**4 numbers.**

---

# 🟦 Example to Understand Correctly

### Suppose:

```
nums = [2, 1, 0, -1, -2, 2]
target = 2
```

We must find **4 numbers** from the array such that their sum = **2**

Some valid sets:

```
[2, 1, 0, -1] → sum = 2
[2, 0, -2, 2] → sum = 2
```

Those are answers.

---

# 🟨 Key Point

We must return **all** such combinations.

And
we must not repeat duplicates.

Example duplicates NOT allowed:

```
[1,2,3,4]
[2,1,4,3]   ← same set, just different order → NOT allowed
```

---

# 🟩 Rewriting the problem in one line

> Find all **unique groups of 4 numbers** in the array that add up to the target.

---

# 🟪 Why is this even a DSA problem?

Because brute force is huge.

To check every possible combination of 4 numbers
takes time:

[
O(n^4)
]

That is very slow.

So we want to reduce the time.

---

# 🟧 Relationship With Previous Problems

### 2-Sum → find 2 numbers = target

### 3-Sum → find 3 numbers = target

### 4-Sum → find 4 numbers = target

Just one extra number being added.

---
---
---



# #️⃣ **Brute Force Approach**

### 💡 Core idea:

Check **every possible combination** of 4 elements from the array,
and see if their sum equals the target.

Meaning:

* pick 1st number
* pick 2nd number
* pick 3rd number
* pick 4th number
  → check the sum

---

# 🔁 How do we generate all combinations?

We use **4 nested loops**.

Why 4?

Because we are choosing **4 numbers**.

Example pseudo logic:

```
for i from 0 to n-1:
  for j from i+1 to n-1:
    for k from j+1 to n-1:
      for l from k+1 to n-1:
         if nums[i] + nums[j] + nums[k] + nums[l] == target:
             store this quadruplet
```

---

# 🕒 Time Complexity

Because there are 4 loops:

[
O(n^4)
]

Super slow for large arrays.

---

# ❌ Problem with brute force

It can also produce **duplicate quadruplets**.

Example:

`[-1, -1, 0, 1]`

could appear multiple times.

So we usually need a **set** (or sorting logic)
to ignore duplicates.

---

# ✔️ Brute Force C++ Code (simple version)

```cpp
vector<vector<int>> fourSumBrute(vector<int>& nums, int target) {
    int n = nums.size();
    set<vector<int>> st;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                for(int l=k+1; l<n; l++){

                    long long sum = 1LL*nums[i] + nums[j] + nums[k] + nums[l];

                    if(sum == target){
                        vector<int> quad = {nums[i], nums[j], nums[k], nums[l]};
                        sort(quad.begin(), quad.end());
                        st.insert(quad);
                    }
                }
            }
        }
    }
    return vector<vector<int>>(st.begin(), st.end());
}
```

---

# 🧠 Why we use `set`?

Because:

* if same quadruplet found twice,
* set automatically removes duplicates

---

# ✔ Final Summary of Brute Force

| Factor   | Answer                          |
| -------- | ------------------------------- |
| Method   | 4 loops, check all combinations |
| Time     | (O(n^4))                        |
| Space    | depends (set for uniqueness)    |
| Good?    | NO (too slow)                   |
| Accuracy | 100%                            |