# 🌳 What is a Binary Search Tree (BST)?

A **Binary Search Tree (BST)** is a special type of binary tree where **nodes follow a strict ordering rule**.

### 🔑 Core Rule (MOST IMPORTANT)

For every node:

\[
\text{Left Subtree} < \text{Node} < \text{Right Subtree}
\]

That’s it. Everything in BST revolves around this one rule.

---

# 📌 Simple Example

![Image](https://images.openai.com/static-rsc-4/pVM4soIwBLQp5cdouVFl9EnfNkd_j-ll8vuIldQAtcig5ZODt4yS1vYu17uisbKCWERi4FLzQMoxObLKEMwPwInNHcmOKNgQrqyNogP9hLYEGBV5MbuYQicdZUViFqaDfbja392rUcnzC_vYX4nTNaWkVctb0esc88OzB08AbGcJU9A6G_4FC9YeCCP2kfv1?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/F1yYcEZkjgqIoXPfw7uIpQ9DkiGb2rAP-p4gmiQgqmzVw-gMCL6RmTF5FI6b850h_56bwvcBrmHb9Z9vtFbeeqxsGBpCMyz3A8khb6v4UW35TCL8zNnEIDOAqHyljcA_YqKIO7-2MTNDOyH7OU0AIhNwOOgnifx7kDCZN_wDTkaFXVLuyGWF0fPklokQpu3_?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/CUekWqrE-yIQIjZsxXEVzVI_IjQtuedbMsCnQSv__ql3GNAGbE2RxHdkiDCLNZRYqlLYciHZW-XbaOjs1tbsaanJRYVFwtc3RqdGllgZTwTwSMRjM_7Y5FT-CWeslbyAjirfhnvwwkDWrR1RnIBCbZFr60an_a6OfOWy1q3UCbN9hm1mPKXCGgbc7CgYc3Tx?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/WLidRKnQuh2vcbCYESXTbCUc58ukr7GGlpBODMh0aj1v-tLSKq8ZyAt8JyWdjrTIQ5sEipsGB8i17_JQ7TGDP5Hzgs9ZarWlZreHFkVVfGGR1dVwWvOw8do0fe5k03wiv0qoBgwoVOK3-z3WguUErpHRPnzG25Pxl0C6Lzcza00ye4Q6ZvJ1DTTJ-Z44bu3V?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/iHAvyAZq1AG8v3Wq8MALM2lg-Y7PfN-c8w5yauE-wwhpFqSzbtE5vF-TJxylXmfdRFp6E9rWUjPmJ50dnET8VkGKohg10qBSz_lYxVec_R95GhMiYFHhf4j3V-8aRVcV0VPlv4w4Lyfvgzenvkz5otTwwFDL46CVrRldw0RAyMKrdGwAO7uEPEyzTgu4vuz6?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/4mGSLVj22XjcBfBo7bahouhSKXnNA-x4XN65x3hpGCplR6jePXVHHZRoc3iBHhGNDODZYr4Fjp3trWKtE_CrsE4j2WS8sZ_CuorDmn-8qLwc3lEbc6m4NAj1ZM6x0NR_dU9vLSKfrx_8sCGVqXY_NyUmWF1eelzbWnztci9TYt-4q25Yrk9bEqeqScBuJc3K?purpose=fullsize)

Consider this tree:

```
        10
       /  \
      5    15
     / \     \
    2   7     20
```

Now check:

* Left of 10 → {5, 2, 7} → all **< 10**
* Right of 10 → {15, 20} → all **> 10**

Same rule applies **recursively** to every node.

---

# 🧠 Why BST is Special (Compared to Normal Binary Tree)

In a normal binary tree:

* No order → searching = **O(n)**

In a BST:

* Ordered → you can **skip half of the tree each time**

👉 Just like **Binary Search in arrays**

---

# 🔍 How Searching Works (Step-by-Step Thinking)

Let’s search for `7`:

1. Start at root (10)

   * 7 < 10 → go LEFT
2. Now at 5

   * 7 > 5 → go RIGHT
3. Found 7 ✅

👉 You didn’t check all nodes — you followed the rule.

---

# ⚡ Time Complexity (Very Important)

| Operation | Best / Avg | Worst |
| --------- | ---------- | ----- |
| Search    | O(log n)   | O(n)  |
| Insert    | O(log n)   | O(n)  |
| Delete    | O(log n)   | O(n)  |

### ❗ Why worst case O(n)?

If tree becomes like:

```
1
 \
  2
   \
    3
     \
      4
```

👉 This is basically a **linked list**, not a balanced tree.

---

# 🌱 Key Operations in BST

## 1. Insertion (Logic)

* Start at root
* Compare:

  * smaller → go left
  * bigger → go right
* Insert at first NULL position

---

## 2. Searching

Same logic as insertion — just stop when found.

---

## 3. Deletion (Concept Only)

This is the only tricky one:

### Cases:

1. **Leaf node** → just delete
2. **One child** → replace with child
3. **Two children** →
   replace with:

   * **Inorder successor (smallest in right subtree)** OR
   * **Inorder predecessor (largest in left subtree)**

---

# 🔥 Golden Property (Interview Favorite)

👉 **Inorder Traversal of BST = Sorted Order**

Example:

```
Inorder → Left → Root → Right
Result → 2 5 7 10 15 20
```

---

# 🧠 Intuition in One Line

> BST = Binary Tree + Sorting Logic Built-In

---

# ⚠️ Common Beginner Mistakes

* Thinking only immediate children matter ❌
  → Entire left subtree must be smaller
* Forgetting recursion rule ❌
* Assuming BST is always balanced ❌

---

# 🚀 What You Should Do Next

Since you already did binary tree, now go in this order:

1. **Search in BST**
2. **Insert in BST**
3. **Validate BST**
4. **Delete in BST**
5. **Kth smallest element**
6. **Lowest Common Ancestor in BST**

---

If you want, I can now:
👉 Teach you **BST insertion step-by-step with dry run (like interview)**
👉 Or give you a **tricky BST question where intuition breaks**


---
---
---
---
---
---
---



Short answer: **by default → NO, BST usually does NOT allow duplicates.**
But… in practice → **it *can* allow duplicates depending on implementation.**

Let’s clear this properly 👇

---

# 🌳 Standard Definition (What you should assume in interviews)

A **Binary Search Tree (BST)** follows:

[
\text{Left Subtree} < \text{Node} < \text{Right Subtree}
]

👉 Notice it's **strict inequality (< and >)**
So:

* Equal values ❌ **not allowed**
* Every value must be **unique**

---

# 🤔 But what if duplicates come?

There are **2 common ways** to handle duplicates:

---

## ✅ Approach 1: Force duplicates to one side

![Image](https://images.openai.com/static-rsc-4/l2sTkYvRTYP9JkcqRGCHLDQEZl4b2_RsoRo_N-eX_JDZIpzafe30N29EsQEtyiDhgtjXLNXqh6mXWNKr-tmn4ofIo6MXiYAtO4FtongfsA6n7mkq0SPDCkYwkn-vjhfJ1iz757sC5FC4qvP1ALX7_2Ps8mnpEDViUZT_78lgALqKqu4vjfNQ36d7o_cFtk2w?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/Z5GOWbJgaC_cct9BWX38_seeYS-bjAzefcfap8jsHtBPtrG4y9RB0qvcc-_RE9BO0uKYQeb0OZ-2hCWghGZqNLkqackJPKlqggTbX2QRdbnbzszzyyQ3qj2z9o-Zwj_W79faJzLv3ZqP9yWG9CvgX6XttI3tvsLnwUfx8eu8-3mtiieu26DICpODc_ryBHCT?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/R01hlg0LRJxkE9YIdA9x6jrKPRS36yGkLYqO9BcoRDDVJs82yL-qQ1GnH-CRUEgvPqEasSp2KagMg_p2KXaJWo-izsWVu62Kbr0rx2nrb39VOJxk9nEIPk7gleOoJ3j-dqfWGVWnc48xi_wG204v4lBhEB7owpNZL0HwN_YphhSpxlL9hM1jblwd14kreGfX?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/cjklK7YPA7B3WS5ZbwA68wik9o8USE5-5tgXteEi4e_2xBdDxk7Nz2nX7jBi56rr-HFinEWiN_hcwoZXX12F2SuBm6kD8MDa4rFTydP-qThuDgNuJgHwkl8Lv2MObkXzNtTfT1cPNVvtlDz256F73Lao6NuhvzrHbfNMPF1qzeJ-9GJjyYIlO6ROibWL62Mu?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/lfG_lExIeg-8kR62b0cLGd1YGhsxg9-uKrO3DGLyM3B36IGYTWIGxhu7Ofq0W_PWECq5i3d-uYDIfK6RLQWp4JWb_KZKrh2cq_07z8L0OxcbtNRjpZSNdRcFNSoqd_vy_ClS1TJgl3vz1srg9unLmdDlZUweJUBof0w7Yj0vdP8WKYzxxg8E2tIcGs1lPRhn?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/QBLDnawJCNYXviw88pNeuXkIXDDnHDhoSldFjd4i4RksyV0ib5mq2Ugj79mywHJph2nRWJwSLaYmN1RkYguuGRC5L-r0kr1wyRohByJwXDmVArktc-Rgdm1fzy8GDBUowKveZctbur49AaaBZDO-ZDB8OhfOWvpAwD1kp37ikJaULob7wjAEqc3KPMrZ432f?purpose=fullsize)

Modify rule:

* Left subtree → **< node**
* Right subtree → **≥ node**
  *(or opposite)*

Example:

```id="f9h9yx"
        10
       /  \
      5    10
            \
             10
```

👉 All duplicates go to one side (usually right)

---

## ✅ Approach 2: Store frequency (Better way)

Instead of creating new nodes:

```id="3a3y1g"
Node = {
  value: 10,
  count: 3
}
```

👉 Cleaner, avoids skewed tree

---

# ⚠️ Important Insight (Interview Trap)

If duplicates are allowed:

👉 You must **clearly define the rule**, otherwise BST property breaks.

Because:

* Where will equal values go?
* Left? Right? Both? ❌ (not allowed)

---

# 🧠 What You Should Answer in Interview

If asked:

> “Does BST allow duplicates?”

Say:

👉 “By standard definition, BST does not allow duplicates due to strict ordering.
But duplicates can be handled by either storing frequency or consistently placing them on one side.”

---

# 🔥 One More Important Thing

If duplicates are inserted carelessly:

```id="z7k2sx"
10
 / \
10  10   ❌ INVALID BST
```

👉 This **breaks BST property**

---

# 🚀 Final Intuition

* BST = **Ordered + Predictable traversal**
* Duplicates = **Ambiguity unless rule is defined**