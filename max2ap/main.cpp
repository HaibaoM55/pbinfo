#include <iostream>
using namespace std;
int n, m, x;
int f[1000004];
int main(){
    cin >> n >> m;
    for(int i= 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> x;
            f[x]++;
        }
    }
    for(int i = 1000000; i >= 0; i--){
        if(f[i] >= 2){
            cout << i;
            return 0;
        }
    }
    cout << "IMPOSIBIL";
    return 0;
}
