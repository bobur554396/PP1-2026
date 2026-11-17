#include <iostream>
#include <stack>

using namespace std;

int main() {
    /*
    3
    5 4 8

    8 4 5
    */
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i]; 
    }
    
    reverse(a, a + n);

    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl; 
    


    return 0;
}