#include <fstream>
using namespace std;
ifstream fin("zoom_poza.in");
ofstream fout("zoom_poza.out");
int c;
int n, m, z;
int main()
{
    fin >> c;
    if(c == 1){
        int a[1001][1001];
        fin >> n >> m;
        fin >> z;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                fin >> a[i][j];
            }
        }
        for(int i = 1; i <= n*z; i++){
            for(int j = 1; j <= m*z; j++){
                fout<<a[(i-1)/z+1][(j-1)/z+1] << " ";
            }
            fout << "\n";
        }
    }else{
        long long a[1001][1001];
        fin >> n >> m;
        fin >> z;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                fin >> a[i][j];
            }
        }
        int q;
        fin >> q;
        for(int i = 1; i <= q; i++){
            long long l1, c1;
            fin >> l1 >> c1;
            fout << a[(l1-1)/z+1][(c1-1)/z+1] << " ";
        }
    }
    return 0;
}
