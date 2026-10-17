#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
ifstream fin("festivaluri.in");
ofstream fout("festivaluri.out");
int n, m, p, z, r;
int x, y, cst;
vector<pair<int, int>> v[104];
int dist[104], f[104];
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
    fin >> n >> m >> p >> z >> r;
    for(int i = 1; i <= m; i++){
        fin >> x >> y >> cst;
        v[x].push_back({y, cst});
        v[y].push_back({x, cst});
    }
    dijkstra(z);
    for(int i = 1; i <= r; i++){
        fin >> x;
        f[i] = dist[x];
    }
    sort(f+1, f+r+1);
    for(int i = 1; i <= r; i++){
        p -= f[i];
        if(p < 0){
            fout << i-1;
            return 0;
        }
    }
    fout << r;
	return 0;
}
