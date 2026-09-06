#include <fstream>
using namespace std;
ifstream fin("lanturi.in");
ofstream fout("lanturi.out");
int n, m, x, y, p, q, p2;
bool v[24][24];
int r[24], b[24];
int vmax = 0, rasp[24];
void bt(int k){
    if(k == q){
        if(b[p2]){
            for(int i = 1; i <= r[0]; i++){
            	fout << r[i] << ' ';
            }
            fout << '\n';
        }
        return;
    }
    b[k] = true;
    for(int i = 1; i <= n; i++){
        if(!b[i] && v[k][i]){
            r[0]++;
            r[r[0]] = i;
            b[i] = true;
            bt(i);
            b[i] = false;
            r[0]--;
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
    fin >> p >> q >> p2;
    r[0]++;
    r[r[0]] = p;
    bt(p);
    for(int i = 1; i <= rasp[0]; i++){
        fout << rasp[i] << ' ';
    }
    return 0;
}
