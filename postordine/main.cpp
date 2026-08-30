#include <fstream>
#include <vector>
using namespace std;
ifstream fin("postordine.in");
ofstream fout("postordine.out");
int n;
int x, st, dr;
int t[1004], c[1004];
int v[1004][3];
int radacina(int y){
    if(t[y] == 0){
        return y;
    }
    return radacina(t[y]);
}
void visit(int k){
    if(k == 0) return;
    visit(v[k][0]);
    visit(v[k][2]);
    fout << c[v[k][1]] << ' ';
}
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x >> st >> dr;
        c[i] = x;
        t[st] = i;
        t[dr] = i;
        v[i][0] = st;
        v[i][1] = i;
        v[i][2] = dr;
    }
    visit(radacina(1));
    return 0;
}
