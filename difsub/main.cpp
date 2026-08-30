#include <fstream>
#include <vector>
using namespace std;
ifstream fin("difsub.in");
ofstream fout("difsub.out");
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
int visit(int k){
    if(k == 0) return 0;
    int s = c[k];
    int l = v[k].size();
    for(int i = 0; i < l; i++){
		s += visit(v[k][i]);
    }
    return s;
}
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x >> st >> dr;
        c[i] = x;
        t[st] = i;
        t[dr] = i;
        v[i].push_back(st);
        v[i].push_back(dr);
    }
    fout << abs(visit(v[radacina(1)][0])-visit(v[radacina(1)][1]));
    return 0;
}
