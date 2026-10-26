# Lecture 7: Functions in C++

## 1. What is a Function?
A **function** is a reusable block of code that performs a specific task. It helps organize
code, reduce repetition, and improve readability.

- **Key Benefits**:
  - Code reusability
  - Easier debugging
  - Modular programming
  - Abstraction (hide implementation details)

You have been calling functions since Lecture 1: `main` is a function, and so are `sort`,
`reverse` and `s.size()`. Now we start writing our own.

## 2. Built-in Functions

C++ provides many **built-in functions** in standard libraries. You must include the right
header for each one.

### 2.1 `sort`, `reverse` (`<algorithm>`)
```cpp
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int arr[] = {5, 3, 8, 1};
    int n = 4;

    sort(arr, arr + n);           // Sort ascending
    for (int i = 0; i < n; i++) cout << arr[i] << " ";  // 1 3 5 8
    cout << endl;

    reverse(arr, arr + n);        // Reverse array
    for (int i = 0; i < n; i++) cout << arr[i] << " ";  // 8 5 3 1
    cout << endl;

    return 0;
}
```

**Output**
```
1 3 5 8
8 5 3 1
```

### 2.2 `tolower`, `toupper` (`<cctype>`)
```cpp
#include <iostream>
#include <cctype>

using namespace std;

int main() {
    char c = 'A';
    cout << (char)tolower(c) << endl;   // a
    cout << (char)toupper(c) << endl;   // A

    char d = 'b';
    cout << (char)toupper(d) << endl;   // B

    // Without the cast you get the ASCII code, not the letter
    cout << tolower(c) << endl;         // 97
    return 0;
}
```

**Output**
```
a
A
B
97
```

Both functions take and return an **`int`**, not a `char`. Printing the result without a
`(char)` cast shows the ASCII code: `cout << tolower('A')` prints `97`, not `a`. Non-letters
are returned unchanged, so `toupper('5')` is `'5'`.

### 2.3 `isalpha`, `isdigit`, `isalnum`, `ispunct` (`<cctype>`)
```cpp
#include <iostream>
#include <cctype>

using namespace std;

int main() {
    char ch = '5';
    cout << isdigit(ch) << endl;  // non-zero: it is a digit
    cout << isalpha(ch) << endl;  // 0: it is not a letter
    cout << isalnum(ch) << endl;  // non-zero: digit or letter
    cout << ispunct('!') << endl; // non-zero: punctuation

    if (isdigit(ch)) {
        cout << ch << " is a digit" << endl;   // the normal way to use them
    }
    return 0;
}
```

These return an `int` where `0` means false and **any** non-zero value means true. The exact
non-zero number is not fixed: on g++ with glibc this program prints `1 0 8 4`, and another
compiler may print `1 0 1 1`. So never write `if (isalnum(c) == 1)`; use the result directly
in an `if`, as the last lines show.

### 2.4 `sqrt`, `pow` (`<cmath>`) and `max`, `min` (`<algorithm>`)
```cpp
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    cout << sqrt(16) << endl;     // 4
    cout << pow(2, 3) << endl;    // 8
    cout << max(10, 20) << endl;  // 20
    cout << min(10, 20) << endl;  // 10

    return 0;
}
```

**Output**
```
4
8
20
10
```

Two things to notice:

- `sqrt` and `pow` return a `double`. `cout` hides the decimal part when it is zero, so `4`
  on screen is really `4.0`. Storing the result in an `int` truncates it:
  `int r = sqrt(15);` gives 3.
- `max` and `min` need **both arguments of the same type**. `max(3, 4.5)` does not compile;
  write `max(3.0, 4.5)`.

---

## 3. Intro to User-Defined Functions

### 3.1 Function Declaration and Definition

#### Before `main()` (Recommended)
```cpp
#include <iostream>

using namespace std;

// Declaration + Definition
void hello() {
    cout << "Hello!" << endl;
}

int main() {
    hello();  // Function call
    return 0;
}
```

#### After `main()` (Need Declaration First)
```cpp
#include <iostream>

using namespace std;

// Declaration (prototype), note the semicolon
void hello();

int main() {
    hello();  // Call
    return 0;
}

// Definition
void hello() {
    cout << "Hello!" << endl;
}
```

The compiler reads the file from top to bottom, so it must have seen the function's name,
return type and parameters before the call. Either define the function above `main`, or put a
**prototype** above `main` and the body below it.

### 3.2 Function Parameters
```cpp
#include <iostream>
#include <string>

using namespace std;

void greet(string name) {
    cout << "Hello, " << name << "!" << endl;
}

int main() {
    greet("Alice");
    greet("Bob");
    return 0;
}
```

**Output**
```
Hello, Alice!
Hello, Bob!
```

The names in the definition (`name`) are **parameters**; the values at the call site
(`"Alice"`) are **arguments**. They are matched by position, and the count and types must fit.

### 3.3 Types of Functions
- **Returning a value** (`int`, `double`, `bool`, `string`, ...)
- **Void functions** (no return value)

```cpp
#include <iostream>

using namespace std;

int sum(int a, int b) {
    return a + b;          // gives a value back to the caller
}

void sayHi() {
    cout << "Hi!" << endl; // returns nothing
}

int main() {
    cout << sum(2, 3) << endl;
    sayHi();
    return 0;
}
```

A `void` function cannot be used in an expression: `int x = sayHi();` does not compile. In a
value-returning function **every** path must `return` something, otherwise the returned value
is garbage. A bare `return;` inside a `void` function just leaves it early.

### 3.4 Local vs Global Variables
```cpp
#include <iostream>

using namespace std;

int global = 100;  // Global variable

void demo() {
    int local = 5;  // Local to function
    cout << "Local: " << local << endl;
    cout << "Global: " << global << endl;
}

int main() {
    demo();
    cout << "Global in main: " << global << endl;
    // cout << local;  // Error! local is not accessible
    return 0;
}
```

**Output**
```
Local: 5
Global: 100
Global in main: 100
```

A local variable is created when the function starts and destroyed when it ends, so two
functions may both use a name like `i` without interfering. A variable declared inside any
`{ }` block, such as a loop body, lives only in that block. Globals are visible everywhere,
which is exactly why they make bugs hard to find: any function can change them.

---

## 4. Examples

### 4.1 `hello` - Simple Function
```cpp
#include <iostream>

using namespace std;

void hello() {
    cout << "Hello!" << endl;
}

int main() {
    hello();
    return 0;
}
```

### 4.2 `hello name` - With Parameter
```cpp
#include <iostream>
#include <string>

using namespace std;

void hello(string name) {
    cout << "Hello, " << name << "!" << endl;
}

int main() {
    string name;
    cin >> name;
    hello(name);
    return 0;
}
```

**Input**
```
Alice
```
**Output**
```
Hello, Alice!
```

### 4.3 `sum of two` - Return Value
```cpp
#include <iostream>

using namespace std;

int sum(int a, int b) {
    return a + b;
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << "Sum: " << sum(x, y) << endl;
    return 0;
}
```

### 4.4 `max of two`
```cpp
#include <iostream>

using namespace std;

int maxOfTwo(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << "Max: " << maxOfTwo(x, y) << endl;
    return 0;
}
```

Naming it `maxOfTwo` rather than `max` avoids a clash with `std::max`, which
`using namespace std;` has already brought into scope.

### 4.5 `my power` - Handle Negative Exponent
```cpp
#include <iostream>

using namespace std;

double power(double base, int exp) {
    int e = exp;
    if (e < 0) {
        e = -e;              // work with a positive count of multiplications
    }

    double result = 1.0;
    for (int i = 0; i < e; i++) {
        result *= base;
    }

    if (exp < 0) {
        result = 1.0 / result;   // negative exponent means the reciprocal
    }
    return result;
}

int main() {
    double b;
    int e;
    cin >> b >> e;
    cout << power(b, e) << endl;
    return 0;
}
```

**Input**
```
2 -3
```
**Output**
```
0.125
```

Note `power(x, 0)` returns 1, because the loop body never runs.

### 4.6 `factorial`
```cpp
#include <iostream>

using namespace std;

long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    cout << factorial(n) << endl;
    return 0;
}
```

**Input**
```
20
```
**Output**
```
2432902008176640000
```

`factorial(0)` and `factorial(1)` both return 1, since the loop starts at 2. Even with
`long long`, 20! is the largest value that fits: `factorial(21)` silently overflows and prints
a wrong number.

### 4.7 `isPrime`
```cpp
#include <iostream>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    cout << (isPrime(n) ? "YES" : "NO") << endl;
    return 0;
}
```

The condition `i * i <= n` stops at the square root of `n`: if `n` has a divisor larger than
its square root, it must also have a matching one that is smaller, and we would have found
that first. A function that answers a yes-or-no question should return `bool`, not print.

### 4.8 `toUpper`, `toLower`, `isDigit` - Character Functions
Written by hand, without the `<cctype>` helpers, using the ASCII table from Lecture 6.

```cpp
#include <iostream>

using namespace std;

char toUpper(char c) {
    if (c >= 'a' && c <= 'z') {
        return (char)(c - 'a' + 'A');
    }
    return c;                      // not a lowercase letter, leave it alone
}

char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return (char)(c - 'A' + 'a');
    }
    return c;
}

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    char ch;
    cin >> ch;

    cout << "Upper: " << toUpper(ch) << endl;
    cout << "Lower: " << toLower(ch) << endl;
    cout << "Is digit: " << (isDigit(ch) ? "YES" : "NO") << endl;

    return 0;
}
```

**Input**
```
g
```
**Output**
```
Upper: G
Lower: g
Is digit: NO
```

`c - 'a'` gives the letter's position in the alphabet, and adding `'A'` moves it to the
uppercase block. Our versions return `char` and `bool`, which is why they need no cast at the
call site, unlike the library's `toupper`.

---

## 5. Summary of Key Concepts

| Concept | Description |
|-------|-----------|
| **Function Declaration** | Tells compiler about function name, return type, parameters |
| **Function Definition** | Actual body of the function |
| **Parameters** | Inputs to the function |
| **Arguments** | The values passed in at the call site |
| **Return Type** | Data type of value returned (`void` if none) |
| **Local Variable** | Defined inside function, scope limited to function |
| **Global Variable** | Defined outside, accessible everywhere |
| **Pass by Value** | The function gets a copy, the caller's variable is unchanged |
| **Pass by Reference** | `int &x`, the function works on the caller's own variable |

---

## 6. Best Practices
- Always declare functions before use
- Avoid global variables when possible
- Keep functions small and focused on one task
- Use meaningful function and parameter names
- Return a value instead of printing inside the function, so the result can be reused
- Pass an array together with its size, since the function cannot work it out itself

---

# Appendix A. Additional Material

Not covered in the lecture. Lab 7 and the course manual use these, so read them before the lab.

## A.1 Pass by Value
```cpp
#include <iostream>

using namespace std;

void increment(int x) {
    x++;                 // changes the copy only
    cout << "inside: " << x << endl;
}

int main() {
    int a = 5;
    increment(a);
    cout << "outside: " << a << endl;
    return 0;
}
```

**Output**
```
inside: 6
outside: 5
```

By default a parameter is a **copy** of the argument. Changing it has no effect on the
caller's variable.

## A.2 Pass by Reference
```cpp
#include <iostream>

using namespace std;

void increment(int &x) {     // note the &
    x++;                     // changes the caller's variable
}

void order(int &a, int &b) { // make a <= b
    if (a > b) {
        int t = a;
        a = b;
        b = t;
    }
}

int main() {
    int a = 5;
    increment(a);
    cout << a << endl;       // 6

    int x = 9, y = 4;
    order(x, y);
    cout << x << " " << y << endl;   // 4 9
    return 0;
}
```

**Output**
```
6
4 9
```

The `&` makes the parameter another name for the caller's variable. Use it when the function
must **change** its argument, or to return more than one value.

## A.3 Arrays as Parameters
```cpp
#include <iostream>

using namespace std;

int sumArray(int a[], int n) {      // read only
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += a[i];
    }
    return total;
}

void doubleAll(int a[], int n) {    // changes the caller's array
    for (int i = 0; i < n; i++) {
        a[i] *= 2;
    }
}

int main() {
    int a[5] = {1, 2, 3, 4, 5};

    cout << sumArray(a, 5) << endl;     // 15

    doubleAll(a, 5);
    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";            // 2 4 6 8 10
    }
    cout << endl;
    return 0;
}
```

**Output**
```
15
2 4 6 8 10
```

An array is **never copied** when passed to a function, so the function always works on the
caller's real data, with or without `&`. Two consequences:

- Changes inside the function are visible outside, as `doubleAll` shows.
- The parameter carries no size, so `sizeof` does not work on it. Always pass the count as a
  second parameter.

## A.4 2D Arrays as Parameters
```cpp
#include <iostream>

using namespace std;

const int MAXN = 100;
int a[MAXN][MAXN];

void printMatrix(int m[][MAXN], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> a[i][j];
        }
    }
    printMatrix(a, n, k);
    return 0;
}
```

The **row** count may be left out of the parameter, but the **column** count is mandatory and
must be the same number used in the declaration: `int a[MAXN][MAXN]` in `main` needs
`int m[][MAXN]` in the parameter. A mismatch is a compile error, not a silent bug.

## A.5 Function Overloading
```cpp
#include <iostream>

using namespace std;

int maxOf(int a, int b) {
    return a > b ? a : b;
}

double maxOf(double a, double b) {
    return a > b ? a : b;
}

int maxOf(int a, int b, int c) {
    return maxOf(maxOf(a, b), c);
}

int main() {
    cout << maxOf(3, 4) << endl;          // the int version
    cout << maxOf(2.5, 1.0) << endl;      // the double version
    cout << maxOf(1, 9, 5) << endl;       // the three-argument version
    return 0;
}
```

**Output**
```
4
2.5
9
```

Several functions may share one name as long as their **parameter lists** differ in number or
type. The return type alone is not enough: `int f(int);` and `double f(int);` is an error.

## A.6 Decomposition: One Function, One Job
```cpp
#include <iostream>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int countPrimes(int from, int to) {
    int count = 0;
    for (int n = from; n <= to; n++) {
        if (isPrime(n)) count++;
    }
    return count;
}

int main() {
    cout << countPrimes(1, 20) << endl;
    return 0;
}
```

**Output**
```
8
```

`isPrime` answers one question, `countPrimes` reuses it, and `main` reads like a sentence. The
primes in 1..20 are 2, 3, 5, 7, 11, 13, 17, 19.
