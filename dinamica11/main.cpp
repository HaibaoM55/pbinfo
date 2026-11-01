#include <iostream>
using namespace std;
#define MOD 666013;
int n;
long long dp[67];
int main(){
    /*dp[1] = 9;
    dp[2] = 74;
    dp[3] = 660;
    dp[4] = 5736;
    dp[5] = 50256;
    dp[6] = 439200;
    int nr = 0;
    for(int i = 10; i <= 99; i++){
        int x = i, lst = -1;
        bool ok = true;
        do{
            if(eprim(lst) && eprim(x%10)){
                ok = false;
            }
            lst = x%10;
            x = x/10;
        }while(x);
        if(ok) nr++;
    }
    cout << nr;*/
    cin >> n;
    dp[1]=5;
    dp[2]=4;
    for(int i = 2; i <= n; i++){
        int rst = dp[1]%MOD;
        dp[1] = (rst+dp[2])%MOD;
        dp[1] = (dp[1]*6)%MOD;
        dp[2] = (rst*4)%MOD;
    }
    cout << (dp[1]+dp[2])%MOD;
	return 0;
}
