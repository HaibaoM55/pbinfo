#include <fstream>
using namespace std;
ifstream fin("memory003.in");
ofstream fout("memory003.out");
int n, m, p;
int x, nr = 0;
long long f[1004];
int main()
{
    fin >> n >> m >> p;
    for(int j = 1; j <= m; j++){
        f[j] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> x;
            if(f[j] != 0){
                f[j] = (f[j]*x)%p;
            }
        }
    }
    for(int i = 1; i <= m; i++){
        if(f[i] == 0){
            nr++;
        }
    }
    fout << nr;
    return 0;
}
