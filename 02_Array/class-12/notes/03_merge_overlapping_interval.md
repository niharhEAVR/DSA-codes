# ⭐ Merge Overlapping Intervals

---

# 🟧 **1. What is an “interval”?**

An interval is just a **range** with a start and an end.

Examples:

```
[1, 3]
[2, 6]
[8, 10]
[15, 18]
```

Each interval means:

* it starts at some position
* and ends at some position

Like a time slot:

* [1, 3] → a meeting from 1 pm to 3 pm
* [2, 6] → a meeting from 2 pm to 6 pm

---

# 🟥 **2. What does “overlapping” mean?**

Two intervals **overlap** when they “touch” or “cover” each other.

Example:

```
[1, 3] and [2, 6]
```

These overlap because:

* The 2–6 meeting starts **before** 1–3 meeting ended.

Visually:

```
1-----3
   2---------6
```

They overlap.

### What if intervals do NOT overlap?

Example:

```
[1, 3] and [8, 10]
```

Visually:

```
1-----3           8----10
```

These do NOT overlap.

---

# 🟩 **3. What does “merge intervals” mean?**

If two intervals overlap, we **join** (merge) them into one big interval.

For example:

```
[1, 3] and [2, 6]
```

Merged interval becomes:

```
[1, 6]
```

Why?

* The start of the merged interval = earliest start = min(1, 2)
* The end of the merged interval = latest end = max(3, 6)

So:

```
min(1,2) = 1  
max(3,6) = 6  
→ [1,6]
```

---

# 🟦 **4. Why do we need to merge at all?**

Because sometimes intervals represent things like:

* meetings
* bookings
* reserved slots
* events
* occupied time ranges
* continuous ranges in math

When two times overlap, we want one cleaner combined interval.

---

# 🟪 **5. FULL VISUALIZATION OF MERGING**

Given:

```
intervals = [[1,3], [2,6], [8,10], [15,18]]
```

Step 1 → **Sort by start**
Already sorted.

Step 2 → Start merging like a train moving forward.

---

### 🔵 Start from the first one:

Current merged interval = `[1,3]`

---

### 🔵 Next: interval `[2,6]`

Does `[2,6]` overlap with `[1,3]`?

Check:

```
2 <= 3
```

YES, it overlaps.

So merge:

```
[1,3] and [2,6] → [1,6]
```

Current merged interval becomes:

```
[1,6]
```

---

### 🔵 Next: interval `[8,10]`

Check if overlaps with `[1,6]`:

```
8 <= 6 ?  → NO
```

So they do NOT overlap.
We **push** `[1,6]` into the answer list
And **move to next** interval.

Now current merged interval = `[8,10]`

---

### 🔵 Next: `[15,18]`

Does it overlap with `[8,10]`?

```
15 <= 10? → NO
```

So no overlap.

Push `[8,10]`
Current becomes `[15,18]`

---

### ⭐ Final merged list:

```
[1, 6]
[8, 10]
[15, 18]
```

---

# 🟧 **6. Simple logic of merging (concept only)**

To merge interval A = `[start1, end1]`
with B = `[start2, end2]`

They overlap if:

\[
\text{start2} \le \text{end1}
\]

If overlap:

\[
\text{mergedStart} = \min(start1, start2)
\]
\[
\text{mergedEnd}   = \max(end1, end2)
\]

If NOT overlap:

→ push old interval
→ start a new one

---

# 🟩 **7. Why sorting is needed?**

Because merging only works if intervals are in order.

Unsorted example:

```
[8,10], [1,3], [2,6]
```

If you don't sort, you cannot see overlap easily.

Sorted:

```
[1,3], [2,6], [8,10]
```

Now overlap is obvious.

---

# 🟦 **8. The big idea in ONE LINE**

### “Walk through the intervals. If the next one overlaps with the current one, merge them. If not, push the current one and move on.”

---
---
---
---


# 🔥 **Merge Overlapping Intervals — BRUTE FORCE**

## ✅ **Problem (Simple Words)**

You are given a list of intervals like:

```
[1,3], [2,6], [8,10], [9,12]
```

Each interval means:
**start = first number**, **end = second number**.

Two intervals **overlap** if their ranges touch each other. Example:
`[1,3]` overlaps `[2,6]` because 2–3 is common.

The goal is to **merge** overlapping intervals:

```
[1,3] + [2,6] -> [1,6]
[8,10] + [9,12] -> [8,12]
```

---

# 🧠 **BRUTE FORCE APPROACH**

### 👉 **Idea**

Check **every pair** of intervals and manually merge the ones that overlap.

This is like comparing everyone with everyone else.

### ⚙️ **Steps**

1. Take each interval.
2. Compare it with all other intervals.
3. If they overlap → merge them.
4. Repeat many times until nothing more merges.

### ❗ Why this is brute?

Because you are repeatedly merging again and again without efficiency.

---

# 📘 **How to check if two intervals overlap?**

Two intervals:

```
[a, b] and [c, d]
```

They overlap **if and only if**:

\[
\text{max}(a, c) \le \text{min}(b, d)
\]

Simple version:

```
start of one <= end of the other
AND
start of other <= end of the first
```

Example:
`[1,3]` and `[2,6]`

Check:

```
2 <= 3 AND 1 <= 6  → yes overlap
```

---

# 🧪 **Brute Example**

Input:

```
[1,3], [2,6], [8,10], [9,12]
```

Compare everything with everything:

1. Compare [1,3] and [2,6] → overlap → merge → [1,6]
2. Compare [8,10] and [9,12] → overlap → merge → [8,12]

Other comparisons don't overlap.

Final answer:

```
[1,6], [8,12]
```

---

# 🕒 **Time Complexity**

### ❗ Checking every pair: O(N²)

Because for N intervals, we compare:

```
(0 with 1,2,3,...)
(1 with 2,3,4,...)
...
```

Total ~
\[
\frac{n(n-1)}{2} \approx O(n^2)
\]

### 🗂️ Space Complexity

```
O(N)  
```

Because we may store merged intervals separately.

---

# 💻 **Brute Code (C++ style, simple)**

```cpp
vector<vector<int>> bruteMerge(vector<vector<int>> intervals)
{
    int n = intervals.size();
    vector<bool> merged(n, false); 
    vector<vector<int>> result;

    for (int i = 0; i < n; i++)
    {
        if (merged[i]) continue;

        int start = intervals[i][0];
        int end = intervals[i][1];

        for (int j = 0; j < n; j++)
        {
            if (i == j || merged[j]) continue;

            int s = intervals[j][0];
            int e = intervals[j][1];

            // Check overlap
            if (max(start, s) <= min(end, e))
            {
                // merge
                start = min(start, s);
                end = max(end, e);
                merged[j] = true;
            }
        }

        merged[i] = true;
        result.push_back({start, end});
    }

    return result;
}
```

# Problem is Brute is not efficient solution, because that it will fail for some cases

---
---
---
---



# ⭐ **BETTER APPROACH — SORT FIRST, THEN MERGE**

## ❓ Why do we sort first?

If the intervals are sorted by starting time, they appear in a **nice line**:

Example unsorted:

```
[8,10], [1,3], [9,12], [2,6]
```

Sorted by start:

```
[1,3], [2,6], [8,10], [9,12]
```

Now you can see clearly:

```
[1,3] overlaps [2,6]
[8,10] overlaps [9,12]
```

This sorting step makes the problem very easy.

---

# 🎬 **Better Approach — Step-by-step Movie**

### We sort the intervals by their **start** value.

Example Input:

```
[1,3], [2,6], [8,10], [9,12]
```

Already sorted. If not, we sort.

---

### ✔️ Step 1: Start with the first interval

Let’s take a "current interval":

```
current_start = 1  
current_end   = 3
```

---

### ✔️ Step 2: Look at the next interval → [2,6]

Check if it overlaps.

How do we check?
Very simple:

```
If next.start <= current_end → overlap
```

Check:

```
2 <= 3 → yes overlap
```

So merge:

```
new_start = 1
new_end   = max(3,6) = 6
```

Current interval becomes:

```
[1,6]
```

---

### ✔️ Step 3: Move to next interval → [8,10]

Check overlap:

```
8 <= 6 ? → NO
```

So we **finalize** the previous interval:

```
Add [1,6] to result
```

And now set current interval to:

```
[8,10]
```

---

### ✔️ Step 4: Next interval → [9,12]

Check overlap:

```
9 <= 10 → yes overlap
```

Merge:

```
new_end = max(10,12) = 12
```

Current interval becomes:

```
[8,12]
```

---

### ✔️ Step 5: No more intervals → add last one to result

Final result:

```
[1,6], [8,12]
```

---

# 🧠 **Why is this approach better?**

Because after sorting, you only need **one pass** through the intervals.

This eliminates checking every pair (which was O(N²)).

Now it's:

* Sorting: O(N log N)
* Merging: O(N)

Total:

\[
O(n \log n)
\]

Much better than:

\[
O(n^2)
\]

---

# 📦 **Space Complexity**

If you store output separately:

```
O(N)
```

If you merge in-place:

```
O(1) extra
```

---

# 💻 **Better Approach Code (super simple C++)**

```cpp
vector<vector<int>> mergeBetter(vector<vector<int>> intervals)
{
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> result;

    int start = intervals[0][0];
    int end   = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++)
    {
        int s = intervals[i][0];
        int e = intervals[i][1];

        if (s <= end)
        {
            // merge
            end = max(end, e);
        }
        else
        {
            // no overlap
            result.push_back({start, end});
            start = s;
            end = e;
        }
    }

    // add last interval
    result.push_back({start, end});
    return result;
}
```

---
---
---
---


# ⭐ OPTIMAL APPROACH

### (Same logic as Better — but space is improved)

---

# 🧠 **Key Idea**

In the **Better approach**, we used:

```
vector<vector<int>> result;
```

This is extra space = O(N).

In the **Optimal approach**, we try to avoid using extra space.

So:

### ✔️ We sort the array

### ✔️ We merge intervals **inside the same array**

### ✔️ We use only an integer `index` to track the position

No extra big vector.

---

# 🎬 **Why sorting is still required?**

Sorting makes overlapping intervals appear next to each other:

```
[1,3] [2,6] [8,10] [9,12]
```

So merging becomes linear.

---

# 🧠 **How is it different from Better?**

### Better:

* Uses a separate result list
* Merges into that list

### Optimal:

* Merges into the *same* intervals array
* Uses a position pointer `index`

---

# 🎥 Let’s visualize the Optimal Approach

Input:

```
[1,3], [2,6], [8,10], [9,12]
```

Sorted:

```
[1,3], [2,6], [8,10], [9,12]
```

### `index = 0`

This means:
intervals[0] is currently:

```
[1,3]
```

This is our **merged interval holder**.

---

# 🔄 Step through

## Step 1

Compare `[1,3]` with `[2,6]`:

```
2 <= 3 → overlap
```

So merge **inside** intervals array:

```
intervals[0] = [1, max(3,6)] = [1,6]
```

Now internal array looks like:

```
[1,6], [2,6], [8,10], [9,12]
```

*(Only the first one matters)*

---

## Step 2

Now move to next interval: `[8,10]`

Check overlap:

```
8 <= 6 ? → NO
```

So increment index:

```
index = 1
```

And write new interval there:

```
intervals[1] = [8,10]
```

Now array:

```
[1,6], [8,10], [8,10], [9,12]
```

---

## Step 3

Check `[8,10]` with `[9,12]`:

```
9 <= 10 → overlap
```

Merge into same place:

```
intervals[1] = [8, max(10,12)] = [8,12]
```

Final array:

```
[1,6], [8,12], [8,10], [9,12]
```

But only first `index+1` (0 and 1) are valid.

---

# 🎉 Final Output

```
[1,6]
[8,12]
```

---

# 🧮 **Optimal Time & Space Complexity**

### Time:

* Sorting: O(N log N)
* One pass merge: O(N)

Total:
\[
O(n \log n)
\]

### Space:

\[
O(1) \text{ extra}
\]
(because merging is done *inside* the array)

---

# 💻 Optimal C++ Code (clean & easy)

```cpp
vector<vector<int>> mergeOptimal(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());

    int index = 0; // this tracks merged intervals

    for (int i = 1; i < intervals.size(); i++)
    {
        // overlap condition
        if (intervals[i][0] <= intervals[index][1])
        {
            // merge into same place
            intervals[index][1] = max(intervals[index][1], intervals[i][1]);
        }
        else
        {
            // no overlap -> move to next position
            index++;
            intervals[index] = intervals[i];
        }
    }

    // return only merged part (index+1 intervals)
    return vector<vector<int>>(intervals.begin(), intervals.begin() + index + 1);
}
```

---

# 🎯 Summary: All 3 Approaches

| Approach    | Idea                     | Time       | Space    |
| ----------- | ------------------------ | ---------- | -------- |
| **Brute**   | Check every pair         | O(N²)      | O(N)     |
| **Better**  | Sort + use result vector | O(N log N) | O(N)     |
| **Optimal** | Sort + merge in-place    | O(N log N) | **O(1)** |



---
---
---


# 🌟 Dry Run Example (Optimal Approach)

Input intervals:

```
[5,7], [1,3], [2,4], [6,9], [10,12], [11,15]
```

---

# 🔹 Step 0 — Sort the intervals

Sort by the starting value:

```
[1,3], [2,4], [5,7], [6,9], [10,12], [11,15]
```

We will work on this sorted array.

---

# 🔹 Step 1 — Set index = 0

This means the **current merged interval** is:

```
index = 0 → [1,3]
```

This is our “main merge box.”

---

# 🔥 Step-by-Step Dry Run

---

## ✔️ i = 1 → interval = [2,4]

Check overlap with intervals[index] = [1,3]:

```
2 <= 3  → YES overlap
```

So merge:

```
intervals[0][1] = max(3,4) = 4
```

Now array becomes:

```
[1,4], [2,4], [5,7], [6,9], [10,12], [11,15]
```

Only `intervals[0]` matters.

---

## ✔️ i = 2 → interval = [5,7]

Check overlap with intervals[index] = [1,4]:

```
5 <= 4 → NO overlap
```

So we move the index forward:

```
index = 1
intervals[1] = [5,7]
```

Array now:

```
[1,4], [5,7], [5,7], [6,9], [10,12], [11,15]
```

(Only first 2 are meaningful)

---

## ✔️ i = 3 → interval = [6,9]

Check overlap with intervals[index] = [5,7]:

```
6 <= 7 → YES overlap
```

So merge:

```
intervals[1][1] = max(7,9) = 9
```

Array now:

```
[1,4], [5,9], [5,7], [6,9], [10,12], [11,15]
```

Again, only up to index=1 matters.

---

## ✔️ i = 4 → interval = [10,12]

Check overlap with intervals[index] = [5,9]:

```
10 <= 9 → NO overlap
```

Move index forward:

```
index = 2
intervals[2] = [10,12]
```

Array becomes:

```
[1,4], [5,9], [10,12], [6,9], [10,12], [11,15]
```

(Only first 3 meaningful)

---

## ✔️ i = 5 → interval = [11,15]

Check overlap with intervals[index] = [10,12]:

```
11 <= 12 → YES overlap
```

Merge:

```
intervals[2][1] = max(12,15) = 15
```

Final array (logical):

```
[1,4], [5,9], [10,15], [6,9], [10,12], [11,15]
```

Only first **index+1 = 3** intervals are valid.

---

# 🎉 FINAL MERGED OUTPUT

```
[1,4]
[5,9]
[10,15]
```

---

# 🧠 Why only index+1 elements matter?

Because the first part of the array now contains all merged intervals in-place:

* index=0 → first merged interval
* index=1 → second
* index=2 → third
* Everything else is junk/not needed

So output = intervals[0 ... index].
