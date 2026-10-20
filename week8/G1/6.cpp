#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "Hello";

    // int n = s.size();
    for(int i = 0; i < s.size(); i++) {
        cout << s[i] << " "; // s[i] is here as "char"
    }

    return 0;
}