#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    string id;
    double gpa;
};

int main() {
    freopen("input.txt", "r", stdin);

    Student s;
    cin >> s.name >> s.id >> s.gpa;

    cout << "Student: " << s.name << ", GPA: " << s.gpa << endl;
    return 0;
}