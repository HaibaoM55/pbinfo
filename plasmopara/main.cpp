#include <fstream>
using namespace std;
ifstream fin("plasmopara.in");
ofstream fout("plasmopara.out");
int cer;
int n, m, k;
char a[205][205];
int dirx[6] = {0,0,-1,1};
int diry[7] = {1,-1,0,0};
struct poz{
    int i, j, z;
}c[40004];
bool vizitat[205][205];
int st=1, dr=0;
int main(){
    fin >> cer;
    fin >> n >> m >> k;
    int nr = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> a[i][j];
            if(a[i][j] == '-'){
                nr++;
            }
        }
    }
    if(a[1][1] != 'N'){
        dr++;
        c[dr] = {1, 1, 1};
        nr--;
    }
    if(a[1][m] != 'N'){
        dr++;
        c[dr] = {1, m, 1};
        nr--;
    }
    if(a[n][1] != 'N'){
        dr++;
        c[dr] = {n, 1, 1};
        nr--;
    }
    if(a[n][m] != 'N'){
        dr++;
        c[dr] = {n, m, 1};
        nr--;
    }
    while(st <= dr){
        if(c[st].z == k){
            break;
        }
        int i = c[st].i;
        int j = c[st].j;
        vizitat[i][j] = true;
        for(int x = 0; x < 4; x++){
            int i1 = i+dirx[x];
            int j1 = j+diry[x];
            if(1 <= i1 && i1 <= n){
                if(1 <= j1 && j1 <= m){
                    if(a[i1][j1] == '-' && vizitat[i1][j1] == false){
                        vizitat[i1][j1]= true;
                        nr--;
                        dr++;
                        c[dr] = {i1, j1, c[st].z+1};
                    }
                }
            }
        }
        st++;
    }
    fout << nr;
    return 0;
}
