#include <iostream>

using namespace std;

int main() {
    string line = "KBTU";

    cout << line.size() << endl;
    cout << line.length() << endl;
    cout << line[0] << endl;
    cout << line[line.size() - 1] << endl;


    return 0;
}