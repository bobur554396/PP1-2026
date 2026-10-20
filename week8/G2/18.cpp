#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "Hello";

    // append (+)
    s.append(" World");
    cout << "After append: " << s << endl;

    // insert
    s.insert(5, ",");  // Insert at position 5
    cout << "After insert: " << s << endl;

    s.insert(0, "Say: ");
    cout << "After insert at beginning: " << s << endl;

    return 0;
}