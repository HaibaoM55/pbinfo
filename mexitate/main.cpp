#include <fstream>
#define mod 1000000007
using namespace std;
ifstream fin("mexitate.in");
ofstream fout("mexitate.out");
int n, m, k, l;
int f[400004];
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
            f[a[i][j]]++;
        }
    }
    int clm = k*l+1;
    for(int z = 1; z <= k*l; z++){
        if(f[z] == 0){
            clm = z;
            break;
        }
    }
    p = p*clm;
    p = p % mod;
    i = k;
    j =l;
    while(i <= n){
        if((i-k) % 2 == 0 && j+1 <= m){
            j++;
            for(int z = i-k+1; z <= i; z++){
                f[a[z][j]]++;
                f[a[z][j-l]]--;
                if(f[a[z][j-l]] == 0){
                    clm = min(clm, a[z][j-l]);
                }
            }
        }else if((i-k) % 2 == 1 && (j-l) >= 1){
            for(int z = i-k+1; z <= i; z++){
                f[a[z][j-l]]++;
                f[a[z][j]]--;
                if(f[a[z][j]] == 0){
                    clm = min(clm, a[z][j]);
                }
            }
            j--;
        }else{
            i++;
            if(i == n+1){
                break;
            }
            for(int z = j-l+1; z <= j; z++){
                f[a[i][z]]++;
                f[a[i-k][z]]--;
                if(f[a[i-k][z]] == 0){
                    clm = min(clm, a[i-k][z]);
                }
            }
        }
        while(f[clm]){
            clm++;
        }
        //fout << clm << ' ' << i << ' ' << j << '\n';
        p = p*clm;
        p = p%mod;
    }
    fout << p;
    return 0;
}
