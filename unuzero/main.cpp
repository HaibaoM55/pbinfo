#include <fstream>
using namespace std;
ifstream fin("unuzero.in");
ofstream fout("unuzero.out");
int n;
int p, q;
int nr = 0;
int dp[1000004];
long long s[1000004];
int main(){
    fin >> n;
    fin >> p >> q;
    dp[0] = 1;
    s[0] = 1;
    for(int i = 1; i <= n+1; i++){
        dp[i] = dp[i-1] % 666013;
        if(i-p-1 >= 0){
            dp[i] += s[i-p-1];
        }
        if(i-q-2 >= 0){
            dp[i] -= s[i-q-2];
        }
        dp[i] = dp[i] % 666013;
        s[i] = s[i-1]+dp[i];
        s[i] = s[i]%666013;
    }
    fout << (dp[n+1]+666013-1)%666013;
    return 0;
}
