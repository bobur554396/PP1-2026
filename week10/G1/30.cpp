#include <iostream>
#include <map>

using namespace std;

int main(){
    map<string, int> m; // 1D: dynamic array
    // map[key] = value; // insert or update key-value pair
    m["banana"] = 3;
    m["apple"] = 5;
    m["orange"] = 3;
    m["apple"] = 10; // update value for key "apple"

    cout << m.size() << endl;

    cout << m["apple"] << endl; // prints 10

    return 0;
}