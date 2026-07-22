#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("BFS.in");
ofstream fout("BFS.out");
int n, m, k;
vector<int> v[104];
int coada[104];
bool viz[104];
int main(){
    fin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        int a, b;
        fin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        sort(v[i].begin(), v[i].end());
    }
    int st = 1, dr = 1;
    coada[1] = k;
    viz[k] = true;
    while(st <= dr){
        fout << coada[st] << ' ';
        int l = v[coada[st]].size();
        for(int i = 0; i < l; i++){
            if(!viz[v[coada[st]][i]]){
                dr++;
                coada[dr] = v[coada[st]][i];
                viz[coada[dr]] = true;
            }
        }
        st++;
    }
    return 0;
}
