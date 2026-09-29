#include <fstream>
#include <vector>
using namespace std;
ifstream fin("topsort.in");
ofstream fout("topsort.out");
int n, m, x, y;
int f[100004];
vector<int> v[100004];
int coada[100004];
int main(){
    fin >> n >> m;
    for(int i = 1; i <= m; i++){
        fin >> x >> y;
        f[y]++;
        v[x].push_back(y);
    }
    int st=1, dr = 0;
    for(int i = 1; i <= n; i++){
        if(f[i] == 0){
            dr++;
            coada[dr] = i;
        }
    }
    while(st <= dr){
        fout << coada[st] << ' ' ;
        int l = v[coada[st]].size();
        for(int i = 0; i < l; i++){
            f[v[coada[st]][i]]--;
            if(f[v[coada[st]][i]] == 0){
                dr++;
                coada[dr] = v[coada[st]][i];
            }
        }
        st++;
    }
    return 0;
}
