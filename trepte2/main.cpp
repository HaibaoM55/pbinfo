#include <iostream>
using namespace std;
#define MOD 9001
int n, k;
int dp[100004];
int s[100004];
int main(){
    cin >> n >> k;
    s[0] = 0;
    s[1] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = (s[i-1]-s[max(0, i-k-1)]+MOD)%MOD;
        s[i]  = (s[i-1]+dp[i])%MOD;
    }
    cout << dp[n];
    return 0;
}
