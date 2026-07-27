#include <fstream>
using namespace std;
ifstream fin("saturate.in");
ofstream fout("saturate.out");
int n, m;
int x, y;
int f[104];
int main(){
    fin >> n >> m;
    for(int i = 1; i <= m; i++){
        fin >> x >> y;
        f[x]++;
        f[y]++;
    }
    bool ok = false;
    for(int i = 1; i <= n; i++){
        if(f[i] >= n/2+n%2){
            fout << i << ' ';
            ok = true;
        }
    }
    if(!ok){
        fout << "Nu exista";
    }
    return 0;
}
