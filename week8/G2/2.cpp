#include <iostream>

using namespace std;

int main() {
    string s = "KBTU";

    // built-in functions

    cout << s.size() << endl;
    cout << s.length() << endl;
    cout << s[0] << " " << s[s.size() - 1] << endl;
    cout << s.front() << " " << s.back() << endl;

    return 0;
}