#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("bal.in");
ofstream fout("bal.out");
int n, m, nr = 0;
int f[100004];
int b[100004];
int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        fin >> f[i];
    }
    sort(f+1, f+n+1);
    for(int i = 1; i <= m; i++){
        fin >> b[i];
    }
    sort(b+1, b+m+1);
    int j = n;
    for(int i = m; i >= 1; i--){
        while(b[i] < f[j]){
            j--;
        }
        if(j > 0){
            nr++;
            j--;
        }
        if(j <= 0){
            break;
        }
    }
    fout << nr;
    return 0;
}
