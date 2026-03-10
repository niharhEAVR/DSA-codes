# ⭐ **The Two-Scan Observation Technique**

(also known as **Prefix Scan / Suffix Scan Method**)

It is SUPER SIMPLE and interviewers love it.

---

# ✅ **INTUITION**

Product behaves differently from sum:

* A zero **breaks** the subarray.
* Negative numbers can flip the sign.
* The maximum product subarray can appear:

  * in the **prefix**
  * or in the **suffix**
  * after a zero
  * between negative pairs

So the trick is:

👉 **Scan the array from L → R keeping running product.**
👉 **Scan again from R → L.**

At both sides, whenever running product becomes `0`, reset to `1`.

Why does this work?

* If the max subarray starts after a negative sequence → suffix scan handles it.
* If it ends before a negative sequence → prefix scan handles it.
* If zero divides segments → both scans reset and continue.

This method uses only **O(1) space** and **O(N) time**.

---

# 📌 **Algorithm (Prefix + Suffix)**

```cpp
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int pre = 1, suff = 1;
    int ans = INT_MIN;

    for (int i = 0; i < n; i++) {

        // forward prefix
        pre *= nums[i];
        ans = max(ans, pre);
        if (pre == 0) pre = 1;

        // backward suffix
        suff *= nums[n-1-i];
        ans = max(ans, suff);
        if (suff == 0) suff = 1;
    }

    return ans;
}
```

---

# 🔥 **Why this works (in simple English)**

* Multiplying left-to-right catches segments where the **max subarray starts early**.
* Multiplying right-to-left catches segments where the **max subarray ends late**.
* Any time you hit 0, you restart (because the product subarray cannot include 0).

The trick is:

> **Every possible contiguous product subarray is captured by either the prefix or suffix scan.**

---

# 🧪 **Example: Your Array**

```
1, 0, -5, 2, 3, -8, -9
```

Kadane DP gives: **432**
This observation method also gives: **432**

It catches:

```
2 * 3 * -8 * -9 = 432
```

Because scanning from the **right** multiplies:

```
-9
(-9)*(-8)=72
72*3 = 216
216*2 = 432
```

Boom! Maximum found.

---

# 🟢 **When is this better?**

* When the interviewer wants “alternative thinking”
* For low-memory embedded systems
* When implementing quick prototype logic
* When debugging the DP version (this approach is simpler)

---

# 📌 **Important: This works only for Maximum Product Subarray**

This trick **does NOT** work for maximum sum subarray, minimum product subarray, or other DP-structured problems.

Only works here because:

🟢 Product spreads in both directions
🟢 Zero acts as a natural boundary
🟢 Sign flipping captured by forward + backward scan

---

# 🎯 Summary

| Method                       | Works? | Notes                       |
| ---------------------------- | ------ | --------------------------- |
| Kadane Sum                   | ❌      | Not applicable              |
| Modified Product Kadane (DP) | ✔️     | Classic solution            |
| **Prefix + Suffix Scan**     | ✔️     | Clean observation technique |

---
---
---



# ⭐ INTUITION BEHIND PREFIX–SUFFIX TECHNIQUE

(Why scanning from both sides magically finds the maximum product)

Think of the array as a road where you walk and multiply numbers.

A product subarray is a **continuous segment** of this road.

But 3 things break product intuition:

---

# 1️⃣ **Zero acts like a WALL**

Example:

```
2, -3, 4,  0,  5, 6, -2
```

If you hit `0`, any product becomes `0`.
So **max product cannot cross a zero**.

Imagine the array breaks into separate worlds:

```
[2, -3, 4]     [5, 6, -2]
```

Left world and right world don’t interact because the wall is 0.

So scanning **L → R** naturally handles everything until zero.
Then scanning **R → L** handles everything after zero.

---

# 2️⃣ **Negative numbers flip the sign**

Example:

```
2, 3, -8, -9
```

Products behave strangely:

* Positive × Negative = Negative
* Negative × Negative = Positive

This means:

> A large **positive product** might appear *only after* meeting 2 negative numbers.

But here’s the key intuition:

👉 A negative chain might become positive only when you come from the **left** direction.
👉 Another negative chain might become positive only when you come from the **right** direction.

So **you must check both directions**.

---

# 3️⃣ **Maximum product might start anywhere & end anywhere**

This is the most important intuition.

Suffix explanation:

### Let’s say the best subarray is:

```
             [ 2, 3, -8, -9 ]
```

When you scan L→R, you first do:

```
2 → 6 → -48 → 432
```

You will get the correct answer.

But look at another example:

```
-1, -2, -3, 4
```

The maximum product is:

```
-1 * -2 * -3 * 4 = 24
```

Left-to-right discovers this.

But consider **this**:

```
4, -1, -2, -3
```

The maximum product is:

```
-1 * -2 * -3 = -6
```

But the **best positive subarray** might be found only when scanning from **right-to-left**, because the useful negatives appear from the right side.

So:

> The maximum product subarray might “start” from left side
> OR “start” from right side.
> You don’t know which direction gives the valid positive chain.

---

# ⚡ The final intuition (the REAL reason it works)

## ⭐ “A product subarray can be destroyed from the left but saved from the right.”

## ⭐ “A product subarray can be destroyed from the right but saved from the left.”

This is the true core idea.

Let's see examples:

---

# 🧠 Case 1 — destroyed from left, saved from right

Example:

```
-1, 2, 3
```

L → R:

```
-1 → -2 → -6 (bad)
```

But R → L:

```
3 → 6 → -6 (positive captured early)
```

Prefix catches later positives
Suffix catches early positives

---

# 🧠 Case 2 — destroyed from right, saved from left

Example:

```
3, 2, -1
```

L → R:

```
3 → 6 → -6 (best is 6)
```

R → L:

```
-1 → -2 → -6 (bad)
```

Left-to-right catches the best part.

---

# 📌 Combining BOTH → Always catches the maximum

Since:

* zeros divide the world
* negatives flip signs
* max subarray may appear favoring left or right direction

Doing BOTH scans guarantees:

**Any maximum-product subarray must be reachable
from SOME direction without breaking the product.**

---

# 🏆 FINAL intuition in one line:

> **The largest product subarray is either a forward-running product or a backward-running product, unless broken by zeros — so scanning both ways captures everything.**

Exactly like this:

```
L → R finds max prefix product
R → L finds max suffix product
```

Both together = captures every possible “window” of product.

---

# ✔ Why your brain can trust this method

Products are destroyed easily by zeros
Products are flipped easily by negatives
Products can start growing from left **or** from right

That’s why:

👉 You cannot predict where the correct subarray starts
👉 So you scan from both directions
👉 And take the maximum

This is why the two-scan method **always works**.
