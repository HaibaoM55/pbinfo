#include <fstream>
#include <bitset>
#include <vector>
using namespace std;
ifstream fin("drumuri.in");
ofstream fout("drumuri.out");
int n, m, x, y;
vector<int> v1[150004], v2[150004];
int f1[150004], f2[150004];
bool viz[150004];
int coada[150004];
int main(){
    fin >> n >> m;
    for(int i = 1; i <= m; i++){
        fin >> x >> y;
        v1[x].push_back(y);
        v2[y].push_back(x);
        f1[x]++;
        f2[y]++;
    }
    int st = 1, dr = 0;
    for(int i = 1; i <= n; i++){
        if(f1[i] == 0){
            dr++;
            coada[dr] = i;
        }
        f1[i] = 0;
    }
    while(st <= dr){
        int k = coada[st];
        int l = v2[k].size();
        for(int i = 0; i < l; i++){
            f1[v2[k][i]] += f1[k]+1;
            if(!viz[v2[k][i]]){
                viz[v2[k][i]] = true;
                dr++;
                coada[dr] = v2[k][i];
            }
        }
        st++;
    }
    st = 1;
    dr = 0;
    for(int i = 1; i <= n; i++){
        viz[i] = false;
        if(f2[i] == 0){
            dr++;
            coada[dr] = i;
        }
        f2[i] = 0;
    }
    while(st <= dr){
        int k = coada[st];
        int l = v1[k].size();
        for(int i = 0; i < l; i++){
            f2[v1[k][i]] += f2[k]+1;
            if(!viz[v1[k][i]]){
                viz[v1[k][i]] = true;
                dr++;
                coada[dr] = v1[k][i];
            }
        }
        st++;
    }
    int nr = 0;
    for(int i = 1; i <= n; i++){
        if(f1[i]+f2[i] == n-1){
            nr++;
        }
    }
    fout << nr << '\n';
    for(int i = 1; i <= n; i++){
        if(f1[i]+f2[i] == n-1){
            fout << i << ' ';
        }
    }
    return 0;
}
