#include <fstream>
using namespace std;
ifstream fin("dsecv.in");
ofstream fout("dsecv.out");
int c, n, x;
int d[10004], v[10004];
int dmax = 0;
int main()
{
    fin >> c >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        d[i] = 1;
        if(x > 1){
            d[i]++;
        }
        if(v[i] < 999990000){
            int j;
            for(j = 2; j * j <v[i]; j++){
                if(v[i] % j==0){
                    d[i] += 2;
                }
            }
            if(j*j == v[i]){
                d[i]++;
            }
        }
        dmax = max(dmax, d[i]);

    }
    if(c == 1){
        int vmax = 0, vmin = 1000000000;
        for(int i = 1; i <= n; i++){
            if(d[i] == dmax){
                vmax = max(vmax, v[i]);
                vmin = min(vmin, v[i]);
            }
        }
        fout << vmin << ' ' << vmax;
    }else{
        int secv = 1;
        int nrsecv= 0, secvmax =0;
        for(int i = 1; i <= n; i++){
            if(d[i] <= d[i+1]){
                secv++;
            }else{
                if(secv > secvmax){
                    secvmax = secv;
                    nrsecv = 1;
                }else if(secvmax == secv){
                    nrsecv++;
                }
                secv = 1;
            }
        }
        if(secv > secvmax){
            secvmax = secv;
            nrsecv = 1;
        }else if(secvmax == secv){
            nrsecv++;
        }
        fout << nrsecv << ' ' << secvmax;
    }
    return 0;
}
