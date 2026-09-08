#include <iostream>

using namespace std;

int main() {

    // break; // exit from the loop
    // continue; // skip the current iteration and go to the next one
    // 5 % 2 = 1
    // 6 % 2 = 0
    // 8 % 2 = 0
    for(int i = 0; i < 100; i++){
        if(i % 2 == 0){
            continue; // skip current iteration
        }
        cout << i << " ";
    }
    
    cout << endl;

    return 0;
}