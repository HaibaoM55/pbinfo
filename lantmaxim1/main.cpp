#include <fstream>
using namespace std;
ifstream fin("lantmaxim1.in");
ofstream fout("lantmaxim1.out");
int n, m, x, y, kk;
bool v[24][24];
int r[24], b[24];
int vmax = 0, rasp[24];
void bt(int k){
    if(k == kk){
        if(r[0] > vmax){
            vmax = r[0];
            for(int i = 0; i <= r[0]; i++){
                rasp[i] = r[i];
            }
        }
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
    fin >> kk;
    for(int i = 1; i <= n; i++){
        v[0][i] = true;
    }
    bt(0);
    for(int i = 1; i <= rasp[0]; i++){
        fout << rasp[i] << ' ';
    }
    return 0;
}
