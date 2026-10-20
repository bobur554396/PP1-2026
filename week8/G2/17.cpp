#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "Hello World";
    // "Herld";

    cout << "Original: " << s << endl;

    // s.erase(2, 6);  // Erase " World"
    // cout << "After erase(5, 6): " << s << endl;

    s = "Hello World";
    s.erase(5);     // Erase from index 5 to the end
    cout << "After erase(5): " << s << endl;

    return 0;
}