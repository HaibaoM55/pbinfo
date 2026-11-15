#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int x, y, z;
vector<pair<int, int>> v[500004];
int dist[500004];
int t[500004];
bool viz[500004];
void dijkstra(int start){
    for(int i = 1; i <= n; i++){
        dist[i] = 0;
    }
    dist[start] = 0;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {start, -1}});
    while(!pq.empty()){
        auto [d, nod] = pq.top();
        pq.pop();
        t[nod.first] = nod.second;
        if(!viz[nod.first]){
            viz[nod.first] = true;
            for(auto &e : v[nod.first]){
                int urm = e.first;
                int w = e.second;
                if(dist[nod.first] + w > dist[urm]){
                    dist[urm] = dist[nod.first]+w;
                    pq.push({dist[urm], {urm, nod.first}});
                }
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> x >> y >> z;
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }
    dijkstra(n);
    int vmax = 0, vmaxi = 0;
    for(int i = 1; i <= n; i++){
        if(dist[i] >= vmax){
            vmax = dist[i];
            vmaxi = i;
        }
    }
    cout << vmax << ' ';
    int ogvmaxi = vmaxi;
    int nr = 0;
    while(t[vmaxi] != -1){
        nr++;
        vmaxi = t[vmaxi];
    }
    cout << nr+1 << '\n';
    vmaxi = ogvmaxi;
    while(t[vmaxi] != -1){
        cout << vmaxi << ' ';
        vmaxi = t[vmaxi];
    }
    cout << n;
	return 0;
}
