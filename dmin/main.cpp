#include <fstream>
#include <vector>
using namespace std;
ifstream fin("dmin.in");
ofstream fout("dmin.out");
int n, m, x, y, q;
vector<int> v[104];
int dist(int a, int b){
    pair<int, int> coada[104];
    bool viz[104];
    for(int i = 1; i <= n; i++){
        viz[i] = false;
    }
    int st = 1, dr = 1;
    coada[1] = {a,0};
    while(st <= dr){
        int k = coada[st].first;
        if(k == b) return coada[st].second;
        int l = v[k].size();
        for(int i = 0; i < l; i++){
            if(!viz[v[k][i]]){
                viz[v[k][i]] = true;
                dr++;
                coada[dr] = {v[k][i], coada[st].second+1};
            }
        }
        st++;
    }
    return 0;
}
int main(){
    fin >> n >> m;
    for(int i = 1; i <= m; i++){
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    fin >> q;
    while(q){
        fin >> x >> y;
        fout << dist(x, y) << '\n';
        q--;
    }
    return 0;
}
