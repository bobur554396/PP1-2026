#include <iostream>

using namespace std;

char toUpper1(char c){
    int code = (int) c;
    if(code >= 97 && code <= 122){
       code -= 32; 
    }
    return (char)code;
}
char toUpper(char c){
    if(c >= 'a' && c <= 'z'){
       c -= 32; 
    }
    return c;
}

int main() {
    char c;
    cin >> c; // 'a'

    cout << toUpper(c) << endl;
    

    return 0;
}
