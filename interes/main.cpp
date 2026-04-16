#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("interes.in");
ofstream fout("interes.out");
int n, q;
int x, y;
vector<int> adj[200004];
int time_in[200004], time_out[200004], d[200004];
int up[200004][18];
void dfs(int u, int parent) {
    static int time = 0;
    time_in[u] = ++time;
    up[u][0] = parent;
    for(int j = 1; j <= 17; j++){
        up[u][j] = up[up[u][j-1]][j-1];
    }
    for(int v: adj[u]){
        if(v != parent){
            d[v] = d[u]+1;
            dfs(v, u);
        }
    }
    time_out[u] = ++time;
}
int lca(int u, int v){
    if(d[v] > d[u]){
        swap(u, v);
    }
    int diff = d[u]-d[v];
    for(int j = 0; j <= 17; j++){
        if((diff >> j) & 1){
            u = up[u][j];
        }
    }
    if(u == v){
        return u;
    }
    for(int i = 17; i >= 0; i--){
        if(up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}
int distanta(int u, int v){
    return d[u]+d[v]-2*d[lca(u,v)];
}
bool compara(int a, int b){
    return time_in[a] < time_in[b];
}
int k, v[200004];
int main(){
    fin >> n >> q;
    for(int i = 1; i < n; i++){
        fin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    d[1] = 0;
    dfs(1, 0);
    for(int i = 1; i <= q; i++){
        fin >> k;
        for(int j = 1; j <= k; j++){
            fin >> v[j];
        }
        int nr = 0;
        sort(v+1, v+k+1, compara);
        for(int j = 1; j < k; j++){
            nr += distanta(v[j], v[j+1]);
        }
        nr += distanta(v[k], v[1]);
        nr = nr/2;
        fout << nr << '\n';
    }
    return 0;
}
