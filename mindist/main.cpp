#include <fstream>
using namespace std;
ifstream fin("mindist.in");
ofstream fout("mindist.out");
int n, m, k;
int a[1004][1004];
int dirx[5] = {0, 0, -1, 1};
int diry[5] = {1, -1, 0, 0};
int x, y;
struct coada{
    int i, j, pasi=0;
}c[1000004];
int st = 1, dr = 0;
int pasimin = 1e9;
int pasi[1004][1004];
int main(){
    fin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        fin >> x >> y;
        a[x][y] = -1;
    }
    for(int i = 1; i <= k; i++){
        fin >> x >> y;
        a[x][y] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j] == 1){
                dr++;
                c[dr].i = i;
                c[dr].j = j;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j] == 1){
                pasi[i][j] = 0;
            }else{
                pasi[i][j] = -1;
            }
        }
    }
    while(st <= dr){
        for(int i = 0; i < 4; i++){
            int i1 = c[st].i+dirx[i];
            int j1 = c[st].j+diry[i];
            if(1 <= i1 && i1 <= n){
                if(1 <= j1 && j1 <= n){
                    if(a[i1][j1] == 0){
                        dr++;
                        c[dr].i = i1;
                        c[dr].j = j1;
                        c[dr].pasi = c[st].pasi+1;
                        a[i1][j1] = 1;
                        if(pasi[i1][j1] == -1){
                            pasi[i1][j1] = c[dr].pasi;
                        }else{
                            pasi[i1][j1] = min(pasi[i1][j1], c[dr].pasi);
                        }
                    }
                }
            }
        }
        st++;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            fout << pasi[i][j] << ' ';
        }
        fout << '\n';
    }
    return 0;
}
