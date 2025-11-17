#include <fstream>
using namespace std;
ifstream fin("acces1.in");
ofstream fout("acces1.out");
int n, m;
struct poz{
    int i, j;
}coada[1000004];
char a[1004][1004];
int rasp[1004][1004];
bool vizitat[1004][1004];
int dirx[6] = {-1,1,0,0};
int diry[7] = {0,0,-1,1};
int main(){
    fin >> n >> m;
    int st = 1, dr = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> a[i][j];
            rasp[i][j] = -1;
            if(a[i][j] == 'P'){
                dr++;
                coada[dr].i = i;
                coada[dr].j = j;
                rasp[i][j] = 0;
            }
        }
    }
    while(st <= dr){
        vizitat[coada[st].i][coada[st].j] = true;
        for(int i = 0; i < 4; i++){
            int i1 = coada[st].i+dirx[i];
            int j1 = coada[st].j+diry[i];
            if(1 <= i1 && i1 <= n){
                if(1 <= j1 && j1 <= m){
                    if(a[i1][j1] == '-' && !vizitat[i1][j1]){
                        rasp[i1][j1] = rasp[coada[st].i][coada[st].j]+1;
                        vizitat[i1][j1] = true;
                        dr++;
                        coada[dr].i = i1;
                        coada[dr].j = j1;
                    }
                }
            }
        }
        st++;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(rasp[i][j] == -1){
                fout << a[i][j];
            }else{
                fout << rasp[i][j];
            }
            fout << ' ';
        }
        fout << '\n';
    }
    return 0;
}
