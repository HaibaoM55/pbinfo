#include <iostream>
using namespace std;
int n, k;
int dp[1000004];
void dof(int x){
    for(int i = x+1; i <= k; i++){
        dp[i]++;
        dof(i);
    }
}
int main(){
    cin >> n >> k;
    //cout << sizeof(dp);
    dp[1] = 1;
    dp[2] = 1;
    for(int i = 3; i <= k; i++){
        dp[i] = dp[i-1]*2;
        dp[i] = dp[i]%9001;
    }
    for(int i = k+1; i <= n; i++){
        dp[i] = (2*dp[i-1]-dp[i-k-1]+9001)%9001;
    }
    cout << dp[n];
    return 0;
}
