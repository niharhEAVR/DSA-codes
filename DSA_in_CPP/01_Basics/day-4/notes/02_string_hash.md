### 🧩 Step 1: The Goal

We want to **count how many times each character (a–z)** appears in a string:

```cpp
string s = "fheufgeckebndqakjcibgw";
```

---

### 🧠 Step 2: What is the hashing array?

```cpp
vector<int> hash(100, 0);
```

This creates a **hash table** (actually just an array here) of size `100`,
and initializes all values to `0`.

Think of it as:

```
hash[0] = 0
hash[1] = 0
...
hash[99] = 0
```

Each index will represent a **character**, and the value will represent its **frequency**.

---

### ⚙️ Step 3: Understanding `ch - 'a'`

Let’s take an example character `'f'`.

In C++:

```cpp
'a' → ASCII value = 97  
'f' → ASCII value = 102
```

So:

```cpp
ch - 'a' = 102 - 97 = 5
```

That means `'f'` will be stored at index **5** of the hash array.

👉 This maps characters `'a'` → index 0, `'b'` → index 1, `'c'` → index 2 … `'z'` → index 25.

So effectively, you have a **fixed mapping** between character → index in array.

---

### 🧮 Step 4: How hashing works here

When you write:

```cpp
hash[ch - 'a']++;
```

You are saying:

* Find the index based on the ASCII distance from `'a'`
* Increment the frequency count for that letter.

Example with `"fheufgeckebndqakjcibgw"`:

| Character | ASCII | ch - 'a' | hash index | hash[index] before | hash[index] after |
| --------- | ----- | -------- | ---------- | ------------------ | ----------------- |
| f         | 102   | 5        | 5          | 0                  | 1                 |
| h         | 104   | 7        | 7          | 0                  | 1                 |
| e         | 101   | 4        | 4          | 0                  | 1                 |
| u         | 117   | 20       | 20         | 0                  | 1                 |
| f         | 102   | 5        | 5          | 1                  | 2                 |
| ...       | ...   | ...      | ...        | ...                | ...               |

At the end of the loop, `hash[5] = 2` means `'f'` appeared 2 times.

---

### 🧠 Step 5: Why this is efficient

* No searching.
* No nested loops.
* Direct access: **O(1)** time per character.
* Total: **O(n)** for entire string (n = length of string).

---

### 🧱 Step 6: Memory usage

You said:

> "if we use the hashing function by normal array then that can only possible of 10⁶ in main and 10⁷ in global — what does that mean?"

Let’s connect that now 👇

In C++:

* Local arrays (inside main or function) are stored in **stack memory** → limited (~1MB to 8MB).

  * So, at most about **10⁶ (1 million)** `int` elements.
* Global arrays are stored in **heap/static memory**, which is much larger.

  * So, at most about **10⁷ (10 million)** `int` elements.

But in this case, our array is only of size 26 (for 26 letters),
so memory usage is tiny and safe.

---

### 🔍 Step 7: Printing the results

```cpp
for (auto ch : s)
{
    if (hash[ch - 'a'] > 0)
    {
        cout << ch << " occurs " << hash[ch - 'a'] << " times" << endl;
    }
}
```

This checks each character again and prints how many times it occurred.
(Though this prints duplicates — we could use a `set` to avoid that.)

---

### ✅ Summary

| Concept            | Meaning                                          |
| ------------------ | ------------------------------------------------ |
| `hash[ch - 'a']`   | Converts a character into an array index (0–25). |
| `hash[ch - 'a']++` | Increments frequency count of that character.    |
| Array `hash[]`     | Stores frequency of each character.              |
| Memory used        | O(1) — only 26 integers.                         |
| Time complexity    | O(n).                                            |
