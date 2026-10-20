#include <iostream>

using namespace std;

int main() {
    string s1;
    string s2 = "hello";
    string s3("kbtu"); // using constructor


    string s4 = s2 + " " + s3; // Concatenation/merge

    cout << s4 << endl;
    cout << s4.size() << endl;

    cout << s4.empty() << endl;
    cout << s1.empty() << endl;

    cout << (s4.size() == 0) << endl;
    cout << (s1.size() == 0) << endl;


    return 0;
}