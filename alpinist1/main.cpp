#include <iostream>
using namespace std;
int n, m;
int a[24][24];
struct poz{
    int i, j;
    int pasi = 0;
}coada[420];
bool viz[24][24];
int dirx[6] = {-1,1,0,0};
int diry[7] = {0,0,1,-1};
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    int st = 1, dr = 1;
    coada[1].i = 1;
    coada[1].j = 1;
    coada[1].pasi = 1;
    viz[1][1] = true;
    while(st <= dr){
        if(coada[st].i == n && coada[st].j == m){
            cout << coada[st].pasi;
            return 0;
        }
        for(int d = 0; d < 4; d++){
            int i1 = coada[st].i+dirx[d];
            int j1 = coada[st].j+diry[d];
            if(1 <= i1 && i1 <= n){
                if(1 <= j1 && j1 <= m){
                    if(!viz[i1][j1] && a[i1][j1] >= a[coada[st].i][coada[st].j]){
                        viz[i1][j1] = true;
                        dr++;
                        coada[dr].i = i1;
                        coada[dr].j = j1;
                        coada[dr].pasi = coada[st].pasi+1;
                    }
                }
            }
        }
        st++;
    }
    cout << "imposibil";
    return 0;
}
