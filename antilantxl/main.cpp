#include <fstream>
using namespace std;
ifstream fin("antilantxl.in");
ofstream fout("antilantxl.out");
int n, m, x, y, a, l;
bool b[24][24], viz[24];
int v[25];
bool ok = false;
void visit(int k){
    if(v[0] >= l){
        ok = true;
        for(int i = 1; i <= v[0]; i++){
            fout << v[i] << ' ';
        }
        fout << '\n';
    }
    for(int i = 1; i <= n; i++){
        if(!viz[i] && !b[k][i]){
            viz[i] = true;
            v[0]++;
            v[v[0]] = i;
            visit(i);
            v[0]--;
            viz[i] = false;
        }
    }
}
int main(){
    fin >> n >> m >> x >> l;
    for(int i = 1; i <= m; i++){
        fin >> a >> y;
        b[a][y] = true;
        b[y][a] = true;
    }
    v[0] = 1;
    v[1] = x;
    viz[x] = true;
    visit(x);
    if(!ok) fout << "NU EXISTA";
    return 0;
}
