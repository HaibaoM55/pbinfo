#include <fstream>
using namespace std;
ifstream fin("fill.in");
ofstream fout("fill.out");
int n, m, nr = 0;
int a[104][104];
int dirx[6] = {0,0,1,-1};
int diry[7] = {-1,1,0,0};
void fill(int i, int j){
    a[i][j] = 0;
    for(int d = 0; d < 4; d++){
        int i1 = i+dirx[d];
        int j1 = j+diry[d];
        if(1 <= i1 && i1 <= n){
            if(1 <= j1 && j1 <= m){
                if(a[i1][j1] == 1){
                    fill(i1, j1);
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
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == 1){
                nr++;
                fill(i, j);
            }
        }
    }
    fout << nr;
    return 0;
}
