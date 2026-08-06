#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream fin("picard.in");
ofstream fout("picard.out");
int n, m, x, y, z;
vector<pair<int, int>> v[104];
bool viz[104];
int dist[104], rasp[104];
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
        fin >> x >> y >> z;
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }
    int vmax = 0;
    for(int i = 1; i <= n; i++){
        int r= 0;
        dijkstra(i);
        for(int j = 1; j <= n; j++){
            r += dist[j];
        }
        rasp[i] = r;
        vmax = max(vmax, r);
    }
    for(int i = 1; i <= n; i++){
        if(vmax == rasp[i]){
            fout << i << ' ';
        }
    }
    return 0;
}
