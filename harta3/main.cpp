#include <fstream>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
ifstream fin("harta3.in");
ofstream fout("harta3.out");
int n;
struct poz{
    int i, j;
}p[104];
bool viz[104];
vector<pair<double, int>> v[104];
double rasp = 0;
double dist(int x, int y){
    return sqrt(1.0*(p[x].i-p[y].i)*(p[x].i-p[y].i)+1.0*(p[x].j-p[y].j)*(p[x].j-p[y].j));
}
void prim(){
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        double cost = pq.top().first;
        int nod = pq.top().second;
        pq.pop();
        if(viz[nod]){
            continue;
        }
        viz[nod] = true;
        rasp += cost;
        for(auto &vecin : v[nod]){
            int urm = vecin.second;
            double w = vecin.first;
            if(!viz[urm]){
                pq.push({w, urm});
            }
        }
    }
}
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> p[i].i >> p[i].j;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j){
                continue;
            }
            v[i].push_back({dist(i, j), j});
        }
    }
    prim();
    fout << rasp;
    return 0;
}
