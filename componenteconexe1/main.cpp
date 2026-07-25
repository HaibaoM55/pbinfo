#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("componenteconexe.in");
ofstream fout("componenteconexe.out");
int n, x, y;
int nr = 0;
bool viz[104];
vector<int> v[104];
vector<int> f;
void visit(int k){
    viz[k] = true;
    int l = v[k].size();
    for(int i = 0; i < l; i++){
        if(!viz[v[k][i]]){
            viz[v[k][i]] = true;
            visit(v[k][i]);
        }
    }
}
int main(){
    fin >> n;
    while(fin >> x >> y){
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        if(!viz[i]){
            f.push_back(i);
            visit(i);
        }
    }
    int l = f.size();
    l--;
    fout << l << '\n';
    for(int i = 1; i <= l; i++){
        fout << 1 << ' ' << f[i] << '\n';
    }
    return 0;
}
