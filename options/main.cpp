#include <iostream>
using namespace std;
#define MOD 666013
long long dp[104], ndp[104];
int l, k;
int grila[104][104];
char s[104];
long long x, c;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> l >> k;
    for(int i = 0; i < l; i++){
        cin >> s;
        for(int j = 0; j < k; j++){
            grila[i][j] = s[j]-'0';
        }
    }
    cin >> x >> c;
    x--;
    if(grila[0][0]){
        dp[0] = 1;
    }
    for(int col = 1; col < c; col++){
        int idx = col % k;
        for(int i = 0; i < l; i++){
            ndp[i] = 0;
        }
        for(int i = 0; i < l; i++){
            if(!dp[i]){
                continue;
            }
            for(int dr = -1; dr <= 1; dr++){
                int ni = i + dr;
                if(0 <= ni && ni < l && grila[ni][idx]){
                    ndp[ni] = (ndp[ni] + dp[i]) % MOD;
                }
            }
        }
        for(int i = 0; i < l; i++){
            dp[i] = ndp[i];
        }
    }
    cout << dp[x];
    return 0;
}
