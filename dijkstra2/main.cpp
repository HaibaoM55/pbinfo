#include <fstream>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;
ifstream fin("dijkstra2.in");
ofstream fout("dijkstra2.out");
int n, m, p;
int x, y, z;
vector<pair<int, int>> v[100004];
int dist[100004];
bool viz[100004];
void dijkstra(int start){
    for(int i = 1; i <= n; i++){
        dist[i] = 2e9;
    }
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    while(!pq.empty()){
        auto [d, nod] = pq.top();
        pq.pop();
        if(!viz[nod]){
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
}
int main(){
    fin >> n >> m>> p;
    for(int i = 1; i <= m; i++){
        fin >> x >> y >> z;
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }
    dijkstra(p);
    for(int i = 1; i <= n; i++){
        if(dist[i] == 2e9){
            dist[i] = -1;
        }
        fout << dist[i] << ' ';
    }
    return 0;
}
