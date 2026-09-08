#include <iostream>

using namespace std;

int main() {

    // break; // exit from the loop
    // continue; // skip the current iteration and go to the next one

    for(int i = 0; i < 100; i++){
        cout << i << " ";
        if(i == 10){
            break; // manually stop the loop
        }
    }
    
    cout << endl;

    return 0;
}