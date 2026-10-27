#include <iostream>

using namespace std;

bool isDigit1(char c){
    int code = (int) c;
    if(code >= 48 && code <= 57)
        return true;
    return false;
}

bool isDigit2(char c){
    if(c >= '0' && c <= '9')
        return true;
    return false;
}

bool isDigit(char c){
    return c >= '0' && c <= '9';
}

int main() {
    // isDigit
    char c;
    cin >> c;

    if(isDigit(c))
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
    

    return 0;
}
