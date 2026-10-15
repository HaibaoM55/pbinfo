#include <iostream>
#include <algorithm>
using namespace std;
int n;
int dp[5004][30];
int main(){
    cin >> n;
    for(int i = 1; i <= 26; i++){
        dp[1][i] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 26; j++){
            for(int k = 1; k <= 26; k++){
                if(abs(j-k) >= 2){
                    dp[i][j] += dp[i-1][k];
                    dp[i][j] = dp[i][j]%3444449;
                }
            }
        }
    }
    int rasp = 0;
    for(int i = 1; i <= 26; i++){
        rasp += dp[n][i];
        rasp = rasp%3444449;
    }
    cout << rasp;
    return 0;
}
