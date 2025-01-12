### **Arrays in Data Structure**

An **array** is a collection of elements, all of the same data type, stored in contiguous memory locations. Arrays are one of the simplest and most commonly used data structures. They allow random access to elements using an index.

#### **Characteristics of Arrays:**
1. **Fixed Size:** The size of an array is defined at the time of its declaration and cannot be changed dynamically.
2. **Homogeneous Elements:** All elements in an array are of the same data type.
3. **Contiguous Memory Allocation:** Elements are stored in adjacent memory locations.
4. **Indexing:** Elements are accessed using an index, starting from 0 in most programming languages.

#### **Advantages of Arrays:**
- Easy to access elements using indices.
- Efficient for iterating through elements.

#### **Disadvantages of Arrays:**
- Fixed size limits flexibility.
- Insertion and deletion operations can be costly as elements may need to be shifted.

#### **Example in C++:**
```cpp
int arr[5] = {10, 20, 30, 40, 50}; // Declaration and initialization
cout << arr[2]; // Accessing the third element (30)
```
