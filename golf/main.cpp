#include <fstream>
using namespace std;
ifstream fin("golf.in");
ofstream fout("golf.out");
#define int long long
int t;
int n, m;
char chr;
int a[1004][1004];
int stc[1004], drc[1004];
int jsl[1004], dsl[1004];
bool viz[1004][1004];
int dirx[6] = {-1,1,0,0};
int diry[7] = {0,0,-1,1};
struct pos{
    int i, j;
}coada[1000004];
int vmax = 0, vmaxi = 0;
signed main(){
    fin >> t >> n >> m;
    int nr = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> chr;
            viz[i][j] = false;
            if(chr == '1'){
                a[i][j] = 1;
                nr++;
            }else{
                a[i][j] = 0;
            }
        }
    }
    if(t == 1){
        fout << nr;
    }else if(t == 2){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(a[i][j] == 1 && !viz[i][j]){
                    int st = 1, dr = 1;
                    coada[1].i = i;
                    coada[1].j = j;
                    viz[i][j] = true;
                    while(st <= dr){
                        for(int d = 0; d < 4; d++){
                            int i1 = coada[st].i+dirx[d];
                            int j1 = coada[st].j+diry[d];
                            if(1 <= i1 && i1 <= n){
                                if(1 <= j1 && j1 <= m){
                                    if(!viz[i1][j1] && a[i1][j1] == 1){
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
                    if(dr > vmax){
                        vmax = dr;
                        vmaxi = 1;
                    }else if(dr == vmax){
                        vmaxi++;
                    }
                }
            }
        }
        fout << vmaxi;
    }else{
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(a[i][j] == 1 && !viz[i][j]){
                    int st = 1, dr = 1;
                    coada[1].i = i;
                    coada[1].j = j;
                    viz[i][j] = true;
                    int vmini = 2e9, vminj = 2e9;
                    int vmaxi = 0, vmaxj = 0;
                    while(st <= dr){
                        vmini = min(vmini, coada[st].i);
                        vminj = min(vminj, coada[st].j);
                        vmaxi = max(vmaxi, coada[st].i);
                        vmaxj = max(vmaxj, coada[st].j);
                        for(int d = 0; d < 4; d++){
                            int i1 = coada[st].i+dirx[d];
                            int j1 = coada[st].j+diry[d];
                            if(1 <= i1 && i1 <= n){
                                if(1 <= j1 && j1 <= m){
                                    if(!viz[i1][j1] && a[i1][j1] == 1){
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
//                    fout << vminj << ' ' << vmaxj << '\n';
//                    fout << vmini << ' ' << vmaxi << '\n';
//                    fout << '\n';
                    stc[vmaxj+1] += dr;
                    drc[vminj-1] += dr;
                    jsl[vmaxi+1] += dr;
                    dsl[vmini-1] += dr;
                }
            }
        }
        int vvv = max(n, m);
        for(int i = 1; i <= vvv; i++){
            stc[i] = stc[i-1]+stc[i];
            jsl[i] = jsl[i-1]+jsl[i];
        }
        for(int i = vvv; i >= 1; i--){
            drc[i] = drc[i+1]+drc[i];
            dsl[i] = dsl[i+1]+dsl[i];
        }
        int q;
        fin >> q;
        for(int i = 1; i <= q; i++){
            int x;
            fin >> chr >> x;
            if(chr == 'L'){
                fout << 1LL*jsl[x]*dsl[x] << '\n';
            }else{
                fout << 1LL*stc[x]*drc[x] << '\n';
            }
        }
    }
    return 0;
}
