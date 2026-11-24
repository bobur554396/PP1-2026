#include <iostream>

using namespace std;

struct Student { // own data type
    string name; // properties or fields
    string id;
    int age; 
    double gpa; 
};


int main() {
    // int a = 3;
    // int b[3] = {1, 2, 3};
    Student s;
    s.name = "Bob";
    s.id = "25B001";
    s.age = 20;
    s.gpa = 3.8;

    cout << s.name << " " << s.id << " " << s.age << " " << s.gpa << endl;    


    return 0;
}