#include <fstream>
using namespace std;
ifstream fin("pct.in");
ofstream fout("pct.out");
int n, k;
int s[2004][2004];
int vmax =0;
int main(){
    fin >> n >> k;
    for(int i = 1; i <= n; i++){
        int lin, col;
        fin >> lin >> col;
        s[lin+1][col+1]++;
    }
    for(int i = 1; i <= 1001; i++){
        for(int j = 1; j <= 1001; j++) {
            s[i][j] = s[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
            if(i == k && j == k){
                vmax = max(vmax, s[i][j]);
            }else if(i == k && j > k){
                vmax = max(vmax, s[i][j]-s[i][j-k-1]);
            }else if(i > k && j == k){
                vmax = max(vmax, s[i][j]-s[i-k-1][j]);
            }else if(i > k && j > k){
                vmax = max(vmax, s[i][j]+s[i-k-1][j-k-1]-s[i-k-1][j]-s[i][j-k-1]);
            }
        }
    }
    fout << vmax;
}
