The **“Top View of Binary Tree”** problem is about **what you see if you look at a binary tree from above (top side)**.

---

## 🧠 Core Idea (Simple Visualization)

Imagine the tree is placed on the ground and you are flying in a helicopter looking straight down.

👉 You will only see **one node per vertical line** — the **topmost node** in that vertical direction.

---

## 🌳 Example Tree

![Image](https://images.openai.com/static-rsc-4/Ky6WSEsozQI8IcMNTiZ5dwAZ8WS-3qCZL_3jMkUvG3h3MhIB7qGGhMYp00HT2fBAQd7SC8vnLNRoRBTtW44brvBRq-6nfLeN_NHmKEWYDmS4CP34t3VwebVoK6RO8XT7gm9OBvFi5_Zae8PqrEm5UUuNyq25g8H-4H0ywKc6rDbNmj9VZFTTnFrlxZcVzJn6?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/_Q6rccjSK1Rl-7raxZXKTcc6NFXCZ8Ipb_GHjja2lMizxciH6m8CXVpIy_fdwrd8238HfrMhcxg7G5WDh-fhjixAztUkreko4te_3HEzjm_2CAONUgCVgGRdVyU1jprRKDED_qZrEgqicqbbPwUb_CQUBDzG14LYFdjslFAZG8V_lOYvkmNUuXkevPq4HzTf?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/mdg0yr6cK4HKzRrd4Xj6tZ7dDxcMiyip4Fc_XGQM2rrIB3i1PnZbHX2ClY1b_or4ct9MY139kXQrw17ZiQMOFLPNg3RV2yiLaUGHlOXT-22FlLcltW1Mukdbsw3Z2VKOLYX1izzT4Jbtule1r13SlY_feDgZaxWxNns-QjhKvboJQe1J6RsF210EajsDf8Bz?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/bFouw5A1Wmo5a3ddGmVI9nDzvrXJQ1DQ_KlwMfzlJh8q0V_9Mc-Qso-PAVINFf4wpAGc4wjmrXNTe7Si3U7UUwBVoI9RFdi8bCc2XDas7dEWSW34S4jYTHUdQCXBRgxyNnS8quEV7VFiC3F38PJlBjs3jIKUjxccNFM50tmF1zVPf-jswXHneeBE2nLFCDcH?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/TTGI8oR0dPGv5tMPUGW9RGNFCjd-jrianvDAoff4EkVpMqZjAzpt1iaegB5xY5Q2avEwaeJkcdPuCtYB8rWYVDK9C8kce6Zzt-1H7oFQq1YBGaRNFamjFDhPJFdIoZJBKbYYRg7Z-E45FJG7GyTavmWQRbcSmqcFp5_wdEF-kpKUzBMPy8iBBEiNoHoOR3rB?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/vXV3o4yvnLgpZt8weCVVEE4EdCQbLb0LZ0xP-mIrsyOl9_uovORk_7rP9f3LdSXSEndWqcWVXAbjDeFJebovSgAaw0xafZCnrBBspiMMkQeDvR8D_3pGktdTt6nH5v4oQ_3tuSt2x-tV9aJ_UBwpYDEyc55eZDRhfrkb0oFLQTKd7IiOb3nVtPTnXxTu2AyT?purpose=fullsize)

Consider this tree:

```
        1
      /   \
     2     3
      \   / \
       4 5   6
```

---

## 👀 What is the Top View?

We assign something called **Horizontal Distance (HD)**:

* Root → HD = 0
* Left child → HD - 1
* Right child → HD + 1

---

### Step-by-step HD mapping:

| Node | HD |
| ---- | -- |
| 1    | 0  |
| 2    | -1 |
| 3    | +1 |
| 4    | 0  |
| 5    | 0  |
| 6    | +2 |

---

### Now pick **topmost node for each HD**

* HD = -1 → Node **2**
* HD = 0 → Node **1** (ignore 4, 5 because they are below)
* HD = +1 → Node **3**
* HD = +2 → Node **6**

---

## ✅ Final Answer (Top View)

```
2 1 3 6
```

---

## 🔥 Important Observations

* You **only take the first node** you see at each HD
* If multiple nodes exist at same HD → take the one **closest to root**
* Order is from **leftmost HD → rightmost HD**

---

## 💡 Intuition (VERY IMPORTANT)

Think like this:

> “For each vertical line, I want the **first node I encounter from top**”

---

## 🧭 How this problem is usually solved (concept only)

* Use **BFS (level order traversal)**
* Track:

  * Node
  * Horizontal Distance (HD)
* Use a **map**

  * Key = HD
  * Value = first node seen at that HD

👉 Why BFS?
Because it processes nodes **level by level (top to bottom)**
So first time you see an HD → that is automatically the top node

---

## ⚠️ Common Mistake

* Using DFS incorrectly → may pick a deeper node first ❌
* Not maintaining order of HD ❌

---

## 🧠 One-line Definition

> Top View = **First visible node at each vertical line when seen from top**

---
---
---
---
---

# 🧠 Step 0: Problem Mindset

> “I need the **first visible node at each vertical line (HD)** when seen from top.”

So automatically:

* We care about **horizontal distance (HD)**
* We care about **topmost node**

---

# 🌳 Step 1: Assign Horizontal Distance (HD)

![Image](https://images.openai.com/static-rsc-4/IrWgPCxxGOjYE3eKmTq8k00kjsDVk1aISdfD0ffQk6Ni2d2VVWDjpjYEBaYsyI7SDjPLVMJorQCPO0YpdtGm5mqG45s0dqm_Ty46m5-wUrBdcbDV8OrylWNALGOaZGW0zzGZYpx5wBCnsHejEIvFcgREA6fWtoGgGhluoehYQa_LzZbOCpMpD2TgiR1Q2_pp?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/Ky6WSEsozQI8IcMNTiZ5dwAZ8WS-3qCZL_3jMkUvG3h3MhIB7qGGhMYp00HT2fBAQd7SC8vnLNRoRBTtW44brvBRq-6nfLeN_NHmKEWYDmS4CP34t3VwebVoK6RO8XT7gm9OBvFi5_Zae8PqrEm5UUuNyq25g8H-4H0ywKc6rDbNmj9VZFTTnFrlxZcVzJn6?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/bFouw5A1Wmo5a3ddGmVI9nDzvrXJQ1DQ_KlwMfzlJh8q0V_9Mc-Qso-PAVINFf4wpAGc4wjmrXNTe7Si3U7UUwBVoI9RFdi8bCc2XDas7dEWSW34S4jYTHUdQCXBRgxyNnS8quEV7VFiC3F38PJlBjs3jIKUjxccNFM50tmF1zVPf-jswXHneeBE2nLFCDcH?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/Lu1o8WLla2mPXpP20G3TP0Rjm_kIJOVLH4WwClVhA44TYDbNbI1Z30qxEWXv2cR8-nOHtf7mKTIOiUXfKQQVLgcm85GyiKiQCPpgObF8uk464Kn2Ng8SefMpR1MDYA6vpsYQhN3cRiu3idLKTczIpE0E_HSCkajwugXsAvUhxjenOT71cq4Sotr3A6tRoLtI?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/_Q6rccjSK1Rl-7raxZXKTcc6NFXCZ8Ipb_GHjja2lMizxciH6m8CXVpIy_fdwrd8238HfrMhcxg7G5WDh-fhjixAztUkreko4te_3HEzjm_2CAONUgCVgGRdVyU1jprRKDED_qZrEgqicqbbPwUb_CQUBDzG14LYFdjslFAZG8V_lOYvkmNUuXkevPq4HzTf?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/vXV3o4yvnLgpZt8weCVVEE4EdCQbLb0LZ0xP-mIrsyOl9_uovORk_7rP9f3LdSXSEndWqcWVXAbjDeFJebovSgAaw0xafZCnrBBspiMMkQeDvR8D_3pGktdTt6nH5v4oQ_3tuSt2x-tV9aJ_UBwpYDEyc55eZDRhfrkb0oFLQTKd7IiOb3nVtPTnXxTu2AyT?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/9AN0FiQSx2LG2u53gVLUOmZ1nqrvem1hb6WU-6M2dCZVl9Oq2p_tzJCVnGyQww1rfm3Cbw8OQnw8A_4ZrdIUuIj6ar1-Q_FSeychfNoxdKwUFvodPNQSTqXzz9hQl58N9dlM_1pDsorLVbycuaKOnLqWm071xOZnGjgckQm4UboWWfpIUUrufPmsEXFDt9Zg?purpose=fullsize)

Rules:

* Root → `HD = 0`
* Left → `HD - 1`
* Right → `HD + 1`

---

# 🚶 Step 2: Decide Traversal (MOST IMPORTANT)

Ask yourself:

👉 “How do I make sure I see top nodes first?”

Answer:

* Use **BFS (Level Order Traversal)**

Why?

* It processes nodes **level by level**
* So higher nodes come before lower ones

---

# 📦 Step 3: What to store in Queue?

Each element in queue should carry:

```
(Node, HD)
```

So you always know:

* which node
* which vertical line

---

# 🗺️ Step 4: Data Structure for Answer

Use:

```
map<HD, node_value>
```

👉 Important rule:

> “Store only if this HD is seen for the first time”

---

# 🔁 Step 5: Core Logic (This is the heart)

When you process a node from queue:

### Condition:

```
If HD is NOT present in map:
    store node value
Else:
    ignore it
```

👉 This ensures:

* Only **topmost node** is stored

---

# 🔄 Step 6: Expand the Tree

After processing a node:

* Push left child → `(HD - 1)`
* Push right child → `(HD + 1)`

---

# 📊 Step 7: Build Final Answer

* Your map is sorted by HD automatically
* Just traverse from **leftmost HD → rightmost HD**

👉 That gives correct top view order

---

# 🔥 Full Flow (Mental Execution)

```
1. Start BFS with (root, 0)
2. Pop node
3. If HD not in map → store it
4. Push left (HD-1), right (HD+1)
5. Repeat until queue empty
6. Read map in sorted order
```

---

# ⚠️ Key Things to Remember

* ❌ No need for set / multiset
* ❌ No need to store multiple nodes per HD
* ✅ Only FIRST occurrence matters
* ✅ BFS is mandatory (DFS can break logic)

---

# 🧠 Intuition Locked

> “I scan level by level, and whenever I see a new vertical line, I lock that node forever.”

---
---
---
---
---
---
---
---
---



Now let’s do the **time complexity properly step by step** 👇

---

# 🧠 Let `N = number of nodes in the tree`

---

# 🔁 Step 1: BFS Traversal

You are doing:

```cpp
while (!q.empty())
```

* Each node is pushed and popped **exactly once**

👉 Cost:

```
O(N)
```

---

# 🗺️ Step 2: Map Operations

Inside BFS, you do:

```cpp
nodes.find(hd)
nodes[hd] = value
```

👉 `map` in C++ is **ordered (Red-Black Tree)**

So each operation costs:

```
O(log K)
```

Where:

* `K = number of unique HDs`
* In worst case → `K ≈ N`

👉 So each operation:

```
O(log N)
```

---

### Total map cost:

You do it for each node →

```
N × log N = O(N log N)
```

---

# 📊 Step 3: Building Answer

```cpp
for (auto &p : nodes)
```

* You traverse the map once
* Map size = `K ≤ N`

👉 Cost:

```
O(N)
```

---

# 🧮 Final Time Complexity

```text
O(N)   (BFS)
+ O(N log N) (map operations)
+ O(N) (building answer)
```

👉 Final:
[
\boxed{O(N \log N)}
]

---

# 💾 Space Complexity

Let’s break it:

### 1. Queue:

* Stores at most one level → worst case `O(N)`

### 2. Map:

* Stores at most `N` entries → `O(N)`

### 3. Answer vector:

* `O(N)`

---

👉 Final Space:
[
\boxed{O(N)}
]

---

# 🔥 Important Insight (Interview Level)

If instead of `map`, you used:

* `unordered_map` → operations become **O(1)** average
* BUT you lose **sorted order of HD**

So you'd need extra sorting later.

👉 That’s why `map` is preferred → keeps HD sorted automatically.

---

# ⚡ Final Answer Summary

* **Time Complexity:**
  [
  O(N \log N)
  ]

* **Space Complexity:**
  [
  O(N)
  ]















---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
---







👉 Your confusion:

> “`find()` should return true/false, right?”

❌ **No — `find()` does NOT return true/false**

---

# 🧠 What `map.find(key)` actually returns

In C++:

```cpp
nodes.find(hd)
```

👉 returns an **iterator**, not a boolean.

---

## 🔍 Two possibilities:

### 1. Key FOUND

```cpp
auto it = nodes.find(hd);
```

👉 `it` points to that element

```text
it → (hd, value)
```

---

### 2. Key NOT FOUND

👉 It returns:

```cpp
nodes.end()
```

---

# 📌 What is `nodes.end()`?

Think of it like:

> “A special iterator that means → OUTSIDE the map”

It does **NOT point to any element**

---

# 🎯 So this condition means:

```cpp
if (nodes.find(hd) == nodes.end())
```

👉 Translation:

```text
“If searching hd gives me ‘not found’ → then insert”
```

---

# 🔁 Let’s Visualize It

Assume:

```cpp
nodes = { -1:2, 0:1, +1:3 }
```

---

## Case 1: `hd = 0`

```cpp
nodes.find(0)
```

👉 returns iterator pointing to:

```text
(0, 1)
```

👉 So:

```cpp
nodes.find(0) == nodes.end()  ❌ false
```

---

## Case 2: `hd = 2`

```cpp
nodes.find(2)
```

👉 returns:

```text
nodes.end()
```

👉 So:

```cpp
nodes.find(2) == nodes.end()  ✅ true
```

---

# 🔥 Why this pattern is used everywhere

Because C++ doesn’t do:

```cpp
if (nodes.contains(hd)) // (only in C++20)
```

Older standard way is:

```cpp
if (nodes.find(hd) != nodes.end())
```

---

# 🧠 Clean Mental Model

| Expression           | Meaning              |
| -------------------- | -------------------- |
| `find(key) != end()` | key exists ✅         |
| `find(key) == end()` | key does NOT exist ❌ |

---

# ⚡ Super Simple Analogy

Think of `map` like a **list of lockers**:

* `find(hd)` → “Check locker number hd”
* If locker exists → you get it
* If not → you reach **end (no locker found)**

---

# 💡 Bonus (Modern C++)

If using C++20:

```cpp
if (!nodes.contains(hd))
```

👉 Same meaning, cleaner

---

# 🔥 Final One-Line Understanding

> `nodes.find(hd) == nodes.end()`
> = “This key does NOT exist in the map”
