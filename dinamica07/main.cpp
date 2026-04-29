#include <iostream>
using namespace std;
#define MOD 1000000007
int n, p, q;
int fact[1000004];
int invers(int b){
    long long rasp=1;
    int rr = MOD-2;
    while(rr){
        if(rr % 2 == 1){
            rasp=(1LL*rasp*b)%MOD;
        }
        b=(1LL*b*b)%MOD;
        rr = rr/2;
    }
    return rasp;
}
int C(int x, int y){
    return (1LL*(1LL*fact[x]*invers(fact[x-y]))%MOD*invers(fact[y]))%MOD;
}
int main(){
    cin >> n >> p >> q;
    fact[0] = 1;
    for(int i = 1; i <= n; i++){
        fact[i] = (1LL*fact[i-1]*i)%MOD;
    }
    int rasp = 0;
    for(int k = p; k <= q; k++){
        rasp += C(n, k);
        rasp = rasp%MOD;
    }
    cout << rasp;
    return 0;
}
