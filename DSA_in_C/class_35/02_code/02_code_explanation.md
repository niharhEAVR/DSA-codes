This line of code: 

```c
if (isalnum(ch)) { postfix[j++] = ch; }
```

### Explanation:
1. **Condition: `isalnum(ch)`**  
   - `isalnum(ch)` is a function from `<ctype.h>` that checks if the character `ch` is **alphanumeric**.  
   - Alphanumeric characters include:
     - Uppercase letters (`A-Z`)
     - Lowercase letters (`a-z`)
     - Digits (`0-9`)
   - If `ch` is an alphanumeric character, the condition evaluates to `true`.

2. **Action: `postfix[j++] = ch;`**  
   - This adds the alphanumeric character `ch` to the `postfix` array (the output).
   - The `postfix[j++]` syntax means:
     - Assign `ch` to the `postfix` array at index `j`.
     - Then, **increment** the value of `j` by 1.  
   - This ensures the next character is stored in the next position in the `postfix` array.

---

### Purpose
- In **infix-to-postfix conversion**, operands (like `A`, `B`, `1`, `2`) are directly copied to the **postfix expression**, without any modifications.
- The `if (isalnum(ch))` block ensures only valid operands are added to the result.

---

### Example:
For the input:  
```
Infix Expression: A+B*C
```
Processing `isalnum`:
- **'A'**: Alphanumeric → Added to `postfix`, `postfix[0] = 'A'`.
- **'B'**: Alphanumeric → Added to `postfix`, `postfix[1] = 'B'`.
- **'C'**: Alphanumeric → Added to `postfix`, `postfix[2] = 'C'`.

The output after this step would look like:  
```
Postfix Array: ['A', 'B', 'C']
``` 

Let me know if this makes sense! 😊