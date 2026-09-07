`#include <bits/stdc++.h>` is a **non-standard header file** that is commonly used in **competitive programming** to include **almost all standard C++ libraries** in one go.

---

### ✅ What it does:

When you write:

```cpp
#include <bits/stdc++.h>
```

It includes **most** (not all!) of the commonly used standard C++ headers, like:

* `<iostream>`
* `<vector>`
* `<algorithm>`
* `<map>`
* `<set>`
* `<cmath>`
* `<cstring>`
* `<queue>`
* `<stack>`
* `<limits>`
* `<utility>`
* and many more...

So, instead of writing:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
// etc...
```

You just write:

```cpp
#include <bits/stdc++.h>
```

---

### ❗ But why **"bits/stdc++.h"**?

* It's a **GNU GCC-specific** internal header file.
* `bits/` is a directory used internally by GCC.
* `stdc++.h` stands for **Standard C++ Header**.
* It's **not part of the official C++ standard**, which means:

  * It **won’t work** in compilers like MSVC (Microsoft Visual C++).
  * It may **break in future versions** of compilers.
  * It may **slow down compile time**, because it includes unnecessary stuff.

---

### ✅ When to use:

* In **competitive programming or coding contests**, to save time typing multiple includes.

### ❌ When NOT to use:

* In **production code**, **interviews**, **real-world applications**, or when you're building **clean and portable code**.

---

### ✅ Better Practice:

Instead of `#include <bits/stdc++.h>`, include only what you need:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
```

---

### Summary:

| Feature                  | `#include <bits/stdc++.h>`     |
| ------------------------ | ------------------------------ |
| Usage                    | Includes most standard headers |
| Portability              | ❌ Not portable (GCC-only)      |
| Compilation speed        | ❌ Slower                       |
| Common in competitions   | ✅ Yes                          |
| Recommended in real apps | ❌ No                           |



---
---
---



#### Like when we are sending the Dimensional array in the function parameter, then we have to manually create the column size in array, we cant use variables!

## ❌ You **cannot use variables for the column size** in 2D arrays.

```cpp
int cols = 3;
int arr[2][cols]; // ❌ INVALID in C++ — only valid in C99 (not C++)
```

In standard **C++**, the number of **columns must be known at compile time**, because the compiler needs to calculate the memory layout of each row.

---

## ✅ So what's allowed?

```cpp
int arr[2][3]; // ✅ Works — column size is a constant
```


---
---
---

## 🔑 In C++, when you pass a built-in array to a function (like a 2D array), **you are passing a pointer to the original array**, **not a copy**.

That means:

* Any changes you make to the array inside the function will directly **affect the original array**.
* No copy is made — only the address is passed.

---

### ✅ Example (You Already Noticed This Behavior):

```cpp
#include <iostream>
using namespace std;

void change(int arr[][3], int r) {
    arr[r][1] = 99; // This will change the original array
}

int main() {
    int arr2d[2][3] = {{1, 2, 3}, {4, 5, 6}};
    change(arr2d, 1); // changes arr2d[1][1] to 99

    // Check if original array changed
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j)
            cout << arr2d[i][j] << " ";
        cout << "\n";
    }
}
```

### ✅ Output:

```
1 2 3
4 99 6
```

---

## ✅ WHY?

Because in C++:

```cpp
void func(int arr[][3])
```

Here, `arr` actually decays into a **pointer to an array of 3 ints** (`int (*)[3]`). So internally, it behaves like:

```cpp
void func(int (*arr)[3])
```

So you're modifying the memory where the original data lives — **no copy is created**.

---

### ✅ Same applies to `std::vector` when passed by reference:

```cpp
void modify(vector<vector<int>>& arr) {
    arr[0][0] = 100;
}
```

But if you pass by value:

```cpp
void modify(vector<vector<int>> arr) // ❌ copy is made
```

Then changes happen **on the copy**, not the original.

---

## 🧠 Summary

| Type                   | Passed by | Modifies Original? |
| ---------------------- | --------- | ------------------ |
| `int arr[][3]`         | Pointer   | ✅ Yes              |
| `vector<vector<int>>&` | Reference | ✅ Yes              |
| `vector<vector<int>>`  | By value  | ❌ No               |
