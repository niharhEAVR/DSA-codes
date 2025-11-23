# **Optimal Approach of 3Sum**.

---

# 🔥 The Core Optimal Idea

Instead of:

**Nested LOOPS + Binary Search**

we switch to:

**Sorting + Two Pointers**

So for each element `i`:

We take:

* left pointer `l = i + 1`
* right pointer `r = n - 1`

and by moving them intelligently,
we find triplets that sum to zero.

---

---

# 💡 WHY is this optimal?

Because:

### 🔻 Binary Search → O(log n)

gets replaced by

### 🔹 Two-pointer sliding → O(n)

So the inner search becomes LINEAR instead of LOGARITHMIC.

---

---

# 🚀 NEW Time Complexity

\[
O(n^2)
\]

instead of

\[
O(n^2 \log n)
\]

This is a big improvement.

---

---

# 🧠 HOW does it work intuitively?

Sorted array gives **structure**:

Example:

```
[-4, -1, -1, 0, 1, 2]
```

Fix first element:

```
i = 0 → -4
```

We try to find two numbers whose sum is `+4`.

We use:

```
l from left side
r from right side
```

If:

### sum < 0 → increase it

because bigger numbers are on right

### sum > 0 → decrease it

because smaller numbers are on left

### sum == 0 → FOUND a triplet!

---

Driving intuition:

Sorting enables movement with logic.

---

---

# 🛑 Why it is called “optimal”?

Because:

* We avoid extra data structures (like set)
* We avoid binary search
* We avoid duplicate triplet creation
* We detect duplicates earlier
* We keep memory low
* We reduce overall operations

---

---

# 🧾 SPACE COMPLEXITY

Only sorting overhead:

\[
O(\log n)
\]

And output storage.

No hashmap.
No set.
No extra large DS.

That’s why SC is greatly reduced.

---

---

# 🌟 FINAL complexity summary

\[
\boxed{\textbf{Time Complexity = } O(n^2)}
\]

\[
\boxed{\textbf{Space Complexity = } O(\log n)}
\]

(excluding result storage)


---

# ✅ Optimal C++ Code (with duplicate skipping)

```cpp
vector<vector<int>> threeSum(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();

    vector<vector<int>> ans;

    for(int i = 0; i < n; i++)
    {
        // Level-1 duplicate skip
        if(i > 0 && nums[i] == nums[i-1]) 
            continue;

        int l = i + 1;
        int r = n - 1;

        while(l < r)
        {
            long long sum = (long long)nums[i] + nums[l] + nums[r];

            if(sum < 0)
                l++;

            else if(sum > 0)
                r--;

            else   // sum == 0
            {
                ans.push_back({nums[i], nums[l], nums[r]});

                // move both
                l++;
                r--;

                // Level-2 duplicate skip (for l)
                while(l < r && nums[l] == nums[l-1])
                    l++;

                // Level-3 duplicate skip (for r)
                while(l < r && nums[r] == nums[r+1])
                    r--;
            }
        }
    }
    return ans;
}
```

---

---

# 🔥 DRY RUN (very detailed)

Let input be:

```
[-1, 0, 1, 2, -1, -4]
```

---

## Step-1: sort

```
[-4, -1, -1, 0, 1, 2]
```

Indices:

```
 0   1   2  3  4  5
```

---

---

# ---- OUTER LOOP ----

## i = 0 → nums[i] = -4

l = 1
r = 5

### loop:

nums = [-4, -1, -1, 0, 1, 2]

sum = -4 + -1 + 2 = -3 < 0
→ increase l

l = 2

sum = -4 + -1 + 2 = -3 < 0
→ increase l

l = 3

sum = -4 + 0 + 2 = -2 < 0
→ increase l

l = 4

sum = -4 + 1 + 2 = -1 < 0
→ increase l

l = 5 → stops

→ NO triplet

---

---

## i = 1 → nums[i] = -1

l = 2
r = 5

### Round-1:

sum = -1 + -1 + 2 = **0**

FOUND triplet:

```
[-1, -1, 2]
```

store it.

Then:

l++
r--

l becomes 3
r becomes 4

NO duplicates to skip here.

---

### Round-2:

sum = -1 + 0 + 1 = 0

FOUND triplet:

```
[-1, 0, 1]
```

store it

Then:

l++
r--

l = 4
r = 3

loop stops

---

---

## i = 2

nums[i] = -1

BUT:

nums[2] == nums[1]

→ Level-1 skip fires

CONTINUE

---

---

## i = 3 → nums[i] = 0

l = 4
r = 5

sum = 0 + 1 + 2 = 3 > 0

so r--

now r = 4 → loop ends

→ NO triplet here

---

---

## i = 4

nums[i] = 1

l = 5
r = 5

l == r → stop

no triplet

---

---

## i = 5

no l exists → end

---

---

# 🎉 FINAL RESULT

Triplets found:

```
[-1, -1, 2]
[-1, 0, 1]
```

---

---

# 🧠 Why this works perfectly:

✔ sorted
✔ two-pointers
✔ skip duplicates
✔ O(n²)
✔ minimal space

---

---

# ⏳ FINAL COMPLEXITY

\[
\boxed{\text{Time} = O(n^2)}
\]

\[
\boxed{\text{Space} = O(\log n)}
\]

(excluding result vector)

---
---
---
---

# 🚧 WHY duplicates are a threat in optimal approach?

Because while using two-pointers, you may encounter:

* same `nums[i]`
* same `nums[l]`
* same `nums[r]`

This would generate the SAME triplet multiple times.

Example sorted array:

```
[-1, -1, -1, 2, 2]
```

The triplet:

```
[-1, -1, 2]
```

can be found many times
as (i, l, r) move.

This will pollute your output.

So we must defend against that.

---

---

# 🧭 There are **THREE LEVELS** of duplicate skipping

## ⭐ Level-1 Skip

### Skip duplicates for the FIRST element (i)

Because if `nums[i] == nums[i-1]`,
you already processed that number as the first element

So we do:

```
if(i > 0 && nums[i] == nums[i-1]) continue;
```

So each number can be “first” element only ONCE.

---

---

## ⭐ Level-2 Skip

### Skip duplicates on LEFT pointer (l)

When we find a valid triplet:

```
[nums[i], nums[l], nums[r]]
```

We move:

```
l++
r--
```

BUT if the new `nums[l]` is same as old `nums[l-1]`
then we must skip it:

```
while(l < r && nums[l] == nums[l-1]) l++;
```

Because that forms same triplet.

---

---

## ⭐ Level-3 Skip

### Skip duplicates on RIGHT pointer (r)

Same logic:

If `nums[r] == nums[r+1]` after a match,
then we skip:

```
while(l < r && nums[r] == nums[r+1]) r--;
```

Because that also forms same triplet again.

---

---

# 🧠 Example to visualize

Sorted:

```
[-2, -1, -1, -1, 3]
```

Valid triplet = `[-1, -1, 2]`

Pointers move:

```
l → from first -1
r → from last  3
```

After found, moving blindly will produce:

```
[-1, -1, 2]
[-1, -1, 2]
[-1, -1, 2]
```

unless you skip duplicates.

---

---

# 🧨 Without duplicate skipping

You will get:

❌ repeated triplets
❌ wrong output
❌ not optimal

---

---

# 🛡️ With duplicate skipping

You will get:

✔ unique triplets
✔ sorted triplets
✔ correct result
✔ minimum memory
✔ O(n²) optimized

---

---

# 🏁 FINAL CONCEPT SUMMARY

Duplicate skipping is needed on:

### 1) `i` (outer loop)

So you don't repeat same starting value

### 2) `l` after finding a triplet

### 3) `r` after finding a triplet