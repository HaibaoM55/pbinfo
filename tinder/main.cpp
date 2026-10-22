#include <iostream>
using namespace std;
int n, vmax, x, y;
int dp[10004];
int main(){
    cin >> n >> vmax;
    for(int i = 1; i <= n; i++){
        cin >> x >> y;
        for(int j = vmax; j >= y; j--){
            dp[j] = max(dp[j], dp[j-y]+x);
        }
    }
    cout << dp[vmax];
    return 0;
}
