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

    for(int x : dq) 
        cout << x << " "; // a deque does support range-for
    cout << endl;

    dq.pop_front();      // [10, 20]
    dq.pop_back();       // [10]

    // direct access: 10
    cout << dq[0] << endl;                     
    return 0;
}