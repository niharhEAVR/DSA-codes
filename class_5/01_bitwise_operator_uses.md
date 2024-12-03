**Bitwise operators** (`&`, `|`, `~`, `^`, etc.) are used for manipulating individual bits of numbers. They are widely used in areas like:

- **Low-level programming** (e.g., hardware programming, device drivers).
- **Optimizations** (e.g., space or time-efficient algorithms).
- **Cryptography** (e.g., encryption/decryption algorithms).
- **Data compression** and **image processing**.

Below are some common **questions and solutions** involving bitwise operators:

---

### **1. Check if a number is odd or even**
**Problem:** Write a function to determine if a number is odd or even using bitwise operators.

**Solution:**
```c
#include<stdio.h>

void checkOddEven(int n) {
    if (n & 1) // Check if the last bit is 1
        printf("%d is Odd\n", n);
    else
        printf("%d is Even\n", n);
}

int main() {
    int num = 5;
    checkOddEven(num); // Output: 5 is Odd
    num = 8;
    checkOddEven(num); // Output: 8 is Even
    return 0;
}
```
**Explanation:** 
- The least significant bit (LSB) of a binary number determines if it’s odd (`1`) or even (`0`).
- `n & 1` isolates the LSB.

---

### **2. Count the number of set bits in a number**
**Problem:** Count how many `1`s are in the binary representation of a number.

**Solution:**
```c
#include<stdio.h>

int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1; // Increment count if the LSB is 1
        n >>= 1;        // Right shift to check the next bit
    }
    return count;
}

int main() {
    int num = 13; // Binary: 1101
    printf("Number of set bits in %d: %d\n", num, countSetBits(num));
    return 0;
}
```
**Output:**
```
Number of set bits in 13: 3
```

---

### **3. Swap two numbers without using a temporary variable**
**Problem:** Swap two integers using bitwise XOR.

**Solution:**
```c
#include<stdio.h>

void swap(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main() {
    int x = 5, y = 10;
    printf("Before swapping: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swapping: x = %d, y = %d\n", x, y);
    return 0;
}
```
**Output:**
```
Before swapping: x = 5, y = 10
After swapping: x = 10, y = 5
```
**Explanation:** XOR has the property:
- `x ^ x = 0`
- `x ^ 0 = x`

---

### **4. Check if a number is a power of 2**
**Problem:** Determine if a given number is a power of 2.

**Solution:**
```c
#include<stdio.h>

int isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main() {
    int num = 16;
    if (isPowerOfTwo(num))
        printf("%d is a power of 2\n", num);
    else
        printf("%d is not a power of 2\n", num);
    return 0;
}
```
**Output:**
```
16 is a power of 2
```
**Explanation:**
- A number is a power of 2 if it has exactly one set bit (e.g., `2: 10`, `4: 100`, `8: 1000`).
- `n & (n - 1)` clears the lowest set bit, and it will be `0` for powers of 2.

---

### **5. Reverse the bits of a number**
**Problem:** Reverse the binary representation of an integer.

**Solution:**
```c
#include<stdio.h>

unsigned int reverseBits(unsigned int n) {
    unsigned int rev = 0;
    for (int i = 0; i < 32; i++) { // Assume 32-bit integers
        rev <<= 1;         // Left shift rev by 1 to make room for the next bit
        rev |= (n & 1);    // Append the last bit of n to rev
        n >>= 1;           // Right shift n to process the next bit
    }
    return rev;
}

int main() {
    unsigned int num = 13; // Binary: 00000000000000000000000000001101
    unsigned int result = reverseBits(num);
    printf("Reversed bits: %u\n", result);
    return 0;
}
```
**Output:**
```
Reversed bits: 2952790016
```
**Explanation:**
- The binary representation is reversed bit by bit.

---

### **6. Find the unique element in an array where all elements except one appear twice**
**Problem:** Given an array where every element appears twice except for one, find the unique element.

**Solution:**
```c
#include<stdio.h>

int findUnique(int arr[], int n) {
    int unique = 0;
    for (int i = 0; i < n; i++) {
        unique ^= arr[i]; // XOR cancels out duplicate elements
    }
    return unique;
}

int main() {
    int arr[] = {2, 3, 5, 4, 5, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("The unique element is: %d\n", findUnique(arr, size));
    return 0;
}
```
**Output:**
```
The unique element is: 2
```
**Explanation:**
- XOR has the property: `x ^ x = 0` and `x ^ 0 = x`.
- Duplicates cancel out, leaving the unique element.

---

These problems show how bitwise operators can be used effectively in solving algorithmic challenges. They are especially useful for optimizing performance in low-level operations.