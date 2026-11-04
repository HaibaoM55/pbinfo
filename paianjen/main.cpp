#include <iostream>
using namespace std;
int n, m;
int dp[11][11];
int main(){
    cin >> n >> m;
    dp[1][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(i == 1 && j == 1) continue;
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    cout << dp[n][m];
    return 0;
}
