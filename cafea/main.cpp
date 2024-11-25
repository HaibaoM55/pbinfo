#include <fstream>
#include <algorithm>
#include <math.h>
using namespace std;
ifstream fin("cafea.in");
ofstream fout("cafea.out");
long long k, s, n;
struct pereche{
    long long pret, grame;
    long double r;
}v[100004];
bool compara(pereche a, pereche b){
    if(a.r < b.r){
        return true;
    }
    return false;
}
int main()
{
    fin >> k >> s >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i].grame>> v[i].pret;
        v[i].r = (double) v[i].pret/v[i].grame;
    }
    sort(v+1, v+n+1, compara);
    int i = 1;
    while(k > 0 && s > 0 && i <= n){
        if(k >= v[i].grame){
            s = s-v[i].pret;
            k = k-v[i].grame;
        }else{
            long long p = ((long long)v[i].pret*k+v[i].grame-1)/v[i].grame;
            s = s-p;
            k = 0;
        }
        i++;
    }
    if(k > 0 && s > 0){
        fout << 0;
        return 0;
    }
    if(k > 0 && s < 0)
    {
        fout << 0;
        return 0;
    }
    if(k == 0 && s >= 0){
        fout << s;
        return 0;
    }
    if(k == 0 && s < 0){
        fout << 0;
        return 0;
    }
    return 0;
}
