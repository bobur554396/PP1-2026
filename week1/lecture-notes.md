# Lecture 1 — Introduction to Programming and C++

## 1. What is a Program?

A **program** is a list of instructions written by a human to be executed by a computer.

- Computers understand **machine code**: a binary language of `0` and `1`
- Humans need tools to write instructions in a readable form and translate them into machine code — these tools are **programming languages**


### Human Language → Machine Language

To convert programming languages into machine code, we use **translators**:

### 1. Compiler

- Translates the **entire code at once**, before the program is run
- Examples of compiled languages:  
  `C`, `C++`, `Rust`, `Go`

> 🧠 `Java` and `C#` are a mixed case: they are compiled to an intermediate **bytecode**, which is then executed by a virtual machine.

### 2. Interpreter

- Translates code **line by line**
- Examples of interpreted languages:  
  `Python`, `Ruby`, `JavaScript`

--- 

### Programming Languages Overview

### High-Level Languages

- Closer to human language
- Easier to learn and write
- Examples:  
  `Python`, `Ruby`, `Java`, `C#`, `JavaScript`

### Mid-Level Languages

- Balance between high-level convenience and low-level control (direct memory access, pointers)
- Examples:  
  `C`, `C++`, `Rust`

### Low-Level Languages

- Close to machine/hardware level
- Harder to write and read
- Example:  
  `Assembly`


### About C++

- **C++** is a **compiled**, mid-level programming language
- Uses a **compiler**: `MinGW g++`
- Recommended editor: **Visual Studio Code (VSCode)**

---

## 2. What is a Variable?

A **variable** is a named storage location in memory that holds a value which can change during program execution.

Think of a variable as a **container** that stores data — such as a number, a letter, or a word — so that you can refer to it by name in your code.


### Declaration Syntax

In C++, a variable must be **declared with a specific type** before you use it.

```cpp
type variableName;
```

You can also assign a value at the time of declaration:

```cpp
type variableName = value;
```

## Allowed Characters and Rules for Variable Names in C++

In **C++**, variable names (also called *identifiers*) must follow specific rules to be valid.


### Allowed Characters

- **Letters**: `a–z`, `A–Z`
- **Digits**: `0–9` (but **not as the first character**)
- **Underscore**: `_`


### Rules for Naming Variables

1. Must **start with a letter** (`a–z`, `A–Z`) or **underscore** (`_`)
   - ✅ `count`, `_value`
   - ❌ `1stNumber` ← Invalid: starts with a digit

2. Can contain **letters**, **digits**, and **underscores**
   - ✅ `user_name`, `total1`, `x2_y3`

3. Cannot use **C++ keywords** as variable names
   - ❌ `int`, `while`, `return`, `class`, etc.

4. **Case-sensitive**
   - `Value` and `value` are different variables in C++


### 🚫 Invalid Examples

| Variable Name | Reason                        |
|---------------|-------------------------------|
| `2total`      | Starts with a digit           |
| `float`       | Reserved keyword              |
| `my-var`      | Hyphens (`-`) not allowed     |
| `total$`      | Dollar sign (`$`) not allowed |
| `user name`   | Contains space                |


### Valid Examples

```cpp
int count;
double total_sum;
char firstLetter;
bool _isReady;
int MAX_VALUE1;
```

### Example with initial values

```cpp
int age = 20;
double pi = 3.14159;
float rate = 0.95f;
char grade = 'A';
bool isOnline = true;
```
---

## 3. Arithmetic Operations

Arithmetic operations allow you to perform mathematical calculations using variables and constants in C++.

### Basic Arithmetic Operators

| Operator | Description          | Example (`a = 10`, `b = 3`) |
|----------|----------------------|-----------------------------|
| `+`      | Addition              | `a + b` → `13`              |
| `-`      | Subtraction           | `a - b` → `7`               |
| `*`      | Multiplication        | `a * b` → `30`              |
| `/`      | Division              | `a / b` → `3`               |
| `%`      | Modulus (remainder)  | `a % b` → `1`               |

> 🧠 **Note**:  
> `/` performs **integer division** if both operands are integers (the fractional part is discarded, not rounded).  
> `%` works with **integers only** — `10.5 % 3` will not compile.

<img src="./img/operators.jpeg" alt="Operators" width="400"/>

### Example Code

```cpp
#include <iostream>

using namespace std;

int main() {
    int a = 10;
    int b = 3;

    cout << "Addition (a + b): " << a + b << endl;
    cout << "Subtraction (a - b): " << a - b << endl;
    cout << "Multiplication (a * b): " << a * b << endl;
    cout << "Integer Division (a / b): " << a / b << endl;
    cout << "Modulus (a % b): " << a % b << endl;

    return 0;
}
```

### ⚠️ Common Mistakes

- **Dividing by zero**:

```cpp
int a = 0;
int x = 5 / a; // ❌ Undefined behavior — usually crashes the program at runtime
```

> With a literal zero (`5 / 0`) `g++` will already refuse to compile the code.

- **Expecting a float result from integer division**:

```cpp
int result = 5 / 2; // result = 2 (not 2.5)
```

✅ To get a float result, at least one operand must be a floating-point number:

```cpp
float result = 5.0 / 2; // result = 2.5
```
---

## 4. Assigning Values

In C++, **assigning a value** means storing a specific piece of data into a variable using the **assignment operator** (`=`).


### Basic Syntax

```cpp
type variableName = value;
```

Or declare first, then assign later:

```cpp
int x;
x = 10;
```


### Assignment Operator `=`

The `=` symbol assigns the value **on the right** to the variable **on the left**.

```cpp
int a = 5;   // a now holds the value 5
a = 10;      // a is updated to hold 10
```

> ⚠️ Note: This is not an equality check. It’s a one-way assignment.


### Reassigning Values

Variables can be updated later in the program:

```cpp
int score = 0;
score = score + 10;  // Now score is 10
```

You can also use shorthand operators:

```cpp
score += 5;  // score = score + 5
score -= 2;  // score = score - 2
score *= 3;  // score = score * 3
score /= 2;  // score = score / 2
score %= 4;  // score = score % 4
```


### Example Code

```cpp
#include <iostream>

using namespace std;

int main() {
    int x = 10;
    int y;

    y = x + 5;  // Assign result of an expression to y

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;

    x = 42;     // Reassign new value to x

    cout << "x (after reassignment): " << x << endl;

    return 0;
}
```


### ⚠️ Common Mistakes

- **Using a variable before assigning a value:**

```cpp
int z;
cout << z; // ⚠️ May produce garbage or warning: 'z' is uninitialized
```

- **Confusing assignment (`=`) with comparison (`==`):**

```cpp
if (x = 5) {   // ❌ Incorrect: assigns 5 to x, then checks that value
    // 5 is not 0, so this condition is ALWAYS true
}
```

✅ Correct usage:

```cpp
if (x == 5) {  // ✅ Checks if x equals 5
    // Do something
}
```

---

## 5. Introduction to Data Types

In C++, every variable must be declared with a **data type**, which tells the compiler:

- What kind of data the variable can store
- How much memory it needs
- What operations can be performed on it

Data types are a **core part** of the language and help C++ be fast and type-safe.


### Common Data Types in C++

| Type     | Description                        | Size (Bytes) | Typical Range                          |
|----------|------------------------------------|--------------|----------------------------------------|
| `int`    | Integer (whole number)             | 4            | −2,147,483,648 to 2,147,483,647        |
| `double` | Double-precision decimal number    | 8            | ±1.7×10<sup>±308</sup> (~15 digits)    |
| `float`  | Single-precision decimal number    | 4            | ±3.4×10<sup>±38</sup> (~6-7 digits)    |
| `char`   | Single character                   | 1            | −128 to 127 (ASCII uses 0–127)          |
| `bool`   | Boolean (`true` or `false`)        | 1            | `true` (1), `false` (0)                |
| `string` | Sequence of characters             | varies       | Depends on content length              |

> Sizes can vary slightly depending on your system and compiler, but these are typical for 64-bit systems using GCC or Clang.


### How to Check Data Type Size

You can use the `sizeof()` operator to check memory usage at runtime:

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;
    cout << "Size of float: " << sizeof(float) << " bytes" << endl;
    cout << "Size of char: " << sizeof(char) << " byte" << endl;
    cout << "Size of bool: " << sizeof(bool) << " byte(s)" << endl;

    return 0;
}
```


### Syntax Examples

```cpp
int age = 20;
double pi = 3.14159;
float temperature = -12.5f;
char grade = 'A';
bool isLoggedIn = true;
string name = "Alice";
```


### Type Details

#### `int`
- Stores whole numbers
- Typically uses **4 bytes**
- Range: ~ −2,147,483,648 to 2,147,483,647

#### `double`
- High-precision floating-point number
- Used by default when you write decimal numbers like `3.14`

#### `float`
- Less precision than `double`
- Takes less memory
- Append `f` to constants (e.g. `2.5f`)

#### `char`
- Stores a single character using single quotes (`'A'`)
- Internally represented using **ASCII codes**

#### `bool`
- Stores logical values: `true` or `false`
- Often used in conditions (`if`, `while`, etc.)

#### `string`
- Stores text (sequence of characters)
- Defined in the `<string>` header
- Many built-in functions like `.length()`, `.substr()`, `.find()`


### Example Program

```cpp
#include <iostream>

#include <string> // Required for using string in some versions

using namespace std;

int main() {
    int age = 18;
    double gpa = 3.75;
    float speed = 5.5f;
    char grade = 'B';
    bool passed = true;
    string name = "Bob";

    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "GPA: " << gpa << endl;
    cout << "Speed: " << speed << endl;
    cout << "Grade: " << grade << endl;
    cout << "Passed: " << passed << endl; // 1 = true, 0 = false

    return 0;
}
```


### ⚠️ Common Mistakes

- ❌ Mixing incompatible types:

```cpp
int x = 5.6; // x will be assigned 5 (decimal truncated)
```

✅ Fix:

```cpp
double x = 5.6; // Correct type for decimal
```

---


## 6. ASCII Code – Short Introduction

### What is ASCII?

**ASCII** stands for **American Standard Code for Information Interchange**.  
It is a character encoding standard that assigns **numeric values (0–127)** to characters like letters, digits, symbols, and control codes.

In C++, `char` values are stored as **integers** behind the scenes — using their ASCII values.


### ASCII Table (Common Characters)

| Character | ASCII Code |
|-----------|-------------|
| `'A'`     | `65`        |
| `'Z'`     | `90`        |
| `'a'`     | `97`        |
| `'z'`     | `122`       |
| `'0'`     | `48`        |
| `'9'`     | `57`        |
| `' '`     | `32` (space)|

> Full ASCII table includes control characters, symbols, and more.

![Full ASCII Table](./img/ascii-table.jpg)

### How C++ Handles `char` and ASCII

You can convert a character to its ASCII code using `int` cast, or convert ASCII code to character using `char` cast.

#### Character to ASCII

```cpp
char c = 'A';
cout << (int)c; // Output: 65
```

#### ASCII to Character

```cpp
int code = 66;
cout << (char)code; // Output: B
```


### Example Program

```cpp
#include <iostream>

using namespace std;

int main() {
    char letter = 'C';
    int asciiCode = (int)letter;

    cout << "Character: " << letter << endl;
    cout << "ASCII Code: " << asciiCode << endl;

    // Reverse: ASCII to character
    int num = 68;
    cout << "ASCII 68 is character: " << (char)num << endl;

    return 0;
}
```

## 7. Math Functions (`sqrt`, `abs`, `sin`, `max`, `min`, `pow`)

C++ provides a wide range of built-in math functions in the **`<cmath>`** library.

To use these functions, you must include the following header:

```cpp
#include <cmath>
```


### Common Math Functions

| Function     | Description                          | Example                     |
|--------------|--------------------------------------|-----------------------------|
| `sqrt(x)`    | Square root                          | `sqrt(25)` → `5`            |
| `abs(x)`     | Absolute value                       | `abs(-3)` → `3`             |
| `sin(x)`     | Sine (input in radians)              | `sin(0)` → `0`              |
| `pow(x, y)`  | Power of x raised to y (`x^y`)       | `pow(2, 3)` → `8`           |
| `max(a, b)`  | Maximum of two numbers               | `max(4, 9)` → `9`           |
| `min(a, b)`  | Minimum of two numbers               | `min(4, 9)` → `4`           |

> ⚠️ `max()` and `min()` are **not** part of `<cmath>` — officially they belong to the `<algorithm>` header.

> 🧠 **In practice:** on most compilers this code will build even with only `#include <iostream>`, because `<iostream>` quietly pulls in other headers behind the scenes. **Do not rely on this** — it is not guaranteed by the C++ standard and changes between compilers and compiler versions. Always include the header you actually use, so your code works everywhere.

> ⚠️ Most of these functions work with `double` values. Cast as needed if you're using `int`.


### Example Program

```cpp
#include <iostream>
#include <cmath>
#include <algorithm> // the official home of max() and min()

using namespace std;

int main() {
    int a = -10;
    double angle = 0.5; // in radians

    cout << "sqrt(16): " << sqrt(16) << endl;
    cout << "abs(a): " << abs(a) << endl;
    cout << "sin(angle): " << sin(angle) << endl;
    cout << "pow(2, 3): " << pow(2, 3) << endl;
    cout << "max(10, 20): " << max(10, 20) << endl;
    cout << "min(10, 20): " << min(10, 20) << endl;

    return 0;
}
```


### ⚠️ Common Mistakes

- Forgetting to `#include <cmath>`:

```cpp
cout << sqrt(25); // ⚠️ May build on your machine, but can fail with
                  //    "error: 'sqrt' was not declared in this scope"
                  //    on another compiler. Include <cmath>.
```

- Using degrees with `sin()` instead of radians:

```cpp
// sin(90) is about 0.894, not 1, because 90 is read as radians
double result = sin(90); // ❌ Incorrect
```

✅ Correct:

```cpp
double radians = 90 * 3.14159 / 180;
double result = sin(radians); // ✅ Correct
```

