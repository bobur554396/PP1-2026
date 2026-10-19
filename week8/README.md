# Lecture 6: Strings in C++

## 1. What is a String?
A string is a sequence of characters used to represent text. In C++, the `std::string` class
(from the `<string>` header) provides a dynamic, convenient way to work with text data.

- **Key Characteristics**:
  - Dynamic size (grows and shrinks automatically, unlike the `char` arrays of Lecture 4).
  - Provides many built-in functions for manipulation.
  - Indexed starting from 0, like arrays.
  - Part of the C++ Standard Library.

## 2. String Operations Overview
- **Initialization**: Create strings using constructors or direct assignment.
- **Access**: Use indices or iterators to access characters.
- **Modification**: Use functions like `append`, `insert`, `erase`, and operators like `+=`.
- **Search**: Use `find` and `substr` to locate and extract substrings.
- **Conversion**: Convert between strings and other data types using `stoi`, `to_string`,
  `stringstream`.

Two conventions used in all examples below:

- No input prompts. The judge compares your output character by character, so a program that
  prints `Enter a string: ` fails even when its answer is right. Read with `cin` or `getline`
  and print only the result.
- The position type is `size_t`, not `int`. `find` returns `size_t`, and `string::npos` is a
  `size_t` too, so `int pos = s.find(...)` mixes signed and unsigned types and makes the
  compiler warn.

## 3. String Examples

### 3.1 What is a String
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "Hello, World!";
    cout << "String: " << s << endl;
    return 0;
}
```

### 3.2 Initialize String (With Constructor)
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1;                          // Empty string
    string s2 = "Hello";                // Direct initialization
    string s3("World");                 // Constructor
    string s4(5, 'A');                  // 5 copies of 'A': "AAAAA"
    string s5(s2);                      // Copy constructor

    cout << "s1: '" << s1 << "'" << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;
    cout << "s4: " << s4 << endl;
    cout << "s5: " << s5 << endl;
    return 0;
}
```

**Output**
```
s1: ''
s2: Hello
s3: World
s4: AAAAA
s5: Hello
```

### 3.3 Size & Length
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "Hello";
    cout << "String: " << s << endl;
    cout << "Size: " << s.size() << endl;       // Returns length
    cout << "Length: " << s.length() << endl;   // Same as size()
    cout << "Empty: " << (s.empty() ? "Yes" : "No") << endl;
    return 0;
}
```

`size()` and `length()` are the same function under two names. Use either one.

### 3.4 Copy String From One to Another
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1 = "Original";
    string s2;

    s2 = s1;  // Copy assignment: s2 gets its own copy of the text

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    s1 = "Modified";
    cout << "After modifying s1:" << endl;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;  // s2 remains unchanged
    return 0;
}
```

Assigning one string to another **copies** the text. Changing `s1` afterwards does not touch
`s2`. This is different from arrays, which cannot be copied with `=` at all.

### 3.5 Comparing Two Strings for Equality
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1 = "Hello";
    string s2 = "Hello";
    string s3 = "World";

    if (s1 == s2) {
        cout << "s1 and s2 are equal" << endl;
    }

    if (s1 != s3) {
        cout << "s1 and s3 are not equal" << endl;
    }

    // Lexicographical comparison (dictionary order, by ASCII codes)
    if (s1 < s3) {
        cout << "s1 comes before s3 lexicographically" << endl;
    }

    return 0;
}
```

`==` compares the **text**, not addresses. `<` compares character by character using ASCII
codes, so every uppercase letter comes before every lowercase one: `"Zoo" < "apple"` is true.

### 3.6 Concatenate Strings/Chars (+, +=)
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1 = "Hello";
    string s2 = " World";

    string s3 = s1 + s2;  // Concatenation with +
    cout << "s3: " << s3 << endl;

    s1 += s2;             // Concatenation with +=
    cout << "s1: " << s1 << endl;

    s1 += '!';            // Append a single character
    cout << "s1: " << s1 << endl;

    return 0;
}
```

One rule to remember: at least one side of `+` must be a `string`. `"Hello" + " World"` does
not compile, because both sides are C-style literals. Write `string("Hello") + " World"`.

### 3.7 Accessing Each Element by Loop
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "Hello";

    // Using index
    int n = s.size();                 // int copy, so i < n needs no cast
    cout << "Using index: ";
    for (int i = 0; i < n; i++) {
        cout << s[i] << " ";
    }
    cout << endl;

    // Using range-based for loop (C++11)
    cout << "Using range-based loop: ";
    for (char c : s) {
        cout << c << " ";
    }
    cout << endl;

    // Modify characters
    s[0] = 'h';
    cout << "Modified: " << s << endl;

    return 0;
}
```

Writing `for (int i = 0; i < s.size(); i++)` compiles but warns: `s.size()` is unsigned and
`i` is signed. Copying the size into an `int` first keeps the comparison clean.

### 3.8 Convert Char to Number (ASCII)
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    char c = 'A';
    int ascii = (int)c;

    cout << "Character: " << c << endl;
    cout << "ASCII code: " << ascii << endl;

    // Convert back
    char c2 = (char)(ascii + 1);
    cout << "Next character: " << c2 << endl;

    // Digit to number
    char digit = '5';
    int num = digit - '0';  // Convert '5' to 5
    cout << "Digit '" << digit << "' as number: " << num << endl;

    return 0;
}
```

**Output**
```
Character: A
ASCII code: 65
Next character: B
Digit '5' as number: 5
```

`digit - '0'` works because the digits `'0'` to `'9'` sit next to each other in the ASCII
table. The same trick gives a letter's position in the alphabet: `c - 'a'`.

### 3.9 s.front(), s.back()
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "Hello";

    cout << "String: " << s << endl;
    cout << "First character (front): " << s.front() << endl;
    cout << "Last character (back): " << s.back() << endl;

    s.front() = 'h';  // Modify first character
    s.back() = '!';   // Modify last character

    cout << "Modified: " << s << endl;

    return 0;
}
```

`s.front()` is `s[0]` and `s.back()` is `s[s.size() - 1]`. Both are **undefined** on an empty
string, so check `s.empty()` first when the string comes from input.

### 3.10 s.begin(), s.end()
```cpp
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string s = "Hello";

    // Using iterators
    cout << "Using iterators: ";
    for (string::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // Modify using iterators
    for (string::iterator it = s.begin(); it != s.end(); it++) {
        *it = (char)toupper(*it);
    }
    cout << "Uppercase: " << s << endl;

    return 0;
}
```

An **iterator** is a position in the string. `s.begin()` points at the first character,
`s.end()` points **past** the last one, so the loop condition is `it != s.end()`. The `*it`
notation reads the character at that position. `toupper` and `tolower` come from `<cctype>`
and return an `int`, hence the `(char)` cast.

### 3.11 Find Function (size_t and string::npos)
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "Hello World";

    // Find a character
    size_t pos = s.find('o');
    if (pos != string::npos) {
        cout << "'o' found at position: " << pos << endl;
    } else {
        cout << "'o' not found" << endl;
    }

    // Find a substring
    pos = s.find("World");
    if (pos != string::npos) {
        cout << "'World' found at position: " << pos << endl;
    }

    // find returns string::npos when there is no match
    pos = s.find('z');
    cout << "Finding 'z': " << (pos == string::npos ? "Not found" : "Found") << endl;

    return 0;
}
```

**Output**
```
'o' found at position: 4
'World' found at position: 6
Finding 'z': Not found
```

`find` returns the index of the **first** match, or `string::npos` when there is none.
`string::npos` is a huge unsigned value, so always compare against it instead of testing for
`-1`, and never store the result in an `int`.

### 3.12 Check if Second String is Found in First
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1;
    cin >> s2;

    if (s1.find(s2) != string::npos) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
```

**Input**
```
abcdef
cde
```
**Output**
```
YES
```

### 3.13 Count How Many Times a Substring Occurs
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "abababa";
    string pattern = "aba";

    int count = 0;
    size_t pos = 0;

    while ((pos = s.find(pattern, pos)) != string::npos) {
        count++;
        pos++;  // Move one character forward, so overlaps are counted
    }

    cout << "'" << pattern << "' occurs " << count << " times in '" << s << "'" << endl;

    return 0;
}
```

**Output**
```
'aba' occurs 3 times in 'abababa'
```

`s.find(pattern, pos)` starts the search at index `pos`. Advancing by one counts **overlapping**
matches ("aba" at 0, 2 and 4). Advancing by `pattern.size()` instead would count only
non-overlapping ones, giving 2. Decide which one the task wants.

### 3.14 getline(cin, s) - Read a Whole Line
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);  // Reads the entire line, spaces included

    cout << s << endl;
    cout << "Length: " << s.length() << endl;

    return 0;
}
```

`cin >> s` stops at the first space, so it reads one word. `getline(cin, s)` reads to the end
of the line.

Careful when mixing them: after `cin >> n`, the newline you pressed is still waiting in the
input, so the next `getline` returns an empty string. Clear it first:

```cpp
int n;
cin >> n;
cin.ignore();        // discard the leftover newline
string line;
getline(cin, line);
```

### 3.15 substr(index, cnt)
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "Hello World";

    string sub1 = s.substr(0, 5);   // "Hello"
    string sub2 = s.substr(6, 5);   // "World"
    string sub3 = s.substr(6);      // "World" (from index 6 to the end)

    cout << "Original: " << s << endl;
    cout << "substr(0, 5): " << sub1 << endl;
    cout << "substr(6, 5): " << sub2 << endl;
    cout << "substr(6): " << sub3 << endl;

    return 0;
}
```

The second argument is a **count**, not an end index. `substr` returns a new string and leaves
the original untouched. A starting index greater than `size()` throws `out_of_range`, but a
count that runs past the end is fine: you simply get the rest of the string.

### 3.16 erase(start_index, count)
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "Hello World";

    cout << "Original: " << s << endl;

    s.erase(5, 6);  // Erase " World"
    cout << "After erase(5, 6): " << s << endl;

    s = "Hello World";
    s.erase(5);     // Erase from index 5 to the end
    cout << "After erase(5): " << s << endl;

    return 0;
}
```

Unlike `substr`, `erase` changes the string itself.

### 3.17 append, insert Functions
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "Hello";

    // append
    s.append(" World");
    cout << "After append: " << s << endl;

    // insert
    s.insert(5, ",");  // Insert at position 5
    cout << "After insert: " << s << endl;

    s.insert(0, "Say: ");
    cout << "After insert at beginning: " << s << endl;

    return 0;
}
```

**Output**
```
After append: Hello World
After insert: Hello, World
After insert at beginning: Say: Hello, World
```

`s.append(t)` does the same job as `s += t`. `s.insert(i, t)` puts `t` **before** the character
currently at index `i`, so `insert(0, ...)` adds to the front.

### 3.18 Print All Doubled Chars in Sequence
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    for (int i = 0; i + 1 < n; i++) {
        if (s[i] == s[i + 1]) {
            cout << s[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
```

**Input**
```
aabbcdee
```
**Output**
```
a b e
```

The condition is `i + 1 < n` because the body looks at `s[i + 1]`. Writing
`i < s.size() - 1` looks equivalent but breaks on an empty string: `size()` is unsigned, so
`0 - 1` becomes a huge number and the loop reads far past the end.

### 3.19 Palindrome Check (Loop with Iterators)
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    bool isPalindrome = true;
    if (!s.empty()) {
        string::iterator left = s.begin();
        string::iterator right = s.end() - 1;

        while (left < right) {
            if (*left != *right) {
                isPalindrome = false;
                break;
            }
            left++;
            right--;
        }
    }

    cout << (isPalindrome ? "YES" : "NO") << endl;

    return 0;
}
```

`s.end()` is one past the last character, so the right iterator starts at `s.end() - 1`. The
`empty()` guard matters: on an empty string `s.end() - 1` is not a valid position.

### 3.20 Palindrome Check (With Bool Flag)
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    bool isPalindrome = true;
    int n = s.length();

    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) {
            isPalindrome = false;
            break;
        }
    }

    cout << (isPalindrome ? "YES" : "NO") << endl;

    return 0;
}
```

Only the first half is compared, `i < n / 2`, because each step checks a pair from both ends.
A middle character in an odd-length string needs no comparison: it is its own mirror.

### 3.21 Palindrome Check (With Contradiction/Return)
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();

    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) {
            cout << "NO" << endl;
            return 0;  // Exit immediately
        }
    }

    cout << "YES" << endl;

    return 0;
}
```

The same idea as 3.20 with no flag to maintain: one counterexample is enough to answer NO.

### 3.22 Palindrome Check (Left and Right Pointers)
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    int left = 0;
    int right = n - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            cout << "NO" << endl;
            return 0;
        }
        left++;
        right--;
    }

    cout << "YES" << endl;

    return 0;
}
```

The two-pointer pattern: walk inwards from both ends until they meet. The same idea as 3.19
with plain indices instead of iterators, which is usually easier to read.

### 3.23 Palindrome Check (Reverse String)
```cpp
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    string reversed = s;
    reverse(reversed.begin(), reversed.end());

    if (s == reversed) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
```

The shortest version, but it copies the whole string. `reverse` comes from `<algorithm>`, the
same function used on arrays in Lecture 5.

### 3.24 StringStream - Concatenating Multiple Data Types
```cpp
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string name = "Alice";
    int age = 25;
    double height = 1.75;

    stringstream ss;
    ss << "Name: " << name << ", Age: " << age << ", Height: " << height;

    string result = ss.str();
    cout << result << endl;

    return 0;
}
```

**Output**
```
Name: Alice, Age: 25, Height: 1.75
```

A `stringstream` behaves like `cout` and `cin`, except the text goes into a string instead of
the screen. `ss << x` writes, and `ss.str()` hands back everything written so far.

### 3.25 StringStream - Extracting Mixed Data Types
```cpp
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string data = "Alice 25 1.75";

    stringstream ss(data);

    string name;
    int age;
    double height;

    ss >> name >> age >> height;

    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Height: " << height << endl;

    return 0;
}
```

Constructing `stringstream ss(data)` fills the stream with that text, and `ss >> ...` then
reads from it exactly as `cin >> ...` reads from the keyboard.

### 3.26 StringStream - Counting Words in a String
```cpp
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    stringstream ss(s);
    string word;
    int count = 0;

    while (ss >> word) {
        count++;
    }

    cout << count << endl;

    return 0;
}
```

**Input**
```
one two   three
```
**Output**
```
3
```

`ss >> word` skips any amount of whitespace and stops being true when the stream runs out, so
repeated spaces do not inflate the count. This is the standard way to split a line into words.

### 3.27 StringStream - Parse String as Float and Int
```cpp
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string s = "123 45.67 89";

    stringstream ss(s);

    int num1;
    double num2;
    int num3;

    ss >> num1 >> num2 >> num3;

    cout << "Integer: " << num1 << endl;
    cout << "Double: " << num2 << endl;
    cout << "Integer: " << num3 << endl;

    return 0;
}
```

### 3.28 stoi - String to Integer
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1 = "123";
    string s2 = "45.67";
    string s3 = "100abc";

    int num1 = stoi(s1);
    cout << "stoi(\"123\"): " << num1 << endl;

    int num2 = stoi(s2);  // Reads up to the decimal point
    cout << "stoi(\"45.67\"): " << num2 << endl;

    int num3 = stoi(s3);  // Reads up to the first non-digit
    cout << "stoi(\"100abc\"): " << num3 << endl;

    // Also: stof (string to float), stod (string to double)
    double d = stod(s2);
    cout << "stod(\"45.67\"): " << d << endl;

    // And the other direction
    string back = to_string(num1 * 2);
    cout << "to_string(246): " << back << endl;

    return 0;
}
```

**Output**
```
stoi("123"): 123
stoi("45.67"): 45
stoi("100abc"): 100
stod("45.67"): 45.67
to_string(246): 246
```

`stoi` reads digits from the **front** and ignores the rest, but it **throws** when there are
no digits at all: `stoi("abc")` crashes the program with `invalid_argument`. `stoi`, `stod` and
`to_string` all need C++11, so compile with `g++ sol.cpp -std=c++11` if your MinGW defaults to
an older standard.

## 4. Summary of Key String Functions

| Function | Description | Example |
|----------|-------------|---------|
| `s.size()` / `s.length()` | Returns string length | `s.size()` |
| `s.empty()` | Checks if string is empty | `s.empty()` |
| `s[i]` | Access character at index i | `s[0]` |
| `s.at(i)` | Same, but throws if i is out of range | `s.at(0)` |
| `s.front()` | First character | `s.front()` |
| `s.back()` | Last character | `s.back()` |
| `s.begin()` / `s.end()` | Iterator to start / past the end | `for (auto it = s.begin(); ...)` |
| `s.find(t)` | Find substring, returns position or `string::npos` | `s.find("hello")` |
| `s.substr(pos, len)` | Extract substring (a copy) | `s.substr(0, 5)` |
| `s.erase(pos, len)` | Remove characters (changes s) | `s.erase(5, 3)` |
| `s.insert(pos, t)` | Insert string at position | `s.insert(5, "hi")` |
| `s.append(t)` | Append string, same as `s += t` | `s.append(" world")` |
| `s.push_back(c)` | Append one character | `s.push_back('!')` |
| `getline(cin, s)` | Read an entire line | `getline(cin, s)` |
| `stoi(s)` / `stod(s)` | Convert string to int / double | `stoi("123")` |
| `to_string(n)` | Convert number to string | `to_string(123)` |
| `reverse(s.begin(), s.end())` | Reverse in place (`<algorithm>`) | `reverse(s.begin(), s.end())` |

## 5. Best Practices
- Use `getline()` when reading text that contains spaces, and `cin.ignore()` after a `cin >> n`
  that comes before it.
- Always compare the result of `find()` against `string::npos`, and store it in a `size_t`.
- Copy `s.size()` into an `int` before using it in a loop condition, or compare unsigned to
  unsigned. Never write `s.size() - 1` on a string that may be empty.
- Check `s.empty()` before `front()`, `back()` or `s.end() - 1`.
- Prefer `+=` over `s = s + t` when building a string in a loop.
- Use `stringstream` for splitting a line into words and for mixed-type parsing.
- Print no prompts in judge solutions.

---

# Appendix A. Additional Examples

Not covered in the lecture, useful for the lab and for self-study.

## A.1 at() Instead of []
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "Hello";

    cout << s.at(0) << endl;      // same as s[0]

    // s[10] reads past the end silently; s.at(10) reports the error
    if (s.size() > 10) {
        cout << s.at(10) << endl;
    } else {
        cout << "index 10 is out of range" << endl;
    }

    return 0;
}
```

`s[i]` does not check the index, exactly like an array. `s.at(i)` checks it and throws
`out_of_range`, which turns a silent wrong answer into a visible crash while you debug.

## A.2 Building a String Character by Character
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    string digits;
    string letters;

    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            digits.push_back(s[i]);
        } else {
            letters.push_back(s[i]);
        }
    }

    cout << digits << endl;
    cout << letters << endl;

    return 0;
}
```

`push_back` adds one character to the end. A string starts empty and grows, so there is no
size to plan in advance.

## A.3 Character Helpers from `<cctype>`
```cpp
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    int letters = 0, digits = 0, spaces = 0, others = 0;

    int n = s.size();
    for (int i = 0; i < n; i++) {
        unsigned char c = s[i];
        if (isalpha(c)) letters++;
        else if (isdigit(c)) digits++;
        else if (isspace(c)) spaces++;
        else others++;
    }

    cout << "letters: " << letters << endl;
    cout << "digits: " << digits << endl;
    cout << "spaces: " << spaces << endl;
    cout << "others: " << others << endl;

    return 0;
}
```

**Input**
```
ab 12 !?
```
**Output**
```
letters: 2
digits: 2
spaces: 2
others: 2
```

`<cctype>` also gives `isalnum`, `ispunct`, `toupper` and `tolower`. Pass an `unsigned char`,
since a negative `char` value is undefined input for these functions.

## A.4 Uppercase and Lowercase a Whole String
```cpp
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    string upper = s;
    string lower = s;

    int n = s.size();
    for (int i = 0; i < n; i++) {
        upper[i] = (char)toupper((unsigned char)s[i]);
        lower[i] = (char)tolower((unsigned char)s[i]);
    }

    cout << upper << endl;
    cout << lower << endl;

    return 0;
}
```

## A.5 Splitting a Line Without stringstream
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    string word;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == ' ') {
            if (!word.empty()) {
                cout << word << endl;
                word.clear();
            }
        } else {
            word.push_back(s[i]);
        }
    }
    if (!word.empty()) {
        cout << word << endl;   // the last word has no space after it
    }

    return 0;
}
```

The last word needs the extra check after the loop, because nothing triggers the "print it"
branch at the end of the line. Forgetting that is the usual bug in hand-written splitting.

## A.6 C-Style Strings (char arrays)
```cpp
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char a[20] = "Hello";          // 5 letters + the '\0' terminator

    cout << a << endl;
    cout << "strlen: " << strlen(a) << endl;   // 5, the '\0' is not counted

    strcat(a, " World");           // append (room must already exist)
    cout << a << endl;

    char b[20];
    strcpy(b, a);                  // copy: b = a does NOT work for arrays
    cout << "copy: " << b << endl;

    cout << "equal: " << (strcmp(a, b) == 0 ? "yes" : "no") << endl;

    return 0;
}
```

A C-style string is the `char` array of Lecture 4, ending with the character `'\0'`. It has a
fixed size, cannot be copied with `=` or compared with `==`, and needs the `<cstring>`
functions instead. You will meet it in older code and in C. In this course prefer
`std::string`, which handles size, copying and comparison for you.
