#include <iostream>
#include <string>

using namespace std;

struct Student {
    // members/properties or fields
    string name;
    string id;
    double gpa;
};                       // note the semicolon after the closing brace

int main() {
    // string names[10];
    // string ids[10];
    // double gpa[10]
    // int a;

    Student s;
    s.name = "Bob";
    s.id = "25B001";
    s.gpa = 3.8;

    cout << s.name << " " << s.id << " " << s.gpa << endl;
    
    return 0;
}