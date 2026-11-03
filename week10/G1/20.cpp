#include <iostream>
#include <set>

using namespace std;

int main(){
    set<int> s; // 1D: dynamic array
    s.insert(5);
    s.insert(3);
    s.insert(7);
    s.insert(5); // duplicate value will not be inserted
    s.insert(7); // duplicate value will not be inserted

    cout << s.size() << endl;
    // cout << s[0] << endl; // This line will cause a compilation error because sets do not support indexing

    return 0;
}