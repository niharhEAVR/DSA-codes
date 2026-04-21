## 🧩 Problem Name: **Longest Consecutive Sequence in an Array**

---

### 🔍 Problem Statement

You are given an **unsorted array** of integers, say:

```cpp
nums = [100, 4, 200, 1, 3, 2]
```

You need to **find the length** of the **longest sequence of consecutive numbers** that appear in the array — but **the sequence doesn’t need to be contiguous in the array**.

So for the above array:

* The consecutive numbers are `[1, 2, 3, 4]` → length = 4
  ✅ That’s the answer.

---

### ⚠️ Important Clarifications

1. **Unsorted array** means numbers can be in any order.
2. You don’t have to sort the array in your approach (though brute force might).
3. A “consecutive sequence” means numbers that differ by exactly **1**.
   Example: `[2, 3, 4, 5]` is consecutive.
   `[2, 4, 5]` is not.
4. You only return **length**, not the actual sequence.

---

### 🎯 Goal

Find the **maximum length** of such consecutive elements.

---

### 🧠 Example Walkthroughs

#### Example 1:

```
nums = [100, 4, 200, 1, 3, 2]
```

✅ Longest consecutive numbers = `[1, 2, 3, 4]`
⏩ Answer = 4

#### Example 2:

```
nums = [0,3,7,2,5,8,4,6,0,1]
```

✅ Longest consecutive numbers = `[0,1,2,3,4,5,6,7,8]`
⏩ Answer = 9

---

### 🧩 Step 1: Understand What’s Being Asked

We’re not looking for **subarray** — we’re looking for **subsequence** (not necessarily in order).
We only care about consecutive integer values.

So our main task is:
➡️ *Find the length of the largest group of numbers that form a continuous range.*

---

### 💭 Step 2: Think about Naive (Brute Force) Intuition

Let’s reason from scratch:

* For every number in the array, check if the next consecutive number exists.
* Count how long that sequence goes before breaking.
* Keep track of the maximum count.

Now think — if you have to check if a number exists again and again, what’s the time complexity?
If you do it with nested loops, that’s **O(n²)**.

That’s our **brute-force thinking**, but we won’t jump there yet — first, we’ll build logic.

---

### 🧩 Step 3: How You Can Start Your Approach (without coding)

Here’s how you should **approach** the problem yourself:

#### 🧠 Step-by-step thinking plan:

1. **Rephrase**: “I want to find the longest streak of consecutive numbers that exist in the array.”
2. **Think about lookup**: “If I need to check if `x+1` exists, what’s the fastest way?”
   → Maybe a **set** (O(1) lookup time).
3. **Find the start of sequences**:

   * If a number has **no smaller neighbor (`num - 1`)**, it could be the **start** of a new sequence.
4. **Expand from that start**:

   * Keep checking for `num+1, num+2, ...` until it breaks.
5. **Count** how long it goes, and store the max length.

---

### ⚙️ Step 4: What You Should Try by Yourself

Before I give even a hint of implementation, try to **think in terms of logic like this**:

* How can I detect that a number starts a new sequence?
* How can I efficiently count consecutive numbers without sorting the array?
* How can I ensure I don’t count the same sequence multiple times?

---
---
---




## 🪜 Step-by-Step Brute Force Thinking

**Goal:** Find the length of the longest consecutive sequence in the array.

Let’s take an example:

```cpp
nums = [100, 4, 200, 1, 3, 2]
```

---

### 🧠 Step 1: Understand What We Need

We want to find consecutive sequences like:

* `[1, 2, 3, 4]`
* `[100]`
* `[200]`

and get the **maximum length** among them.
So final output → `4`.

---

### 🔍 Step 2: Start with the Simplest Idea

You think:

> “Okay, I’ll take each element one by one and see how long a consecutive sequence can start from that number.”

That’s literally the **brute-force** definition — try everything.

---

### 🧩 Step 3: Visualizing the Process

Let’s go element by element.

#### 🧩 For `100`

We check:

* Is `101` in the array? ❌ No → sequence length = 1

#### 🧩 For `4`

We check:

* Is `5` in the array? ❌ No → sequence length = 1

#### 🧩 For `200`

We check:

* Is `201` in the array? ❌ No → sequence length = 1

#### 🧩 For `1`

We check:

* Is `2` in array? ✅ Yes
* Is `3` in array? ✅ Yes
* Is `4` in array? ✅ Yes
* Is `5` in array? ❌ No
  So sequence = `[1,2,3,4]` → length = 4 ✅

#### 🧩 For `3` or `2`

You’ll end up checking again similar numbers (redundant checks).

---

### 🔁 Step 4: How You’d Implement It (Conceptually)

1. Initialize `maxLength = 1`
2. For every number `nums[i]` in array:

   * Let `count = 1`
   * Let `current = nums[i]`
   * While `(current + 1)` exists in the array:

     * Increase count
     * Move `current` forward
   * Update `maxLength = max(maxLength, count)`

---

### ⏱️ Step 5: Analyze Time Complexity

Now — let’s think about how slow this is.

* For each element (n elements)
* You might search for `(current + 1)` using something like `array.contains()`
* In an unsorted array, searching takes **O(n)** time
* So, **O(n) for each of n elements** → **O(n²)** total.

So **time complexity = O(n²)**
**space complexity = O(1)** (we’re not using extra data structures)

---

### 🧩 Step 6: Example Dry Run (step-by-step)

Array: `[100, 4, 200, 1, 3, 2]`

| i | current | Consecutive Found | Length | Max Length |
| - | ------- | ----------------- | ------ | ---------- |
| 0 | 100     | 101 ❌             | 1      | 1          |
| 1 | 4       | 5 ❌               | 1      | 1          |
| 2 | 200     | 201 ❌             | 1      | 1          |
| 3 | 1       | 2✅, 3✅, 4✅        | 4      | 4          |
| 4 | 3       | 4✅                | 2      | 4          |
| 5 | 2       | 3✅, 4✅            | 3      | 4          |

✅ Final `maxLength = 4`

---

### ⚠️ Step 7: Weakness of Brute Force

* Repeated checks — for example, when checking `2` or `3`, you re-do the same sequence work already done for `1`.
* Each “does number exist?” is costly since array is unsorted.

That’s why it’s **O(n²)**.

---

### 🧭 Step 8: Next Direction (Thinking Ahead)

Now, if you want to **optimize**, your next thoughts should be:

> “How can I check if a number exists faster?”
> → Use a **hash set** for O(1) lookups.

> “How can I avoid rechecking the same sequence again and again?”
> → Only start counting if the **previous number (num−1)** doesn’t exist.

That thinking leads us toward the **optimal approach**, which runs in **O(n)** time.


---
---
---
---





<br>
<br>
<br>


## 🧠 Problem Recap

We’re given an unsorted array of integers —
we need to find the **length of the longest consecutive sequence** (numbers appearing one after another in increasing order, e.g. `1,2,3,4`).

> Example:
> Input: `nums = [100, 4, 200, 1, 3, 2]`
> Output: `4` → because the longest consecutive sequence is `[1, 2, 3, 4]`.

---

## 🚶 Step-by-Step Thinking for the **Optimal Approach**

### Step 1️⃣ — Identify the problem in the better approach

Your **better approach** probably sorted the array first (`O(N log N)`) and then traversed it once to find the longest sequence, right?

That’s fine, but we can do **better** because sorting takes `O(N log N)`.

Our **goal**: do it in **O(N)** using a **HashSet**.

---

### Step 2️⃣ — HashSet idea 💡

We use a **HashSet** because:

* It lets us check if a number exists in **O(1)**.
* We can store all numbers first and then check sequences directly.

---

### Step 3️⃣ — Core Observation 🔍

If you are at a number `x`:

* You only want to **start counting a sequence** if **`x-1` doesn’t exist** in the array.
  (Because if `x-1` exists, that means this `x` is *not the start* of a sequence — the sequence started earlier.)

So:

* If `x-1` not in set → this is **start of a sequence**.
* Then, check how long that sequence goes by checking `x+1`, `x+2`, `x+3`, ... etc.

---

### Step 4️⃣ — Stepwise Logic

1. Put all elements into a `set` → `O(N)`
2. Initialize a variable `longest = 0`
3. Loop through each number `num` in the set:

   * If `num - 1` not in set:

     * It’s the **start** of a new sequence.
     * Now, initialize `currentNum = num`
     * Count how long the sequence continues (`currentNum + 1`, `currentNum + 2`, ...)
       while they exist in the set.
     * Update `longest` if this sequence is longer.
4. Return `longest`

---

### Step 5️⃣ — Example Dry Run

Input: `[100, 4, 200, 1, 3, 2]`
Set = `{100, 4, 200, 1, 3, 2}`

| num | num-1 in set? | Sequence counted | Length |
| --- | ------------- | ---------------- | ------ |
| 100 | ❌             | [100]            | 1      |
| 4   | ✅ (3 exists)  | skip             | -      |
| 200 | ❌             | [200]            | 1      |
| 1   | ❌             | [1, 2, 3, 4]     | 4 ✅    |
| 3   | ✅ (2 exists)  | skip             | -      |
| 2   | ✅ (1 exists)  | skip             | -      |

Max length = **4**

---

### Step 6️⃣ — Time & Space Complexity

✅ **Time Complexity**: `O(N)`
(Each number is visited only once, and lookups in a HashSet are O(1))

✅ **Space Complexity**: `O(N)`
(for storing elements in HashSet)

---
---
---
---




## 🧩 Problem Recap

> Given an unsorted array `nums`, find the length of the longest consecutive sequence.

Example:
`nums = [100, 4, 200, 1, 3, 2]` → Output = `4` (sequence = `[1,2,3,4]`)

---

## ✅ Optimal Approach — C++ Code + Full Explanation

```cpp
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    // Step 1: Edge case — empty array
    if (nums.empty()) return 0;

    // Step 2: Store all numbers in a HashSet
    unordered_set<int> s;
    for (int num : nums)
        s.insert(num);

    int longest = 0; // this will store our final answer

    // Step 3: Traverse every number
    for (int num : s) {
        // Step 3.1: Only start if it’s the beginning of a sequence
        if (s.find(num - 1) == s.end()) {
            int currentNum = num;  // start of sequence
            int count = 1;         // sequence length counter

            // Step 3.2: Keep checking the next consecutive numbers
            while (s.find(currentNum + 1) != s.end()) {
                currentNum++;
                count++;
            }

            // Step 3.3: Update longest if current sequence is longer
            longest = max(longest, count);
        }
    }

    return longest;
}
```

---

## 🧠 Step-by-Step Dry Run

Let’s take:

```cpp
nums = [100, 4, 200, 1, 3, 2];
```

### Step 1: Store in HashSet

`s = {100, 4, 200, 1, 3, 2}`
Lookups now are O(1).

---

### Step 2: Loop starts

Let’s iterate over each `num` in the set.

#### 🧩 num = 100

* Check if `99` is in set → ❌ (not found)
  → So 100 is start of a sequence
* Now check next numbers:

  * `101` not found → stop
    → count = 1
    → longest = max(0, 1) = 1

---

#### 🧩 num = 4

* `3` exists → skip (because 4 is not the start)

---

#### 🧩 num = 200

* `199` not found → start new sequence
* `201` not found → stop
  → count = 1
  → longest = max(1, 1) = 1

---

#### 🧩 num = 1

* `0` not found → start new sequence
* `2` found → count = 2
* `3` found → count = 3
* `4` found → count = 4
* `5` not found → stop
  → longest = max(1, 4) = 4 ✅

---

#### 🧩 num = 3 → skipped (2 exists)

#### 🧩 num = 2 → skipped (1 exists)

---

✅ Final Answer → **4**

---

## 🧮 Time & Space Complexity

| Operation                    | Complexity             |
| ---------------------------- | ---------------------- |
| Inserting into set           | O(N)                   |
| Checking consecutive numbers | O(N) total             |
| **Overall Time**             | **O(N)**               |
| **Space**                    | **O(N)** (for HashSet) |

---

## 💡 Why This Is Optimal

* Each number is processed **only once**.
* We **never repeat work** like in sorting or nested loops.
* HashSet gives O(1) lookups, which makes it linear overall.




---
---
---





## 🧩 Problem Recap

We have:

```
nums = [100, 4, 200, 1, 3, 2]
```

We put everything in a set:

```
s = {100, 4, 200, 1, 3, 2}
```

Now we loop:

```cpp
for (int num : s) {
    if (s.find(num - 1) == s.end()) {   // means this is start of a sequence
        int currentNum = num;
        while (s.find(currentNum + 1) != s.end()) {
            currentNum++;
        }
    }
}
```

At first glance — looks like:

* Outer loop runs N times
* Inner loop runs multiple times
  → Looks like O(N²)… right?

Now we’ll *track what actually happens*.

---

## 🎯 Step-by-Step Example (Watch how each number is used)

| Step | num | `num-1` exists? | Entered while loop? | While loop visited numbers | Total visits |
| ---- | --- | --------------- | ------------------- | -------------------------- | ------------ |
| 1    | 100 | ❌               | ✅                   | [100]                      | 1            |
| 2    | 4   | ✅ (3 exists)    | ❌                   | -                          | 0            |
| 3    | 200 | ❌               | ✅                   | [200]                      | 1            |
| 4    | 1   | ❌               | ✅                   | [1, 2, 3, 4]               | 4            |
| 5    | 3   | ✅ (2 exists)    | ❌                   | -                          | 0            |
| 6    | 2   | ✅ (1 exists)    | ❌                   | -                          | 0            |

👉 Total inner loop visits = **1 + 1 + 4 = 6 = N**

---

## 💡 What’s Actually Going On

Let’s visualize this:

```
Sequence 1: [1, 2, 3, 4]
Sequence 2: [100]
Sequence 3: [200]
```

Now imagine we process elements one by one:

* When we reach `1`,
  we go `→ 2 → 3 → 4` in the while loop.
  After that, `2`, `3`, and `4` **will never start a loop** again, because for them `num-1` exists.
  (They’re already part of the chain that began at `1`.)

* When we reach `100`,
  we just check once — done.

* When we reach `200`,
  same.

So:
Each number gets touched **exactly once** — either inside a `while` loop, or skipped because it’s already part of an earlier sequence.

That’s the **big secret** 🧠 —
we never “revisit” elements inside the inner loop again in another iteration of the outer loop.

---

## 🧮 Let’s Count Actual Work Done

Let’s simulate:

```
Outer loop visits = N times (6)
Inner while total visits = each number once (6)
----------------------------------------------
Total = 6 + 6 = 12 operations ≈ O(N)
```

If it were **O(N²)**, inner loop would run N times *for every* outer iteration.
But here — each number gets processed once overall, so it’s *linear*.

---

## ⚙️ Real-World Analogy

Imagine a row of people standing in order of their “sequence”:

```
1 - 2 - 3 - 4      100      200
```

Now, your job is:
👉 “Find where a sequence starts, then count how long it continues.”

You walk down the line:

* You stop at **1** (because no one with number 0 stands before it).
  You count: 1, 2, 3, 4 → 4 people total.
* When you reach 2, 3, 4 — you skip them (because they’re already part of the chain you just counted).
* You do the same for 100 and 200.

Notice:
Even though there’s an “outer” loop for every person,
you’re not recounting the same people again.
You only “walk over” each person once — that’s why it’s **O(N)**.

---

## 🧠 Summary

| Step | Concept          | Explanation                                   |
| ---- | ---------------- | --------------------------------------------- |
| 1    | Outer loop       | Runs N times                                  |
| 2    | Inner loop       | Runs once for each sequence (not each number) |
| 3    | Each number      | Processed once total                          |
| ✅    | Final Complexity | **O(N)**                                      |
