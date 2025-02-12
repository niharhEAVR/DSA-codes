## This repo contains all the c codes which i used to learn the DSA in my 2nd year, There is more coming!!!


## ➡️ So doing the advanced DSA in c we need the Mingw 64-bit compiler

To compile for 64-bit, you need to install and use **MinGW-w64**:

#### **Step 1: Check if You Have MinGW-w64 Installed**
Run:
```sh
gcc -v
```
If it mentions `mingw32`, you're using the 32-bit version.

#### **Step 2: Install MinGW-w64 (64-bit GCC)**
1. **Download MinGW-w64**  
   - Go to: [https://www.mingw-w64.org/](https://www.mingw-w64.org/)
   - Install the **64-bit version**.

2. **Add MinGW-w64 to Your PATH**  
   After installing, update your system's PATH variable:
   - Open **System Properties** → **Advanced** → **Environment Variables**.
   - Add the path to `mingw64\bin` (e.g., `C:\mingw64\bin`).

3. **Verify the Installation**  
   Run:
   ```sh
   gcc -dumpmachine
   ```
   If it shows **x86_64-w64-mingw32**, you're now using the 64-bit version.

#### **Step 3: Compile Your Code in 64-bit Mode**
If you want to use the 64-bit compiler explicitly, try:
```sh
x86_64-w64-mingw32-gcc yourfile.c -o output.exe
```

Now, when you check `sizeof(int*)`, it should return **8 bytes** instead of 4. ⬅️
