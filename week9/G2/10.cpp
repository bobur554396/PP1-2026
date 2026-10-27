#include <iostream>

using namespace std;

float max(float a, float b){
    if(a > b)
        return a;
    return b;
}

int main() {
    
    cout << max(10, 20) << endl;


    return 0;
}
