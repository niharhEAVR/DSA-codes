Absolutely. Since you're doing a **quick C++ revision for DSA**, I'll keep this as a **one-go syntax/reference sheet** rather than explaining every concept deeply.

# C++ Quick Revision Sheet — Arrays, Strings & Functions

---

# 7. ARRAYS

## Declaration

### Fixed-size array

```cpp
int arr[5];
```

Creates:

```text
arr[0] arr[1] arr[2] arr[3] arr[4]
```

Index always starts from **0**.

### Declaration + initialization

```cpp
int arr[5] = {10, 20, 30, 40, 50};
```

Size can be omitted:

```cpp
int arr[] = {10, 20, 30, 40, 50};
```

---

## Accessing Elements

```cpp
cout << arr[0];    // first element
cout << arr[2];    // third element

arr[1] = 100;      // modify second element
```

Remember:

```text
first element → arr[0]
last element  → arr[n-1]
```

---

## Input

### Input `n` elements

```cpp
int n;
cin >> n;

int arr[n];

for (int i = 0; i < n; i++) {
    cin >> arr[i];
}
```

> For standard C++, variable-length arrays like `int arr[n]` are not officially part of the language. In modern C++, prefer `vector<int> arr(n)` when the size is known at runtime.

For basic DSA practice, you'll often see:

```cpp
vector<int> arr(n);
```

---

## Traversal

### Normal traversal

```cpp
for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
}
```

### Reverse traversal

```cpp
for (int i = n - 1; i >= 0; i--) {
    cout << arr[i] << " ";
}
```

---

## Find Maximum

### Basic method

```cpp
int maxi = arr[0];

for (int i = 1; i < n; i++) {
    if (arr[i] > maxi) {
        maxi = arr[i];
    }
}

cout << maxi;
```

### STL

```cpp
int maxi = *max_element(arr, arr + n);
```

For vector:

```cpp
int maxi = *max_element(arr.begin(), arr.end());
```

---

## Find Minimum

```cpp
int mini = arr[0];

for (int i = 1; i < n; i++) {
    if (arr[i] < mini) {
        mini = arr[i];
    }
}
```

STL:

```cpp
int mini = *min_element(arr, arr + n);
```

For vector:

```cpp
int mini = *min_element(arr.begin(), arr.end());
```

---

## Sum of Array

```cpp
int sum = 0;

for (int i = 0; i < n; i++) {
    sum += arr[i];
}
```

For potentially large sums:

```cpp
long long sum = 0;
```

---

## Searching

### Linear Search

```cpp
int target;
cin >> target;

for (int i = 0; i < n; i++) {

    if (arr[i] == target) {
        cout << "Found";
        break;
    }

}
```

### Find index

```cpp
int index = -1;

for (int i = 0; i < n; i++) {

    if (arr[i] == target) {
        index = i;
        break;
    }

}
```

`-1` commonly means **not found**.

---

## Reverse an Array

### Manually

```cpp
int left = 0;
int right = n - 1;

while (left < right) {

    swap(arr[left], arr[right]);

    left++;
    right--;
}
```

Example:

```text
Before:
10 20 30 40 50

After:
50 40 30 20 10
```

### STL

```cpp
reverse(arr, arr + n);
```

For vector:

```cpp
reverse(arr.begin(), arr.end());
```

---

# ⭐ Array Patterns to Remember

```cpp
// Traversal
for (int i = 0; i < n; i++)

// Reverse traversal
for (int i = n - 1; i >= 0; i--)

// First element
arr[0]

// Last element
arr[n - 1]

// Sum
sum += arr[i]

// Maximum
maxi = max(maxi, arr[i])

// Minimum
mini = min(mini, arr[i])

// Swap
swap(arr[i], arr[j])
```

---

# 8. STRINGS

C++ has the `string` type.

```cpp
string s;
```

Usually:

```cpp
#include <bits/stdc++.h>
using namespace std;
```

---

## Input

### One word

```cpp
string s;
cin >> s;
```

Input:

```text
hello
```

### Sentence / spaces

Use `getline()`:

```cpp
string s;
getline(cin, s);
```

If you used `cin` immediately before `getline`:

```cpp
int n;
cin >> n;

cin.ignore();
getline(cin, s);
```

---

# String Length

```cpp
string s = "hello";

cout << s.length();
```

Output:

```text
5
```

Also:

```cpp
s.size();
```

Both are commonly used.

---

# String Indexing

Just like an array.

```cpp
string s = "hello";

cout << s[0];    // h
cout << s[1];    // e
cout << s[4];    // o
```

Last character:

```cpp
s[s.length() - 1]
```

You can modify characters:

```cpp
s[0] = 'H';
```

Now:

```text
Hello
```

---

# String Traversal

### Using index

```cpp
for (int i = 0; i < s.length(); i++) {
    cout << s[i] << " ";
}
```

### Range-based loop

```cpp
for (char ch : s) {
    cout << ch << " ";
}
```

Very common in DSA:

```cpp
for (char ch : s) {
    if (ch == 'a') {
        // ...
    }
}
```

---

# String Comparison

You can directly use:

```cpp
string a = "hello";
string b = "world";

if (a == b) {
    cout << "Same";
}
```

Operators:

```cpp
a == b
a != b
a < b
a > b
```

String comparison is **lexicographical** (dictionary-like).

```cpp
"apple" < "banana"   // true
```

---

# Reverse String

### STL

```cpp
reverse(s.begin(), s.end());
```

Example:

```cpp
string s = "hello";

reverse(s.begin(), s.end());

cout << s;
```

Output:

```text
olleh
```

### Manually

```cpp
int left = 0;
int right = s.length() - 1;

while (left < right) {

    swap(s[left], s[right]);

    left++;
    right--;
}
```

---

# Palindrome

A palindrome reads the same forward and backward.

Examples:

```text
madam
racecar
121
```

### Using reverse

```cpp
string original = s;

reverse(s.begin(), s.end());

if (original == s) {
    cout << "Palindrome";
}
else {
    cout << "Not Palindrome";
}
```

### Better: two-pointer approach

```cpp
int left = 0;
int right = s.length() - 1;

bool palindrome = true;

while (left < right) {

    if (s[left] != s[right]) {
        palindrome = false;
        break;
    }

    left++;
    right--;
}
```

---

# Character Operations

A `char` stores one character.

```cpp
char ch = 'A';
```

⚠️ Single quotes for characters:

```cpp
'A'
```

Double quotes for strings:

```cpp
"A"
```

---

## Check Character Type

Use `<cctype>` functions:

```cpp
isdigit(ch)
isalpha(ch)
islower(ch)
isupper(ch)
isalnum(ch)
isspace(ch)
```

Example:

```cpp
if (isdigit(ch)) {
    cout << "Digit";
}
```

---

## Convert Case

```cpp
tolower(ch);
toupper(ch);
```

Example:

```cpp
char ch = 'A';

ch = tolower(ch);

cout << ch;
```

Output:

```text
a
```

Reverse:

```cpp
char ch = 'a';

ch = toupper(ch);
```

---

## Character → Number

Very important for DSA.

```cpp
char ch = '7';

int num = ch - '0';
```

Now:

```text
num = 7
```

Why?

```text
'7' - '0' = 7
```

Common pattern:

```cpp
int digit = s[i] - '0';
```

---

## Number → Character

```cpp
int num = 7;

char ch = num + '0';
```

Result:

```text
'7'
```

---

# ⭐ String Patterns

```cpp
// Length
s.length()

// First character
s[0]

// Last character
s[s.length() - 1]

// Traversal
for (char ch : s)

// Reverse
reverse(s.begin(), s.end())

// Compare
if (s1 == s2)

// Character
char ch = s[i]

// Digit → number
ch - '0'

// Number → digit character
num + '0'

// Lowercase
tolower(ch)

// Uppercase
toupper(ch)

// Check digit
isdigit(ch)

// Check alphabet
isalpha(ch)
```

---

# 9. FUNCTIONS

Functions let you write a piece of logic once and reuse it.

---

## Basic Function

```cpp
returnType functionName() {

    // code

}
```

Example:

```cpp
void greet() {
    cout << "Hello";
}
```

Call it:

```cpp
greet();
```

---

# Function Declaration / Prototype

You can declare the function before `main()` and define it later.

```cpp
int add(int a, int b);
```

Then:

```cpp
int main() {

    cout << add(5, 3);

}
```

Definition:

```cpp
int add(int a, int b) {
    return a + b;
}
```

---

# Parameters

Parameters are values received by a function.

```cpp
void greet(string name) {
    cout << "Hello " << name;
}
```

Call:

```cpp
greet("Nihar");
```

Here:

```text
name → parameter
"Nihar" → argument
```

---

# Multiple Parameters

```cpp
int add(int a, int b) {
    return a + b;
}
```

Call:

```cpp
int result = add(10, 20);
```

---

# Return Value

A function can send a value back using `return`.

```cpp
int square(int n) {
    return n * n;
}
```

Usage:

```cpp
int ans = square(5);

cout << ans;
```

Output:

```text
25
```

---

## `void`

If the function doesn't return anything:

```cpp
void printHello() {
    cout << "Hello";
}
```

No return value is required.

You can also use:

```cpp
return;
```

to exit a `void` function early.

---

# Pass by Value

Normally, C++ passes a **copy**.

```cpp
void change(int x) {
    x = 100;
}

int main() {

    int a = 10;

    change(a);

    cout << a;
}
```

Output:

```text
10
```

The original `a` doesn't change.

---

# Pass by Reference ⭐

Use `&` to work with the **original variable**.

```cpp
void change(int &x) {
    x = 100;
}
```

Now:

```cpp
int a = 10;

change(a);

cout << a;
```

Output:

```text
100
```

### Remember

```cpp
int x       // copy
int &x      // reference to original
```

---

# Why Pass by Reference?

### Modify original

```cpp
void swapValues(int &a, int &b) {
    swap(a, b);
}
```

### Avoid copying large objects

Very common with strings/vectors:

```cpp
void print(string &s)
```

Even better when you don't need to modify it:

```cpp
void print(const string &s)
```

This means:

```text
const → don't modify
&     → don't make a copy
```

Very common DSA syntax:

```cpp
void solve(vector<int> &arr)
```

---

# Function Cheat Patterns

### No input, no return

```cpp
void fun() {
}
```

### Input, no return

```cpp
void fun(int n) {
}
```

### Input + return

```cpp
int fun(int n) {
    return n * n;
}
```

### Multiple inputs

```cpp
int add(int a, int b) {
    return a + b;
}
```

### Pass by reference

```cpp
void fun(int &x) {
    x++;
}
```

### Vector by reference

```cpp
void fun(vector<int> &arr) {
}
```

### Read-only vector reference

```cpp
void fun(const vector<int> &arr) {
}
```

---

# 🧠 ULTRA-SHORT C++ REVISION

```text
ARRAYS
────────────────────────────
int arr[5];

arr[0]              → first
arr[n-1]            → last

for (int i = 0; i < n; i++)
    cout << arr[i];

for (int i = n-1; i >= 0; i--)
    cout << arr[i];

sum += arr[i];

maxi = max(maxi, arr[i]);
mini = min(mini, arr[i]);

reverse(arr, arr + n);

swap(arr[i], arr[j]);


STRINGS
────────────────────────────
string s;

cin >> s;             → word
getline(cin, s);      → line with spaces

s.length()
s.size()

s[0]                  → first
s[s.length()-1]       → last

for (char ch : s)

reverse(s.begin(), s.end());

s1 == s2              → comparison

isdigit(ch)
isalpha(ch)
islower(ch)
isupper(ch)

tolower(ch)
toupper(ch)

ch - '0'              → char → number
num + '0'             → number → char


FUNCTIONS
────────────────────────────
void fun() {
}

int fun(int n) {
    return n * n;
}

int add(int a, int b) {
    return a + b;
}

int &x                   → pass by reference
vector<int> &arr         → original vector
const vector<int> &arr   → read-only, no copy


IMPORTANT
────────────────────────────
array index starts at 0

arr[n-1] → last element

string indexing works like arrays

char → 'A'
string → "ABC"

break    → exit loop
continue → skip iteration

return   → send value back / exit function
```

### The 3 things I'd make **automatic** for DSA

```cpp
// 1. Array traversal
for (int i = 0; i < n; i++)

// 2. String traversal
for (char ch : s)

// 3. Function with reference
void solve(vector<int> &arr)
```

If these patterns become muscle memory, you won't waste your brainpower on C++ syntax while solving the actual DSA problem.
