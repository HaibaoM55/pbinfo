#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("joc4.in");
ofstream fout("joc4.out");
int n, k;
int a[3][5004];
int dp[3][5004][12];
int main(){
    fin >> n >> k;
    for(int i = 1; i <= n; i++){
        fin >> a[1][i];
    }
    for(int i = 1; i <= n; i++){
        fin >> a[2][i];
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5004; j++){
            for(int t = 0; t < 12; t++){
                dp[i][j][t] = -2e9;
            }
        }
    }
    dp[1][1][1] = a[1][1];
    dp[2][1][1] = a[1][1] + a[2][1];
    for(int j = 2; j <= n; j++){
        for(int i = 1; i <= 2; i++){
            int o = 3 - i;
            for(int t = 2; t <= k; t++){
                if(dp[i][j-1][t-1] > -2e9/2){
                    dp[i][j][t] = dp[i][j-1][t-1] + a[i][j];
                }
            }
            int vmax = -2e9;
            for(int s = 2; s <= k; s++){
                if(dp[o][j-1][s-1] > -2e9/2){
                    vmax = max(vmax, dp[o][j-1][s-1] + a[o][j]);
                }
            }
            if(vmax > -2e9/2){
                dp[i][j][1] = vmax+a[i][j];
            }
        }
    }
    int rasp = -2e9;
    for(int t = 1; t <= k; t++){
        rasp = max(rasp, dp[2][n][t]);
    }
    fout << rasp;
    return 0;
}
