#include <fstream>
using namespace std;
ifstream fin("partial.in");
ofstream fout("partial.out");
int n, x, y;
bool b[204][204], f[204][204];
bool viz[204];
int v[204];
int nr = 0;
void visit(int k){
    bool ok = true;
    viz[k] = true;
    for(int i = 1; i <= n; i++){
        if(!viz[i] && b[k][i]){
            ok = false;
            f[k][i] = true;
            f[i][k] = true;
            viz[i] = true;
            visit(i);
        }
    }
}
int main(){
    fin >> n;
    while(fin >> x >> y){
        b[x][y] = true;
        b[y][x] = true;
        nr++;
    }

    nr = nr/2;
    viz[1] = true;
    visit(1);
    for(int i = 1; i < n; i++){
        for(int j = i+1; j <= n; j++){
            if(b[i][j] && nr > 0 && !f[i][j]){
                nr--;
                b[i][j] = false;
                b[j][i] = false;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(b[i][j]){
                fout << 1;
            }else{
                fout << 0;
            }
            fout << ' ';
        }
        fout << '\n';
    }
    return 0;
}
