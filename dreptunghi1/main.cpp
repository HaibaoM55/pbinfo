#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("dreptunghi1.in");
ofstream fout("dreptunghi1.out");
int n, m, z;
int l, c;
struct pereche{
    int l, c;
}p[10004];
long long amax = 0;
bool a1[10004];
int v[10004];
int stv[10004];
int vf = 0;
int p0 = 1;
int s[10004];
int d[10004];
bool compara(pereche a, pereche b){
    if(a.l < b.l){
        return true;
    }else if(a.l == b.l){
        if(a.c < b.c){
            return true;
        }
    }
    return false;
}
int main()
{
    fin >> n >> m >> z;
    for(int i = 1; i <= z; i++){
        fin >> p[i].l >> p[i].c;
    }
    sort(p+1, p+z+1, compara);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            a1[j] = 1;
        }
        for(p0; p0 <= z; p0++){
            if(p[p0].l == i){
                a1[p[p0].c] = 0;
            }else{
                break;
            }
        }
        for(int j = 1; j <= m; j++){
            if(a1[j]){
                v[j]++;
            }else{
                v[j] = 0;
            }
        }
        vf = 0;
        stv[0] = 0;
        v[0] = -1;
        for(int j = 1; j <= m; j++){
            s[j] = j;
            while(v[stv[vf]] >= v[j]){
                s[j] = s[stv[vf]];
                vf--;
            }
            vf++;
            stv[vf] = j;
        }
        vf = 0;
        stv[0] = m+1;
        v[m+1] = -1;
        for(int j = m; j >= 1; j--){
            d[j] = j;
            while(v[stv[vf]] >= v[j]){
                d[j] = d[stv[vf]];
                vf--;
            }
            vf++;
            stv[vf] = j;
        }
        for(int j = 1; j <= m; j++){
            amax = max(amax, 1LL*v[j]*(d[j]-s[j]+1));
        }
    }
    fout << amax;
    return 0;
}
