#include <fstream>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define MOD 1000000007
ifstream fin("seqstr.in");
ofstream fout("seqstr.out");
int n, m;
bool a[5004], b[5004];
int dp[5004];
int cer;
int p, q;
map<vector<int>, bool> f;
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> a[i];
    }
    fin >> m;
    for(int i = 1; i <= m; i++){
        fin >> b[i];
    }
    fin >> cer;
    if(cer == 1){
        int nr = 0;
        set<vector<int>> rasp;
        for(int i = 1; i <= m; i++){
            int p1 = i;
            vector<int> fm(5004);
            for(int k = 1; k <= n; k++){
                if(a[k] == b[p1]){
                    p1++;
                    fm[p1-i] = b[p1-1]+1;
                    rasp.insert(fm);
                }
                if(p1 == m+1){
                    break;
                }
            }
        }
        fout << rasp.size();
    }else if(cer == 2){
        fin >> p >> q;
        int l = q-p+1;
		dp[0] = 1;
		for(int i = 1; i <= n; i++){
			for(int j = l; j >= 1; j--){
				if(a[i] == b[p+j-1]){
                    dp[j] = (dp[j] + dp[j-1])%MOD;
                }
			}
		}
		fout << dp[l];
    }else{
        long long ans = 0;
        set<vector<int>> gasit;
        int maxl = m;
        vector<vector<long long>> dp(m+1, vector<long long>(m+1, 0));
        for(int p = 1; p <= m; p++) dp[p][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int p = 1; p <= m; p++){
                for(int j = m - p + 1; j >= 1; j--){
                    if(a[i] == b[p + j - 1]){
                        dp[p][j] = (dp[p][j] + dp[p][j-1]) % MOD;
                    }
                }
            }
        }
        for(int p = 1; p <= m; p++){
            vector<int> pat;
            for(int q = p; q <= m; q++){
                pat.push_back(b[q]);
                if(!gasit.count(pat)){
                    gasit.insert(pat);
                    int l = q - p + 1;
                    ans = (ans + dp[p][l]) % MOD;
                }
            }
        }
        fout << ans;
    }
    return 0;
}
