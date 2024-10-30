#define MOD 1000000007
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, t, x;
int v[1000004], f[1000004], p[1000004];
long long s=0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> t;
    p[0] = 1;
    for(int i = 1 ; i < 1000004; i++){
        p[i] = (long long)(p[i - 1] * 2) % MOD;
    }
    for(int i = 1; i <= n; i++){
        cin >> x;
        f[x]++;
    }
    int k = 0;
    for(int i = 0; i < 1000004; i++){
        while(f[i]){
            k++;
            v[k] = i;
            f[i]--;
        }
    }
    int dr = 1;
    for(int i = 1; i <= n; i++){
        while(v[i]-v[dr] > t){
            dr++;
        }
        s = (s + (long long) p[i - dr] * v[i] ) % MOD;
    }
    dr = 1;
    for(int i = 1; i <= n; i++){
        if(dr < i){
            dr = i;
        }
        while(v[dr + 1] - v[i] <= t){
            if(dr < n){
                dr++;
            }else{
                break;
            }
        }
        s = s - ((long long) p[dr - i] * v[i]) % MOD;
        while(s < 0){
            s = MOD + s;
        }
    }
    cout << s;
    return 0;
}
