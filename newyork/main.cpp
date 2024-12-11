#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("nyk.in");
ofstream fout("nyk.out");
long long  n, m;
long long  x;
long long gmax=0, vmaxi, vmaxj;
bool esteprim(long long  x){
    if(x <= 1){
        return false;
    }
    for(int j = 2; j*j <= x; j++){
        if(x % j == 0){
            return false;
        }
    }
    return true;
}
long long v[1004][1004];
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> m;
        long long  j1=0;
        long long  jmax = 0;
        long long g;
        for(int j = 1; j <= m; j++){
            fin >> v[i][j];
            if(j == 1){
                g = v[i][1];
            }else{
                g = __gcd(g, v[i][j]);
            }
            if(esteprim(v[i][j]) && v[i][j] >= jmax){
                jmax = v[i][j];
                j1 = j;
            }
        }
        if(g >= gmax){
            gmax = g;
            vmaxi = i;
            vmaxj = j1;
        }
    }
    if(gmax > 0){
        fout << vmaxi << ' ' << vmaxj <<'\n';
        fout << gmax;
    }else{
        fout << "Nu am gasit casa!";
    }
    return 0;
}
