#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
ifstream fin("bolovani.in");
ofstream fout("bolovani.out");
int n;
struct bolovan{
    long long z, d;
    int i;
}v[10004], sol[10004];
struct timp{
    int i, j;
}f[10004];
int z = 0;
int a[10004], q[100004];
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
bool compara1(int x, int y){
    if(v[x].d < v[y].d){
        return true;
    }
    return false;
}
bool comparav(bolovan x, bolovan y){
    if(x.d < y.d){
        return true;
    }
    return false;
}
signed main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i].z >> v[i].d;
        v[i].i = i;
    }
    if(n <= 10){
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
    }else{
        sort(v+1, v+n+1, comparav);
        long long s = 0;
        int nrq = 0;
        for(int i = 1; i <= n; i++){
            if(s + v[i].z <= v[i].d){
                s += v[i].z;
                nrq++;
                q[nrq] = i;
            }else{
                int vmax=0, p=0;
                for(int j1 = 1; j1 <= nrq; j1++){
                    int j = q[j1];
                    if(v[j].z > vmax){
                        vmax=v[j].z;
                        p=j1;
                    }
                }
                if(v[i].z<=vmax){
                    q[p]=i;
                    s-=vmax;
                    s+=v[i].z;
                }
            }
        }
        sort(q+1, q+nrq+1, compara1);
        s=1;
        int nr = 0;
        for(int i1 = 1; i1 <= nrq; i1++){
            int i = q[i1];
            if(s+v[i].z-1 <= v[i].d){
                nr++;
            }
            sol[v[i].i].z = s;
            s += v[i].z;
            sol[v[i].i].d=s-1;
        }
        for(int i=1;i<=n;i++){
            if(sol[v[i].i].z==0){
                sol[v[i].i]={s, s+v[i].z-1};
                s+=v[i].z;
            }
        }
        fout << nr << '\n';
        for(int i = 1; i <= n; i++){
            fout << sol[i].z << " " << sol[i].d << '\n';
        }
    }
    return 0;
}
