#include <iostream>
using namespace std;
int n;
int dp[100004];
int main(){
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    cin >> n;
    for(int i = 4; i <= n; i++){
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
        dp[i] = dp[i]%4001;
    }
    cout << dp[n];
    return 0;
}
