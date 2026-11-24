#include <iostream>

using namespace std;

int main(){
    int a = 2;
    int* p = &a;

    *p = 5;
    // a = 5;

    cout << a << endl;

    return 0;
}