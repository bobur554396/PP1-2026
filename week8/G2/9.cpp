#include <iostream>
#include <string>

using namespace std;

int main() {
    char c = 'A';
    int ascii = (int)c; // type casting

    cout << "Character: " << c << endl;
    cout << "ASCII code: " << ascii << endl;

    // Convert back
    char c2 = (char)(ascii + 1);
    cout << "Next character: " << c2 << endl;

    // Digit to number
    char digit = '5';
    int num = digit - '0';  // Convert '5' to 5
    cout << "Digit '" << digit << "' as number * 2: " << num * 2 << endl;

    return 0;
}