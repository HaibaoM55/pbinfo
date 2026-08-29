#include <fstream>
using namespace std;
ifstream fin("moscraciun.in");
ofstream fout("moscraciun.out");
int n, m, k, nr;
int a[104][104];
int dirx[6] = {0,0,1,-1};
int diry[7] = {-1,1,0,0};
void fill(int i, int j){
    if(a[i][j] == 3){
        nr++;
    }else if(a[i][j] == 2){
    	nr += 100000;
    }
    a[i][j] = 0;
    for(int d = 0; d < 4; d++){
        int i1 = i+dirx[d];
        int j1 = j+diry[d];
        if(1 <= i1 && i1 <= n){
            if(1 <= j1 && j1 <= m){
                if(a[i1][j1] == 1 || a[i1][j1] == 2 || a[i1][j1] == 3){
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
    int rasp = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == 1 || a[i][j] == 2 || a[i][j] == 3){
                nr = 0;
                fill(i, j);
                rasp = max(rasp, nr);
            }
        }
    }
    fout << rasp-100000;
    return 0;
}
