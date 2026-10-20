#include <iostream>

using namespace std;

int main() {
    string s1;
    string s2 = "hello";
    string s3("kbtu"); // using constructor


    string s4 = s2 + " " + s3; // concatination/merge

    cout << s4 << endl;
    cout << s4.size() << endl;


    return 0;
}