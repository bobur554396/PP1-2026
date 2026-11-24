#include <iostream>
#include <string>
#include "student.h"

using namespace std;

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