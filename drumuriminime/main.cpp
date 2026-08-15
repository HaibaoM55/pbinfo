#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream fin("dmin2.in");
ofstream fout("dmin2.out");
int n, m;
int x, y;
vector<pair<int, int>> v[104];
int dist[104];
bool viz[104];
void dijkstra(int start){
    for(int i = 1; i <= n; i++){
        dist[i] = 2e9;
        viz[i] = false;
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
    fin >> n >> m;
    for(int i = 1; i <= m; i++){
        fin >> x >> y;
        v[x].push_back({y, 1});
    }
    fin >> m;
    for(int i = 1; i <= m; i++){
        fin >> x >> y;
        dijkstra(x);
        if(dist[y] == 2e9){
            fout << -1;
        }else{
            fout << dist[y];
        }
        fout << '\n';
    }
    return 0;
}
