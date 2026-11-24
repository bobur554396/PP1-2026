#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    string id;
    double gpa;
};

int main() {
    Student s;
    cin >> s.name >> s.id >> s.gpa;

    cout << s.name << " " << s.id << " " << s.gpa << endl;
    return 0;
}