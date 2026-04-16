#include <fstream>
#include <map>
using namespace std;
ifstream fin("sokoban.in");
ofstream fout("sokoban.out");
int n, m, nc, mc;
int bi, bj, pi, pj, fi, fj;
char c[1004][1004];
struct State{
    int bi, bj, pi, pj;
    int pasi;
};
State coada[10000004];
map<pair<pair<int,int>,pair<int,int>>, bool> vizitat;
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};
bool inBox(int i, int j, int bbi, int bbj){
    return i >= bbi && i < bbi + nc && j >= bbj && j < bbj + mc;
}
bool lamargine(int ppi, int ppj, int bbi, int bbj){
    for(int ddi = -1; ddi <= 1; ddi++){
        for(int ddj = -1; ddj <= 1; ddj++){
            if(ddi == 0 && ddj == 0) continue;
            int ni = ppi + ddi;
            int nj = ppj + ddj;
            if(inBox(ni, nj, bbi, bbj)) return true;
        }
    }
    return false;
}
bool mergef(int i, int j, int bbi, int bbj){
    if(i < 1 || i > n || j < 1 || j > m) return false;
    if(inBox(i, j, bbi, bbj)) return false;
    if(c[i][j] == 'W') return false;
    return true;
}
bool mergefBox(int bbi, int bbj){
    for(int i = bbi; i < bbi + nc; i++){
        for(int j = bbj; j < bbj + mc; j++){
            if(i < 1 || i > n || j < 1 || j > m) return false;
            if(c[i][j] == 'W') return false;
        }
    }
    return true;
}
int main(){
    fin >> n >> m >> nc >> mc;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> c[i][j];
            if(c[i][j] == 'P'){
                pi = i;
                pj = j;
            }else if(c[i][j] == 'B'){
                if(bi == 0){
                    bi = i;
                    bj = j;
                }
            }else if(c[i][j] == 'F'){
                fi = i;
                fj = j;
            }
        }
    }
    int st = 1, dr = 1;
    coada[1].bi = bi;
    coada[1].bj = bj;
    coada[1].pi = pi;
    coada[1].pj = pj;
    coada[1].pasi = 0;
    vizitat[{{bi, bj}, {pi, pj}}] = true;
    while(st <= dr){
        int cbi = coada[st].bi;
        int cbj = coada[st].bj;
        int cpi = coada[st].pi;
        int cpj = coada[st].pj;
        int cpasi = coada[st].pasi;
        st++;
        if(cpi == fi && cpj == fj){
            fout << cpasi;
            return 0;
        }
        for(int dir = 0; dir < 4; dir++){
            int npi = cpi + di[dir];
            int npj = cpj + dj[dir];
            int nbi = cbi;
            int nbj = cbj;
            if(inBox(npi, npj, cbi, cbj)){
                nbi = cbi + di[dir];
                nbj = cbj + dj[dir];
                if(!mergefBox(nbi, nbj)) continue;
            }
            if(!mergef(npi, npj, nbi, nbj)) continue;
            if(!lamargine(npi, npj, nbi, nbj)) continue;
            if(vizitat[{{nbi, nbj}, {npi, npj}}]) continue;
            vizitat[{{nbi, nbj}, {npi, npj}}] = true;
            dr++;
            coada[dr].bi = nbi;
            coada[dr].bj = nbj;
            coada[dr].pi = npi;
            coada[dr].pj = npj;
            coada[dr].pasi = cpasi + 1;
        }
    }

    fout << -1;
    return 0;
}
