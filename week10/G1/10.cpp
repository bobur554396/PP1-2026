#include <iostream>
#include <vector>

using namespace std;

int main(){

    int a[4] = {3, 5, 7, 9}; // 1D: static array of size 4
    // a[6] = 10;
    // cout << a[0] << endl;

    vector<int> v; // 1D: dynamic array
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
    v.push_back(9);
    v.push_back(6);

    cout << "Size of vector: " << v.size() << endl;
    // cout << v[v.size() - 1] << endl;
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }

    return 0;
}