#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("ff.in");
ofstream fout("ff.out");
int n, m, x, y;
int f[100004], coada[100004];
vector<int> v[100004];
int main(){
    fin >> n;
    fin >> m;
    while(fin >> x >> y){
        v[x].push_back(y);
        v[y].push_back(x);
        f[x]++;
        f[y]++;
    }
    int st = 1, dr = 0;
    for(int i = 1; i <= n; i++){
        if(f[i] < 2){
            dr++;
            coada[dr] = i;
        }
    }
    while(st <= dr){
        int l = v[coada[st]].size();
        for(int j = 0; j < l; j++){
            f[v[coada[st]][j]]--;
            if(f[v[coada[st]][j]] == 1){
                dr++;
                coada[dr] = v[coada[st]][j];
            }
        }
        st++;
    }
    fout << n-dr;
    return 0;
}
