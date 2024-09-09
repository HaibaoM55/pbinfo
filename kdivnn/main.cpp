#include <iostream>
#include <math.h>
using namespace std;
int n, k;
int f[20], e[20], fx[20], ex[20];
int nf;
int nrcifre(int f1[], int e1[], int p){
    double s = 0;
    for(int i = 1; i <= p; i++){
        s += e1[i]*log10(f1[i]);
    }
    return floor(s)+1;
}
long long val(int f[], int e[], int p){
    long long s = 1;
    for(int i = 1; i <= p; i++){
        for(int j = 1; j <= e[i]; j++){
            s *= f[i];
        }
    }
    return s;
}
long long vmax = 1;
void bk(int p){
    if(p <= nf){
        long long v = val(fx, ex, p-1);
        if(v > vmax){
            vmax = v;
        }
        for(int i = 1; i <= nf; i++){
            if(f[i] > fx[p-1]){
                fx[p] = f[i];
                for(int j = 1; j <= e[i]; j++){
                    ex[p] = j;
                    if(nrcifre(fx, ex, p) <= k){
                        bk(p+1);
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
    for(int i = 1; i <= nf; i++){
        cout << f[i] << ' ' << e[i] << endl;
    }
    vmax = 1;
    bk(1);
    cout << vmax;
    return 0;
}
