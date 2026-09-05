#include <iostream>
using namespace std;
int n, f[14], v[14];
void bt(int k){
    bool nmc = true;
    for(int i = 1; i <= n; i++){
        if(f[i] < i){
            nmc = false;
            f[i]++;
            v[k] = i;
            bt(k+1);
            f[i]--;
        }
    }
    if(nmc){
        for(int i = 1; i < k; i++){
            cout << v[i];
        }
        cout << '\n';
    }
}
int main(){
    cin >> n;
    bt(1);
    return 0;
}
