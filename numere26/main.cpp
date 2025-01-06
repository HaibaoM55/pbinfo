#include <fstream>
using namespace std;
ifstream fin("numere.in");
ofstream fout("numere.out");
int n, c;
int v[10004];
bool ciur[10004];
int nrp=0, prm[10004];
int f[10004];
int vmax = 0;
int main()
{
    for(int i = 2; i <= 10000; i++){
        if(ciur[i] == false){
            nrp++;
            prm[nrp] = i;
            for(int j = i; j*i <= 10000; j++){
                ciur[j*i] = true;
            }
        }
    }
    fin >> n >> c;
    for(int i = 1; i <= n; i++){
        int x;
        fin >> x;
        for(int j = 1; j <= nrp && prm[j] <= x; j++){
            if(x % prm[j] == 0){
                v[i] = prm[j];
            }
        }
    }
    if(c == 1){
        for(int i = 1; i <= n; i++){
            f[v[i]] = i;
        }
        for(int i = 1; i <= n; i++){
            vmax = max(vmax, f[v[i]]-i+1);
        }
        fout << vmax;
    }else{
        for(int i = 1; i <= n; i++){
            f[v[i]]++;
        }
        long long s = 0;
        for(int i = 1; i <= 10000; i++){
            s = s + f[i]*(f[i]-1)/2;
        }
        fout << s;
    }
    return 0;
}
