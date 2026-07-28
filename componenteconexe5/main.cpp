#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("componenteconexe5.in");
ofstream fout("componenteconexe5.out");
int n, m, q, x, y;
int nr = 0;
bool viz[1004];
vector<int> v[1004];
vector<int> cc[1004];
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
    for(int i = 1; i <= m; i++){
        fin >>  x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        if(!viz[i]){
            nr++;
            visit(i);
        }
    }
    fin >> q;
    for(int i = 1; i <= q; i++){
        fin >> x;
        for(int j = 1; j <= nr; j++){
            bool ok = false;
            int l = cc[j].size();
            for(int k = 0; k < l; k++){
                if(cc[j][k] == x){
                    ok = true;
                    break;
                }
            }
            if(ok){
                fout << l << '\n';
                break;
            }
        }
    }
    return 0;
}
