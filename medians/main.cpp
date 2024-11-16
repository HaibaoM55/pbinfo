#include <fstream>
using namespace std;
ifstream fin("medians.in");
ofstream fout("medians.out");
int n, k;
int v[100004];
unsigned int nr = 0;
int stv[100004];
int nrkv[100004];
int z = 0;
int ap[100004];
int main()
{
    fin >> n >> k;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        if(v[i] < k){
            stv[i]++;
        }else if(v[i] == k){
            z++;
            ap[z] = i;
            nrkv[i]++;
        }
        stv[i] = stv[i-1]+stv[i];
        nrkv[i] = nrkv[i-1]+nrkv[i];
    }
    int p0 = 1;
    ap[z+1]=n+1;
    for(int i = 1; i <= n; i++){
        if(ap[p0] < i){
            p0++;
        }
        for(int j = ap[p0]; j <= n; j++){
            int r = (j-i+2)/2;
            int st = stv[j]-stv[i-1];
            int nrk = nrkv[j]-nrkv[i-1];
            if(st+nrk >= r && st < r){
                nr++;
            }
        }
    }
    fout << nr;
    return 0;
}
