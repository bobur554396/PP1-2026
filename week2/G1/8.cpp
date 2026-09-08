#include <iostream>

using namespace std;

int main() {
    /*
    AND (&&): Returns true only if both conditions are true
    OR (||): Returns true if at least one condition is true
    XOR (^): Returns true if exactly one condition is true (exclusive or)
    NOT (!): Reverses the boolean value    
    */

    bool a = true, b = false;
    cout << (a && b) << endl;  // 0 (false)
    cout << (a || b) << endl;  // 1 (true)
    cout << (a ^ b) << endl;   // 1 (true)
    cout << (!a) << endl;      // 0 (false)

    return 0;
}