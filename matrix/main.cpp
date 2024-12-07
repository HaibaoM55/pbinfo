#include <fstream>
using namespace std;
ifstream fin("matrix.in");
ofstream fout("matrix.out");
int n, m;
int k;
long long a[1504][1504], b[1504][1504];
long long mrs[1504][1504];
int i;
int main()
{
    fin >> n >> m;
    /*for(int i = 1; i <= m; i++){
        fin >> k;
        if(k == 1){
            int i1, i2, j1, j2, x;
            fin >> i1 >> j1 >> i2 >> j2 >> x;
            for(int x1 = i1; x1 <= i2; x1++){
                for(int y = j1; y <= j2; y++){
                    a[x1][y] += x;
                }
            }
        }else if(k == 2){
        }else if(k == 3){

        }else{
        }
    }*/
    int ok = 0;
    int nrk = 0;
    while(i <= n){
        fin >> k;
        if(k == 1){
            int i1, i2, j1, j2, x;
            fin >> i1 >> j1 >> i2 >> j2 >> x;
            mrs[i1][j1] += x;
            mrs[i1][j2+1] -= x;
            mrs[i2+1][j1] -= x;
            mrs[i2+1][j2+1] += x;
        }else if(k == 2){
            int nrm;
            fin >> nrm;
            nrk = (nrk+nrm)%4;
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
        }else if(k == 4){
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
        if(k != ok){
            if(ok == 1){
                for(int i = 1 ; i <= n ; i ++){
                    for(int j = 1; j <= m ; j ++){
                        mrs[i][j] = mrs[i][j] + mrs[i-1][j] + mrs[i][j-1] - mrs[i-1][j-1];
                        a[i][j] = a[i][j]+mrs[i][j];
                    }
                }
                for(int i = 1; i<= n; i++){
                    for(int j = 1; j <= m; j++){
                        mrs[i][j] = 0;
                    }
                }
            }else if(ok == 2){
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
                nrk = 0;
            }
        }
        ok = k;
        i++;
    }
    if(ok == 1){
        for(int i = 1 ; i <= n ; i ++){
            for(int j = 1; j <= m ; j ++){
                mrs[i][j] = mrs[i][j] + mrs[i-1][j] + mrs[i][j-1] - mrs[i-1][j-1];
                a[i][j] = a[i][j]+mrs[i][j];
            }
        }
        for(int i = 1; i<= n; i++){
            for(int j = 1; j <= m; j++){
                mrs[i][j] = 0;
            }
        }
    }else if(ok == 2){
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
        nrk = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            fout << a[i][j] << ' ';
        }
        fout << '\n';
    }
    return 0;
}
