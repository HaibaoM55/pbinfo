#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
ifstream fin("termite.in");
ofstream fout("termite.out");
int n, m, k, q, x, y, cost, t;
int dist[400005], parinte[400005], marime[400005], cdsu[400005];
struct muchie{
    int nod, cost;
};
struct muchie2{
    int x, y, cost;
};
bool compara1(muchie a, muchie b){
    return a.cost > b.cost;
}
bool compara2(muchie2 a, muchie2 b){
    return a.cost > b.cost;
}
vector<muchie> graf[400005];
vector<muchie2> muchii;
priority_queue<muchie, vector<muchie>, bool(*)(muchie, muchie)> coada(compara1);
void construieste_dsu(){
    for(int i = 1; i <= n; i++){
        parinte[i] = i;
        marime[i] = 1;
        cdsu[i] = 1e9;
    }
}
int gaseste_dsu(int& x, int& y){
    int rez = 1e9;
    while((x != y) && (parinte[x] != x || parinte[y] != y)){
        if(x == parinte[x] || (y != parinte[y] && marime[y] < marime[x])){
            swap(y, x);
        }
        rez = min(rez, cdsu[x]);
        x = parinte[x];
    }
    return rez;
}
int uneste_dsu(int x, int y, int c){
    int a = gaseste_dsu(x, y);
    if(x == y){
        return a;
    }
    if(marime[x] < marime[y]){
        swap(x, y);
    }
    parinte[y] = x;
    marime[x] += marime[y];
    cdsu[y] = c;
    return -1;
}
void dijkstra() {
    while(!coada.empty()){
        auto u = coada.top();
        coada.pop();
        if(dist[u.nod] != u.cost){
            continue;
        }
        for(auto v: graf[u.nod]){
            if(dist[v.nod] > u.cost+v.cost){
                dist[v.nod] = u.cost+v.cost;
                coada.push({v.nod, dist[v.nod]});
            }
        }
    }
}
void kruskal() {
    for(int i = 1; i <= m; i++){
        muchii[i].cost = min(dist[muchii[i].x], dist[muchii[i].y]);
    }
    sort(muchii.begin(), muchii.end(), compara2);
    for(auto e: muchii){
        uneste_dsu(e.x, e.y, e.cost);
    }
}
int rezolva(int x, int y, int t){
    if(x == y){
        return max(0, dist[x]-t);
    }
    int rez = uneste_dsu(x, y, 1e9);
    if(rez == 1e9 || rez < 0){
        return 0;
    }
    return max(0, rez-t);
}
int main(){
    fin >> n >> m >> k >> q;
    for(int i = 1; i <= n; i++){
        dist[i] = 1e9;
    }
    for(int i = 1; i <= k; i++){
        fin >> x;
        dist[x] = 0;
        coada.push({x, 0});
    }
    for(int i = 1; i <= m; i++){
        fin >> x >> y >> cost;
        muchii.push_back({x,y,cost});
        graf[x].push_back({y,cost});
        graf[y].push_back({x,cost});
    }
    dijkstra();
    construieste_dsu();
    kruskal();
    while(q){
        fin >> x >> y >> t;
        fout << rezolva(x, y, t) << '\n';
        q--;
    }
    return 0;
}
