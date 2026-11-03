#include <iostream>
#include <string>
#include <utility>

using namespace std;

int main() {
    int a = 5;
    a = 10;

    pair<string, int> p = {"Alice", 25};

    cout << p.first << " " << p.second << endl;

    p.second = 26;                      // the members can be changed
    cout << p.first << " " << p.second << endl;

    pair<string, int> q = make_pair("Bob", 30);
    cout << q.first << " " << q.second << endl;
    return 0;
}