#include <fstream>
#include <vector>
using namespace std;
ifstream fin("roy-floyd.in");
ofstream fout("roy-floyd.out");
int n, m;
int x, y, z;
vector<pair<int, int>> v[104];
int dist[104];
bool viz[104];
void dijkstra(int k){
    int l = v[k].size();
    for(int i = 0; i < l; i++){
        if(dist[k]+v[k][i].second < dist[v[k][i].first]){
            dist[v[k][i].first] = dist[k]+v[k][i].second;
            dijkstra(v[k][i].first);
        }
    }
    viz[k] = true;
}
int main(){
    fin >> n >> m;
    while(fin >> x >> y >> z){
        v[x].push_back({y, z});
    }
    for(int p = 1; p <= n; p++){
        for(int i = 1; i <= n; i++){
            dist[i] = 2e9;
        }
        dist[p] = 0;
        dijkstra(p);
        for(int i = 1; i <= n; i++){
            if(dist[i] == 2e9){
                dist[i] = -1;
            }
            fout << dist[i] << ' ';
        }
        fout << '\n';
    }
    return 0;
}
