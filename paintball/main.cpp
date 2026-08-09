#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream fin("paintball.in");
ofstream fout("paintball.out");
int n, m, b;
int x, y;
vector<pair<int, int>> v[1004];
int dist[1004];
bool viz[1004];
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
    fin >> n >> m >> b;
    for(int i = 1; i <= m; i++){
        fin >> x >> y;
        v[x].push_back({y, 1});
        v[y].push_back({x, 1});
    }
    dijkstra(b);
    int rasp = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if(dist[i] == dist[j] && dist[i] != 2e9){
                rasp++;
            }
        }
    }
    fout << rasp;
    return 0;
}
