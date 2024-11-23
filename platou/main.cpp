#include <fstream>
using namespace std;
ifstream fin("platou.in");
ofstream fout("platou.out");
int v, n, a[1000005];
int f[1000005];
int nrmax, nrvalmax;
int main()
{
    fin >> v;
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> a[i];
    }
    if(v == 1){
        int nr = 1;
        nrmax=0;
        nrvalmax=0;
        for(int i = 2; i <= n; i++){
            if(a[i] == a[i-1]){
                nr++;
                if(nr > nrmax){
                    nrmax = nr;
                    nrvalmax = a[i];
                }else if(nr == nrmax){
                    nrvalmax = max(nrvalmax, a[i]);
                }
            }else{
                nr = 1;
            }
        }
        fout << nrmax << ' ' << nrvalmax;
    }else{
        int nr = 1;
        nrmax=0;
        nrvalmax=0;
        for(int i = 2; i <= n; i++){
            if(a[i] == a[i-1]){
                nr++;
                if(f[a[i]]+nr > nrmax){
                    nrmax = f[a[i]]+nr;
                    nrvalmax = a[i];
                }else if(f[a[i]]+nr == nrmax){
                    nrvalmax = max(nrvalmax, a[i]);
                }
            }else{
                f[a[i-1]] = max(f[a[i-1]], nr);
                nr = 1;
                if(f[a[i]]+nr > nrmax){
                    nrmax = f[a[i]]+nr;
                    nrvalmax = a[i];
                }else if(f[a[i]]+nr == nrmax){
                    nrvalmax = max(nrvalmax, a[i]);
                }
            }
        }
        fout << nrmax << ' ' << nrvalmax;
    }
    return 0;
}
