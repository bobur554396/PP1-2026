#include <iostream>
#include <cctype>

using namespace std;

int main() {
    char c = 'A';
    cout << (char)tolower(c) << endl;   // a
    cout << (char)toupper(c) << endl;   // A

    char d = 'b';
    cout << (char)toupper(d) << endl;   // B

    // Without the cast you get the ASCII code, not the letter
    cout << tolower(c) << endl;         // 97
    return 0;
}