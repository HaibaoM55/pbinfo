#include <fstream>
#include <math.h>
#include <algorithm>
using namespace std;
ifstream fin("partitura.in");
ofstream fout("partitura.out");
int n;
long long a[20][300004];
bool compara(long long a, long long b){
    if(a > b){
        return true;
    }else{
        return false;
    }
}
long long z[20];
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        int x, y;
        fin >> x >> y;
        z[x]++;
        a[x][z[x]] = y;
    }
    for(int i = 18; i >= 1; i--){
        sort(a[i]+1, a[i]+z[i]+1, compara);
        for(int j = 1; j <= z[i]; j = j+2){
            z[i-1]++;
            a[i-1][z[i-1]] = a[i][j] + a[i][j+1];
        }
    }
    long long s = 0;
    for(int i = 1; i <= z[0]; i++){
        s += a[0][i] * a[0][i];
    }
    fout << s;
    return 0;
}
