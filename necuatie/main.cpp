#include <fstream>
using namespace std;
#define MOD 555557
ifstream cin("necuatie.in");
ofstream cout("necuatie.out");
long long v[2004], w[2004];
long long mod_inv(long long x) {
    long long a = x, b = MOD, u = 1, v = 0;
    while (b != 0) {
        long long q = a / b;
        a -= q * b;
        swap(a, b);
        u -= q * v;
        swap(u, v);
    }
    return (u + MOD) % MOD;
}
long long comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    return v[n] * w[k] % MOD * w[n - k] % MOD;
}
int n;
int main() {
    cin >> n;
    v[0] = 1;
    for (int i = 1; i <= n; ++i) {
        v[i] = v[i-1] * i % MOD;
    }
    w[n] = mod_inv(v[n]);
    for (int i = n - 1; i >= 0; --i) {
        w[i] = w[i+1] * (i+1) % MOD;
    }
    long long rasp = 1;
    for (int i = 1; i <= n/2; i++){
        rasp = (rasp+ comb(n, i) * comb(n - i, i)) % MOD;
    }

    cout << rasp;

    return 0;
}
