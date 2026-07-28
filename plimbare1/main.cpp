#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream fin("plimbare1.in");
ofstream fout("plimbare1.out");
int n, m;
int t, x, y, z;
long long total = 0;
bool viz[100004];
vector<pair<int, int>> v[100004];
void prim(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        auto [cost, nod] = pq.top();
        pq.pop();
        if(viz[nod]){
            continue;
        }
        viz[nod] = true;
        total += cost;
        for(auto &vecin : v[nod]){
            int urm = vecin.first;
            int w = vecin.second;
            if(!viz[urm]){
                pq.push({w, urm});
            }
        }
    }
}
int main(){
    fin >> n >> m;
    for(int i = 1; i <= m; i++){
        fin >> t >> x >> y;
        if(t == 1){
            z = 0;
        }else{
            fin >> z;
        }
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }
    prim();
    fout << total;
    return 0;
}
