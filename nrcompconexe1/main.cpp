#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("nrcompconexe.in");
ofstream fout("nrcompconexe.out");
int n, m, x, y;
int nr = 0;
bool viz[30004];
vector<int> v[30004];
vector<int> cc[30004];
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
    fin >> n >> m;
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
    fout << nr;
    return 0;
}

