#include <iostream>
#include <math.h>
using namespace std;
int n, k;
int f[20], e[20], fx[20];
int nf;
long long w;
long long vmax = 1;
void bk(int p, long long q){
    if(p <= nf){
        for(int i = 1; i <= nf; i++){
            if(f[i] > fx[p-1]){
                fx[p] = f[i];
                long long r=q;
                for(int j = 1; j <= e[i]; j++){
                    r=r*f[i];
                    if(r<=w){
                        if(r>vmax)vmax=r;
                        bk(p+1,r);
                    }else{
                        break;
                    }
                }
            }
        }
    }
}
int main()
{
    cin >> n >> k;
    w=1;
    for(int i=1;i<=k;i++){
        w=w*10;
    }
    w--;
    ///w=10^k-1
    nf = 0;
    int x=n;
    int d=2;
    while(d*d <= x){
        int c = 0;
        while(x % d == 0){
            x = x / d;
            c++;
        }
        if(c > 0){
            nf++;
            f[nf] = d;
            e[nf] = c*n;
        }
        d++;
    }
    if(x > 1){
        nf++;
        f[nf] = x;
        e[nf] = n;
    }
    vmax = 1;
    bk(1,1);
    cout << vmax;
    return 0;
}
