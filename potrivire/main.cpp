#define mn p[x].x[p[x].z]
#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("potrivire.in");
ofstream fout("potrivire.out");
int n, m;
int cif[100004];
int f[100004];
bool nrcorect[100005];
long long s;
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> cif[i];
    }
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= n-i+1; j++){
            int numar = 0;
            for(int m = j; m <= j+i-1; m++){
                numar = numar*10+cif[m];
            }
            nrcorect[numar] = true;
        }
    }
    fin >> m;
    for(int i = 1; i <= m; i++){
        int nr;
        fin >> nr;
        if(f[nr] == false){
            if(nrcorect[nr]){
                s += nr;
            }
        }
        f[nr] = true;
    }
    fout << s;
    return 0;
}
