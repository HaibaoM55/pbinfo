#include <fstream>
#include <map>
using namespace std;
ifstream fin("soarece.in");
ofstream fout("soarece.out");
int n, m;
int i1, j1, in, jn;
int dirx[6] = {-1,1,0,0};
int diry[7] = {0,0,1,-1};
int a[67][41];
int nr = 0;
map<pair<int, int>, bool> clearv;
void fill(int i, int j, map<pair<int, int>, bool> f){
    if(i == in && j == jn){
        nr++;
        return;
    }
    for(int d = 0; d < 4; d++){
        int ix = i+dirx[d];
        int jx = j+diry[d];
        if(1 <= ix && ix <= n){
            if(1 <= jx && jx <= m){
                if(!f[{ix, jx}] && !a[ix][jx]){
                    f[{ix, jx}] = true;
                    fill(ix, jx, f);
                    f[{ix, jx}] = false;
                }
            }
        }
    }
}
int main(){
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> a[i][j];
        }
    }
    fin >> i1 >> j1 >> in >> jn;
    clearv[{i1, j1}] = true;
    fill(i1, j1, clearv);
    fout << nr;
    return 0;
}
