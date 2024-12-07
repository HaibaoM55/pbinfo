#include <fstream>
using namespace std;
ifstream fin("trafalet.in");
ofstream fout("trafalet.out");
int n, m;
int a[504][504];
long long v[504];
long long s[504][504];
long long smax = 0;
int main()
{
    fin >>n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> a[i][j];
            if((i+j) % 2 == 0){
                a[i][j] = -a[i][j];
            }
        }
    }
    for(int i1 = 1; i1 <= n; i1++){
        for(int j = 1; j <= m; j++){
            v[j] = 0;
        }
        for(int i2 = i1; i2 <= n; i2++){
            for(int j = 1; j <= m; j++){
                v[j] += a[i2][j];
            }
            long long suma = 0;
            long long smin1 = 0, smax1 = 0;
            for(int j = 1; j <= m; j++){
                suma = suma+v[j];
                if(suma-smin1 > smax){
                    smax = suma-smin1;
                }
                if(suma < smin1){
                    smin1 = suma;
                }
                if(-suma+smax1 > smax){
                    smax = -suma+smax1;
                }
                if(suma > smax1){
                    smax1 = suma;
                }
            }
        }
    }
    fout << smax;
    return 0;
}
