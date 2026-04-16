#include <fstream>
using namespace std;
#define int long long
#define MOD 1000000007
ifstream fin("cercetasi.in");
ofstream fout("cercetasi.out");
int n,r,a,b;
int f[100004], invf[100004];
int s[100004];
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
int putere(int x, int y){
    if(y == 0){
        return 1;
    }
    if(y == 1){
        return x%MOD;
    }
    if(y % 2 == 0){
        long long z = putere(x, y/2)%MOD;
        return (z*z)%MOD;
    }else{
        return (putere(x, y-1)*(x%MOD))%MOD;
    }
}
signed main(){
    fin >> n >> r >> a >> b;
    f[0] = 1;
    invf[0] = 1;
    for(int i = 1; i <= n; i++){
        f[i] = f[i-1]*i;
        f[i] = f[i]%MOD;
        invf[i] = invers(f[i]);
    }
    s[0] = 1;
    for(int i = 1; i <= n; i++){
        if(i % 2 == 1){
            s[i] = MOD-invf[i];
        }else{
            s[i] = invf[i];
        }
        s[i] = (s[i-1]+s[i])%MOD;
    }
    long long rasp = 0;
    for(int i = r; i <= b; i++){
        long long k = s[b-i];
        if(a > i){
            k = (k-s[a-i-1]+MOD)%MOD;
        }
        k = (k*invf[i-r])%MOD;
        k = (k*putere(i-r+1,n-r))%MOD;
        rasp = (rasp+k)%MOD;
    }
    fout << rasp;
    return 0;
}
