#include <fstream>
using namespace std;
ifstream fin("hamilton.in");
ofstream fout("hamilton.out");
int n, m, x, y, p, q, p2;
bool v[24][24];
int r[24], b[24];
int vmax = 0, rasp[24];
void bt(int k){
    if(r[0] == n && v[k][r[1]]){
        fout << "1\n";
        for(int i = 1; i <= n; i++){
            fout << r[i] << ' ';
        }
        fout << r[1];
        exit(0);
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
    fin >> n;
    while(fin >> x >> y){
        v[x][y] = true;
        v[y][x] = true;
    }
    for(int i = 1; i <= n; i++){
        v[0][i] = true;
    }
    bt(0);
    fout << "0";
    return 0;
}
