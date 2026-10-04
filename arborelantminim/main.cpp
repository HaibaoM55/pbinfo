#include <fstream>
#include <vector>
using namespace std;
ifstream fin("arborelantmaxim.in");
ofstream fout("arborelantmaxim.out");
int n, x, y, z;
vector<pair<int, int>> v[100004];
int dist[100004];
int rasp = 0;
void stabileste_parinti(int k, int tata){
    int suma1 = 0;
    int suma2 = 0;
    int l = v[k].size();
    for(int i = 0; i < l; i++){
        if(v[k][i].first == tata){
            continue;
        }
        stabileste_parinti(v[k][i].first, k);
        int d = dist[v[k][i].first]+v[k][i].second;
        dist[k] = max(dist[k], d);
        if(d > suma1){
            suma2 = suma1;
            suma1 = d;
        }else if(d > suma2){
            suma2 = d;
        }
    }
    rasp = max(rasp, suma1+suma2);
}
int main(){
    fin >> n;
    for(int i = 1; i < n; i++){
        fin >> x >> y >> z;
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }
    stabileste_parinti(1, 0);
    fout << rasp;
    return 0;
}
