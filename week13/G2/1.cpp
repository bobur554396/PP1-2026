#include <iostream>

using namespace std;

int main(){
    int a = 2;
    int* p = &a;

    cout << &a << endl;
    cout << *p << endl;

    return 0;
}