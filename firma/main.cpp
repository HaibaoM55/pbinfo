#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream fin("firma.in");
ofstream fout("firma.out");
int n, m;
int x, y, z;
vector<pair<int, int>> v[104];
bool viz[104];
int dist[104];
int dijkstra(int start){
    for(int i = 1; i <= n; i++){
        dist[i] = 2e9;
        viz[i] = false;
    }
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    int r = 0;
    while(!pq.empty()){
        auto [d, nod] = pq.top();
        pq.pop();
        if(!viz[nod]){
            r += d;
            viz[nod] = true;
            for(auto &e : v[nod]){
                int urm = e.first;
                int w = e.second;
                if(dist[nod] + w < dist[urm]){
                    dist[urm] = dist[nod]+w;
                    pq.push({dist[urm], urm});
                }
            }
        }
    }
    return r;
}
int main(){
    fin >> n >> m;
    for(int i = 1; i <= m; i++){
        fin >> x >> y >> z;
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }
    int vmin = 2e9;
    for(int i = 1; i <= n; i++){
        vmin = min(vmin, dijkstra(i));
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            viz[j] = false;
        }
        if(dijkstra(i) == vmin){
            fout << i;
            return 0;
        }
    }
    return 0;
}
