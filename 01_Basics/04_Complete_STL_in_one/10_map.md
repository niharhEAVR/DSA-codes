Perfect! Now you're learning the STL in the right order.

You've already learned:

* ✅ `vector`
* ✅ `priority_queue`
* ✅ `set`
* ✅ `multiset`
* ✅ `unordered_set`

The next important containers are:

* ✅ `map`
* ✅ `multimap`
* ✅ `unordered_map` (probably the most used STL container in DSA)

Let's start.

---

# What is a map?

A `map` stores **key-value pairs**.

Think of it as a dictionary.

Instead of storing only values like a vector

```cpp
10 20 30
```

it stores

```text
Key   Value

1     Apple
2     Mango
3     Banana
```

In C++

```cpp
map<int, string> fruits;
```

means

* Key → `int`
* Value → `string`

---

# Real-life Example

Think of a phone book.

```text
Name          Phone Number

Nihar         9876543210
Rahul         9123456789
Amit          9988776655
```

Here

Name = Key

Phone Number = Value

That's exactly what a map stores.

---

# Creating a map

```cpp
#include <map>

map<int, string> mp;
```

---

# Inserting Elements

Method 1

```cpp
mp[1] = "Apple";
mp[2] = "Mango";
mp[3] = "Banana";
```

Output

```text
1 Apple
2 Mango
3 Banana
```

---

Method 2

```cpp
mp.insert({4, "Orange"});
```

---

Method 3

```cpp
mp.emplace(5, "Grapes");
```

---

# Properties

## 1. Keys are unique

```cpp
map<int,string> mp;

mp[1]="Apple";
mp[1]="Mango";
```

Output

```text
1 Mango
```

The second assignment replaces the value.

Unlike `multimap`.

---

## 2. Keys are sorted automatically

```cpp
mp[5]="A";
mp[1]="B";
mp[10]="C";
```

Printing

```cpp
for(auto x:mp)
{
    cout<<x.first<<" "<<x.second<<endl;
}
```

Output

```text
1 B
5 A
10 C
```

Sorted by **key**, not value.

---

# Accessing Values

```cpp
cout<<mp[2];
```

Output

```text
Mango
```

---

# first and second

Each element is actually a

```cpp
pair<Key, Value>
```

Example

```cpp
for(auto x:mp)
{
    cout<<x.first<<" ";
    cout<<x.second<<endl;
}
```

Output

```text
1 Apple
2 Mango
3 Banana
```

Remember

```text
first

↓

Key

second

↓

Value
```

---

# find()

```cpp
auto it=mp.find(2);
```

If found

```cpp
cout<<it->second;
```

Output

```text
Mango
```

---

If not found

```cpp
if(it==mp.end())
```

---

Complexity

```text
O(log N)
```

---

# count()

Since keys are unique

```cpp
mp.count(2);
```

returns

```text
0 or 1
```

---

# erase()

```cpp
mp.erase(2);
```

Before

```text
1 Apple
2 Mango
3 Banana
```

After

```text
1 Apple
3 Banana
```

---

# size()

```cpp
cout<<mp.size();
```

---

# empty()

```cpp
mp.empty();
```

---

# clear()

```cpp
mp.clear();
```

Everything removed.

---

# lower_bound()

Suppose

```text
1

5

8

10
```

```cpp
mp.lower_bound(6);
```

Returns

```text
8
```

---

# upper_bound()

```cpp
upper_bound(5)
```

returns

```text
8
```

---

# Time Complexity

| Operation   | Complexity |
| ----------- | ---------- |
| Insert      | O(log N)   |
| Find        | O(log N)   |
| Erase       | O(log N)   |
| Count       | O(log N)   |
| lower_bound | O(log N)   |

---

# Why use map instead of vector?

Suppose

Roll numbers

```text
1001

1007

5010

9001
```

If you use vector

```cpp
vector<string> v(9002);
```

Huge waste of memory.

Map stores only existing keys.

```text
1001 → Nihar

5010 → Rahul

9001 → Amit
```

Very memory efficient for sparse keys.

---

# What is multimap?

Exactly like map,

except

**duplicate keys are allowed.**

---

Example

```cpp
multimap<int,string> mm;

mm.insert({1,"Apple"});
mm.insert({1,"Mango"});
mm.insert({1,"Banana"});
```

Output

```text
1 Apple
1 Mango
1 Banana
```

Notice

Key

```text
1
```

appears three times.

---

# Why can't we use []

Suppose

```cpp
mm[1]="Apple";
```

Which value should it overwrite?

There may be

```text
1 Apple

1 Mango

1 Banana
```

So

`operator[]`

doesn't exist.

You must use

```cpp
insert()

or

emplace()
```

---

# Traversing

```cpp
for(auto x:mm)
{
    cout<<x.first<<" "<<x.second<<endl;
}
```

---

# find()

```cpp
auto it=mm.find(1);
```

Returns iterator to the **first occurrence**.

---

# count()

```cpp
cout<<mm.count(1);
```

Output

```text
3
```

---

# erase()

```cpp
mm.erase(1);
```

Removes **all** entries with key `1`.

---

Remove only one

```cpp
auto it=mm.find(1);

mm.erase(it);
```

---

# Real-world Example

Suppose a college stores students by department.

```text
CSE → Rahul

CSE → Amit

CSE → Nihar

ECE → Priya
```

Multiple students belong to the same department.

`multimap` is a natural fit.

---

# map vs multimap

| Feature        | map      | multimap |
| -------------- | -------- | -------- |
| Duplicate Keys | ❌ No     | ✅ Yes    |
| Sorted         | ✅ Yes    | ✅ Yes    |
| `[]` operator  | ✅ Yes    | ❌ No     |
| `insert()`     | ✅        | ✅        |
| `find()`       | O(log N) | O(log N) |
| `count()`      | 0 or 1   | 0...N    |

---

# When should you use each?

### Use `map`

When each key should have **only one value**.

Examples:

```text
Student ID → Name

Roll Number → Marks

Username → Password Hash

Country Code → Country Name
```

---

### Use `multimap`

When one key can have **multiple values**.

Examples:

```text
Department → Students

Author → Books

Category → Products

City → Restaurants
```

---

# Interview Tip

In modern C++, you'll see **`unordered_map`** much more often than `multimap`.

Why?

Because many DSA problems involve:

* Counting frequencies
* Fast lookups
* Hashing

Examples:

* Two Sum
* Frequency of elements
* Longest Consecutive Sequence
* Group Anagrams
* Subarray Sum Equals K

All of these are commonly solved using `unordered_map`.

So after `map`, the **most important STL container to master** is `unordered_map`. It's one of the most frequently used containers in coding interviews and competitive programming.



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



Excellent! This is probably the **most important STL container** for DSA interviews.

If I had to rank STL containers by how often they're used in coding interviews:

1. 🥇 `unordered_map`
2. 🥈 `vector`
3. 🥉 `unordered_set`
4. `map`
5. `priority_queue`
6. `set`
7. `multiset`

If you master `unordered_map`, you'll solve a huge number of LeetCode, TCS, Amazon, Google, and Microsoft interview questions.

---

# What is an unordered_map?

An `unordered_map` stores **key-value pairs**, just like a `map`.

The difference is:

* `map` → Red-Black Tree
* `unordered_map` → Hash Table

---

## Example

```cpp
unordered_map<int, string> um;

um[1] = "Apple";
um[2] = "Mango";
um[3] = "Banana";
```

It stores

```text
1 → Apple
2 → Mango
3 → Banana
```

---

# Properties

## 1. Keys are unique

```cpp
unordered_map<int,string> um;

um[1]="Apple";
um[1]="Orange";
```

Output

```text
1 → Orange
```

The value is updated.

---

## 2. Not Sorted

```cpp
unordered_map<int,string> um;

um[5]="A";
um[1]="B";
um[10]="C";
um[7]="D";
```

Printing

```cpp
for(auto x:um)
    cout<<x.first<<" "<<x.second<<endl;
```

Possible output

```text
7 D
1 B
10 C
5 A
```

or

```text
10 C
5 A
7 D
1 B
```

or any other order.

**Never depend on the order.**

---

# Why isn't it sorted?

Because of hashing.

Suppose there are buckets

```text
Bucket 0

Bucket 1

Bucket 2

Bucket 3

Bucket 4
```

Insert

```text
25
```

Hash function

```text
25 % 5 = 0
```

So

```text
Bucket 0

25
```

Insert

```text
18
```

```text
18 % 5 = 3
```

```text
Bucket 3

18
```

The data is stored according to the hash value, not numerical order.

---

# Accessing Values

```cpp
cout<<um[2];
```

Output

```text
Mango
```

---

# Adding Values

```cpp
um[10]="Laptop";
```

or

```cpp
um.insert({20,"Phone"});
```

or

```cpp
um.emplace(30,"TV");
```

---

# Updating Values

```cpp
um[10]="Desktop";
```

No new key is created.

The value changes.

---

# find()

```cpp
auto it=um.find(10);
```

If found

```cpp
cout<<it->second;
```

Output

```text
Desktop
```

If not

```cpp
if(it==um.end())
```

---

Complexity

Average

```text
O(1)
```

Worst

```text
O(N)
```

---

# count()

```cpp
cout<<um.count(10);
```

Returns

```text
0
```

or

```text
1
```

because keys are unique.

---

# erase()

```cpp
um.erase(10);
```

Removes the key-value pair.

---

# size()

```cpp
um.size();
```

---

# empty()

```cpp
um.empty();
```

---

# clear()

```cpp
um.clear();
```

Everything removed.

---

# Traversing

```cpp
for(auto x:um)
{
    cout<<x.first<<" "<<x.second<<endl;
}
```

Remember

```text
first

↓

Key

second

↓

Value
```

---

# Time Complexity

| Operation | Average | Worst |
| --------- | ------- | ----- |
| Insert    | O(1)    | O(N)  |
| Find      | O(1)    | O(N)  |
| Erase     | O(1)    | O(N)  |
| Count     | O(1)    | O(N)  |

Worst case happens only when many keys hash to the same bucket. Good hash functions make this uncommon.

---

# Most Important Use

## Frequency Counting

Suppose

```text
5 2 5 1 2 5
```

Need frequency.

Instead of

```cpp
for(int i=0;i<n;i++)
{
    int count=0;

    for(int j=0;j<n;j++)
    {
        if(arr[i]==arr[j])
            count++;
    }
}
```

Time

```text
O(N²)
```

Use

```cpp
unordered_map<int,int> freq;

for(int x:arr)
{
    freq[x]++;
}
```

Result

```text
5 → 3

2 → 2

1 → 1
```

Time

```text
O(N)
```

---

# Example

```cpp
vector<int> arr={5,2,5,1,2,5};

unordered_map<int,int> freq;

for(int x:arr)
{
    freq[x]++;
}

for(auto x:freq)
{
    cout<<x.first<<" "<<x.second<<endl;
}
```

Possible output

```text
1 1
2 2
5 3
```

---

# Example: Check if Element Exists

Without hash map

```cpp
for(...)
```

O(N)

With unordered_map

```cpp
if(um.count(50))
```

O(1)

---

# map vs unordered_map

| Feature            | map            | unordered_map |
| ------------------ | -------------- | ------------- |
| Sorted             | ✅              | ❌             |
| Duplicate Keys     | ❌              | ❌             |
| Internal Structure | Red-Black Tree | Hash Table    |
| Search             | O(log N)       | O(1) average  |
| Insert             | O(log N)       | O(1) average  |
| lower_bound()      | ✅              | ❌             |
| upper_bound()      | ✅              | ❌             |

---

# When do we use map?

Need sorted keys.

Example

```text
Marks

10

20

35

40
```

Need the next greater key.

Need `lower_bound()`.

Use `map`.

---

# When do we use unordered_map?

Need speed.

Don't care about order.

Use

```cpp
unordered_map
```

---

# Most Common Interview Problems

Almost all of these use `unordered_map`:

### 1. Two Sum

```text
2 7 11 15
```

Store

```text
Number → Index
```

---

### 2. Frequency Count

```text
1 2 1 3 2 1
```

Store

```text
Number → Frequency
```

---

### 3. First Non-Repeating Character

Store

```text
Character → Frequency
```

---

### 4. Group Anagrams

Store

```text
Sorted String → List of Words
```

Example

```text
"eat"

↓

"aet"

↓

["eat","tea","ate"]
```

---

### 5. Longest Consecutive Sequence

Uses hashing for O(N) performance.

---

### 6. Subarray Sum Equals K

One of the most famous interview problems.

Store

```text
Prefix Sum → Frequency
```

---

# Interview Trick (Very Important)

You can use **almost any type as the key**, as long as it can be hashed.

Examples:

```cpp
unordered_map<string, int> wordCount;
```

```cpp
unordered_map<char, int> freq;
```

```cpp
unordered_map<long long, int> mp;
```

You can even use custom types, but then you must provide a custom hash function.

---

# Complete Comparison of the Four Most Important Associative Containers

| Feature            | `set`                | `multiset`                    | `map`                  | `unordered_map`                               |
| ------------------ | -------------------- | ----------------------------- | ---------------------- | --------------------------------------------- |
| Stores             | Values               | Values                        | Key → Value            | Key → Value                                   |
| Duplicates         | ❌                    | ✅                             | Keys ❌                 | Keys ❌                                        |
| Sorted             | ✅                    | ✅                             | ✅ (by key)             | ❌                                             |
| Internal Structure | Red-Black Tree       | Red-Black Tree                | Red-Black Tree         | Hash Table                                    |
| Search             | O(log N)             | O(log N)                      | O(log N)               | O(1) average                                  |
| Insert             | O(log N)             | O(log N)                      | O(log N)               | O(1) average                                  |
| Best For           | Unique sorted values | Sorted values with duplicates | Sorted key-value pairs | Fast key-value lookups and frequency counting |

---

## One last interview tip

If you're solving a DSA problem and you think:

* "I need to **count** something." → Think `unordered_map`.
* "I need to **check whether something already exists quickly**." → Think `unordered_map` or `unordered_set`.
* "I need the **keys in sorted order**." → Think `map`.
* "I need **unique sorted values**." → Think `set`.

This simple decision process will help you choose the right STL container in most interview questions.
