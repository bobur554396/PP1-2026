#include <iostream>

using namespace std;

int main() {
    string s1;
    string s2 = "hello";
    string s3("kbtu"); // using constructor

    s2 += " " + s3; // Concatenation/merge

    cout << s2 << endl;

    return 0;
}