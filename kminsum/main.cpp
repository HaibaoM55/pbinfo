#include <fstream>
using namespace std;
ifstream fin("kminsum.in");
ofstream fout("kminsum.out");
int n, m, k;
int p = 1;
int a[1004], b[1004];
int f[1004];
int main()
{
    fin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        fin >> a[i];
        f[i] = 1;
    }
    for(int i = 1; i <= m; i++){
        fin >> b[i];
    }
    while(p <= k){
        int vmin = 2000000;
        int vmini;
        for(int i = 1; i <= n; i++){
            if(f[i] <= n){
                if(a[i]+b[f[i]] < vmin){
                    vmin = a[i]+b[f[i]];
                    vmini = i;
                }
            }
        }
        fout << a[vmini] << ' ' << b[f[vmini]] << '\n';
        f[vmini]++;
        p++;
    }
    return 0;
}
