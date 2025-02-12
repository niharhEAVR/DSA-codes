### **Does Passing an Array to a Function Require a Pointer?**
Yes, when you pass an array to a function in C, it is **implicitly converted into a pointer** to its first element. This means inside the function, the parameter is treated as a pointer, even if the array was passed as an argument.

---

### **Understanding Your Code**
```c
#include <stdio.h>
#include <string.h>

void printname(char *name) { // 'name' is a pointer to the first character of the array
    for (int i = 0; i < strlen(name); i++) {
        char ch = name[i]; // Accessing array elements using pointer notation
        if (name[i] == 'D') {
            printf("Found D\n");
        }
    }
    puts(name);
}

int main() {
    char name[] = "Nihar Debnath"; // name is an array of characters
    printname(name); // Passing the array (converted to pointer)
    return 0;
}
```

### **How Does the Array Work in Function Calls?**
- When you declare `char name[] = "Nihar Debnath";` inside `main()`, `name` is an **array**.
- But when you pass `name` to `printname(name);`, it **decays into a pointer** to the first element (`char*`).
- Inside `printname()`, the parameter `char *name` acts as a pointer to the first character of the array.
- Thus, `name[i]` works just like accessing an array.

### **Alternative Declaration: Array Parameter vs Pointer**
You can declare the function parameter as:
```c
void printname(char name[]) {  // name[] is still treated as a pointer
```
or
```c
void printname(char *name) {  // Equivalent: pointer to first element
```
Both are functionally the same because **arrays decay into pointers** when passed to functions.

### **Key Takeaways**
✅ **Passing an array to a function implicitly converts it to a pointer**.  
✅ **Inside the function, you can access it using pointer or array notation (`name[i]`)**.  
✅ **Using `char name[]` or `char *name` in the function parameter is the same**.
