#include <iostream>
#include <algorithm>
using namespace std;
int v[10];
int n, m;
void bt(int k, int lst){
    if(k == n+1){
        for(int i = 1; i <= n; i++){
            cout << v[i];
        }
        cout << '\n';
        return;
    }
    for(int i = 0; i < m; i++){
        if(abs(i-lst) >= 2){
            v[k] = i;
            bt(k+1, i);
        }
    }
}
int main(){
    cin >> n >> m;
    bt(1, -1);
}
