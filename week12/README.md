# Lecture 9: STL (Part 2) - Stack, Queue, Deque

## 1. Overview
Lecture 8 introduced `vector`, `set` and `map`, which are general-purpose storage. This lecture
covers three containers built for a specific **access pattern** instead: they restrict *how*
you may reach the data, and in exchange the operations they do allow are fast and the code that
uses them is short.

| Container | Underlying structure | Access pattern | Key feature |
|---------|----------------------|----------------|-------------|
| `stack`   | usually `deque` | LIFO (Last In, First Out) | only the top element is reachable |
| `queue`   | usually `deque` | FIFO (First In, First Out) | read the front, add at the back |
| `deque`   | double-ended queue | both ends | fast insert and remove at both sides |

Each needs its own header:

```cpp
#include <stack>
#include <queue>
#include <deque>
```

`stack` and `queue` are called **adapters**: they are a restricted interface on top of another
container. That restriction is the point. A `stack<int>` cannot be indexed, has no `begin()` or
`end()`, and cannot be used in a range-based `for`. If you find yourself wanting to look at the
middle of a stack, you wanted a `vector` or a `deque`.

---

## 2. Stack: LIFO (Last In, First Out)

A stack behaves like a pile of plates: you add a plate on **top**, and you can only take the
plate from the **top**. The last item in is the first item out.

### 2.1 Key Operations
| Function     | Description                            | Time Complexity |
|--------------|----------------------------------------|-----------------|
| `push(x)`    | Add element to top                     | O(1)            |
| `pop()`      | Remove top element                     | O(1)            |
| `top()`      | Access top element (no remove)         | O(1)            |
| `empty()`    | Check if stack is empty                | O(1)            |
| `size()`     | Return number of elements              | O(1)            |

### 2.2 Basic Usage
```cpp
#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "size: " << st.size() << endl;
    cout << "top: " << st.top() << endl;

    while (!st.empty()) {
        cout << st.top() << " ";   // read the top
        st.pop();                  // then remove it
    }
    cout << endl;
    return 0;
}
```

**Output**
```
size: 3
top: 30
30 20 10
```

Two rules worth repeating:

- `pop()` **returns nothing**. It only removes. To use the value you must read `top()` first
  and then call `pop()`, as the loop above does. `cout << st.pop();` does not compile.
- `top()` and `pop()` on an **empty** stack are undefined behaviour, not an error you can
  catch. Always guard with `!st.empty()`.

### 2.3 Reverse a Sequence with a Stack
```cpp
#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> st;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.push(x);
    }

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}
```

**Input**
```
5
1 2 3 4 5
```
**Output**
```
5 4 3 2 1
```

Reversing is what a stack does for free: the order you take things out is the reverse of the
order you put them in.

### 2.4 Validating Balanced Brackets
```cpp
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string s) {
    stack<char> st;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        char c = s[i];

        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) return false;          // a closer with nothing open

            char open = st.top();
            st.pop();

            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{')) {
                return false;                      // wrong kind of closer
            }
        }
        // any other character is ignored
    }

    return st.empty();                             // nothing may stay open
}

int main() {
    string s;
    cin >> s;
    cout << (isValid(s) ? "YES" : "NO") << endl;
    return 0;
}
```

**Input**
```
{[()]}
```
**Output**
```
YES
```

Three ways a string can fail, and each is handled above: a closing bracket with nothing open
(`)(`), a closing bracket of the wrong kind (`([)]`), and an opening bracket never closed
(`([]`). The stack is the right tool because the bracket that must close next is always the one
opened **most recently**.

---

## 3. Queue: FIFO (First In, First Out)

A queue behaves like a line of people: new arrivals join at the **back**, and the person served
next is the one at the **front**. The first item in is the first item out.

### 3.1 Key Operations
| Function     | Description                            | Time Complexity |
|--------------|----------------------------------------|-----------------|
| `push(x)`    | Add element to the back                | O(1)            |
| `pop()`      | Remove the element at the front        | O(1)            |
| `front()`    | Access the front element               | O(1)            |
| `back()`     | Access the back element                | O(1)            |
| `empty()`    | Check if empty                         | O(1)            |
| `size()`     | Number of elements                     | O(1)            |

Note the asymmetry: you `push` at the back but `pop` at the front. As with a stack, `pop()`
returns nothing, and `front()` on an empty queue is undefined.

### 3.2 Basic Usage
```cpp
#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "front: " << q.front() << endl;
    cout << "back: " << q.back() << endl;

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}
```

**Output**
```
front: 10
back: 30
10 20 30
```

The same loop over a `stack` printed `30 20 10`. That one difference in output is the whole
difference between the two containers.

### 3.3 Print Queue Simulation
```cpp
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    queue<string> jobs;
    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command == "enqueue") {
            string job;
            cin >> job;
            jobs.push(job);
        } else if (command == "dequeue") {
            if (jobs.empty()) {
                cout << "empty" << endl;
            } else {
                cout << jobs.front() << endl;
                jobs.pop();
            }
        }
    }

    cout << "left in queue: " << jobs.size() << endl;
    return 0;
}
```

**Input**
```
6
enqueue report
enqueue thesis
dequeue
enqueue photo
dequeue
dequeue
```
**Output**
```
report
thesis
photo
left in queue: 0
```

Jobs are served in the order they arrived, no matter what arrives in between. The `empty`
branch matters: without it, a `dequeue` on an empty queue is undefined behaviour.

---

## 4. Deque: Double-Ended Queue

A `deque` (pronounced "deck") supports fast insertion and removal at **both ends**, and unlike
`stack` and `queue` it also allows access by index.

### 4.1 Key Operations
| Function         | Description                            | Time Complexity |
|------------------|----------------------------------------|-----------------|
| `push_back(x)`   | Add to the back                        | O(1)            |
| `push_front(x)`  | Add to the front                       | O(1)            |
| `pop_back()`     | Remove from the back                   | O(1)            |
| `pop_front()`    | Remove from the front                  | O(1)            |
| `front()`, `back()` | Access the ends                     | O(1)            |
| `dq[i]`, `at(i)` | Access by index                        | O(1)            |
| `empty()`, `size()`, `clear()` | Standard checks          | O(1)            |

### 4.2 Deque as a Flexible Container
```cpp
#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> dq;
    dq.push_back(10);    // [10]
    dq.push_front(5);    // [5, 10]
    dq.push_back(20);    // [5, 10, 20]

    cout << "Front: " << dq.front() << endl;   // 5
    cout << "Back: " << dq.back() << endl;     // 20
    cout << "Size: " << dq.size() << endl;     // 3

    for (int x : dq) cout << x << " ";         // a deque does support range-for
    cout << endl;

    dq.pop_front();      // [10, 20]
    dq.pop_back();       // [10]

    cout << dq[0] << endl;                     // direct access: 10
    return 0;
}
```

**Output**
```
Front: 5
Back: 20
Size: 3
5 10 20
10
```

A `vector` has no `push_front`: adding at the front of a vector means moving every other
element, which costs O(n). That is the reason `deque` exists.

### 4.3 Deque as a Sliding Window
```cpp
#include <iostream>
#include <deque>

using namespace std;

int main() {
    const int K = 3;       // keep only the last K numbers

    deque<int> window;
    int x;
    while (cin >> x) {
        window.push_back(x);
        if (window.size() > K) {
            window.pop_front();     // the oldest one leaves
        }

        for (int y : window) cout << y << " ";
        cout << endl;
    }
    return 0;
}
```

**Input**
```
1 2 3 4 5
```
**Output**
```
1
1 2
1 2 3
2 3 4
3 4 5
```

One `push_back` plus one `pop_front` keeps a window of fixed size moving across the input, and
both are O(1). This would need an O(n) shift on every step with a plain array.

### 4.4 Palindrome Check from Both Ends
```cpp
#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n;
    cin >> n;

    deque<int> dq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        dq.push_back(x);
    }

    bool ok = true;
    while (dq.size() > 1) {
        if (dq.front() != dq.back()) {
            ok = false;
            break;
        }
        dq.pop_front();
        dq.pop_back();
    }

    cout << (ok ? "YES" : "NO") << endl;
    return 0;
}
```

**Input**
```
5
1 2 3 2 1
```
**Output**
```
YES
```

The same two-pointer idea as the palindrome checks in Lecture 6, except the container itself
shrinks from both ends. The loop stops at `size() > 1`, because a single element left in the
middle is its own mirror and needs no comparison.

---

## 5. Comparison Table

| Feature              | Stack           | Queue           | Deque              |
|----------------------|-----------------|-----------------|---------------------|
| Access               | top only        | front and back  | both ends + by index |
| Insert               | top             | back            | front and back     |
| Remove               | top             | front           | front and back     |
| Access by index      | no              | no              | yes (`dq[i]`)      |
| Range-based `for`    | no              | no              | yes                |
| Underlying container | `deque` (default) | `deque` (default) | itself          |
| Typical use          | undo, brackets, reversing | BFS, scheduling | sliding window, both-ended work |

---

## 6. Common Real-World Applications

| Data Structure | Application Examples                          |
|----------------|-----------------------------------------------|
| `stack`        | function call stack, undo and redo, expression evaluation, bracket matching |
| `queue`        | BFS in graphs, printer queue, task scheduling, level-order traversal |
| `deque`        | sliding window problems, buffers that grow at both ends |

---

## 7. Best Practices
- Use `stack` when you need LIFO, `queue` for FIFO, `deque` when you work at both ends or need
  access by index.
- Always check `empty()` before `top()`, `front()`, `back()` or `pop()`.
- Remember that `pop()` returns nothing: read the value first, then pop.
- Do not reach for a `stack` or `queue` if you need to look at the middle; use `vector` or
  `deque`.
- Prefer `deque` over `vector` when you often add at the front.

---

# Appendix A. Additional Material

Not covered in the lecture. Lab 9 and the course manual use these.

## A.1 Printing a Stack Without Losing It
```cpp
#include <iostream>
#include <stack>

using namespace std;

void printStack(stack<int> st) {      // by value: we get our own copy
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);

    printStack(st);                   // prints 3 2 1 and empties the copy
    cout << "size after: " << st.size() << endl;
    return 0;
}
```

**Output**
```
3 2 1
size after: 3
```

There is no way to read a stack without removing elements, so to keep the original we pass it
**by value**: the function empties its own copy and the caller's stack is untouched. This is the
one place where the "pass by reference to avoid copying" advice from Lecture 7 is deliberately
ignored.

## A.2 Decimal to Binary with a Stack
```cpp
#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    stack<int> bits;
    while (n > 0) {
        bits.push(n % 2);      // remainders come out in reverse order
        n /= 2;
    }

    while (!bits.empty()) {
        cout << bits.top();
        bits.pop();
    }
    cout << endl;
    return 0;
}
```

**Input**
```
45
```
**Output**
```
101101
```

The conversion from Lecture 3 produced the bits from last to first. In that lecture we stored
them in an array and printed it backwards; a stack does the reversing for us. The `n == 0` case
needs its own branch, because the loop body never runs.

## A.3 A Queue of Pairs
```cpp
#include <iostream>
#include <queue>
#include <string>
#include <utility>

using namespace std;

int main() {
    queue<pair<string, int> > tasks;

    tasks.push(make_pair("print", 3));
    tasks.push(make_pair("scan", 1));
    tasks.push(make_pair("fax", 2));

    while (!tasks.empty()) {
        cout << tasks.front().first << " needs " << tasks.front().second << " min" << endl;
        tasks.pop();
    }
    return 0;
}
```

**Output**
```
print needs 3 min
scan needs 1 min
fax needs 2 min
```

Any type can go inside the angle brackets, including the `pair` from Lecture 8. Note the space
in `queue<pair<string, int> >`: without it, older compilers read `>>` as the input operator.
