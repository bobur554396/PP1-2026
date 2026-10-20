#include <iostream>
#include <string>

using namespace std;

int main() {
    // Palindrome
    /*
    YES:
    aba
    abba
    abcba

    NO:
    abc
    bacb
    */
    string s;
    cin >> s;

    int n = s.size();
    for(int i = 0; i < n / 2; i++){
        // 0 <-> s.size() - 1 - 0
        // 1 <-> s.size() - 1 - 1
        // 2 <-> s.size() - 1 - 2
        // i <-> s.size() - 1 - i
        if(s[i] != s[n - 1 - i]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    


    return 0;
}