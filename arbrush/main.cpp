#include <fstream>
#include <vector>
using namespace std;
ifstream fin("arbrush.in");
ofstream fout("arbrush.out");
int n, m, rad, x, y;
vector<int> v[27044];
int f[27044], t[27044], coada[27044];
bool viz[27044];
void dfs(int k){
    int l = v[k].size();
    f[k] = 1;
    viz[k] = true;
    for(int i = 0; i < l; i++){
        if(!viz[v[k][i]]){
            viz[v[k][i]] = true;
            dfs(v[k][i]);
            f[k] += f[v[k][i]];
        }
    }
}
int main(){
    fin >> n >> m >> rad;
    for(int i = 1; i < n; i++){
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(rad);
    for(int i = 1; i <= m; i++){
        fin >> x;
        fout << ((f[x]-1)*f[x])/2<< '\n';
    }
	return 0;
}
