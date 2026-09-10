#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
ifstream fin("unire.in");
ofstream fout("unire.out");
int n, m, x, y, cer;
int nr = 0;
bool viz[100004];
vector<int> v[100004];
vector<int> f;
void visit(int k){
    viz[k] = true;
    int l = v[k].size();
    for(int i = 0; i < l; i++){
        if(!viz[v[k][i]]){
            viz[v[k][i]] = true;
            visit(v[k][i]);
        }
    }
}
signed main(){
    fin >> n >> m;
    fin >> cer;
    for(int i = 1; i <= m; i++){
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        if(!viz[i]){
            f.push_back(i);
            visit(i);
        }
    }
    int l = f.size();
    l--;
    if(cer == 1){
        fout << l << '\n';
    }
    int rasp = 0;
    for(int i = 1; i <= l; i++){
        rasp += f[i]+1;
    }
    if(cer == 2){
        fout << rasp;
    }
    return 0;
}
