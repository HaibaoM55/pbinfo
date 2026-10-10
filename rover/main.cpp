#include <fstream>
using namespace std;
ifstream fin("rover.in");
ofstream fout("rover.out");
int t;
int n, g;
int a[505][505];
struct pos{
    int i, j;
    int nes=1;
}coada[4*500*500+5];
int dirx[6] = {-1,1,0,0};
int diry[6] = {0,0,1,-1};
int nesigur[505][505];
bool viz[505][505];
bool verif(int x){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            viz[i][j] = false;
        }
    }
    int st = 1, dr =1;
    coada[st].i = 1;
    coada[st].j = 1;
    while(st <= dr){
        if(coada[st].i == n && coada[st].j == n){
            return true;
        }
        for(int d = 0; d < 4; d++){
            int i1 = coada[st].i+dirx[d];
            int j1 = coada[st].j+diry[d];
            if(1 <= i1 && i1 <= n){
                if(1 <= j1 && j1 <= n){
                    if(!viz[i1][j1] && a[i1][j1] >= x){
                        dr++;
                        coada[dr].i = i1;
                        coada[dr].j = j1;
                        viz[i1][j1] = true;
                    }
                }
            }
        }
        st++;
    }
    return false;
}
int main(){
    fin >> t;
    fin >> n;
    if(t == 1){
        fin >> g;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            fin >> a[i][j];
            nesigur[i][j] = -1;
        }
    }
    if(t == 1){
        int st = 1;
        int dr = 1;
        int ost = 1;
        coada[st].i = 1, coada[st].j = 1;
        int nri = 0;
        if(a[1][1] < g){
            nri++;
        }
        while(!viz[n][n]){
            ost = st;
            while(st <= dr){
                for(int d = 0; d < 4; d++){
                    int i1 = coada[st].i+dirx[d];
                    int j1 = coada[st].j+diry[d];
                    if(1 <= i1 && i1 <= n){
                        if(1 <= j1 && j1 <= n){
                            if(a[i1][j1] >= g && !viz[i1][j1]){
                                dr++;
                                coada[dr].i = i1;
                                coada[dr].j = j1;
                                viz[i1][j1] = true;
                                nesigur[i1][j1] = nri;
                            }
                        }
                    }
                }
                st++;
            }
            int odr = dr;
            st = ost;
            while(st <= odr){
                for(int d = 0; d < 4; d++){
                    int i1 = coada[st].i+dirx[d];
                    int j1 = coada[st].j+diry[d];
                    if(1 <= i1 && i1 <= n){
                        if(1 <= j1 && j1 <= n){
                            if(a[i1][j1] <= g && !viz[i1][j1]){
                                dr++;
                                coada[dr].i = i1;
                                coada[dr].j = j1;
                                viz[i1][j1] = true;
                                nesigur[i1][j1] = nri+1;
                            }
                        }
                    }
                }
                st++;
            }
            nri++;
        }
        fout << nesigur[n][n];
    }else{
        int p1 = 1, p2 = 10000, p=1;
        while(p1 <= p2){
            int mij = (p1+p2)/2;
            if(verif(mij)){
                p1 = mij+1;
                p = mij;
            }else{
                p2 = mij-1;
            }
        }
        fout << p;
    }
    return 0;
}
