#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n); // n elements, all 0
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    // solution part
    
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }

    return 0;
}