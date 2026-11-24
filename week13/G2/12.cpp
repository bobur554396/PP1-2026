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

bool byGpaDesc(Student &a, Student &b) {
    if (a.gpa != b.gpa) {
        return a.gpa > b.gpa;        // higher GPA first
    }
    return a.name < b.name;          // equal GPA: alphabetical
}

bool cmp(int a, int b){
    return a > b;
}

int main() {
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    Student students[n];
    for(int i = 0; i < n; i++)
        students[i].read();

    
    sort(students, students + n, byGpaDesc);

    for(int i = 0; i < n; i++)
        students[i].print();    
    
    return 0;
}