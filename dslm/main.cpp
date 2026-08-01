#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("dslm.in");
ofstream fout("dslm.out");
int n, p;
int x, y;
vector<int> v[24];
bool viz[24][24];
int vmax = 0;
int f[34], fmax[34];
void bt(int k, int nr){
    int l = v[k].size();
    if(nr > vmax){
        vmax = nr;
        for(int i = 1; i <= nr; i++){
            fmax[i] = f[i];
        }
    }
    for(int i = 0; i < l; i++){
        if(!viz[k][v[k][i]]){
            viz[k][v[k][i]] = true;
            f[nr] = v[k][i];
            bt(v[k][i], nr+1);
            viz[k][v[k][i]] = false;
        }
    }
}
int main(){
    fin >> n >> p;
    while(fin >> x >> y){
        v[x].push_back(y);
    }
    for(int i = 1; i <= n; i++){
        sort(v[i].begin(), v[i].end());
    }
    bt(p, 1);
    fout << p << ' ';
    for(int i = 1; i < vmax; i++){
        fout << fmax[i] << ' ';
    }
    return 0;
}
