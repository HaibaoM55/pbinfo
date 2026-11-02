#include <fstream>
using namespace std;
ifstream fin("fractii2.in");
ofstream fout("fractii2.out");
#define MOD 100003
int cer, n;
int dp[4004][4004];
int main(){
    fin >> cer;
    fin >> n;
    if(cer == 1){
        for(int i = 1; i <= n-1; i++){
            fout << i << ' ';
        }
        fout << n-1;
    }else{
        dp[2][1] = 1;
        for(int i = 1; i <= n; i++){
            dp[i][i] = 1;
        }
        dp[2][2] = 1;
        for(int i = 3; i <= n; i++){
            for(int j = i-1; j >= 1; j--){
                dp[i][j] = dp[i-1][j-1]+dp[i][j*2];
                dp[i][j] = dp[i][j]%MOD;
            }
        }
        fout << dp[n][1];
    }
    return 0;
}
