#include <iostream>
using namespace std;
char x, y;
int n, m;
char v[30];
bool b[30];
void bt(int k){
    if(k == n+1){
        for(int i = 1; i <= n; i++){
            cout << v[i];
        }
        cout << '\n';
        return;
    }
    for(int i = 0; i < m; i++){
        if(!b[i]){
            b[i] = true;
            v[k] = i+'A';
            bt(k+1);
            b[i] = false;
        }
    }
}
int main(){
    cin >> m >> n;
    bt(1);
    return 0;
}
