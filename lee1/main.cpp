#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("lee1.in");
ofstream fout("lee1.out");
int n, m;
int mat[104][104], matrice[104][104];
struct poz{
    int i,j;
}v[7];
poz inceput, sfarsit;
int dirx[6] = {1,-1,0,0};
int diry[6] = {0,0,-1,1};
struct coada1{
    int i, j, val;
}coada[1000004];
int lee(poz a, poz b){
    bool vizitat[104][104] = {false};
    int st = 1, dr = 1;
    coada[1].i = a.i;
    coada[1].j = a.j;
    coada[1].val = 0;
    vizitat[coada[1].i][coada[1].j] = 1;
    while(st <= dr){
        if(coada[st].i == b.i && coada[st].j == b.j){
            return coada[st].val;
        }else{
            for(int i = 0; i < 4; i++){
                int i1 = coada[st].i+dirx[i];
                int j1 = coada[st].j+diry[i];
                if(1 <= i1 && i1 <= n){
                    if(1 <= j1 && j1 <= m){
                        if(mat[i1][j1] == 0 && vizitat[i1][j1] == 0){
                            vizitat[i1][j1] = 1;
                            dr++;
                            coada[dr].i = i1;
                            coada[dr].j = j1;
                            coada[dr].val = coada[st].val+1;
                        }
                    }
                }
            }
        }
        st++;
    }
    return 0;
}
int k;
int kk[7], ordine[7];
int main(){
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> mat[i][j];
        }
    }
    fin >> inceput.i >> inceput.j >> sfarsit.i >> sfarsit.j;
    fin >> k;
    for(int i = 1; i <= k; i++){
        fin >> v[i].i >> v[i].j;
        kk[i] = i;
    }
    int vmin = 2e9;
    do{
        int rasp = lee(inceput, v[kk[1]]);
        for(int i = 2; i <= k; i++){
            rasp += lee(v[kk[i-1]], v[kk[i]]);
        }
        rasp += lee(v[kk[k]], sfarsit);
        if(rasp < vmin){
            vmin = rasp;
            for(int i = 1; i <= k; i++){
                ordine[i] = kk[i];
            }
        }
    }while(next_permutation(kk+1, kk+k+1));
    fout << vmin << '\n';
    fout << inceput.i << ','<< inceput.j << '\n';
    for(int i = 1; i <= k; i++){
        fout << v[ordine[i]].i << ',' << v[ordine[i]].j << '\n';
    }
    fout << sfarsit.i << ',' << sfarsit.j;
    return 0;
}
