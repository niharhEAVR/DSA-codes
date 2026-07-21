# 🧠 Core Idea (Difference from Top View)

> **Bottom View = last visible node at each vertical line (HD)**

👉 In Top View you did:

* “first come → store”

👉 In Bottom View you do:

* **“last come → overwrite”**

---

# 🌳 Visual Understanding

![Image](https://images.openai.com/static-rsc-4/p08AF1jJIGQRdeYWmuTAD-agmnbjPWK1PPdzZtjOevxm7et6-DbaqAV_TcGdPB-TNJL5sicFrlSqWKztPjkaFu6rWIZpTindoa15JDObEwieua6L-gqcQ0_WIWZlzbr7tUzzBjMRKO-Dl_6T8chTjKQBrcQ-S3EPA2gglQUPPbb2PYWrKsgOwUJ3AK2_Pxxt?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/S5fe0XNUWvdrx4L-u80OZVLA0t0GYjkMbdJWf5k69dW8aD341uIBVmO8o5P_v55BmZO_GTB70Au5DURgmpwD8agbMCWjRpk8if3aIyaxqHpEoMkqqfaG9-cg69eV2IbbqazrOFEtOeaKPbxUTNbNRxrqg84RrNktFQc2Gm1UhCCfhBOuCnu_SqTOCzOjAO5U?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/Ky6WSEsozQI8IcMNTiZ5dwAZ8WS-3qCZL_3jMkUvG3h3MhIB7qGGhMYp00HT2fBAQd7SC8vnLNRoRBTtW44brvBRq-6nfLeN_NHmKEWYDmS4CP34t3VwebVoK6RO8XT7gm9OBvFi5_Zae8PqrEm5UUuNyq25g8H-4H0ywKc6rDbNmj9VZFTTnFrlxZcVzJn6?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/9AN0FiQSx2LG2u53gVLUOmZ1nqrvem1hb6WU-6M2dCZVl9Oq2p_tzJCVnGyQww1rfm3Cbw8OQnw8A_4ZrdIUuIj6ar1-Q_FSeychfNoxdKwUFvodPNQSTqXzz9hQl58N9dlM_1pDsorLVbycuaKOnLqWm071xOZnGjgckQm4UboWWfpIUUrufPmsEXFDt9Zg?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/Mx2JRPlygGAlZFYX7sKtjrBV-k0YMs3SlfUgMKnCLJmAAnOPQnCG8Qt1jNb85juq6dKI8ejps7hjcDBZkbl4PVASH0PRm59hkmEFcg9NHcp_lsDarwtXErPeC3ILPFXW-sf4NTzVM4woK2Dr8h5KkoRES4HG9vkD-ZHk3G9J9zruvmAR9B3M9of-GI-LHCCw?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/Lu1o8WLla2mPXpP20G3TP0Rjm_kIJOVLH4WwClVhA44TYDbNbI1Z30qxEWXv2cR8-nOHtf7mKTIOiUXfKQQVLgcm85GyiKiQCPpgObF8uk464Kn2Ng8SefMpR1MDYA6vpsYQhN3cRiu3idLKTczIpE0E_HSCkajwugXsAvUhxjenOT71cq4Sotr3A6tRoLtI?purpose=fullsize)

Tree:

```text
        1 (0)
      /       \
   2(-1)     3(+1)
      \       /
      4(0)   5(0)
```

---

# 🔍 HD Mapping

| Node | HD |
| ---- | -- |
| 1    | 0  |
| 2    | -1 |
| 3    | +1 |
| 4    | 0  |
| 5    | 0  |

---

# 🔁 BFS Step-by-step (IMPORTANT CHANGE)

### Start:

```text
Map = {}
Queue = [(1,0)]
```

---

## Step 1: Node 1

```text
Map[0] = 1
```

---

## Step 2: Node 2

```text
Map[-1] = 2
```

---

## Step 3: Node 3

```text
Map[+1] = 3
```

---

## Step 4: Node 4

👉 Same HD = 0
BUT NOW:

```text
Map[0] = 4   (overwrite 1)
```

---

## Step 5: Node 5

```text
Map[0] = 5   (overwrite 4)
```

---

# 🎯 Final Map

```text
HD   Node
-1 → 2
 0 → 5
+1 → 3
```

---

# ✅ Bottom View Answer

```text
2 5 3
```

---

# 🔥 Key Difference (MOST IMPORTANT)

| Feature         | Top View           | Bottom View      |
| --------------- | ------------------ | ---------------- |
| Store condition | only if not exists | always overwrite |
| Logic           | first node         | last node        |
| Map update      | once               | every time       |

---

# 🧠 Code Logic Change (JUST ONE LINE!)

### Top View:

```cpp
if (nodes.find(hd) == nodes.end()) {
    nodes[hd] = node->val;
}
```

---

### Bottom View:

```cpp
nodes[hd] = node->val;
```

👉 No condition — just overwrite

---

# ⚠️ Why BFS still works?

Because BFS goes **level by level**

👉 Lower nodes come later
👉 So they automatically overwrite upper ones

---

# 💡 Mental Model

> “Each vertical column keeps updating with deeper nodes”

---

# 🧮 Complexity

Same as before:

* **Time:**
  [
  O(N \log N)
  ]

* **Space:**
  [
  O(N)
  ]

---

# 🔥 One-line Summary

> Top View → first node per HD
> Bottom View → last node per HD

---
---
---
---
---
---


# 🧠 First: What you misunderstood

You were (probably) thinking:

> “Bottom view = deepest node at each HD”

❌ That sounds logical… but it’s **not how the problem works**

---

# ✅ Correct Rule (VERY IMPORTANT)

> Bottom View = **last node you see at each HD during BFS**

Not deepest.
Not biggest value.
👉 Just **last visited in level order**

---

# 🌳 Let’s Rebuild the Tricky Example Slowly

![Image](https://images.openai.com/static-rsc-4/Mx2JRPlygGAlZFYX7sKtjrBV-k0YMs3SlfUgMKnCLJmAAnOPQnCG8Qt1jNb85juq6dKI8ejps7hjcDBZkbl4PVASH0PRm59hkmEFcg9NHcp_lsDarwtXErPeC3ILPFXW-sf4NTzVM4woK2Dr8h5KkoRES4HG9vkD-ZHk3G9J9zruvmAR9B3M9of-GI-LHCCw?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/p08AF1jJIGQRdeYWmuTAD-agmnbjPWK1PPdzZtjOevxm7et6-DbaqAV_TcGdPB-TNJL5sicFrlSqWKztPjkaFu6rWIZpTindoa15JDObEwieua6L-gqcQ0_WIWZlzbr7tUzzBjMRKO-Dl_6T8chTjKQBrcQ-S3EPA2gglQUPPbb2PYWrKsgOwUJ3AK2_Pxxt?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/bBUECWBkodZANQGBccoRx9sL9B5200Pg7NYSTa5rgVjHum3PaUMhVYf587T1SVE5tV9PIL8mACX80jx8VNPanHC_HXoFQSXOu2P1nKNjKlrHWXonVySE8ZoTcKyhg2lCBs6LKO98oKTe2OMmB22lED0-ZhCNn89LaLxcwYpJsmaTrUTNsEnxaJfGOFx0GZ3A?purpose=fullsize)

![Image](https://images.openai.com/static-rsc-4/TTGI8oR0dPGv5tMPUGW9RGNFCjd-jrianvDAoff4EkVpMqZjAzpt1iaegB5xY5Q2avEwaeJkcdPuCtYB8rWYVDK9C8kce6Zzt-1H7oFQq1YBGaRNFamjFDhPJFdIoZJBKbYYRg7Z-E45FJG7GyTavmWQRbcSmqcFp5_wdEF-kpKUzBMPy8iBBEiNoHoOR3rB?purpose=fullsize)

Tree:

```text
              1 (0)
           /         \
       2(-1)        3(+1)
         \          /   \
         4(0)     5(0)  6(+2)
        /             \
     7(-1)            8(+1)
```

---

# 🔁 Now we simulate BFS (THIS is the key)

## Step-by-step (focus only on HD updates)

---

### Step 1: Visit 1

```text
Map[0] = 1
```

---

### Step 2: Visit 2

```text
Map[-1] = 2
```

---

### Step 3: Visit 3

```text
Map[+1] = 3
```

---

### Step 4: Visit 4

```text
Map[0] = 4   ← overwrite 1
```

👉 Why? Because we don’t care about “top” anymore

---

### Step 5: Visit 5

```text
Map[0] = 5   ← overwrite 4
```

---

### Step 6: Visit 6

```text
Map[+2] = 6
```

---

### Step 7: Visit 7

```text
Map[-1] = 7  ← overwrite 2
```

---

### Step 8: Visit 8

```text
Map[+1] = 8  ← overwrite 3
```

---

# 🎯 Final Map

```text
HD   Node
-1 → 7
 0 → 5
+1 → 8
+2 → 6
```

---

# ❗ Now the REAL QUESTION

You might ask:

> “Why did 5 win over 4 and 1?”

👉 Answer:
Because **it came later in BFS**

---

# 💡 Super Simple Way to Think

Forget depth. Forget tree.

Just think:

```text
Each HD = 1 slot
Whenever a new node comes → replace old one
```

---

# 🧪 Mini Simulation (Even Simpler)

For HD = 0:

```text
1 comes → store
4 comes → replace
5 comes → replace
```

👉 Final = 5

---

# ⚠️ Why this is called “tricky”

Because your brain wants to think:

* deeper node wins ❌
* lower level wins ❌

But actual rule is:

👉 **later in BFS wins**

---

# 🔥 One-line Truth

> Bottom View = “last write wins for each HD”

---

# 🧠 If still confused, answer this:

For HD = 0, nodes came in this order:

```text
1 → 4 → 5
```

👉 Who should be answer?

✔️ The last one → **5**
