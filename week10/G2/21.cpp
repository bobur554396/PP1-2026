#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> s;
    s.insert(30);
    s.insert(10);
    s.insert(30);                 // ignored, 30 is already there
    s.insert(20);

    cout << "size: " << s.size() << endl; // 3

    if (s.find(10) != s.end()) {
        cout << "Found!" << endl;
    }
    cout << "count(99): " << s.count(99) << endl;

    for (int x : s) 
        cout << x << " ";      // always in sorted order
    cout << endl;

    s.erase(10);
    for (int x : s) 
        cout << x << " ";
    cout << endl;
    return 0;
}