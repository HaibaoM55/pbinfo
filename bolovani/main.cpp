#include <fstream>
#include <algorithm>
using namespace std;
#define int long long
ifstream fin("bolovani.in");
ofstream fout("bolovani.out");
int n;
struct bolovan{
    long long z, d;
    int i;
}v[10004];
struct timp{
    int i, j;
}f[10004];
int z = 0;
int a[10004];
bool compara(bolovan a, bolovan b){
    if(a.z < b.z){
        return true;
    }else if(a.z == b.z){
        if(a.d < b.d){
            return true;
        }
    }
    return false;
}
signed main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i].z >> v[i].d;
        v[i].i = i;
    }
    if(n > 10){
        sort(v+1, v+n+1, compara);
        int nr = 0;
        int d = 0;
        for(int i = 1; i <= n; i++){
            if(d+v[i].z <= v[i].d){
                f[v[i].i].i = d+1;
                d += v[i].z;
                f[v[i].i].j = d;
                nr++;
            }else{
                z++;
                a[z] = i;
            }
        }
        for(int i = 1; i <= z; i++){
            f[v[a[i]].i].i = d+1;
            d += v[a[i]].z;
            f[v[a[i]].i].j = d;
        }
        fout << nr << '\n';
        for(int i = 1; i <= n; i++){
            fout << f[i].i << ' ' << f[i].j << '\n';
        }
    }else{
        int v1[14];
        for(int i = 1; i <= n; i++){
            v1[i] = i;
        }
        int nrmax = 0;
        do{
            int d = 0;
            int nr = 0;
            for(int j = 1; j <= n; j++){
                int i = v1[j];
                d += v[i].z;
                if(d <= v[i].d){
                    nr++;
                }
            }
            if(nr > nrmax){
                for(int i = 1; i <= n; i++){
                    a[i] = v1[i];
                }
                nrmax = nr;
            }
        }while(next_permutation(v1+1, v1+n+1));
        fout << nrmax << '\n';
        int d = 1;
        for(int i = 1; i <= n; i++){
            fout << d << ' ';
            d += v[i].z-1;
            fout << d << '\n';
            d++;
        }
    }
    return 0;
}
