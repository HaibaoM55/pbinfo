#include <iostream>
using namespace std;
int a, r, n;
int main(){
    cin >> a >> r >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a + j*n*r<< ' ';
        }
        cout << '\n';
        a += r;
    }
    return 0;
}
