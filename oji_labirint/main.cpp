#include <fstream>
using namespace std;
ifstream fin("labirint.in");
ofstream fout("labirint.out");
int n, m;
char x;
bool a[1004][1004];
int a1[1004][1004];
int a2[1004][1004];
bool vizitat[1004][1004];
int nr = 0;
int dirx[6] = {-1,1,0,0};
int diry[6] = {0,0,-1,1};
struct poz{
    int i, j, pasi;
};
poz coada[1000004];
int st = 1, dr = 1;
int main(){
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j =1;  j <= m; j++){
            fin >> x;
            if(x == '1'){
                a[i][j] = true;
            }else{
                a[i][j] = false;
            }
        }
    }
    nr = 0;
    coada[1] = {1, 1, 0};
    st = 1, dr = 1;
    vizitat[1][1] = true;
    while(st <= dr){
        int i1 = coada[st].i;
        int j1 = coada[st].j;
        for(int p = 0; p < 4; p++){
            int i2 = i1+dirx[p];
            int j2 = j1+diry[p];
            if(1 <= i2 && i2 <= n){
                if(1 <= j2 && j2 <= m){
                    if(!vizitat[i2][j2]){
                        vizitat[i2][j2] = true;
                        if(!a[i2][j2]){
                            dr++;
                            coada[dr] = {i2, j2, coada[st].pasi+1};
                        }
                        a1[i2][j2] = coada[st].pasi+1;
                    }
                }
            }
        }
        st++;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            vizitat[i][j] = false;
        }
    }
    coada[1] = {n, m, 0};
    st = 1, dr = 1;
    vizitat[n][m] = true;
    while(st <= dr){
        int i1 = coada[st].i;
        int j1 = coada[st].j;
        for(int p = 0; p < 4; p++){
            int i2 = i1+dirx[p];
            int j2 = j1+diry[p];
            if(1 <= i2 && i2 <= n){
                if(1 <= j2 && j2 <= m){
                    if(!vizitat[i2][j2]){
                        vizitat[i2][j2] = true;
                        if(!a[i2][j2]){
                            dr++;
                            coada[dr] = {i2, j2, coada[st].pasi+1};
                        }
                        a2[i2][j2] = coada[st].pasi+1;
                    }
                }
            }
        }
        st++;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j]){
                if(a1[i][j] != 0 && a2[i][j] != 0 && a1[i][j]+a2[i][j] < a1[n][m]){
                    fout << 1;
                }else{
                    fout << 0;
                }
            }else{
                fout << 0;
            }
        }
        fout << '\n';
    }
    return 0;
}
