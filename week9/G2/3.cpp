#include <iostream>
#include <cctype>

using namespace std;

int main() {
    char ch = '5';
    cout << isdigit(ch) << endl;  // non-zero: it is a digit
    cout << isalpha(ch) << endl;  // 0: it is not a letter
    cout << isalnum(ch) << endl;  // non-zero: digit or letter
    cout << ispunct('!') << endl; // non-zero: punctuation

    if(isdigit(ch)) {
        cout << ch << " is a digit" << endl;   // the normal way to use them
    }
    return 0;
}