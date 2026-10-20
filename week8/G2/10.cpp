#include <iostream>

using namespace std;

int main() {
    string s = "KBTU";

    cout << s[0] << " " << s[s.size() - 1] << endl;
    cout << s.front() << " " << s.back() << endl;
    cout << *s.begin() << " " << *(s.end() - 1) << endl;

    return 0;
}