#include <iostream> // input / output stream

using namespace std; // we want to use standard library

int main(){

    /*
    Data Types:

    int: Whole numbers (e.g., 5, -10, 0)
    double/float: Decimal numbers (e.g., 3.14, -2.5)
    bool: true or false values
    char: Single characters (e.g., 'A', '5', '@')
    string: Text/sequences of characters (e.g., "Hello World")    
    */

    /*
    1 byte = 8 bits => [][][][][][][][]

    int = 4 bytes = 32 bits => [][][][][][][][] [][][][][][][] [][][][][][][] [][][][][][][]
    */
    
    cout << "sizeof(int): " << sizeof(int) << " bytes" << endl;
    cout << "sizeof(double): " << sizeof(double) << " bytes" << endl;
    cout << "sizeof(float): " << sizeof(float) << " bytes" << endl;
    cout << "sizeof(bool): " << sizeof(bool) << " bytes" << endl;
    cout << "sizeof(char): " << sizeof(char) << " bytes" << endl;
    cout << "sizeof(string): " << sizeof(string) << " bytes" << endl;

    return 0;
}
