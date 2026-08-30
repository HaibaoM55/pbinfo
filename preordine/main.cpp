#include <fstream>
#include <vector>
using namespace std;
ifstream fin("preordine.in");
ofstream fout("preordine.out");
int n;
int x, st, dr;
int t[1004], c[1004];
vector<int> v[1004];
int radacina(int y){
    if(t[y] == 0){
        return y;
    }
    return radacina(t[y]);
}
void visit(int k){
    if(k == 0) return;
    fout << c[k] << ' ';
    int l = v[k].size();
    for(int i = 0; i < l; i++){
        visit(v[k][i]);
    }
}
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x >> st >> dr;
        c[i] = x;
        t[st] = i;
        t[dr] = i;
        if(st != 0){
            v[i].push_back(st);
        }
        if(dr != 0){
            v[i].push_back(dr);
        }
    }
    visit(radacina(1));
    return 0;
}
