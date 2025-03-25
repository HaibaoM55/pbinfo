#include <fstream>
#define mod 1000000007
using namespace std;
ifstream fin("mexitate.in");
ofstream fout("mexitate.out");
int n, m, k, l;
int f[654][654];
/*
f[650][650]
f[i][0] = nr elm
*/
long long p = 1;
int main()
{
    fin >> n >> m >> k >> l;
    int a[n+4][m+4];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> a[i][j];
        }
    }
    int r = 0;
    int i, j;
    for(i = 1; i <= k; i++){
        for(j = 1; j <= l; j++){
            f[a[i][j]/650][a[i][j]%650]++;
        }
    }
    int clm = 651;
    for(int z1 = 0; z1 <= 650; z1++){
        for(int z2 = 0; z2 <= 650; z2++){
            if(f[z1][z2] == 0){
                f[z1][0]++;
            }
        }
    }
    bool ok = true;
    for(int z1 = 0; z1 <= 650 && ok; z1++){
        if(f[z1][0] > 0){
            clm = min(clm, z1);
            for(int z2 = 0; z2 < 650; z2++){
                if(f[z1][z2] == 0){
                    p = p *(z1*650+z2);
                    p = p % mod;
                    ok = false;
                    break;
                }
            }
        }
    }
    if(ok){
        p = p*422501;
        p = p %mod;
    }
    i = k;
    j =l;
    while(i <= n){
        if((i-k) % 2 == 0 && j+1 <= m){
            j++;
            for(int z = i-k+1; z <= i; z++){
                f[a[z][j]/650][a[z][j]%650]++;
                if(f[a[z][j]/650][a[z][j]%650] == 1){
                    f[a[z][j]/650][0]--;
                }
                f[a[z][j-l]/650][a[z][j-l]%650]--;
                if(f[a[z][j-l]/650][a[z][j-l]%650] == 0){
                    f[a[z][j-l]/650][0]++;
                    clm = min(clm, a[z][j-l]/650);
                }
            }
        }else if((i-k) % 2 == 1 && (j-l) >= 1){
            for(int z = i-k+1; z <= i; z++){
                f[a[z][j-l]/650][a[z][j-l]%650]++;
                if(f[a[z][j-l]/650][a[z][j-l]%650] == 1){
                    f[a[z][j-l]/650][0]--;
                }
                f[a[z][j]/650][a[z][j]%650]--;
                if(f[a[z][j]/650][a[z][j]%650] == 0){
                    f[a[z][j]/650][0]++;
                    clm = min(clm, a[z][j]/650);
                }
            }
            j--;
        }else{
            i++;
            if(i == n+1){
                break;
            }
            for(int z = j-l+1; z <= j; z++){
                f[a[i][z]/650][a[i][z]%650]++;
                if(f[a[i][z]/650][a[i][z]%650] == 1){
                    f[a[i][z]/650][0]--;
                }
                f[a[i-k][z]/650][a[i-k][z]%650]--;
                if(f[a[i-k][z]/650][a[i-k][z]%650] == 0){
                    f[a[i-k][z]/650][0]++;
                    clm = min(clm, a[i-k][z]/650);
                }
            }
        }
        bool ok = true;
        for(int z1 = clm; z1 <= 650 && ok; z1++){
            if(f[z1][0] > 0){
                clm = z1;
                for(int z2 = 0; z2 < 650; z2++){
                    if(f[z1][z2] == 0){
                        p = p *(z1*650+z2);
                        p = p % mod;
                        ok = false;
                        break;
                    }
                }
            }
        }
    }
    fout << p;
    return 0;
}
