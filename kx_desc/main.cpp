#include <fstream>
using namespace std;
ifstream fin("desc.in");
ofstream fout("desc.out");
#define int long long
#define MOD 10007
int n, k, x;
int dp[1000005];
signed main(){
    fin >> n >> k >> x;
    dp[0] = 1;
    n -= k;
    n -= k*(k-1)*x/2;
    for(int i = 1; i <= k; i++){
        for(int j = i; j <= n; j++){
            dp[j] = (dp[j]+dp[j-i])%MOD;
        }
    }
    fout << dp[n];
    return 0;
}
