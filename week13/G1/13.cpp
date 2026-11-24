#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    string id;
    double gpa;

    void read(){
        cin >> name >> id >> gpa;
    }

    void print() {
        cout << name << " (" << id << ") " << gpa << endl;
    }
};

bool byGpaDesc(const Student &a, const Student &b) {
    if (a.gpa != b.gpa) {
        return a.gpa > b.gpa;        // higher GPA first
    }
    return a.name < b.name;          // equal GPA: alphabetical
}

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    Student arr[n];

    for(int i = 0; i < n; i++) {
        arr[i].read();
    }    

    sort(arr, arr + n, byGpaDesc);

    for (int i = 0; i < n; i++) {
        arr[i].print();
    }
    return 0;
}