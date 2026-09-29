#include <iostream>

using namespace std;

int main(){
    // - [ ] What is an array?
    int n1 = 3;
    int n2 = 5;
    int n3 = 6;
    /*

    n1 - []

       address - 0x. 0x. 0x. 0x. 
    a: values  - [3] [5] [4] [7]
       indexes -  0   1   2   3 
    How we can create an array?

    data_type arr_name[size_of_the_array];
    */
    int a[4];
    a[0] = 3; // assign/update
    a[1] = a[0] + 2;
    a[2] = 4;
    a[3] = 7;

    cout << a[0] << endl; // accessing the value
    cout << a[1] << endl;
    cout << a[2] << endl;
    cout << a[3] << endl;

    // cout << a[4]; // error




    return 0;
}