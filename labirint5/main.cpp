#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("labirint.in");
ofstream fout("labirint.out");
int n, m;
bool b[1005][1005];
bool p[1005][1005];
int x[1005][1005];
int x1[1005][1005];
struct coada{
    int i, j;
}c[1000005];
int st = 1, dr = 1;
int dirx[5]={1, -1, 0, 0};
int diry[5]={0, 0, 1, -1};
void coada(){
    st = 1;
    dr = 1;
    c[1].i = 1;
    c[1].j = 1;
    x[1][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            p[i][j] = false;
        }
    }
    p[1][1] = true;
    while(st <= dr){
        for(int i = 0; i <= 3; i++){
            int i1 = c[st].i+dirx[i];
            int j1 = c[st].j+diry[i];
            if(1 <= i1 && i1 <= n){
                if(1 <= j1 && j1 <= m){
                    if(b[i1][j1] == false){
                        if(p[i1][j1] == false){
                            p[i1][j1] = true;
                            dr++;
                            c[dr].i = i1;
                            c[dr].j = j1;
                            x[i1][j1] = x[c[st].i][c[st].j]+1;
                        }
                    }else{
                        if(p[i1][j1] == false){
                            p[i1][j1] = true;
                            x[i1][j1] = x[c[st].i][c[st].j]+1;
                        }
                    }
                }
            }
        }
        st++;
    }
}
void coada1(){
    st = 1;
    dr = 1;
    c[1].i = n;
    c[1].j = m;
    x1[n][m] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            p[i][j] = false;
        }
    }
    p[n][m] = true;
    while(st <= dr){
        for(int i = 0; i <= 3; i++){
            int i1 = c[st].i+dirx[i];
            int j1 = c[st].j+diry[i];
            if(1 <= i1 && i1 <= n){
                if(1 <= j1 && j1 <= m){
                    if(b[i1][j1] == false){
                        if(p[i1][j1] == false){
                            p[i1][j1] = true;
                            dr++;
                            c[dr].i = i1;
                            c[dr].j = j1;
                            x1[i1][j1] = x1[c[st].i][c[st].j]+1;
                        }
                    }else{
                        if(p[i1][j1] == false){
                            p[i1][j1] = true;
                            x1[i1][j1] = x1[c[st].i][c[st].j]+1;
                        }
                    }
                }
            }
        }
        st++;
    }
}
int main()
{
    fin >> n >> m;
    char p1[1004];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char crf;
            fin >> crf;
            if(crf == '1'){
                b[i][j] = true;
            }else{
                b[i][j] = false;
            }
        }
    }
    coada();
    coada1();
    int d0 = x[1][1]+x1[1][1]-1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(b[i][j]){
                if(x[i][j]+x1[i][j]-1 < d0 && x[i][j]+x1[i][j]-1 != -1){
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
