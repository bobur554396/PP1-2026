#include <iostream>

using namespace std;

int main() {
    string line("KBTU"); // create string using constructor

    cout << line.size() << endl;
    cout << line.length() << endl;
    cout << line[0] << endl;
    cout << line[line.size() - 1] << endl;


    string line2 = line; // full copy of the value

    line[0] = 'A';

    cout << line2 << endl;


    return 0;
}