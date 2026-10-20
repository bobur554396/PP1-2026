#include <iostream>
#include <sstream> // stringstream

using namespace std;

int main() {
    int num = 255;
    stringstream ss;

    ss << num;

    string n;
    ss >> n; // n = "255"

    n += '!';
    cout << n << endl;


    return 0;
}