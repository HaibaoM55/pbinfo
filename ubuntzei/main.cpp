#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
ifstream fin("ubuntzei.in");
ofstream fout("ubuntzei.out");
int n, m;
int x, y, z;
int k, a[17];
vector<pair<int, int>> v[2004];
int dist[2004][2004];
long long dp[131076][17];
bool viz[2004];
void dijkstra(int start){
    for(int i = 1; i <= n; i++){
        viz[i] = false;
        dist[start][i] = 2e9;
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
                if(dist[start][nod] + w < dist[start][urm]){
                    dist[start][urm] = dist[start][nod]+w;
                    pq.push({dist[start][urm], urm});
                }
            }
        }
    }
}
signed main(){
    fin >> n >> m;
    fin >> k;
    for(int i = 1; i <= k; i++){
        fin >> a[i];
    }
    for(int i = 1; i <= m; i++){
        fin >> x >> y >> z;
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }
    a[0] = 1;
    k++;
    a[k] = n;
    for(int i = 0; i <= k; i++){
        dijkstra(a[i]);
    }
//    sort(a+1, a+k+1);
//    do{
//        long long cst = 0;
//        for(int i = 0; i <= k; i++){
//            cst += dist[a[i]][a[i+1]];
//        }
//        cstmin = min(cstmin, cst);
//    }while(next_permutation(a+1, a+k+1));
    for(int i = 0; i < (1<<(k+1)); i++){
        for(int j = 0; j <= k; j++){
            dp[i][j] = 3200000000LL;
        }
    }
    dp[1][0] = 0;
    for(int i = 3; i < (1 << (k+1)); i += 2){
        for(int j = 1; j <= k; j++){
            if(i & (1 << j)){
                for(int j2 = 0; j2 <= k; j2++){
                    if(j == j2){
                        continue;
                    }
                    if(i & (1 << j2)){
                        dp[i][j] = min(dp[i][j], dp[i^(1<<j)][j2]+dist[a[j2]][a[j]]);
                    }
                }
            }
        }
    }
    fout << dp[(1<<(k+1))-1][k];
    return 0;
}
