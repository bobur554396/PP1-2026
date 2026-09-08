#include <iostream>
#include <cmath>

using namespace std;

int main(){
    
    // - [ ] count number of dividers of N
    /*
    in: 2 13 3
    out: 4
    */
    int a, b, n;
    cin >> a >> b >> n;

    int count = 0;
    for(int i = a; i <= b; i++){
        if(i % n == 0){
            count++;
            cout << i << " ";
        }
    }
    cout << endl << count << endl;


    return 0;
}