#include <fstream>
using namespace std;
ifstream fin("maria.in");
ofstream fout("maria.out");
int n, m, p, q;
int s[1001][1001];
int k;
int main()
{
    fin >> n >> m >> p >> q;
    fin >> k;
    for(int i = 1; i <= k; i++){
        int a, b;
        fin >> a >> b;
        s[a][b]++;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+s[i][j];
        }
    }
    int zile = 0;
    for(int i = 1; i <= n-p+1; i++){
        for(int j = 1; j <= m-q+1; j++){
            int ij = i+p-1;
            int jj = j+q-1;
            if(s[ij][jj]-s[i-1][jj]-s[ij][j-1]+s[i-1][j-1] == 0){
                zile++;
            }
        }
    }
    if(p != q){
        for(int i = 1; i <= n-q+1; i++){
            for(int j = 1; j <= m-p+1; j++){
                int ij = i+q-1;
                int jj = j+p-1;
                if(s[ij][jj]-s[i-1][jj]-s[ij][j-1]+s[i-1][j-1] == 0){
                    zile++;
                }
            }
        }
    }
    fout << zile;
    return 0;
}
