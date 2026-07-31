#include <fstream>
#include <vector>
using namespace std;
ifstream fin("subarbori.in");
ofstream fout("subarbori.out");
int n, x;
int a[104];
vector<int> v[104];
int visit(int k){
    if(a[k] != 0){
        return a[k];
    }
    int l = v[k].size();
    int r = 1;
    for(int i = 0; i < l; i++){
        r += visit(v[k][i]);
    }
    a[k] = r;
    return a[k];
}
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
        v[x].push_back(i);
    }
    for(int i = 1; i <= n; i++){
        visit(i);
    }
    int nr = 0;
    for(int p = 1; p <= n; p++){
        for(int q = p+1; q <= n; q++){
            if(a[p] == a[q] && a[p] != 1){
                nr++;
            }
        }
    }
    fout << nr;
    return 0;
}
