#include <iostream>
using namespace std;
#define NMAX 200005
#define MOD 1000000007
int n, q, t;
long long l,r,val;
long long a[200005], s, p;
int main() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    while(q){
        cin >> t >> l >> r;
        l++;
        r++;
        if(t == 1){
            cin >> val;
            for(int i = l; i <= r; i++){
                a[i] = val;
            }
        }else{
            s = 0;
            p = 1;
            for(long long i = l; i <= r; i++){
                p = (1LL*p*(a[i]+1))%MOD;
                s = (s+((((i-l+1)*(r-i+1))%MOD)*a[i])%MOD)%MOD;
            }
            cout << (1LL*(1LL*(s*p)%MOD)*500000004)%MOD << '\n';
        }
        q--;
    }
    return 0;
}
