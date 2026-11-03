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