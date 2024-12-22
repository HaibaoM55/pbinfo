#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("primprim.in");
ofstream fout("primprim.out");
int p, n, q;
int v[1000004], c[1000004];
bool ciur[1000004];
int nrp = 0;
int prm[1000004];
int f[150];
long long s = 0;
int cost(int x){
    int p1 = 1;
    int p2 = nrp;
    while(p1 <= p2){
        int mij = (p1+p2)/2;
        if(prm[mij] < x){
            p1 = mij+1;
        }else{
            p2 = mij-1;
        }
    }
    return min(prm[p1]-x, x-prm[p1-1]);
}
int main()
{
    fin >> p;
    fin >> n;
    for(int i = 2; i <= 1000000; i++){
        if(ciur[i] == false){
            nrp++;
            prm[nrp] = i;
            for(int j = i; (long long) j*i <= 1000000; j++){
                ciur[j*i] = true;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        v[i] = cost(v[i]);
        f[v[i]]++;
        s = s + v[i];
    }
    if(p == 1){
        fout << s;
    }else{
        fin >> q;
        for(int i = 1; i <= q; i++){
            int j, x, pz;
            fin >> j >> x >> pz;
            int cst = cost(x);
            f[v[j]]--;
            v[j] = cst;
            f[cst]++;
            s = 0;
            for(int j = 0; j <= 114 && pz > 0; j++){
                if(f[j] < pz){
                    pz -= f[j];
                    s = s + j*f[j];
                }else{
                    s = s + j*pz;
                    pz = 0;
                    break;
                }
            }
            fout << s << '\n';
        }
    }
    return 0;
}
