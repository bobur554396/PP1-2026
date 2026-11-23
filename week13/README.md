# Lecture 10: Struct and Pointers

## 1. What is a Pointer?

A **pointer** is a variable that stores the **memory address** of another variable.

Every variable lives somewhere in memory, and that location has a number, its address. `&x`
gives you the address of `x`, and a pointer is a variable able to hold such an address. The
`*p` notation goes the other way: it reaches the variable the pointer points at.

### 1.1 Declaring Pointers
```cpp
#include <iostream>

using namespace std;

int main() {
    int x = 10;
    int* ptr = &x;        // ptr holds the address of x

    cout << "Value of x: " << x << endl;
    cout << "Value pointed by ptr: " << *ptr << endl;

    *ptr = 50;            // change x through the pointer
    cout << "New x: " << x << endl;

    cout << "Same address: " << (ptr == &x) << endl;
    return 0;
}
```

**Output**
```
Value of x: 10
Value pointed by ptr: 10
New x: 50
Same address: 1
```

Read the declaration from right to left: `int* ptr` is "ptr is a pointer to int". A pointer has
a type, so an `int*` cannot point at a `double`.

Printing `ptr` or `&x` shows the address itself, something like `0x7ffd3c8a4b2c`. The number
changes on every run, so never write a program whose output is an address.

Two symbols, two jobs, and they are easy to mix up:

- `&x` in a declaration-free expression means **"address of x"**.
- `*ptr` means **"the variable at that address"**. This is called **dereferencing**.
- The `*` in `int* ptr` is part of the type, not a dereference.

### 1.2 The Name of an Array Is an Address
```cpp
#include <iostream>

using namespace std;

int main() {
    int a[4] = {10, 20, 30, 40};

    cout << (a == &a[0]) << endl;     // 1: the array name is the address of element 0
    cout << *a << endl;               // 10, the same as a[0]
    cout << *(a + 2) << endl;         // 30, the same as a[2]
    cout << a[2] << endl;             // 30

    return 0;
}
```

**Output**
```
1
10
30
30
```

This is the key fact behind everything below: `a[i]` is only a convenient spelling of
`*(a + i)`. Adding 1 to a pointer moves it on by **one element**, not by one byte, so
`a + 2` is the address of `a[2]` whatever the element type.

### 1.3 Array as a Function Argument
```cpp
#include <iostream>

using namespace std;

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";        // same as *(arr + i)
    }
    cout << endl;
}

int main() {
    int a[4] = {1, 2, 3, 4};
    printArray(a, 4);                 // the array is passed as an address
    return 0;
}
```

**Output**
```
1 2 3 4
```

`void printArray(int* arr, int n)` and `void printArray(int arr[], int n)` from Lecture 7 mean
exactly the same thing to the compiler. Now you know why an array parameter carries no size:
only an address is passed, and an address says nothing about how many elements follow. That is
also why the function can change the caller's array.

### 1.4 Fill an Array Using a Pointer
```cpp
#include <iostream>

using namespace std;

int main() {
    const int N = 5;
    int arr[N];
    int* p = arr;              // same as &arr[0]

    for (int i = 0; i < N; i++) {
        *(p + i) = i * 10;
    }

    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
```

**Output**
```
0 10 20 30 40
```

We wrote through `p` and read through `arr`: both names refer to the same memory.

### 1.5 Looping Through an Array Using Pointers
```cpp
#include <iostream>

using namespace std;

int main() {
    int arr[4] = {10, 20, 30, 40};

    // 1. pointer arithmetic with an index
    int* p = arr;
    for (int i = 0; i < 4; i++) {
        cout << *(p + i) << " ";
    }
    cout << endl;

    // 2. moving the pointer itself
    p = arr;                       // put it back to the start
    while (p < arr + 4) {
        cout << *p << " ";
        p++;                       // advance by one element
    }
    cout << endl;

    // 3. the same with a for loop
    for (int* q = arr; q != arr + 4; q++) {
        cout << *q << " ";
    }
    cout << endl;
    return 0;
}
```

**Output**
```
10 20 30 40
10 20 30 40
10 20 30 40
```

`arr + 4` is one past the last element, the same idea as `v.end()` in Lecture 8: a valid stop
marker that must never be dereferenced. After the second loop `p` sits at that marker, which is
why it has to be reset before being reused. Forgetting that reset is the usual bug here.

---

## 2. What is `struct`?

A **struct** is a user-defined data type that groups related variables, called **members**,
under one name. Instead of three parallel arrays for names, ids and grades, you get one array
of students.

### 2.1 Basic Student Example
```cpp
#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    string id;
    double gpa;
};                       // note the semicolon after the closing brace

int main() {
    Student s;
    s.name = "Bob";
    s.id = "25B001";
    s.gpa = 3.8;

    cout << s.name << " " << s.id << " " << s.gpa << endl;
    return 0;
}
```

**Output**
```
Bob 25B001 3.8
```

Members are reached with the dot: `s.name`. The semicolon after `};` is required, and leaving
it out produces a confusing error on the *next* line.

### 2.2 Read Student Data
```cpp
#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    string id;
    double gpa;
};

int main() {
    Student s;
    cin >> s.name >> s.id >> s.gpa;

    cout << s.name << " " << s.gpa << endl;
    return 0;
}
```

**Input**
```
Alice 25B002 3.95
```
**Output**
```
Alice 3.95
```

`cin` has no idea what a `Student` is, so each member is read separately. `cin >> s;` does not
compile.

### 2.3 freopen: Read from a File
```cpp
#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    string id;
    double gpa;
};

int main() {
    freopen("input.txt", "r", stdin);

    Student s;
    cin >> s.name >> s.id >> s.gpa;

    cout << "Student: " << s.name << ", GPA: " << s.gpa << endl;
    return 0;
}
```

`input.txt`:
```
Alice 25B002 3.95
```

Same `freopen` trick as Lecture 4, and the same warning: remove both lines before submitting
to ejudge.

### 2.4 Member Functions
A struct can hold functions as well as data. Inside such a function the members are used by
name, with no dot, because they belong to the object the function was called on.

```cpp
#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    string id;
    double gpa;

    void print() {                  // member function
        cout << name << " (ID: " << id << ") GPA: " << gpa << endl;
    }

    bool isExcellent() {
        return gpa >= 3.67;
    }
};

int main() {
    Student s = {"Bob", "25B001", 3.9};    // members in declaration order

    s.print();
    cout << (s.isExcellent() ? "excellent" : "not excellent") << endl;
    return 0;
}
```

**Output**
```
Bob (ID: 25B001) GPA: 3.9
excellent
```

The brace list `{"Bob", "25B001", 3.9}` fills the members **in the order they are declared**,
so the types must line up. Swapping two members in the struct silently changes what this line
means, which is a good reason to prefer a constructor.

### 2.5 Constructors
A **constructor** is a member function with the struct's own name and no return type. It runs
when an object is created, so an object can never be left half-initialised.

```cpp
#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    string id;
    double gpa;

    Student() {                     // default constructor: no arguments
        name = "unknown";
        id = "none";
        gpa = 0.0;
    }

    Student(string n, string i, double g) {   // constructor with arguments
        name = n;
        id = i;
        gpa = g;
    }

    void print() {
        cout << name << " (" << id << ") " << gpa << endl;
    }
};

int main() {
    Student a;                                  // uses the default constructor
    Student b("Alice", "25B002", 3.95);         // uses the three-argument one

    a.print();
    b.print();
    return 0;
}
```

**Output**
```
unknown (none) 0
Alice (25B002) 3.95
```

Two constructors with different parameter lists are just function overloading, exactly as in
Lecture 7. Note the catch: as soon as you write any constructor, the brace list of 2.4 stops
working unless a matching constructor exists, so `Student s = {"Bob", "25B001", 3.9};` now
compiles only because the three-argument constructor accepts those types.

Without a constructor, a local `Student s;` has `gpa` filled with garbage, the same as an
uninitialised `int`. Only `string` members start out empty, because `string` initialises
itself.

### 2.6 Array of Structs
```cpp
#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    string id;
    double gpa;

    void print() {
        cout << name << " (" << id << ") " << gpa << endl;
    }
};

const int MAXN = 100;
Student students[MAXN];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> students[i].name >> students[i].id >> students[i].gpa;
    }

    for (int i = 0; i < n; i++) {
        students[i].print();
    }
    return 0;
}
```

**Input**
```
3
Alice 25B001 3.8
Bob 25B002 4.0
Charlie 25B003 3.5
```
**Output**
```
Alice (25B001) 3.8
Bob (25B002) 4
Charlie (25B003) 3.5
```

One array of structs instead of three parallel arrays: the data of one student can no longer
drift out of step with the rest. Note the `4` in the output: `cout` drops a trailing `.0`.

### 2.7 Sort Students by GPA
```cpp
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    string id;
    double gpa;

    void print() {
        cout << name << " (" << id << ") " << gpa << endl;
    }
};

bool byGpaDesc(const Student &a, const Student &b) {
    if (a.gpa != b.gpa) {
        return a.gpa > b.gpa;        // higher GPA first
    }
    return a.name < b.name;          // equal GPA: alphabetical
}

int main() {
    Student arr[3] = {
        {"Alice", "25B001", 3.8},
        {"Bob", "25B002", 4.0},
        {"Charlie", "25B003", 3.8}
    };

    sort(arr, arr + 3, byGpaDesc);

    for (int i = 0; i < 3; i++) {
        arr[i].print();
    }
    return 0;
}
```

**Output**
```
Bob (25B002) 4
Alice (25B001) 3.8
Charlie (25B003) 3.8
```

The **comparator** is the same idea as in Lecture 8, now over a struct: it answers "must `a`
come before `b`?". The parameters are `const Student &` so that nothing is copied and nothing
can be changed. As always, it must return `false` for equal items, which is why the tie is
broken on the name rather than by writing `>=`.

### 2.8 Find a Student by Name
```cpp
#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    string id;
    double gpa;
};

int main() {
    Student students[3] = {
        {"Alice", "25B001", 3.8},
        {"Bob", "25B002", 4.0},
        {"Charlie", "25B003", 3.5}
    };

    string target;
    cin >> target;

    int found = -1;
    for (int i = 0; i < 3; i++) {
        if (students[i].name == target) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        cout << "not found" << endl;
    } else {
        cout << students[found].name << " " << students[found].gpa << endl;
    }
    return 0;
}
```

**Input**
```
Bob
```
**Output**
```
Bob 4
```

Linear search from Lecture 4, with `students[i].name` in place of `a[i]`. Remembering the index
in `found` keeps the search and the printing apart.

### 2.9 All Students Above a Threshold
```cpp
#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    double gpa;
};

int main() {
    Student students[4] = {
        {"Alice", 3.8},
        {"Bob", 4.0},
        {"Charlie", 3.5},
        {"Dana", 3.7}
    };

    double threshold;
    cin >> threshold;

    int count = 0;
    for (int i = 0; i < 4; i++) {
        if (students[i].gpa >= threshold) {
            cout << students[i].name << " " << students[i].gpa << endl;
            count++;
        }
    }

    if (count == 0) {
        cout << "nobody" << endl;
    }
    return 0;
}
```

**Input**
```
3.7
```
**Output**
```
Alice 3.8
Bob 4
Dana 3.7
```

### 2.10 Point Example (2D Point)
```cpp
#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    int x, y;                    // two members of the same type on one line

    void print() {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    double distanceFromOrigin() {
        return sqrt(x * x + y * y);
    }
};

double distance(Point a, Point b) {            // a free function, not a member
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    Point p = {3, 4};
    Point q = {0, 0};

    p.print();
    cout << p.distanceFromOrigin() << endl;
    cout << distance(p, q) << endl;
    return 0;
}
```

**Output**
```
(3, 4)
5
5
```

`sqrt` needs `#include <cmath>`. A struct can be passed to and returned from an ordinary
function like any other type, and unlike an array it **is** copied when passed by value.

### 2.11 Pointer to a Struct and the `->` Operator
```cpp
#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    double gpa;
};

void raise(Student *s, double bonus) {     // changes the caller's student
    s->gpa += bonus;
}

int main() {
    Student a = {"Alice", 3.5};
    Student *p = &a;

    cout << p->name << " " << p->gpa << endl;      // -> through a pointer
    cout << (*p).name << " " << (*p).gpa << endl;  // exactly the same thing

    raise(&a, 0.3);
    cout << a.gpa << endl;                         // the original changed
    return 0;
}
```

**Output**
```
Alice 3.5
Alice 3.5
3.8
```

`p->member` is shorthand for `(*p).member`. The parentheses in the long form are not optional:
`*p.name` would be read as `*(p.name)` and does not compile. Taking a pointer (or a reference,
as in Lecture 7) is how a function changes the caller's struct instead of a copy.

### 2.12 Struct in a Header File
A large program is split across files: declarations go in a **header** (`.h`), the code that
implements them in a **source** file (`.cpp`), and each `.cpp` includes the headers it needs.

**student.h**
```cpp
#ifndef STUDENT_H          // include guard: keeps this file from being pasted twice
#define STUDENT_H

#include <string>

struct Student {
    std::string name;
    std::string id;
    double gpa;

    void print();          // declared here, defined in student.cpp
    bool isExcellent();
};

#endif
```

**student.cpp**
```cpp
#include <iostream>
#include "student.h"

using namespace std;

void Student::print() {            // Student:: says which struct this belongs to
    cout << name << " (" << id << ") " << gpa << endl;
}

bool Student::isExcellent() {
    return gpa >= 3.67;
}
```

**main.cpp**
```cpp
#include <iostream>
#include "student.h"

using namespace std;

int main() {
    Student s = {"Alice", "25B001", 3.9};

    s.print();
    cout << s.isExcellent() << endl;
    return 0;
}
```

Compile **both** source files together, from the terminal:

```bash
g++ main.cpp student.cpp -o main
./main
```

**Output**
```
Alice (25B001) 3.9
1
```

Three rules for headers:

- `#include "student.h"` with quotes for your own files, `<iostream>` with angle brackets for
  library ones.
- Always use an include guard (`#ifndef` / `#define` / `#endif`), or the struct gets defined
  twice as soon as two files include the header.
- Do not put `using namespace std;` in a header: every file that includes it would be forced
  into that choice. Write `std::string` in the header, and keep `using namespace std;` in the
  `.cpp` files.

Compiling only `g++ main.cpp` fails with an "undefined reference to `Student::print()`" error,
because the body of `print` lives in the other file. Both files must be on the command line.

---

## 3. Summary Table

| Concept             | Syntax Example                  | Purpose |
|---------------------|----------------------------------|-------|
| Pointer declaration | `int* p = &x;`                  | store an address |
| Address of          | `&x`                            | get a variable's address |
| Dereference         | `*p = 10;`                      | reach the value at an address |
| Pointer arithmetic  | `*(p + i)`, `p++`               | move along an array |
| Array to pointer    | `printArray(a, n)`              | pass an array to a function |
| Struct              | `struct Student { ... };`       | group related data |
| Member access       | `s.name`, `s.print()`           | use a field or member function |
| Constructor         | `Student(string n, double g)`   | initialise on creation |
| Pointer to struct   | `Student* p = &s; p->name`      | reach members through a pointer |
| Comparator          | `sort(a, a + n, byGpaDesc)`     | sort structs by a chosen field |
| Header separation   | `.h` + `.cpp`, include guard    | split a larger program |

---

## 4. Best Practices
- Always initialise pointers; a pointer that points nowhere should be `nullptr`.
- Never dereference a pointer one past the end of an array (`arr + n`).
- Reset a pointer before reusing it after a loop that moved it.
- Prefer one array of structs over several parallel arrays.
- Pass a struct by `const` reference when the function only reads it, by pointer or reference
  when it must change it.
- Give a struct a constructor instead of relying on brace lists in member order.
- Use an include guard in every header, and keep `using namespace std;` out of headers.

---

# Appendix A. Additional Material

Not covered in the lecture. Lab 10 and the course manual use these.

## A.1 `nullptr`: a Pointer That Points Nowhere
```cpp
#include <iostream>

using namespace std;

int* findFirstEven(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            return &a[i];            // address of the element we found
        }
    }
    return nullptr;                  // nothing found
}

int main() {
    int a[5] = {1, 3, 4, 7, 9};

    int *p = findFirstEven(a, 5);
    if (p != nullptr) {
        cout << "found " << *p << endl;
    } else {
        cout << "no even number" << endl;
    }

    int b[2] = {1, 3};
    int *q = findFirstEven(b, 2);
    cout << (q == nullptr ? "no even number" : "found") << endl;
    return 0;
}
```

**Output**
```
found 4
no even number
```

`nullptr` is the standard way to say "this pointer points at nothing", and it is the only value
a pointer can be compared against safely before use. Dereferencing it crashes the program, so
check first, exactly as with `find` and `end()` in Lecture 8. Older code writes `NULL` or `0`
for the same thing; `nullptr` needs C++11.

## A.2 `vector<Student>` Instead of a Fixed Array
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    double gpa;

    Student(string n, double g) {
        name = n;
        gpa = g;
    }
};

bool byGpaDesc(const Student &a, const Student &b) {
    if (a.gpa != b.gpa) return a.gpa > b.gpa;
    return a.name < b.name;
}

int main() {
    int n;
    cin >> n;

    vector<Student> v;
    for (int i = 0; i < n; i++) {
        string name;
        double gpa;
        cin >> name >> gpa;
        v.push_back(Student(name, gpa));
    }

    sort(v.begin(), v.end(), byGpaDesc);

    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i].name << " " << v[i].gpa << endl;
    }
    return 0;
}
```

**Input**
```
3
Charlie 3.5
Alice 4.0
Bob 4.0
```
**Output**
```
Alice 4
Bob 4
Charlie 3.5
```

A `vector` of structs needs no guessed maximum size, and the comparator works the same.

## A.3 Passing a Struct by Value, by Reference and by `const` Reference
```cpp
#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    double gpa;
};

void byValue(Student s) {               // gets a copy
    s.gpa = 0.0;
}

void byReference(Student &s) {          // works on the caller's object
    s.gpa = 0.0;
}

void readOnly(const Student &s) {       // no copy, cannot change it
    cout << s.name << " " << s.gpa << endl;
    // s.gpa = 0.0;                     // would not compile
}

int main() {
    Student a = {"Alice", 3.9};

    byValue(a);
    cout << a.gpa << endl;              // 3.9, unchanged

    readOnly(a);

    byReference(a);
    cout << a.gpa << endl;              // 0
    return 0;
}
```

**Output**
```
3.9
Alice 3.9
0
```

A struct is copied when passed by value, so a big struct costs real time. `const Student &` is
the usual choice for a function that only reads: no copy, and the compiler stops you from
changing the caller's data by mistake. Note how this differs from an array, which is never
copied because only its address is passed.
