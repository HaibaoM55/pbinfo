#include <iostream>
#define MOD 1000000007
#define int long long
using namespace std;

int n;
int v[1000067];

long long invmodular(long long a, long long m){
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;
    if (m == 1) return 0;
    while (a > 1){
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
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }

    long long sum = (v[1] + v[n]) % MOD;
    int inv2 = invmodular(2, MOD);
    sum = (sum * inv2) % MOD;
    sum = (sum * n) % MOD;

    cout << sum;
    return 0;
}
