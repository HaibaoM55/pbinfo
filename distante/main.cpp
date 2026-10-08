#include <fstream>
#include <vector>
using namespace std;
ifstream fin("distante.in");
ofstream fout("distante.out");
int n, m, p, q, x, y;
vector<int> v[1004];
bool viz[1004];
int coada[1004], distp[1004], distq[1004];
int main(){
    fin >> n >> m >> p >> q;
    for(int i = 1; i <= m; i++){
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int st = 1, dr = 1;
    coada[1] = p;
    distp[p] = 0;
    viz[p] = true;
    while(st <= dr){
        int k = coada[st];
        int l = v[k].size();
        for(int i = 0; i < l; i++){
            if(!viz[v[k][i]]){
                dr++;
                coada[dr] = v[k][i];
                viz[v[k][i]] = true;
                distp[v[k][i]] = distp[k]+1;
            }
        }
        st++;
    }
    for(int i = 1; i <= n; i++){
        viz[i] = false;
    }
    st = 1;
    dr = 1;
    coada[1] = q;
    distq[q] = 0;
    viz[q] = true;
    while(st <= dr){
        int k = coada[st];
        int l = v[k].size();
        for(int i = 0; i < l; i++){
            if(!viz[v[k][i]]){
                dr++;
                coada[dr] = v[k][i];
                viz[v[k][i]] = true;
                distq[v[k][i]] = distq[k]+1;
            }
        }
        st++;
    }
    for(int i = 1; i <= n; i++){
        if(i == p || i == q) continue;
        if(distp[i] == distq[i]){
            fout << i << ' ';
        }
    }
    return 0;
}
