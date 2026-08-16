#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream fin("lungimeminima.in");
ofstream fout("lungimeminima.out");
int n, p, l;
int x, y;
bool viz[104];
int dist[104];
vector<pair<int, int>> v[104];
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
    fin >> n >> p >> l;
    while(fin >> x >> y){
        v[x].push_back({y, 1});
        v[y].push_back({x, 1});
    }
    dijkstra(p);
    int nr = 0;
    for(int i = 1; i <= n; i++){
        if(dist[i] == l){
            nr++;
        }
    }
    fout << nr << '\n';
    for(int i = 1; i <= n; i++){
        if(dist[i] == l){
            fout << i << ' ';
        }
    }
    return 0;
}
