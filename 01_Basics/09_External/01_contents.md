## 🔥 The Core DSA You Actually Need

### Priority 1 — MUST KNOW

These are the foundations you should be able to use without thinking.

1. **Arrays**
2. **Strings**
3. **Searching**

   * Linear Search
   * Binary Search
4. **Sorting**

   * Bubble Sort
   * Selection Sort
   * Insertion Sort
   * `sort()` / custom comparator
5. **Hashing**

   * `unordered_map`
   * `unordered_set`
   * frequency counting
6. **Two Pointers**
7. **Sliding Window**
8. **Prefix Sum**
9. **Basic Recursion**
10. **Stack**
11. **Queue**
12. **Linked List**
13. **Basic Math / Number Algorithms**

These are your **highest-value topics**.

---

# 1. Arrays ⭐⭐⭐⭐⭐

This is probably the **single most important DSA topic** for fresher coding exams.

Know:

* Traversing an array
* Finding max/min
* Sum
* Average
* Counting elements
* Reverse array
* Rotate array
* Find duplicate
* Find missing number
* Remove duplicates
* Second largest
* Frequency
* Subarrays
* Maximum subarray sum
* Kadane's Algorithm

### C++ basics

```cpp
vector<int> a = {1, 2, 3, 4, 5};

for(int x : a)
    cout << x << " ";
```

Know these extremely well:

```cpp
a.size();
a.push_back(x);
a.pop_back();
a.front();
a.back();
a.begin();
a.end();
```

---

# 2. Strings ⭐⭐⭐⭐⭐

Extremely common in aptitude/coding tests.

Know:

* Character traversal
* Reverse string
* Palindrome
* Count vowels/consonants
* Character frequency
* Remove spaces
* Remove duplicate characters
* Anagram
* Substring
* String comparison
* Convert case
* ASCII
* Word counting

Important C++:

```cpp
string s;

getline(cin, s);

s.length();
s.size();

s[0];

s.substr(start, length);

reverse(s.begin(), s.end());
```

Also understand:

```cpp
'a' - 'a' = 0
'b' - 'a' = 1
...
'z' - 'a' = 25
```

This is extremely useful for frequency arrays.

---

# 3. Searching ⭐⭐⭐⭐⭐

## Linear Search

```text
Check every element one by one.
```

Time:

```text
O(n)
```

## Binary Search

Very important.

Requirement:

> **Array must be sorted.**

Time:

```text
O(log n)
```

Know:

```cpp
binary_search()
lower_bound()
upper_bound()
```

And preferably understand how to implement binary search manually.

---

# 4. Sorting ⭐⭐⭐⭐⭐

You don't need to become a sorting-algorithm expert.

Understand the idea of:

### Bubble Sort

```text
Repeatedly swap adjacent elements.
```

### Selection Sort

```text
Find minimum → put it at correct position.
```

### Insertion Sort

```text
Take element → insert into correct position.
```

But in actual C++ coding:

```cpp
sort(a.begin(), a.end());
```

is what you'll usually use.

Also learn:

```cpp
sort(a.begin(), a.end(), greater<int>());
```

and custom comparator.

---

# 5. Hashing ⭐⭐⭐⭐⭐

This is HUGE.

You should be comfortable with:

```cpp
unordered_map<int, int> mp;
```

and:

```cpp
unordered_set<int> st;
```

Most importantly:

## Frequency counting

Example:

```cpp
for(int x : a)
    mp[x]++;
```

Then:

```cpp
mp[x]
```

gives frequency.

For strings:

```cpp
unordered_map<char, int> freq;

for(char c : s)
    freq[c]++;
```

You should immediately think:

> "Frequency/counting → hashmap."

---

# 6. Two Pointers ⭐⭐⭐⭐⭐

Very important problem-solving pattern.

Typical structure:

```text
left →→
       ←← right
```

Common problems:

* Pair sum
* Two sum in sorted array
* Reverse array/string
* Remove duplicates
* Move zeros
* Palindrome
* Container-style problems

For example:

```cpp
int left = 0;
int right = n - 1;

while(left < right) {
    ...
}
```

You should recognize this pattern quickly.

---

# 7. Sliding Window ⭐⭐⭐⭐⭐

Another extremely important pattern.

Used for:

* Maximum sum subarray
* Minimum/maximum window
* Longest substring
* Fixed-size subarray
* Distinct elements
* Frequency-based substring problems

Basic idea:

```text
[ window ]
   ↓
left ------ right
```

Instead of recalculating everything, you **move the window**.

This can turn:

```text
O(n²)
```

into:

```text
O(n)
```

---

# 8. Prefix Sum ⭐⭐⭐⭐⭐

Very easy but extremely useful.

Example:

```text
Array:
2  4  1  5  3

Prefix:
2  6  7  12 15
```

Formula:

```text
prefix[i] = prefix[i-1] + a[i]
```

Used for:

* Range sum
* Subarray sum
* Multiple queries
* Subarray problems

---

# 9. Recursion ⭐⭐⭐⭐

You don't need crazy recursion right now.

Understand:

* Base condition
* Recursive call
* Stack behavior
* Factorial
* Fibonacci
* Sum of digits
* Reverse number/string
* Basic array recursion

Most importantly understand:

```cpp
void solve(...) {
    if(base_condition)
        return;

    solve(...);
}
```

Recursion becomes important later for trees/backtracking.

---

# 10. Stack ⭐⭐⭐⭐

Understand:

```cpp
stack<int> st;
```

Operations:

```cpp
st.push(x);
st.pop();
st.top();
st.empty();
st.size();
```

Concept:

> **LIFO — Last In, First Out**

Common problems:

* Balanced parentheses
* Reverse
* Next greater element
* Previous greater/smaller
* Expression problems

For your exam, **balanced parentheses** is particularly worth knowing.

---

# 11. Queue ⭐⭐⭐⭐

Understand:

```cpp
queue<int> q;
```

Operations:

```cpp
q.push(x);
q.pop();
q.front();
q.back();
q.empty();
```

Concept:

> **FIFO — First In, First Out**

Also know:

```cpp
deque<int>
```

at least conceptually.

---

# 12. Linked List ⭐⭐⭐

Know the fundamentals.

Understand:

```text
Node
 ↓
data | next
```

Know how to:

* Create node
* Traverse
* Insert
* Delete
* Search
* Reverse linked list
* Find middle
* Detect cycle

Basic structure:

```cpp
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
```

For TCS-level coding, you don't need to spend enormous amounts of time here.

---

# 13. Basic Math / Number Algorithms ⭐⭐⭐⭐⭐

This is VERY relevant to fresher coding tests.

Know:

### Prime number

```text
Check divisibility up to √n.
```

### GCD

```cpp
gcd(a, b)
```

### LCM

```text
LCM = (a × b) / GCD
```

### Factorial

### Fibonacci

### Armstrong number

### Palindrome number

### Reverse number

### Sum of digits

### Count digits

### Perfect number

### Strong number

### Power

### Divisibility

### Sieve of Eratosthenes

You should definitely practice these.

---

# 🧠 VERY IMPORTANT: DSA Patterns

Don't just memorize algorithms.

Learn these **patterns**.

These are what actually make you good at solving questions.

| Pattern           | Typical Use                      |
| ----------------- | -------------------------------- |
| Frequency Hashing | duplicates, frequency, anagrams  |
| Two Pointers      | pairs, palindrome, sorted arrays |
| Sliding Window    | subarrays/substrings             |
| Prefix Sum        | range/subarray sums              |
| Binary Search     | sorted data                      |
| Sorting + Greedy  | intervals, minimum/maximum       |
| Recursion         | repeated decomposition           |
| Stack             | brackets, next greater           |
| Queue             | sequential processing            |
| Fast/Slow Pointer | linked lists                     |
| Kadane            | maximum subarray                 |
| HashMap + Array   | counting/lookups                 |

---

# 🔥 C++ STL You MUST KNOW

Since you're using C++, this is almost as important as DSA itself.

## `vector`

```cpp
vector<int> v;
```

Know:

```cpp
push_back()
pop_back()
size()
empty()
front()
back()
begin()
end()
```

---

## `string`

```cpp
string s;
```

Know:

```cpp
length()
size()
substr()
find()
push_back()
pop_back()
```

and:

```cpp
reverse(s.begin(), s.end());
```

---

## `set`

```cpp
set<int> s;
```

Properties:

> Sorted + unique

---

## `unordered_set`

```cpp
unordered_set<int> s;
```

Properties:

> Unique + generally O(1) lookup

---

## `map`

```cpp
map<int, int> mp;
```

Properties:

> Key-value + sorted keys

---

## `unordered_map`

```cpp
unordered_map<int, int> mp;
```

Properties:

> Key-value + generally O(1) lookup

This one is **extremely important**.

---

## `stack`

```cpp
stack<int> st;
```

## `queue`

```cpp
queue<int> q;
```

## `priority_queue`

At least know:

```cpp
priority_queue<int> pq;
```

and min heap:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

---

# ⚡ Complexity Rules You MUST Know

Don't skip Big-O.

Memorize these:

```text
O(1)       → Constant
O(log n)   → Binary Search
O(n)       → Single loop
O(n log n) → Efficient sorting
O(n²)      → Nested loops
O(2ⁿ)      → Some brute-force recursion
O(n!)      → Permutations
```

### Quick recognition

```cpp
for(int i = 0; i < n; i++)
```

→ `O(n)`

```cpp
for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
```

→ `O(n²)`

```cpp
while(n > 1)
    n /= 2;
```

→ `O(log n)`

---

# 🧩 Then Learn These

After the above foundation, move to:

### Trees ⭐⭐⭐

* Binary Tree
* BST
* Traversals

  * Inorder
  * Preorder
  * Postorder
  * Level order
* Height/depth
* Search in BST

### Heap ⭐⭐⭐

* Min heap
* Max heap
* Priority queue
* K largest/smallest

### Backtracking ⭐⭐

Know the basic idea:

```text
Choose
→ Explore
→ Undo
```

Examples:

* Subsets
* Permutations
* Combination
