#include <fstream>
using namespace std;
ifstream fin("lant.in");
ofstream fout("lant.out");
int n, m, x, y;
int v[24];
bool b[24][24];
bool viz[24];
void visit(int k){
    if(v[v[0]] == y){
        for(int i = 1; i <= v[0]; i++){
            fout << v[i] << ' ';
        }
        fout << '\n';
        return;
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
    v[0] = 1;
    v[1] = x;
    viz[x] = true;
    visit(x);
    return 0;
}
