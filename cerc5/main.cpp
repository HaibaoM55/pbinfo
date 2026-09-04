#include <iostream>
#include <math.h>
using namespace std;
int n;
int v[40],f[40];
bool estepatrat(int x){
    int sq = sqrt(x);
    return sq*sq==x;
}
void bt(int k){
    if(k == n+1 && estepatrat(v[1]+v[n])){
        for(int i = 1; i <= n; i++){
            cout << v[i] << ' ';
        }
        exit(0);
    }
    for(int j = 1; j <= n; j++){
        if(f[j] == 0 && estepatrat(v[k-1]+j)){
            v[k] = j;
            f[j] = 1;
            bt(k+1);
            f[j] = 0;
        }
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        v[1] = i;
        f[i] = 1;
        bt(2);
        f[i] = 0;
    }
    cout << "nu exista";
    return 0;
}
