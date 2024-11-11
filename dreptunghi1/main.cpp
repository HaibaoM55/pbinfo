#include <fstream>
using namespace std;
ifstream fin("dreptunghi1.in");
ofstream fout("dreptunghi1.out");
int n, m, z;
int l, c;
int a[1004][1004];
int s[1004][1004];
int amax = 0;
int main()
{
    fin >> n >> m >> z;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            a[i][j] = 1;
        }
    }
    for(int i = 1; i <= z; i++){
        fin >> l >> c;
        a[l][c] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int l = 1; l <= n-i+1; l++){
                for(int L = amax/l; L <= m-j+1; L++){
                    int is=i,js=j; // coltul stanga sus
                    int ij=i+l-1,jj=j+L-1; // coltul dreapta jos
                    int b;
                    b = s[ij][jj] - s[is-1][jj] - s[ij][js-1] + s[is-1][js-1];
                    if(b == l*L){
                        amax = max(amax, l*L);
                    }
                }
            }
        }
    }
    fout << amax;
    return 0;
}
