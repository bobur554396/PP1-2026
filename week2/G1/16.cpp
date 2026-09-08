#include <iostream>

using namespace std;

int main() {
    // Loop - doing some tasks several times / repeat code 

    // i++ = i = i + 1


    /*
    1) i = 0; 0 < 5;
    2) i = 1; 1 < 5;
    3) i = 2; 2 < 5;
    4) i = 3; 3 < 5;
    5) i = 4; 4 < 5;
    6) i = 5; 5 < 5; false - exit loop

    */
    for (int i = 0; i < 5; i++) {
        cout << "i = " << i << ": Hello, World!" << endl;
    }
    
    

    return 0;
}