#include <iostream>
#include <string>

using namespace std;

int main() {
    int a[3] = {11, 2, 3};
    // a[0] - 11
    a[0] = 20;


    pair<string, int> p = {"Alice", 25};

    cout << p.first << " " << p.second << endl;

    p.second = 26;                      // the members can be changed
    cout << p.first << " " << p.second << endl;

    int b = 2;
    pair<string, int> q = make_pair("Bob", 30);
    cout << q.first << " " << q.second << endl;
    return 0;
}