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
    Student s;
    cin >> s.name >> s.id >> s.gpa;

    cout << s.name << " " << s.id << " " << s.gpa << endl;
    
    return 0;
}