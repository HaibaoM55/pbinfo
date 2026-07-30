#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, k, m, x, y;
vector<pair<int, int>> v[104];
int dist[104];
bool viz[104];
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
    cin >> n >> k >> m;
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        v[x].push_back({y, 1});
    }
    dijkstra(k);
    int nr = 0;
    for(int i = 1; i <= n; i++){
        if(i == k){
            continue;
        }
        if(dist[i] % 2 == 0){
            nr++;
        }
    }
    cout << nr << '\n';
    for(int i = 1; i <= n; i++){
        if(i == k){
            continue;
        }
        if(dist[i] % 2 == 0){
            cout << i << ' ';
        }
    }
    return 0;
}
