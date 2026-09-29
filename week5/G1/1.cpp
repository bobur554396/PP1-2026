#include <iostream>

using namespace std;

int main(){
    // - [ ] What is an array?
    int n1 = 3;
    int n2 = 6;
    int n3 = 1;
    /*
    n1 - []
    n2 - []

    How we can create an array?

    data_type arr_name[size_of_the_array];
    */
    char str[10];       // Array of 10 characters
    double prices[100]; // Array of 100 doubles
    int arr[4];
    /*
         address-  0x. 0x. 0x. 0x.
    arr: values -  [3] [6] [1] [7]
         index  -   0   1   2   3
    */
    arr[0] = 3; // assign/update the value
    arr[1] = arr[0] * 2;
    arr[2] = 1;
    arr[3] = 7;

    cout << *(arr + 0) << endl;
    cout << *(arr + 1) << endl;
    cout << *(arr + 2) << endl;
    cout << *(arr + 3) << endl;
    // cout << *(arr + 4) << endl;




    return 0;
}