#include <fstream>
#include <string.h>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("omit-frame-pointer")
#pragma GCC optimize("unsafe-math-optimizations")
#pragma GCC optimize("no-signed-zeros")
#pragma GCC optimize("finite-math-only")
using namespace std;
#define MOD 1000000009
ifstream fin("comun.in");
ofstream fout("comun.out");
int n, m, k;
bool f[30][30][30];
char x[30];
bool v[30];
bool doarab = true;
int frecv[456976+4];
int p2[30], p[10];
void kp(int panacu, int i, int j){
    if(j == m+1){
        frecv[panacu]++;
        return;
    }
    if(f[i][j][0]){
        kp(panacu+p2[j], i, j+1);
    }
    if(f[i][j][1]){
        kp(panacu, i, j+1);
    }
}
void kpg(int panacu, int i, int j){
    if(j == m+1){
        frecv[panacu]++;
        return;
    }
    for(int z = 0; z < 26; z++){
        if(f[i][j][z]){
            kpg(panacu+p[j]*z, i, j+1);
        }
    }
}
long long cate(int cat, int ics, int nre, vector<int> elm){
    if(nre == cat){
        long long ans = 1;
        for(int j = 1; j <= m; j++){
            for(int z = 0; z < 26; z++){
                v[z] = true;
            }
            for(int i = 0; i < nre; i++){
                for(int z = 0; z < 26; z++){
                    if(!f[elm[i]][j][z]){
                        v[z] = false;
                    }
                }
            }
            int nre = 0;
            for(int i = 0; i < 26; i++){
                if(v[i]){
                    nre++;
                }
            }
            ans = ans*nre;
            ans = ans%MOD;
        }
        return ans;
    }
    if(ics == n+1){
        return 0;
    }
    long long nr1 = cate(cat,ics+1,nre,elm);
    elm.push_back(ics);
    return nr1+cate(cat,ics+1, nre+1, elm);
}
int invers(int b){
    long long rasp=1;
    int rr = MOD-2;
    while(rr){
        if(rr % 2 == 1){
            rasp=(1LL*rasp*b)%MOD;
        }
        b=(1LL*b*b)%MOD;
        rr = rr/2;
    }
    return rasp;
}
long long c[23][23];
vector<int> vclear;
int main(){
    fin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> x;
            int l = strlen(x);
            for(int z = 0; z < l; z++){
                f[i][j][x[z]-'a'] = true;
                if(x[z]-'a' > 1){
                    doarab = false;
                }
            }
        }
    }
    if(k == n){
        long long rasp = 1;
        for(int j = 1; j <= m; j++){
            for(int z = 0; z < 26; z++){
                v[z] = true;
            }
            for(int i = 1; i <= n; i++){
                for(int z = 0; z < 26; z++){
                    if(!f[i][j][z]){
                        v[z] = false;
                    }
                }
            }
            int nre = 0;
            for(int z = 0; z < 26; z++){
                if(v[z]){
                    nre++;
                }
            }
            rasp = rasp * nre;
            rasp = rasp % MOD;
        }
        fout << rasp;
    }else if(doarab){
        p2[1] = 1;
        for(int i = 2; i <= 29; i++){
            p2[i] = p2[i-1]*2;
        }
        for(int i = 1; i <= n; i++){
            kp(0,i, 1);
        }
        int nr = 0;
        for(int i = 0; i <= 32768; i++){
            if(frecv[i] >= k){
                nr++;
            }
        }
        fout << nr;
    }else if(m <= 4){
        p[1] = 1;
        p[2] = p[1]*26;
        p[3] = p[2]*26;
        p[4] = p[3]*26;
        for(int i = 1; i <= n; i++){
            kpg(0, i, 1);
        }
        int nr = 0;
        for(int i = 0; i <= 456976; i++){
            if(frecv[i] >= k){
                nr++;
            }
        }
        fout << nr;
    }else{
        for(int i = 0; i <= n; i++){
            c[i][0] = 1;
            for(int j = 1; j <= i; j++){
                c[i][j] = (c[i-1][j-1] + c[i-1][j])%MOD;
            }
        }
        long long rasp = 0;
        for(int i = k; i <= n; i++){
            long long fi = cate(i, 1, 0, vclear);
            long long coef = c[i-1][k-1];
            if((i-k) % 2 == 0){
                rasp = (rasp+coef*fi)%MOD;
            }else{
                rasp = (rasp-coef*fi%MOD+MOD)%MOD;
            }
        }
        fout << rasp;
    }
    return 0;
}
