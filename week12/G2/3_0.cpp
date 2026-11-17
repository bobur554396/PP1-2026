#include <iostream>
#include <stack>

using namespace std;

int main() {
    /*
    (x+2)*7+(3+y) - YES
    (x+3+y) - YES
    (x+(3+y)*2/z) - YES

    (x+(3+y)*2 - NO
    (x+3+y)*2) - NO
    x+3+y)*2) - NO

    ()() - YES
    () - YES
    (()) - YES
    (() - NO
    ()) - NO
    )) - NO
    */
    string s;
    cin >> s;
    
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(') cnt1++;
        if(s[i] == ')') cnt2++;
    }

    if(cnt1 == cnt2)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
    
    



    return 0;
}