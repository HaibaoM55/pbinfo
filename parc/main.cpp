#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream fin("parc.in");
ofstream fout("parc.out");
int n, m, c;
vector<pair<int, int>> v[104];
bool viz[104];
int dist[104];
int x, y, z;
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
    fin >> n >> m >> c;
    for(int i = 1; i <= m; i++){
        fin >> x >> y >> z;
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }
    dijkstra(c);
    int k, vmin = 2e9, vmini=1;
    fin >> k;
    for(int i = 1; i <= k; i++){
        fin >> x;
        if(dist[x] < vmin){
            vmin = dist[x];
            vmini = x;
        }
    }
    fout << vmini;
    return 0;
}
