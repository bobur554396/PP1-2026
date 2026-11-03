#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v;                      // empty
    vector<int> a(5);                   // 5 elements, all 0
    vector<int> b(5, 2);                // 5 elements, all 2
    vector<int> c = {1, 2, 3, 4, 5};    // listed values    
    

    for(int i = 0; i < c.size(); i++){
        cout << c[i] << " ";
    }
    cout << endl;

    return 0;
}