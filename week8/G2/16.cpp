#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "Hello World";

    // substr - sub string
    // substr(index, count)

    string sub1 = s.substr(0, 5);   // "Hello"
    string sub2 = s.substr(6, 5);   // "World"
    string sub3 = s.substr(6);      // "World" (from index 6 to the end)

    cout << "Original: " << s << endl;
    cout << "substr(0, 5): " << sub1 << endl;
    cout << "substr(6, 5): " << sub2 << endl;
    cout << "substr(6): " << sub3 << endl;

    return 0;
}