#include <iostream>
#include <bitset>

using namespace std;

int main(){
    // << - left shift;    
    // >> - right shift
    int a = 3;
    int b = 3 << 5;
    bitset<32> b1(a);
    bitset<32> b2(b);

    cout << b1 << " " << a << endl ;
    cout << b2 << " " << b << endl;

    return 0;
}