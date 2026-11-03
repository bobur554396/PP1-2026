#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a[3] = {10, 20, 30};
    vector<int> v(a, a + 3); // copy from array to vector
    // cout << v.size() << endl; // 3

    // 1. Range-based for (cleanest)
    // for(int x : v) 
    //     cout << x << " ";
    // cout << endl;

    // 2. Classic index loop
    // int n = v.size();
    // for (int i = 0; i < n; i++) 
    //     cout << v[i] << " ";
    // cout << endl;

    // 3. Iterators
    // for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) 
    //     cout << *it << " ";
    // cout << endl;

    // the same with auto, which asks the compiler to work out the type
    // for (auto it = v.begin(); it != v.end(); ++it) 
    //     cout << *it << " ";
    // cout << endl;

    // to CHANGE the elements in a range-based for, take a reference
    // for (int &x : v) 
    //     x *= 2;
    
    for (int x : v) 
        cout << x << " ";
    
    cout << endl;
    return 0;
}