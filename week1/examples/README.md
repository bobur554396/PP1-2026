# Lecture Examples

## hello.cpp
Basic "Hello, World!" program - prints greeting message

**Hint:** Use `cout` to output text, `endl` for new line
```cpp
#include <iostream>

using namespace std;

int main() {

    cout << "Hello, World!" << endl;

    return 0;
}
```

---

## main_structure.cpp
Basic C++ program structure template

**Hint:** Every C++ program needs `#include <iostream>`, `using namespace std;`, and `int main()` function
```cpp
#include <iostream>

using namespace std;

int main() {
    
    

    return 0;
}
```

---

## 1.cpp
Variable declaration and assignment

**Hint:** Declare variable first, then assign value separately using `=` operator
```cpp
#include <iostream>

using namespace std;

int main() {

    int number;

    number = 5;

    cout << number << endl;

    return 0;
}
```

---

## 2.cpp
Multiple variable declaration and arithmetic operation

**Hint:** Declare each variable separately, assign values, then perform arithmetic operations
```cpp
#include <iostream>

using namespace std;

int main() {

    int number1;
    number1 = 5;
    
    int number2;
    number2 = 10;

    int result = number1 + number2;

    cout << result << endl;

    return 0;
}
```

---

## 3.cpp
Variable initialization at declaration

**Hint:** Combine declaration and assignment in one line: `int variable = value;`
```cpp
#include <iostream>

using namespace std;

int main() {

    int number1 = 5;
    int number2 = 10;

    int result = number1 + number2;

    cout << result << endl;

    return 0;
}
```

---

## 4.cpp
Different data types demonstration

**Hint:** Use appropriate data types: `int` for integers, `double`/`float` for decimals, `char` for single characters, `bool` for true/false, `string` for text
```cpp
#include <iostream>

using namespace std;

int main() {

    int number1 = 5;
    double number2 = 2.6;
    float number3 = 3.4f;
    char character = 'A';
    bool isActive = true;
    string text = "KBTU SITE";
    

    return 0;
}
```

---

## 5.cpp
Variable naming rules and comments

**Hint:** Variable names can use letters, digits (not first), underscore. Use `//` for line comments, `/* */` for block comments
```cpp
#include <iostream>

using namespace std;

int main() {
    // line comment

    /*
    multi 
    line 
    comment
    */


    /*
    Allowed Characters
        Letters: a–z, A–Z
        Digits: 0–9 (but not as the first character)
        Underscore: _
    
    */

    // int 1num; error
    // int 3; error
    // int my-number; error
    int my_number; // ok
    int myNumber; // ok
    int a, A; // ok
    // int my number; error
    int _count;
    // int char; error
    // int return; error

    int age = 20;
    double pi = 3.14159;
    float rate = 0.95f;
    char grade = 'A';
    bool isOnline = true;

    

    return 0;
}
```

---

## 6.cpp
Input two numbers separately and calculate sum

**Hint:** Use `cin` twice to read two separate inputs, then add them together
```cpp
#include <iostream>

using namespace std;

int main() {
    
    int num1, num2;

    cin >> num1;
    cin >> num2;

    int sum = num1 + num2;

    cout << sum << endl;
    

    return 0;
}
```

---

## 7.cpp
Input two numbers in one line and calculate sum

**Hint:** Use `cin >> var1 >> var2` to read multiple values separated by spaces in one statement
```cpp
#include <iostream>

using namespace std;

int main() {
    
    int num1, num2;

    cin >> num1 >> num2;

    int sum = num1 + num2;

    cout << sum << endl;
    

    return 0;
}
```

---

## 8.cpp
Modulo operation demonstration

**Hint:** Use `%` operator to get remainder of division. When dividend is smaller than divisor, result equals dividend
```cpp
#include <iostream>

using namespace std;

int main() {
    
    int a = 10;
    int b = 12;
    
    cout << a % b << endl;
    

    return 0;
}
```

---

## 9.cpp
Floating point division

**Hint:** Use `double` type and ensure at least one operand is decimal (5.0) to get precise division result
```cpp
#include <iostream>

using namespace std;

int main() {
    
    double result = 5.0 / 2;

    cout << result << endl;
    

    return 0;
}
```

---

## 10.cpp
Type casting (conversion) demonstration

**Hint:** Use `(type)` before value to convert between data types. `(int)5.6` converts float to integer
```cpp
#include <iostream>

using namespace std;

int main() {
    
    int x = (int)5.6; // type casting

    cout << x << endl;



    return 0;
}
```

---

## 11.cpp
Character to ASCII code conversion

**Hint:** Cast `char` to `int` using `(int)character` to get ASCII value. Space character has ASCII value 32
```cpp
#include <iostream>

using namespace std;

int main() {
    
    char a = ' ';

    cout << (int)a << endl;


    return 0;
}
```