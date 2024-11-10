#include <fstream>
using namespace std;
ifstream fin("spirala2.in");
ofstream fout("spirala2.out");
#define MOD 100003
int p;
int n, k;
int a[505][505];
int main()
{
    fin >> p;
    fin >> n >> k;
    int z = 0;
    for(int c = 0; c <= n/2; c++){
        for(int j = 1; j <= n; j++){
            if(a[c+1][j] == 0){
                z++;
                a[c+1][j]=z;
            }
        }
        for(int i = 1; i <= n; i++){
            if(a[i][n-c] == 0){
                z++;
                a[i][n-c]=z;
            }
        }
        for(int j = n; j >= 1; j--){
            if(a[n-c][j] == 0){
                z++;
                a[n-c][j] = z;
            }
        }
        for(int i = n; i >= 1; i--){
            if(a[i][c+1] == 0){
                z++;
                a[i][c+1] = z;
            }
        }
    }
    if(p == 1){
        long long s = 0;
        for(int i = 1; i <= n; i++){
            if(i == k){
                continue;
            }
            s = s + a[i][k]%MOD + a[k][i]%MOD;
        }
        fout << s;
    }else{
        for(int i = 1; i <= n; i++){
            if(i == k){
                continue;
            }
            int aux = a[i][k];
            a[i][k] = a[k][i];
            a[k][i] = aux;
        }
        for(int i = 1;  i <= n; i++){
            for(int j = 1; j <= n; j++){
                fout << a[i][j] << ' ';
            }
            fout << '\n';
        }
    }
    return 0;
}
