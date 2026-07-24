#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
ifstream fin("componenteconexe6.in");
ofstream fout("componenteconexe6.out");
int n, x, y;
int nr = 0;
vector<int> v[104];
vector<int> c[104];
bool viz[104];
void bt(int k){
    c[nr].push_back(k);
    int l = v[k].size();
    for(int i = 0; i < l; i++){
        if(!viz[v[k][i]]){
            viz[v[k][i]] = true;
            bt(v[k][i]);
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
            viz[i] = true;
            bt(i);
        }
    }
    fout << nr << '\n';
    for(int i = 1; i <= nr; i++){
        sort(c[i].begin(), c[i].end());
        int l = c[i].size();
        for(int j = 0; j < l; j++){
            fout << c[i][j] << ' ';
        }
        fout << '\n';
    }
    return 0;
}
