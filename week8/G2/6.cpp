#include <iostream>

using namespace std;

int main() {
    string s1;
    string s2 = "hello";
    string s3("kbtu"); // using constructor

    if(s2 == s3)
        cout << "equal" << endl;

    if(s2 != s3)
        cout << "not equal" << endl;

    // lexicagraphicaly comparision
    cout << ('A' > 'B') << endl;

    cout << (s2 > s3) << endl;

    return 0;
}