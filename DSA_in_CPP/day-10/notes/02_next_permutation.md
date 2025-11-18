## 🌱 1. What is a “Permutation”?

A **permutation** means **an arrangement of elements** in all possible different orders.

Example:
If we have `[1, 2, 3]`, all possible permutations (arrangements) are:

| # | Permutation |
| - | ----------- |
| 1 | [1, 2, 3]   |
| 2 | [1, 3, 2]   |
| 3 | [2, 1, 3]   |
| 4 | [2, 3, 1]   |
| 5 | [3, 1, 2]   |
| 6 | [3, 2, 1]   |

Total = 3! = 6 permutations.

---

## ⚙️ 2. What does “Next Permutation” mean?

Imagine that all these permutations are arranged **in dictionary (lexicographic)** order, just like words in a dictionary:

`[1,2,3]` comes **before** `[1,3,2]`
because `1 == 1`, but `2 < 3` at the first difference.

Now, **“next permutation”** simply means:

> The permutation that comes **immediately after** the current one in this sorted list.

So:

* Next permutation of `[1,2,3]` → `[1,3,2]`
* Next permutation of `[1,3,2]` → `[2,1,3]`
* Next permutation of `[2,3,1]` → `[3,1,2]`
* Next permutation of `[3,2,1]` → There is **no next** (it’s the largest one),
  so we go **back to the smallest one** → `[1,2,3]`

---

## 🔍 3. Why do we need this problem?

In many algorithmic or combinatorial tasks, we want to:

* Generate permutations **one by one in order** (instead of generating all at once)
* Move to the **next possible arrangement** efficiently

For example:

* Solving puzzles or optimization problems
* Enumerating possible paths or configurations in order
* Writing your own version of `std::next_permutation()` (which C++ already provides)

---

## 🧠 4. Let’s visualize step-by-step with example

Suppose your current sequence is:

```
[1, 3, 2]
```

Now, imagine you list all permutations in lexicographic order again:

| Order | Permutation               |
| ----- | ------------------------- |
| 1     | [1, 2, 3]                 |
| 2     | [1, 3, 2] ← (our current) |
| 3     | [2, 1, 3]                 |
| 4     | [2, 3, 1]                 |
| 5     | [3, 1, 2]                 |
| 6     | [3, 2, 1]                 |

Now if we are currently at `[1,3,2]`,
the **next** permutation is `[2,1,3]`.

So the goal of the problem is:

> Given `[1,3,2]`, return `[2,1,3]`.

If input was `[3,2,1]`, it’s the **last** one in order.
So we **wrap around** and return the smallest: `[1,2,3]`.

---

## 🧩 5. What are we trying to do in code?

We want to **take an array** (say `nums = [1,3,2]`)
and modify or return a new array that’s the **next lexicographical permutation**.

That’s it.

You don’t have to generate *all permutations*.
There’s a very clever pattern that lets you find the next one directly —
that’s the **optimal** way (you said you’ll do that later).

But before that, let’s understand **how we can solve it conceptually.**

---

## 💡 6. Brute-force understanding (the dumb but easy way)

We can literally do this:

1. Generate **all possible permutations** of `nums`.
2. **Sort** them lexicographically.
3. Find where `nums` currently is in that sorted list.
4. Return the one that comes **just after** it.

Example with `[1,3,2]`:

All permutations → sorted:

```
[1,2,3]
[1,3,2]   <-- current
[2,1,3]   <-- NEXT
[2,3,1]
[3,1,2]
[3,2,1]
```

Next permutation = `[2,1,3]`.

✅ Works correctly
❌ Extremely slow (`O(n! * n)`) — impossible for large `n`.

---

## ⚙️ 7. Better approach idea (but still not optimal)

Instead of generating and storing all,
we can **generate them one by one (backtracking)** in sorted order and **stop** when we find the next one.

So:

* Start from smallest permutation (`[1,2,3]`)
* Keep generating next ones in order:

  * `[1,2,3]`
  * `[1,3,2]`
  * `[2,1,3]`
* Stop when you pass the given array `[1,3,2]`
* Return `[2,1,3]`

It’s still slow but saves memory since you don’t store all — just generate sequentially.

---

## ⚙️ 8. Optimal idea (just conceptually)

Since you said you’ll do this part yourself, I won’t give code, but let’s understand the **intuition**:

You can find the next permutation **in O(n)** time by:

* Scanning from **right to left** to find where the order breaks
* Swapping some numbers
* Reversing the tail

It’s like “finding the next greater number using the same digits.”

We’ll leave this part for you to implement later.

---

## 🧾 9. Summary Table

| Approach    | Idea                                                              | Time Complexity        | Space Complexity |
| ----------- | ----------------------------------------------------------------- | ---------------------- | ---------------- |
| **Brute**   | Generate all permutations, sort, find next                        | `O(n! * n)`            | `O(n! * n)`      |
| **Better**  | Generate one-by-one using recursion/backtracking until next found | `O(n! * n)` worst-case | `O(n)`           |
| **Optimal** | Direct math-based method (find break point + swap + reverse)      | `O(n)`                 | `O(1)`           |

---

## 🧠 10. Simple analogy

Think of digits in your array as **numbers on a lock**.

If your lock currently shows **1-3-2**,
you want to find the **next number** you’d get if you kept spinning digits **in sorted order**, like:

```
132 → 213 → 231 → 312 → 321 → 123 → ...
```

When you reach the end (321), it wraps around to start (123).
That’s exactly what “next permutation” means.

---
---
---

<br>
<br>
<br>



















# Brute Force Approach (generate all permutations and pick the next)

**Idea:**

1. Generate all permutations of the input array.
2. Sort the list of permutations lexicographically (or generate them and insert into a set that keeps order).
3. Find the input permutation in that sorted list and return the next element (or the first if input is last).

This is straightforward but extremely slow for larger `n`.

**Complexity:**

* Time: `O(n * n!)` to generate all permutations and copy them (n! permutations, each of length n; sorting adds another `n! * log(n!)` factor but the `n * n!` term dominates for copying/printing). If you sort the permutations explicitly, sorting cost would be `O(n! * log(n!) * n)`. Overall exponential/factorial.
* Space: `O(n * n!)` to store all permutations.

**Correctness:** trivial by construction — you have the entire ordered list.

**C++ implementation (brute):**

```cpp
#include <bits/stdc++.h>
using namespace std;

// Brute: generate all permutations, sort them lexicographically, find the next
vector<int> nextPermutationBrute(vector<int> A) {
    int n = A.size();
    vector<vector<int>> perms;

    // generate all permutations using std::next_permutation but first sort
    vector<int> temp = A;
    sort(temp.begin(), temp.end());
    do {
        perms.push_back(temp);
    } while (next_permutation(temp.begin(), temp.end()));

    // sort not strictly necessary because above generates in lex order,
    // but if you used another generator you'd sort:
    // sort(perms.begin(), perms.end());

    // find the current permutation in perms
    for (size_t i = 0; i < perms.size(); ++i) {
        if (perms[i] == A) {
            if (i + 1 < perms.size()) return perms[i + 1];
            else return perms[0]; // wrap to smallest
        }
    }
    return perms[0]; // fallback (shouldn't happen)
}
```

**Notes:**

* If input contains duplicates, `next_permutation` on the sorted `temp` will produce *unique* lexicographic permutations (C++ `next_permutation` treats equal elements appropriately). If you instead used naive swapping backtracking, you must dedupe.
* Very slow for `n >= 10`. Practically only usable for `n <= 8..10` depending on constraints.

---

# Better (but still exponential) approach — Backtracking with early stop

You said you don’t want the optimal one — so here’s a middle-ground: **generate permutations in lexicographic order using backtracking**, and **stop as soon as you find the next permutation** after the input. That avoids storing all permutations and may stop early (often much earlier than enumerating all), but worst-case cost is still factorial (e.g., when the input is near the end).

**Idea:**

1. Sort the elements to prepare lexicographic generation. (If there are duplicates, sorting + used[] + skip-equal logic ensures unique permutations.)
2. Perform backtracking that generates permutations in lexicographic order.
3. Maintain a state:

   * `found` flag = `false` until we encounter the original permutation.
   * When we build a permutation equal to input and `found == false`, set `found = true`.
   * The next permutation built after that is the lexicographic successor; return it immediately.
4. If we finish generation without finding a successor, return the first generated permutation (smallest).

**Complexity:**

* Time: Worst-case `O(n * n!)`. But average-case often much better because we stop early.
* Space: `O(n)` extra for recursion stack + used[] + current permutation. (We do not store all permutations.)

**C++ implementation (backtracking with early stop):**

```cpp
#include <bits/stdc++.h>
using namespace std;

bool eqVec(const vector<int>& a, const vector<int>& b) {
    if (a.size() != b.size()) return false;
    for (size_t i=0;i<a.size();++i) if (a[i]!=b[i]) return false;
    return true;
}

bool backtrackNextLex(const vector<int>& target, vector<int>& cur, vector<int>& sorted,
                      vector<bool>& used, bool &found, vector<int> &answer) {
    int n = sorted.size();
    if ((int)cur.size() == n) {
        if (!found) {
            if (eqVec(cur, target)) {
                found = true; // found the input permutation
            }
            // else continue generating
        } else {
            // found was true on previous exact match; this is the next permutation
            answer = cur;
            return true; // stop everything
        }
        return false; // continue
    }
    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        // skip duplicates: if same as previous and previous not used, skip
        if (i > 0 && sorted[i] == sorted[i-1] && !used[i-1]) continue;

        used[i] = true;
        cur.push_back(sorted[i]);

        if (backtrackNextLex(target, cur, sorted, used, found, answer)) return true;

        cur.pop_back();
        used[i] = false;
    }
    return false;
}

vector<int> nextPermutationBetter(vector<int> A) {
    int n = A.size();
    vector<int> sorted = A;
    sort(sorted.begin(), sorted.end());
    vector<bool> used(n,false);
    vector<int> cur, answer;
    bool found = false;

    // If we never find the target in generation (e.g., input not a permutation of sorted),
    // we fall back to smallest permutation.
    bool got = backtrackNextLex(A, cur, sorted, used, found, answer);
    if (got) return answer;
    // If not got, either input was the last or input wasn't found; return smallest:
    return sorted;
}
```

**Notes / correctness:**

* Because we generate permutations in lexicographic order (due to iterating sorted array and skipping duplicates correctly), the first permutation we generate after seeing the target is the lexicographic successor.
* Works with duplicates (the skip-equal + used[] pattern prevents duplicate permutations being generated).
* Space usage is linear in `n` (recursion stack + used[]).

**When is this better than brute?**

* Brute generated and stored all permutations; this approach generates on-the-fly and stops early, so memory is much lower and time may be much lower if the successor is near the start.

---

# Edge cases & practical notes

1. **All descending (largest permutation)**: no lexicographically larger permutation exists → return smallest (sorted ascending). Both approaches handle this (brute wraps to first; backtracking will generate smallest as first, find target near the end and no successor — then you return smallest).
2. **Duplicates**: carefully handle duplicates if you generate permutations yourself. Sorting + skip-equal logic prevents duplicate permutations.
3. **Input not a permutation of provided multiset**: Usually the problem assumes `A` contains the elements being permuted. If you call the "next-permutation" operation on any sequence, the standard definition still applies (treat it as sequence of elements). If your generator is based on sorted multiset, ensure `A` is indeed a reordering; otherwise behavior depends on your implementation.
4. **In-place vs new array**: Many problem variants ask to modify `A` in-place; both approaches can be adapted to do that (just overwrite `A` with result).

---

# Quick summary of complexities

* **Brute (generate all, sort/list, find next)**

  * Time: `O(n * n!)` (dominant) — extremely expensive
  * Space: `O(n * n!)` to store all permutations

* **Better (backtracking generating lexicographic permutations, stop early)**

  * Time: worst-case `O(n * n!)` but often stops early in practice
  * Space: `O(n)` extra (recursion + used[] + current permutation)

---

# Small test cases to think with

* `[1,2,3]` → `[1,3,2]`
* `[1,3,2]` → `[2,1,3]`
* `[3,2,1]` → `[1,2,3]` (wrap)
* `[1,2,2]` → `[2,1,2]` (duplicates handled carefully)
