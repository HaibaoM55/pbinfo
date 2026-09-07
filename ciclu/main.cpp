#include <fstream>
using namespace std;
ifstream fin("ciclu.in");
ofstream fout("ciclu.out");
int n, m, p, x, y, q, p2;
bool v[24][24];
int r[24], b[24];
int vmax = 0, rasp[24];
void bt(int k){
    if(r[0] > 2 && v[k][p]){
        for(int i = 1; i <= r[0]; i++){
            fout << r[i] << ' ';
        }
        fout << p;
        exit(0);
    }
    for(int i = 1; i <= n; i++){
        if(!b[i] && v[k][i]){
            v[k][i] = false;
            v[i][k] = false;
            r[0]++;
            r[r[0]] = i;
            b[i] = true;
            bt(i);
            b[i] = false;
            r[0]--;
            v[k][i] = true;
            v[i][k] = true;
        }
    }
}
int main(){
    fin >> n >> m;
    for(int i = 1; i <= m; i++){
        fin >> x >> y;
        v[x][y] = true;
        v[y][x] = true;
    }
    fin >> p;
    r[0] = 1;
    r[1] = p;
    b[p] = true;
    bt(p);
    return 0;
}
