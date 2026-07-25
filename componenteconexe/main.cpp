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
vector<int> cc[104];
void visit(int k){
    cc[nr].push_back(k);
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
            nr++;
            visit(i);
        }
    }
    fout << nr << '\n';
    for(int i = 1; i <= nr; i++){
        sort(cc[i].begin(), cc[i].end());
        int l = cc[i].size();
        for(int j = 0; j < l; j++){
            fout << cc[i][j] << ' ';
        }
        fout <<'\n';
    }
    return 0;
}
