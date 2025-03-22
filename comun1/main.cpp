#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("comun.in");
ofstream fout("comun.out");
int n;
int v[100005];
bool f[100005];
bool b[100005];
int w[100005];
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        f[v[i]] = true;
        b[v[i]] = true;
    }
    int vmax = v[n];
    for(int i = 1; i <= n; i++){
        if(b[v[i]]){
            int g=0;
            for(int j = 2*v[i]; j <= vmax; j += v[i]){
                if(f[j]){
                    g = __gcd(j, g);
                }
            }
            if(g == v[i]){
                b[v[i]] = false;
            }
        }
    }
    int z =0;
    for(int i = 1; i <= vmax; i++){
        if(b[i]){
            z++;
            w[z] = i;
        }
    }
    fout << z << '\n';
    for(int i = 1; i <= z; i++){
        fout << w[i] << ' ';
    }
    return 0;
}
