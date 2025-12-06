#include <fstream>
using namespace std;
ifstream fin("soarece1.in");
ofstream fout("soarece1.out");
int n, m;
char a[14][14];
bool vizitat[14][14];
int v[14][14];
int dirx[6] = {-1,1,0,0};
int diry[7] = {0,0,-1,1};
struct que{
    int i, j;
    int val;
    int st;
}coada[104];
int main(){
    fin >> n >> m;
    int si=-1, sj=-1;
    int bi=-1, bj=-1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> a[i][j];
            if(a[i][j] == 'S'){
                v[i][j] = 1;
                si = i;
                sj = j;
            }
            if(a[i][j] == 'B'){
                bi = i;
                bj = j;
            }
        }
    }
    v[si][sj] = 1;
    vizitat[si][sj] = true;
    int st=1,dr=1;
    coada[1].i = si;
    coada[1].j = sj;
    coada[1].val = 1;
    coada[1].st = -1;
    int ind = 1;
    while(st <= dr){
        int i = coada[st].i;
        int j = coada[st].j;
        for(int z = 0; z < 4; z++){
            int i1 = i+dirx[z];
            int j1 = j+diry[z];
            if(1 <= i1 && i1 <= n){
                if(1 <= j1 && j1 <= m){
                    if(!vizitat[i1][j1] && (a[i1][j1] == '_' || a[i1][j1] == 'B')){
                        vizitat[i1][j1] = true;
                        //fout << i1 << ' ' << j1 << '\n';
                        dr++;
                        coada[dr].i = i1;
                        coada[dr].j = j1;
                        coada[dr].val = coada[st].val+1;
                        coada[dr].st = st;
                        if(coada[dr].i == bi && coada[dr].j == bj){
                            ind = dr;
                            break;
                        }
                    }
                }
            }
        }
        st++;
    }
    if(ind == 1){
        v[si][sj] = 0;
    }
    while(coada[ind].st != -1){
        v[coada[ind].i][coada[ind].j] = coada[ind].val;
        ind = coada[ind].st;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fout << v[i][j] << ' ';
        }
        fout << '\n';
    }
    return 0;
}
