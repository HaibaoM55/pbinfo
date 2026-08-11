#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, k;
int x, y;
int dist[104];
bool viz[104];
vector<pair<int, int>> v[104];
void dijkstra(int start){
    for(int i = 1; i <= n; i++){
        viz[i] = false;
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
bool b[104];
pair<int, int> c[10004];
int main(){
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        c[i] = {x, y};
        v[c[i].first].push_back({c[i].second, 1});
    }
    dijkstra(1);
    for(int i = 2; i <= n; i++){
        if(dist[i] == k){
            b[i] = true;
        }
    }
    for(int i = 1; i <= n; i++){
        v[i].clear();
    }
    for(int i = 1; i <= m; i++){
        v[c[i].second].push_back({c[i].first, 1});
    }
    dijkstra(1);
    for(int i = 2; i <= n; i++){
        if(dist[i] == k){
            b[i] = true;
        }
    }
    bool ok = false;
    for(int i = 2; i <= n; i++){
        if(b[i]){
            ok = true;
            cout << i << ' ';
        }
    }
    if(!ok){
        cout << "Nu exista";
    }
    return 0;
}
