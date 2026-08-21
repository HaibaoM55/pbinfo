#include <fstream>
#include <bitset>
using namespace std;
ifstream fin("drumuri.in");
ofstream fout("drumuri.out");
int n, m, x, y;
int f[150004];
bitset<704> b1[704], b2[704];
bool viz1[704], viz2[704];
void visit1(int k){
    for(int i = 1; i <= n; i++){
        if(b1[k][i]){
            if(!viz1[i]){
                viz1[i] = true;
                visit1(i);
            }
            b1[k] = b1[k] | b1[i];
        }
    }
}void visit2(int k){
    for(int i = 1; i <= n; i++){
        if(b2[k][i]){
            if(!viz2[i]){
                viz2[i] = true;
                visit2(i);
            }
            b2[k] = b2[k] | b2[i];
        }
    }
}
int nr = 0;
int v[704];
int main(){
    fin >> n >> m;
    if(n <= 700){
        for(int i = 1; i <= m; i++){
            fin >> x >> y;
            b1[x][y] = true;
            b2[y][x] = true;
        }
        for(int i = 1; i <= n; i++){
            if(!viz1[i]){
                viz1[i] = true;
                visit1(i);
            }
            if(!viz2[i]){
                viz2[i] = true;
                visit2(i);
            }
            bool ok = true;
            for(int j = 1; j <= n; j++){
                if(!b1[i][j] && !b2[i][j] && j != i){
                    ok = false;
                }
            }
    //        for(int j = 1; j <= n; j++){
    //            fout << b1[i][j] << ' ';
    //        }
    //        fout << '\n';
    //        for(int j = 1; j <= n; j++){
    //            fout << b2[i][j] << ' ';
    //        }
    //        fout << '\n';
    //        fout << '\n';
            if(ok){
                nr++;
                v[nr] = i;
            }
        }
        fout << nr << '\n';
        for(int i = 1; i <= nr; i++){
            fout << v[i] << ' ';
        }
    }else{
        int nr = 0;
        for(int i = 1; i <= n; i++){
            fin >> x >> y;
            f[x]++;
            f[y]++;
            if(f[x] == n){
                nr++;
            }
            if(f[y] == n){
                nr++;
            }
        }
        fout << nr << '\n';
        for(int i = 1; i <= n; i++){
            if(f[i] == n){
                fout << i << ' ';
            }
        }
    }
    return 0;
}
