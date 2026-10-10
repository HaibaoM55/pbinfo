#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("dfs.in");
ofstream fout("dfs.out");
int n, m, x, y;
int f[1004];
bool viz[1004];
int a[1004][1004];
vector<int> v[1004];
int nr = 0, rasp = 0;
void visit(int k){
    viz[k] = true;
    nr++;
    f[nr] = k;
    int l = v[k].size();
    for(int i = 0; i < l; i++){
        if(!viz[v[k][i]]){
            viz[v[k][i]] = true;
            visit(v[k][i]);
        }
    }
}
void visit2(int k){
    nr++;
    viz[k] = true;
    for(int i = 1; i <= n; i++){
        if(!viz[i] && a[k][i]){
            if(f[nr+1] == i){
                visit2(i);
            }else{
                a[k][i] = 0;
                a[i][k] = 0;
            }
        }
    }
}
int main(){
    fin >> n;
    fin >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j){
                continue;
            }
            a[i][j] = 2;
        }
    }
    for(int i = 1; i <= m; i++){
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
        a[x][y] = 1;
        a[y][x] = 1;
    }
    for(int i = 1; i <= n; i++){
        sort(v[i].begin(), v[i].end());
    }
    visit(1);
    for(int i = 1; i <= n; i++){
        viz[i] = false;
        fout << f[i] << ' ';
    }
    nr = 0;
    visit2(1);
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if(a[i][j] == 2){
                rasp++;
            }
        }
    }
    fout << rasp;
    return 0;
}
