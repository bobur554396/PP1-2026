#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string data = "Alice 25 1.75";

    stringstream ss(data);

    string name;
    int age;
    double height;

    ss >> name >> age >> height;

    cout << "Name: " << name << endl;
    cout << "Age: " << age + 1 << endl;
    cout << "Height: " << height + 0.4<< endl;

    return 0;
}