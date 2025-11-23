# Quick verbal summary

The algorithm keeps a running prefix sum `preSum`. For each position `i`, it asks: *how many previous prefixes had value `preSum - k`?* Each such previous prefix marks the end of a prefix so that the elements between that prefix and current index sum to `k`. We count those, then record the current `preSum` in the map.

# Line-by-line explanation (with intent)

```cpp
std::unordered_map<int, int> mp;
```

Create a hash map `mp` where `mp[x]` = number of times a prefix sum of value `x` has been seen so far.

```cpp
int preSum = 0;
```

`preSum` holds the running prefix sum from the start to current index (inclusive).

```cpp
int cnt = 0;
```

`cnt` accumulates the number of subarrays found whose sum equals `k`.

```cpp
mp[0] = 1;
```

Important base-case: we’ve seen prefix-sum `0` once (empty prefix). This allows subarrays that start at index 0 and sum to `k` to be counted (because `preSum - k == 0` in that case).

Loop:

```cpp
for (int i = 0; i < arr.size(); i++)
{
    preSum += arr[i];
```

Add current element to running sum.

```cpp
    int remove = preSum - k;
```

We want earlier prefix sums equal to `remove`. If a previous prefix sum `P` equals `remove`, then `preSum - P = k`, i.e. the subarray between that previous index+1 and current `i` sums to `k`.

```cpp
    cnt += mp[remove];
```

Add count of such earlier prefixes. If `mp[remove]` doesn't exist, it behaves as `0` (no contribution).

```cpp
    mp[preSum] += 1;
}
```

Record that we've now seen this `preSum` (so future indices can use it). Note the order: we query `mp[remove]` **before** incrementing `mp[preSum]`. That's important so subarrays that end at the current index only match **previous** prefixes, not the current one.

```cpp
return cnt;
```

Return total count.

# Complexity correction

Your comment said:

```
// TC = O(n log n) for map and O(n^2) for unordered map
```

That's wrong. Correct statement:

* Using `std::map` (ordered): each lookup/insert is `O(log n)`, so overall `O(n log n)`.
* Using `std::unordered_map` (hash): average-case `O(1)` per op → **average** overall `O(n)`. Worst-case (hash collisions / adversarial) can be `O(n^2)`, but practically it's `O(n)` and that's why `unordered_map` is preferred here.
* Space: `O(n)` for storing prefix counts.

# Dry-run table (nums3 = [1,2,1,2,1], k=3)

Start:

* `mp = { 0:1 }`
* `preSum = 0`
* `cnt = 0`

Now iterate i = 0..4:

|  i | arr[i] | preSum (after add) | remove = preSum - k | mp[remove] | cnt (after) |  mp (after mp[preSum]++)  |
| -: | :----: | :----------------: | :-----------------: | :--------: | :---------: | :-----------------------: |
|  0 |    1   |          1         |      1 - 3 = -2     |      0     |      0      |         {0:1, 1:1}        |
|  1 |    2   |          3         |      3 - 3 = 0      |      1     |      1      |      {0:1, 1:1, 3:1}      |
|  2 |    1   |          4         |      4 - 3 = 1      |      1     |      2      |    {0:1, 1:1, 3:1, 4:1}   |
|  3 |    2   |          6         |      6 - 3 = 3      |      1     |      3      |   {0:1,1:1,3:1,4:1,6:1}   |
|  4 |    1   |          7         |      7 - 3 = 4      |      1     |      4      | {0:1,1:1,3:1,4:1,6:1,7:1} |

Final `cnt = 4` → output `4 = Result`.
Each increment of `cnt` corresponds to a subarray that sums to `k`:

* i=1 (preSum=3, remove=0): subarray `[0..1]` → `{1,2}` sum 3.
* i=2 (preSum=4, remove=1): subarray `[1..2]` → `{2,1}` sum 3.
* i=3 (preSum=6, remove=3): subarray `[2..3]` → `{1,2}` sum 3.
* i=4 (preSum=7, remove=4): subarray `[3..4]` → `{2,1}` sum 3.

So there are 4 distinct subarrays whose sum equals 3.

# Why this works (intuitively)

If `prefix[j]` is sum up to index `j` and `prefix[i]` is sum up to index `i` (with `i > j`), then sum of subarray `(j+1..i)` is `prefix[i] - prefix[j]`. We want `prefix[i] - prefix[j] == k` → `prefix[j] == prefix[i] - k`. For each `i` we count how many `j < i` have `prefix[j] == prefix[i] - k`. The map stores frequencies of earlier `prefix[j]`.

# Important implementation notes / gotchas

* Keep `mp[0] = 1` to handle subarrays starting at index 0.
* Use `unordered_map` for average `O(n)` runtime.
* Keep the order: check `mp[remove]` before updating `mp[preSum]` so current element doesn’t pair with itself incorrectly.
* Be careful with integer overflow if elements or sums are very large — then use `long long` for `preSum` and map keys.



---
---
---


<br>
<br>
<br>


```cpp
mp[preSum] += 1;
```

---

# ✅ **1. What `mp[preSum]` actually means**

`mp` is an **unordered_map<int, int>**.

So `mp[key]` gives you the **value stored at that key**.

Example:

```cpp
mp[3] = 7;
```

means the map stores:

```
key = 3
value = 7
```

But if key *does not exist*, then doing `mp[key]` will:

* **create the key**
* **set its value to 0**
* return that 0 (so you can modify it)

This is the most important rule.

---

# ✅ **2. What does `mp[preSum] += 1;` do?**

Equivalent to:

```cpp
mp[preSum] = mp[preSum] + 1;
```

This means:

1. **Look up** the current count of how many times this prefix sum has appeared.
2. **Add 1** because this new prefix sum occurred once more.
3. **Store the updated count back into the map.**

---

# ❗ Your confusion:

> *“If preSum is 3, why does mp[3] go from 3 to 4? Does mp store something like 3:3+1 ?”*

Let me break it down.

---

# ✅ **3. Example: Suppose preSum = 3**

Let’s assume this is the third time we've seen prefix-sum = 3.

Before update:

```
mp = { … , 3 : 3 }
```

Now this line executes:

```cpp
mp[preSum] += 1;   // preSum = 3
```

So the map does:

```
mp[3] = mp[3] + 1
mp[3] = 3 + 1
mp[3] = 4
```

Now the map becomes:

```
mp = { … , 3 : 4 }
```

Nothing weird happens — we simply increment the count.

---

# 🎯 **4. Why do we increment it?**

Because every prefix sum value represents **how many earlier indices** had that prefix sum.

We need this to know:

> How many previous prefix sums match `preSum - k`?

So if prefix-sum `3` was seen 4 times, we store:

```
mp[3] = 4
```

This tells us:

> Prefix sum 3 has appeared 4 times in the path so far.

---

# ⭐ **5. Visualizing it**

Think of the map like a frequency counter:

| Prefix Sum (key) | Frequency (value) |
| ---------------- | ----------------- |
| 0                | 1                 |
| 1                | 1                 |
| 3                | 4                 |
| 4                | 1                 |

When you do:

```cpp
mp[3] += 1;
```

You are just updating the **frequency** of the prefix sum `3`.

---

# 🧠 **6. Why does unordered_map allow `mp[key]++` even if key doesn’t exist?**

Because the rule says:

> Accessing mp[key] creates key with default value = 0.

So:

```cpp
mp[10] += 1;
```

If 10 didn’t exist:

```
Before: mp = { }
mp[10] → creates entry: {10 : 0}
Then mp[10] += 1 → {10 : 1}
```

So now:

```
mp = { 10 : 1 }
```

---

# ✔ Final Summary

* `mp[preSum]` gives the **count of how many times preSum has appeared**.
* `mp[preSum] += 1` increments that count.
* If preSum never appeared before, map auto-creates it with value 0.
* The map stores **frequencies**, NOT mathematical operations like `3:3+1`.