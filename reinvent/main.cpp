#include <fstream>
#include <vector>
using namespace std;
ifstream fin("reinvent.in");
ofstream fout("reinvent.out");
int n, m, x, y, z;
vector<int> v[100004];
int a[100004];
bool b[100004], viz[100004];
int coada[100004];
int f[100004], g[100004];
int main(){
    fin >> n >> m >> x;
    for(int i = 1; i <= m; i++){
        fin >> y >> z;
        v[y].push_back(z);
        v[z].push_back(y);
    }
    for(int i = 1; i <= x; i++){
        fin >> a[i];
        b[a[i]] = true;
        coada[i] = a[i];
        f[a[i]] = 0;
        viz[a[i]] = true;
        g[a[i]] = a[i];
    }
    int st = 1, dr = x;
    while(st <= dr){
        int k = coada[st];
        int l = v[k].size();
        for(int i = 0; i < l; i++){
            if(!viz[v[k][i]]){
                viz[v[k][i]] = true;
                dr++;
                coada[dr] = v[k][i];
                f[v[k][i]] = f[k]+1;
                g[v[k][i]] = g[k];
            }else if(g[v[k][i]] != g[k]){
                fout << f[v[k][i]]+f[k]+1;
                return 0;
            }
        }
        st++;
    }
    return 0;
}
