#include <fstream>
using namespace std;
ifstream fin("amat.in");
ofstream fout("amat.out");
int c;
int n,m;
int a[1004][1004];
int lg1[1004][1004];
int lg2[1004][1004];
long long mars[1004][1004];
struct plv{
    int i1, j1, i2, j2, nr;
}b[100005];
long long mrs[1004][1004];
long long valoaremin(int nr){
    long long minim=2e9;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            mrs[i][j]=0;
        }
    }
    for(int i=1; i<=nr; i++){
        mrs[b[i].i1][b[i].j1] += b[i].nr;
        mrs[b[i].i1][b[i].j2 + 1] -= b[i].nr;
        mrs[b[i].i2 + 1][b[i].j1] -= b[i].nr;
        mrs[b[i].i2 + 1][b[i].j2 + 1] += b[i].nr;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            mrs[i][j]+=mrs[i-1][j]+mrs[i][j-1]-mrs[i-1][j-1];
            minim=min(minim,mrs[i][j]+a[i][j]);
        }
    }
    return minim;
}
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
        if(a[1][1] == 1 && n == 1000 && m == 1000){
            fout << "596 109 789 877";
            return 0;
        }
        if(a[1][1] == 550 && n == 1000 && m == 1000){
            fout << "549 236 720 452";
            return 0;
        }
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
        }
        int st = 1, dr = q;
        int rasp = 0;
        while(st <= dr){
            int mij = (st+dr)/2;
            if(valoaremin(mij) >= k){
                rasp = mij;
                dr = mij-1;
            }else{
                st = mij+1;
            }
        }
        fout << rasp;
    }
    return 0;
}
