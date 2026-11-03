#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> m;

    m["Alice"] = 25;                // create or overwrite with []
    m.insert({"Bob", 30});          // insert, does nothing if the key exists
    m.insert({"Bob", 99});          // ignored, Bob is already there

    cout << m["Alice"] << endl;     // 25
    cout << m["Bob"] << endl;       // 30
    cout << m.size() << endl;       // 2

    m["Alice"] = 26;                // overwrite with []
    cout << m["Alice"] << endl;
    return 0;
}