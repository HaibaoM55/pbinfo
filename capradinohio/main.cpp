#include <fstream>
using namespace std;
ifstream fin("capradinohio.in");
ofstream fout("capradinohio.out");
int n, m, x, y;
bool b[24][24];
int v[24];
bool viz[24], exista = false;
void visit(int nre){
    if(nre == n+1){
        exista = true;
        for(int i = 1; i <= n; i++){
            fout << v[i] << ' ';
        }
        fout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++){
        if(b[v[nre-1]][i] && !viz[i]){
            viz[i] = true;
            v[nre] = i;
            visit(nre+1);
            viz[i] = false;
        }
    }
}
int main(){
    fin >> n >> m;
    v[0] = 0;
    for(int i = 1; i <= m; i++){
        fin >> x >> y;
        b[x][y] = true;
        b[y][x] = true;
    }
    for(int i = 1; i <= n; i++){
        b[0][i] = true;
    }
    visit(1);
    if(!exista){
        fout << "NU EXISTA";
    }
    return 0;
}
