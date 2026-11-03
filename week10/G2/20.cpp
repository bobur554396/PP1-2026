#include <iostream>
#include <set>

using namespace std;

int main(){
    set<int> s; // init the set, 1D "dynamic" array
    s.insert(4);
    s.insert(5);
    s.insert(5); // duplicate, will not be added
    s.insert(5); // duplicate, will not be added
    s.insert(5); // duplicate, will not be added
    s.insert(2);

    cout << s.size() << endl; // 3
    // cout << s[0] << endl; // error: no operator[] for set

    return 0;
}