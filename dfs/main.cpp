#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("dfs.in");
ofstream fout("dfs.out");
int n, m, k;
vector<int> v[104];
bool viz[104];
void dfs(int x){
    fout << x << ' ';
    int l = v[x].size();
    for(int i = 0; i < l; i++){
        if(!viz[v[x][i]]){
            viz[v[x][i]] = true;
            dfs(v[x][i]);
        }
    }
}
int a, b;
int main(){
    fin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        fin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        sort(v[i].begin(), v[i].end());
    }
    viz[k] = true;
    dfs(k);
    return 0;
}
