#include <iostream>
#include <string>

using namespace std;

struct Student {
    // members/properties or fields
    string name;
    string id;
    double gpa;

    void read() {
        cin >> name >> id >> gpa;
    }

    void print() {
        cout << name << " " << id << " " << gpa << endl;
    }

};

bool byGpaDesc(const Student &a, const Student &b) {
    if (a.gpa != b.gpa) {
        return a.gpa > b.gpa;        // higher GPA first
    }
    return a.name < b.name;          // equal GPA: alphabetical
}
