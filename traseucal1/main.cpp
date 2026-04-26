#include <fstream>
using namespace std;
ifstream fin("traseucal1.in");
ofstream fout("traseucal1.out");
int n, m;
int a[14][14];
int z;
int dirx[10] = {2, 2, -2, -2, 1, 1, -1, -1};
int diry[10] = {1,-1,  1, -1, 2,-2, 2 , -2};
struct matrice{
    int a[14][14];
}clearm;
int nr =0;
matrice raspmax;
int rmax = 0;
void viz(int i, int j, matrice rasp, int vmax){
    if(i == n && j == m){
        nr++;
        raspmax = rasp;
    }
    for(int d = 0; d < 8; d++){
        int i1=i+dirx[d], j1=j+diry[d];
        if(1 <= i1 && i1 <= n){
            if(1 <= j1 && j1 <= m){
                if(a[i1][j1] == 0 && rasp.a[i1][j1] == 0){
                    matrice raspc = rasp;
                    raspc.a[i1][j1] = vmax+1;
                    viz(i1, j1, raspc, vmax+1);
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
    clearm.a[1][1] = 1;
    viz(1,1,clearm,1);
    fout << nr << '\n';
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fout << raspmax.a[i][j] << ' ';
        }
        fout << '\n';
    }
    return 0;
}
