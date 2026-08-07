#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int x, y, z;
bool viz[104];
int dist[104][104];
vector<pair<int, int>> v[104];
void dijkstra(int start){
    for(int i = 1; i <= n; i++){
        dist[start][i] = 2e9;
        viz[i]= false;
    }
    dist[start][start] = 0;
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
                if(dist[start][nod] + w < dist[start][urm]){
                    dist[start][urm] = dist[start][nod]+w;
                    pq.push({dist[start][urm], urm});
                }
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        v[x].push_back({y, 1});
    }
    for(int i = 1; i <= n; i++){
        dijkstra(i);
    }
    int p = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if(dist[i][j] == dist[j][i] && dist[i][j] != 2e9){
                p++;
                cout <<i << ' ' << j << '\n';
            }
        }
    }
    if(!p){
        cout << "Nu exista";
    }
    return 0;
}
