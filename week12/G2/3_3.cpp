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
    ())(() - NO
    ))(( - NO
    */
    string s;
    cin >> s;
    stack<char> st;
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(') 
            st.push(s[i]);
        else {
            if(st.empty()) {
                cout << "NO" << endl;
                return 0;
            }
            st.pop();
        }
    }

    if(st.empty())
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
    
    



    return 0;
}