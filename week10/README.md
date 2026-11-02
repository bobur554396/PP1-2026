# Lecture 8: STL (Part 1) - Containers

## 1. What is STL?
The **Standard Template Library (STL)** is the part of the C++ Standard Library that gives you
ready-made data structures and operations, so you do not have to write your own dynamic array
or your own sorting routine.

- **Components**:
  - **Containers**: store data (`vector`, `set`, `map`, ...)
  - **Algorithms**: sorting, searching, counting (`sort`, `find`, `max_element`, ...)
  - **Iterators**: pointer-like objects used to walk through a container
  - **Functions**: comparators you hand to an algorithm to change its behaviour

You have already been using the library: `cout` and `string` come from it. Each container needs
its own header: `<vector>`, `<set>`, `<map>`, plus `<algorithm>` for the algorithms.

Everything in this lecture uses C++11 features (`auto`, range-based `for`, brace lists such as
`{1, 2, 3}`), so compile with:

```bash
g++ main.cpp -o main -std=c++11
```

---

## 2. Containers Overview
STL containers are class templates that store collections of objects.

| Container | Order of elements | Duplicates | Access by index | Find a value |
|---------|--------|--------|-----------|-----------|
| `vector` | insertion order | allowed | yes, O(1) | O(n) |
| `set`    | sorted | not allowed | no | O(log n) |
| `map`    | sorted by key | keys unique | no, by key instead | O(log n) |

The type in angle brackets is the element type: `vector<int>`, `vector<string>`, `set<char>`,
`map<string, int>`.

---

## 3. Vector

`std::vector` is a dynamic array that can grow and shrink in size.

### 3.1 Key Functions
- `push_back(elm)` -> add element at the end
- `pop_back()` -> remove the last element
- `size()` -> number of elements
- `empty()` -> check if empty
- `v[i]` -> element number i, unchecked
- `at(i)` -> element number i, checked
- `front(), back()` -> first / last element
- `begin(), end()` -> iterators
- `insert(pos, elm)` -> insert at a position
- `erase(pos)` -> remove an element
- `clear()` -> remove all

### 3.2 Creating a Vector
```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;                      // empty
    vector<int> a(5);                   // 5 elements, all 0
    vector<int> b(5, 2);                // 5 elements, all 2
    vector<int> c = {1, 2, 3, 4, 5};    // listed values

    cout << v.size() << " " << a.size() << endl;
    cout << a[0] << " " << b[0] << " " << c[4] << endl;

    v.push_back(7);                     // v grows by one
    cout << v.size() << " " << v[0] << endl;
    return 0;
}
```

**Output**
```
0 5
0 2 5
1 7
```

Note the difference: `vector<int> a(5)` makes **five zeros**, while `vector<int> c = {5}`
makes **one element** equal to 5.

### 3.3 Given N Elements
```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    int size = v.size();                // int copy: no signed/unsigned warning
    for (int i = 0; i < size; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
```

**Input**
```
4
10 20 30 40
```
**Output**
```
10 20 30 40
```

`v.size()` is an unsigned type, so `i < v.size()` with `int i` makes the compiler warn.
Copying the size into an `int` first keeps the loop clean, exactly as with `s.size()` in
Lecture 6.

### 3.4 `v[i]` versus `v.at(i)`
```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v = {10, 20, 30};

    cout << v[1] << " " << v.at(1) << endl;    // both print 20

    int i = 10;
    if (i < (int)v.size()) {
        cout << v.at(i) << endl;
    } else {
        cout << "index " << i << " is out of range" << endl;
    }
    return 0;
}
```

**Output**
```
20 20
index 10 is out of range
```

Both read element `i`. `v[i]` does **not** check the index, so a wrong index gives rubbish or
a crash somewhere else in the program. `v.at(i)` checks and throws `out_of_range`, which turns
a silent wrong answer into a visible error while you are debugging.

### 3.5 Three Ways to Iterate
```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v = {10, 20, 30};

    // 1. Range-based for (cleanest)
    for (int x : v) cout << x << " ";
    cout << endl;

    // 2. Classic index loop
    int n = v.size();
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    cout << endl;

    // 3. Iterators
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) cout << *it << " ";
    cout << endl;

    // the same with auto, which asks the compiler to work out the type
    for (auto it = v.begin(); it != v.end(); ++it) cout << *it << " ";
    cout << endl;

    // to CHANGE the elements in a range-based for, take a reference
    for (int &x : v) x *= 2;
    for (int x : v) cout << x << " ";
    cout << endl;
    return 0;
}
```

**Output**
```
10 20 30
10 20 30
10 20 30
10 20 30
20 40 60
```

Without the `&` in `for (int &x : v)` you get a copy of each element, and `x *= 2` changes
nothing in the vector.

### 3.6 Sort with a Custom Function
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(int a, int b) {
    return a > b;           // "a must come before b"
}

int main() {
    vector<int> v = {5, 2, 8, 1};

    sort(v.begin(), v.end());             // ascending, the default
    for (int x : v) cout << x << " ";
    cout << endl;

    sort(v.begin(), v.end(), desc);       // descending, using our function
    for (int x : v) cout << x << " ";
    cout << endl;
    return 0;
}
```

**Output**
```
1 2 5 8
8 5 2 1
```

The comparator answers one question: *must `a` come before `b`?* It must return `false` when
the two are equal, so use `>` and `<`, never `>=` or `<=`. A comparator with `>=` can make
`sort` read past the end of the data and crash.

### 3.7 Erase and Clear
```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4};

    v.erase(v.begin() + 1);                 // remove the element at index 1 -> {1, 3, 4}
    for (int x : v) cout << x << " ";
    cout << endl;

    v.erase(v.begin(), v.begin() + 2);      // remove a range [0, 2) -> {4}
    for (int x : v) cout << x << " ";
    cout << endl;

    v.clear();                              // remove everything
    cout << v.size() << " " << v.empty() << endl;
    return 0;
}
```

**Output**
```
1 3 4
4
0 1
```

`erase` takes **iterators**, not indices, which is why we write `v.begin() + 1`. A range
`(first, last)` removes `last - first` elements and does not include `last` itself. Erasing in
the middle shifts everything after it one step left, so it costs O(n).

### 3.8 Insert
```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v = {1, 3};

    v.insert(v.begin() + 1, 2);      // {1, 2, 3}
    for (int x : v) cout << x << " ";
    cout << endl;

    v.insert(v.begin(), 0);          // {0, 1, 2, 3}
    for (int x : v) cout << x << " ";
    cout << endl;
    return 0;
}
```

**Output**
```
1 2 3
0 1 2 3
```

The new element goes **before** the position you give. Adding at the end with `push_back` is
cheap; inserting at the front moves every other element, so it costs O(n).

### 3.9 Read Until 0
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v;
    int x;
    while (cin >> x && x != 0) {
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    for (int y : v) cout << y << " ";
    cout << endl;
    return 0;
}
```

**Input**
```
5 3 9 1 0
```
**Output**
```
1 3 5 9
```

`cin >> x` is false when the input ends, so this loop also stops at end of file even without
the terminating 0. This is the usual pattern when the count is not given in advance: a vector
grows as needed, where a plain array would need a guessed maximum size.

---

## 4. Set

`std::set` is an ordered collection of **unique** elements.

### 4.1 Key Functions
- `insert(elm)` -> add, silently ignored if already present
- `find(elm)` -> iterator to the element, or `end()` if absent
- `count(elm)` -> 1 if present, 0 if not
- `erase(elm)` or `erase(iterator)`
- `size()`, `empty()`, `clear()`

### 4.2 Example
```cpp
#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> s;
    s.insert(30);
    s.insert(10);
    s.insert(30);                 // ignored, 30 is already there
    s.insert(20);

    cout << "size: " << s.size() << endl;

    if (s.find(10) != s.end()) {
        cout << "Found!" << endl;
    }
    cout << "count(99): " << s.count(99) << endl;

    for (int x : s) cout << x << " ";      // always in sorted order
    cout << endl;

    s.erase(10);
    for (int x : s) cout << x << " ";
    cout << endl;
    return 0;
}
```

**Output**
```
size: 3
Found!
count(99): 0
10 20 30
20 30
```

A set has no `[]` and no `push_back`: there is no position to speak of, because the set keeps
itself sorted. `count(x)` is the shortest membership test, and it only ever returns 0 or 1.

### 4.3 Distinct Values from Input
```cpp
#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    cout << s.size() << endl;              // how many distinct values
    for (int x : s) cout << x << " ";      // sorted, no duplicates
    cout << endl;
    return 0;
}
```

**Input**
```
6
5 1 5 3 1 5
```
**Output**
```
3
1 3 5
```

Two jobs in one container: duplicates disappear and the result comes out sorted.

---

## 5. Map

`std::map` holds ordered key-value pairs, like a dictionary.

### 5.1 What is `pair`?
```cpp
#include <iostream>
#include <string>
#include <utility>

using namespace std;

int main() {
    pair<string, int> p = {"Alice", 25};

    cout << p.first << " " << p.second << endl;

    p.second = 26;                      // the members can be changed
    cout << p.first << " " << p.second << endl;

    pair<string, int> q = make_pair("Bob", 30);
    cout << q.first << " " << q.second << endl;
    return 0;
}
```

**Output**
```
Alice 25
Alice 26
Bob 30
```

A `pair` glues two values of any types together. Its members are always called `first` and
`second`. A `map` is built from pairs: each element of a `map<string, int>` is a
`pair<const string, int>`, which is why loops over a map use `p.first` and `p.second`.

### 5.2 Insert and Access
```cpp
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> m;

    m["Alice"] = 25;                // create or overwrite with []
    m.insert({"Bob", 30});          // insert, does nothing if the key exists
    m.insert({"Bob", 99});          // ignored, Bob is already there

    cout << m["Alice"] << endl;     // 25
    cout << m["Bob"] << endl;       // 30
    cout << m.size() << endl;       // 2

    m["Alice"] = 26;                // overwrite with []
    cout << m["Alice"] << endl;
    return 0;
}
```

**Output**
```
25
30
2
26
```

Keep the two apart: `m[k] = v` always ends with `v` stored at `k`, while `m.insert({k, v})`
leaves an existing key untouched.

### 5.3 Checking a Key Without Creating It
```cpp
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> m;
    m["Alice"] = 25;

    // WRONG: reading a missing key with [] inserts it with value 0
    cout << m["Carol"] << endl;        // prints 0 ... and Carol now exists
    cout << m.size() << endl;          // 2

    // RIGHT: ask first
    if (m.count("Dave")) {
        cout << m["Dave"] << endl;
    } else {
        cout << "Dave is not in the map" << endl;
    }
    cout << m.size() << endl;          // still 2, Dave was not created

    // find gives you the element itself
    map<string, int>::iterator it = m.find("Alice");
    if (it != m.end()) {
        cout << it->first << " -> " << it->second << endl;
    }
    return 0;
}
```

**Output**
```
0
2
Dave is not in the map
2
Alice -> 25
```

Reading `m[k]` for a key that does not exist **inserts** it with the value 0. That silently
changes `size()`, adds the key to every later loop over the map, and is the single most common
map bug. Use `count(k)` when you only want to know whether the key is there, and `find(k)` when
you want the element itself. The `it->first` and `it->second` notation is shorthand for
`(*it).first` and `(*it).second`.

### 5.4 Student Points
```cpp
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> points;
    points["A"] = 95;
    points["B"] = 88;
    points["C"] = 92;

    string maxStudent;
    int maxPoints = -1;
    for (auto &p : points) {
        if (p.second > maxPoints) {
            maxPoints = p.second;
            maxStudent = p.first;
        }
    }
    cout << maxStudent << " has " << maxPoints << endl;
    return 0;
}
```

**Output**
```
A has 95
```

The same "find the maximum" pattern as with arrays, except the candidate value is `p.second`
and the answer we remember is `p.first`.

### 5.5 Count Letter Frequency
```cpp
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    for (auto &p : freq) {
        cout << p.first << ": " << p.second << endl;
    }
    return 0;
}
```

**Input**
```
banana
```
**Output**
```
a: 3
b: 1
n: 2
```

`freq[c]++` works even the first time a character is seen: `[]` creates the key with the value
0, and `++` makes it 1. The output comes out in sorted key order for free, because a map keeps
its keys sorted.

### 5.6 Read a Map from Input
```cpp
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> m;
    for (int i = 0; i < n; i++) {
        string key;
        int val;
        cin >> key >> val;
        m[key] = val;
    }

    for (auto &p : m) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}
```

**Input**
```
3
pear 4
apple 7
pear 9
```
**Output**
```
apple 7
pear 9
```

Note what the repeated key does: `m["pear"] = 9` overwrites the 4, so the map has two entries,
not three, and they print in alphabetical order.

---

## 6. Iterators

An **iterator** is an object that marks a position inside a container. `begin()` is the first
element and `end()` is **one past** the last one, which is why a loop runs while
`it != end()`. You read the element at a position with `*it`, and for a pair you can write
`it->first` as a shorthand for `(*it).first`.

```cpp
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    vector<int> v = {10, 20, 30};

    cout << *v.begin() << endl;             // 10, the first element
    cout << *(v.end() - 1) << endl;         // 30, the last one

    // forwards
    for (auto it = v.begin(); it != v.end(); ++it) cout << *it << " ";
    cout << endl;

    // backwards, with reverse iterators
    for (auto it = v.rbegin(); it != v.rend(); ++it) cout << *it << " ";
    cout << endl;

    // the same code shape works on a completely different container
    set<int> s = {3, 1, 2};
    for (auto it = s.begin(); it != s.end(); ++it) cout << *it << " ";
    cout << endl;
    return 0;
}
```

**Output**
```
10
30
10 20 30
30 20 10
1 2 3
```

This uniformity is the point of iterators: the same loop shape walks a vector, a set or a map,
so an algorithm written against iterators works on all of them. Note that `*end()` must never
be read, and that adding to a vector with `push_back` while you hold its iterators can make
those iterators invalid.

---

## 7. Algorithms

All of these come from `<algorithm>` and take a pair of iterators marking the range to work
on. `accumulate` is the exception: it lives in `<numeric>`.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    vector<int> v = {5, 2, 8, 2, 1};

    cout << *max_element(v.begin(), v.end()) << endl;   // 8
    cout << *min_element(v.begin(), v.end()) << endl;   // 1
    cout << count(v.begin(), v.end(), 2) << endl;       // 2 (how many 2s)
    cout << accumulate(v.begin(), v.end(), 0) << endl;  // 18 (sum, starting from 0)

    if (find(v.begin(), v.end(), 8) != v.end()) {
        cout << "8 is in the vector" << endl;
    }

    reverse(v.begin(), v.end());
    for (int x : v) cout << x << " ";
    cout << endl;

    sort(v.begin(), v.end());
    for (int x : v) cout << x << " ";
    cout << endl;
    return 0;
}
```

**Output**
```
8
1
2
18
8 is in the vector
1 2 8 2 5
1 2 2 5 8
```

`max_element`, `min_element` and `find` return **iterators**, so they need a `*` to read the
value, and the result must be compared against `end()` before being used. The third argument of
`accumulate` is the starting value, and it also fixes the type: pass `0LL` when the sum could
overflow an `int`.

A set or a map cannot be given to `sort`: they keep their own order, and `sort` would have to
move elements around. To order data differently, copy it into a vector and sort that.

---

## 8. Summary Table

| Feature | Vector | Set | Map |
|-------|------|-----|-----|
| Dynamic size | yes | yes | yes |
| Duplicates | allowed | no | keys unique |
| Order | insertion order | sorted | sorted by key |
| Access by index | yes, O(1) | no | no, by key |
| Find a value | O(n) | O(log n) | O(log n) |
| Add | `push_back` | `insert` | `m[k] = v` |
| Membership test | `find` + `end()` | `count` | `count` |

---

## 9. Best Practices
- Use `vector` for simple lists, `set` for uniqueness plus order, `map` for key-value data.
- Never read a missing map key with `[]` when you only want to check it: `[]` creates it. Use
  `count` or `find`.
- Compare the result of `find` against `end()` before dereferencing it.
- Copy `v.size()` into an `int` before using it in a loop condition, or cast it.
- Prefer `auto` in iterator loops, and `for (int &x : v)` when you need to modify elements.
- A comparator must return `false` for equal values: use `<` or `>`, never `<=` or `>=`.
- Compile with `-std=c++11`.

---

# Appendix A. Additional Material

Not covered in the lecture. Lab 8 and the course manual use these.

## A.1 Sorting a `vector<pair<...>>` with a Two-Level Comparator
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool byScore(pair<string, int> a, pair<string, int> b) {
    if (a.second != b.second) {
        return a.second > b.second;   // higher score first
    }
    return a.first < b.first;         // same score: alphabetical
}

int main() {
    int n;
    cin >> n;

    vector<pair<string, int> > v;
    for (int i = 0; i < n; i++) {
        string name;
        int score;
        cin >> name >> score;
        v.push_back(make_pair(name, score));
    }

    sort(v.begin(), v.end(), byScore);

    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i].first << " " << v[i].second << endl;
    }
    return 0;
}
```

**Input**
```
4
ann 70
bob 90
cat 70
dan 90
```
**Output**
```
bob 90
dan 90
ann 70
cat 70
```

The comparator decides the main order first, and only when the two are equal on that does it
fall back to the tie-breaker. This is the standard shape for "sort by X, then by Y".

## A.2 Vector of Vectors (a Matrix with Sizes from Input)
```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > a(n, vector<int>(m, 0));   // n rows, m columns, all 0

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
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

This is the legal way to get a matrix whose sizes come from input, instead of the non-standard
`int a[n][m]` from Lecture 5. Indexing is still `a[i][j]`.

## A.3 Removing While Iterating
```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6};

    // remove every even number: build a new vector instead of erasing in place
    vector<int> odds;
    for (int x : v) {
        if (x % 2 != 0) odds.push_back(x);
    }
    v = odds;

    for (int x : v) cout << x << " ";
    cout << endl;
    return 0;
}
```

**Output**
```
1 3 5
```

Erasing from a vector inside a loop over that same vector is a classic bug: after `erase` the
following elements shift left, so the index or iterator you hold now points at the wrong
element and every second match gets skipped. Building a second container, as above, is simple
and always correct.
