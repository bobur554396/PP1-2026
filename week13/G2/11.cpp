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

    int n;
    cin >> n;
    Student students[n];
    for(int i = 0; i < n; i++)
        students[i].read();

    for(int i = 0; i < n; i++)
        students[i].print();    
    
    return 0;
}