#include <iostream>
#include <string>
#include <algorithm>
#include "student.h"

using namespace std;

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