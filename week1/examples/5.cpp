#include <iostream>

using namespace std;

int main() {
    // line comment

    /*
    multi 
    line 
    comment
    */


    /*
    Allowed Characters
        Letters: a–z, A–Z
        Digits: 0–9 (but not as the first character)
        Underscore: _
    
    */

    // int 1num; error
    // int 3; error
    // int my-number; error
    int my_number; // ok
    int myNumber; // ok
    int a, A; // ok
    // int my number; error
    int _count;
    // int char; error
    // int return; error

    int age = 20;
    double pi = 3.14159;
    float rate = 0.95f;
    char grade = 'A';
    bool isOnline = true;

    

    return 0;
}
