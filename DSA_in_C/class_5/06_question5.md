Let's analyze the **time complexity** of the `isPrime` function step by step.

### **Code Analysis**
```c
int isPrime(int n)
{
    if (n == 1)    // Base case: if n is 1, return 0 (not prime)
    {
        return 0;
    }
    for (int i = 2; i * i < n; i++)   // Loop to check divisibility
    {
        if (n % i == 0)   // If n is divisible by i, it's not prime
        {
            return 0;
        }
    }
    return 1;   // If no divisors were found, n is prime
}
```

### **Step-by-Step Analysis**

1. **Base Case:**
   - The function first checks if \( n \) is equal to 1. This is a constant-time operation, \( O(1) \).

2. **For Loop:**
   - The loop runs from \( i = 2 \) to \( i \times i < n \). The condition \( i \times i < n \) is equivalent to \( i < \sqrt{n} \), so the loop runs approximately \( \sqrt{n} \) times.
   - In each iteration of the loop, the function checks if \( n \) is divisible by \( i \) using the modulus operator (`n % i`), which is a constant-time operation, \( O(1) \).

3. **Worst Case:**
   - In the worst case, the loop runs \( O(\sqrt{n}) \) times because the loop continues as long as \( i \times i < n \). If no divisor is found during the loop, the function returns 1, indicating that \( n \) is prime.

### **Time Complexity Analysis:**
- The loop runs \( O(\sqrt{n}) \) times, and in each iteration, the modulus operation takes constant time, \( O(1) \).
- Therefore, the total time complexity is \( O(\sqrt{n}) \).

### **Final Answer:**
The **time complexity** of the `isPrime` function is \( O(\sqrt{n}) \), where \( n \) is the number being tested for primality.

### **Explanation in Simple Terms:**
- To check if a number \( n \) is prime, the function checks if any number from 2 up to \( \sqrt{n} \) divides \( n \) without a remainder.
- This means that the function only needs to check up to \( \sqrt{n} \), which makes the process much faster than checking all numbers up to \( n-1 \).
