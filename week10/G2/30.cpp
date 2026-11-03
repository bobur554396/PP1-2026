#include <iostream>
#include <map>

using namespace std;

int main(){
    map<string, int> m; // init the map, 1D "dynamic" array
    // map_var[key] = value; // adding new pair
    m["banana"] = 5;
    m["apple"] = 5;
    m["orange"] = 10;
    m["apple"] = 8; // updating existing pair

    cout << m.size() << endl; // 3
    cout << m["banana"] << endl; // 5

    return 0;
}