#include <fstream>
using namespace std;
ifstream fin("tort.in");
ofstream fout("tort.out");
int n, m, l;
int s[504][504];
int smax=0, nr=0;
int main(){
    fin >> n >> m >> l;
    for(int i=1;i <= n;i++){
        for(int j=1;j <= m;j++){
            int x;
            fin >> x;
            s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+x;
        }
    }
    for(int i=0; i<=l; i++){
        for(int j=0; j<=l-i; j++){
            for(int h=0; h<=l-i-j; h++){
                int g=l-h-i-j;
                int suma=s[i][m]+s[n][m]-s[n][m-j]-s[i][m]+s[i][m-j]+s[n][m-j]-s[n-h][m-j]+s[n-h][g]-s[i][g];
                if(suma > smax){
                    smax=suma;
                    nr=1;
                }else if(suma==smax){
                    nr++;
                }
            }
        }
    }
    fout << smax << '\n';
    fout << nr;
    return 0;
}
