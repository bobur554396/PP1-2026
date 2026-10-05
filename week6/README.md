# Lecture 5: Two-Dimensional Arrays

## 1. 1D Array Sort and Reverse
Two operations on a plain 1D array that we will reuse on matrix rows later.

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1000;
int arr[MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);           // ascending
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    reverse(arr, arr + n);        // now descending
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
```

Both functions come from `<algorithm>`. `sort(arr, arr + n)` sorts the elements
`arr[0] .. arr[n-1]`: the second argument is the position *after* the last element, not the
last element itself. To sort descending, sort first and then reverse.

**Input**
```
5
4 1 3 2 5
```
**Output**
```
1 2 3 4 5
5 4 3 2 1
```

## 2. Infinite Loops and Nested Loops

### 2.1 Infinite loops
A loop whose condition never becomes false runs forever:

```cpp
while (true) { /* ... */ }   // most common form
for (;;)      { /* ... */ }  // the same thing with for
```

They are useful when the exit condition is discovered *inside* the body, and the only way out
is `break` (or `return`):

```cpp
while (true) {
    int x;
    cin >> x;
    if (x == 0) break;   // 0 means "stop"
    cout << x * x << endl;
}
```

An **accidental** infinite loop is a bug: forgetting `i++`, or writing `i--` where `i++` was
meant. The program simply hangs, and `Ctrl + C` in the terminal stops it.

### 2.2 Nested loops
A **nested loop** is a loop inside another loop. This is the basic tool for 2D arrays: the
outer loop walks through the rows, the inner loop walks across the columns of the current row.

```cpp
for (int i = 0; i < n; i++) {        // pick a row
    for (int j = 0; j < m; j++) {    // walk across that row
        // work here
    }
}
```

For each value of `i` the inner loop runs completely before `i` moves on, so the work is done
in the order `(0,0), (0,1), ..., (0,m-1), (1,0), ...` - left to right, top to bottom, the way
we read a page of text. This **rows-outer, columns-inner** order is the standard one. The body
of the inner loop runs `n * m` times in total.

### 2.3 Multiplication table
A nested loop with no array at all.

```cpp
#include <iostream>

using namespace std;

int main() {
    int n = 10;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << i * j << "\t";
        }
        cout << endl;                 // end of a row
    }
    return 0;
}
```

`"\t"` is a tab character, which lines the numbers up in columns. `endl` after the inner loop
ends the row. Swap the two `cout` lines around and the whole table collapses into one line, a
good mistake to try once on purpose.

## 3. 2D Array (Matrix)
A one-dimensional array is a single row of boxes: `a[0]`, `a[1]`, `a[2]`, ...
A **two-dimensional (2D) array** is a *grid* of boxes arranged in **rows** and **columns**,
exactly like a table or a chessboard. In mathematics such a grid is called a **matrix**.

To name one box in a grid we need *two* numbers: the **row index** and the **column index**.
We write `a[i][j]`, where `i` is the row and `j` is the column. Both indices start at **0**.

```
            col 0   col 1   col 2   col 3
row 0   [    5   ][   8  ][   2  ][   9  ]
row 1   [    1   ][   0  ][   7  ][   4  ]
row 2   [    3   ][   6  ][   8  ][   2  ]
```

Here `a[0][0]` is 5, `a[1][3]` is 4, and `a[2][1]` is 6.

- **Key characteristics**:
  - Elements are stored in a grid of rows and columns.
  - All elements have the same type.
  - The number of rows and columns is fixed (for the static arrays we use in this course).
  - Both indices are 0-based: for `n` rows and `m` columns the valid indices are
    `0 .. n-1` and `0 .. m-1`.

### Declaration
Give **two** sizes in square brackets: first the number of rows, then the number of columns.

```cpp
int a[3][4];   // 3 rows, 4 columns, 12 boxes in total (uninitialised)
```

A freshly declared array contains **garbage** until you put something into it.

As in Lecture 4, the sizes must be constants known at compile time, so `int a[n][m];` after
reading `n` and `m` is not standard C++. Declare the matrix at the **maximum** size the
problem allows and use only the first `n` rows and `m` columns:

```cpp
const int MAXN = 100;      // the problem says 1 <= n, m <= 100
int a[MAXN][MAXN];
```

## 4. Initializing Two-Dimensional Arrays
Fill a 2D array at the moment of declaration with **nested initializer lists**, one inner
`{ }` per row:

```cpp
int b[2][2] = {{1, 2},
               {3, 4}};      // b[0][0]=1, b[0][1]=2, b[1][0]=3, b[1][1]=4

int c[][3] = {{1, 2, 3},
              {4, 5, 6}};    // rows counted by the compiler -> 2 rows, 3 columns

int grid[3][4] = {};         // all 12 elements become 0
```

You may leave out the **number of rows** and let the compiler count them, but you must
**always** state the number of columns. The compiler needs it to know where each row ends, so
`int a[][] = ...;` does not compile.

A complete program that declares and prints a fixed matrix:

```cpp
#include <iostream>

using namespace std;

int main() {
    int a[3][3] = {{1, 2, 3},
                   {4, 5, 6},
                   {7, 8, 9}};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
```

## 5. Accessing Two-Dimensional Array Elements
One element is read or changed with two indices, `a[row][column]`:

```cpp
int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
cout << a[1][2];   // Outputs 6 (row 1, column 2)
a[0][1] = 9;       // row 0, column 1 becomes 9
```

Two rules worth repeating:

> Keep `i` for rows and `j` for columns everywhere in the program. Writing `a[j][i]` where you
> mean `a[i][j]` reads the wrong cell, and may go out of bounds.

> Loop conditions are `i < n` and `j < m`, never `<=`. In a 3x4 matrix the valid rows are
> 0 to 2 and the valid columns are 0 to 3; `a[3][0]` and `a[0][4]` are out of bounds and C++
> does not check them for you.

A program that asks for a position and prints that element:

```cpp
#include <iostream>

using namespace std;

int main() {
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int row, col;
    cin >> row >> col;

    if (row < 0 || row >= 2 || col < 0 || col >= 3) {
        cout << "out of bounds" << endl;      // never read outside the array
        return 0;
    }
    cout << "Element at [" << row << "][" << col << "]: " << a[row][col] << endl;
    return 0;
}
```

## 6. Matrix Input and Output
On the judge the sizes come first, then the values row by row.

```cpp
#include <iostream>

using namespace std;

const int MAXN = 100;
int a[MAXN][MAXN];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;                 // newline after each row
    }
    return 0;
}
```

**Input**
```
2 3
1 2 3
4 5 6
```
**Output**
```
1 2 3
4 5 6
```

A space between the numbers of a row and a newline at the end of each row. Without them the
output is an unreadable wall of digits and the judge reports a wrong answer.

## 7. freopen
Typing a whole matrix by hand on every run is slow. `freopen` redirects `cin` to read from a
file and `cout` to write to a file, so you prepare the test once and rerun it as often as you
like.

```cpp
#include <iostream>

using namespace std;

const int MAXN = 100;
int a[MAXN][MAXN];

int main() {
    freopen("input.txt", "r", stdin);     // cin now reads from input.txt
    freopen("output.txt", "w", stdout);   // cout now writes to output.txt

    int n, m;
    cin >> n >> m;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            sum += a[i][j];
        }
    }
    cout << sum << endl;
    return 0;
}
```

`input.txt`, in the same folder as the program:
```
2 3
1 2 3
4 5 6
```

`output.txt` after running:
```
21
```

Notes:

- `"r"` means *read*, `"w"` means *write* (an existing `output.txt` is overwritten).
- `freopen` comes from `<cstdio>`; `<iostream>` usually pulls it in, but adding
  `#include <cstdio>` is safer.
- **Remove both `freopen` lines before submitting to ejudge.** The judge feeds the test
  through standard input and reads standard output.

## 8. Table of Multiplication Stored in a Matrix
The same table as in 2.3, but built in a matrix first and printed afterwards. Note that
`a[i][j]` holds `(i + 1) * (j + 1)`, because the indices start at 0 while the table starts at 1.

```cpp
#include <iostream>

using namespace std;

const int MAXN = 100;
int a[MAXN][MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = (i + 1) * (j + 1);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
```

**Input**
```
3
```
**Output**
```
1	2	3
2	4	6
3	6	9
```

## 9. Max Element in a Matrix
```cpp
#include <iostream>

using namespace std;

const int MAXN = 100;
int a[MAXN][MAXN];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int mx = a[0][0];               // start from a real element, not from 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] > mx) {
                mx = a[i][j];
            }
        }
    }
    cout << "Max element: " << mx << endl;
    return 0;
}
```

Starting with `mx = 0` is a classic bug: if every element is negative, the program answers 0,
a value that is not in the matrix at all.

## 10. Eye Matrix (1 on the Main Diagonal, 0 Elsewhere)
The identity matrix. A cell is on the **main diagonal** when its row and column indices are
equal, `i == j`.

```cpp
#include <iostream>

using namespace std;

const int MAXN = 100;
int a[MAXN][MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = (i == j) ? 1 : 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
```

**Input**
```
3
```
**Output**
```
1 0 0
0 1 0
0 0 1
```

## 11. Eye Matrix with 1, 2, 3, ... on the Main Diagonal
The only change from section 10 is the value we store: `i + 1` instead of `1`.

```cpp
#include <iostream>

using namespace std;

const int MAXN = 100;
int a[MAXN][MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = (i == j) ? (i + 1) : 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
```

**Input**
```
3
```
**Output**
```
1 0 0
0 2 0
0 0 3
```

## 12. Opposite Eye Matrix (1 on the Anti-Diagonal)
The **anti-diagonal** runs from the top right corner to the bottom left one. A cell is on it
when `i + j == n - 1`. Check it on paper for `n = 3`: `(0,2)`, `(1,1)`, `(2,0)`.

```cpp
#include <iostream>

using namespace std;

const int MAXN = 100;
int a[MAXN][MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = (i + j == n - 1) ? 1 : 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
```

**Input**
```
3
```
**Output**
```
0 0 1
0 1 0
1 0 0
```

## 13. Opposite Eye Matrix with 1, 2, 3, ... on the Anti-Diagonal
```cpp
#include <iostream>

using namespace std;

const int MAXN = 100;
int a[MAXN][MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = (i + j == n - 1) ? (i + 1) : 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
```

**Input**
```
3
```
**Output**
```
0 0 1
0 2 0
3 0 0
```

## 14. Symmetric Matrix
A square matrix is **symmetric** when `a[i][j] == a[j][i]` for every pair of indices, that is,
when it is unchanged by mirroring across the main diagonal. The same job is done three ways
below, which is the point of the exercise: a flag, an early exit, and a counter.

Note that all three loop with `j = i + 1`, so each pair is compared **once**. Comparing all
`n * n` cells does the same work twice.

### 14.1 With bool
```cpp
#include <iostream>

using namespace std;

const int MAXN = 100;
int a[MAXN][MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    bool isSymmetric = true;
    for (int i = 0; i < n && isSymmetric; i++) {     // stops the outer loop too
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                isSymmetric = false;
                break;                               // leaves the inner loop only
            }
        }
    }
    cout << (isSymmetric ? "Symmetric" : "Not Symmetric") << endl;
    return 0;
}
```

A plain `break` leaves only the **inner** loop. The `&& isSymmetric` in the outer condition is
what stops the outer one as well.

### 14.2 With return
```cpp
#include <iostream>

using namespace std;

const int MAXN = 100;
int a[MAXN][MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                cout << "Not Symmetric" << endl;
                return 0;                      // leaves main immediately
            }
        }
    }
    cout << "Symmetric" << endl;
    return 0;
}
```

The shortest of the three: no flag to maintain, and `return 0` escapes both loops at once.

### 14.3 With counter
```cpp
#include <iostream>

using namespace std;

const int MAXN = 100;
int a[MAXN][MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int bad = 0;                                   // how many pairs do not match
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                bad++;
            }
        }
    }
    cout << "Mismatched pairs: " << bad << endl;
    cout << (bad == 0 ? "Symmetric" : "Not Symmetric") << endl;
    return 0;
}
```

The counter version always scans the whole matrix, so it is the slowest of the three, but it
tells us *how far* the matrix is from symmetric, not just yes or no.

**Input**
```
3
1 2 3
2 4 5
3 5 6
```
**Output**
```
Mismatched pairs: 0
Symmetric
```

## 15. Max and Min with Their Locations (n x m Matrix)
```cpp
#include <iostream>

using namespace std;

const int MAXN = 100;
int a[MAXN][MAXN];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int mx = a[0][0], mn = a[0][0];
    int mxRow = 0, mxCol = 0, mnRow = 0, mnCol = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] > mx) {
                mx = a[i][j];
                mxRow = i;
                mxCol = j;
            }
            if (a[i][j] < mn) {
                mn = a[i][j];
                mnRow = i;
                mnCol = j;
            }
        }
    }
    cout << "Max: " << mx << " at [" << mxRow << "][" << mxCol << "]" << endl;
    cout << "Min: " << mn << " at [" << mnRow << "][" << mnCol << "]" << endl;
    return 0;
}
```

Because we compare with `>` and `<` (not `>=` and `<=`), the **first** occurrence in reading
order is reported when a value repeats. Both the value and its position have to be updated
inside the same `if`, which is the usual place to make a mistake.

**Input**
```
2 3
5 9 1
9 0 1
```
**Output**
```
Max: 9 at [0][1]
Min: 0 at [1][1]
```

## 16. Max per Row
```cpp
#include <iostream>

using namespace std;

const int MAXN = 100;
int a[MAXN][MAXN];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        int mx = a[i][0];             // declared inside the row loop: fresh for each row
        for (int j = 1; j < m; j++) {
            if (a[i][j] > mx) {
                mx = a[i][j];
            }
        }
        cout << "Row " << i << " max: " << mx << endl;
    }
    return 0;
}
```

`mx` lives inside the outer loop, so it restarts from `a[i][0]` for every row. Declaring it
above the outer loop would compare rows against each other instead.

## 17. Max per Row Sum (the Heaviest Row)
```cpp
#include <iostream>

using namespace std;

const int MAXN = 100;
int a[MAXN][MAXN];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int maxRow = 0;
    long long maxSum = 0;
    for (int j = 0; j < m; j++) {
        maxSum += a[0][j];          // start from row 0, not from 0
    }

    for (int i = 1; i < n; i++) {
        long long sum = 0;
        for (int j = 0; j < m; j++) {
            sum += a[i][j];
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxRow = i;
        }
    }
    cout << "Row " << maxRow << " has max sum: " << maxSum << endl;
    return 0;
}
```

Starting with `maxSum = 0` is the same bug as in section 9: with every row sum negative, no
row ever beats 0 and the program reports a sum that does not exist. Seed it from row 0 and
start the search at row 1.

**Input**
```
2 2
-1 -2
-5 -6
```
**Output**
```
Row 0 has max sum: -3
```

## 18. Snake
Print row 0 left to right, row 1 right to left, row 2 left to right, and so on.

```cpp
#include <iostream>

using namespace std;

const int MAXN = 100;
int a[MAXN][MAXN];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; j++) {       // even row: forwards
                cout << a[i][j] << " ";
            }
        } else {
            for (int j = m - 1; j >= 0; j--) {  // odd row: backwards
                cout << a[i][j] << " ";
            }
        }
    }
    cout << endl;
    return 0;
}
```

The direction depends on the parity of the row index, `i % 2`. The backwards loop counts down
from `m - 1` to `0`, so its condition is `j >= 0` and its step is `j--`.

**Input**
```
3 3
1 2 3
4 5 6
7 8 9
```
**Output**
```
1 2 3 6 5 4 7 8 9
```

---

# Appendix A. Additional Examples

Not covered in the lecture. Useful for the lab and for self-study: Lab 5 and the course manual
use the transpose and the row/column sums.

## A.1 Bubble Sort by Hand
How sorting actually works, without `<algorithm>`.

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

    for (int p = 0; p < n - 1; p++) {              // n - 1 passes are enough
        for (int q = 0; q < n - 1 - p; q++) {      // compare neighbours
            if (arr[q] > arr[q + 1]) {
                swap(arr[q], arr[q + 1]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
```

On every pass the largest remaining value "bubbles" to the end, so after `p` passes the last
`p` values are already in place and the inner loop can shrink. `swap` comes from `<utility>`
and is usually already available through `<iostream>`.

## A.2 Sum of All Elements
```cpp
#include <iostream>

using namespace std;

const int MAXN = 100;
int a[MAXN][MAXN];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    long long sum = 0;          // long long: many numbers may overflow int
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += a[i][j];
        }
    }
    cout << sum << endl;
    return 0;
}
```

## A.3 Sum of Each Row and Each Column
```cpp
#include <iostream>

using namespace std;

const int MAXN = 100;
int a[MAXN][MAXN];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {           // rows
        int rowSum = 0;
        for (int j = 0; j < m; j++) {
            rowSum += a[i][j];
        }
        cout << "Row " << i << ": " << rowSum << endl;
    }

    for (int j = 0; j < m; j++) {           // columns
        int colSum = 0;
        for (int i = 0; i < n; i++) {       // note: i moves, j is fixed
            colSum += a[i][j];
        }
        cout << "Col " << j << ": " << colSum << endl;
    }
    return 0;
}
```

For **row** sums the outer loop fixes a row and the inner loop slides across its columns. For
**column** sums the roles swap: the outer loop fixes a column and the inner loop slides *down*
the rows. The classic slip here is writing `a[j][i]` in the column loop.

## A.4 Diagonal Sums of a Square Matrix
```cpp
#include <iostream>

using namespace std;

const int MAXN = 100;
int a[MAXN][MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    long long main_d = 0, anti_d = 0;
    for (int i = 0; i < n; i++) {
        main_d += a[i][i];              // main diagonal
        anti_d += a[i][n - 1 - i];      // anti-diagonal
    }
    cout << "Main: " << main_d << endl;
    cout << "Anti: " << anti_d << endl;
    return 0;
}
```

Both diagonals need only **one** loop, not a nested pair: the column index is computed from
the row index.

## A.5 Transpose a Square Matrix (In Place)
Transposing turns rows into columns: the element at `[i][j]` swaps with the one at `[j][i]`.

```cpp
#include <iostream>

using namespace std;

const int MAXN = 100;
int a[MAXN][MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {     // upper triangle only
            swap(a[i][j], a[j][i]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
```

The inner loop starts at `j = i + 1` so each pair is touched **once**. Starting at `j = 0`
would swap every pair twice and give back the original matrix.

## A.6 Sort Each Row
```cpp
#include <iostream>

using namespace std;

const int MAXN = 100;
int a[MAXN][MAXN];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {                      // one row at a time
        for (int p = 0; p < m - 1; p++) {
            for (int q = 0; q < m - 1 - p; q++) {
                if (a[i][q] > a[i][q + 1]) {
                    swap(a[i][q], a[i][q + 1]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
```

This is the bubble sort of A.1 with `a[i][q]` in place of `arr[q]`, run once per row. Three
nested loops in total. The same thing with the ready-made function is
`sort(a[i], a[i] + m);` inside the row loop.

## A.7 Search for a Value in a Matrix
```cpp
#include <iostream>

using namespace std;

const int MAXN = 100;
int a[MAXN][MAXN];

int main() {
    int n, m, k;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    cin >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == k) {
                cout << "Found at [" << i << "][" << j << "]" << endl;
                return 0;
            }
        }
    }
    cout << "not found" << endl;
    return 0;
}
```
