#include <fstream>
#include <vector>
using namespace std;
ifstream fin("ghiocel2.in");
ofstream fout("ghiocel2.out");
int n, m, g, x, y, kk;
vector<int> v[104];
bool viz[104];
int b[104];
void visit(int pp){
    int k = pp;
    viz[k] = true;
    pair<int, int> coada[104];
    int st = 1, dr = 1;
    coada[1] = {k, 0};
    int final1 = kk;
    while(st <= dr){
        if(coada[st].second == final1) break;
        k = coada[st].first;
        int l = v[k].size();
        for(int i = 0; i < l; i++){
            if(!viz[v[k][i]]){
                viz[v[k][i]] = true;
                dr++;
                coada[dr] = {v[k][i], coada[st].second+1};
                if(b[v[k][i]] == 1){
                    b[v[k][i]] = 2;
                }
            }
        }
        st++;
    }
}
int main(){
    fin >> n >> m >> g;
    for(int i = 1; i <= m; i++){
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        b[i] = 1;
    }
    fin >> kk;
    b[g] = 0;
    visit(g);
    int nr = 0;
    for(int i = 1; i <= n; i++){
        if(b[i] == 2){
            nr++;
        }
    }
    fout << nr;
    return 0;
}
