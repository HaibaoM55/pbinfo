#include <fstream>
using namespace std;
ifstream fin("circuiteparitate.in");
ofstream fout("circuiteparitate.out");
int n, m, x, y;
bool b[24][24];
bool viz[24];
int v[24];
bool ok = false;
void circuite(int c, int start){
    v[0]++;
    v[v[0]] = c;
    if(c == start && v[0] >= 3){
        ok = true;
        for(int i = 1; i <= v[0]; i++){
            fout << v[i] << ' ';
        }
        fout << '\n';
    }
    for(int i = 1; i <= n; i++){
        if(i % 2 == c % 2 && b[c][i] && !viz[i]){
            viz[i] = true;
            circuite(i, start);
            v[0]--;
            viz[i] =false;
        }
    }
}
int main(){
    fin >> n >> m;
    for(int i = 1; i <= m; i++){
        fin >> x >> y;
        b[x][y] = true;
    }
    for(int i = 1; i <= n; i++){
        v[0] = 0;
        for(int  j = 1; j <= n; j++){
            viz[j] = false;
        }
        circuite(i, i);
    }
    if(!ok){
        fout << "NU EXISTA";
    }
    return 0;
}
