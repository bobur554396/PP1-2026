#include <iostream>
#include <string>

using namespace std;

struct Student {
    // properties or fields
    string name;
    string id;
    double gpa;

    // member function
    void print() {                  
        cout << name << " (ID: " << id << ") GPA: " << gpa << endl;
    }

    bool isExcellent() {
        return gpa >= 3.67;
    }
};

int main() {
    Student s = {"Bob", "25B001", 3.9};    // members in declaration order

    s.print();
    cout << (s.isExcellent() ? "excellent" : "not excellent") << endl;
    return 0;
}