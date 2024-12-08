#include <fstream>
using namespace std;
ifstream fin("matrix.in");
ofstream fout("matrix.out");
int n, m;
int k;
long long a[1504][1504], b[1504][1504];
long long M[1504][1504];
int i=1;
int main()
{
    fin >> n >> m;
    int ok = 0;
    int nrk = 0;
    while(i <= m){
        fin >> k;
        if(k == 1){
            int i1, i2, j1, j2, x;
            fin >> i1 >> j1 >> i2 >> j2 >> x;
            M[i1][j1] += x;
            M[i1][j2+1] -= x;
            M[i2+1][j1] -= x;
            M[i2+1][j2+1] += x;
        }else{
            if(ok == 1){
                for(int i1 = 1; i1 <= n; i1++){
                    for(int j1 = 1; j1 <= n; j1++){
                        M[i1][j1] += M[i1-1][j1]+M[i1][j1-1]-M[i1-1][j1-1];
                        a[i1][j1] = a[i1][j1]+M[i1][j1];
                    }
                }
                for(int i1 = 1; i1 <= n; i1++){
                    for(int j1 = 1; j1 <= n; j1++){
                        M[i1][j1] = 0;
                    }
                }
            }
            if(k == 2){
                int nrk;
                fin >> nrk;
                nrk = nrk%4;
                for(int p = 1; p <= nrk; p++){
                    for(int x = 1; x <= n; x++){
                        for(int y = 1; y <= n; y++){
                            b[x][y] = a[x][y];
                        }
                    }
                    int i1=1, j1 = 0;
                    for(int y = n; y >= 1; y--){
                        for(int x = 1; x <= n; x++){
                            j1++;
                            a[i1][j1] = b[x][y];
                        }
                        i1++;
                        j1 = 0;
                    }
                }
            }else if(k == 3){
                for(int x = 1; x <= n; x++){
                    for(int y = 1; y <= n; y++){
                        b[x][y] = a[x][y];
                    }
                }
                int z = n;
                for(int x = 1; x <= n; x++){
                    for(int y = 1; y <= n; y++){
                        a[x][y] = b[z][y];
                    }
                    z--;
                }
            }else{
                for(int x = 1; x <= n; x++){
                    for(int y = 1; y <= n; y++){
                        b[x][y] = a[x][y];
                    }
                }
                int z = n;
                for(int y = 1; y <= n; y++){
                    for(int x = 1; x <= n; x++){
                        a[x][y] = b[x][z];
                    }
                    z--;
                }
            }
        }
        ok = k;
        i++;
    }
    if(ok == 1){
        for(int i1 = 1; i1 <= n; i1++){
            for(int j1 = 1; j1 <= n; j1++){
                M[i1][j1] += M[i1-1][j1]+M[i1][j1-1]-M[i1-1][j1-1];
                a[i1][j1] = a[i1][j1]+M[i1][j1];
            }
        }
        for(int i1 = 1; i1 <= n; i1++){
            for(int j1 = 1; j1 <= n; j1++){
                M[i1][j1] = 0;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            fout << a[i][j] << ' ';
        }
        fout << '\n';
    }
    return 0;
}
