## 🧩 Problem Name:

**“Majority Element”**

---

## 🔍 Problem Meaning (in simple words)

You’re given an array of numbers.
Your job is to **find the number that appears more than half the time** in that array.

That’s it.

---

### 📘 Example 1

```
nums = [3, 2, 3]
```

Array size `n = 3`

Half of `n` = `3 / 2 = 1.5`

Now check how many times each number appears:

| Number | Count |
| ------ | ----- |
| 3      | 2     |
| 2      | 1     |

👉 The element `3` appears **2 times**, which is **more than 1.5**.
✅ So, the **majority element = 3**

---

### 📘 Example 2

```
nums = [2, 2, 1, 1, 1, 2, 2]
```

Array size `n = 7`
Half = `7 / 2 = 3.5`

| Number | Count |
| ------ | ----- |
| 1      | 3     |
| 2      | 4     |

`2` appears **4 times**, which is **more than 3.5**,
✅ So **majority element = 2**

---

### 🧠 Definition Again

> The **majority element** is the element that appears **more than ⌊n/2⌋ times**.

* The symbol `⌊ ⌋` means **floor value** → round down to nearest integer.
* So for `n=7`, ⌊7/2⌋ = 3.
* "More than ⌊n/2⌋" → means strictly greater than half the array.

---

### 💡 Important Note

The problem guarantees that:

> The majority element **always exists**.

So you **don’t** need to check if it exists or not — it will definitely be there.

---

### 🧮 Some More Examples

| nums          | n | ⌊n/2⌋ | Majority element |
| ------------- | - | ----- | ---------------- |
| [1]           | 1 | 0     | 1                |
| [1,1,2]       | 3 | 1     | 1                |
| [3,3,4,2,3,3] | 6 | 3     | 3                |
| [9,9,9,8,8]   | 5 | 2     | 9                |

---

### 🧩 Goal

✅ **Input:** array `nums`
✅ **Output:** the element that appears **more than half** of the time.

---
---
---

<br>
<br>
<br>

The **Moore’s Voting Algorithm (or Boyer–Moore Voting Algorithm)** — the optimal way to find the **Majority Element**.

---

## 🧩 Problem Recap

We need to find the **majority element** in an array —
the number that appears **more than ⌊n / 2⌋ times**.

✅ Example:

```
nums = [2, 2, 1, 1, 1, 2, 2]
→ Majority = 2 (appears 4 times, n/2 = 3.5)
```

---

## ⚙️ Moore’s Voting Algorithm — Concept

Think of it like a **voting game**:

* Each element is a **candidate**.
* If two different elements meet, they **cancel each other’s votes**.
* The element that remains at the end is the **majority element**.

---

### 🧠 Step-by-step Logic

We use **two variables**:

1. `candidate` → the number we’re currently “voting” for.
2. `count` → how many “votes” it currently has.

---

### 🔁 Algorithm Steps

1️⃣ Initialize:

```cpp
candidate = None
count = 0
```

2️⃣ Loop through each element `x` in the array:

* If `count == 0`:
  set `candidate = x`
* If `x == candidate`:
  `count++`
* Else:
  `count--`

3️⃣ At the end, the **candidate** will be the **majority element**.

---

### 🧩 Example Dry Run

Let’s take:

```
nums = [2, 2, 1, 1, 1, 2, 2]
```

| Step | Element | candidate | count | Action                        |
| ---- | ------- | --------- | ----- | ----------------------------- |
| 1    | 2       | 2         | 1     | count was 0 → set candidate=2 |
| 2    | 2       | 2         | 2     | same as candidate → count++   |
| 3    | 1       | 2         | 1     | different → count--           |
| 4    | 1       | 2         | 0     | different → count-- (now 0)   |
| 5    | 1       | 1         | 1     | count==0 → new candidate=1    |
| 6    | 2       | 1         | 0     | different → count--           |
| 7    | 2       | 2         | 1     | count==0 → new candidate=2    |

✅ Final `candidate = 2` → Majority element is **2**

---

## ✅ C++ Code Implementation

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        for (int num : nums) {
            if (count == 0)
                candidate = num;
            if (num == candidate)
                count++;
            else
                count--;
        }

        return candidate;
    }
};
```

---

## ⏱️ Complexity

| Metric    | Value | Explanation                   |
| --------- | ----- | ----------------------------- |
| **Time**  | O(n)  | Single pass through the array |
| **Space** | O(1)  | Only two variables used       |

---

## ⚠️ Important Note

This works **only if** the majority element **always exists** (as the problem guarantees).
If the array **might not** have one, you need a **second pass** to confirm that the candidate really appears > n/2 times.

---

### 🧮 Example Where It Fails Without Guarantee

```
nums = [1, 2, 3, 4]
```

No majority element exists.
The algorithm would still give a “candidate” (e.g., 4), but it’s **not actually** a majority.

---

## 🧠 Real-Life Analogy

Imagine a group discussion:

* Every person supports someone (votes).
* When two people disagree, they both leave the discussion (cancel votes).
* At the end, only the **majority-supported person** is left in the room.

That person = **Moore’s candidate** 🎯

---
---
---



### To solve that fail issue we need this

```cpp
int majorEle(std::vector<int> &nums)
{
    int count{},candidate;
    for (int i = 0; i < nums.size(); i++)
    {
        if(count == 0) count++,candidate = nums[i];

        if(nums[i] == candidate) count++;
        else count--;
    }
    
    int count2{};
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == candidate) count2++;
    }
    
    if(count2 > (nums.size()/2)) return candidate;
    return -1;
}
```


### 💡 **Moore’s Voting Algorithm — Concept Recap**

It’s used to find the **majority element**, i.e., an element that appears **more than n/2 times** in an array.

---

### ⚙️ **How It Works**

It works in **two phases**:

#### **Phase 1: Find a Candidate**

We assume there’s one element that dominates (appears more than half times).
We track:

* `candidate` → possible majority element
* `count` → balance counter

Algorithm:

1. Start with `count = 0`
2. For every element `x` in `nums`:

   * If `count == 0`, set `candidate = x`
   * If `x == candidate`, increment `count`
   * Else decrement `count`

At the end, the `candidate` will be **the only element that could possibly be the majority**.

---

#### **Phase 2: Verify the Candidate**

Because sometimes the candidate may **not** be a real majority (for example `[1,2,3,4]`).

We do a final pass to count how many times `candidate` appears.
If it appears more than `n/2` times → ✅ return it.
Otherwise → ❌ return `-1`.

---

### 🧠 Example 1 — Majority Exists

```
nums = [2, 2, 1, 1, 1, 2, 2]
```

**Step 1 — Find Candidate**

| i | nums[i] | count | candidate |
| - | ------- | ----- | --------- |
| 0 | 2       | 1     | 2         |
| 1 | 2       | 2     | 2         |
| 2 | 1       | 1     | 2         |
| 3 | 1       | 0     | 2         |
| 4 | 1       | 1     | 1         |
| 5 | 2       | 0     | 1         |
| 6 | 2       | 1     | 2         |

Candidate found → **2**

**Step 2 — Verify**
Count of 2 = 4
`n/2 = 3.5`
✅ 4 > 3.5 → majority element is **2**

---

### 🧮 Example 2 — No Majority Exists

```
nums = [1, 2, 3, 4]
```

**Step 1 — Candidate Phase**

| i | nums[i] | count | candidate |
| - | ------- | ----- | --------- |
| 0 | 1       | 1     | 1         |
| 1 | 2       | 0     | 1         |
| 2 | 3       | 1     | 3         |
| 3 | 4       | 0     | 3         |

Candidate → 3
**But** 3 appears only once.

**Step 2 — Verify**
Count(3) = 1
`n/2 = 2`
❌ Not majority → return `-1`.

---

### ✅ Time & Space Complexity

* **Time:** O(n) (two passes)
* **Space:** O(1) (constant space)
