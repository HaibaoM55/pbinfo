#include <fstream>
using namespace std;
ifstream fin("countseqmatch.in");
ofstream fout("countseqmatch.out");
int n, m, nr=0;
int a[100004];
int b[100004];
int f[100004], f1[100004];
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> a[i];
    }
    fin >> m;
    for(int i = 1; i <= m; i++){
        fin >> b[i];
        f[b[i]+50000]++;
    }
    for(int i = 1; i <= n; i++){
        f1[a[i]+50000]++;
        if(i > m){
            f1[a[i-m]+50000]--;
        }
        bool ok = true;
        for(int j = 1; j <= m; j++){
            if(f1[b[j]+50000] != f[b[j]+50000]){
                ok = false;
                break;
            }
        }
        if(ok){
            nr++;
        }
    }
    fout << nr;
    return 0;
}
