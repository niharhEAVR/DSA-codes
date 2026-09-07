This is actually one of the **most important concepts in Data Structures & Algorithms**. Once you understand this, you'll be able to analyze almost every algorithm.

Let's build it from **zero**, assuming you've never seen it before.

---

# Step 1: What is Time Complexity?

Time Complexity **does NOT measure actual time** (seconds or milliseconds).

It measures:

> **How does the number of operations grow as the input size grows?**

For example:

```cpp
for (int i = 0; i < n; i++)
    cout << i;
```

If

```
n = 5
```

Loop runs

```
5 times
```

If

```
n = 100
```

Loop runs

```
100 times
```

If

```
n = 1,000,000
```

Loop runs

```
1,000,000 times
```

So we say

```
Time Complexity = O(n)
```

because the work grows **linearly** with `n`.

---

# Step 2: What exactly is the "input"?

This is where beginners get confused.

Sometimes the input is

```
number of elements
```

Sometimes

```
number of nodes
```

Sometimes

```
number of characters
```

Sometimes

```
the value of a number
```

The input depends on the problem.

For example

### Array

```cpp
vector<int> arr;
```

Input size =

```
number of elements
```

If there are

```
100 elements
```

then

```
n = 100
```

---

### String

```
"Hello"
```

Input size =

```
5
```

because there are 5 characters.

---

### Tree

Input size =

```
number of nodes
```

---

### Integer problems

Here is where today's confusion came from.

Suppose

```
n = 153
```

The input isn't the number of digits.

The input is

```
153
```

---

# Step 3: Why isn't digit extraction O(n)?

Look at this loop:

```cpp
while (n > 0)
{
    n /= 10;
}
```

Let's see how many times it runs.

---

For

```
n = 153
```

```
153
15
1
0
```

Loop ran

```
3 times
```

---

Now

```
9999
```

```
9999
999
99
9
0
```

Runs

```
4 times
```

---

Now

```
123456789
```

Runs

```
9 times
```

---

Notice something?

The loop doesn't care about

```
153
```

It cares about

```
3 digits
```

---

# Step 4: What is the relation between digits and the number?

This is the part almost every beginner skips.

Let's write some numbers.

```
9
```

Digits =

```
1
```

---

```
99
```

Digits =

```
2
```

---

```
999
```

Digits =

```
3
```

---

```
9999
```

Digits =

```
4
```

---

```
99999
```

Digits =

```
5
```

Notice the pattern?

Every extra digit means the number becomes about **10 times larger**.

| Digits | Largest Number |
| ------ | -------------- |
| 1      | 9              |
| 2      | 99             |
| 3      | 999            |
| 4      | 9999           |
| 5      | 99999          |

So if the number grows like

```
10
100
1000
10000
100000
```

the number of digits grows like

```
1
2
3
4
5
```

This is exactly what a **logarithm** measures.

---

# Step 5: What is a logarithm?

Forget the scary math.

Think of it like this.

Multiplication asks:

```
10 × 10 × 10 = ?
```

Answer

```
1000
```

Logarithm asks the opposite question:

> **How many times do I multiply 10 by itself to get this number?**

Example

```
1000
```

Multiply

```
10 × 10 × 10
```

Three times.

So

```
log₁₀(1000) = 3
```

---

Another

```
100000
```

```
10
100
1000
10000
100000
```

Five multiplications.

So

```
log₁₀(100000)=5
```

---

Now look carefully.

```
100000
```

has

```
6 digits
```

and

```
log₁₀(100000)=5
```

That's why the exact formula is

[
\text{digits}=\lfloor \log_{10}(n)\rfloor+1
]

You don't need to memorize it now. Just remember:

> **The number of digits grows logarithmically with the value of the number.**

---

# Step 6: So why O(d) = O(log n)?

Suppose

```
n = 987654321
```

It has

```
9 digits
```

Your loop runs

```
9 times
```

You can say:

```
O(9)
```

or more generally:

```
O(d)
```

where `d` = number of digits.

But since

```
digits = log(n)
```

you can also write

```
O(log n)
```

They describe the same amount of work from different perspectives.

---

# Step 7: A bigger example

Suppose someone says

```
n = 1,000,000,000
```

Does your loop run one billion times?

No.

```
1000000000
100000000
10000000
1000000
100000
10000
1000
100
10
1
0
```

It runs only **10 times** because there are only **10 digits**.

This is why digit-processing algorithms are very efficient.

---

# Other important time complexity concepts you'll encounter

As you learn DSA, you'll repeatedly see these:

| Time Complexity | Typical Situation                                                                          |
| --------------- | ------------------------------------------------------------------------------------------ |
| **O(1)**        | Access an array element, push/pop from a stack (average), hash lookup (average)            |
| **O(log n)**    | Binary Search, operations on balanced BSTs, digit extraction, repeated division by 2 or 10 |
| **O(√n)**       | Checking factors of a number, primality tests by trial division                            |
| **O(n)**        | Single loop through an array or string                                                     |
| **O(n log n)**  | Merge Sort, Heap Sort, average/worst-case operations in many divide-and-conquer algorithms |
| **O(n²)**       | Two nested loops over the same input, Bubble Sort, Selection Sort                          |
| **O(2ⁿ)**       | Generating all subsets using recursion                                                     |
| **O(n!)**       | Generating all permutations                                                                |

---

# A simple trick to recognize complexities

When you see code, ask yourself:

* `i++` or `i--` → usually **O(n)** (one step at a time)
* `i *= 2` or `i /= 2` → usually **O(log n)** (input shrinks or grows exponentially)
* `n /= 10` → **O(log₁₀ n)**, which is **O(log n)**
* Two independent loops of size `n` → **O(n) + O(n) = O(n)**
* Nested loops, each up to `n` → **O(n²)**

---

## What I recommend next

Don't try to memorize every complexity. Instead, learn **why** each one appears.

A great learning order is:

1. **Big O notation** (what it means and how to ignore constants)
2. **O(1), O(log n), O(n), O(n²)** with lots of examples
3. **Why nested loops are sometimes not O(n²)** (this is a very common interview trap)
4. **Time complexity of recursion**
5. **Space complexity**

Once you understand those five topics, you'll be able to analyze the vast majority of LeetCode solutions with confidence.
