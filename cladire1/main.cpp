#include <fstream>
using namespace std;
ifstream fin("cladire1.in");
ofstream fout("cladire1.out");
int n, m;
int k, x, y;
bool a[1004][1004];
int dp[1004][1004];
int nr = 0;
void fill(int i, int j){
    if(a[i][j]){
        return;
    }
    if(i > n){
        return;
    }
    if(j > m){
        return;
    }
    dp[i][j]++;
    if(i == n && j == m){
        nr++;
        return;
    }
    fill(i+1, j);
    fill(i, j+1);
}
int main(){
    fin >> n >> m;
    fin >> k;
    for(int i = 1; i <= k; i++){
        fin >> x >> y;
        a[x][y] = true;
    }
    //fill(1, 1);
    dp[1][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(i == 1 && j == 1){
                continue;
            }
            if(a[i][j]){
                continue;
            }
            dp[i][j] = dp[i-1][j]+dp[i][j-1];
            dp[i][j] = dp[i][j]%9901;
        }
    }
    fout << dp[n][m]%9901;
    return 0;
}
