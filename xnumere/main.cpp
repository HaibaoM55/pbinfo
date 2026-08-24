#include <fstream>
using namespace std;
#define MOD 666013
#define int long long
ifstream fin("xnumere.in");
ofstream fout("xnumere.out");
long long k, x, n;
int v[15];
long long rasp = 0;
void bt(int i){
    if(i == n+1){
        int f[15] = {0,0,0,0,0,0,0,0,0,0,0};
        int y = 0;
        for(int j = 1; j <= n; j++){
            f[v[j]]++;
            if(f[v[j]] == 1){
                y++;
            }
        }
        if(y == x){
            rasp++;
        }
        return;
    }
    for(int j = 1; j <= k; j++){
        v[i] = j;
        bt(i+1);
        v[i] = 0;
    }
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
long long comb(long long x, long long y){
    long long numarator = 1, numitor = 1;
    for(long long i = 0; i < y; i++){
        numarator=(numarator*((x-i)%MOD))%MOD;
        numitor=(numitor*((i+1)%MOD))%MOD;
    }
    return (numarator*invers((int)numitor))%MOD;
}
long long rs[100004], f[100004];
signed main(){
    fin >> k >> x >> n;
    for(int i = 1; i <= x; i++){
        f[i] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= x; j++){
            f[j] = f[j]*j;
            f[j] = f[j]%MOD;
        }
    }
    rs[1] = 1;
    for(int i = 2; i <= x; i++){
        rs[i] = f[i];
        for(int j = i-1; j >= 1; j--){
            rs[i] -= (1LL*comb(i, j)*rs[j])%MOD;
            rs[i] += MOD;
            rs[i] %= MOD;
        }
        //fout << rs[i] << ' ';
    }
    long long rasp = (1LL*comb(k, x)*rs[x])%MOD;
    fout << rasp;
    return 0;
}
