#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("nivelepare.in");
ofstream fout("nivelepare.out");
int n, x;
vector<int> v[104], niv[104];
bool viz[104];
int vmax = 0;
void visit(int k, int nivel){
    if(nivel % 2 != 0 && nivel != 0){
        niv[nivel/2].push_back(k);
        vmax = max(vmax, nivel/2);
    }
    int l = v[k].size();
    for(int i = 0; i < l; i++){
        if(!viz[v[k][i]]){
            viz[v[k][i]] = true;
            visit(v[k][i], nivel+1);
        }
    }
}
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
        v[x].push_back(i);
    }
    visit(0, 0);
    for(int i = 0; i <= vmax; i++){
        sort(niv[i].begin(), niv[i].end());
        int l = niv[i].size();
        for(int j = 0; j < l; j++){
            fout << niv[i][j] << ' ';
        }
        fout << '\n';
    }
    return 0;
}
