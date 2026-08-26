#include <fstream>
#include <vector>
using namespace std;
ifstream fin("biperm.in");
ofstream fout("biperm.out");
int n;
int a[10004], b[10004];
int fa[10004], fb[10004];
int nr = 0;
bool viz[10004];
vector<int> v[10004];
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
bool avoid[10004];
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        fin >> b[i];
        if(a[i] == b[i]){
            avoid[a[i]] = true;
        }
        v[b[i]].push_back(a[i]);
        v[a[i]].push_back(b[i]);
    }
    long long p = 1;
    for(int i = 1; i <= n; i++){
        if(avoid[i]){
            viz[i] = true;
            continue;
        }
        if(!viz[i]){
            visit(i);
            p = p*2;
        }
    }
    fout << p << ' ' << -1 << '\n';
    for(int i = 1; i <= n; i++){
        fout << a[i] << ' ';
    }
    fout << '\n';
    for(int i = 1; i <= n; i++){
        fout << b[i] << ' ';
    }
    return 0;
}
