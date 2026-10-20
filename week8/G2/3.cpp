#include <iostream>

using namespace std;

int main() {
    string s1;
    string s2 = "hello";
    string s3("kbtu"); // using constructor

    string s4 = s2; // copy string value
    s2[0] = 'a';

    cout << s4 << endl;
    cout << s2 << endl;



    return 0;
}