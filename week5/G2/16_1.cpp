#include <iostream>

using namespace std;

int main(){
    // - [ ] Linear search of K from given array
    /*
    Input:
    he2l8lo
    
    Output:
    28
    */
    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            cout << s[i] << " ";
        }
    }
    cout << endl;
    



    return 0;
}