#include <fstream>
using namespace std;
ifstream fin("zoo.in");
ofstream fout("zoo.out");
int n, m, q;
long long s[104][104];
int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int x;
            fin >> x;
            s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+x;
        }
    }
    fin >> q;
    for(int i = 1; i <= q; i++){
        int i1, j1, i2, j2;
        fin >> i1 >> j1 >> i2 >> j2;
        fout << s[i2][j2]-s[i1-1][j2]-s[i2][j1-1]+s[i1-1][j1-1] << '\n';
    }
    return 0;
}
