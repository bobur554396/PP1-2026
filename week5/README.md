# Lecture 4: Arrays

## 1. What is an Array?
An array is a **fixed-size, ordered collection of elements of the same type**, stored next to each other in memory. Each element is reached by its position number, called the **index**.

Imagine you must store the marks of 5 students. With ordinary variables you would write:

```cpp
int m0, m1, m2, m3, m4;
```

That is already painful. Now imagine 200 students. An array gives us **one name** that holds many values of the same type:

```cpp
int m[200];
```

## 2. Types of Arrays
- **One-Dimensional Array (1D)**: A single row of elements (e.g., `int arr[5];`).
- **Multi-Dimensional Array**: Arrays of arrays (e.g., `int matrix[3][3];` for a 3x3 matrix) - Lecture 5.
- **Array of Characters (Strings)**: Array of `char` elements, terminated by `'\0'`.
- **Dynamic Arrays**: Size decided at runtime (e.g., `std::vector`) - later in the course.

## 3. Array Declaration
- **Syntax** (C++):
  ```cpp
  dataType arrayName[size];
  ```
- **Example**:
  ```cpp
  int arr[5];         // Array of 5 integers
  char str[10];       // Array of 10 characters
  double prices[100]; // Array of 100 doubles
  ```

### The size must be a compile-time constant
You may have seen code like this:

```cpp
int n;
cin >> n;
int arr[n];   // compiles on g++, but this is NOT standard C++
```

`g++` accepts it as an extension (a *variable-length array*), but the C++ standard does not,
and it will fail on other compilers and on some judges.

**In this course we do it the standard way**: declare the array **large enough for the worst
case** and use only the first `n` elements.

```cpp
const int MAXN = 1000;
int a[MAXN];      // we will use a[0] .. a[n-1]
```

Pick `MAXN` from the constraints of the problem (if the problem says `n <= 1000`, use `1000`).
Every example below follows this style.

### Initialization
```cpp
int b[5] = {1, 2, 3};   // -> {1, 2, 3, 0, 0}  (the rest become 0)
int c[]  = {4, 5, 6};   // size inferred -> size 3
int z[100] = {0};       // a quick way to set every element to 0
```

- If you provide **fewer** values than the size, the remaining elements become `0`.
- If you leave the size brackets empty, the compiler counts the values for you.

A freshly declared array such as `int a[5];` is **uninitialised** - its elements contain
*garbage*. Never read an element before you have given it a value.

## 4. Accessing an Element of an Array
- Indexing is **0-based**: the first element is `a[0]`, and for `n` elements the last one is `a[n-1]`.
- **Syntax**:
  ```cpp
  arrayName[index];
  ```
- **Example**:
  ```cpp
  int arr[3] = {10, 20, 30};
  cout << arr[1]; // Outputs 20
  arr[1] = 25;    // Updates index 1 to 25
  ```

> **You may only use indices from `0` to `n-1`.**

Reading or writing `a[5]` in a 5-element array, or `a[-1]`, is **out of bounds**. C++ does
**not** check this for you: the program may print rubbish, give a wrong answer on the judge,
or crash. Staying inside the bounds is *your* responsibility.

Because of that rule, every loop over an array uses `i < n`, never `i <= n`:

```cpp
for (int i = 0; i < n; i++) {
    // use a[i] here
}
```

## 5. Searching in an Array
- **Linear Search**: check each element one by one until the key is found.
  - Time Complexity: O(n)
  - Works on any array - sorted or not.
  - A good "not found" answer is `-1`, because it is not a valid index.

## 6. 1D Array Samples
Below are simple examples demonstrating common array operations in C++.

### 6.1 Read n numbers and Show Them
```cpp
#include <iostream>

using namespace std;

const int MAXN = 1000;
int arr[MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
```

### 6.2 Sum and Average of All Elements
```cpp
#include <iostream>

using namespace std;

const int MAXN = 1000;
int arr[MAXN];

int main() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    double average = (double)sum / n;   // cast, otherwise integer division
    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;
    return 0;
}
```

### 6.3 Show Even Numbers from Given Array
```cpp
#include <iostream>

using namespace std;

const int MAXN = 1000;
int arr[MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
    return 0;
}
```

### 6.4 Show Numbers in Odd Positions
```cpp
#include <iostream>

using namespace std;

const int MAXN = 1000;
int arr[MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i < n; i += 2) {   // indices 1, 3, 5, ...
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
```

### 6.5 Count Positive Numbers in Array
```cpp
#include <iostream>

using namespace std;

const int MAXN = 1000;
int arr[MAXN];

int main() {
    int n;
    cin >> n;
    int count = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > 0) {
            count++;
        }
    }
    cout << "Positive numbers: " << count << endl;
    return 0;
}
```

### 6.6 Find Max / Min from Given Array
```cpp
#include <iostream>

using namespace std;

const int MAXN = 1000;
int arr[MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int mx = arr[0], mn = arr[0];   // start from a real element, not from 0
    for (int i = 1; i < n; i++) {
        if (arr[i] > mx) mx = arr[i];
        if (arr[i] < mn) mn = arr[i];
    }
    cout << "Max: " << mx << ", Min: " << mn << endl;
    return 0;
}
```

### 6.7 Reverse the Order of Elements
```cpp
#include <iostream>

using namespace std;

const int MAXN = 1000;
int arr[MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
```

### 6.8 Linear Search of K in Given Array

#### Simple Version (return as soon as it is found)
```cpp
#include <iostream>

using namespace std;

const int MAXN = 1000;
int arr[MAXN];

int main() {
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> k;
    for (int i = 0; i < n; i++) {
        if (arr[i] == k) {
            cout << "Found at index: " << i << endl;
            return 0;
        }
    }
    cout << "not found" << endl;
    return 0;
}
```

#### With bool (the usual "flag" pattern)
```cpp
#include <iostream>

using namespace std;

const int MAXN = 1000;
int arr[MAXN];

int main() {
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> k;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == k) {
            cout << "Found at index: " << i << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "not found" << endl;
    }
    return 0;
}
```

### 6.9 Show All Elements Except K
```cpp
#include <iostream>

using namespace std;

const int MAXN = 1000;
int arr[MAXN];

int main() {
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> k;
    for (int i = 0; i < n; i++) {
        if (arr[i] == k) {
            continue;   // skip this one
        }
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
```

### 6.10 Find K, Remove It, Shift Left, Add 0 at the End
Here we really change the array, not just the printing.

```cpp
#include <iostream>

using namespace std;

const int MAXN = 1000;
int arr[MAXN];

int main() {
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> k;

    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == k) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        cout << "not found" << endl;
        return 0;
    }

    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];   // shift every next element one step left
    }
    arr[n - 1] = 0;            // the freed last cell becomes 0

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
```

## 7. String as an Array of Characters
A string in C++ can be a C-style array of characters (`char[]`) terminated by `'\0'`,
or a `std::string` object. Both are indexed like an array, from `0` to `length - 1`.

```cpp
char s[6] = "hello";   // needs 6 cells: 'h','e','l','l','o','\0'
cout << s[0];          // h
```

### 7.1 String Size / Length
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    cout << "Size: " << s.size() << endl;     // number of characters
    cout << "Length: " << s.length() << endl; // exactly the same thing
    return 0;
}
```

### 7.2 Show All Digits from String
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int len = s.size();
    for (int i = 0; i < len; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            cout << s[i] << " ";
        }
    }
    cout << endl;
    return 0;
}
```

### 7.3 Convert All Letters to Uppercase
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int len = s.size();
    for (int i = 0; i < len; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            cout << char(s[i] - 32);   // 'a' - 'A' == 32 in the ASCII table
        } else {
            cout << s[i];
        }
    }
    cout << endl;
    return 0;
}
```

### 7.4 Count Vowels in a Word
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int len = s.size();
    int count = 0;
    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
```

## 8. freopen - Testing with Files
Typing the same test data by hand every time you run the program is slow. `freopen`
redirects `cin` to read from a file and `cout` to write to a file, so you can prepare the
test once and run it as many times as you like.

```cpp
#include <iostream>

using namespace std;

const int MAXN = 1000;
int arr[MAXN];

int main() {
    freopen("input.txt", "r", stdin);    // cin now reads from input.txt
    freopen("output.txt", "w", stdout);  // cout now writes to output.txt

    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    cout << sum << endl;
    return 0;
}
```

`input.txt` (put it in the same folder as the program):
```
5
1 2 3 4 5
```

`output.txt` after running:
```
15
```

Notes:

- `"r"` means *read*, `"w"` means *write* (an existing `output.txt` is overwritten).
- `freopen` comes from `<cstdio>`; `<iostream>` usually pulls it in, but adding
  `#include <cstdio>` is safer.
- **Remove both `freopen` lines before submitting to ejudge.** The judge feeds the test
  through standard input and reads standard output; a program that opens `input.txt`
  will fail there.
