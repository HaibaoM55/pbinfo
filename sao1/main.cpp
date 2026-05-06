#include <fstream>
using namespace std;
ifstream fin("sao1.in");
ofstream fout("sao1.out");
int n, m;
long long a[504][504];
bool viz[504][504];
int nr = 0;
void fill(int i, int j, long long val){
    if(1 <= i && i <= n){
        if(1 <= j && j <= m){
            if(!viz[i][j] && a[i][j] == val){
                viz[i][j] = true;
                nr++;
                fill(i+1, j, val);
                fill(i-1, j, val);
                fill(i, j+1, val);
                fill(i, j-1, val);
            }
        }
    }
}
signed main(){
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> a[i][j];
        }
    }
    long long rasp = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!viz[i][j]){
                nr = 0;
                fill(i, j, a[i][j]);
                rasp = max(rasp, 1LL*nr*a[i][j]);
            }
        }
    }
    fout << rasp;
    return 0;
}
