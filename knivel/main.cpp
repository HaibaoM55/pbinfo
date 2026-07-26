#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("knivel.in");
ofstream fout("knivel.out");
int n, x, y;
vector<int> v[104], f[104];
bool viz[104];
void visit(int k, int nivel){
    viz[k] = true;
    f[nivel].push_back(k);
    int l = v[k].size();
    for(int i = 0; i < l; i++){
        if(!viz[v[k][i]]){
            viz[v[k][i]] = true;
            visit(v[k][i], nivel+1);
        }
    }
}
int main(){
    fin >> n >> y;
    for(int i = 1; i <= n; i++){
        fin >> x;
        v[x].push_back(i);
    }
    visit(0, 0);
    int l = f[y].size();
    sort(f[y].begin(), f[y].end());
    for(int i = 0; i < l; i++){
        fout << f[y][i] << ' ';
    }
    return 0;
}
