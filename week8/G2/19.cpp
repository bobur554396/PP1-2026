#include <iostream>
#include <sstream> // stringstream

using namespace std;

int main() {
    string name = "Alice";
    int age = 25;
    double height = 1.75;

    stringstream ss;
    ss << "Name: " << name << ", Age: " << age << ", Height: " << height;

    string result = ss.str();
    cout << result << endl;

    return 0;
}