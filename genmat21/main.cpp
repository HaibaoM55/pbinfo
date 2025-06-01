#include <iostream>
using namespace std;
int n;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int nr = n;
        for(int j = i; j <= n; j++){
            cout << j << ' ';
            nr--;
        }
        for(int j = 1; j <= nr; j++){
            cout << n-j << ' ';
        }
        cout << '\n';
    }
    return 0;
}
