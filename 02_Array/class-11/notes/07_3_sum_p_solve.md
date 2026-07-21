# ✅ **Brute Force Code (C++ – triple loops)**

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSumBrute(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> result;

    // check ALL triplets
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){

                if(nums[i] + nums[j] + nums[k] == 0){
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    sort(triplet.begin(), triplet.end());
                    result.push_back(triplet);
                }
            }
        }
    }

    // remove duplicate triplets
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());

    return result;
}
```

---

# 🧾 What this code does (in simple steps)

1. pick **i**
2. pick **j after i**
3. pick **k after j**
4. check if sum == 0
5. save that triplet
6. THEN remove duplicates at the end

This is a TRUE brute-force implementation.

### **what is this new thing?**

```cpp
result.erase(unique(result.begin(), result.end()), result.end());
```

This line confuses many beginners — so let me explain it SUPER clearly.

---

# 🧭 Purpose of that line

This line is used to **remove duplicate triplets** from the result array.

Because brute force can insert same triplet many times.

So in short:

> ✔ `unique()` groups duplicates together
> ✔ `erase()` actually deletes them from memory

---

# 🧩 But let’s understand it step-by-step like a beginner

---

# Step 1️⃣ — sort the vector of triplets

```cpp
sort(result.begin(), result.end());
```

Why?

Because duplicates MUST be **next to each other**
otherwise `unique()` cannot detect them.

---

# Step 2️⃣ — use `unique()`

```cpp
unique(result.begin(), result.end());
```

What does `unique()` do?

It does **NOT remove elements physically**.

It only moves **unique values to the front**, and returns an iterator to the new “logical end”.

Example:

Before unique:

```
[ [ -1,-1,2 ], [ -1,-1,2 ], [ -1,0,1 ] ]
```

After `unique()`:

```
[ [ -1,-1,2 ], [ -1,0,1 ], ??? ]
```

The `???` area still exists in memory,
but is ignored.

---

# Step 3️⃣ — remove remaining garbage using erase

```cpp
result.erase(unique(...), result.end());
```

This deletes ALL elements **after the new logical end**.

So we get proper final output.

---

# 📌 Why unique() alone is not enough?

Because:

✔ unique() keeps only unique entries
✘ BUT does NOT delete duplicates physically

So we combine both:

```
erase(unique(...))
```

to fully clean the vector.

---

# ✨ One line meaning

This removes duplicate triplets safely.

---

# 🧠 Very important fact

`unique()` only works correctly if the list is sorted.

Therefore:

1. sort triplets
2. unique()
3. erase()

This is a very common C++ pattern.

---

# 📦 Summary

| Function | What it does             |
| -------- | ------------------------ |
| sort()   | puts duplicates together |
| unique() | compresses duplicates    |
| erase()  | removes them             |


---

# ✅ **Brute Force (3-Sum)**

### **Time Complexity (TC)**

We loop like this:

* outer loop → `n`
* middle loop → `n`
* inner loop → `n`

So total operations:

\[
O(n^3)
\]

✔ **TC = (O(n^3))**

---

# 🧠 **Space Complexity (SC)**

Let’s separate it into 2 parts:

---

## **1️⃣ Auxiliary Space (extra space used while running)**

We are NOT using:

* extra arrays (besides temporary triplet)
* maps
* sets
* pointers

Only constant temporary space.

Therefore:

\[
\text{Auxiliary SC} = O(1)
\]

(because the temp triplet does not scale with input)

---

## **2️⃣ Output Space**

The result vector stores all **valid triplets**.

Worst case, how many triplets can exist?

In worst case:

* every triple sums to zero
  (very unrealistic but mathematically possible)

Then output size could grow to:

\[
O(n^3)
\]

Because we could output every possible triplet.

So:

\[
\text{Output SC} = O(\text{number of triplets}) = O(n^3)
\]

---

# ⭐ Final SC Summary

| Space Type      | Complexity             |
| --------------- | ---------------------- |
| auxiliary space | **O(1)**               |
| output space    | **O(n³)** (worst case) |

---

# 📦 **Why is auxiliary O(1)?**

Because the algorithm itself does NOT store large data structures.
It only runs loops.

Memory does NOT depend on input size.

Only **time** explodes.

---

# 🟦 Final Answer

### **TC = O(n³)**

### **SC (auxiliary) = O(1)**











---

# You thinks:

> SC = O(n²) because there are 2 data structures.

But this is **not correct**, let me explain why.

---

# 🚨 First important rule:

### **Space Complexity DOES NOT count data structures — it counts how their size grows with input.**

Meaning:

If you declare:

```
vector<int> v;
vector<int> res;
```

That does **NOT** automatically mean O(n²).

We only count structures that *grow with input*.

---

# 🧠 Let’s analyze brute force space

### Data structures in brute force code:

1. input array → already exists, NOT counted
2. temp triplet `{a,b,c}` → constant size → O(1)
3. result vector → stores all found triplets

---

# 🌰 Why auxiliary memory is O(1)

Because inside the logic (without output), we only store:

* 3 integers at a time
* maybe some loop counters

None of these grow if input grows.

If array is size 10
OR 100
OR 10000

the extra memory stays same.

So:

\[
\boxed{\text{Auxiliary SC = O(1)}}
\]

---

# 🌋 Why result vector can be huge?

Because it stores the answer.

Worst case scenario:

EVERY triplet is valid.

Meaning:

\[
\binom{n}{3} = O(n^3)
\]

So maximum **answer size = O(n³)**

→ this is OUTPUT space.

---

# ⭐ FINAL SC BREAKDOWN

### ✔ Auxiliary Space Complexity: `O(1)`

This is the real space complexity logic.

### ✔ Output Space Complexity: `O(n³)` in worst case

if you count results inside memory.

---

# 📘 Why NOT O(n²)?

Because:

* no data structure is growing like n²
* no 2D matrix with dimension n × n
* no nested storage proportional to n²

So **O(n²) is not applicable here**.

---

# 🧾 KEY LEARNING

Space complexity is about **growth**, not about **count of variables**.



---
---
---

<br>
<br>
<br>


# ⭐ What is the idea behind the *Better Approach*?

**→ FIX 2 numbers, and FIND the 3rd using binary search**

This is the core idea.

We don't blindly check k.

---

# 🌱 What must change?

Instead of:

pick i
pick j
pick k from scratch

We do:

pick i
pick j
then **SEARCH** for the required 3rd value

---

---

# 🎯 Key Thought

If

\[
nums[i] + nums[j] + nums[k] = 0
\]

then

\[
nums[k] = -(nums[i] + nums[j])
\]

So 3rd value is NOT unknown anymore.

It is FIXED mathematically.

This is the core improvement.

---

---

# 🚀 How to search faster?

Sort the array.

Then searching becomes fast:

→ binary search

Binary search speed:

\[
O(\log n)
\]

---

---

# 🔥 Combining the loops

i → loop
j → loop
k → found via binary search

Complexity becomes:

\[
O(n^2 \log n)
\]

→ MUCH faster than brute

---






## **Time Complexity** and **Space Complexity** for the **entire BETTER approach** (the one using sorting + 2 nested loops + binary search).

Remember, the **better approach algorithm steps** are:

1. Sort the array
2. Run two nested loops
3. For each pair, binary search the 3rd element
4. Store valid triplets in a set
5. Return answer

Let’s analyze each part step-by-step.

---

# ✅ 1) Sorting Step

TC:
\[
O(n \log n)
\]

SC:
\[
O(\log n)
\]
(recursion stack)

---

# ✅ 2) Two nested loops

Indexes: `i` and `j`

So:

\[
O(n^2)
\]

---

# ✅ 3) Binary search inside nested loops

Binary search takes:

\[
O(\log n)
\]

And it runs for each pair.

So this becomes:

\[
O(n^2 \log n)
\]

---

# 👍 Combined TC

We combine everything:

### Sorting

= (O(n \log n))

### Nested loops + binary search

= (O(n^2 \log n))

Total:

\[
\boxed{O(n^2 \log n)}
\]

Because when combining, the highest dominating term stays.

So:

\[
\boxed{\textbf{Time Complexity = } O(n^2 \log n)}
\]

---

---

# 📦 Space Complexity Analysis

The main extra space used in better approach:

✔ recursion stack from sorting → (O(\log n))

✔ result set (worst-case stores many triplets)

Worst case output size:

Triplets can be **O(n²)** in the worst case.

So:

\[
\boxed{O(n^2)}
\]

(only for storing results—NOT algorithm overhead)

There is NO extra heavy array used.

---

So final answer:

---

# ⭐ FINAL

\[
\boxed{\textbf{Time Complexity = } O(n^2 \log n)}
\]

\[
\boxed{\textbf{Space Complexity = } O(n^2)}
\]

---

# 📌 Why SC is (O(n^2))?

Because worst case you might store LOTS of triplets in the answer.

Example:

array all zeros:

```
[0,0,0,0,0,0,0,0....]
```

Every combination is valid.

---

# 🧠 Summary in Simple English

Brute force tries ALL triplets.

Better approach does:

1. sort array
2. pick first number
3. pick second number
4. compute what 3rd number SHOULD be
5. use **binary search** to check if it exists

This is **mathematically intelligent**, not blind.

---

---

# ⭐ Final Notes

* Better approach = logically smarter brute-force
* Still NOT optimal
* Still has duplicate issues
* Still not perfect

BUT:
MUCH faster than brute force.


---
---



# ✅ **Better Approach — C++ Code (Sorting + Binary Search)**

### **TC = O(n² log n)**

### **SC = O(1) Auxiliary**

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSumBetter(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> result;

    sort(nums.begin(), nums.end());  // step 1

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){

            int third = -(nums[i] + nums[j]);  // required 3rd value

            // binary search in the remaining array
            if(binary_search(nums.begin() + j + 1, nums.end(), third)){
                vector<int> triplet = {nums[i], nums[j], third};
                result.push_back(triplet);
            }
        }
    }

    // remove duplicates
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());

    return result;
}
```

---

# 🔍 Notes

### ✔ Sorting improves search speed

### ✔ Binary search finds 3rd element fast

### ✔ Still 2 loops, not 3

### ✔ MUCH better than O(n³)

---

# ⏳ Time Complexity

Sorting: `O(n log n)`
2 loops: `O(n²)`
Binary search inside: `O(log n)`

\[
\boxed{O(n^2 \log n)}
\]

---

# 📦 Space Complexity

Auxiliary space:

→ no extra structures used

\[
\boxed{O(1)}
\]

Output space → `O(count of triplets)` (as always)

---
























---

# 🔹 NEW THING #1

## `sort(nums.begin(), nums.end())`

This line sorts the array.

Why?

Because binary search ONLY works on sorted arrays.

Sorting makes numbers placed in order like this:

Before:

```
4, -2, 1, 0
```

After sorting:

```
-2, 0, 1, 4
```

---

---

# 🔹 NEW THING #2

## `int third = -(nums[i] + nums[j]);`

Why do we calculate this?

Because:

\[
nums[i] + nums[j] + nums[k] = 0
\]

rearranged:

\[
nums[k] = -(nums[i] + nums[j])
\]

So instead of searching everything,
we compute EXACTALLY what we need.

---

---

# 🔹 NEW THING #3

## `binary_search(nums.begin() + j + 1, nums.end(), third)`

This part:

```
nums.begin() + j + 1
```

Means: we only search AFTER `j`.

Why?

Because:

* i is fixed
* j is fixed
* k must be after j

Else duplicates and unnecessary checks happen.

Binary search will return:

* `true`   → if found
* `false` → if not found

---
---
---

<br>
<br>
<br>

