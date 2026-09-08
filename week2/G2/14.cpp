#include <iostream>

using namespace std;

int main() {
    // Loop - what I want to do something multiple times

    // i++ => i = i + 1


    /*
    1) i = 0; 0 < 5; true => cout "Hello World!" 
    2) i = 1; 1 < 5; true => cout "Hello World!"
    3) i = 2; 2 < 5; true => cout "Hello World!"
    4) i = 3; 3 < 5; true => cout "Hello World!"
    5) i = 4; 4 < 5; true => cout "Hello World!"
    6) i = 5; 5 < 5; false => exit loop
    */

    for(int i = 0; i <= 5; i++){
        cout << "i = " << i << ": " << "Hello World!" << endl;
    }

    return 0;
}