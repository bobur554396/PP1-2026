#include <iostream>

using namespace std;

int main(){
    // - [ ] Linear search of K from given array
    /*
    Input:
    he2l8lo
    
    Output:
    2 8
    */
    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++){
        // cout << s[i] << " "; // s[i] - is "char"
        // cout << (int) s[i] << " "; // type casting/convert to int
        int code = (int)s[i];
        if(code >= 48 && code <= 57){
            cout << s[i] << " ";
        }
    }
    cout << endl;
    



    return 0;
}