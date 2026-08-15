#include <fstream>
#include <vector>
using namespace std;
ifstream fin("detdrum2.in");
ofstream fout("detdrum2.out");
int n, p, q;
int t[104], f[104], v[104];
int lca(int p, int q){
    while(t[p] != 0){
        p = t[p];
        f[p]++;
    }
    while(t[q] != 0){
        q = t[q];
        f[q]++;
        if(f[q] == 2){
            return q;
        }
    }
    return 0;
}
int main(){
    fin >> n >> p >> q;
    for(int i = 1; i <= n; i++){
        fin >> t[i];
    }
    int comun = lca(p, q);
    while(p != comun){
        fout << p << ' ';
        p = t[p];
    }
    fout << comun << ' ';
    int z = 0;
    while(q != comun){
        z++;
        v[z] = q;
        q = t[q];
    }
    for(int i = z; i >= 1; i--){
        fout << v[i] << ' ';
    }
    return 0;
}
