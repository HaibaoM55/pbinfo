#include <iostream>
using namespace std;
#define MOD 1000000007
#define int long long
int x, p, q;
int a, b;
bool ciur[1000004];
int nrp = 0, prm[1000004];
int f[1000004];
long long invmodular(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;
    if (m == 1) return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}
signed main(){
    cin >> x >> p >> q;
    for(int i = 2; i <= x; i++){
        if(ciur[i] == false){
            nrp++;
            prm[nrp] = i;
            f[i] = p+1;
            for(int j = i; j<=x/i; j++){
                ciur[j*i] = true;
            }
        }
    }
    long long nrf = 1;
    for(int i = 1; i <= nrp; i++){
        if(f[prm[i]] != 0){
            nrf = nrf*f[prm[i]];
            nrf = nrf%MOD;
        }
    }
    for(int i = 1; i <= q; i++){
        cin >> a >> b;
        if(b < f[a]){
            int mdv = nrf%f[a];
            nrf = nrf*invmodular(f[a], MOD);
            nrf = nrf%MOD;
            nrf = nrf*b;
            nrf = nrf%MOD;
            f[a] = b;
        }
        cout << nrf << '\n';
    }
    return 0;
}
