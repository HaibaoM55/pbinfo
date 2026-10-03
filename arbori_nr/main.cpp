#include <fstream>
#include <vector>
using namespace std;
ifstream fin("arbori_nr.in");
ofstream fout("arbori_nr.out");
int n, m, x, y;
vector<int> v[100004];
int t[100004];
int visit(int k, int p){
    int s = 0;
    if(k < p){
        s++;
    }
    int l = v[k].size();
    for(int i = 0; i < l; i++){
        s += visit(v[k][i], p);
    }
    return s;
}
void stabileste_parinti(int nod, int par) {
    t[nod] = par;
    for(int vecin : v[nod]) {
        if(vecin != par) {
            stabileste_parinti(vecin, nod);
        }
    }
}
int main(){
    fin >> n >> m;
    while(fin >> x >> y){
        v[x].push_back(y);
        v[y].push_back(x);
    }
    stabileste_parinti(m, 0);
    for(int i = 1; i <= n; i++){
        v[i].clear();
    }
    for(int i = 1; i <= n; i++){
        v[t[i]].push_back(i);
    }
    for(int i = 1; i <= n; i++){
        fout << visit(i, i) << ' ';
    }
    return 0;
}
