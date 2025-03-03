#include <fstream>
#include <algorithm>
#include <math.h>
using namespace std;
ifstream fin("ace.in");
ofstream fout("ace.out");
int p;
int n, m;
int a[1004][1004];
bool b[1004][1004];
int nr = 0;
int main(){
    fin >> p;
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> a[i][j];
        }
    }
    double mt = 0, t;
    for(int i = m-1; i >= 1; i--){
        t=1.0*a[n][i]/(m-i);
        if(t > mt){
            mt = t;
            nr++;
        }
    }
    mt = 0;
    for(int i = n-1; i >= 1; i--){
        t=1.0*a[i][m]/(n-i);
        if(t > mt){
            mt = t;
            nr++;
        }
    }
    int onr = nr;
    if(p == 1){
        fout << onr;
    }else{
        nr = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(b[i][j] == 0){
                    int g = __gcd(n-i, m-j);
                    if(g == 1){
                        int di = n-i;
                        int dj = m-j;
                        int k = 1;
                        long double mt = 0, t = 0;
                        /*double d = sqrt((n-i1)*(n-i1)+(m-j1)*(m-j1));
                        mt = a[i1][j1]/d;
                        b[i1][j1] = 1;
                        nr++;
                        */
                        long double d = sqrt(di*di+dj*dj);
                        while(n-k*di >= 1 && m-k*dj >= 1){
                            int i2 = n-k*di, j2 = m-k*dj;
                            t = a[i2][j2]/(k*d);
                            if(t > mt){
                                b[i2][j2] = 1;
                                mt = t;
                                nr++;
                            }
                            k++;
                        }
                    }
                }
            }
        }
        /*for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                fout << b[i][j] << ' ';
            }
            fout << '\n';
        }*/
        fout << nr;
    }
}
