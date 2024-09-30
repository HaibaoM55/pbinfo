#include <fstream>
using namespace std;
ifstream fin("matrix_replace.in");
ofstream fout("matrix_replace.out");
int n, k;
int a[154][154];
int lmax = 1;
int mn = 0;
int main()
{
    fin >> n >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            fin >> a[i][j];
        }
    }
    for(int i = 1; i <= n-lmax+1; i++){
        for(int j = 1; j <= n-lmax+1; j++){
            int f[101] = {0};
            int fmax = 1;
            f[a[i][j]]++;
            for(int lg = 2; lg <= min(n-i+1, n-j+1); lg++){
                for(int p = j; p <= j+lg-1; p++){
                    f[a[i+lg-1][p]]++;
                    if(f[a[i+lg-1][p]] > fmax){
                        fmax = f[a[i+lg-1][p]];
                    }
                }
                for(int p = i; p < i+lg-1; p++){
                    f[a[p][j+lg-1]]++;
                    if(f[a[p][j+lg-1]] > fmax){
                        fmax = f[a[p][j+lg-1]];
                    }
                }
                if(lg*lg-fmax <= k){
                    if(lmax < lg){
                        lmax = lg;
                        mn = lg*lg-fmax;
                    }else if(lmax == lg){
                        if(lg*lg-fmax < mn){
                            mn = lg*lg-fmax;
                        }
                    }
                }else{
                    break;
                }
            }
        }
    }
    fout << lmax << ' ' << mn;
    return 0;
}
