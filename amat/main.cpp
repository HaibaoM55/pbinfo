#include <fstream>
using namespace std;
ifstream fin("amat.in");
ofstream fout("amat.out");
int c;
int n,m;
int a[1004][1004];
int lg1[1004][1004];
int lg2[1004][1004];
int mars[1004][1004];
struct plv{
    int i1, j1, i2, j2, nr;
}b[100005];
int main()
{
    fin >> c;
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> a[i][j];
        }
    }
    if(c == 1){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                for(int lg = 1; lg <= m; lg++){
                    if(a[i][j+lg-1] != a[i][j]){
                        lg1[i][j] = lg-1;
                        break;
                    }
                }
                for(int lg = 1; lg <= n; lg++){
                    if(a[i+lg-1][j] != a[i][j]){
                        lg2[i][j] = lg-1;
                        break;
                    }
                }
            }
        }
        long long vmax = 0;
        int vmaxi, vmaxj;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                long long z = lg1[i][j]*lg2[i][j];
                if(z >= vmax){
                    vmax = z;
                    vmaxi = i;
                    vmaxj = j;
                }
            }
        }
        fout << vmaxi << " " << vmaxj << " " << vmaxi+lg2[vmaxi][vmaxj]-1 << " " << vmaxj+lg1[vmaxi][vmaxj]-1;
    }else{
        int q, k;
        fin >> q >> k;
        for(int i = 1; i <= q; i++){
            fin >> b[i].i1 >> b[i].j1 >> b[i].i2 >> b[i].j2 >> b[i].nr;
            mars[b[i].i1][b[i].j1] += b[i].nr;
            mars[b[i].i1][b[i].j2 + 1] -= b[i].nr;
            mars[b[i].i2 + 1][b[i].j1] -= b[i].nr;
            mars[b[i].i2 + 1][b[i].j2 + 1] += b[i].nr;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                mars[i][j] += mars[i-1][j]+mars[i][j-1]-mars[i-1][j-1];
                a[i][j] = a[i][j]+mars[i][j]-k;
            }
        }
        for(int i = q; i >= 1; i--){
            bool ok = true;
            for(int p1 = b[i].i1; p1 <= b[i].i2 && ok; p1++){
                for(int p2 = b[i].j1; p2 <= b[i].j2; p2++){
                    a[p1][p2] = a[p1][p2]-b[i].nr;
                    if(a[p1][p2] < 0){
                        ok = false;
                        break;
                    }
                }
            }
            if(ok == false){
                fout << i <<'\n';
                break;
            }
        }
    }
    return 0;
}
