# Lecture 3: Numeric Systems, Bits and Bitwise Operators

## 1. Numeric Systems

### Decimal System
- Base 10
- Digits: 0–9
- Example: `245` means (2 × 10²) + (4 × 10¹) + (5 × 10⁰)

### Binary System
- Base 2
- Digits: 0, 1
- Example: `1011` (binary) = (1 × 2³) + (0 × 2²) + (1 × 2¹) + (1 × 2⁰) = 11 (decimal)

### Octal System
- Base 8
- Digits: 0–7
- Example: `17` (octal) = (1 × 8¹) + (7 × 8⁰) = 15 (decimal)

### Hexadecimal System
- Base 16
- Digits: 0–9, A–F
- Example: `1A` (hex) = (1 × 16¹) + (10 × 16⁰) = 26 (decimal)

### Conversions
- **From any system to decimal**: Multiply each digit by its base raised to position power.
- **From decimal to binary**: Divide by 2 repeatedly, read remainders in reverse.
- **From decimal to octal**: Divide by 8 repeatedly, read remainders in reverse.
- **From decimal to hex**: Divide by 16 repeatedly, read remainders in reverse.

## 2. Bitwise Operators

- **AND (`&`)**: Bit is 1 if both are 1.  
  Example: `6 & 3` → `110 & 011 = 010` (2)

- **OR (`|`)**: Bit is 1 if at least one is 1.  
  Example: `6 | 3` → `110 | 011 = 111` (7)

- **XOR (`^`)**: Bit is 1 if bits are different.  
  Example: `6 ^ 3` → `110 ^ 011 = 101` (5)

- **NOT (`~`)**: Inverts all bits (1 → 0, 0 → 1).

- **Left shift (`<<`)**: Shifts bits left, fills with 0.  
  Example: `5 << 1` → `101` → `1010` (10)

- **Right shift (`>>`)**: Shifts bits right, fills with 0 (for unsigned).  
  Example: `5 >> 1` → `101` → `10` (2)

Common patterns:
- Setting a bit: x |= (1 << n) sets bit n.
- Clearing a bit: x &= ~(1 << n) clears bit n.
- Toggling a bit: x ^= (1 << n) flips bit n.
- Checking bit: (x >> n) & 1 returns bit n (0 or 1).
- Check if even: (x & 1) == 0 -> true if even.

#### Truth tables (bitwise / boolean view)

AND (a & b)

| a | b | a & b |
|---:|---:|---:|
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

OR (a | b)

| a | b | a \| b |
|---:|---:|---:|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 1 |

XOR (a ^ b)

| a | b | a ^ b |
|---:|---:|---:|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

NOT (~a) — unary (bit flip)

| a | ~a |
|---:|---:|
| 0 | 1 |
| 1 | 0 |

## 3. Bit Manipulation Tasks

### 3.1 Set the i-th bit to 1
**Hint:** Use `x |= (1 << i)` to force the i-th bit to 1.
```cpp
#include <iostream>

using namespace std;

int main() {
    int x = 5; // 0101
    int i = 1;
    x |= (1 << i);
    cout << "After setting bit " << i << ": " << endl; // 7 (0111)
    return 0;
}
```

### 3.2 Clear the i-th bit (set to 0)
**Hint:** Use `x &= ~(1 << i)` to reset the i-th bit to 0.
```cpp
#include <iostream>

using namespace std;

int main() {
    int x = 7; // 0111
    int i = 0;
    x &= ~(1 << i);
    cout << "After clearing bit " << i << ": " << x << endl; // 6 (0110)

    return 0;
}
```

### 3.3 Toggle (invert) the i-th bit
**Hint:** Use `x ^= (1 << i)` to flip the i-th bit.
```cpp
#include <iostream>

using namespace std;

int main() {
    int x = 6; // 0110
    int i = 2;
    x ^= (1 << i);
    cout << "After toggling bit " << i << ": " << x << endl; // 2 (0010)

    return 0;
}
```

### 3.4 Check if the i-th bit is set
**Hint:** Use `(x >> i) & 1` to test whether the i-th bit is 1.
```cpp
#include <iostream>

using namespace std;

int main() {
    int x = 2; // 0010
    int i = 1;
    bool isSet = (x >> i) & 1;
    cout << "Is bit " << i << " set? " << isSet << endl; // 1

    return 0;
}
```

### 3.5 Count number of set bits (Hamming weight)
**Hint:** Shift right and add `(n & 1)` to count all 1s in the number.
```cpp
#include <iostream>

using namespace std;

int main() {
    int x = 7; // 0111
    int count = 0;
    int n = x;
    while (n) {
        count += (n & 1);
        n >>= 1;
    }
    cout << "Number of set bits: " << count << endl; // 3

    return 0;
}
```

### 3.6 Compute 2^n using bit shifting
**Hint:** Use `(1 << n)` to compute 2 raised to the power of n.
```cpp
#include <iostream>

using namespace std;

int main() {
    int n = 3;
    int result = (1 << n);
    cout << "2^" << n << " = " << result << endl; // 8 (1000)

    return 0;
}

```

### 3.7 Remove the lowest set bit
**Hint:** Use `x & (x - 1)` to clear the rightmost 1 in the binary number.
```cpp
#include <iostream>

using namespace std;

int main() {
    int x = 12; // 1100
    x = x & (x - 1);
    cout << "After removing lowest set bit: " << x << endl; // 8 (1000)

    return 0;
}
```

### 3.8 Check if a number is a power of 2
**Hint:** A number is a power of 2 if it has exactly one set bit.
```cpp
#include <iostream>

using namespace std;

int main() {
    int x = 16;
    bool isPowerOfTwo = (x > 0) && ((x & (x - 1)) == 0);
    cout << x << (isPowerOfTwo ? " is " : " is not ") << "a power of 2" << endl;
    
    return 0;
}
```

### 3.9 Swap two numbers without a temporary variable
**Hint:** Use the XOR trick to swap two variables without using an extra one.
```cpp
a ^ b ^ a = b
a ^ b ^ b = a
```

```cpp
#include <iostream>

using namespace std;

int main() {
    int a = 5, b = 9;
    a ^= b;
    b ^= a;
    a ^= b;
    cout << "a = " << a << ", b = " << b << endl; // a = 9, b = 5

    return 0;
}
```
