#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
char x[39];
int z = 0, nrc=0;
int v[39], f[14];
long long fact[24];
void init_fact() {
    fact[0] = 1;
    for (int i = 1; i <= 20; i++)
        fact[i] = fact[i-1] * i;
}
long long countPerm(const int f[10], int n) {
    long long res = fact[n];
    for (int i = 0; i < 10; i++)
        res /= fact[f[i]];
    return res;
}
long long countNoLeadingZero(const int f[10]){
    int total = 0;
    for (int i = 0; i < 10; i++) total += f[i];
    long long ans = 0;
    for(int d = 1; d <= 9; d++){
        if (f[d] == 0) continue;
        int g[10];
        memcpy(g, f, sizeof(g));
        g[d]--;
        ans += countPerm(g, total - 1);
    }
    return ans;
}
int main(){
    cin >> x;
    int l = strlen(x);
    for(int i = 0; i < l; i++){
        f[x[i]-'0']++;
        nrc++;
    }
    if(nrc == 1){
        cout << 1;
        return 0;
    }
    bool ok = true;
    for(int i = 0; i <= 9; i++){
        if(ok && f[i] % 2 != 0){
            ok = false;
        }else if(!ok && f[i] % 2 != 0){
            cout << 0;
            return 0;
        }
        f[i] = f[i]/2;
    }
    init_fact();
    cout << countNoLeadingZero(f);
    return 0;
}
