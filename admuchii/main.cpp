#include <fstream>
#include <vector>
using namespace std;
#define int long long
ifstream fin("admuchii.in");
ofstream fout("admuchii.out");
int n, m, k;
int x, y, p = 0;
int s[50004];
bool viz[50004];
vector<int> v[50004], cc[50004];
int nrm[50004];
bool f[50004], fm[50004];
int vmax = 0;
long long rasp = 0;
void visit(int q){
    if(fm[q]){
        f[p] = true;
    }
    cc[p].push_back(q);
    viz[q] = true;
    int l = v[q].size();
    for(int i = 0; i < l; i++){
        if(!viz[v[q][i]]){
            viz[v[q][i]] = true;
            visit(v[q][i]);
        }
    }
}
signed main(){
    fin >> n >> m >> k;
    for(int i = 1; i <= k; i++){
        fin >> s[i];
        fm[s[i]] = true;
    }
    for(int i = 1; i <= m; i++){
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
        nrm[x]++;
        nrm[y]++;
    }
    for(int i = 1; i <= n; i++){
        if(!viz[i]){
            p++;
            visit(i);
        }
    }
    for(int i = 1; i <= p; i++){
        int l = cc[i].size();
        int raspp = 0;
        for(int j = 0; j < l; j++){
            raspp += l-nrm[cc[i][j]]-1;
        }
        raspp = raspp/2;
        rasp += raspp;
        if(f[i]){
            vmax = max(vmax, l);
        }
    }
    for(int i = 1; i <= p; i++){
        if(!f[i]){
            int l = cc[i].size();
            rasp += l*vmax;
            vmax += l;
        }
    }
    fout << rasp;
    return 0;
}
