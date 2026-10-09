#include <fstream>
#include <vector>
using namespace std;
ifstream fin("epidemie.in");
ofstream fout("epidemie.out");
int n, m, p, q, x, y;
vector<int> v[1004];
bool viz[1004];
int coada[1004], distp[1004], distq[1004];
int main(){
    fin >> n >> m;
    for(int i = 1; i <= m; i++){
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int st = 1, dr = 0;
    fin >> dr;
    for(int i = 1; i <= dr; i++){
        fin >> x;
        viz[x] = true;
        distp[x] = 1;
        coada[i] = x;
    }
    int vmax = 1;
    while(st <= dr){
        int k = coada[st];
        vmax = distp[k];
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
    fout << vmax;
    return 0;
}
