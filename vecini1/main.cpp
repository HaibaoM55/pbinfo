#include <fstream>
using namespace std;
ifstream fin("vecini1.in");
ofstream fout("vecini1.out");
int n, m;
int a[104][104];
int dirx[5] = {1,-1,0, 0};
int diry[5] = {0, 0,1,-1};
int v[5];
bool exista(int x, int y){
    if(1 <= x && x <= n){
        if(1 <= y && y <= m){
            return true;
        }
    }
    return false;
}
int main(){
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> a[i][j];
        }
    }
    int nr = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int z = 0;
            for(int d = 0; d < 4; d++){
                int i1 = i+dirx[d];
                int j1 = j+diry[d];
                if(exista(i1, j1)){
                    z++;
                    v[z] = a[i1][j1];
                }
            }
            bool ok = true;
            for(int k = 1; k < z; k++){
                for(int k1 = k+1; k1 <= z; k1++){
                    if(v[k] == v[k1]){
                        ok = false;
                        break;
                    }
                }
            }
            if(ok){
                nr++;
            }
        }
    }
    fout << nr;
    return 0;
}
