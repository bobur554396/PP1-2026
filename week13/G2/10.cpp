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

int main() {
    freopen("input.txt", "r", stdin);
    
    // int a;
    // string s;
    // s.size();
    
    Student s;
    s.read();
    s.print();
    
    return 0;
}