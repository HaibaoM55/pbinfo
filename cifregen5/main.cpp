#include <iostream>
using namespace std;
int n;
int v[30];
void bt(int k){
    if(k == n+1){
        if(v[1] == v[n]){
            for(int i = 1; i <= n; i++){
                cout << v[i];
            }
            cout << '\n';
        }
        return;
    }
    if(v[k-1] == 0){
        v[k] = 1;
        bt(k+1);
    }else{
        v[k] = v[k-1]-1;
        bt(k+1);
        v[k] = v[k-1]+1;
        bt(k+1);
    }
}
int main(){
    cin >> n;
    v[1] = 0;
    bt(2);
    return 0;
}
