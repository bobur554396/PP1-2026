# How to Compile and Run C++ Code from Terminal

Use the following steps to compile and run C++ programs on different operating systems using the terminal.

---

## Windows (using MinGW)

1. 📦 [Download MinGW (mingw64tdm.7z)](https://www.dropbox.com/scl/fi/tqr1y8ut31lfkapgsbicp/mingw64tdm.7z?rlkey=qhng07c0014udgrransk6jc1j&e=1&dl=0)
2. 🗂 Extract it to the root of your drive (e.g., `C:\` or `D:\`)
3. 🛠 Follow this video tutorial to configure MinGW and add `g++` to your system `PATH`:  
   🎥 [MinGW Configuration on Windows](https://www.youtube.com/watch?v=m4jZDXdT_tM)

After setup, test compilation:

1. Open **Command Prompt** or **PowerShell**  
2. Navigate to your C++ file location:
   ```bash
   cd path\to\your\folder
   ```
3. Compile the code:
   ```bash
   g++ main.cpp
   ```
4. Run the program:

   In **Command Prompt**:
   ```bat
   a.exe
   ```

   In **PowerShell** you must include the `.\` prefix, because PowerShell does
   not run programs from the current folder by default:
   ```powershell
   .\a.exe
   ```
---

## Mac OS

> ✅ First-time setup may require installing command-line tools:
```bash
xcode-select --install
```
> ℹ️ On macOS the `g++` command is Apple's `clang++` compiler under a different
> name. `g++ --version` will report `Apple clang` — this is normal and works
> fine for this course.

1. Open the Terminal  
2. Navigate to your project folder:
   ```bash
   cd ~/your/folder/
   ```
3. Compile the code:
   ```bash
   g++ main.cpp
   ```
4. Run the program:
   ```bash
   ./a.out
   ```

---

## Linux

> ✅ Most Linux distributions come with `g++` pre-installed. If not, install it using:
```bash
sudo apt install g++
```

1. Open the terminal  
2. Navigate to your C++ file location:
   ```bash
   cd ~/your/folder/
   ```
3. Compile the code:
   ```bash
   g++ main.cpp
   ```
4. Run the program:
   ```bash
   ./a.out
   ```

---


## Example Code (main.cpp)

```cpp
#include <iostream>

using namespace std;

int main() {

    cout << "Hello, world!" << endl;
    
    return 0;
}
```

After compiling and running, your terminal will display:

```
Hello, world!
```
