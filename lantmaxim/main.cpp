#include <fstream>
using namespace std;
ifstream fin("lantmaxim.in");
ofstream fout("lantmaxim.out");
int n, m, x, y, p, q;
bool b[24][24], viz[24];
int vmax, vmaxvec[24];
int v[24];
void visit(int nre){
    if(v[nre-1] == q && nre > vmax){
        vmax = nre;
        for(int i = 0; i < nre; i++){
            vmaxvec[i] = v[i];
        }
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!viz[i] && b[v[nre-1]][i]){
            viz[i] = true;
            v[nre] = i;
            visit(nre+1);
            viz[i] = false;
        }
    }
}
int main(){
    fin >> n >> m;
    for(int i = 1; i <= m; i++){
        fin >> x >> y;
        b[x][y] = true;
        b[y][x] = true;
    }
    fin >> p >> q;
    viz[p] = true;
    v[0] = p;
    visit(1);
    for(int i = 0; i < vmax; i++){
        fout << vmaxvec[i] << ' ';
    }
    return 0;
}
