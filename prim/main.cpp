#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream fin("prim.in");
ofstream fout("prim.out");
int n, m;
int x, y, z;
vector<pair<int, int>> v[104];
bool viz[104];
int t[104];
int total = 0;
void prim(){
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {1, 0}});
    int old = 0;
    while(!pq.empty()){
        auto [cost, p] = pq.top();
        auto [nod, parinte] = p;
        pq.pop();
        if(viz[nod]){
            continue;
        }
        viz[nod] = true;
        t[nod] = parinte;
        total += cost;
        for(auto &vecin : v[nod]){
            int urm = vecin.first;
            int w = vecin.second;
            if(!viz[urm]){
                pq.push({w, {urm, nod}});
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
    prim();
    fout << total << '\n';
    for(int i = 1; i <= n; i++){
        fout << t[i] << ' ';
    }
    return 0;
}
