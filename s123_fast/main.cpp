#include <iostream>
using namespace std;
long long n;
int dp[1400004];
int main(){
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    cin >> n;
    for(int i = 4; i <= 1334000; i++){
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
        dp[i] = dp[i]%4001;
        //fout << i << '=' << dp[i] << endl;
    }
    cout << dp[(n-1)%1334000+1];
    return 0;
}
