# 🚀 **1. BRUTE FORCE APPROACH (Start Here)**

## 🎯 **Basic Idea**

For each element in the array:

1. Count how many times it appears in the entire array.
2. If its count is more than
   \[
   \left\lfloor \frac{n}{3} \right\rfloor
   \]
   → include it.

But avoid duplicates.

---

# 🔍 **STEP-BY-STEP THINKING**

Suppose array =

```
[1, 2, 3, 1, 1, 2]
```

n = 6
threshold = ⌊6/3⌋ = 2

### Let’s simulate brute force manually:

### **i = 0 → element = 1**

Count all 1s → 3
3 > 2 → YES
Add 1 to answer.

### **i = 1 → element = 2**

Count all 2s → 2
2 > 2? → NO
Do nothing.

### **i = 2 → element = 3**

Count all 3s → 1
1 > 2? → NO

### **i = 3 → element = 1**

Already added before → ignore.

### **i = 4 → element = 1**

Ignore.

### **i = 5 → element = 2**

Check but no need to add.

---

# ⏱️ **Time Complexity of Brute**

For each element (n times), count in the whole array (n times):

\[
O(n^2)
\]

Space =
\[
O(1)
\]

---

# 💡 **Thought Process Summary (Brute)**

* Loop over every index
* For each element, count frequency
* If frequency > n/3 AND not already taken → store it
* Continue scanning

---
---
---
---


# ⭐ **BETTER APPROACH — Think Like a Human Counting Items**

Imagine someone gives you a bag of numbers:

```
[1, 1, 2, 3, 1, 2, 2, 2]
```

And tells you:

> “Count how many times each number appears.”

What will you do?

You will take a notebook, and write:

```
1 → 3 times  
2 → 4 times  
3 → 1 time
```

This notebook = **hash map** (frequency map).

That’s it.
This is the “better approach”.

---

# ✔️ Let’s break it even simpler

### 👇 Step 1: Create an empty map (or notebook)

```
{}
```

### 👇 Step 2: Go through the array once

Array:
`[1, 1, 2, 3, 1, 2, 2, 2]`

Keep updating the map:

1 → `{1: 1}`
1 → `{1: 2}`
2 → `{1: 2, 2: 1}`
3 → `{1: 2, 2: 1, 3: 1}`
1 → `{1: 3, 2: 1, 3: 1}`
2 → `{1: 3, 2: 2, 3: 1}`
2 → `{1: 3, 2: 3, 3: 1}`
2 → `{1: 3, 2: 4, 3: 1}`

Done 🎉
You built a frequency table with **ONE loop**.

---

# ✔️ Step 3: Calculate majority threshold

Array length = 8

\[
\left\lfloor \frac{8}{3} \right\rfloor = 2
\]

To be a majority element, frequency must be **> 2**.

---

# ✔️ Step 4: Check which frequencies are > 2

Map:

```
1 → 3  
2 → 4  
3 → 1
```

Check:

* Is 3 > 2? → YES → include 1
* Is 4 > 2? → YES → include 2
* Is 1 > 2? → NO

Answer:

```
[1, 2]
```

---

# 🔥 Why this approach is “better”?

Because:

* You only traverse the array **once** → O(n)
* You never count any element repeatedly
* Hash map automatically remembers counts for you

Compared to brute force where you count each element again and again (which is slow).

---

# ⭐ **Time Complexity (TC)**

We do **two things**:

### ✅ **1st loop → Count frequencies**

We go through every element **once**:

\[
O(n)
\]

### ✅ **2nd loop → Check which elements have freq > n/3**

The hashmap can have at most **n** entries (worst case all elements are different):

\[
O(n)
\]

### 🔥 Total TC:

\[
O(n) + O(n) = O(n)
\]

👉 **Final Time Complexity = ( \mathbf{O(n)} )**

---

# ⭐ **Space Complexity (SC)**

We use a hashmap (frequency map).

In the **worst case**, all elements are different:

Example:

```
[1, 2, 3, 4, 5]
```

You will store:

```
1 → 1
2 → 1
3 → 1
4 → 1
5 → 1
```

Meaning **n entries in the map**.

So space used = proportional to number of elements.

\[
\mathbf{O(n)}
\]

👉 **Final Space Complexity = ( \mathbf{O(n)} )**

---

# ⭐ Final Summary for Better Approach

| Approach             | Time Complexity | Space Complexity |
| -------------------- | --------------- | ---------------- |
| **Better (Hashmap)** | **O(n)**        | **O(n)**         |

---
---
---


<br>
<br>
<br>





# ⭐ Optimal Algorithm: **Extended Boyer–Moore Voting Algorithm**

This is the optimal solution.

Time: **O(n)**
Space: **O(1)**

---

# 🎯 **Goal (Understand this first)**

We need to find the element(s) that appear more than:

\[
\left\lfloor \frac{n}{3} \right\rfloor
\]

Example:
If array size is 9, n/3 = 3, so any element must appear **4 or more times**.

👉 Maximum answers = **2**
(VERY IMPORTANT!!)

Why max 2?
Because:

* If 3 different numbers appear more than n/3 times
* Then total freq would be > n
* Impossible

So we only need to track **TWO** candidates.

---

# 🎯 **Main Confusion You Have**

I know EXACTLY what your confusion is:

You don’t understand:

* **Why we reduce counts (cancel out)?**
* **Why only 2 candidates?**
* **Why this works without storing full frequencies?**

So let’s fix this deeply.

---

# 🍎 **Imagine the array as a voting system**

Each number is a **candidate**.
Every occurrence of the number is a **vote**.

But we don’t want:

* full HashMap
* full frequency table

We just want to know:
**Which 2 candidates have the best chance of being “majority” > n/3?**

So we simulate a "political election":

* The top 2 candidates will always survive elimination.
* Rest will get cancelled out.

---

# 🍎 Real-World Analogy

Imagine the array:

```
1 2 3 1 2 1 4 1
```

People are voting for numbers.

But we have only **2 tickets** (like 2 possible winners in election).

Who will survive till the end?
→ The ones who keep getting support and don’t get cancelled out.

---

# 🎯 KEY IDEA

We maintain these **two tickets**:

```
c1, cnt1
c2, cnt2
```

When someone votes:

### Case 1 — They vote for c1

Give c1 one extra vote (cnt1++)

### Case 2 — They vote for c2

Give c2 one extra vote (cnt2++)

### Case 3 — They vote for someone NEW

Three subcases:

#### (a) If cnt1 == 0

Then assign this number to c1
(It gets a “ticket”)

#### (b) Else if cnt2 == 0

Assign this number to c2
(It gets the second “ticket”)

#### (c) Else both cnt1 & cnt2 > 0

→ This new number “cancels out” one vote from each candidate
→ Because it's a vote for someone else, so both candidates lose power
(We reduce both counts by 1)

---

# 💡 Visual Example — VERY SIMPLE

Array:

```
[1, 2, 3]
```

n=3 → n/3 = 1

None appear more than once.

Let’s simulate:

### 1 arrives

```
c1 = 1, cnt1 = 1
c2 = ?, cnt2 = 0
```

### 2 arrives

```
c1 = 1
cnt1 = 1

c2 = 2
cnt2 = 1
```

### 3 arrives

Now cnt1 > 0 and cnt2 >0
And 3 ≠ c1, 3 ≠ c2 → cancel

```
cnt1-- → 0
cnt2-- → 0
```

Final:

```
c1 empty
c2 empty
```

👉 This is correct: **no majority element exists**.

---

# 💡 Why Cancel Works?

Because if a number must appear more than n/3,
it must survive all the cancelling.

If a number is NOT majority,
it will get cancelled away to zero.

Think of it like:

* Majority elements have *too many* votes → they will survive
* Minority elements get cancelled away → they disappear

---

# 🍏 Big Example (very beginner-friendly)

Array:

```
[1, 2, 1, 3, 1]
```

n = 5 → n/3 = 1
Need elements appearing **≥ 2 times**.

Expected answer = **[1]**

Let’s simulate slowly:

---

### 🟦 Step 1: 1 comes

```
c1 = 1, cnt1 = 1
c2 = ?, cnt2 = 0
```

---

### 🟦 Step 2: 2 comes

```
c1 = 1, cnt1 = 1
c2 = 2, cnt2 = 1
```

---

### 🟦 Step 3: 1 comes

Matches c1:

```
cnt1 = 2
```

c1 has strong support now.

---

### 🟦 Step 4: 3 comes

3 ≠ c1 AND 3 ≠ c2
cnt1>0 and cnt2>0
So cancel out BOTH candidates:

```
cnt1 = 1
cnt2 = 0
```

2 lost its power (cnt2 = 0)

---

### 🟦 Step 5: 1 comes

Matches c1:

```
cnt1 = 2
```

Final:

```
c1 = 1, cnt1 = 2
c2 = 2, cnt2 = 0
```

Candidate is correctly 1.

---

# 🎯 Step 2 — VALIDATION

We MUST check again because candidate is only a *potential* winner.

Count actual freq:

```
1 → 3 times  ✔
2 → 1 time   ✖
```

Answer = `[1]`

---

# 🎉 Summary in Baby Language

* Keep only two possible winners
* If a new number comes and both winners have votes → reduce both votes
  (like hitting both with a punch)
* Only numbers with **very high frequency** survive this punching
* At the end, verify which of the two survived candidates actually appear > n/3 times



---
---
---




# ✅ **Optimal C++ Code (Clean & Correct)**

```cpp
std::vector<int> majorityElement(std::vector<int> &nums) {
    int n = nums.size();

    // Step 1: Find potential candidates
    int c1 = 0, c2 = 0;
    int cnt1 = 0, cnt2 = 0;

    for (int x : nums) {
        if (x == c1) {
            cnt1++;
        }
        else if (x == c2) {
            cnt2++;
        }
        else if (cnt1 == 0) {
            c1 = x;
            cnt1 = 1;
        }
        else if (cnt2 == 0) {
            c2 = x;
            cnt2 = 1;
        }
        else {
            cnt1--;
            cnt2--;
        }
    }

    // Step 2: Validate the candidates
    cnt1 = 0;
    cnt2 = 0;

    for (int x : nums) {
        if (x == c1) cnt1++;
        else if (x == c2) cnt2++;
    }

    // Step 3: Build result
    std::vector<int> ans;
    if (cnt1 > n / 3) ans.push_back(c1);
    if (cnt2 > n / 3) ans.push_back(c2);

    return ans;
}
```

---

# ✔ Time Complexity

\[
O(n)
\]

# ✔ Space Complexity

\[
O(1)
\]

# ✔ Guaranteed optimal

This is the **standard** and most efficient solution used everywhere.

---

It’s **VERY important** to understand *why* the optimal solution has **O(1) space**, even though the brute and better solutions use extra space.

Let’s explain it **slowly and clearly**.

---

# 🧠 **What does O(1) space mean?**

O(1) means:

> **The algorithm uses a constant amount of extra memory, no matter how big the input is.**

It does **NOT** depend on `n`.

So even if the array has:

* 10 elements
* 10,000 elements
* 10 million elements

The algorithm still uses the **same small amount of memory**.

---

# 📦 **How much memory does the optimal solution use?**

In the optimal Boyer–Moore solution, we only store:

```
c1, cnt1
c2, cnt2
```

That’s 4 integers.

No matter how large nums.size() is,
we will **never** store more than:

* 2 candidates
* 2 counters
* (optional) result vector of max size 2

So the total extra memory is:

```
4 integers + result of size ≤ 2
```

This is a **constant amount** of space → does NOT grow with n.

---

# 📘 **Deep Explanation (Why only 2 variables?)**

Because:

### 👉 At most 2 elements can appear more than n/3 times.

This is a fundamental mathematical property:

If 3 different numbers each appeared **more than n/3 times**,
the total frequency would be:

\[
 \frac{n}{3} + \frac{n}{3} + \frac{n}{3} = n
\]

Which is impossible.

So:

* We only ever need to track **two candidates**.
* Therefore, **space remains constant**.

---

# 🧮 Example

Even if array = 10 million elements:

```
c1, cnt1 = 2 integers
c2, cnt2 = 2 integers
result vector = 0–2 integers
```

That's it.

---

# 🚫 What O(1) space does NOT count

* Input array memory does **not** count
* Output memory does **not** count

Space complexity counts **only the extra memory the algorithm itself allocates**.

Since we only allocate 4 integers → that’s **O(1)**.

---

# 🎯 Final Explanation

| Approach                  | Extra Space                          |
| ------------------------- | ------------------------------------ |
| Brute                     | O(n) or O(n log n) depending on sort |
| Better (HashMap)          | O(n)                                 |
| **Optimal (Boyer–Moore)** | **O(1)**                             |

Optimal is O(1) because:

* stores **exactly 2 candidates**
* stores **exactly 2 counters**
* stores **max 2 answers**

This is **constant space**, not dependent on n.