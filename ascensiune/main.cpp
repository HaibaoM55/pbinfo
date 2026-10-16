#include <fstream>
#include <vector>
using namespace std;
ifstream fin("ascensiune.in");
ofstream fout("ascensiune.out");
int n, x, y;
vector<int> v[100004];
bool viz[100004];
int dist[100004];
int distmax = 0, distmaxi=0;
void dfs(int k){
    if(dist[k] > distmax){
        distmax = dist[k];
        distmaxi = k;
    }
    int l = v[k].size();
    for(int i = 0; i < l; i++){
        if(!viz[v[k][i]]){
            viz[v[k][i]] = true;
            dist[v[k][i]] = dist[k]+1;
            dfs(v[k][i]);
        }
    }
}
int main(){
    fin >> n;
    while(fin >> x >> y){
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dist[1] = 0;
    viz[1] = true;
    dfs(1);
    for(int i = 1; i <= n; i++){
        viz[i] = false;
        dist[i] = 0;
    }
    viz[distmaxi] = true;
    dfs(distmaxi);
    fout << distmax+1;
    return 0;
}
