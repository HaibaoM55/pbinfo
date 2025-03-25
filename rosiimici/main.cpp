#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("rosii_mici.in");
ofstream fout("rosii_mici.out");
long long n, m, q;
int x;
long long a[1004][1004], b[1000004];
int main()
{
    fin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        sort(a[i]+1, a[i]+m+1);
        for(int j = 1; j <= m; j++){
            b[a[i][j]]=max(b[a[i][j]], (long long)i*j);
        }
    }
    for(int i = 1; i <= 1000000; i++){
        b[i] = max(b[i-1], b[i]);
    }
    for(int i = 1; i <= q; i++){
        fin >> x;
        fout << b[x] << '\n';
    }
}
