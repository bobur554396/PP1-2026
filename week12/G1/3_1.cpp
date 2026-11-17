#include <iostream>
#include <stack>

using namespace std;

int main() {
    /*
    ()() - YES
    (()) - YES
    )() - NO
    (() - NO
    ))(( - NO
    ())(() - NO
    */
    string s;
    cin >> s;

    int cnt = 0; 
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(') cnt++;
        if(s[i] == ')'){
            if(cnt <= 0){
                cout << "NO" << endl;
                return 0;
            }
            cnt--;
        }
    }

    if(cnt == 0)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;


    return 0;
}