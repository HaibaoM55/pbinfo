#include <fstream>
#include <queue>
#include <vector>
using namespace std;
#define int long long
ifstream fin("dragoni.in");
ofstream fout("dragoni.out");
int cer;
int n, m, x, y, z;
int dmax[804], dist[804][804];
int rasp[804];
vector<pair<int,int>> v[804];
bool viz[804];
void dijkstra(int start){
    for(int i = 1; i <= n; i++){
        dist[start][i] = 2e9;
        viz[i] = false;
    }
    dist[start][start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    while(!pq.empty()){
        auto d = pq.top().first;
        auto nod = pq.top().second;
        pq.pop();
        if(!viz[nod]){
            viz[nod] = true;
            for(auto &e : v[nod]){
                int urm = e.first;
                int w = e.second;
                if(dmax[start] < w){
                    continue;
                }
                if(dist[start][nod] + w < dist[start][urm]){
                    dist[start][urm] = dist[start][nod]+w;
                    pq.push({dist[start][urm], urm});
                }
            }
        }
    }
}
int vmax = 0;
void visit(int k){
    int l = v[k].size();
    viz[k] = true;
    vmax = max(vmax, dmax[k]);
    for(int i = 0; i < l; i++){
        if(!viz[v[k][i].first]){
            viz[v[k][i].first] = true;
            visit(v[k][i].first);
        }
    }
}
signed main(){
    fin >> cer;
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        fin >> dmax[i];
    }
    for(int i = 1; i <= m; i++){
        fin >> x >> y >> z;
        if(cer == 1 && z > dmax[1]){
            continue;
        }
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }
    if(cer == 1){
        visit(1);
        fout << vmax;
    }else{
        for(int i = 1; i <= n; i++){
            dijkstra(i);
//            for(int j = 1; j <= n; j++){
//                fout << dist[i][j] << ' ';
//            }
//            fout << '\n';
        }
        for(int i = 1; i <= n; i++){
            viz[i] = false;
            rasp[i] = 2e9;
        }
        rasp[1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});
        while(!pq.empty()){
            auto d = pq.top().first;
            auto nod = pq.top().second;
            pq.pop();
            if(!viz[nod]){
                viz[nod] = true;
                for(int i = 1; i <= n; i++){
                    if(d+dist[nod][i] < rasp[i]){
                        rasp[i] = d+dist[nod][i];
                        pq.push({rasp[i], i});
                    }
                }
            }
        }
        fout << rasp[n];
    }
    return 0;
}
