#include <fstream>
using namespace std;
ifstream fin("lantpq.in");
ofstream fout("lantpq.out");
int n, m, x, y;
int v[24];
bool b[24][24];
bool viz[24];
bool ok = false;
void visit(int k){
    if(x <= v[0] && v[0] <= y){
        ok = true;
        for(int i = 1; i <= v[0]; i++){
            fout << v[i] << ' ';
        }
        fout << '\n';
    }
    for(int i = 1; i <= n; i++){
        if(b[k][i] && !viz[i]){
            viz[i] = true;
            v[0]++;
            v[v[0]] = i;
            visit(i);
            viz[i] = false;
            v[0]--;
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
    fin >> x >> y;
    x++;
    y++;
    for(int i = 1; i <= n; i++){
        v[0] = 1;
        v[1] = i;
        viz[i] = true;
        visit(i);
        viz[i] = false;
    }
    if(!ok) fout << "NU EXISTA";
    return 0;
}
