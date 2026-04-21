# 🌳 What is

## **Boundary of Binary Tree?**

> You need to print the **boundary (outline)** of the tree in **anti-clockwise direction**, starting from the root.

---

# 🧠 Think like this

Imagine you are **standing outside the tree** and walking around it from the **left side → bottom → right side**.

👉 You only pick the nodes that lie on the **edge (boundary)**.

---

# 🌳 Example Tree

```
        1
      /   \
     2     3
    / \     \
   4   5     6
      / \   /
     7   8 9
```

---

# 🔥 Final Boundary Output

```
[1, 2, 4, 7, 8, 9, 6, 3]
```

---

# 🧩 The boundary has 3 parts (VERY IMPORTANT)

## 1️⃣ Left Boundary (excluding leaf nodes)

👉 Go from root → down the **left side**

```
1 → 2 → 4
```

But ❗ don’t include leaf nodes here

So:

```
[1, 2]
```

---

## 2️⃣ Leaf Nodes (left → right)

👉 All nodes with **no children**

```
4, 7, 8, 9, 6
```

---

## 3️⃣ Right Boundary (excluding leaf nodes, reversed)

👉 Go from root → down the **right side**

```
1 → 3 → 6
```

Exclude leaf nodes → `[3]`

Then reverse it:

```
[3] → stays same here
```

---

# 🔄 Combine all parts

```
Root + Left Boundary + Leaves + Right Boundary (reversed)
```

```
[1] + [2] + [4,7,8,9,6] + [3]
```

👉 Final:

```
[1, 2, 4, 7, 8, 9, 6, 3]
```

---

# ⚠️ MOST IMPORTANT RULES (where people get confused)

## ❌ Don’t duplicate nodes

* Leaf nodes should appear **only once**
* So:

  * Don’t include leaves in left boundary
  * Don’t include leaves in right boundary

---

## ❌ Root edge case

If tree has only one node:

```
[1]
```

---

## ❌ Left / Right missing cases

### Case 1: Only right subtree

```
1
 \
  2
   \
    3
```

Boundary:

```
[1, 3, 2]
```

---

### Case 2: Only left subtree

```
1
/
2
/
3
```

Boundary:

```
[1, 2, 3]
```

---

# 🧠 Clean Mental Model (VERY IMPORTANT)

Break the problem into 3 independent tasks:

### 🔹 Left Boundary

* Go down left
* Prefer left child, else right
* Stop before leaves

---

### 🔹 Leaf Nodes

* Do full traversal
* Collect all leaves

---

### 🔹 Right Boundary

* Go down right
* Prefer right child, else left
* Stop before leaves
* Reverse at the end

---

# 🔥 Visualization Trick

Imagine drawing a circle around the tree:

```
       (1)
     /     \
   (2)     (3)
   /         \
 (4)         (6)
```

👉 You trace the outer edge like:

```
Top → Left side ↓ → Bottom → Right side ↑
```

---

# 🎯 What this problem is REALLY testing

* Tree traversal understanding
* Edge case handling
* Ability to **split problem into parts**
* Avoiding duplicates

---

# 💡 One-line understanding

> “Print root, then left boundary, then all leaves, then right boundary in reverse — without duplicates.”

---
---
---
---
---



# 🧠 Core Idea (Very Important)

Boundary traversal = walking **around the tree** in an anti-clockwise way:

👉 **3 parts (in order):**

1. **Left Boundary** (excluding leaf nodes)
2. **All Leaf Nodes** (left → right)
3. **Right Boundary** (excluding leaf nodes, but added in reverse)

---

# 🌳 Visual Understanding

![Image](https://images.openai.com/static-rsc-4/EN5PI5WzzTXwcyYVdvlOcrWZH7JmeWzmloBKPUoC2lgn_fgFcjvwhSeiNQtaYmCLMnO49R9pRZRa_fynPf7AMwdCDLgB3fIx4U2uQ4W_DmyxpcxDR6mMzfmzxvmNrHp0LZTGp4dRRIhyjSo3n7Uz9iryyNDrVfoNNdYhKx_M4v47Eeib3UUi-PfCnjehkqvz?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/jpiV5SHQV1RVCdGeVxIuXVP0HjrJYlSYGnfW723ve9O5WMzTX9CKBzRl0sRRLVB4g30Qjv1tsj-nk59rPGnYIrsqz0yEjCK-VXsD_xmTdY8q_XV0lUS_krrlhsihaS1yDCnbRrlyR5D1jvKtbFkgqUlfSkT0IWHmG5iwTpeTYO13LvG3mdr47WzloMnqjFkl?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/sTYJ3O-d-4QdaQSmHJuVOCGIFUaznXxN8ktmbtX2C3n4IGnyyaKZA5rzEOACY0P7KKTxGdwqKcwCLWpMOt7VBpi3Re9DJ2g7O3Q7fVpQwa3fabPXYUbVSWa9yIytVCqjzd8JE7FFZZBckGmocNdPuckzEH0h9AB34y9W-HQVw4YANaFsPTa9A8Sb0lHw7Ljb?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/mpuNWQZIt-axqlYGqt7uXXJinPVnLE7CmVJ80y8CDf59N36FfY2KlQlsxl2I99rpET1pufnucCzw50j8sgLMuq41m9NNLiMvE3q2u5iJqOtZcY499n5pcV12K0kWR8JyW-6dGacIC2CnqJTVv8-kqoLxiy0PE_Y7KDmjPjTRhWpwdOUeT0qCjej1q86KVc7O?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/Rihafuz2IBymC14LGXzle0CqXWPMYWPBNt-6bkcOFs39U6-xoeKn-Est3vg1xPxQLrIZSqAa74lGQK_mej98ANmXiJE9gM6Kc8yHVklhcS3FM-Z6ysVl_GnCnpAGyW33Nys3Vc0iabp87aHeDMm2qRxIg-OXwTRXBZGPwh6N9TSlbVDxFx8_-6cljrRqx3V4?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/PhIssKiLI5HHtlJ6ek5geo9Qbz3iETDMiQPR7GAB-NST239JkGm7BIc3rMhGa226YfICa0g_nAQ50GsXYYterZ4TVLSV_Us4OMHrk_uhv4DiQ_5UAiCmi1Yl26gW_TZMESRxZ7vH9Pid5qXhKNs-Oiv_S3aSGKRu5DOntDlEQnjU52YrVtaoHeCTa-TLBL9n?purpose=fullsize)

---

# 🔥 Step-by-Step Approach (This is the real logic)

## ✅ Step 0: Edge Case

* If root is NULL → return empty
* If root is NOT a leaf → add root first

---

## ✅ Step 1: Left Boundary

👉 Start from `root->left`

Rules:

* Go **downward preferring left**
* If left not present → go right
* **Skip leaf nodes**

👉 Why skip leaves?
Because leaves will be added separately (avoid duplicates)

---

## ✅ Step 2: Leaf Nodes

👉 Traverse **entire tree (DFS)**

Rules:

* If node has **no left & no right → it's a leaf**
* Add it

👉 Important:

* This includes leaves from **both left and right subtree**

---

## ✅ Step 3: Right Boundary

👉 Start from `root->right`

Rules:

* Go **downward preferring right**
* If right not present → go left
* **Skip leaf nodes**
* Store nodes in a temporary list

👉 At the end:

* **Reverse this list and append**

---

# ⚠️ Most Common Mistakes (avoid these)

❌ Adding leaf nodes in left/right boundary
❌ Not reversing right boundary
❌ Adding root twice when it's a leaf
❌ Forgetting edge case of single node tree

---

# 🧩 How to Think Structurally (THIS is what interviewer wants)

Break problem into **3 helper functions**:

* `addLeftBoundary(root)`
* `addLeaves(root)`
* `addRightBoundary(root)`

Each function has a **very clear responsibility** → no confusion

---

# 🧠 Mental Model (Super Important)

Think like this:

> “I am walking around the tree edge like a boundary wall”

* Left side ↓
* Bottom leaves →
* Right side ↑ (reverse)

---

# ⏱️ Complexity

* **Time Complexity:** `O(N)`
  (you visit each node at most once)

* **Space Complexity:**

  * `O(H)` recursion stack (for leaf traversal)
  * `O(N)` result storage

---

# 💡 Final Intuition (1-line memory trick)

👉
**Left (no leaves) → Leaves → Right (no leaves, reversed)**

---
---
---
---
---
---



👉 You **do NOT need 3 separate data structures**.

---

# ✅ Correct Approach (Clean & Optimal)

You can use:

* ✔️ **1 single result vector**
* ✔️ **3 helper functions** (for clarity)

---

# 🧠 How Data Flows (Important)

Instead of this ❌:

```
left = []
leaf = []
right = []
merge them
```

Do this ✅:

```
result = []

add root
add left boundary → directly into result
add leaves → directly into result
add right boundary → store temporarily → reverse → add to result
```

---

# ⚠️ Only ONE Extra Structure Needed

👉 For **right boundary**, you need a temporary list because:

* It must be added in **reverse order**

So:

* Left boundary → directly push into result
* Leaves → directly push into result
* Right boundary → store in temp → reverse → push

---

# 🧩 Structure in Your Head

Think like this:

```
vector<int> result;

addRoot()

addLeftBoundary(result)

addLeaves(result)

vector<int> tempRight;
addRightBoundary(tempRight)
reverse(tempRight)
append to result
```

---

# 🔥 Why This is Better

* Saves space (no unnecessary arrays)
* Cleaner logic
* Matches interview expectations
* Avoids merging complexity

---

# ⚠️ Common Beginner Mistake (you were heading here)

> “Let me store everything separately and combine later”

That works, but:

* More memory
* More bugs (especially duplicates)
* Not elegant

---

# 💡 Final Mental Shortcut

👉
**1 result + 1 temporary (only for right boundary)**
That’s it.







---
---
---
---
---
---



# 🧠 What does “Add Leaves” really mean?

👉 It means:

> **Collect all nodes that have no children (leaf nodes), from left to right**

That’s it. Sounds simple—but the **way you reach them matters**.

---

# 🌳 Visual Idea

![Image](https://images.openai.com/static-rsc-4/2JLIcCBOlVX5FBGAU_FNtj2fP41GF-fnL8fNDAQc48GNzFgADB-0s1wo1Scz6DgE3f3WRFH1itu_IBn739aCHCpoWGRxXZYWab30cH3c11K4xaclA4Nkc5bGSitTl9MT26_IyXdkMZTlmcLTcllYM1SboXMHHFDJB8z-l2w2Aco7NjIy9xjicLewdj6k7xVd?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/f2d_m69MtOOH9gO83QkC0bSt7392mKlgqT5eMTrcqklA_vCEt7FPPEiACw2oFSG7Ftu1H4TqAq6vzu1ocGaBT785dyYh59KNOde6nQSLY5QhRegECSjseJlcdHUYJ3r1GLLkwwiOtRMpZNEPtVv2cJDiXKHRObRdTnyxl3BBirW7bPh9-lpc9UsA37tVe1no?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/ZCBgc6KhkNwnaSsbsOtbwqGxcPIkZYPPfezbHpQFA9muPbfr3SuS6IVpCxUsTje7UC-BrvoXfJeVVvHOLe91_HAkwh8LKi2Slwf_2FCCxF8akGUDCrdl5k1QD1B55DAryEACDWffy1eso8J1LoUlTwN5bzkZ34yttDRZfCtmnrlvXUpmAmpa43UrvolMZao6?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/H5FSIer4qAEIvM38FBWdqK3mgqvysa0u8Bp3jLGf2Kefj5OICinxEtPFb7rfug7Wnzi0gNAzG5HUD4pQvi2RP2WeynfKkVw41grP-uzltlk-8PWRBTxRQmjmRsvJP7DUoCIDMqmlDjLmRHI_iJpNR18zBTtlzftMr6TpkvlLjluTgvqu3DIM64c6pu816sn_?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/CGOgDblBglZsIGJezcHYgipbAfpCzh36WdC7u6W7G5dm7dEgiuPKyuo22NEkzxCbxJgY3yZFKHcpRQ9kqYDMoL7Yq_CakhCZge5PatDieKQGeUWjkIf7Yfkm_YSU-FicszBUSh7jkGxciUDS3QgEwDNfaxO6u2pE4Wl1vlHGFEXxyFubqB9QnYnLDpN2yA4X?purpose=fullsize)

---

# 🔥 Core Concept (Very Important)

Unlike left/right boundary:

* ❌ You are NOT following one path
* ❌ You are NOT prioritizing left/right only

👉 You must **visit the entire tree**

---

# ✅ How You Should Think

Imagine you're saying:

> “Go everywhere in the tree, and whenever you find a node with no children → pick it.”

---

# 🧭 Traversal Strategy

👉 Use **DFS (Depth First Search)**

Why?

* DFS naturally goes **left → right**
* That ensures leaves are collected in correct order

---

# 🧩 Mental Flow

At every node:

1. If node is `NULL` → ignore
2. If node is a **leaf** → add it
3. Otherwise:

   * go left
   * go right

---

# ⚠️ Important Observations

### 1. Leaves include BOTH sides

* Left subtree leaves ✅
* Right subtree leaves ✅

👉 No discrimination

---

### 2. Order matters

You must get:

```
leftmost leaf → ... → rightmost leaf
```

👉 That’s why:

* Traverse **left first**
* Then **right**

---

### 3. No duplication rule

Remember:

* Left boundary ❌ should NOT include leaves
* Right boundary ❌ should NOT include leaves

👉 So **leaves are added only here**

---

# 💡 Key Difference From Left Boundary

| Left Boundary   | Leaves            |
| --------------- | ----------------- |
| Follow one edge | Visit entire tree |
| Skip leaves     | Only pick leaves  |
| Directional     | Full traversal    |

---

# 🧠 One-Line Memory Trick

👉
**“Traverse whole tree, pick only nodes with 0 children”**

---

# 🔥 Common Mistakes

❌ Only traversing left subtree
❌ Missing right subtree leaves
❌ Adding leaves twice (if also added in boundary)
❌ Using BFS and messing up order

---

# 🎯 Final Intuition

Think like this:

> Left boundary = left wall
> Leaves = ground floor
> Right boundary = right wall

You need the **entire bottom layer**, not just edges.


---
---
---
---
---
---
---

# 🧠 What is “Right Boundary”?

👉 It means:

> **All nodes on the right edge of the tree (excluding leaves), but added in bottom-up order**

---

# 🌳 Visual Understanding

![Image](https://images.openai.com/static-rsc-4/1cidhgY8mFyTL58efs9BwtDQJOO1sNCFhlmXZSi4abcp4HPiI97w5yyvyTOZlRuW1FBUjijGnlq8JIhwNZgUaV8mCtbZ93QsHHT47J6v7rzk8S3hs-UyLVooC-aXJFsYhmDRh9KDVctAneKcCuBMZ74tyuvo4mjC5zT57jZUY1LqIYuBzcZ-lKasLlUzyIz7?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/Rihafuz2IBymC14LGXzle0CqXWPMYWPBNt-6bkcOFs39U6-xoeKn-Est3vg1xPxQLrIZSqAa74lGQK_mej98ANmXiJE9gM6Kc8yHVklhcS3FM-Z6ysVl_GnCnpAGyW33Nys3Vc0iabp87aHeDMm2qRxIg-OXwTRXBZGPwh6N9TSlbVDxFx8_-6cljrRqx3V4?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/sTYJ3O-d-4QdaQSmHJuVOCGIFUaznXxN8ktmbtX2C3n4IGnyyaKZA5rzEOACY0P7KKTxGdwqKcwCLWpMOt7VBpi3Re9DJ2g7O3Q7fVpQwa3fabPXYUbVSWa9yIytVCqjzd8JE7FFZZBckGmocNdPuckzEH0h9AB34y9W-HQVw4YANaFsPTa9A8Sb0lHw7Ljb?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/mpuNWQZIt-axqlYGqt7uXXJinPVnLE7CmVJ80y8CDf59N36FfY2KlQlsxl2I99rpET1pufnucCzw50j8sgLMuq41m9NNLiMvE3q2u5iJqOtZcY499n5pcV12K0kWR8JyW-6dGacIC2CnqJTVv8-kqoLxiy0PE_Y7KDmjPjTRhWpwdOUeT0qCjej1q86KVc7O?purpose=fullsize)

---

# 🔥 Core Difference from Left Boundary

| Left Boundary | Right Boundary       |
| ------------- | -------------------- |
| Top → Bottom  | Bottom → Top ❗       |
| Directly add  | Store then reverse ❗ |
| Prefer left   | Prefer right         |

---

# 🧭 Traversal Logic

👉 Start from:

```
root->right
```

Then at each step:

1. If node is NOT a leaf → consider it
2. Move:

   * If right exists → go right
   * Else → go left

👉 Same structure as left boundary, just mirrored

---

# ⚠️ The MOST IMPORTANT PART

👉 You **CANNOT directly push into result**

Because order should be:

```
bottom → up
```

But traversal naturally gives:

```
top → down
```

---

# ✅ So What Do You Do?

👉 Use a **temporary storage**

Flow:

```
collect nodes (top → down)
reverse them
append to result
```

---

# 🧩 Mental Flow

While traversing:

* Skip leaf nodes
* Store nodes in temp list

After traversal:

* Reverse temp
* Add to result

---

# ⚠️ Why skipping leaves again?

Because:
👉 Leaves are already handled in **leaf traversal**

If you include them here:
❌ duplication happens

---

# 🧠 Example Thinking

Tree:

```
    1
     \
      2
       \
        3
```

👉 Right boundary nodes:

* 2 (not leaf)
* 3 ❌ (leaf → skip)

👉 Stored:

```
[2]
```

👉 Reverse:

```
[2]
```

---

# 💡 Key Intuition

Think like this:

> “I walk down the right edge… but I report it while coming back up”

---

# 🔥 Common Mistakes

❌ Forgetting to reverse
❌ Including leaf nodes
❌ Starting from root instead of `root->right`
❌ Adding directly to result (wrong order)

---

# 🧠 One-Line Memory Trick

👉
**“Go right if possible, else left, skip leaves, store & reverse”**

---

# 🎯 Final Big Picture (Now you know all 3)

1. Left boundary → top-down
2. Leaves → left to right
3. Right boundary → bottom-up
