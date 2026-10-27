#include <iostream>

using namespace std;

char toLower(char c){
    // if(c >= 'A' && c <= 'Z')
    int code = (int)c;
    if(code >= 65 && code <= 90){
        code = code + 32;
    }
    return (char)code;
}



int main() {
    // char c = 'A'; // 65 + 32
    // 'a' - 97
    char c;
    cin >> c;

    cout << toLower(c) << endl;

    return 0;
}