#include <fstream>
#include <math.h>
using namespace std;
#pragma GCC optimize("O3")
ifstream fin("orase2.in");
ofstream fout("orase2.out");
int t;
int n, x;
int d[50004], v[50004];
unsigned short f[10010004];
double nr;
int verif(double t){
    int n1 = 0;
    nr = 0;
    for(int i = 1; i <= n; i++){
        int v1 = ceil(-0.5 + sqrt(0.25 + d[i]/t));
        if(v1 > v[i]){
            n1 += v1 - v[i];
        }
        else{
            v1 = v[i];
        }
        nr += (double)d[i]/v1;
    }
    nr -= 1.0*t * (x - n1);
    return n1;
}
int main(){
    fin >> t;
    fin >> n >> x;
    for(int i = 1; i <= n; i++){
        fin >> d[i];
    }
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    if(t != 4){
        double p1 = 0, p2 = 1e4,r;
        int nrt =0;
        while(p1 <= p2 && nrt < 50){
            nrt++;
            double mij = ((double)p1+p2)/2;
            if(verif(mij) <= x){
                p2 = mij;
                r = mij;
            }else{
                p1 = mij;
            }
        }
        verif(r);
        fout << (int)nr;
    }else{
        for(int i = 1; i <= n; i++){
            f[v[i]]++;
        }
        int i = 1;
        while(x > 0){
            if(f[i] <= x) {
                f[i+1] += f[i];
                x -= f[i];
                f[i] = 0;
            }else{
                f[i] -= x;
                f[i+1] += x;
                x = 0;
            }
            i++;
        }
        double t = 0;
        for(i = 1; i <= 10010001; i++){
            if(f[i] > 0){
                t += 1.0*f[i]*((double)d[1]/i);
            }
        }
        int timp = t;
        fout << timp;
    }
    return 0;
}
