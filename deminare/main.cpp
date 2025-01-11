#include <fstream>
using namespace std;
ifstream fin("deminare.in");
ofstream fout("deminare.out");
int c;
int n, m, p;
bool a[505][505];
int s[505][505];
int z=0, v[505];
int main()
{
    fin >> c;
    fin >> n >> m >> p;
    for(int i = 1; i <= p; i++){
        int x, y;
        fin >> x >> y;
        a[x][y] = true;
    }
    if(c == 1){
        int smax = 0;
        for(int i = 1; i <= n; i++){
            int s = 0;
            for(int j = 1; j <= m; j++){
                s = s + (int) a[i][j];
            }
            if(s > smax){
                smax = s;
                z = 1;
                v[z] = i;
            }else if(s == smax){
                z++;
                v[z] = i;
            }
        }
        for(int i = 1; i <= z; i++){
            fout << v[i] << ' ';
        }
    }else{
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1];
                if(a[i][j]){
                    s[i][j]++;
                }
            }
        }
        int sumax = 0;
        for(int k = 1; k <= p; k++){
            if(p % k == 0){
                int a1 = k;
                int b1 = p/k;
                if(b1 == a1){
                    continue;
                }
                for(int i = 1; i <= n-a1+1; i++){
                    for(int j = 1; j <= m-b1+1; j++){
                        //de la (i, j) pana la (i+a1-1, j+b1-1)
                        int is=i,js=j;
                        int ij=i+a1-1,jj=j+b1-1;
                        int suma = s[ij][jj] - s[is-1][jj] - s[ij][js-1] + s[is-1][js-1];
                        if(suma > sumax){
                            sumax = suma;
                        }
                    }
                }
            }
        }
        if(sumax == 0){
            fout << -1;
        }else{
            fout << p-sumax;
        }
    }
    return 0;
}
