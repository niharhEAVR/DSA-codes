Yes. Since you’re **revising C++ rather than learning it from scratch**, you don’t need long explanations. You need a **one-go syntax/reference sheet** that you can quickly scan whenever you forget something.

For your DSA preparation, I’d keep it focused on **basic C++ + the syntax you actually use in coding problems**.

## 1. Basic C++ Structure

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {

    // code here

    return 0;
}
```

### Important

```cpp
#include <bits/stdc++.h>
```

Includes almost all standard C++ libraries. Commonly used in competitive programming.

```cpp
using namespace std;
```

Allows you to write:

```cpp
cout
cin
string
vector
```

instead of:

```cpp
std::cout
std::cin
std::string
std::vector
```

---

# 2. Input / Output

### Output

```cpp
cout << "Hello";
cout << x;
cout << "Value = " << x;
```

New line:

```cpp
cout << "\n";
cout << endl;
```

Prefer:

```cpp
cout << "\n";
```

### Input

```cpp
int x;
cin >> x;
```

Multiple inputs:

```cpp
int a, b, c;
cin >> a >> b >> c;
```

Example:

```cpp
int a, b;
cin >> a >> b;

cout << a + b;
```

---

## `getline()`

Used to read an **entire line**, including spaces.

```cpp
string name;
getline(cin, name);
```

Input:

```text
Hello World
```

`name` becomes:

```text
"Hello World"
```

### Important problem: `cin` + `getline`

```cpp
int age;
string name;

cin >> age;
cin.ignore();
getline(cin, name);
```

Why `ignore()`?

`cin >> age` leaves the newline `\n` in the input buffer. `getline()` would otherwise read that newline as an empty line.

---

# 3. Variables & Data Types

## Basic syntax

```cpp
data_type variable_name;
```

or

```cpp
data_type variable_name = value;
```

Examples:

```cpp
int age = 20;
long long population = 10000000000LL;
float price = 10.5f;
double pi = 3.14159;
char grade = 'A';
string name = "Nihar";
bool isPassed = true;
```

---

## `int`

Usually stores:

```text
-2,147,483,648 to 2,147,483,647
```

Use for normal integers.

```cpp
int x = 100;
```

---

## `long long`

For integers larger than `int`.

```cpp
long long x = 1000000000000LL;
```

### Important

For a large integer literal, use `LL`:

```cpp
long long x = 1000000000000LL;
```

---

## `float`

Decimal number, lower precision.

```cpp
float x = 3.14f;
```

Usually you won't need `float` much in DSA.

---

## `double`

Decimal number with higher precision.

```cpp
double x = 3.1415926535;
```

Usually prefer `double` over `float` when you need decimal calculations.

---

## `char`

Stores **one character**.

```cpp
char ch = 'A';
```

Single quotes:

```cpp
'A'
'7'
'#'
```

Not:

```cpp
" A "
```

---

## `string`

Stores text.

```cpp
string name = "Nihar";
```

String uses **double quotes**:

```cpp
"Hello"
```

Character uses **single quotes**:

```cpp
'H'
```

---

## `bool`

Only two values:

```cpp
true
false
```

Example:

```cpp
bool isAdult = true;
```

Internally:

```text
true  → 1
false → 0
```

---

# 4. Quick Data Type Table

| Type        | Example                        | Use                  |
| ----------- | ------------------------------ | -------------------- |
| `int`       | `int x = 10;`                  | Normal integers      |
| `long long` | `long long x = 10000000000LL;` | Large integers       |
| `float`     | `float x = 3.14f;`             | Decimal              |
| `double`    | `double x = 3.14159;`          | More precise decimal |
| `char`      | `char ch = 'A';`               | Single character     |
| `string`    | `string s = "Hello";`          | Text                 |
| `bool`      | `bool ok = true;`              | True/false           |

---

# 5. Constants

```cpp
const int x = 10;
```

You cannot later change `x`.

```cpp
const double PI = 3.14159;
```

---

# 6. Operators

### Arithmetic

```cpp
+    // addition
-    // subtraction
*    // multiplication
/    // division
%    // remainder
```

Example:

```cpp
int a = 10, b = 3;

cout << a + b;  // 13
cout << a - b;  // 7
cout << a * b;  // 30
cout << a / b;  // 3
cout << a % b;  // 1
```

### Important: integer division

```cpp
5 / 2
```

gives:

```text
2
```

because both are integers.

But:

```cpp
5.0 / 2
```

gives:

```text
2.5
```

---

# 7. Assignment Operators

```cpp
x = 10;

x += 5;   // x = x + 5
x -= 5;   // x = x - 5
x *= 5;   // x = x * 5
x /= 5;   // x = x / 5
x %= 5;   // x = x % 5
```

---

# 8. Increment / Decrement

```cpp
x++;
++x;

x--;
--x;
```

### Difference

```cpp
x++;
```

Use current value first, then increase.

```cpp
++x;
```

Increase first, then use the value.

Example:

```cpp
int x = 5;

cout << x++;   // 5
cout << x;     // 6
```

```cpp
int x = 5;

cout << ++x;   // 6
cout << x;     // 6
```

---

# 9. Comparison Operators

Used in conditions.

```cpp
==    // equal
!=    // not equal
>     // greater
<     // smaller
>=    // greater/equal
<=    // smaller/equal
```

### VERY IMPORTANT

```cpp
x == 5
```

means **comparison**.

```cpp
x = 5
```

means **assignment**.

---

# 10. Logical Operators

```cpp
&&    // AND
||    // OR
!     // NOT
```

Example:

```cpp
if (age >= 18 && age <= 60)
```

Both conditions must be true.

```cpp
if (x == 5 || x == 10)
```

At least one must be true.

```cpp
if (!flag)
```

Means opposite of `flag`.

---

# 11. `if / else`

```cpp
if (condition) {

}
else {

}
```

Example:

```cpp
if (x > 0) {
    cout << "Positive";
}
else {
    cout << "Not positive";
}
```

Multiple conditions:

```cpp
if (x > 0) {
    cout << "Positive";
}
else if (x < 0) {
    cout << "Negative";
}
else {
    cout << "Zero";
}
```

---

# 12. Ternary Operator

Short form of `if-else`.

```cpp
condition ? value_if_true : value_if_false;
```

Example:

```cpp
int max = (a > b) ? a : b;
```

Equivalent:

```cpp
int max;

if (a > b)
    max = a;
else
    max = b;
```

---

# 13. `switch`

```cpp
switch (x) {

    case 1:
        cout << "One";
        break;

    case 2:
        cout << "Two";
        break;

    default:
        cout << "Other";
}
```

`break` prevents execution from falling into the next case.

---

# 14. Loops

## `for`

Most common in DSA.

```cpp
for (initialization; condition; update) {

}
```

Example:

```cpp
for (int i = 0; i < 5; i++) {
    cout << i << " ";
}
```

Output:

```text
0 1 2 3 4
```

### Reverse

```cpp
for (int i = 5; i >= 0; i--) {
    cout << i << " ";
}
```

---

## `while`

```cpp
while (condition) {

}
```

Example:

```cpp
int i = 0;

while (i < 5) {
    cout << i << " ";
    i++;
}
```

---

## `do while`

Runs **at least once**.

```cpp
do {

} while (condition);
```

---

# 15. `break` and `continue`

### `break`

Immediately exits the loop.

```cpp
for (int i = 0; i < 10; i++) {

    if (i == 5)
        break;

    cout << i << " ";
}
```

Output:

```text
0 1 2 3 4
```

### `continue`

Skips the current iteration.

```cpp
for (int i = 0; i < 5; i++) {

    if (i == 2)
        continue;

    cout << i << " ";
}
```

Output:

```text
0 1 3 4
```

---

# 16. Type Casting

Convert one type to another.

```cpp
int a = 5;
double b = (double)a;
```

Modern C++:

```cpp
double b = static_cast<double>(a);
```

Very useful for avoiding integer division:

```cpp
double ans = (double)a / b;
```

or:

```cpp
double ans = static_cast<double>(a) / b;
```

---

# 17. Functions

Basic syntax:

```cpp
return_type function_name(parameters) {

    // code

    return value;
}
```

Example:

```cpp
int add(int a, int b) {
    return a + b;
}
```

Calling:

```cpp
int result = add(5, 3);
```

### `void`

Function returns nothing:

```cpp
void printHello() {
    cout << "Hello";
}
```

---

# 18. Pass by Value vs Reference

### Pass by value

```cpp
void change(int x) {
    x = 100;
}
```

Original variable doesn't change.

### Pass by reference

```cpp
void change(int &x) {
    x = 100;
}
```

Original variable changes.

You'll use references **a lot** in DSA.

---

# 19. Arrays

Declaration:

```cpp
int arr[5];
```

Initialization:

```cpp
int arr[5] = {1, 2, 3, 4, 5};
```

Access:

```cpp
arr[0]
arr[1]
arr[4]
```

Loop:

```cpp
for (int i = 0; i < 5; i++) {
    cout << arr[i] << " ";
}
```

---

# 20. String Basics

```cpp
string s = "Hello";
```

Access character:

```cpp
s[0]
```

Length:

```cpp
s.length();
```

or:

```cpp
s.size();
```

Input:

```cpp
cin >> s;
```

Reads one word.

```cpp
getline(cin, s);
```

Reads the complete line.

---

# 21. Useful String Operations

```cpp
string s = "Hello World";
```

Length:

```cpp
s.size();
```

First character:

```cpp
s[0];
```

Last character:

```cpp
s[s.size() - 1];
```

Add character:

```cpp
s += '!';
```

Add string:

```cpp
s += " ABC";
```

Substring:

```cpp
s.substr(start, length);
```

Example:

```cpp
string s = "abcdef";

cout << s.substr(1, 3);
```

Output:

```text
bcd
```

---

# 22. Comments

Single line:

```cpp
// This is a comment
```

Multiple lines:

```cpp
/*
    This is
    a comment
*/
```

---

# 23. Scope

```cpp
int x = 10;

if (true) {
    int y = 20;
}
```

`y` exists only inside that `{ }` block.

---

# 24. `auto`

C++ can automatically determine the type.

```cpp
auto x = 10;       // int
auto y = 3.14;     // double
auto ch = 'A';     // char
```

You'll see this **very frequently with STL iterators**.

---

# 25. Common Useful Functions

Include:

```cpp
#include <bits/stdc++.h>
using namespace std;
```

### Maximum / minimum

```cpp
max(a, b);
min(a, b);
```

### Absolute value

```cpp
abs(x);
```

### Swap

```cpp
swap(a, b);
```

### Power

```cpp
pow(a, b);
```

### Square root

```cpp
sqrt(x);
```

### GCD

```cpp
gcd(a, b);
```

Example:

```cpp
cout << gcd(12, 18);
```

Output:

```text
6
```

---

# 26. Namespace

Without:

```cpp
using namespace std;
```

you need:

```cpp
std::cout
std::cin
std::string
std::vector
```

With:

```cpp
using namespace std;
```

you can simply use:

```cpp
cout
cin
string
vector
```

---

# 27. The C++ Skeleton You Should Memorize

For DSA, this is probably the **single most important template**:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {

    // Input

    // Logic

    // Output

    return 0;
}
```

And when solving a DSA problem:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    // solution

    return 0;
}
```

---

# 🧠 Ultra-Short Revision Sheet

If you want something you can look at **30 seconds before coding**, remember this:

```text
C++ BASIC SYNTAX
────────────────────────────────

HEADER
#include <bits/stdc++.h>
using namespace std;

MAIN
int main() {
    return 0;
}

INPUT
cin >> x;
cin >> a >> b;
getline(cin, s);
cin.ignore();

OUTPUT
cout << x;
cout << "Hello";
cout << "\n";

DATA TYPES
int
long long
float
double
char
string
bool

VARIABLE
int x = 10;
const int x = 10;

ARITHMETIC
+  -  *  /  %

COMPARISON
==  !=  >  <  >=  <=

LOGICAL
&&  ||  !

ASSIGNMENT
=  +=  -=  *=  /=  %=

INCREMENT
x++;
++x;
x--;
--x;

IF
if (condition) {}
else if (condition) {}
else {}

TERNARY
condition ? a : b;

SWITCH
switch (x) {
    case 1:
        ...
        break;
    default:
        ...
}

LOOPS
for (int i = 0; i < n; i++) {}

while (condition) {}

do {} while (condition);

LOOP CONTROL
break;
continue;

FUNCTION
int add(int a, int b) {
    return a + b;
}

VOID
void fun() {}

REFERENCE
void fun(int &x) {}

ARRAY
int arr[5] = {1,2,3,4,5};
arr[i];

STRING
string s = "Hello";
s[i];
s.size();
s.length();
s.substr(start, length);

CAST
(double)x;
static_cast<double>(x);

COMMON
max(a,b);
min(a,b);
abs(x);
swap(a,b);
sqrt(x);
pow(a,b);
gcd(a,b);

COMMENTS
// single line
/* multi line */
```

**For your current stage, don't try to memorize every C++ feature.** Get this basic syntax automatic first. Then the next really important revision layer for DSA is **STL**: `vector`, `pair`, `set`, `map`, `unordered_map`, `stack`, `queue`, `priority_queue`, iterators, `sort()`, etc. That is much more important for your DSA work than advanced C++ language features.
