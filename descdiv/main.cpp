#include <iostream>
using namespace std;
#define MOD 123457
int n;
int nr = 0;
int dp[20004];
void bt(int x, int y, int vmax){
    if(x == 0){
        nr++;
    }
    for(int d = 1; d*d <= y && d <= x; d++){
        if(y % d == 0){
            if(d >= vmax){
                bt(x-d, y, d);
            }
            if(d*d < y && y/d <= x && y/d >= vmax){
                bt(x-(y/d), y, y/d);
            }
        }
    }
}
int main(){
    cin >> n;
    for(int x = 1; x <= n; x++){
        if(n % x == 0){
            dp[x]++;
            dp[x] = dp[x]%MOD;
            for(int i = x; i <= n; i++){
                dp[i] += dp[i-x];
                dp[i] = dp[i]%MOD;
            }
        }
    }
    cout << dp[n];
    return 0;
}
