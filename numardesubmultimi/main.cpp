#include <iostream>
using namespace std;
#define MOD 777013
int n;
int dp[100004];
int s[100004];
int main(){
    cin >> n;
    dp[n] = 1;
    dp[n-1]=1;
    s[n-1] = 2;
    int rasp = 2;
    for(int i = n-2; i >= 1; i--){
        s[i] = s[i+1];
        dp[i] = (1+s[i]-dp[i+1]+MOD)%MOD;
        s[i] += dp[i];
        s[i] = s[i]%MOD;
        rasp += dp[i];
        rasp = rasp%MOD;
    }
    cout << rasp;
    return 0;
}

