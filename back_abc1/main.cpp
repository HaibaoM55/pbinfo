#include <iostream>
using namespace std;
char x, y;
int n, m;
char v[24];
void bt(int k, int vmax){
    if(k == n+1){
        for(int i = 1; i <= n; i++){
            cout << v[i];
        }
        cout << '\n';
        return;
    }
    for(int i = vmax+1; i < m; i++){
        v[k] = i+'A';
        bt(k+1, i);
    }
}
int main(){
    cin >> m >> n;
    bt(1, -1);
    return 0;
}
