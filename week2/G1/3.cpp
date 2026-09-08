#include <iostream>

using namespace std;

int main() {

    /*
    Variables are used to store data in a program. Each variable has a specific data type that determines the kind of data it can hold. Here are some common data types in C++:

    int: Whole numbers (e.g., 5, -10, 0)
    double/float: Decimal/Real numbers (e.g., 3.14, -2.5)
    bool: true (1) or false (0) values
    char: Single characters (e.g., 'A', '5', '@')
    string: Text/sequences of characters (e.g., "Hello World")    
    */

    // - [x] data type sizeof

    /*
    1 byte = 8 bits
    [][][][][][][][] = 1 byte

    int = 4 bytes = 32 bits
    4 bytes = [][][][][][][][][][][][][][][][0][0][1][1] = 1*2^0 + 1*2^1 + 0*2^2 ... = 2
    
    
    bool - can store only two values: true (1) or false (0). It is typically used for logical operations and conditions. The size of a bool variable is usually 1 byte, but it can vary depending on the compiler and platform.
    */

    int a = 3;
    int b = 2;
    double c = 3.14;
    float d = -2.5;
    char e1 = 'A';
    char e2 = 'r';
    char e3 = ' ';
    char e4 = '4';
    char e5 = '&';
    bool f1 = true; // f1 = 1 = [0][0][0][0][0][0][0][1]
    bool f2 = false; // f2 = 0 = [0][0][0][0][0][0][0][0]
    string g = "Hello KBTU!";
    string g2 = "Ar 4&";

    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;
    cout << "Size of float: " << sizeof(float) << " bytes" << endl;
    cout << "Size of char: " << sizeof(char) << " bytes" << endl;
    cout << "Size of bool: " << sizeof(bool) << " bytes" << endl;
    cout << "Size of string: " << sizeof(string) << " bytes" << endl;

    return 0;
}