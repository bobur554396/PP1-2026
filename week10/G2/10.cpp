#include <iostream>
#include <vector>

using namespace std;

int main(){
    int a[4]; // 1D "fixed/static" array
    // a[5] = 10; // out of bounds, undefined behavior
    a[0] = 4;
    a[1] = 5;
    a[2] = 1;
    a[3] = 2;
    // a[4] = 10; // out of bounds, undefined behavior

    // cout << a[0] << endl; // 4

    vector<int> v; // init the vector, 1D "dynamic" array
    v.push_back(4);
    v.push_back(5);
    v.push_back(5);
    v.push_back(2);
    v.push_back(10); // add 10 to the end of the vector

    v.pop_back(); // remove the last element (10) from the vector

    cout << v.empty() << endl; // 0 (false)
    cout << v.size() << endl; // 5
    cout << v.front() << " " << v.back() << endl; // 4 2
    cout << v[0] << " " << v[v.size() - 1] << endl; // 4 2
    cout << *v.begin() << " " << *(v.end() - 1) << endl; // 4 2
    
    v.erase(v.end() - 1); // remove the second element (5) from the vector
    v.clear(); // remove all elements from the vector

    for(int i = 0; i < v.size(); i++){
        // cout << v[i] << " ";
        cout << v.at(i) << " ";
    }
    cout << endl;

    return 0;
}